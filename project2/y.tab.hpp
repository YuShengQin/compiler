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

#ifndef YY_YY_Y_TAB_HPP_INCLUDED
# define YY_YY_Y_TAB_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    BOOLEAN = 258,
    BREAK = 259,
    CHAR = 260,
    CASE = 261,
    CLASS = 262,
    CONTINUE = 263,
    DEF = 264,
    DO = 265,
    ELSE = 266,
    EXIT = 267,
    FLOAT = 268,
    FOR = 269,
    IF = 270,
    INT = 271,
    NUL = 272,
    OBJECT = 273,
    PRINT = 274,
    PRINTLN = 275,
    REPEAT = 276,
    RETURN = 277,
    READ = 278,
    STRING = 279,
    TO = 280,
    TYPE = 281,
    VAL = 282,
    VAR = 283,
    WHILE = 284,
    LE_OP = 285,
    GE_OP = 286,
    EQ_OP = 287,
    NE_OP = 288,
    AND_OP = 289,
    OR_OP = 290,
    ID = 291,
    STR = 292,
    NUM = 293,
    DOUBLE = 294,
    _CHAR = 295,
    FALSE = 296,
    TRUE = 297,
    UMINUS = 298
  };
#endif
/* Tokens.  */
#define BOOLEAN 258
#define BREAK 259
#define CHAR 260
#define CASE 261
#define CLASS 262
#define CONTINUE 263
#define DEF 264
#define DO 265
#define ELSE 266
#define EXIT 267
#define FLOAT 268
#define FOR 269
#define IF 270
#define INT 271
#define NUL 272
#define OBJECT 273
#define PRINT 274
#define PRINTLN 275
#define REPEAT 276
#define RETURN 277
#define READ 278
#define STRING 279
#define TO 280
#define TYPE 281
#define VAL 282
#define VAR 283
#define WHILE 284
#define LE_OP 285
#define GE_OP 286
#define EQ_OP 287
#define NE_OP 288
#define AND_OP 289
#define OR_OP 290
#define ID 291
#define STR 292
#define NUM 293
#define DOUBLE 294
#define _CHAR 295
#define FALSE 296
#define TRUE 297
#define UMINUS 298

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 14 "parser.y" /* yacc.c:1909  */

	int ival;
	double dval;
	char cval;
	bool bval;
	string *sval;
	class idInfo *info;
	int type;

#line 150 "y.tab.hpp" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_HPP_INCLUDED  */
