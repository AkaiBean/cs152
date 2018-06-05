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
    }variable;

    variable vArr[1024];
    int numList[1024];
    void createTemp(variable* arr, int* intList);
    int insArr(variable* arr, variable ele);
    void initArr(variable* arr, int size);
    void printArr(variable* arr);
    int boolean;
    int numCnt;
    int isMain;
}

%union {
    char* sval;
    int ival;
}

%error-verbose
%start progam
%token FUNCTION BEGINPARAMS ENDPARAMS BEGINLOCALS ENDLOCALS BEGINBODY ENDBODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOREACH IN BEGINLOOP ENDLOOP CONTINUE READ WRITE TRUE FALSE RETURN SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET
%token <sval> IDENT
%type <sval> ident identifiers
%token <ival> NUMBER
%type <ival> number
%left MULT DIV MOD ADD SUB LT LTE GT GTE EQ NEQ AND OR
%right ASSIGN NOT

%%
progam:  functions
        {
            if(!isMain)
            {
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
        ;

functionIdent: FUNCTION ident
        {
            variable myVar = {$2, "function"};
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

declarations: /* epsilon */
        | declaration SEMICOLON declarations    
        ;

declaration: identifiers COLON INTEGER
        {
            variable myVar = {$1, "intDec"};
            if(boolean)
                myVar.vType = "intParam";
            insArr(vArr, myVar);
        }
        | identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
        {
            variable myVar = {$1, "arrDec"};
            if(boolean)
                myVar.vType = "arrParam";
            insArr(vArr, myVar);

        }
        ;

identifiers: ident                              
        | ident COMMA identifiers
        ;

ident: IDENT
        ;

statements: /* epsilon */                    
        | statement SEMICOLON statements    
        ;

statement: var ASSIGN expression
        {
            
        }
        | IF bool_exp THEN statements ENDIF
        | IF bool_exp THEN statements ELSE statements ENDIF
        | WHILE bool_exp BEGINLOOP statements ENDLOOP
        | DO BEGINLOOP statements ENDLOOP WHILE bool_exp
        | FOREACH ident IN ident BEGINLOOP statements ENDLOOP
        | READ vars                   
        | WRITE vars                 
        | CONTINUE                  
        | RETURN expression        
        ;

vars: /* epsilon */               
        | var                    
        | var COMMA vars        
        ;

var: ident
        {
            createTemp(vArr, numList);
        }
        | ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET
        ;

bool_exp: relation_and_exp   
        | relation_and_exp OR bool_exp    
        ;

relation_and_exp: relation_exp           
        | relation_exp AND relation_and_exp
        ;

relation_exp: expression comp expression  
        | TRUE                           
        | FALSE                         
        | L_PAREN bool_exp R_PAREN     
        | NOT expression comp expression 
        | NOT TRUE                      
        | NOT FALSE                    
        | NOT L_PAREN bool_exp R_PAREN
        ;

comp: EQ                             
        | NEQ                       
        | LT                       
        | GT                      
        | LTE                    
        | GTE                   
        ;

expressions: /* epsilon */     
        | expression          
        | expression COMMA expressions 
        ;

expression: multiplicative_expression 
        | multiplicative_expression ADD expression
        | multiplicative_expression SUB expression
        ;

multiplicative_expression: term    
        | term MULT multiplicative_expression  
        | term DIV multiplicative_expression  
        | term MOD multiplicative_expression 
        ;

term: var                                   
        | number                           
        | L_PAREN expression R_PAREN      
        | SUB var                        
        | SUB NUMBER                    
        | SUB L_PAREN expression R_PAREN
        | ident L_PAREN expressions R_PAREN
        ;

number: NUMBER
        ;
%%

// Helper Functions
void yyerror(const char *msg)
{
    printf("Error line %d, column %d: %s\n", currLine, currPos, msg);
}

void createTemp(variable* arr, int* intList)
{
    int i;
    while(arr[i].vName != "")
    {
        i++;
    }
    arr[i].vID = intList[numCnt];
    arr[i].vName = "temp_";
    arr[i].vType = "temp";
    numCnt++;
}

// TODO: use return statements to determine to print mil_code
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
        if(arr[i].vName != "" && arr[i].vType != "temp")
        {
            printf("%s| %s\n", arr[i].vName, arr[i].vType);
        }
        else if(arr[i].vName != "" && arr[i].vType == "temp")
        {
           printf("%s%d| %s\n", arr[i].vName, arr[i].vID, arr[i].vType); 
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
    isMain = 0;
    numCnt = 0;
    initList(numList);
    initArr(vArr, 1024);
    yyparse();
    printArr(vArr);
    return 0;
}


