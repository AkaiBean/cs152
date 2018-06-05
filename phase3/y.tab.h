/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 15 "mini_l.y" /* yacc.c:1909  */

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

#line 93 "y.tab.h" /* yacc.c:1909  */

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    FUNCTION = 258,
    BEGINPARAMS = 259,
    ENDPARAMS = 260,
    BEGINLOCALS = 261,
    ENDLOCALS = 262,
    BEGINBODY = 263,
    ENDBODY = 264,
    INTEGER = 265,
    ARRAY = 266,
    OF = 267,
    IF = 268,
    THEN = 269,
    ENDIF = 270,
    ELSE = 271,
    WHILE = 272,
    DO = 273,
    FOREACH = 274,
    IN = 275,
    BEGINLOOP = 276,
    ENDLOOP = 277,
    CONTINUE = 278,
    READ = 279,
    WRITE = 280,
    TRUE = 281,
    FALSE = 282,
    RETURN = 283,
    SEMICOLON = 284,
    COLON = 285,
    COMMA = 286,
    L_PAREN = 287,
    R_PAREN = 288,
    L_SQUARE_BRACKET = 289,
    R_SQUARE_BRACKET = 290,
    IDENT = 291,
    NUMBER = 292,
    MULT = 293,
    DIV = 294,
    MOD = 295,
    ADD = 296,
    SUB = 297,
    LT = 298,
    LTE = 299,
    GT = 300,
    GTE = 301,
    EQ = 302,
    NEQ = 303,
    AND = 304,
    OR = 305,
    ASSIGN = 306,
    NOT = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 64 "mini_l.y" /* yacc.c:1909  */

    char* sval;
    int ival;

#line 163 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
