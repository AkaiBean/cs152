/*
  Name: Rodney Ho 861144114, Nam Nguyen 861152982
*/

%{
    #include "y.tab.h"
    int currLine = 1, currPos = 1;
%}

COMMENT     ##.*
DIGIT       [0-9]
ALPHA       [a-zA-Z]
IDENTIFIER  {ALPHA}({ALPHA}|{DIGIT})*(_+({ALPHA}|{DIGIT})+)*
INVALID_ID     ({DIGIT}+{ALPHA}+|{IDENTIFIER}_+|_+{IDENTIFIER}|_+({DIGIT}+|{IDENTIFIER})|({DIGIT}+)(_+|{IDENTIFIER})*)

%%
{COMMENT}       {/* ignore comments */ currPos += yyleng;}
"function"      {currPos += yyleng; return FUNCTION;}
"beginparams"   {currPos += yyleng; return BEGINPARAMS;}
"endparams"     {currPos += yyleng; return ENDPARAMS;}
"beginlocals"   {currPos += yyleng; return BEGINLOCALS;}
"endlocals"     {currPos += yyleng; return ENDLOCALS;}
"beginbody"     {currPos += yyleng; return BEGINBODY;}
"endbody"       {currPos += yyleng; return ENDBODY;}
"integer"       {currPos += yyleng; return INTEGER;}
"array"         {currPos += yyleng; return ARRAY;}
"of"            {currPos += yyleng; return OF;}
"if"            {currPos += yyleng; return IF;}
"then"          {currPos += yyleng; return THEN;}
"endif"         {currPos += yyleng; return ENDIF;}
"else"          {currPos += yyleng; return ELSE;}
"while"         {currPos += yyleng; return WHILE;}
"do"            {currPos += yyleng; return DO;}
"foreach"       {currPos += yyleng; return FOREACH;}
"in"            {currPos += yyleng; return IN;}
"beginloop"     {currPos += yyleng; return BEGINLOOP;}
"endloop"       {currPos += yyleng; return ENDLOOP;}
"continue"      {currPos += yyleng; return CONTINUE;}
"read"          {currPos += yyleng; return READ;}
"write"         {currPos += yyleng; return WRITE;}
"and"           {currPos += yyleng; return AND;}
"or"            {currPos += yyleng; return OR;}
"not"           {currPos += yyleng; return NOT;}
"true"          {currPos += yyleng; return TRUE;}
"false"         {currPos += yyleng; return FALSE;}
"return"        {currPos += yyleng; return RETURN;}

"-"             {currPos += yyleng; return SUB;}
"+"             {currPos += yyleng; return ADD;}
"*"             {currPos += yyleng; return MULT;}
"/"             {currPos += yyleng; return DIV;}
"%"             {currPos += yyleng; return MOD;}
"=="            {currPos += yyleng; return EQ;}
"<>"            {currPos += yyleng; return NEQ;}
"<"             {currPos += yyleng; return LT;}
">"             {currPos += yyleng; return GT;}
"<="            {currPos += yyleng; return LTE;}
">="            {currPos += yyleng; return GTE;}

{IDENTIFIER}    {currPos += yyleng; yylval.sval = strdup(yytext); return IDENT;}
{DIGIT}+        {currPos += yyleng; yylval.sval = strdup(yytext); return NUMBER;}
{INVALID_ID}    {printf("Error at line %d, column %d, invalid identifier, \"%s\"", currLine, currPos, yytext); exit(0);}


";"             {currPos += yyleng; return SEMICOLON;}
":"             {currPos += yyleng; return COLON;}
","             {currPos += yyleng; return COMMA;}
"("             {currPos += yyleng; return L_PAREN;}
")"             {currPos += yyleng; return R_PAREN;}
"["             {currPos += yyleng; return L_SQUARE_BRACKET;}
"]"             {currPos += yyleng; return R_SQUARE_BRACKET;}
":="            {currPos += yyleng; return ASSIGN;}

[ \t]+          {/* ignore spaces */ currPos += yyleng;}
"\n"            {currLine++; currPos = 1;}
.               {printf("Error at line %d, column %d, unrecognized symbol \"%s\"\n", currLine, currPos, yytext); exit(0);}


%%
