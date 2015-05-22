/* A Bison parser, made by GNU Bison 1.875.  */

/* Skeleton parser for Yacc-like parsing with Bison,
   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002 Free Software Foundation, Inc.

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
   Foundation, Inc., 59 Temple Place - Suite 330,
   Boston, MA 02111-1307, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

/* Tokens.  */
#if 0 
# define FDO_CONSTRAINT_YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum fdo_constraint_yytokentype {
     FdoToken_NULL = 258,
     FdoToken_TRUE = 259,
     FdoToken_FALSE = 260,
     FdoToken_DATE = 261,
     FdoToken_TIME = 262,
     FdoToken_TIMESTAMP = 263,
     FdoToken_GEOMFROMTEXT = 264,
     FdoToken_AND = 265,
     FdoToken_OR = 266,
     FdoToken_NOT = 267,
     FdoToken_LIKE = 268,
     FdoToken_IN = 269,
     FdoToken_BEYOND = 270,
     FdoToken_WITHINDISTANCE = 271,
     FdoToken_CONTAINS = 272,
     FdoToken_COVEREDBY = 273,
     FdoToken_CROSSES = 274,
     FdoToken_DISJOINT = 275,
     FdoToken_ENVELOPEINTERSECTS = 276,
     FdoToken_EQUALS = 277,
     FdoToken_INTERSECTS = 278,
     FdoToken_INSIDE = 279,
     FdoToken_OVERLAPS = 280,
     FdoToken_TOUCHES = 281,
     FdoToken_WITHIN = 282,
     FdoToken_RELATE = 283,
     FdoToken_IDENTIFIER = 284,
     FdoToken_PARAMETER = 285,
     FdoToken_STRING = 286,
     FdoToken_INTEGER = 287,
     FdoToken_INT64 = 288,
     FdoToken_DOUBLE = 289,
     FdoToken_DATETIME = 290,
     FdoToken_BLOB = 291,
     FdoToken_CLOB = 292,
     FdoToken_Add = 293,
     FdoToken_Subtract = 294,
     FdoToken_Multiply = 295,
     FdoToken_Divide = 296,
     FdoToken_Negate = 297,
     FdoToken_EQ = 298,
     FdoToken_NE = 299,
     FdoToken_GT = 300,
     FdoToken_GE = 301,
     FdoToken_LT = 302,
     FdoToken_LE = 303,
     FdoToken_LeftParenthesis = 304,
     FdoToken_RightParenthesis = 305,
     FdoToken_LeftSquareBrackets = 306,
     FdoToken_RightSquareBrackets = 307,
     FdoToken_Comma = 308,
     FdoToken_Dot = 309,
     FdoToken_Colon = 310,
     FdoToken_AS = 311,
     FdoToken_BETWEEN = 312
   };
#endif
#define FdoToken_NULL 258
#define FdoToken_TRUE 259
#define FdoToken_FALSE 260
#define FdoToken_DATE 261
#define FdoToken_TIME 262
#define FdoToken_TIMESTAMP 263
#define FdoToken_GEOMFROMTEXT 264
#define FdoToken_AND 265
#define FdoToken_OR 266
#define FdoToken_NOT 267
#define FdoToken_LIKE 268
#define FdoToken_IN 269
#define FdoToken_BEYOND 270
#define FdoToken_WITHINDISTANCE 271
#define FdoToken_CONTAINS 272
#define FdoToken_COVEREDBY 273
#define FdoToken_CROSSES 274
#define FdoToken_DISJOINT 275
#define FdoToken_ENVELOPEINTERSECTS 276
#define FdoToken_EQUALS 277
#define FdoToken_INTERSECTS 278
#define FdoToken_INSIDE 279
#define FdoToken_OVERLAPS 280
#define FdoToken_TOUCHES 281
#define FdoToken_WITHIN 282
#define FdoToken_RELATE 283
#define FdoToken_IDENTIFIER 284
#define FdoToken_PARAMETER 285
#define FdoToken_STRING 286
#define FdoToken_INTEGER 287
#define FdoToken_INT64 288
#define FdoToken_DOUBLE 289
#define FdoToken_DATETIME 290
#define FdoToken_BLOB 291
#define FdoToken_CLOB 292
#define FdoToken_Add 293
#define FdoToken_Subtract 294
#define FdoToken_Multiply 295
#define FdoToken_Divide 296
#define FdoToken_Negate 297
#define FdoToken_EQ 298
#define FdoToken_NE 299
#define FdoToken_GT 300
#define FdoToken_GE 301
#define FdoToken_LT 302
#define FdoToken_LE 303
#define FdoToken_LeftParenthesis 304
#define FdoToken_RightParenthesis 305
#define FdoToken_LeftSquareBrackets 306
#define FdoToken_RightSquareBrackets 307
#define FdoToken_Comma 308
#define FdoToken_Dot 309
#define FdoToken_Colon 310
#define FdoToken_AS 311
#define FdoToken_BETWEEN 312




#if ! defined (FDO_CONSTRAINT_YYSTYPE) && ! defined (FDO_CONSTRAINT_YYSTYPE_IS_DECLARED)

typedef union _FDO_CONSTRAINT_YYSTYPE
{
	FdoIDisposable*	m_node;		// constraint parse tree node
	FdoInt32		m_id;		// enumerations, keywords, ...
	FdoInt32		m_integer;	// integer values (Int8, Int16, Int32 )
	FdoInt64		m_int64;	// 64bit integer values 
	double			m_double;	// floating point values (single(float), double)
	FdoString*		m_string;	// string
	_FdoDateTime	m_datetime;	// date time
} FDO_CONSTRAINT_YYSTYPE;
/* Line 1248 of yacc.c.  */

# define fdo_constraint_yystype FDO_CONSTRAINT_YYSTYPE /* obsolescent; will be withdrawn */
# define FDO_CONSTRAINT_YYSTYPE_IS_DECLARED 1
# define FDO_CONSTRAINT_YYSTYPE_IS_TRIVIAL 1
#endif




