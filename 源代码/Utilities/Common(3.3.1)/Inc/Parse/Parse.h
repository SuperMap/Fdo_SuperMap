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
#ifndef _PARSE_H_
#define _PARSE_H_

#ifdef _WIN32
#pragma once
#endif

#ifndef _WIN32
#include <stdint.h>
#endif

#include <FdoStd.h>
#include <Fdo/Schema/PropertyValueConstraint.h>
#include <Fdo/Expression/ComputedIdentifier.h>
#include <Fdo/IDisposableCollection.h>

#include <Parse/Types.h>
#include <Parse/Lex.h>

#ifdef _DEBUG
#include <stdio.h>
#endif

#ifndef FdoToken_NULL
#ifdef _WIN32
#include <Parse/yyConstraintWin.h>
#else
#include <Parse/yyConstraint.h>
#endif
#endif

#ifdef _WIN32
// The following is from yyConstraint.cpp

#ifdef FDO_CONSTRAINT_YYSTACKSIZE
#undef FDO_CONSTRAINT_YYMAXDEPTH
#define FDO_CONSTRAINT_YYMAXDEPTH FDO_CONSTRAINT_YYSTACKSIZE
#else
#ifdef FDO_CONSTRAINT_YYMAXDEPTH
#define FDO_CONSTRAINT_YYSTACKSIZE FDO_CONSTRAINT_YYMAXDEPTH
#else
#define FDO_CONSTRAINT_YYSTACKSIZE 500
#define FDO_CONSTRAINT_YYMAXDEPTH 500
#endif
#endif

#endif

class FdoCommonParse
{
public:
	FdoCommonParse();
	~FdoCommonParse();

    /// parse constraint
    /// returning root node of parse tree, NULL if invalid
	FdoPropertyValueConstraint* ParseConstraint(FdoString* pwzConstraint);
	FdoInt32			GetLexeme(FdoCommonParse *pParse, void* yylval);

    /// parse tree operations
	FdoIDisposable* AddNode(FdoIDisposable* pNode);
	FdoIDisposable* AddNodeToDelete(FdoIDisposable* pNode);
    void  AddCompIdentifier(FdoComputedIdentifier* pNode);
    FdoComputedIdentifier* FindComputedIdentifier( FdoString* name );
	FdoIDisposable*	Add(FdoString* pDebug, FdoIDisposable *pThis);
	FdoIDisposable* Copy(FdoString* pDebug, FdoIDisposable *pThis);
	void			Trace(FdoString* pDebug);
	void			Abort(void);
	void			Clean(void);
	void			SetRoot(FdoIDisposable* pNode);

    /// data members
	FdoIDisposableCollection*	m_nodes;
	FdoIDisposableCollection*	m_nodesToDelete;
    FdoIdentifierCollection*    m_ComputedIdentifiers;
	FdoIDisposable*				m_root;
	FdoLex*						m_lex;

    int                         fdo_constraint_yydebug;
    int                         fdo_constraint_yynerrs;
    int                         fdo_constraint_yyerrflag;
    int                         fdo_constraint_yychar;
    short                       *fdo_constraint_yyssp;

    FDO_CONSTRAINT_YYSTYPE      *fdo_constraint_yyvsp;
    FDO_CONSTRAINT_YYSTYPE      fdo_constraint_yyval;
    FDO_CONSTRAINT_YYSTYPE      fdo_constraint_yylval;
#if _WIN32
    short                       fdo_constraint_yyss[FDO_CONSTRAINT_YYSTACKSIZE];
    FDO_CONSTRAINT_YYSTYPE      fdo_constraint_yyvs[FDO_CONSTRAINT_YYSTACKSIZE];
#else
    short                       *fdo_constraint_yyss;
	short						*fdo_constraint_yysslim;
    FDO_CONSTRAINT_YYSTYPE      *fdo_constraint_yyvs;
	int							fdo_constraint_yystacksize;
#endif
    FdoInt32		            fdo_constraint_yylineno;
};

// constraint YACC interface
extern FdoInt32		fdo_constraint_yyerror(FdoCommonParse *, char* str);
extern FdoInt32		fdo_constraint_yyparse(FdoCommonParse*);
extern FdoInt32		fdo_constraint_yylex(FdoCommonParse*);

// tree management
#if _DEBUG
#define Node_Add(a,b)	pParse->Add(a, b)
#define Node_Copy(a,b)	pParse->Copy(a, b)
#define Node_Trace(a)	pParse->Trace(a)
#else
#define Node_Add(a,b)	pParse->Add(NULL, b)
#define Node_Copy(a,b)	pParse->Copy(NULL, b)
#define Node_Trace(a)	
#endif
#endif


