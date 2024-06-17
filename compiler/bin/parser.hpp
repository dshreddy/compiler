/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     BEG = 258,
     END = 259,
     DECL = 260,
     BEGDECL = 261,
     ENDDECL = 262,
     T_INT = 263,
     T_FLOAT = 264,
     READ = 265,
     WRITE = 266,
     IF = 267,
     THEN = 268,
     ELSE = 269,
     ENDIF = 270,
     FOR = 271,
     WHILE = 272,
     BREAK = 273,
     RET = 274,
     ID = 275,
     NUM = 276,
     FLOAT = 277,
     EQEQ = 278,
     LE = 279,
     GE = 280,
     NE = 281,
     INCR = 282,
     UMINUS = 283
   };
#endif
/* Tokens.  */
#define BEG 258
#define END 259
#define DECL 260
#define BEGDECL 261
#define ENDDECL 262
#define T_INT 263
#define T_FLOAT 264
#define READ 265
#define WRITE 266
#define IF 267
#define THEN 268
#define ELSE 269
#define ENDIF 270
#define FOR 271
#define WHILE 272
#define BREAK 273
#define RET 274
#define ID 275
#define NUM 276
#define FLOAT 277
#define EQEQ 278
#define LE 279
#define GE 280
#define NE 281
#define INCR 282
#define UMINUS 283




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 59 "./src/compiler.y"
{ 

	struct var_name { 

		char name[100]; 
		int val;
		float fval;
        struct node *nd;

	} nd_obj; 

}
/* Line 1529 of yacc.c.  */
#line 118 "./bin/parser.hpp"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

