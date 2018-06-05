%code top 
{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #define YY_USER_INIT yylloc.first_line=1;
    void yyerror(const char* msg);
    /*int yyerror(const char* msg);*/
    extern int currLine;
    extern int currPos;
    FILE * yyin;
}

%code requires
{
    typedef struct 
    {
        char* vName;
        char* vType;
        int vID;
        char vStatement[128];
    }variable;

    variable vArr[1024];
    int numList[1024];
    variable tracker[1024];
    void tpush(variable ele);
    variable tpop();
    int top;

    variable createTempStr(variable* arr, int* intList, char* ident);
    variable createTempNum(variable* arr, int* intList, int num);
    variable decTemp(variable* arr, int* intList);
    void initTemp(variable* arr, variable ele);
    int insArr(variable* arr, variable ele);
    void initArr(variable* arr, int size);
    void printArr(variable* arr);

    int boolean;
    int numCnt;
    int labCnt;
    int paramCnt;
    int isMain;
    void deepcpy(char* dest, char* src);
    void deepFind(char* dest, char* src);
    
    variable ltracker[1024];
    void lpush(variable ele);
    variable lpop();
    int ltop;
    int errFlag;
    
    variable whiletracker[1024];
    void whilepush(variable ele);
    variable whilepop();
    int whiletop;
    int whileCnt;
    int numAnd;
    int readCnt;
    int writeCnt;
    void checkDec(variable* arr, char* ident);
}

%union {
    char* sval;
    int ival;
}

%error-verbose
%start progam
%token FUNCTION BEGINPARAMS ENDPARAMS BEGINLOCALS ENDLOCALS BEGINBODY ENDBODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOREACH IN BEGINLOOP ENDLOOP CONTINUE READ WRITE TRUE FALSE RETURN SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET
%token <sval> IDENT
%type <sval> statement_var checkident
%token <ival> NUMBER
%type <ival> number
%left MULT DIV MOD ADD SUB LT LTE GT GTE EQ NEQ AND OR
%right ASSIGN NOT

%%
progam:  functions
        {
            if(!isMain)
            {
                errFlag = 1;
                char* msg;
                msg = "\"main\" function is not defined.";
                yyerror(msg);
            }
        }
        ;

functions: /* epsilon */                   
        | function functions
        ;

function: functionIdent SEMICOLON beginparamIdent declarations endparamIdent BEGINLOCALS declarations ENDLOCALS BEGINBODY statements ENDBODY
        {
            variable myVar = {"endfunc", "endfunction", -1, "endfunc\n"};
            insArr(vArr, myVar);
            paramCnt = 0;   // reset paramCnt for next function
        }
        ;

functionIdent: FUNCTION IDENT
        {
            char msg[128];
            sprintf(msg, "func %s\n", $2);
            variable myVar = {$2, "function", -1};
            deepcpy(myVar.vStatement, msg);
            insArr(vArr, myVar);
        }
        ;

beginparamIdent: BEGINPARAMS
        {
            boolean = 1;
        }
        ;

endparamIdent: ENDPARAMS
        {
            boolean = 0;
        }
        ;

declarations: /* epsilon */
        | declaration SEMICOLON declarations
        ;

declaration: checkident commaIdent COLON INTEGER
        {
            char msg[128];
            sprintf(msg, ". %s\n", $1);
            variable myVar = {$1, "dec", -1};
            deepcpy(myVar.vStatement, msg);
            if(boolean)
            {
                char msg2[128];
                myVar.vType = "paramdec";
                myVar.vID = numList[paramCnt]; 
                sprintf(msg2, ". %s\n= %s, $%d\n", $1, $1, myVar.vID);
                deepcpy(myVar.vStatement, msg2);
                paramCnt++;
            }
            insArr(vArr, myVar);
        }
        | checkident commaIdent COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
        {
            char msg[128];
            if($6 <= 0)
            {
                errFlag = 1;
                yyerror("array size cannot be <= 0.");
            }
            sprintf(msg, ".[] %s, %d\n", $1, $6);
            variable myVar = {$1, "arrdec", $6};
            deepcpy(myVar.vStatement, msg);
            insArr(vArr, myVar);
        }
        | checkident commaIdent COLON ARRAY L_SQUARE_BRACKET SUB NUMBER R_SQUARE_BRACKET OF INTEGER
        {
            errFlag = 1;
            yyerror("array size cannot be <= 0.");
        }
        ;
        
checkident: IDENT
          {
          }
          | error 
          {
              printf("");
              /*int i;
              for(i = 0; i< 29; i++)
              {
                  printf("vArr[i]: %s, ident: %s\n", vArr[i].vName, $$);
                  if(strcmp(vArr[i].vName, $$) == 0)
                  {
                      printf("found error\n");
                      char msg[128];
                      sprintf(msg, "variable name \"%s\" is a reserved keyword.", $$);
                      yyerror(msg);
                  }
              }*/
          }
        ;

commaIdent: /* epsilon */
        | COMMA IDENT commaIdent
        {
            char msg[128];
            sprintf(msg, ". %s\n", $2);
            variable myVar = {$2, "dec", -1};
            deepcpy(myVar.vStatement, msg);
            if(boolean)
            {
                char msg2[128];                
                myVar.vType = "paramdec";
                myVar.vID = numList[paramCnt];
                sprintf(msg2, ". %s\n= %s, $%d\n", $2, $2, myVar.vID);
                deepcpy(myVar.vStatement, msg2);
                paramCnt++;
            }
            insArr(vArr, myVar);
        }
        ;

statements: /* epsilon */                    
        | statement SEMICOLON statements    
        ;

statement: statement_var ASSIGN expression
        {
            // now have to check for expression type also
            char msg[128];
            variable src = tpop();      //expression
            variable myVar2 = tpop();   //statement var
               
            if(strcmp(myVar2.vType, "variable") == 0 && (strcmp(src.vType, "temp") == 0 || strcmp(src.vType, "multiplicative") == 0))
            {
                checkDec(vArr, myVar2.vName); 
                sprintf(msg, "= %s, %s%d\n", myVar2.vName, src.vName, src.vID);
                deepcpy(myVar2.vStatement, msg);
                initTemp(vArr, myVar2);
            }
            else if(strcmp(myVar2.vType, "temp") == 0 && strcmp(src.vType, "arrVariable") == 0)
            {
                variable myIdent = tpop();
                if(strcmp(myIdent.vType, "variable") == 0)
                {
                    variable myVar3 = {myIdent.vName, "assignToArray", -1};
                    sprintf(msg, "=[] %s, %s, %s%d\n", myIdent.vName, src.vName, myVar2.vName, myVar2.vID);
                    deepcpy(myVar3.vStatement, msg);
                    initTemp(vArr, myVar3);
                }
                else if(strcmp(myIdent.vType, "arrVariable") == 0)
                {
                    variable identIndex = tpop();
                    variable temp = {"temp_", "temp", numCnt};
                    numCnt++;
                    variable myVar3 = {myIdent.vName, "arrayToArray", -1};
                    
                    sprintf(msg, ". %s%d\n=[] %s%d, %s, %s%d\n", temp.vName, temp.vID, temp.vName, temp.vID, src.vName, myVar2.vName, myVar2.vID);
                    deepcpy(temp.vStatement, msg);
                    initTemp(vArr, temp);
                    char msg2[128];
                    sprintf(msg2, "[]= %s, %s%d, %s%d\n", myIdent.vName, identIndex.vName, identIndex.vID, temp.vName, temp.vID);
                    deepcpy(myVar3.vStatement, msg2);
                    initTemp(vArr, myVar3);
                }
            }
            else if(strcmp(myVar2.vType, "arrVariable") == 0 && strcmp(src.vType, "temp") == 0)
            {
                variable indexx = tpop();   //expression
                variable myVar3 = {myVar2.vName, "arrAssign", -1};
                sprintf(msg, "[]= %s, %s%d, %s%d\n", myVar2.vName, indexx.vName, indexx.vID, src.vName, src.vID);
                deepcpy(myVar3.vStatement, msg);
                initTemp(vArr, myVar3);
            }
            else if(strcmp(myVar2.vType, "arrVariable") == 0 && strcmp(src.vType, "multiplicative") == 0)
            {
                variable express = tpop();  //expression
                variable myVar3 = {myVar2.vName, "arrAssignMult", -1};
                sprintf(msg, "[]= %s, %s%d, %s%d\n", myVar2.vName, express.vName, express.vID, src.vName, src.vID);
                deepcpy(myVar3.vStatement, msg);
                initTemp(vArr, myVar3);
            }
        }
        | ifclause statements ENDIF
        {
            if(strcmp(ltracker[ltop].vType, "do_while_loop_cond") != 0)
            {
                char msg[128];
                variable myVar = lpop();
                sprintf(msg, ": %s%d\n", myVar.vName, myVar.vID);
                deepcpy(myVar.vStatement, msg);
                initTemp(vArr, myVar);
            }
        }
        | ifclause statements ifelse statements ENDIF
        {
            
        }
        | whileexp BEGINLOOP statements ENDLOOP
        {
           char msg[128];
           char msg2[128];
           variable f = whilepop();
           variable f2 = {"gobackwhile", "gobackwhile", -1};
           sprintf(msg2, ":= %s%d\n", f.vName, f.vID);
           deepcpy(f2.vStatement, msg2);
           initTemp(vArr, f2);

           variable v = lpop();
           variable v2= {"whileendloop", "whileendloop", -1};
           sprintf(msg, ": %s%d\n", v.vName, v.vID);
           deepcpy(v2.vStatement, msg);
           initTemp(vArr, v2);
        }
        | dobegin statements endwhile bool_exp
        {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = whilepop();
            variable myVar3 = {"endwhileloop", "endwhileloop", -1};
            sprintf(msg, "?:= %s%d, %s%d\n", myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement,msg);
            initTemp(vArr, myVar3);
        }
        | foreachwhile statements ENDLOOP
        {
            variable v3 = tpop();
            variable t1 = tpop();   
            variable v = tpop();   
            variable v2 = tpop();   
            //printf("v2 %s", v2.vStatement);
            // add 1 then check if is_prime < size, if not go to new label
           
            /*char msg1[128];
            variable chk = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg1, ". %s%d\n< %s%d, %s, %d\n?:= %s%d, %s%d\n", chk.vName, chk.vID, chk.vName, chk.vID, ttop.vName, v2.vID, v3.vName, v3.vID, chk.vName, chk.vID);
            deepcpy(chk.vStatement, msg1);
            initTemp(vArr, chk);*/

            char msg1[128];
            variable inc = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg1, ". %s%d\n= %s%d, %s%d\n+ %s%d, %s%d, 1\n", inc.vName, inc.vID, inc.vName, inc.vID, t1.vName, t1.vID, t1.vName, t1.vID, inc.vName, inc.vID);
            deepcpy(inc.vStatement, msg1);
            initTemp(vArr, inc);

            char msg2[128];
            variable chk = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg2, ". %s%d\n< %s%d, %s%d, %d\n?:= %s%d, %s%d\n", chk.vName, chk.vID, chk.vName, chk.vID, t1.vName, t1.vID, v2.vID, v3.vName, v3.vID, chk.vName, chk.vID);
            deepcpy(chk.vStatement, msg2);
            initTemp(vArr, chk);
        }
        | READ rvars
        {
            int i;
            for(i = 0; i < readCnt; i++)
            {
                initTemp(vArr, tpop());
            }
            readCnt = 0;
        }
        | WRITE wvars
        {
            variable testVar = tracker[top];
            if(strcmp(testVar.vType, "arrWrite") == 0)
            {
                char msg[128];
                testVar = tpop();
                variable myVar1 = tpop();
                variable myVar2 = {testVar.vName, "arrWriteAssign", -1};
                sprintf(msg, ".[]> %s, %s%d\n", testVar.vName, myVar1.vName, myVar1.vID);
                deepcpy(myVar2.vStatement, msg);
                initTemp(vArr, myVar2);
            }
            else if(strcmp(testVar.vType, "write") == 0)
            {
                int i;
                variable reverse[128];
                for(i = 0; i < writeCnt; i++)
                {
                    initTemp(vArr, tpop());
                }
                writeCnt = 0;
            }
        }
        | CONTINUE
        {
            char msg[128];
            variable myVar2 = whilepop();
            whilepush(myVar2);
            if(strcmp(myVar2.vType, "dowhileloop") == 0)
            {
                variable myVar1 = {"do_while_loop_check_", "do_while_loop_cond", whileCnt};
                whileCnt++;
                sprintf(msg, ":= %s%d\n", myVar1.vName, myVar1.vID);
                deepcpy(myVar1.vStatement, msg);
                whilepush(myVar1);
                initTemp(vArr, myVar1);
            }
            else if(strcmp(myVar2.vType, "whileloop") == 0)
            {
               // go back to beginning
               variable v = {"continue", "continuewhile", -1};
               sprintf(msg, ":= %s%d\n", myVar2.vName, myVar2.vID);
               deepcpy(v.vStatement, msg);
               initTemp(vArr, v);
            }
        }
        | RETURN expression       
        {
            char msg[128];
            variable myVar1;
            variable myVar2 = {"ret", "return", -1};
            myVar1 = tpop();
            sprintf(msg, "ret %s%d\n", myVar1.vName, myVar1.vID);             
            deepcpy(myVar2.vStatement, msg);
            initTemp(vArr, myVar2);
        }
        ;

foreachwhile: FOREACH IDENT IN IDENT BEGINLOOP
        {
            variable v = {$2, "foreachident", 0};
            insArr(vArr, v);
            int i;
            int err = 1;
            variable v2;
            for(i = 0; i < 1024; i++)
            {
                if(strcmp(vArr[i].vName, $4) == 0 && strcmp(vArr[i].vType, "arrdec") == 0)
                {
                    err = 0;
                    v2 = vArr[i];
                    tpush(v2);
                }
            }
            if(err)
            {
                errFlag = 1;
                char msg[128];
                sprintf(msg, "used variable \"%s\" is scalar", $4);
                yyerror(msg);
            }
            char msg1[128];
            sprintf(msg1, ". %s\n", v.vName);
            deepcpy(v.vStatement, msg1);
            initTemp(vArr, v);
            tpush(v);
            
            char msg2[128];
            variable t1 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg2, ". %s%d\n= %s%d, 0\n", t1.vName, t1.vID, t1.vName, t1.vID);
            deepcpy(t1.vStatement, msg2);
            initTemp(vArr, t1);
            tpush(t1);

            char msg3[128];
            variable v3 = {"for_each_loop_", "foreachloop", whileCnt};
            whileCnt++;
            sprintf(msg3, ": %s%d\n", v3.vName, v3.vID);
            deepcpy(v3.vStatement, msg3);
            initTemp(vArr, v3);
            tpush(v3);

            char msg4[128];
            variable v4 = {"arrAccess", "arrAccess", -1};
            sprintf(msg4, "=[] %s, %s, %s%d\n", v.vName, v2.vName, t1.vName, t1.vID);
            deepcpy(v4.vStatement, msg4);
            initTemp(vArr, v4);
            
        }
        ;

ifelse: ELSE
        {
            char msg[128];
            variable v = lpop();
            variable v2 = {"else", "ifelse", -1};
            sprintf(msg, ": %s%d\n", v.vName, v.vID);
            deepcpy(v2.vStatement,msg);
            initTemp(vArr, v2);
        }
        ;

whileexp: whilebegin bool_exp
        {
               // check if condition is false
               char msg[128];
               variable v = tpop();
               variable a = {"temp_", "whilecond", numCnt};
               variable l = {"label_", "label", labCnt};
               numCnt++;
               labCnt++;
               sprintf(msg, ". %s%d\n== %s%d, %s%d, 0\n?:= %s%d, %s%d\n", a.vName, a.vID, a.vName, a.vID, v.vName, v.vID, l.vName, l.vID, a.vName, a.vID);
               deepcpy(a.vStatement, msg);
               initTemp(vArr, a);
               lpush(l);   
        }
        ;

whilebegin: WHILE
        {
            char msg[128];
            variable myVar1 = {"while_loop_", "whileloop", whileCnt};
            whileCnt++;
            sprintf(msg, ": %s%d\n", myVar1.vName, myVar1.vID);
            deepcpy(myVar1.vStatement, msg);
            initTemp(vArr, myVar1);
            whilepush(myVar1);
        }
        ;

dobegin: DO BEGINLOOP
        {
            char msg[128];
            variable myVar1 = {"do_while_loop_", "dowhileloop", whileCnt};
            whileCnt++;
            sprintf(msg, ": %s%d\n", myVar1.vName, myVar1.vID);
            deepcpy(myVar1.vStatement, msg);
            initTemp(vArr, myVar1);
            whilepush(myVar1);
        }   
        ;

endwhile: ENDLOOP WHILE
        {
            char msg[128];
            variable myVar1 = whilepop();
            variable myVar2 = {"do_while_loop_check_", "do_while_loop_cond", myVar1.vID};
            sprintf(msg, ": %s%d\n", myVar2.vName, myVar2.vID);
            deepcpy(myVar2.vStatement, msg);
            initTemp(vArr, myVar2);
        }
        ;
statement_var: IDENT
        {
            // basically check dec
            int i = 0;
            int decFlag = 1;
            while(vArr[i].vName != "")
            {
                if(strcmp(vArr[i].vName, $1) == 0 && strcmp(vArr[i].vType, "arrdec") == 0)
                {
                    decFlag = 0;
                    break;
                }
                i++;
            }
            if(!decFlag)
            {
                errFlag = 1;
                char msg[128];
                sprintf(msg, "need to specify an index for array variable \"%s\".", $1);
                yyerror(msg);
            }
            variable myVar = {$1, "variable", -1};
            tpush(myVar);
        }
        | IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
        {
            //basically check dec
            int i = 0;
            int decFlag = 1;
            while(vArr[i].vName != "")
            {
                //printf("%s, %s\n", vArr[i].vName, vArr[i].vType);
                if(strcmp(vArr[i].vName, $1) == 0 && strcmp(vArr[i].vType, "dec") == 0)
                {
                    decFlag = 0;
                    break;
                }
                i++;
            }
            if(!decFlag)
            {
                errFlag = 1;
                char msg[128];
                sprintf(msg, "\"%s\" is not an array variable. Cannot use a regular variable as an array variable.", $1);
                yyerror(msg);
            }
            variable myVar = {$1, "arrVariable", -1};
            tpush(myVar);
        }
        ;


ifclause: IF bool_exp THEN
        {
            char msg[128];
            variable myVar1 = {"label_", "label", labCnt};
            labCnt++;
            variable myVar2 = {"label_", "label", labCnt};
            labCnt++;
            variable myVar3 = tpop();   // might have to for loop using top variable
            sprintf(msg, "?:= %s%d, %s%d\n:= %s%d\n: %s%d\n", myVar1.vName, myVar1.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar1.vStatement, msg);
            initTemp(vArr, myVar1);
            lpush(myVar2);
        }
        ;


rvars: /* epsilon */               
        | IDENT
        {
            checkDec(vArr, $1);
            char msg[128];
            variable myVar1 = {$1, "read", -1};
            sprintf(msg, ".< %s\n", $1);
            deepcpy(myVar1.vStatement, msg);
            tpush(myVar1);
            readCnt++;
        }
        | IDENT COMMA rvars
        {
            checkDec(vArr, $1);
            char msg[128];
            variable myVar1 = {$1, "read", -1};
            sprintf(msg, ".< %s\n", $1);
            deepcpy(myVar1.vStatement, msg);
            tpush(myVar1);
            readCnt++;
        }
        ;

wvars: /* epsilon */
        | IDENT
        {
            char msg[128];
            variable myVar1 = {$1, "write", -1};
            sprintf(msg, ".> %s\n", $1);
            deepcpy(myVar1.vStatement, msg);
            //initTemp(vArr, myVar1);
            tpush(myVar1);
            writeCnt++;
        }
        | IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
        {
            variable myVar = {$1, "arrWrite", -1};
            tpush(myVar);
        }
        | IDENT COMMA wvars
        {
            char msg[128];
            variable v = {$1, "write", -1};
            sprintf(msg, ".> %s\n", $1);
            deepcpy(v.vStatement, msg);
            //initTemp(vArr, v);
            tpush(v);
            writeCnt++;
        }
        ;

var: IDENT
        {
            variable myVar;
            myVar = createTempStr(vArr, numList, $1);
            tpush(myVar);
        }
        | IDENT L_SQUARE_BRACKET expression R_SQUARE_BRACKET
        {
            variable myVar = {$1, "arrVariable", -1};
            tpush(myVar);
        }
        ;

bool_exp: relation_and_exp   
        | relation_and_exp OR bool_exp
        {
            char msg[128];
            variable myVar1 = tpop();   //boolean for second while loop
            variable myVar2 = tpop();   //temp for second while loop
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n|| %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
        ;

relation_and_exp: relation_exp           
        | relation_exp AND relation_and_exp
        {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n&& %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
        ;

relation_exp: relation_exp_comp
        | TRUE                           
        | FALSE
        {
            char msg[128];
            variable myVar1 = {"temp_", "bool", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n= %s%d, 0\n", myVar1.vName, myVar1.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar1.vStatement, msg);
            initTemp(vArr, myVar1);
            tpush(myVar1);
        }
        | L_PAREN bool_exp R_PAREN     
        | NOT relation_exp_comp 
        | NOT TRUE                      
        | NOT FALSE                    
        | NOT L_PAREN bool_exp R_PAREN
        ;

relation_exp_comp: expression EQ expression
        {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;

            if(strcmp(myVar2.vType, "multiplicative") == 0 || strcmp(myVar2.vType, "temp") == 0)
            {
                sprintf(msg, ". %s%d\n== %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            }
            else if(strcmp(myVar2.vType, "arrVariable") == 0)
            {
                //printf("name: %s, type: %s, id: %d, statement: %s", myVar1.vName, myVar1.vType, myVar1.vID, myVar1.vStatement);
             
                //printf("name: %s, type: %s, id: %d, statement: %s", myVar2.vName, myVar2.vType, myVar2.vID, myVar2.vStatement);   
                variable v = tpop();
                sprintf(msg, ". %s%d\n=[] %s%d, %s, %s%d\n== %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, v.vName, v.vID, myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar1.vName, myVar1.vID);
            }
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);

        }
        | expression NEQ expression
        | expression LT expression
        {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n< %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
        | expression GT expression
        {
            char msg[128];
            variable v1 = tpop();
            variable v2 = tpop();
            variable v3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n> %s%d, %s%d, %s%d\n", v3.vName, v3.vID, v3.vName, v3.vID, v2.vName, v2.vID, v1.vName, v1.vID);
            deepcpy(v3.vStatement, msg);
            initTemp(vArr, v3);
            tpush(v3);
        }
        | expression LTE expression
        {
            char msg[128];
            variable myVar1;
            variable myVar2;
            variable myVar3;
            myVar1 = tpop();
            myVar2 = tpop();
            myVar3 = decTemp(vArr, numList);
            sprintf(msg, ". %s%d\n<= %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }

        | expression GTE expression
        {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n>= %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
        ;

expressions: /* epsilon */     
        | expression
        | expression COMMA expressions 
        ;

expression: multiplicative_expression
        | multiplicative_expression ADD expression
        {
            char msg[128];
            variable myVar1;
            variable myVar2;
            variable myVar3;
            myVar1 = tpop();
            myVar2 = tpop();
            myVar3 = decTemp(vArr, numList);
            sprintf(msg, ". %s%d\n+ %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3); 
        }
        | multiplicative_expression SUB expression
        {
            char msg[128];
            variable myVar1;
            variable myVar2;
            variable myVar3;
            myVar1 = tpop();
            myVar2 = tpop();
            myVar3 = decTemp(vArr, numList);
            sprintf(msg, ". %s%d\n- %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3); 
        }
        ;

multiplicative_expression: term
        | term MULT multiplicative_expression
        {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "multiplicative", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n* %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
        | term DIV multiplicative_expression
        {
            char msg[128];
            variable v1 = tpop();
            variable v2 = tpop();
            variable v3 = {"temp_", "multiplicative", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n/ %s%d, %s%d, %s%d\n", v3.vName, v3.vID, v3.vName, v3.vID, v2.vName, v2.vID, v1.vName, v1.vID);
            deepcpy(v3.vStatement, msg);
            initTemp(vArr, v3);
            tpush(v3);
        }
        | term MOD multiplicative_expression
        {
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = tpop();
            variable myVar3 = {"temp_", "multiplicative", numCnt};
            numCnt++;
            sprintf(msg, ". %s%d\n%% %s%d, %s%d, %s%d\n", myVar3.vName, myVar3.vID, myVar3.vName, myVar3.vID, myVar2.vName, myVar2.vID, myVar1.vName, myVar1.vID);
            deepcpy(myVar3.vStatement, msg);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
        ;

term: var
        | number                           
        | L_PAREN expression R_PAREN      
        | SUB var                        
        | SUB NUMBER                    
        | SUB L_PAREN expression R_PAREN
        | IDENT L_PAREN expressions R_PAREN
        {
            // check function name
            int flag = 1;
            int i;
            for(i = 29; i < 1024; i++)
            {
                if(strcmp(vArr[i].vName, $1) == 0)    
                {
                    flag = 0;
                }
            }
            if(flag)
            {
                errFlag = 1;
                char errmsg[128];
                sprintf(errmsg, "function \"%s\" is not defined.", $1);
                yyerror(errmsg);
            }
            
            // param section
            char msg[128];
            variable myVar1 = tpop();
            variable myVar2 = {"param", "parameter", -1};
            sprintf(msg, "param %s%d\n", myVar1.vName, myVar1.vID);
            deepcpy(myVar2.vStatement, msg);
            initTemp(vArr, myVar2);
            
            // function call section
            char msg2[128];
            variable myVar3 = {"temp_", "temp", numCnt};
            numCnt++;
            sprintf(msg2, ". %s%d\ncall %s, %s%d\n", myVar3.vName, myVar3.vID, $1, myVar3.vName, myVar3.vID);
            deepcpy(myVar3.vStatement, msg2);
            initTemp(vArr, myVar3);
            tpush(myVar3);
        }
        ;

number: NUMBER
        {
            variable myVar;
            myVar = createTempNum(vArr, numList, $1);
            tpush(myVar); 
        }
        ;
%%

// Helper Functions
void yyerror(const char *msg)
{
    errFlag = 1;
    printf("Error line %d, column %d: %s\n", currLine, currPos, msg);
}

void whilepush(variable ele)
{
    whiletop = whiletop + 1;
    whiletracker[whiletop] = ele;
}

variable whilepop()
{
    int temp = whiletop;
    whiletop = whiletop - 1;
    if(whiletop < -1)
    {
        /*printf("popping empty stack whiletracker\n");
        printf("previous -> name:%s , type:%s , id:%d\n", whiletracker[0].vName, whiletracker[0].vType, whiletracker[0].vID);*/
        char msg[128];
        sprintf(msg, "continue statement is outside a loop");
        yyerror(msg);
        variable empty;
        return empty;
    }
    return whiletracker[temp];
}

void lpush(variable ele)
{
    ltop = ltop + 1;
    ltracker[ltop] = ele;
}

variable lpop()
{
    int temp = ltop;
    ltop = ltop - 1;
    if(ltop < -1)
    {
        printf("popping empty stack ltracker\n");
        printf("previous -> name:%s , type:%s , id:%d\n", ltracker[0].vName, ltracker[0].vType, ltracker[0].vID);
        exit(0);
    }
    return ltracker[temp];
}

void tpush(variable ele)
{
    top = top + 1;
    tracker[top] = ele;
}

variable tpop()
{
    int temp = top;
    top = top - 1;
    if(top < -1)
    {
        printf("popping empty stack tracker\n");
        printf("previous -> name:%s , type:%s , id:%d\n", tracker[1].vName, tracker[1].vType, tracker[1].vID);
        exit(0);
    }
    return tracker[temp];
}

variable createTempStr(variable* arr, int* intList, char* ident)
{
    int i = 0;
    int decFlag = 0;
    while(arr[i].vName != "")
    {
        if(strcmp(arr[i].vName, ident) == 0)
        {
            // if declared then its fine to use
            decFlag = 1;
        }
        i++;
    }
    if(!decFlag)    // if undeclared print error
    {
        errFlag = 1;
        char msg[128];
        sprintf(msg, "used variable \"%s\" was not previously declared.", ident);
        yyerror(msg);
    }
    variable myVar = {"temp_", "temp", intList[numCnt]};
    char msg[128];
    sprintf(msg, ". %s%d\n= %s%d, %s\n", myVar.vName, myVar.vID, myVar.vName, myVar.vID, ident);
    deepcpy(myVar.vStatement, msg);
    arr[i] = myVar;
    numCnt++;
    return myVar;
}

void checkDec(variable* arr, char* ident)
{
    int i = 0;
    int decFlag = 0;
    while(arr[i].vName != "")
    {
        if(strcmp(arr[i].vName, ident) == 0)
        {
            decFlag = 1;
        }
        i++;
    }
    if(!decFlag)
    {
        errFlag = 1;
        char msg[128];
        sprintf(msg, "used variable \"%s\" was not previously declared.", ident);
        yyerror(msg);
    }
}

variable createTempNum(variable* arr, int* intList, int num)
{
    int i = 0;
    while(arr[i].vName != "")
    {
        i++;
    }
    variable myVar = {"temp_", "temp", intList[numCnt]};
    char msg[128];
    sprintf(msg, ". %s%d\n= %s%d, %d\n", myVar.vName, myVar.vID, myVar.vName, myVar.vID, num);
    deepcpy(myVar.vStatement, msg);
    arr[i] = myVar;
    numCnt++; 
    return arr[i];
}

variable decTemp(variable* arr, int* intList)
{
    int i = 0;
    while(arr[i].vName != "")
    {
        i++;
    }
    variable myVar = {"temp_", "temp", intList[numCnt]};
    numCnt++;
    return myVar;
}

void initTemp(variable* arr, variable ele)
{
    int i = 0;
    int undecFlag = 0;
    while(arr[i].vName != "")
    {
        i++;
    }
    arr[i] = ele;
}

int insArr(variable* arr, variable ele)
{
    if(strcmp(ele.vName, "main") == 0)
    {
        isMain = 1;
    }

    int i;

    for(i = 0; i < 29; ++i) // check if ele is a reserved word
    {
        if(strcmp(arr[i].vName, ele.vName) == 0)
        {
            errFlag = 1;
            char msg[128];
            sprintf(msg, "symbol \"%s\" is a reserved keyword.", ele.vName);
            yyerror(msg);
            return -1;
        }
    }

    for(i = 29; i < 1024; ++i)
    {
        if(arr[i].vName != "" && strcmp(arr[i].vName, ele.vName) == 0)  // check if empty to prevent traverse whole array
        {
            if(strcmp(arr[i].vName, "endfunc") == 0)
                continue;
            
            errFlag = 1;
            char msg[128];
            sprintf(msg, "symbol \"%s\" is multiply-defined.", ele.vName);
            yyerror(msg);
            return -1;
        }
        else if(arr[i].vName != "")  // not empty then increment
        {
            continue;
        }
        else  // insert element if empty and no duplicate
        {
            arr[i] = ele;
            return 1;
        }
    }
    // should not reach here
    return -1;
}

void initArr(variable* arr, int size)
{
    int i;
    variable var0 = {"function", "reserved", -1};       arr[0] = var0;
    variable var1 = {"beginparams", "reserved", -1};    arr[1] = var1;
    variable var2 = {"endparams", "reserved", -1};      arr[2] = var2;
    variable var3 = {"beginlocals", "reserved", -1};    arr[3] = var3;
    variable var4 = {"endlocals", "reserved", -1};      arr[4] = var4;
    variable var5 = {"beginbody", "reserved", -1};      arr[5] = var5;
    variable var6 = {"endbody", "reserved", -1};        arr[6] = var6;
    variable var7 = {"integer", "reserved", -1};        arr[7] = var7;
    variable var8 = {"array", "reserved", -1};          arr[8] = var8;
    variable var9 = {"of", "reserved", -1};             arr[9] = var9;
    variable var10 = {"if", "reserved", -1};            arr[10] = var10;
    variable var11 = {"then", "reserved", -1};          arr[11] = var11; 
    variable var12 = {"endif", "reserved", -1};         arr[12] = var12;
    variable var13 = {"else", "reserved", -1};          arr[13] = var13;
    variable var14 = {"while", "reserved", -1};         arr[14] = var14;
    variable var15 = {"do", "reserved", -1};            arr[15] = var15;
    variable var16 = {"foreach", "reserved", -1};       arr[16] = var16;
    variable var17 = {"in", "reserved", -1};            arr[17] = var17;
    variable var18 = {"beginloop", "reserved", -1};     arr[18] = var18;
    variable var19 = {"endloop", "reserved", -1};       arr[19] = var19;
    variable var20 = {"continue", "reserved", -1};      arr[20] = var20;
    variable var21 = {"read", "reserved", -1};          arr[21] = var21;
    variable var22 = {"write", "reserved", -1};         arr[22] = var22;
    variable var23 = {"and", "reserved", -1};           arr[23] = var23;
    variable var24 = {"or", "reserved", -1};            arr[24] = var24;
    variable var25 = {"not", "reserved", -1};           arr[25] = var25;
    variable var26 = {"true", "reserved", -1};          arr[26] = var26;
    variable var27 = {"false", "reserved", -1};         arr[27] = var27;
    variable var28 = {"return", "reserved", -1};        arr[28] = var28;

    for(i = 29; i < size; i++)
    {
        arr[i].vName = "";
        arr[i].vType = "";
        arr[i].vID = -1;
    }
    return;
}

void printArr(variable* arr)
{
    int i;
    for(i = 29; i < 1024; i++)
    {
        if(arr[i].vName != "")
        { 
            printf("%s", arr[i].vStatement);
        }
        else
        {
            return;
        }
    }
    return;
}

void initList(int* intList)
{
    int i;
    for(i = 0; i < 1024; i++)
    {
        intList[i] = i;
    }
}

void printList(int* intList)
{
    int i;
    for(i = 0; i < 1024; i++)
    {
        printf("%d\n", intList[i]);
    }
}

void deepcpy(char* dest, char* src)
{
    int i;
    for(i = 0; i < 128; i++)
    {
        dest[i] = src[i];
    }
    return;
}

void deepFind(char* dest, char* src)
{
    int i;
    int j;
    int bIndex = 0;
    int eIndex = 0;
    for(i = 0; i < 128; i++)
    {
        if(src[i] == ',')
        {
            bIndex = i + 2;
        }
        if(src[i] == '\n')
        {
            eIndex = i;
        }
    }
    for(i = bIndex, j = 0; i < eIndex; i++, j++)
    {
        dest[j] = src[i];
    }
    dest[j] = '\0';
    return;
}
// End Helper Functions





// Main Function
int main (int argc, char **argv)
{
    if(argc > 1)
    {
        yyin = fopen(argv[1], "r");
        if(yyin == NULL)
        {
            printf("syntax: %s filename\n", argv[0]);
        }
    }
    whiletop = ltop = top = -1;
    readCnt = writeCnt = numAnd = whileCnt = errFlag = isMain = numCnt = paramCnt = labCnt = 0;
    initList(numList);
    initArr(vArr, 1024);
    yyparse();
    if(!errFlag)
        printArr(vArr);
    
    return 0;
}
