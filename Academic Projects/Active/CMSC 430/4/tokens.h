/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    INT_LITERAL = 258,             /* INT_LITERAL  */
    CHAR_LITERAL = 259,            /* CHAR_LITERAL  */
    REAL_LITERAL = 260,            /* REAL_LITERAL  */
    HEX_LITERAL = 261,             /* HEX_LITERAL  */
    RELOP = 262,                   /* RELOP  */
    ADDOP = 263,                   /* ADDOP  */
    ANDOP = 264,                   /* ANDOP  */
    MULOP = 265,                   /* MULOP  */
    MODOP = 266,                   /* MODOP  */
    NEGOP = 267,                   /* NEGOP  */
    EXPOP = 268,                   /* EXPOP  */
    IDENTIFIER = 269,              /* IDENTIFIER  */
    LEFT = 270,                    /* LEFT  */
    RIGHT = 271,                   /* RIGHT  */
    ARROW = 272,                   /* ARROW  */
    OROP = 273,                    /* OROP  */
    NOTOP = 274,                   /* NOTOP  */
    WHEN = 275,                    /* WHEN  */
    BEGIN_ = 276,                  /* BEGIN_  */
    END = 277,                     /* END  */
    FUNCTION = 278,                /* FUNCTION  */
    IS = 279,                      /* IS  */
    LIST = 280,                    /* LIST  */
    OF = 281,                      /* OF  */
    RETURNS = 282,                 /* RETURNS  */
    SWITCH = 283,                  /* SWITCH  */
    CASE = 284,                    /* CASE  */
    OTHERS = 285,                  /* OTHERS  */
    ENDSWITCH = 286,               /* ENDSWITCH  */
    IF = 287,                      /* IF  */
    THEN = 288,                    /* THEN  */
    ELSE = 289,                    /* ELSE  */
    ELSIF = 290,                   /* ELSIF  */
    ENDIF = 291,                   /* ENDIF  */
    FOLD = 292,                    /* FOLD  */
    ENDFOLD = 293,                 /* ENDFOLD  */
    CHARACTER = 294,               /* CHARACTER  */
    REAL = 295,                    /* REAL  */
    INTEGER = 296                  /* INTEGER  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "parser.y"


    CharPtr iden;          // for identifiers (usually char*)	
	//merge from Project 4 sample
	Types type; // for types like INTEGER, CHARACTER, REAL // part of change 1.2


#line 113 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
