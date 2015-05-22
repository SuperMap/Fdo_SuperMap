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

/* Written by Richard Stallman by simplifying the original so called
   ``semantic'' parser.  */

/* All symbols defined below should begin with fdo_constraint_yy or FDO_CONSTRAINT_YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define FDO_CONSTRAINT_YYBISON 1

/* Skeleton name.  */
#define FDO_CONSTRAINT_YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define FDO_CONSTRAINT_YYPURE 0

/* Using locations.  */
#define FDO_CONSTRAINT_YYLSP_NEEDED 0



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




/* Copy the first part of user declarations.  */



#include <FdoStd.h>
#include <Fdo/Expression/StringValue.h>
#include <Fdo/Expression/Int32Value.h>
#include <Fdo/Expression/Int64Value.h>
#include <Fdo/Expression/DoubleValue.h>
#include <Fdo/Expression/DateTimeValue.h>
#include <Fdo/Expression/BooleanValue.h>
#include <Fdo/Schema/PropertyValueConstraintRange.h>
#include <Fdo/Schema/PropertyValueConstraintList.h>
#include <Fdo/Expression/DataValueCollection.h>
#include <Parse/Types.h>
#include <Parse/Parse.h>

#pragma warning(disable:4102)	// unreferenced labels in fdo_constraint_yyConstraint.cpp



/* Enabling traces.  */
#ifndef FDO_CONSTRAINT_YYDEBUG
# define FDO_CONSTRAINT_YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef FDO_CONSTRAINT_YYERROR_VERBOSE
# undef FDO_CONSTRAINT_YYERROR_VERBOSE
# define FDO_CONSTRAINT_YYERROR_VERBOSE 1
#else
# define FDO_CONSTRAINT_YYERROR_VERBOSE 0
#endif

#if ! defined (FDO_CONSTRAINT_YYSTYPE) && ! defined (FDO_CONSTRAINT_YYSTYPE_IS_DECLARED)

typedef union FDO_CONSTRAINT_YYSTYPE _FDO_CONSTRAINT_YYSTYPE
{
	FdoIDisposable*	m_node;		// constraint parse tree node
	FdoInt32		m_id;		// enumerations, keywords, ...
	FdoInt32		m_integer;	// integer values (Int8, Int16, Int32 )
	FdoInt64		m_int64;	// 64bit integer values 
	double			m_double;	// floating point values (single(float), double)
	FdoString*		m_string;	// string
	_FdoDateTime	m_datetime;	// date time
 
/* Line 191 of yacc.c.  */

# define fdo_constraint_yystype FDO_CONSTRAINT_YYSTYPE /* obsolescent; will be withdrawn */
# define FDO_CONSTRAINT_YYSTYPE_IS_DECLARED 1
# define FDO_CONSTRAINT_YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 214 of yacc.c.  */


#if ! defined (fdo_constraint_yyoverflow) || FDO_CONSTRAINT_YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# if FDO_CONSTRAINT_YYSTACK_USE_ALLOCA
#  define FDO_CONSTRAINT_YYSTACK_ALLOC alloca
# else
#  ifndef FDO_CONSTRAINT_YYSTACK_USE_ALLOCA
#   if defined (alloca) || defined (_ALLOCA_H)
#    define FDO_CONSTRAINT_YYSTACK_ALLOC alloca
#   else
#    ifdef __GNUC__
#     define FDO_CONSTRAINT_YYSTACK_ALLOC __builtin_alloca
#    endif
#   endif
#  endif
# endif

# ifdef FDO_CONSTRAINT_YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning. */
#  define FDO_CONSTRAINT_YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
# else
#  if defined (__STDC__) || defined (__cplusplus)
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   define FDO_CONSTRAINT_YYSIZE_T size_t
#  endif
#  define FDO_CONSTRAINT_YYSTACK_ALLOC malloc
#  define FDO_CONSTRAINT_YYSTACK_FREE free
# endif
#endif /* ! defined (fdo_constraint_yyoverflow) || FDO_CONSTRAINT_YYERROR_VERBOSE */


#if (! defined (fdo_constraint_yyoverflow) \
     && (! defined (__cplusplus) \
	 || (FDO_CONSTRAINT_YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union fdo_constraint_yyalloc
{
  short fdo_constraint_yyss;
  FDO_CONSTRAINT_YYSTYPE fdo_constraint_yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define FDO_CONSTRAINT_YYSTACK_GAP_MAXIMUM (sizeof (union fdo_constraint_yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define FDO_CONSTRAINT_YYSTACK_BYTES(N) \
     ((N) * (sizeof (short) + sizeof (FDO_CONSTRAINT_YYSTYPE))				\
      + FDO_CONSTRAINT_YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef FDO_CONSTRAINT_YYCOPY
#  if 1 < __GNUC__
#   define FDO_CONSTRAINT_YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define FDO_CONSTRAINT_YYCOPY(To, From, Count)		\
      do					\
	{					\
	  register FDO_CONSTRAINT_YYSIZE_T fdo_constraint_yyi;		\
	  for (fdo_constraint_yyi = 0; fdo_constraint_yyi < (Count); fdo_constraint_yyi++)	\
	    (To)[fdo_constraint_yyi] = (From)[fdo_constraint_yyi];		\
	}					\
      while (0)
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables FDO_CONSTRAINT_YYSIZE and FDO_CONSTRAINT_YYSTACKSIZE give the old and new number of
   elements in the stack, and FDO_CONSTRAINT_YYPTR gives the new location of the
   stack.  Advance FDO_CONSTRAINT_YYPTR to a properly aligned location for the next
   stack.  */
# define FDO_CONSTRAINT_YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	FDO_CONSTRAINT_YYSIZE_T fdo_constraint_yynewbytes;						\
	FDO_CONSTRAINT_YYCOPY (&fdo_constraint_yyptr->Stack, Stack, fdo_constraint_yysize);				\
	Stack = &fdo_constraint_yyptr->Stack;						\
	fdo_constraint_yynewbytes = fdo_constraint_yystacksize * sizeof (*Stack) + FDO_CONSTRAINT_YYSTACK_GAP_MAXIMUM; \
	fdo_constraint_yyptr += fdo_constraint_yynewbytes / sizeof (*fdo_constraint_yyptr);				\
      }									\
    while (0)

#endif

#if defined (__STDC__) || defined (__cplusplus)
   typedef signed char fdo_constraint_yysigned_char;
#else
   typedef short fdo_constraint_yysigned_char;
#endif

/* FDO_CONSTRAINT_YYFINAL -- State number of the termination state. */
#define FDO_CONSTRAINT_YYFINAL  21
/* FDO_CONSTRAINT_YYLAST -- Last index in FDO_CONSTRAINT_YYTABLE.  */
#define FDO_CONSTRAINT_YYLAST   108

/* FDO_CONSTRAINT_YYNTOKENS -- Number of terminals. */
#define FDO_CONSTRAINT_YYNTOKENS  63
/* FDO_CONSTRAINT_YYNNTS -- Number of nonterminals. */
#define FDO_CONSTRAINT_YYNNTS  20
/* FDO_CONSTRAINT_YYNRULES -- Number of rules. */
#define FDO_CONSTRAINT_YYNRULES  54
/* FDO_CONSTRAINT_YYNRULES -- Number of states. */
#define FDO_CONSTRAINT_YYNSTATES  101

/* FDO_CONSTRAINT_YYTRANSLATE(FDO_CONSTRAINT_YYLEX) -- Bison symbol number corresponding to FDO_CONSTRAINT_YYLEX.  */
#define FDO_CONSTRAINT_YYUNDEFTOK  2
#define FDO_CONSTRAINT_YYMAXUTOK   312

#define FDO_CONSTRAINT_YYTRANSLATE(FDO_CONSTRAINT_YYX) 						\
  ((unsigned int) (FDO_CONSTRAINT_YYX) <= FDO_CONSTRAINT_YYMAXUTOK ? fdo_constraint_yytranslate[FDO_CONSTRAINT_YYX] : FDO_CONSTRAINT_YYUNDEFTOK)

/* FDO_CONSTRAINT_YYTRANSLATE[FDO_CONSTRAINT_YYLEX] -- Bison symbol number corresponding to FDO_CONSTRAINT_YYLEX.  */
static const unsigned char fdo_constraint_yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      58,    59,     2,     2,    60,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    61,     2,    62,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if FDO_CONSTRAINT_YYDEBUG
/* FDO_CONSTRAINT_YYPRHS[FDO_CONSTRAINT_YYN] -- Index of the first RHS symbol of rule number FDO_CONSTRAINT_YYN in
   FDO_CONSTRAINT_YYRHS.  */
static const unsigned char fdo_constraint_yyprhs[] =
{
       0,     0,     3,     5,     7,    11,    13,    15,    17,    19,
      21,    23,    25,    29,    33,    37,    41,    47,    53,    54,
      56,    60,    64,    68,    74,    78,    84,    88,    94,    98,
     104,   108,   114,   115,   117,   121,   125,   127,   129,   131,
     133,   135,   137,   139,   141,   143,   145,   147,   149,   151,
     153,   155,   157,   159,   163
};

/* FDO_CONSTRAINT_YYRHS -- A `-1'-separated list of the rules' RHS. */
static const fdo_constraint_yysigned_char fdo_constraint_yyrhs[] =
{
      64,     0,    -1,    65,    -1,     1,    -1,    58,    65,    59,
      -1,    66,    -1,    67,    -1,    68,    -1,    69,    -1,    70,
      -1,    72,    -1,    73,    -1,    69,    10,    70,    -1,    69,
      10,    73,    -1,    72,    10,    70,    -1,    72,    10,    73,
      -1,    82,    57,    75,    10,    75,    -1,    82,    14,    58,
      74,    59,    -1,    -1,    71,    -1,    58,    68,    59,    -1,
      68,    11,    68,    -1,    82,    45,    75,    -1,    58,    82,
      45,    75,    59,    -1,    82,    47,    75,    -1,    58,    82,
      47,    75,    59,    -1,    82,    43,    75,    -1,    58,    82,
      43,    75,    59,    -1,    82,    46,    75,    -1,    58,    82,
      46,    75,    59,    -1,    82,    48,    75,    -1,    58,    82,
      48,    75,    59,    -1,    -1,    75,    -1,    74,    60,    75,
      -1,    58,    75,    59,    -1,    76,    -1,    81,    -1,    80,
      -1,    78,    -1,    79,    -1,    77,    -1,    36,    -1,    37,
      -1,     3,    -1,     4,    -1,     5,    -1,    31,    -1,    32,
      -1,    33,    -1,    34,    -1,    35,    -1,    29,    -1,    61,
      82,    62,    -1,    58,    82,    59,    -1
};

/* FDO_CONSTRAINT_YYRLINE[FDO_CONSTRAINT_YYN] -- source line where rule number FDO_CONSTRAINT_YYN was defined.  */
static const unsigned short fdo_constraint_yyrline[] =
{
       0,   119,   119,   120,   124,   128,   129,   130,   146,   154,
     162,   170,   178,   187,   196,   205,   218,   231,   251,   254,
     261,   265,   293,   298,   306,   311,   319,   324,   332,   337,
     345,   350,   358,   361,   368,   377,   379,   382,   384,   386,
     388,   390,   392,   394,   396,   401,   402,   405,   408,   411,
     414,   417,   421,   423,   425
};
#endif

#if FDO_CONSTRAINT_YYDEBUG || FDO_CONSTRAINT_YYERROR_VERBOSE
/* FDO_CONSTRAINT_YYTNME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at FDO_CONSTRAINT_YYNTOKENS, nonterminals. */
static const char *const fdo_constraint_yytname[] =
{
  "$end", "error", "$undefined", "FdoToken_NULL", "FdoToken_TRUE", 
  "FdoToken_FALSE", "FdoToken_DATE", "FdoToken_TIME", 
  "FdoToken_TIMESTAMP", "FdoToken_GEOMFROMTEXT", "FdoToken_AND", 
  "FdoToken_OR", "FdoToken_NOT", "FdoToken_LIKE", "FdoToken_IN", 
  "FdoToken_BEYOND", "FdoToken_WITHINDISTANCE", "FdoToken_CONTAINS", 
  "FdoToken_COVEREDBY", "FdoToken_CROSSES", "FdoToken_DISJOINT", 
  "FdoToken_ENVELOPEINTERSECTS", "FdoToken_EQUALS", "FdoToken_INTERSECTS", 
  "FdoToken_INSIDE", "FdoToken_OVERLAPS", "FdoToken_TOUCHES", 
  "FdoToken_WITHIN", "FdoToken_RELATE", "FdoToken_IDENTIFIER", 
  "FdoToken_PARAMETER", "FdoToken_STRING", "FdoToken_INTEGER", 
  "FdoToken_INT64", "FdoToken_DOUBLE", "FdoToken_DATETIME", 
  "FdoToken_BLOB", "FdoToken_CLOB", "FdoToken_Add", "FdoToken_Subtract", 
  "FdoToken_Multiply", "FdoToken_Divide", "FdoToken_Negate", 
  "FdoToken_EQ", "FdoToken_NE", "FdoToken_GT", "FdoToken_GE", 
  "FdoToken_LT", "FdoToken_LE", "FdoToken_LeftParenthesis", 
  "FdoToken_RightParenthesis", "FdoToken_LeftSquareBrackets", 
  "FdoToken_RightSquareBrackets", "FdoToken_Comma", "FdoToken_Dot", 
  "FdoToken_Colon", "FdoToken_AS", "FdoToken_BETWEEN", "'('", "')'", 
  "','", "'['", "']'", "$accept", "fdo", "Constraint", "BEConstraint", 
  "INConstraint", "ORConstraint", "GTConstraint", "LTConstraint", 
  "EqualConstraint", "GEConstraint", "LEConstraint", 
  "DataValueCollection", "DataValue", "boolean", "string", "integer", 
  "int64", "double", "datetime", "Identifier", 0
};
#endif

# ifdef FDO_CONSTRAINT_YYPRINT
/* FDO_CONSTRAINT_YYTOKNUM[FDO_CONSTRAINT_YYLEX-NUM] -- Internal token number corresponding to
   token FDO_CONSTRAINT_YYLEX-NUM.  */
static const unsigned short fdo_constraint_yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    40,    41,
      44,    91,    93
};
# endif

/* FDO_CONSTRAINT_YYR1[FDO_CONSTRAINT_YYN] -- Symbol number of symbol that rule FDO_CONSTRAINT_YYN derives.  */
static const unsigned char fdo_constraint_yyr1[] =
{
       0,    63,    64,    64,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    66,    67,    68,    68,
      68,    68,    69,    69,    70,    70,    71,    71,    72,    72,
      73,    73,    74,    74,    74,    75,    75,    75,    75,    75,
      75,    75,    75,    75,    75,    76,    76,    77,    78,    79,
      80,    81,    82,    82,    82
};

/* FDO_CONSTRAINT_YYR2[FDO_CONSTRAINT_YYN] -- Number of symbols composing right hand side of rule FDO_CONSTRAINT_YYN.  */
static const unsigned char fdo_constraint_yyr2[] =
{
       0,     2,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     3,     3,     3,     3,     5,     5,     0,     1,
       3,     3,     3,     5,     3,     5,     3,     5,     3,     5,
       3,     5,     0,     1,     3,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3
};

/* FDO_CONSTRAINT_YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when FDO_CONSTRAINT_YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const unsigned char fdo_constraint_yydefact[] =
{
       0,     3,    52,    18,     0,     0,     2,     5,     6,     7,
       8,     9,    19,    10,    11,     0,     0,     0,     0,     0,
       0,     1,    18,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     4,    20,     0,     0,     0,     0,     0,    54,
       0,    53,    18,    21,     0,     0,    12,    13,     0,    14,
      15,    32,    44,    45,    46,    47,    48,    49,    50,    51,
      42,    43,     0,    26,    36,    41,    39,    40,    38,    37,
      22,    28,    24,    30,     0,    26,    22,    28,     0,     0,
       0,     0,     0,     0,    33,     0,     0,    27,    23,    29,
      25,    31,     0,     0,    17,     0,    35,    16,     0,     0,
      34
};

/* FDO_CONSTRAINT_YYDEFGOTO[NTERM-NUM]. */
static const fdo_constraint_yysigned_char fdo_constraint_yydefgoto[] =
{
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    83,    63,    64,    65,    66,    67,    68,    69,    48
};

/* FDO_CONSTRAINT_YYPACT[STATE-NUM] -- Index in FDO_CONSTRAINT_YYTABLE of the portion describing
   STATE-NUM.  */
#define FDO_CONSTRAINT_YYPACT_NINF -40
static const fdo_constraint_yysigned_char fdo_constraint_yypact[] =
{
      12,   -40,   -40,    -4,    27,    17,   -40,   -40,   -40,    20,
      18,   -40,   -40,    24,   -40,    36,   -10,    -6,    15,    27,
     -24,   -40,    38,    47,    47,     6,    11,    11,    11,    11,
      11,    11,   -40,   -40,    11,    11,    11,    11,    11,   -40,
      21,   -40,    38,    20,    34,    27,   -40,   -40,   -21,   -40,
     -40,    11,   -40,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,    11,   -40,   -40,   -40,   -40,   -40,   -40,   -40,
     -40,   -40,   -40,   -40,    79,    31,    32,    35,    39,    41,
      -6,   -37,   -29,   -39,   -40,    42,    11,   -40,   -40,   -40,
     -40,   -40,    11,    11,   -40,    11,   -40,   -40,    39,    41,
     -40
};

/* FDO_CONSTRAINT_YYPGOTO[NTERM-NUM].  */
static const fdo_constraint_yysigned_char fdo_constraint_yypgoto[] =
{
     -40,   -40,    89,   -40,   -40,    29,   -40,    16,   -40,   -40,
      63,   -40,   -27,   -40,   -40,   -40,   -40,   -40,   -40,    33
};

/* FDO_CONSTRAINT_YYTABLE[FDO_CONSTRAINT_YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what FDO_CONSTRAINT_YYDEFACT says.
   If FDO_CONSTRAINT_YYTABLE_NINF, syntax error.  */
#define FDO_CONSTRAINT_YYTABLE_NINF -19
static const fdo_constraint_yysigned_char fdo_constraint_yytable[] =
{
      70,    71,    72,    73,    74,    22,    34,    75,    76,    77,
      78,    79,   -18,     1,    52,    53,    54,    21,    92,    93,
      94,    95,    39,   -18,    84,     2,    29,    30,    23,    25,
      39,    22,    17,    15,    24,    85,    18,    20,    41,    46,
      49,     2,    55,    56,    57,    58,    59,    60,    61,    32,
      25,    43,    40,    33,     3,    44,     2,     4,    34,    97,
      35,    36,    37,    38,    51,    98,    99,     2,   100,    62,
       3,    80,    31,     4,    39,    81,     2,    26,    82,    26,
      39,    27,    28,    29,    30,    19,    47,    50,     4,    86,
      87,    88,    16,    31,    89,     0,    42,     0,    90,     4,
      91,    96,     0,     0,     0,    45,     0,     0,     4
};

static const fdo_constraint_yysigned_char fdo_constraint_yycheck[] =
{
      27,    28,    29,    30,    31,    11,    43,    34,    35,    36,
      37,    38,     0,     1,     3,     4,     5,     0,    47,    48,
      59,    60,    59,    11,    51,    29,    47,    48,    10,    14,
      59,    11,     3,     0,    10,    62,     3,     4,    62,    23,
      24,    29,    31,    32,    33,    34,    35,    36,    37,    59,
      14,    22,    19,    59,    58,    22,    29,    61,    43,    86,
      45,    46,    47,    48,    58,    92,    93,    29,    95,    58,
      58,    42,    57,    61,    59,    42,    29,    43,    45,    43,
      59,    45,    46,    47,    48,    58,    23,    24,    61,    10,
      59,    59,     3,    57,    59,    -1,    58,    -1,    59,    61,
      59,    59,    -1,    -1,    -1,    58,    -1,    -1,    61
};

/* FDO_CONSTRAINT_YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const unsigned char fdo_constraint_yystos[] =
{
       0,     1,    29,    58,    61,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    82,    65,    68,    82,    58,
      82,     0,    11,    10,    10,    14,    43,    45,    46,    47,
      48,    57,    59,    59,    43,    45,    46,    47,    48,    59,
      82,    62,    58,    68,    82,    58,    70,    73,    82,    70,
      73,    58,     3,     4,     5,    31,    32,    33,    34,    35,
      36,    37,    58,    75,    76,    77,    78,    79,    80,    81,
      75,    75,    75,    75,    75,    75,    75,    75,    75,    75,
      68,    82,    82,    74,    75,    75,    10,    59,    59,    59,
      59,    59,    47,    48,    59,    60,    59,    75,    75,    75,
      75
};

#if ! defined (FDO_CONSTRAINT_YYSIZE_T) && defined (__SIZE_TYPE__)
# define FDO_CONSTRAINT_YYSIZE_T __SIZE_TYPE__
#endif
#if ! defined (FDO_CONSTRAINT_YYSIZE_T) && defined (size_t)
# define FDO_CONSTRAINT_YYSIZE_T size_t
#endif
#if ! defined (FDO_CONSTRAINT_YYSIZE_T)
# if defined (__STDC__) || defined (__cplusplus)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define FDO_CONSTRAINT_YYSIZE_T size_t
# endif
#endif
#if ! defined (FDO_CONSTRAINT_YYSIZE_T)
# define FDO_CONSTRAINT_YYSIZE_T unsigned int
#endif

#define fdo_constraint_yyerrok		(fdo_constraint_yyerrstatus = 0)
#define fdo_constraint_yyclearin	(pParse->fdo_constraint_yychar = FDO_CONSTRAINT_YYEMPTY)
#define FDO_CONSTRAINT_YYEMPTY		(-2)
#define FDO_CONSTRAINT_YYEOF		0

#define FDO_CONSTRAINT_YYACCEPT	goto fdo_constraint_yyacceptlab
#define FDO_CONSTRAINT_YYABORT		goto fdo_constraint_yyabortlab
#define FDO_CONSTRAINT_YYERROR		goto fdo_constraint_yyerrlab1

/* Like FDO_CONSTRAINT_YYERROR except do call fdo_constraint_yyerror.  This remains here temporarily
   to ease the transition to the new meaning of FDO_CONSTRAINT_YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define FDO_CONSTRAINT_YYFAIL		goto fdo_constraint_yyerrlab

#define FDO_CONSTRAINT_YYRECOVERING()  (!!fdo_constraint_yyerrstatus)

#define FDO_CONSTRAINT_YYBACKUP(Token, Value)					\
do								\
  if (pParse->fdo_constraint_yychar == FDO_CONSTRAINT_YYEMPTY && fdo_constraint_yylen == 1)				\
    {								\
      pParse->fdo_constraint_yychar = (Token);						\
      pParse->fdo_constraint_yylval = (Value);						\
      fdo_constraint_yytoken = FDO_CONSTRAINT_YYTRANSLATE (pParse->fdo_constraint_yychar);				\
      FDO_CONSTRAINT_YYPOPSTACK;						\
      goto fdo_constraint_yybackup;						\
    }								\
  else								\
    { 								\
      fdo_constraint_yyerror(pParse,"syntax error: cannot back up");\
      FDO_CONSTRAINT_YYERROR;							\
    }								\
while (0)

#define FDO_CONSTRAINT_YYTERROR	1
#define FDO_CONSTRAINT_YYERRCODE	256

/* FDO_CONSTRAINT_YYLLOC_DEFAULT -- Compute the default location (before the actions
   are run).  */

#ifndef FDO_CONSTRAINT_YYLLOC_DEFAULT
# define FDO_CONSTRAINT_YYLLOC_DEFAULT(Current, Rhs, N)         \
  Current.first_line   = Rhs[1].first_line;      \
  Current.first_column = Rhs[1].first_column;    \
  Current.last_line    = Rhs[N].last_line;       \
  Current.last_column  = Rhs[N].last_column;
#endif

/* FDO_CONSTRAINT_YYLEX -- calling `fdo_constraint_yylex' with the right arguments.  */

#ifdef FDO_CONSTRAINT_YYLEX_PARAM
# define FDO_CONSTRAINT_YYLEX fdo_constraint_yylex (FDO_CONSTRAINT_YYLEX_PARAM)
#else
# define FDO_CONSTRAINT_YYLEX fdo_constraint_yylex(pParse)
#endif

/* Enable debugging if requested.  */
#if FDO_CONSTRAINT_YYDEBUG

# ifndef FDO_CONSTRAINT_YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define FDO_CONSTRAINT_YYFPRINTF fprintf
# endif

# define FDO_CONSTRAINT_YYDPRINTF(Args)			\
do {						\
  if (pParse->fdo_constraint_yydebug)					\
    FDO_CONSTRAINT_YYFPRINTF Args;				\
} while (0)

# define FDO_CONSTRAINT_YYDSYMPRINT(Args)			\
do {						\
  if (pParse->fdo_constraint_yydebug)					\
    fdo_constraint_yysymprint Args;				\
} while (0)

# define FDO_CONSTRAINT_YYDSYMPRINTF(Title, Token, Value, Location)		\
do {								\
  if (pParse->fdo_constraint_yydebug)							\
    {								\
      FDO_CONSTRAINT_YYFPRINTF (stderr, "%s ", Title);				\
      fdo_constraint_yysymprint (stderr, 					\
                  Token, Value);	\
      FDO_CONSTRAINT_YYFPRINTF (stderr, "\n");					\
    }								\
} while (0)

/*------------------------------------------------------------------.
| fdo_constraint_yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (cinluded).                                                   |
`------------------------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
fdo_constraint_yy_stack_print (short *bottom, short *top)
#else
static void
fdo_constraint_yy_stack_print (bottom, top)
    short *bottom;
    short *top;
#endif
{
  FDO_CONSTRAINT_YYFPRINTF (stderr, "Stack now");
  for (/* Nothing. */; bottom <= top; ++bottom)
    FDO_CONSTRAINT_YYFPRINTF (stderr, " %d", *bottom);
  FDO_CONSTRAINT_YYFPRINTF (stderr, "\n");
}

# define FDO_CONSTRAINT_YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (pParse->fdo_constraint_yydebug)							\
    fdo_constraint_yy_stack_print ((Bottom), (Top));				\
} while (0)


/*------------------------------------------------.
| Report that the FDO_CONSTRAINT_YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
fdo_constraint_yy_reduce_print (int fdo_constraint_yyrule)
#else
static void
fdo_constraint_yy_reduce_print (fdo_constraint_yyrule)
    int fdo_constraint_yyrule;
#endif
{
  int fdo_constraint_yyi;
  unsigned int pParse->fdo_constraint_yylineno = fdo_constraint_yyrline[fdo_constraint_yyrule];
  FDO_CONSTRAINT_YYFPRINTF (stderr, "Reducing stack by rule %d (line %u), ",
             fdo_constraint_yyrule - 1, pParse->fdo_constraint_yylineno);
  /* Print the symbols being reduced, and their result.  */
  for (fdo_constraint_yyi = fdo_constraint_yyprhs[fdo_constraint_yyrule]; 0 <= fdo_constraint_yyrhs[fdo_constraint_yyi]; fdo_constraint_yyi++)
    FDO_CONSTRAINT_YYFPRINTF (stderr, "%s ", fdo_constraint_yytname [fdo_constraint_yyrhs[fdo_constraint_yyi]]);
  FDO_CONSTRAINT_YYFPRINTF (stderr, "-> %s\n", fdo_constraint_yytname [fdo_constraint_yyr1[fdo_constraint_yyrule]]);
}

# define FDO_CONSTRAINT_YY_REDUCE_PRINT(Rule)		\
do {					\
  if (pParse->fdo_constraint_yydebug)				\
    fdo_constraint_yy_reduce_print (Rule);		\
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
#else /* !FDO_CONSTRAINT_YYDEBUG */
# define FDO_CONSTRAINT_YYDPRINTF(Args)
# define FDO_CONSTRAINT_YYDSYMPRINT(Args)
# define FDO_CONSTRAINT_YYDSYMPRINTF(Title, Token, Value, Location)
# define FDO_CONSTRAINT_YY_STACK_PRINT(Bottom, Top)
# define FDO_CONSTRAINT_YY_REDUCE_PRINT(Rule)
#endif /* !FDO_CONSTRAINT_YYDEBUG */


/* FDO_CONSTRAINT_YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	FDO_CONSTRAINT_YYINITDEPTH
# define FDO_CONSTRAINT_YYINITDEPTH 200
#endif

/* FDO_CONSTRAINT_YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   SIZE_MAX < FDO_CONSTRAINT_YYSTACK_BYTES (FDO_CONSTRAINT_YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#if FDO_CONSTRAINT_YYMAXDEPTH == 0
# undef FDO_CONSTRAINT_YYMAXDEPTH
#endif

#ifndef FDO_CONSTRAINT_YYMAXDEPTH
# define FDO_CONSTRAINT_YYMAXDEPTH 10000
#endif



#if FDO_CONSTRAINT_YYERROR_VERBOSE

# ifndef fdo_constraint_yystrlen
#  if defined (__GLIBC__) && defined (_STRING_H)
#   define fdo_constraint_yystrlen strlen
#  else
/* Return the length of FDO_CONSTRAINT_YYSTR.  */
static FDO_CONSTRAINT_YYSIZE_T
#   if defined (__STDC__) || defined (__cplusplus)
fdo_constraint_yystrlen (const char *fdo_constraint_yystr)
#   else
fdo_constraint_yystrlen (fdo_constraint_yystr)
     const char *fdo_constraint_yystr;
#   endif
{
  register const char *fdo_constraint_yys = fdo_constraint_yystr;

  while (*fdo_constraint_yys++ != '\0')
    continue;

  return fdo_constraint_yys - fdo_constraint_yystr - 1;
}
#  endif
# endif

# ifndef fdo_constraint_yystpcpy
#  if defined (__GLIBC__) && defined (_STRING_H) && defined (_GNU_SOURCE)
#   define fdo_constraint_yystpcpy stpcpy
#  else
/* Copy FDO_CONSTRAINT_YYSRC to FDO_CONSTRAINT_YYDEST, returning the address of the terminating '\0' in
   FDO_CONSTRAINT_YYDEST.  */
static char *
#   if defined (__STDC__) || defined (__cplusplus)
fdo_constraint_yystpcpy (char *fdo_constraint_yydest, const char *fdo_constraint_yysrc)
#   else
fdo_constraint_yystpcpy (fdo_constraint_yydest, fdo_constraint_yysrc)
     char *fdo_constraint_yydest;
     const char *fdo_constraint_yysrc;
#   endif
{
  register char *fdo_constraint_yyd = fdo_constraint_yydest;
  register const char *fdo_constraint_yys = fdo_constraint_yysrc;

  while ((*fdo_constraint_yyd++ = *fdo_constraint_yys++) != '\0')
    continue;

  return fdo_constraint_yyd - 1;
}
#  endif
# endif

#endif /* !FDO_CONSTRAINT_YYERROR_VERBOSE */



#if FDO_CONSTRAINT_YYDEBUG
/*--------------------------------.
| Print this symbol on FDO_CONSTRAINT_YYOUTPUT.  |
`--------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
fdo_constraint_yysymprint (FILE *fdo_constraint_yyoutput, int fdo_constraint_yytype, FDO_CONSTRAINT_YYSTYPE *fdo_constraint_yyvaluep)
#else
static void
fdo_constraint_yysymprint (fdo_constraint_yyoutput, fdo_constraint_yytype, fdo_constraint_yyvaluep)
    FILE *fdo_constraint_yyoutput;
    int fdo_constraint_yytype;
    FDO_CONSTRAINT_YYSTYPE *fdo_constraint_yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) fdo_constraint_yyvaluep;

  if (fdo_constraint_yytype < FDO_CONSTRAINT_YYNTOKENS)
    {
      FDO_CONSTRAINT_YYFPRINTF (fdo_constraint_yyoutput, "token %s (", fdo_constraint_yytname[fdo_constraint_yytype]);
# ifdef FDO_CONSTRAINT_YYPRINT
      FDO_CONSTRAINT_YYPRINT (fdo_constraint_yyoutput, fdo_constraint_yytoknum[fdo_constraint_yytype], *fdo_constraint_yyvaluep);
# endif
    }
  else
    FDO_CONSTRAINT_YYFPRINTF (fdo_constraint_yyoutput, "nterm %s (", fdo_constraint_yytname[fdo_constraint_yytype]);

  switch (fdo_constraint_yytype)
    {
      default:
        break;
    }
  FDO_CONSTRAINT_YYFPRINTF (fdo_constraint_yyoutput, ")");
}

#endif /* ! FDO_CONSTRAINT_YYDEBUG */
/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

#if defined (__STDC__) || defined (__cplusplus)
static void
fdo_constraint_yydestruct (int fdo_constraint_yytype, FDO_CONSTRAINT_YYSTYPE *fdo_constraint_yyvaluep)
#else
static void
fdo_constraint_yydestruct (fdo_constraint_yytype, fdo_constraint_yyvaluep)
    int fdo_constraint_yytype;
    FDO_CONSTRAINT_YYSTYPE *fdo_constraint_yyvaluep;
#endif
{
  /* Pacify ``unused variable'' warnings.  */
  (void) fdo_constraint_yyvaluep;
/*  switch (fdo_constraint_yytype)
    {

      default:
        break;
    }
	*/
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef FDO_CONSTRAINT_YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int fdo_constraint_yyparse (void *FDO_CONSTRAINT_YYPARSE_PARAM);
# else
int fdo_constraint_yyparse(FdoCommonParse* pParse);
# endif
#else /* ! FDO_CONSTRAINT_YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int fdo_constraint_yyparse(FdoCommonParse* pParse);
#else
int fdo_constraint_yyparse(FdoCommonParse* pParse);
#endif
#endif /* ! FDO_CONSTRAINT_YYPARSE_PARAM */



/* The lookahead symbol.  */

/* The semantic value of the lookahead symbol.  */

/* Number of syntax errors so far.  */



/*----------.
| fdo_constraint_yyparse.  |
`----------*/

#ifdef FDO_CONSTRAINT_YYPARSE_PARAM
# if defined (__STDC__) || defined (__cplusplus)
int fdo_constraint_yyparse (void *FDO_CONSTRAINT_YYPARSE_PARAM)
# else
int fdo_constraint_yyparse (FDO_CONSTRAINT_YYPARSE_PARAM)
  void *FDO_CONSTRAINT_YYPARSE_PARAM;
# endif
#else /* ! FDO_CONSTRAINT_YYPARSE_PARAM */
#if defined (__STDC__) || defined (__cplusplus)
int
fdo_constraint_yyparse(FdoCommonParse* pParse)
#else
int
fdo_constraint_yyparse(FdoCommonParse* pParse)

#endif
#endif
{
  
  register int fdo_constraint_yystate;
  register int fdo_constraint_yyn;
  int fdo_constraint_yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int fdo_constraint_yyerrstatus;
  /* Lookahead token as an internal (translated) token number.  */
  int fdo_constraint_yytoken = 0;

  /* Three stacks and their tools:
     `fdo_constraint_yyss': related to states,
     `fdo_constraint_yyvs': related to semantic values,
     `fdo_constraint_yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow fdo_constraint_yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  short *fdo_constraint_yyss = pParse->fdo_constraint_yyss;

  /* The semantic value stack.  */
  FDO_CONSTRAINT_YYSTYPE *fdo_constraint_yyvs = pParse->fdo_constraint_yyvs;



#define FDO_CONSTRAINT_YYPOPSTACK   (pParse->fdo_constraint_yyvsp--, pParse->fdo_constraint_yyssp--)

  FDO_CONSTRAINT_YYSIZE_T fdo_constraint_yystacksize = FDO_CONSTRAINT_YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */


  /* When reducing, the number of symbols on the RHS of the reduced
     rule.  */
  int fdo_constraint_yylen;

  FDO_CONSTRAINT_YYDPRINTF ((stderr, "Starting parse\n"));

  fdo_constraint_yystate = 0;
  fdo_constraint_yyerrstatus = 0;
  pParse->fdo_constraint_yynerrs = 0;
  pParse->fdo_constraint_yychar = FDO_CONSTRAINT_YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  pParse->fdo_constraint_yyssp = fdo_constraint_yyss;
  pParse->fdo_constraint_yyvsp = fdo_constraint_yyvs;

  goto fdo_constraint_yysetstate;

/*------------------------------------------------------------.
| fdo_constraint_yynewstate -- Push a new state, which is found in fdo_constraint_yystate.  |
`------------------------------------------------------------*/
 fdo_constraint_yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed. so pushing a state here evens the stacks.
     */
  pParse->fdo_constraint_yyssp++;

 fdo_constraint_yysetstate:
  *pParse->fdo_constraint_yyssp = fdo_constraint_yystate;

  if (fdo_constraint_yyss + fdo_constraint_yystacksize - 1 <= pParse->fdo_constraint_yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      FDO_CONSTRAINT_YYSIZE_T fdo_constraint_yysize = pParse->fdo_constraint_yyssp - fdo_constraint_yyss + 1;

#ifdef fdo_constraint_yyoverflow
      {
	/* Give user a chance to reallocate the stack. Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	FDO_CONSTRAINT_YYSTYPE *fdo_constraint_yyvs1 = fdo_constraint_yyvs;
	short *fdo_constraint_yyss1 = fdo_constraint_yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if fdo_constraint_yyoverflow is a macro.  */
	fdo_constraint_yyoverflow ("parser stack overflow",
		    &fdo_constraint_yyss1, fdo_constraint_yysize * sizeof (*pParse->fdo_constraint_yyssp),
		    &fdo_constraint_yyvs1, fdo_constraint_yysize * sizeof (*pParse->fdo_constraint_yyvsp),

		    &fdo_constraint_yystacksize);

	fdo_constraint_yyss = fdo_constraint_yyss1;
	fdo_constraint_yyvs = fdo_constraint_yyvs1;
      }
#else /* no fdo_constraint_yyoverflow */
# ifndef FDO_CONSTRAINT_YYSTACK_RELOCATE
      goto fdo_constraint_yyoverflowlab;
# else
      /* Extend the stack our own way.  */
      if (FDO_CONSTRAINT_YYMAXDEPTH <= fdo_constraint_yystacksize)
	goto fdo_constraint_yyoverflowlab;
      fdo_constraint_yystacksize *= 2;
      if (FDO_CONSTRAINT_YYMAXDEPTH < fdo_constraint_yystacksize)
	fdo_constraint_yystacksize = FDO_CONSTRAINT_YYMAXDEPTH;

      {
	short *fdo_constraint_yyss1 = fdo_constraint_yyss;
	union fdo_constraint_yyalloc *fdo_constraint_yyptr =
	  (union fdo_constraint_yyalloc *) FDO_CONSTRAINT_YYSTACK_ALLOC (FDO_CONSTRAINT_YYSTACK_BYTES (fdo_constraint_yystacksize));
	if (! fdo_constraint_yyptr)
	  goto fdo_constraint_yyoverflowlab;
	FDO_CONSTRAINT_YYSTACK_RELOCATE (fdo_constraint_yyss);
	FDO_CONSTRAINT_YYSTACK_RELOCATE (fdo_constraint_yyvs);

#  undef FDO_CONSTRAINT_YYSTACK_RELOCATE
	if (fdo_constraint_yyss1 != pParse->fdo_constraint_yyss)
	  FDO_CONSTRAINT_YYSTACK_FREE (fdo_constraint_yyss1);
      }
# endif
#endif /* no fdo_constraint_yyoverflow */

      pParse->fdo_constraint_yyssp = fdo_constraint_yyss + fdo_constraint_yysize - 1;
      pParse->fdo_constraint_yyvsp = fdo_constraint_yyvs + fdo_constraint_yysize - 1;


      FDO_CONSTRAINT_YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) fdo_constraint_yystacksize));

      if (fdo_constraint_yyss + fdo_constraint_yystacksize - 1 <= pParse->fdo_constraint_yyssp)
	FDO_CONSTRAINT_YYABORT;
    }

  FDO_CONSTRAINT_YYDPRINTF ((stderr, "Entering state %d\n", fdo_constraint_yystate));

  goto fdo_constraint_yybackup;

/*-----------.
| fdo_constraint_yybackup.  |
`-----------*/
fdo_constraint_yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* fdo_constraint_yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  fdo_constraint_yyn = fdo_constraint_yypact[fdo_constraint_yystate];
  if (fdo_constraint_yyn == FDO_CONSTRAINT_YYPACT_NINF)
    goto fdo_constraint_yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* FDO_CONSTRAINT_YYCHAR is either FDO_CONSTRAINT_YYEMPTY or FDO_CONSTRAINT_YYEOF or a valid lookahead symbol.  */
  if (pParse->fdo_constraint_yychar == FDO_CONSTRAINT_YYEMPTY)
    {
      FDO_CONSTRAINT_YYDPRINTF ((stderr, "Reading a token: "));
      pParse->fdo_constraint_yychar = FDO_CONSTRAINT_YYLEX;
    }

  if (pParse->fdo_constraint_yychar <= FDO_CONSTRAINT_YYEOF)
    {
      pParse->fdo_constraint_yychar = fdo_constraint_yytoken = FDO_CONSTRAINT_YYEOF;
      FDO_CONSTRAINT_YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      fdo_constraint_yytoken = FDO_CONSTRAINT_YYTRANSLATE (pParse->fdo_constraint_yychar);
      FDO_CONSTRAINT_YYDSYMPRINTF ("Next token is", fdo_constraint_yytoken, &pParse->fdo_constraint_yylval, &fdo_constraint_yylloc);
    }

  /* If the proper action on seeing token FDO_CONSTRAINT_YYTOKEN is to reduce or to
     detect an error, take that action.  */
  fdo_constraint_yyn += fdo_constraint_yytoken;
  if (fdo_constraint_yyn < 0 || FDO_CONSTRAINT_YYLAST < fdo_constraint_yyn || fdo_constraint_yycheck[fdo_constraint_yyn] != fdo_constraint_yytoken)
    goto fdo_constraint_yydefault;
  fdo_constraint_yyn = fdo_constraint_yytable[fdo_constraint_yyn];
  if (fdo_constraint_yyn <= 0)
    {
      if (fdo_constraint_yyn == 0 || fdo_constraint_yyn == FDO_CONSTRAINT_YYTABLE_NINF)
	goto fdo_constraint_yyerrlab;
      fdo_constraint_yyn = -fdo_constraint_yyn;
      goto fdo_constraint_yyreduce;
    }

  if (fdo_constraint_yyn == FDO_CONSTRAINT_YYFINAL)
    FDO_CONSTRAINT_YYACCEPT;

  /* Shift the lookahead token.  */
  FDO_CONSTRAINT_YYDPRINTF ((stderr, "Shifting token %s, ", fdo_constraint_yytname[fdo_constraint_yytoken]));

  /* Discard the token being shifted unless it is eof.  */
  if (pParse->fdo_constraint_yychar != FDO_CONSTRAINT_YYEOF)
    pParse->fdo_constraint_yychar = FDO_CONSTRAINT_YYEMPTY;

  *++pParse->fdo_constraint_yyvsp = pParse->fdo_constraint_yylval;


  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (fdo_constraint_yyerrstatus)
    fdo_constraint_yyerrstatus--;

  fdo_constraint_yystate = fdo_constraint_yyn;
  goto fdo_constraint_yynewstate;


/*-----------------------------------------------------------.
| fdo_constraint_yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
fdo_constraint_yydefault:
  fdo_constraint_yyn = fdo_constraint_yydefact[fdo_constraint_yystate];
  if (fdo_constraint_yyn == 0)
    goto fdo_constraint_yyerrlab;
  goto fdo_constraint_yyreduce;


/*-----------------------------.
| fdo_constraint_yyreduce -- Do a reduction.  |
`-----------------------------*/
fdo_constraint_yyreduce:
  /* fdo_constraint_yyn is the number of a rule to reduce with.  */
  fdo_constraint_yylen = fdo_constraint_yyr2[fdo_constraint_yyn];

  /* If FDO_CONSTRAINT_YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets FDO_CONSTRAINT_YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to FDO_CONSTRAINT_YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that FDO_CONSTRAINT_YYVAL may be used uninitialized.  */
  pParse->fdo_constraint_yyval = pParse->fdo_constraint_yyvsp[1-fdo_constraint_yylen];


  FDO_CONSTRAINT_YY_REDUCE_PRINT (fdo_constraint_yyn);
  switch (fdo_constraint_yyn)
    {
        case 2:

    {pParse->SetRoot(Node_Copy(L"Constraint", pParse->fdo_constraint_yyvsp[0].m_node));	FDO_CONSTRAINT_YYACCEPT;}
    break;

  case 3:

    {Node_Trace(L"ERROR!");	pParse->SetRoot((FdoIDisposable*)NULL);	FDO_CONSTRAINT_YYABORT;}
    break;

  case 4:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[-1].m_node;
					}
    break;

  case 5:

    {pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[0].m_node;}
    break;

  case 6:

    {pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[0].m_node;}
    break;

  case 7:

    {
						FdoPropertyValueConstraintList* list = FdoPropertyValueConstraintList::Create();
						FdoDataValueCollection* dvCol = list->GetConstraintList();
						FdoDataValue* dvTemp = NULL;
						int count = ((FdoDataValueCollection*)pParse->fdo_constraint_yyvsp[0].m_node)->GetCount();
						for (int i = 0; i < count; i++)
						{
							dvTemp = ((FdoDataValueCollection*)pParse->fdo_constraint_yyvsp[0].m_node)->GetItem(i);
							dvCol->Insert(i, dvTemp);
							FDO_SAFE_RELEASE(dvTemp);
						}
						pParse->fdo_constraint_yyval.m_node=Node_Add(L"Constraint List",list);
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node); 
						FDO_SAFE_RELEASE(dvCol);
					}
    break;

  case 8:

    {
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create();
						range->SetMinValue((FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node);
						range->SetMinInclusive(false);
						pParse->fdo_constraint_yyval.m_node=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node); 
					}
    break;

  case 9:

    {
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create();
						range->SetMaxValue((FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node);
						range->SetMaxInclusive(false);
						pParse->fdo_constraint_yyval.m_node=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node); 
					}
    break;

  case 10:

    {
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create();
						range->SetMinValue((FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node);
						range->SetMinInclusive(true);
						pParse->fdo_constraint_yyval.m_node=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node); 
					}
    break;

  case 11:

    {
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create();
						range->SetMaxValue((FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node);
						range->SetMaxInclusive(true);
						pParse->fdo_constraint_yyval.m_node=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node); 
					}
    break;

  case 12:

    {
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create((FdoDataValue*)pParse->fdo_constraint_yyvsp[-2].m_node, (FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node);
						range->SetMinInclusive(false);
						range->SetMaxInclusive(false);
						pParse->fdo_constraint_yyval.m_node=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-2].m_node); 
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node);
					}
    break;

  case 13:

    {
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create((FdoDataValue*)pParse->fdo_constraint_yyvsp[-2].m_node, (FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node);
						range->SetMinInclusive(false);
						range->SetMaxInclusive(true);
						pParse->fdo_constraint_yyval.m_node=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-2].m_node); 
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node);
					}
    break;

  case 14:

    {
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create((FdoDataValue*)pParse->fdo_constraint_yyvsp[-2].m_node, (FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node);
						range->SetMinInclusive(true);
						range->SetMaxInclusive(false);
						pParse->fdo_constraint_yyval.m_node=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-2].m_node); 
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node);
					}
    break;

  case 15:

    {
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create((FdoDataValue*)pParse->fdo_constraint_yyvsp[-2].m_node, (FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node);
						range->SetMinInclusive(true);
						range->SetMaxInclusive(true);
						pParse->fdo_constraint_yyval.m_node=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-2].m_node); 
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node);
					}
    break;

  case 16:

    {
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create((FdoDataValue*)pParse->fdo_constraint_yyvsp[-2].m_node, (FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node);
						range->SetMinInclusive(true);
						range->SetMaxInclusive(true);
						pParse->fdo_constraint_yyval.m_node=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-4].m_node); 
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-2].m_node); 
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node);
					}
    break;

  case 17:

    {
						FdoPropertyValueConstraintList* list = FdoPropertyValueConstraintList::Create();
						FdoDataValueCollection* dvCol = list->GetConstraintList();
						FdoDataValue* dvTemp = NULL;
						int count = ((FdoDataValueCollection*)pParse->fdo_constraint_yyvsp[-1].m_node)->GetCount();
						for (int i = 0; i < count; i++)
						{
							dvTemp = ((FdoDataValueCollection*)pParse->fdo_constraint_yyvsp[-1].m_node)->GetItem(i);
							dvCol->Insert(i, dvTemp);
							FDO_SAFE_RELEASE(dvTemp);
						}
						pParse->fdo_constraint_yyval.m_node=Node_Add(L"Constraint List",list);
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-4].m_node); 
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-1].m_node); 
						FDO_SAFE_RELEASE(dvCol);
					}
    break;

  case 18:

    {
						pParse->fdo_constraint_yyval.m_node=pParse->AddNodeToDelete(FdoDataValueCollection::Create());
					}
    break;

  case 19:

    {
						pParse->fdo_constraint_yyval.m_node=pParse->AddNodeToDelete(FdoDataValueCollection::Create()); 
						((FdoDataValueCollection*)pParse->fdo_constraint_yyval.m_node)->Add((FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node); 
						Node_Trace(L"DataValue Arg 1,");
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node); 
					}
    break;

  case 20:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[-1].m_node;
					}
    break;

  case 21:

    {
						pParse->fdo_constraint_yyval.m_node=pParse->AddNodeToDelete(FdoDataValueCollection::Create()); 
						
						FdoDataValue* dvTemp = NULL;
						
						int count = ((FdoDataValueCollection*)pParse->fdo_constraint_yyvsp[-2].m_node)->GetCount();
						for (int i = 0; i < count; i++)
						{
							dvTemp = ((FdoDataValueCollection*)pParse->fdo_constraint_yyvsp[-2].m_node)->GetItem(i);
							((FdoDataValueCollection*)pParse->fdo_constraint_yyval.m_node)->Add(dvTemp); 
							FDO_SAFE_RELEASE(dvTemp);
						}
						
						count = ((FdoDataValueCollection*)pParse->fdo_constraint_yyvsp[0].m_node)->GetCount();
						for (int i = 0; i < count; i++)
						{
							dvTemp = ((FdoDataValueCollection*)pParse->fdo_constraint_yyvsp[0].m_node)->GetItem(i);
							((FdoDataValueCollection*)pParse->fdo_constraint_yyval.m_node)->Add(dvTemp); 
							FDO_SAFE_RELEASE(dvTemp);
						}				
		
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-2].m_node); 
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node);
					}
    break;

  case 22:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[0].m_node;
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-2].m_node); 
					}
    break;

  case 23:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[-1].m_node;
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-3].m_node); 
					}
    break;

  case 24:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[0].m_node;
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-2].m_node); 
					}
    break;

  case 25:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[-1].m_node;
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-3].m_node); 
					}
    break;

  case 26:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[0].m_node;
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-2].m_node); 
					}
    break;

  case 27:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[-1].m_node;
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-3].m_node); 
					}
    break;

  case 28:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[0].m_node;
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-2].m_node); 
					}
    break;

  case 29:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[-1].m_node;
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-3].m_node); 
					}
    break;

  case 30:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[0].m_node;
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-2].m_node); 
					}
    break;

  case 31:

    {
						pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[-1].m_node;
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[-3].m_node); 
					}
    break;

  case 32:

    {
						pParse->fdo_constraint_yyval.m_node=pParse->AddNodeToDelete(FdoDataValueCollection::Create());
					}
    break;

  case 33:

    {
						pParse->fdo_constraint_yyval.m_node=pParse->AddNodeToDelete(FdoDataValueCollection::Create()); 
						((FdoDataValueCollection*)pParse->fdo_constraint_yyval.m_node)->Add((FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node); 
						Node_Trace(L"DataValue Arg 1,");
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node); 
					}
    break;

  case 34:

    {
						((FdoDataValueCollection*)pParse->fdo_constraint_yyval.m_node)->Add((FdoDataValue*)pParse->fdo_constraint_yyvsp[0].m_node); 
						Node_Trace(L"DataValue Arg N,");
						FDO_SAFE_RELEASE(pParse->fdo_constraint_yyvsp[0].m_node); 
					}
    break;

  case 35:

    {pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[-1].m_node;}
    break;

  case 36:

    {pParse->fdo_constraint_yyval.m_node=Node_Copy(L"boolean", pParse->fdo_constraint_yyvsp[0].m_node);}
    break;

  case 37:

    {pParse->fdo_constraint_yyval.m_node=Node_Copy(L"datetime", pParse->fdo_constraint_yyvsp[0].m_node);}
    break;

  case 38:

    {pParse->fdo_constraint_yyval.m_node=Node_Copy(L"double", pParse->fdo_constraint_yyvsp[0].m_node);}
    break;

  case 39:

    {pParse->fdo_constraint_yyval.m_node=Node_Copy(L"integer", pParse->fdo_constraint_yyvsp[0].m_node);}
    break;

  case 40:

    {pParse->fdo_constraint_yyval.m_node=Node_Copy(L"int64", pParse->fdo_constraint_yyvsp[0].m_node);}
    break;

  case 41:

    {pParse->fdo_constraint_yyval.m_node=Node_Copy(L"string", pParse->fdo_constraint_yyvsp[0].m_node);}
    break;

  case 42:

    {pParse->fdo_constraint_yyval.m_node=Node_Copy(L"TODO:BLOB", NULL);}
    break;

  case 43:

    {pParse->fdo_constraint_yyval.m_node=Node_Copy(L"TODO:CLOB", NULL);}
    break;

  case 44:

    {pParse->fdo_constraint_yyval.m_node=Node_Add(L"NULL", FdoDataValue::Create(FdoDataType_Boolean));}
    break;

  case 45:

    {pParse->fdo_constraint_yyval.m_node=Node_Add(L"TRUE", FdoBooleanValue::Create(true));}
    break;

  case 46:

    {pParse->fdo_constraint_yyval.m_node=Node_Add(L"FALSE", FdoBooleanValue::Create(false));}
    break;

  case 47:

    {pParse->fdo_constraint_yyval.m_node=Node_Add(L"STRING", FdoDataValue::Create(pParse->fdo_constraint_yyvsp[0].m_string));}
    break;

  case 48:

    {pParse->fdo_constraint_yyval.m_node=Node_Add(L"INTEGER", FdoInt32Value::Create(pParse->fdo_constraint_yyvsp[0].m_integer));}
    break;

  case 49:

    {pParse->fdo_constraint_yyval.m_node=Node_Add(L"INT64", FdoInt64Value::Create(pParse->fdo_constraint_yyvsp[0].m_int64));}
    break;

  case 50:

    {pParse->fdo_constraint_yyval.m_node=Node_Add(L"DOUBLE", FdoDoubleValue::Create(pParse->fdo_constraint_yyvsp[0].m_double));}
    break;

  case 51:

    {pParse->fdo_constraint_yyval.m_node=Node_Add(L"DateTime", FdoDataValue::Create(pParse->fdo_constraint_yyvsp[0].m_datetime));}
    break;

  case 52:

    {pParse->fdo_constraint_yyval.m_node = Node_Add(L"IDENTIFIER", FdoIdentifier::Create(pParse->fdo_constraint_yyvsp[0].m_string));}
    break;

  case 53:

    {pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[-1].m_node;}
    break;

  case 54:

    {pParse->fdo_constraint_yyval.m_node = pParse->fdo_constraint_yyvsp[-1].m_node;}
    break;


    }

/* Line 991 of yacc.c.  */


  pParse->fdo_constraint_yyvsp -= fdo_constraint_yylen;
  pParse->fdo_constraint_yyssp -= fdo_constraint_yylen;


  FDO_CONSTRAINT_YY_STACK_PRINT (fdo_constraint_yyss, pParse->fdo_constraint_yyssp);

  *++pParse->fdo_constraint_yyvsp = pParse->fdo_constraint_yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  fdo_constraint_yyn = fdo_constraint_yyr1[fdo_constraint_yyn];

  fdo_constraint_yystate = fdo_constraint_yypgoto[fdo_constraint_yyn - FDO_CONSTRAINT_YYNTOKENS] + *pParse->fdo_constraint_yyssp;
  if (0 <= fdo_constraint_yystate && fdo_constraint_yystate <= FDO_CONSTRAINT_YYLAST && fdo_constraint_yycheck[fdo_constraint_yystate] == *pParse->fdo_constraint_yyssp)
    fdo_constraint_yystate = fdo_constraint_yytable[fdo_constraint_yystate];
  else
    fdo_constraint_yystate = fdo_constraint_yydefgoto[fdo_constraint_yyn - FDO_CONSTRAINT_YYNTOKENS];

  goto fdo_constraint_yynewstate;


/*------------------------------------.
| fdo_constraint_yyerrlab -- here on detecting error |
`------------------------------------*/
fdo_constraint_yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!fdo_constraint_yyerrstatus)
    {
      ++pParse->fdo_constraint_yynerrs;
#if FDO_CONSTRAINT_YYERROR_VERBOSE
      fdo_constraint_yyn = fdo_constraint_yypact[fdo_constraint_yystate];

      if (FDO_CONSTRAINT_YYPACT_NINF < fdo_constraint_yyn && fdo_constraint_yyn < FDO_CONSTRAINT_YYLAST)
	{
	  FDO_CONSTRAINT_YYSIZE_T fdo_constraint_yysize = 0;
	  int fdo_constraint_yytype = FDO_CONSTRAINT_YYTRANSLATE (pParse->fdo_constraint_yychar);
	  char *fdo_constraint_yymsg;
	  int fdo_constraint_yyx, fdo_constraint_yycount;

	  fdo_constraint_yycount = 0;
	  /* Start FDO_CONSTRAINT_YYX at -FDO_CONSTRAINT_YYN if negative to avoid negative indexes in
	     FDO_CONSTRAINT_YYCHECK.  */
	  for (fdo_constraint_yyx = fdo_constraint_yyn < 0 ? -fdo_constraint_yyn : 0;
	       fdo_constraint_yyx < (int) (sizeof (fdo_constraint_yytname) / sizeof (char *)); fdo_constraint_yyx++)
	    if (fdo_constraint_yycheck[fdo_constraint_yyx + fdo_constraint_yyn] == fdo_constraint_yyx && fdo_constraint_yyx != FDO_CONSTRAINT_YYTERROR)
	      fdo_constraint_yysize += fdo_constraint_yystrlen (fdo_constraint_yytname[fdo_constraint_yyx]) + 15, fdo_constraint_yycount++;
	  fdo_constraint_yysize += fdo_constraint_yystrlen ("syntax error, unexpected ") + 1;
	  fdo_constraint_yysize += fdo_constraint_yystrlen (fdo_constraint_yytname[fdo_constraint_yytype]);
	  fdo_constraint_yymsg = (char *) FDO_CONSTRAINT_YYSTACK_ALLOC (fdo_constraint_yysize);
	  if (fdo_constraint_yymsg != 0)
	    {
	      char *fdo_constraint_yyp = fdo_constraint_yystpcpy (fdo_constraint_yymsg, "syntax error, unexpected ");
	      fdo_constraint_yyp = fdo_constraint_yystpcpy (fdo_constraint_yyp, fdo_constraint_yytname[fdo_constraint_yytype]);

	      if (fdo_constraint_yycount < 5)
		{
		  fdo_constraint_yycount = 0;
		  for (fdo_constraint_yyx = fdo_constraint_yyn < 0 ? -fdo_constraint_yyn : 0;
		       fdo_constraint_yyx < (int) (sizeof (fdo_constraint_yytname) / sizeof (char *));
		       fdo_constraint_yyx++)
		    if (fdo_constraint_yycheck[fdo_constraint_yyx + fdo_constraint_yyn] == fdo_constraint_yyx && fdo_constraint_yyx != FDO_CONSTRAINT_YYTERROR)
		      {
			const char *fdo_constraint_yyq = ! fdo_constraint_yycount ? ", expecting " : " or ";
			fdo_constraint_yyp = fdo_constraint_yystpcpy (fdo_constraint_yyp, fdo_constraint_yyq);
			fdo_constraint_yyp = fdo_constraint_yystpcpy (fdo_constraint_yyp, fdo_constraint_yytname[fdo_constraint_yyx]);
			fdo_constraint_yycount++;
		      }
		}
	      fdo_constraint_yyerror(pParse,fdo_constraint_yymsg);
	      FDO_CONSTRAINT_YYSTACK_FREE (fdo_constraint_yymsg);
	    }
	  else
	    fdo_constraint_yyerror(pParse,"syntax error; also virtual memory exhausted");
	}
      else
#endif /* FDO_CONSTRAINT_YYERROR_VERBOSE */
	fdo_constraint_yyerror(pParse,"syntax error");
    }



  if (fdo_constraint_yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      /* Return failure if at end of input.  */
      if (pParse->fdo_constraint_yychar == FDO_CONSTRAINT_YYEOF)
        {
	  /* Pop the error token.  */
          FDO_CONSTRAINT_YYPOPSTACK;
	  /* Pop the rest of the stack.  */
	  while (fdo_constraint_yyss < pParse->fdo_constraint_yyssp)
	    {
	      FDO_CONSTRAINT_YYDSYMPRINTF ("Error: popping", fdo_constraint_yystos[*pParse->fdo_constraint_yyssp], pParse->fdo_constraint_yyvsp, fdo_constraint_yylsp);
	      fdo_constraint_yydestruct (fdo_constraint_yystos[*pParse->fdo_constraint_yyssp], pParse->fdo_constraint_yyvsp);
	      FDO_CONSTRAINT_YYPOPSTACK;
	    }
	  FDO_CONSTRAINT_YYABORT;
        }

      FDO_CONSTRAINT_YYDSYMPRINTF ("Error: discarding", fdo_constraint_yytoken, &pParse->fdo_constraint_yylval, &fdo_constraint_yylloc);
      fdo_constraint_yydestruct (fdo_constraint_yytoken, &pParse->fdo_constraint_yylval);
      pParse->fdo_constraint_yychar = FDO_CONSTRAINT_YYEMPTY;

    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto fdo_constraint_yyerrlab2;


/*----------------------------------------------------.
| fdo_constraint_yyerrlab1 -- error raised explicitly by an action.  |
`----------------------------------------------------*/
fdo_constraint_yyerrlab1:

  /* Suppress GCC warning that fdo_constraint_yyerrlab1 is unused when no action
     invokes FDO_CONSTRAINT_YYERROR.  */
#if defined (__GNUC_MINOR__) && 2093 <= (__GNUC__ * 1000 + __GNUC_MINOR__)
  __attribute__ ((__unused__))
#endif


  goto fdo_constraint_yyerrlab2;


/*---------------------------------------------------------------.
| fdo_constraint_yyerrlab2 -- pop states until the error token can be shifted.  |
`---------------------------------------------------------------*/
fdo_constraint_yyerrlab2:
  fdo_constraint_yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      fdo_constraint_yyn = fdo_constraint_yypact[fdo_constraint_yystate];
      if (fdo_constraint_yyn != FDO_CONSTRAINT_YYPACT_NINF)
	{
	  fdo_constraint_yyn += FDO_CONSTRAINT_YYTERROR;
	  if (0 <= fdo_constraint_yyn && fdo_constraint_yyn <= FDO_CONSTRAINT_YYLAST && fdo_constraint_yycheck[fdo_constraint_yyn] == FDO_CONSTRAINT_YYTERROR)
	    {
	      fdo_constraint_yyn = fdo_constraint_yytable[fdo_constraint_yyn];
	      if (0 < fdo_constraint_yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (pParse->fdo_constraint_yyssp == fdo_constraint_yyss)
	FDO_CONSTRAINT_YYABORT;

      FDO_CONSTRAINT_YYDSYMPRINTF ("Error: popping", fdo_constraint_yystos[*pParse->fdo_constraint_yyssp], pParse->fdo_constraint_yyvsp, fdo_constraint_yylsp);
      fdo_constraint_yydestruct (fdo_constraint_yystos[fdo_constraint_yystate], pParse->fdo_constraint_yyvsp);
      pParse->fdo_constraint_yyvsp--;
      fdo_constraint_yystate = *--pParse->fdo_constraint_yyssp;

      FDO_CONSTRAINT_YY_STACK_PRINT (fdo_constraint_yyss, pParse->fdo_constraint_yyssp);
    }

  if (fdo_constraint_yyn == FDO_CONSTRAINT_YYFINAL)
    FDO_CONSTRAINT_YYACCEPT;

  FDO_CONSTRAINT_YYDPRINTF ((stderr, "Shifting error token, "));

  *++pParse->fdo_constraint_yyvsp = pParse->fdo_constraint_yylval;


  fdo_constraint_yystate = fdo_constraint_yyn;
  goto fdo_constraint_yynewstate;


/*-------------------------------------.
| fdo_constraint_yyacceptlab -- FDO_CONSTRAINT_YYACCEPT comes here.  |
`-------------------------------------*/
fdo_constraint_yyacceptlab:
  fdo_constraint_yyresult = 0;
  goto fdo_constraint_yyreturn;

/*-----------------------------------.
| fdo_constraint_yyabortlab -- FDO_CONSTRAINT_YYABORT comes here.  |
`-----------------------------------*/
fdo_constraint_yyabortlab:
  fdo_constraint_yyresult = 1;
  goto fdo_constraint_yyreturn;

#ifndef fdo_constraint_yyoverflow
/*----------------------------------------------.
| fdo_constraint_yyoverflowlab -- parser overflow comes here.  |
`----------------------------------------------*/
fdo_constraint_yyoverflowlab:
  fdo_constraint_yyerror(pParse,"parser stack overflow");
  fdo_constraint_yyresult = 2;
  /* Fall through.  */
#endif

fdo_constraint_yyreturn:
#ifndef fdo_constraint_yyoverflow
  if (fdo_constraint_yyss != pParse->fdo_constraint_yyss)
    FDO_CONSTRAINT_YYSTACK_FREE (fdo_constraint_yyss);
#endif
  return fdo_constraint_yyresult;
}




///////////////////////////////////////////////////////////////////////

#include <stdio.h>

FdoInt32 fdo_constraint_yyerror_default(char *str, FdoInt32 lineno)
{
#ifdef FDO_FDO_CONSTRAINT_YYDEBUG
	fprintf(stderr, "line %d: %s\n", lineno, str);
#endif
	return 0;
}

typedef FdoInt32 (*ERRFUNC)(char*, FdoInt32);
static ERRFUNC fdo_constraint_yyerror_func = fdo_constraint_yyerror_default;

FdoInt32 fdo_constraint_yyerror(FdoCommonParse *pParse, char* str)
{
	return (*fdo_constraint_yyerror_func)(str, pParse->fdo_constraint_yylineno);
}

ERRFUNC fdo_constraint_yyerror_set(ERRFUNC func)
{
	ERRFUNC old_func = fdo_constraint_yyerror_func;

	if (func != NULL)
		fdo_constraint_yyerror_func = func;

	return old_func;
}

static void  print_current_token()
{
//TODO: this has not been updated, but it is unused anyway
#ifdef FDO_FDO_CONSTRAINT_YYDEBUG
	char  *token_name;
	
	if( pParse->fdo_constraint_yychar <= FDO_CONSTRAINT_YYMAXTOKEN )
	{
		switch( pParse->fdo_constraint_yychar )
		{
			case IDENTIFIER:
				token_name = pParse->fdo_constraint_yylval.id;
				break;

			default:
				token_name = fdo_constraint_yyname[pParse->fdo_constraint_yychar];
				break;
		}
	}
	else
	{
		token_name = "illegal-name";
	}

	printf( "***  current token is %d (%s)  ***\n", pParse->fdo_constraint_yychar, token_name );
#endif
}

