// 
//  
//  Copyright (C) 2004-2006  Autodesk, Inc.
//  
//  This library is free software; you can redistribute it and/or
//  modify it under the terms of version 2.1 of the GNU Lesser
//  General Public License as published by the Free Software Foundation.
//  
//  This library is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//  Lesser General Public License for more details.
//  
//  You should have received a copy of the GNU Lesser General Public
//  License along with this library; if not, write to the Free Software
//  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
//  
#include <stdafx.h>
#include <FdoGeometry.h>
#include <Fdo/IDisposableCollection.h>
#include <Fdo/Commands/IdentifierCollection.h>
#include <Fdo/Expression/StringValue.h>
#include <Fdo/Expression/Int32Value.h>
#include <Fdo/Expression/DoubleValue.h>
#include <Fdo/Expression/DateTimeValue.h>
#include <Fdo/Expression/BooleanValue.h>
#include <Fdo/Expression/ExpressionException.h>
#include <Parse/Parse.h>

FdoCommonParse::FdoCommonParse()
{
	// initialize tree with empty list
	m_nodes = FdoIDisposableCollection::Create();
	m_nodesToDelete = FdoIDisposableCollection::Create();
    m_ComputedIdentifiers = FdoIdentifierCollection::Create();

	// default to invalid root node
	m_root = NULL;
	// ... no lexical analyzer
	m_lex = NULL;


    fdo_constraint_yydebug = 0;
    fdo_constraint_yynerrs = 0;
    fdo_constraint_yyerrflag = 0;
    fdo_constraint_yychar = -1;
    fdo_constraint_yyssp = NULL;
    fdo_constraint_yyvsp = NULL;
#ifndef _WIN32
	fdo_constraint_yyss = NULL;
	fdo_constraint_yysslim = NULL;
	fdo_constraint_yyvs = NULL;
	fdo_constraint_yystacksize = 0;
#endif
    fdo_constraint_yylineno = 0;
}

FdoCommonParse::~FdoCommonParse()
{
	FDO_SAFE_RELEASE(m_nodes);
	FDO_SAFE_RELEASE(m_nodesToDelete);
    FDO_SAFE_RELEASE(m_ComputedIdentifiers);
	if (m_lex != NULL)
		delete m_lex;
#ifndef _WIN32
    free(fdo_constraint_yyss);
    free(fdo_constraint_yyvs);
#endif
}

FdoIDisposable* FdoCommonParse::AddNode(FdoIDisposable* pNode)
{
	if (pNode != NULL)
		m_nodes->Add(pNode);
	return pNode;
}

FdoIDisposable* FdoCommonParse::AddNodeToDelete(FdoIDisposable* pNode)
{
	if (pNode != NULL)
		m_nodesToDelete->Add(pNode);
	return pNode;
}

void FdoCommonParse::AddCompIdentifier(FdoComputedIdentifier* pNode)
{
    if (pNode != NULL)
    {
        if( m_ComputedIdentifiers != NULL )
            m_ComputedIdentifiers->Add( pNode );
    }
}

FdoComputedIdentifier* FdoCommonParse::FindComputedIdentifier( FdoString* name )
{
    for(int i=0; i<m_ComputedIdentifiers->GetCount(); i++ )
    {
        FdoComputedIdentifier *id = (FdoComputedIdentifier*)m_ComputedIdentifiers->GetItem(i);
        if( wcscmp( id->GetName(), name ) == 0 )
            return id;
        else
            id->Release();
    }
    return NULL;
}

//	provide debug trace of action type
FdoIDisposable* FdoCommonParse::Add(FdoString* pDebug, FdoIDisposable *pThis)
{
#ifdef DEBUG_TRACETREE
	printf("Tree(%S)\n", pDebug);
#endif
	return AddNode(pThis);
}
FdoIDisposable* FdoCommonParse::Copy(FdoString* pDebug, FdoIDisposable *pThis)
{
#ifdef DEBUG_TRACETREE
	printf("Tree(%S)\n", pDebug);
#endif
	return pThis;
}
void FdoCommonParse::Trace(FdoString* pDebug)
{
#ifdef DEBUG_TRACETREE
	printf("Tree(%S)\n", pDebug);
#endif
}

// release all the allocated nodes and then Clean
void FdoCommonParse::Abort(void)
{
	// go through collection and release nodes
/* TODO: The following can release objects too many times if their parse tree
//    reference has been released.
// However, commenting this out leads to some memory leaks that need to be addressed.

	for (FdoInt32 i=0; i<m_nodes->GetCount(); i++)
	{
		FdoIDisposable* pItem = m_nodes->GetItem(i);
		pItem->Release();
		pItem->Release();
	}
*/
	m_nodes->Clear();
}

// clean up deleted always list
void FdoCommonParse::Clean(void)
{
	m_nodes->Clear();
	m_ComputedIdentifiers->Clear();
    m_nodesToDelete->Clear();
}

void FdoCommonParse::SetRoot(FdoIDisposable* pNode)
{
	m_root = pNode;
}

// same lexical analyzer for constraints
FdoInt32 FdoCommonParse::GetLexeme(FdoCommonParse *pParse, void* pyylval)
{
	// Note, this is based on the supposition that the union
	// in yyConstraint.y
	FDO_CONSTRAINT_YYSTYPE* yylval = (FDO_CONSTRAINT_YYSTYPE*) pyylval;

	FdoInt32 iToken = m_lex->GetToken(pParse);
#ifdef DEBUG_TRACELEX
	m_lex->PrintToken(iToken);
#endif
	switch (iToken)
	{
	case FdoToken_Literal:
		if (!m_lex->m_data)
		{
			return FdoToken_NULL;
		}
		else
		{
			// check if null
			if (m_lex->m_data->IsNull())
				return FdoToken_NULL;
			else
			{
				// print type and value
				switch (m_lex->m_data->GetDataType())
				{
				case FdoDataType_String:
					yylval->m_string = ((FdoStringValue*)(m_lex->m_data))->GetString();
					return FdoToken_STRING;
				case FdoDataType_Int16:
				case FdoDataType_Int32:
					yylval->m_integer = ((FdoInt32Value*)(m_lex->m_data))->GetInt32();
					return FdoToken_INTEGER;
				case FdoDataType_Int64:
					yylval->m_int64 = ((FdoInt64Value*)(m_lex->m_data))->GetInt64();
					return FdoToken_INT64;
				case FdoDataType_Single:
				case FdoDataType_Double:
					yylval->m_double = ((FdoDoubleValue*)(m_lex->m_data))->GetDouble();
					return FdoToken_DOUBLE;
				// date, time, timestamp
				case FdoDataType_DateTime:
				    yylval->m_datetime.Set(((FdoDateTimeValue*)(m_lex->m_data))->GetDateTime());
					return FdoToken_DATETIME;
				case FdoDataType_Boolean:
					if (((FdoBooleanValue*)(m_lex->m_data))->GetBoolean())
					{
						yylval->m_integer = 1;
						return FdoToken_TRUE;
					}
					else
					{
						yylval->m_integer = 0;
						return FdoToken_FALSE;
					}
					break;
				case FdoDataType_Byte:
				case FdoDataType_Decimal:
				case FdoDataType_BLOB:
				case FdoDataType_CLOB:
				default:
					return FdoToken_Error;
				}
			}
		}
		break;

	case FdoToken_IDENTIFIER:
		yylval->m_string = ((FdoStringValue*)(m_lex->m_data))->GetString();
		return FdoToken_IDENTIFIER;
	case FdoToken_PARAMETER:
		yylval->m_string = ((FdoStringValue*)(m_lex->m_data))->GetString();
		return FdoToken_PARAMETER;

	case FdoToken_LeftParenthesis:
		return '(';
	case FdoToken_RightParenthesis:
		return ')';
	case FdoToken_LeftSquareBrackets:
		return '[';
	case FdoToken_RightSquareBrackets:
		return ']';
	case FdoToken_Comma:
		return ',';
//	case FdoToken_Dot:
//		return '.';
//	case FdoToken_Colon:
//		return ':';

#ifdef _DEBUG
	case FdoToken_End:
	// symbols
//	case FdoToken_LeftParenthesis:
//	case FdoToken_RightParenthesis:
//	case FdoToken_Comma:
	case FdoToken_Dot:
	case FdoToken_Colon:
	// expression operators
	case FdoToken_Add:
	case FdoToken_Subtract:
	case FdoToken_Multiply:
	case FdoToken_Divide:
	case FdoToken_Negate:
	// comparison operators
	case FdoToken_EQ:
	case FdoToken_NE:
	case FdoToken_LT:
	case FdoToken_LE:
	case FdoToken_GT:
	case FdoToken_GE:
	// keywords
	case FdoToken_AND:
	case FdoToken_AS:
	case FdoToken_BEYOND:
	case FdoToken_CONTAINS:
	case FdoToken_COVEREDBY:
	case FdoToken_CROSSES:
	case FdoToken_DATE:
	case FdoToken_DISJOINT:
	case FdoToken_ENVELOPEINTERSECTS:
	case FdoToken_EQUALS:
	case FdoToken_FALSE:
	case FdoToken_GEOMFROMTEXT:
	case FdoToken_IN:
	case FdoToken_INSIDE:
	case FdoToken_INTERSECTS:
	case FdoToken_LIKE:
	case FdoToken_NOT:
	case FdoToken_NULL:
	case FdoToken_OR:
	case FdoToken_OVERLAPS:
	case FdoToken_RELATE:
	case FdoToken_TIME:
	case FdoToken_TIMESTAMP:
	case FdoToken_TOUCHES:
	case FdoToken_TRUE:
	case FdoToken_WITHIN:
	case FdoToken_WITHINDISTANCE:
	case FdoToken_BETWEEN:
		return iToken;
	default:
		printf("!ERROR! Unknown token=%d\n", iToken);
		return FdoToken_Error;
#else
	default:
		return iToken;
#endif // _DEBUG
	}
// unreachable	return FdoToken_Error;
}

FdoPropertyValueConstraint* FdoCommonParse::ParseConstraint(FdoString* pwzConstraint)
{
	m_lex = new FdoLex(this, pwzConstraint);
	if (m_lex == NULL)
		return NULL;
	try
	{
		fdo_constraint_yyparse(this);
        if (m_root == NULL)
            throw FdoExpressionException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_4_STRINGINCORRECTLYFORMATTED)));
	}
	catch (FdoException* exception)
	{
		Abort();
		Clean();

        FdoExpressionException* exceptionOuter = FdoExpressionException::Create(NlsMsgGetFdo(FDO_NLSID(EXPRESSION_17_STRINGNOTEXPRESSION)), exception);
        exception->Release();
		throw exceptionOuter;
	}
	Clean();
	return (FdoPropertyValueConstraint*) m_root;
}

// use same lexical analyzer for constraints
FdoInt32 fdo_constraint_yylex(FdoCommonParse* parse)
{
	return parse->GetLexeme(parse, (FDO_CONSTRAINT_YYSTYPE*)&parse->fdo_constraint_yylval);
}
