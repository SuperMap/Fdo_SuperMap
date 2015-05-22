// 
// Copyright (C) 2004-2006  Autodesk, Inc.
// 
// This library is free software; you can redistribute it and/or
// modify it under the terms of version 2.1 of the GNU Lesser
// General Public License as published by the Free Software Foundation.
// 
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.
// 
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

///////////////////////////////////////////////////////////////////////
// Name
//	yyConstraint.y - YACC grammar 
//								
// Synopsis	
//	FdoInt32  fdo_constraint_yyparse(FdoCommonParse* pParse)
//
// Description							
//	Parse a FDO constraint, and build a parse tree for it.
//
// Parameters
//	pParse	pointer to context
//
// Function Value									
//	0 if successful, 1 otherwise (respect YYACCEPT and YYABORT macros).
//	If successful, the root node is set in FdoParse to be returned. 
///////////////////////////////////////////////////////////////////////

%{

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

#pragma warning(disable:4102)	// unreferenced labels in y.tab.c

%}

%union _YYSTYPE
{
	FdoIDisposable*	m_node;		// constraint parse tree node
	FdoInt32		m_id;		// enumerations, keywords, ...
	FdoInt32		m_integer;	// integer values (Int8, Int16, Int32 )
	FdoInt64		m_int64;	// 64bit integer values 
	double			m_double;	// floating point values (single(float), double)
	FdoString*		m_string;	// string
	_FdoDateTime	m_datetime;	// date time
}

// keywords 
// ... data values
%token FdoToken_NULL
%token FdoToken_TRUE FdoToken_FALSE
%token FdoToken_DATE FdoToken_TIME FdoToken_TIMESTAMP
%token FdoToken_GEOMFROMTEXT
// ... operators
%token FdoToken_AND FdoToken_OR FdoToken_NOT FdoToken_LIKE FdoToken_IN
// ... distance operations
%token FdoToken_BEYOND FdoToken_WITHINDISTANCE
// ... spatial operations
%token FdoToken_CONTAINS FdoToken_COVEREDBY FdoToken_CROSSES
%token FdoToken_DISJOINT FdoToken_ENVELOPEINTERSECTS FdoToken_EQUALS FdoToken_INTERSECTS FdoToken_INSIDE
%token FdoToken_OVERLAPS FdoToken_TOUCHES FdoToken_WITHIN
// ... future use
%token FdoToken_RELATE
// data types
%token FdoToken_IDENTIFIER FdoToken_PARAMETER FdoToken_STRING
%token FdoToken_INTEGER  FdoToken_INT64 FdoToken_DOUBLE FdoToken_DATETIME
%token FdoToken_BLOB FdoToken_CLOB
// operators
%token FdoToken_Add FdoToken_Subtract FdoToken_Multiply FdoToken_Divide 
%token FdoToken_Negate
%token FdoToken_EQ FdoToken_NE FdoToken_GT FdoToken_GE FdoToken_LT FdoToken_LE 
%token FdoToken_LeftParenthesis FdoToken_RightParenthesis FdoToken_LeftSquareBrackets FdoToken_RightSquareBrackets
%token FdoToken_Comma FdoToken_Dot FdoToken_Colon FdoToken_AS

// keywords
%token FdoToken_BETWEEN

// expression
%type <m_node>		DataValue DataValueCollection
%type <m_node>		Identifier
%type <m_node>		Constraint GTConstraint GEConstraint EqualConstraint LTConstraint LEConstraint BEConstraint INConstraint ORConstraint

// both
%type <m_node>		double string boolean FdoToken_Negate
%type <m_node>		FdoToken_BLOB FdoToken_CLOB FdoToken_TRUE FdoToken_FALSE
%type <m_node>		FdoToken_NULL FdoToken_GEOMFROMTEXT
%type <m_node>		integer int64 datetime
%type <m_double>	FdoToken_DOUBLE
%type <m_integer>	FdoToken_INTEGER
%type <m_int64>		FdoToken_INT64
%type <m_string>	FdoToken_IDENTIFIER FdoToken_STRING FdoToken_PARAMETER
%type <m_datetime>	FdoToken_DATETIME

// precedence
%left FdoToken_Add FdoToken_Subtract
%left FdoToken_Multiply FdoToken_Divide
%left FdoToken_Negate

%start fdo
%%

fdo : Constraint	{pParse->SetRoot(Node_Copy(L"Constraint", $1));	YYACCEPT;}
	| error			{Node_Trace(L"ERROR!");	pParse->SetRoot((FdoIDisposable*)NULL);	YYABORT;}
	;

Constraint : 
	  '(' Constraint ')'
					{
						$$ = $2;
					}
	| BEConstraint	{$$ = $1;}
	| INConstraint	{$$ = $1;}
	| ORConstraint	
					{
						FdoPropertyValueConstraintList* list = FdoPropertyValueConstraintList::Create();
						FdoDataValueCollection* dvCol = list->GetConstraintList();
						FdoDataValue* dvTemp = NULL;
						int count = ((FdoDataValueCollection*)$1)->GetCount();
						for (int i = 0; i < count; i++)
						{
							dvTemp = ((FdoDataValueCollection*)$1)->GetItem(i);
							dvCol->Insert(i, dvTemp);
							FDO_SAFE_RELEASE(dvTemp);
						}
						$$=Node_Add(L"Constraint List",list);
						FDO_SAFE_RELEASE($1); 
						FDO_SAFE_RELEASE(dvCol);
					}
	| GTConstraint	
					{
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create();
						range->SetMinValue((FdoDataValue*)$1);
						range->SetMinInclusive(false);
						$$=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE($1); 
					}
	| LTConstraint
					{
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create();
						range->SetMaxValue((FdoDataValue*)$1);
						range->SetMaxInclusive(false);
						$$=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE($1); 
					}
	| GEConstraint
					{
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create();
						range->SetMinValue((FdoDataValue*)$1);
						range->SetMinInclusive(true);
						$$=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE($1); 
					}
	| LEConstraint
					{
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create();
						range->SetMaxValue((FdoDataValue*)$1);
						range->SetMaxInclusive(true);
						$$=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE($1); 
					}
	| GTConstraint FdoToken_AND LTConstraint
					{
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create((FdoDataValue*)$1, (FdoDataValue*)$3);
						range->SetMinInclusive(false);
						range->SetMaxInclusive(false);
						$$=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE($1); 
						FDO_SAFE_RELEASE($3);
					}
	| GTConstraint FdoToken_AND LEConstraint
					{
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create((FdoDataValue*)$1, (FdoDataValue*)$3);
						range->SetMinInclusive(false);
						range->SetMaxInclusive(true);
						$$=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE($1); 
						FDO_SAFE_RELEASE($3);
					}
	| GEConstraint FdoToken_AND LTConstraint
					{
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create((FdoDataValue*)$1, (FdoDataValue*)$3);
						range->SetMinInclusive(true);
						range->SetMaxInclusive(false);
						$$=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE($1); 
						FDO_SAFE_RELEASE($3);
					}
	| GEConstraint FdoToken_AND LEConstraint
					{
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create((FdoDataValue*)$1, (FdoDataValue*)$3);
						range->SetMinInclusive(true);
						range->SetMaxInclusive(true);
						$$=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE($1); 
						FDO_SAFE_RELEASE($3);
					}
	;

// All kinds of constraint declarations
BEConstraint :
	 Identifier FdoToken_BETWEEN DataValue FdoToken_AND DataValue
					{
						FdoPropertyValueConstraintRange* range = FdoPropertyValueConstraintRange::Create((FdoDataValue*)$3, (FdoDataValue*)$5);
						range->SetMinInclusive(true);
						range->SetMaxInclusive(true);
						$$=Node_Add(L"Constraint Range", range);
						FDO_SAFE_RELEASE($1); 
						FDO_SAFE_RELEASE($3); 
						FDO_SAFE_RELEASE($5);
					}
	;

INConstraint :
	  Identifier FdoToken_IN '(' DataValueCollection ')'
					{
						FdoPropertyValueConstraintList* list = FdoPropertyValueConstraintList::Create();
						FdoDataValueCollection* dvCol = list->GetConstraintList();
						FdoDataValue* dvTemp = NULL;
						int count = ((FdoDataValueCollection*)$4)->GetCount();
						for (int i = 0; i < count; i++)
						{
							dvTemp = ((FdoDataValueCollection*)$4)->GetItem(i);
							dvCol->Insert(i, dvTemp);
							FDO_SAFE_RELEASE(dvTemp);
						}
						$$=Node_Add(L"Constraint List",list);
						FDO_SAFE_RELEASE($1); 
						FDO_SAFE_RELEASE($4); 
						FDO_SAFE_RELEASE(dvCol);
					}
	;
	 
ORConstraint :
					{
						$$=pParse->AddNodeToDelete(FdoDataValueCollection::Create());
					}
	| EqualConstraint							
					{
						$$=pParse->AddNodeToDelete(FdoDataValueCollection::Create()); 
						((FdoDataValueCollection*)$$)->Add((FdoDataValue*)$1); 
						Node_Trace(L"DataValue Arg 1,");
						FDO_SAFE_RELEASE($1); 
					}
	| '(' ORConstraint ')'
					{
						$$ = $2;
					}
	| ORConstraint FdoToken_OR ORConstraint
					{
						$$=pParse->AddNodeToDelete(FdoDataValueCollection::Create()); 
						
						FdoDataValue* dvTemp = NULL;
						
						int count = ((FdoDataValueCollection*)$1)->GetCount();
						for (int i = 0; i < count; i++)
						{
							dvTemp = ((FdoDataValueCollection*)$1)->GetItem(i);
							((FdoDataValueCollection*)$$)->Add(dvTemp); 
							FDO_SAFE_RELEASE(dvTemp);
						}
						
						count = ((FdoDataValueCollection*)$3)->GetCount();
						for (int i = 0; i < count; i++)
						{
							dvTemp = ((FdoDataValueCollection*)$3)->GetItem(i);
							((FdoDataValueCollection*)$$)->Add(dvTemp); 
							FDO_SAFE_RELEASE(dvTemp);
						}				
		
						FDO_SAFE_RELEASE($1); 
						FDO_SAFE_RELEASE($3);
					}
	;
	 
GTConstraint :
	  Identifier FdoToken_GT DataValue
					{
						$$ = $3;
						FDO_SAFE_RELEASE($1); 
					}
	| '(' Identifier FdoToken_GT DataValue ')'
					{
						$$ = $4;
						FDO_SAFE_RELEASE($2); 
					}
	;

LTConstraint :
	  Identifier FdoToken_LT DataValue
					{
						$$ = $3;
						FDO_SAFE_RELEASE($1); 
					}
	| '(' Identifier FdoToken_LT DataValue ')'
					{
						$$ = $4;
						FDO_SAFE_RELEASE($2); 
					}
	;

EqualConstraint :
	  Identifier FdoToken_EQ DataValue
					{
						$$ = $3;
						FDO_SAFE_RELEASE($1); 
					}
	| '(' Identifier FdoToken_EQ DataValue ')'
					{
						$$ = $4;
						FDO_SAFE_RELEASE($2); 
					}
	;

GEConstraint :
	  Identifier FdoToken_GE DataValue
					{
						$$ = $3;
						FDO_SAFE_RELEASE($1); 
					}
	| '(' Identifier FdoToken_GE DataValue ')'
					{
						$$ = $4;
						FDO_SAFE_RELEASE($2); 
					}
	;

LEConstraint :
	  Identifier FdoToken_LE DataValue
					{
						$$ = $3;
						FDO_SAFE_RELEASE($1); 
					}
	| '(' Identifier FdoToken_LE DataValue ')'
					{
						$$ = $4;
						FDO_SAFE_RELEASE($2); 
					}
	;

DataValueCollection :							
					{
						$$=pParse->AddNodeToDelete(FdoDataValueCollection::Create());
					}
	| DataValue								
					{
						$$=pParse->AddNodeToDelete(FdoDataValueCollection::Create()); 
						((FdoDataValueCollection*)$$)->Add((FdoDataValue*)$1); 
						Node_Trace(L"DataValue Arg 1,");
						FDO_SAFE_RELEASE($1); 
					}
	| DataValueCollection ',' DataValue		
					{
						((FdoDataValueCollection*)$$)->Add((FdoDataValue*)$3); 
						Node_Trace(L"DataValue Arg N,");
						FDO_SAFE_RELEASE($3); 
					}
	;

DataValue :
	'(' DataValue ')'
						{$$ = $2;}
	|  boolean			// e.g. TRUE or FALSE
 						{$$=Node_Copy(L"boolean", $1);}
//	| byte
	| datetime			{$$=Node_Copy(L"datetime", $1);}
//	| decimal
	| double			// double and single precision
 						{$$=Node_Copy(L"double", $1);}
	| integer			// 16bit, 32bit
 						{$$=Node_Copy(L"integer", $1);}
	| int64 			// 64bit
 						{$$=Node_Copy(L"int64", $1);}
	| string			// e.g. 'abc', "abc" (NOT!)
 						{$$=Node_Copy(L"string", $1);}
	| FdoToken_BLOB 	// '{' bytes... '}'	// e.g. BLOB { \x01 \x02 }	// TBD?
						{$$=Node_Copy(L"TODO:BLOB", NULL);}
	| FdoToken_CLOB  	// '{' bytes... '}'	// e.g. CLOB { \x01 \x02 }	// TBD?
						{$$=Node_Copy(L"TODO:CLOB", NULL);}
	| FdoToken_NULL		// e.g. null
						{$$=Node_Add(L"NULL", FdoDataValue::Create(FdoDataType_Boolean));}
 	;

boolean :
	FdoToken_TRUE		{$$=Node_Add(L"TRUE", FdoBooleanValue::Create(true));}
	| FdoToken_FALSE	{$$=Node_Add(L"FALSE", FdoBooleanValue::Create(false));}
	;
string :
	FdoToken_STRING		{$$=Node_Add(L"STRING", FdoDataValue::Create($1));}
	;
integer :
	FdoToken_INTEGER	{$$=Node_Add(L"INTEGER", FdoInt32Value::Create($1));}
	;
int64 :
	FdoToken_INT64  	{$$=Node_Add(L"INT64", FdoInt64Value::Create($1));}
	;
double :
	FdoToken_DOUBLE		{$$=Node_Add(L"DOUBLE", FdoDoubleValue::Create($1));}
	;
datetime :
	FdoToken_DATETIME	{$$=Node_Add(L"DateTime", FdoDataValue::Create($1));}
	;
	
Identifier :			// e.g. "Address.City", "Street", "City", and "Zip Code"
	FdoToken_IDENTIFIER
						{$$ = Node_Add(L"IDENTIFIER", FdoIdentifier::Create($1));}
	| '[' Identifier ']'
						{$$ = $2;}
	| '(' Identifier ')'
						{$$ = $2;}
 	;

%%
///////////////////////////////////////////////////////////////////////

#include <stdio.h>

FdoInt32 yyerror_default(char *str, FdoInt32 lineno)
{
#ifdef FDO_YYDEBUG
	fprintf(stderr, "line %d: %s\n", lineno, str);
#endif
	return 0;
}

typedef FdoInt32 (*ERRFUNC)(char*, FdoInt32);
static ERRFUNC yyerror_func = yyerror_default;

FdoInt32 yyerror(FdoCommonParse *pParse, char* str)
{
	return (*yyerror_func)(str, yylineno);
}

ERRFUNC yyerror_set(ERRFUNC func)
{
	ERRFUNC old_func = yyerror_func;

	if (func != NULL)
		yyerror_func = func;

	return old_func;
}

static void  print_current_token()
{
//TODO: this has not been updated, but it is unused anyway
#ifdef FDO_YYDEBUG
	char  *token_name;
	
	if( yychar <= YYMAXTOKEN )
	{
		switch( yychar )
		{
			case IDENTIFIER:
				token_name = yylval.id;
				break;

			default:
				token_name = yyname[yychar];
				break;
		}
	}
	else
	{
		token_name = "illegal-name";
	}

	printf( "***  current token is %d (%s)  ***\n", yychar, token_name );
#endif
}
