%{
    #include <stdio.h>
    #include <stdlib.h>
    void yyerror(const char *msg);
    extern int currLine;
    extern int currPos;
    FILE * yyin;
%}

%union {
    char* sval;
}

%error-verbose
%start progam
%token FUNCTION BEGINPARAMS ENDPARAMS BEGINLOCALS ENDLOCALS BEGINBODY ENDBODY INTEGER ARRAY OF IF THEN ENDIF ELSE WHILE DO FOREACH IN BEGINLOOP ENDLOOP CONTINUE READ WRITE AND OR NOT TRUE FALSE RETURN SUB ADD MULT DIV MOD EQ NEQ LT GT LTE GTE SEMICOLON COLON COMMA L_PAREN R_PAREN L_SQUARE_BRACKET R_SQUARE_BRACKET ASSIGN
%token <sval> IDENT NUMBER
%type <sval> ident number

%%
progam:  functions                              {printf("prog_start -> functions\n");}
        ;

functions:      /* epsilon */                   {printf("functions -> epsilon\n");}
        | function functions                    {printf("functions -> function functions\n");}
        ;

function: FUNCTION ident SEMICOLON BEGINPARAMS declarations ENDPARAMS BEGINLOCALS declarations ENDLOCALS BEGINBODY statements ENDBODY                     
                                                {printf("function -> FUNCTION IDENT SEMICOLON BEGIN_PARAMS declarations END_PARAMS BEGIN_LOCALS declarations END_LOCALS BEGIN_BODY statements END_BODY\n");}
        ;

declarations: /* epsilon */                     {printf("declarations -> epsilon\n");}
        | declaration SEMICOLON declarations    {printf("declarations -> declaration SEMICOLON declarations\n");}
        ;

declaration: identifiers COLON INTEGER          {printf("declaration -> identifiers COLON INTEGER\n");}
        | identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER
                                                {printf("declaration -> identifiers COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
        ;

identifiers: ident                              {printf("identifiers -> ident\n");}
        | ident COMMA identifiers               {printf("identifiers -> ident COMMA identifiers\n");}
        ;

ident: IDENT                                    {printf("ident -> IDENT %s\n", $1);}
        ;

statements: /* epsilon */                       {printf("statements -> epsilon\n");}
        | statement SEMICOLON statements        {printf("statements -> statement SEMICOLON statements\n");}
        ;

statement: var ASSIGN expression                {printf("statement -> var ASSIGN expression\n");}
        | IF bool_exp THEN statements ENDIF     {printf("statement -> IF bool_exp THEN statements ENDIF\n");}
        | IF bool_exp THEN statements ELSE statements ENDIF
                                                {printf("statement -> IF bool_exp THEN statements ELSE statements ENDIF\n");}
        | WHILE bool_exp BEGINLOOP statements ENDLOOP
                                                {printf("statement -> WHILE bool_exp BEGINLOOP statements ENDLOOP\n");}
        | DO BEGINLOOP statements ENDLOOP WHILE bool_exp
                                                {printf("statement -> DO BEGINLOOP statements ENDLOOP WHILE bool_exp\n");}
        | FOREACH ident IN ident BEGINLOOP statements ENDLOOP
                                                {printf("statement -> FOREACH ident IN ident BEGINLOOP statements ENDLOOP\n");}
        | READ vars                             {printf("statement -> READ vars\n");}
        | WRITE vars                            {printf("statement -> WRITE vars\n");}
        | CONTINUE                              {printf("statement -> CONTINUE\n");}
        | RETURN expression                     {printf("statement -> RETURN expression\n");}
        ;

vars: /* epsilon */                             {printf("vars -> epsilon\n");}
        | var                                   {printf("vars -> var\n");}
        | var COMMA vars                        {printf("vars -> var COMMA vars\n");}
        ;

var: ident                                      {printf("var -> ident\n");}
        | ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET
                                                {printf("var -> ident L_SQUARE_BRACKET expression R_SQUARE_BRACKET\n");}
        ;

bool_exp: relation_and_exp                      {printf("bool_exp -> relation_and_exp\n");}
        | relation_and_exp OR bool_exp          {printf("bool_exp -> relation_and_exp OR relation_and_exp\n");}
        ;

relation_and_exp: relation_exp                  {printf("relation_and_exp -> relation_exp\n");}
        | relation_exp AND relation_and_exp     {printf("relation_and_exp -> relation_exp AND relation_exp\n");}
        ;

relation_exp: expression comp expression        {printf("relation_exp -> expression comp expression\n");}
        | TRUE                                  {printf("relation_exp -> TRUE\n");}
        | FALSE                                 {printf("relation_exp -> FALSE\n");}
        | L_PAREN bool_exp R_PAREN              {printf("relation_exp -> L_PAREN bool_exp R_PAREN\n");}
        | NOT expression comp expression        {printf("relation_exp -> NOT expression comp expression\n");}
        | NOT TRUE                              {printf("relation_exp -> NOT TRUE\n");}
        | NOT FALSE                             {printf("relation_exp -> NOT FALSE\n");}
        | NOT L_PAREN bool_exp R_PAREN          {printf("relation_exp -> NOT L_PAREN bool_exp R_PAREN\n");}
        ;

comp: EQ                                        {printf("comp -> EQ\n");}
        | NEQ                                   {printf("comp -> NEQ\n");}
        | LT                                    {printf("comp -> LT\n");}
        | GT                                    {printf("comp -> GT\n");}
        | LTE                                   {printf("comp -> LTE\n");}
        | GTE                                   {printf("comp -> GTE\n");}
        ;

expressions: /* epsilon */                      {printf("expressions -> epsilon\n");}
        | expression                            {printf("expressions -> expression\n");}
        | expression COMMA expressions          {printf("expressions -> expression COMMA expressions\n");}
        ;

expression: multiplicative_expression           {printf("expression -> multiplicative_expression\n");}
        | multiplicative_expression ADD expression
                                                {printf("expression -> multiplicative_expression ADD multiplicative_expression\n");}
        | multiplicative_expression SUB expression
                                                {printf("expression -> multiplicative_expression SUB multiplicative_expression\n");}
        ;

multiplicative_expression: term                 {printf("multiplicative_expression -> term\n");}
        | term MULT multiplicative_expression   {printf("multiplicative_expression -> term MULT term\n");}
        | term DIV multiplicative_expression    {printf("multiplicative_expression -> term DIV term\n");}
        | term MOD multiplicative_expression    {printf("multiplicative_expression -> term MOD term\n");}
        ;

term: var                                       {printf("term -> var\n");}
        | number                                {printf("term -> number\n");}
        | L_PAREN expression R_PAREN            {printf("term -> L_PAREN expression R_PAREN\n");}
        | SUB var                               {printf("term -> SUB var\n");}
        | SUB NUMBER                            {printf("term -> SUB NUMBER\n");}
        | SUB L_PAREN expression R_PAREN        {printf("term -> SUB L_PAREN expression R_PAREN\n");}
        | ident L_PAREN expressions R_PAREN     {printf("term -> ident L_PAREN expressions R_PAREN\n");}
        ;

number: NUMBER                                  {printf("number -> NUMBER %s\n", $1);}
        ;
%%

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
    yyparse();
    return 0;
}

void yyerror(const char *msg)
{
    printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}
