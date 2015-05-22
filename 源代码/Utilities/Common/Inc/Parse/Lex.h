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
// Note: used SED substitution to fix getenv() prototype
// if you want tracing enabled you need to set environment
// variables of these names with a value of 1 to 9
#ifndef _LEX_H_
#define _LEX_H_

#ifdef _WIN32
#pragma once
#endif

class FdoCommonParse;

#include <FdoStd.h>
#include <Fdo/Expression/DataValue.h>
#include <Parse/Types.h>

// include both 1) exposes both fdo_*_yylval unions and 2) guarantees
// that tokens align, because will get compile redefinition errors if bad
#ifndef NOTOKEN_H
#ifdef _WIN32
#include <Parse/yyConstraintWin.h>
#else
#include <Parse/yyConstraint.h>
#endif
#endif

#ifdef _DEBUG
//#define DEBUG_TRACELEX	1
//#define DEBUG_TRACETREE	1
#endif

// The FdoLex class provides lexical analysis support for Constraint
// parsing, i.e. accepts data from the input stream, recognizes tokens 
// in it and outputs their type together with appropriate attributes.
class FdoLex
{
// was 256 in Object_Data2; the max text literal length in SQL is 4000 bytes
static const FdoInt32 maxCharLength = 4000;
static const FdoInt32 maxBinaryLength = 256*8;

  public:
    /// must contruct class with string to parse.
	explicit    FdoLex(FdoCommonParse *, FdoString*);  

    virtual		~FdoLex(void);

    /// Read next token and its attributes
    FdoInt32		GetToken(FdoCommonParse *);

    /// find keyword in table
	FdoInt32		FindKeyWord(FdoString*, FdoKeyWord*, FdoInt32);

    ///  Public data
    FdoInt32		m_token;			// Token type 
    FdoInt32		m_lastToken;		// Predecessor
	FdoDataValue*	m_data;				// token data
    FdoInt32		m_cprev;            // Start of the token
#if _DEBUG
	void			PrintToken(FdoInt32 token);
#endif

private:
    const wchar_t	nextchar		(void) const;  // Next character 
    const wchar_t	prevchar		(void) const;  // Previous character
    const wchar_t	if_getch		(FdoCommonParse *);        // Read next character
    const wchar_t	find_nonblank	(FdoCommonParse *pParse);        // Get next not blank symbol

    void			getword			(FdoCommonParse *, wchar_t*, FdoInt32);   // Get keyword or identifier from input

    wchar_t*		getdigits		(FdoCommonParse *pParse, wchar_t*);  	// Get digits 
    FdoUInt32		get_unsigned	(FdoCommonParse *pParse);			// Get unsigned integer number
    bool			getnumber		(FdoCommonParse *pParse, bool);			// Get number 
    bool			get_string		(FdoCommonParse *pParse, wchar_t*&, wchar_t);	// Get character string; caller is responsible for freeing buffer

    bool			get_date		(FdoCommonParse *pParse, FdoUInt16 *, FdoUInt16 *, FdoUInt16 *);  
    bool			get_second		(FdoCommonParse *pParse, double *);
    bool			get_timevalue	(FdoCommonParse *pParse, FdoUInt16 *, FdoUInt16 *, double *);
    bool			get_time		(FdoCommonParse *pParse, FdoUInt16 *, FdoUInt16 *, double *);
    bool			get_timestamp	(FdoCommonParse *pParse, FdoUInt16 *, FdoUInt16 *, FdoUInt16 *,	FdoUInt16 *, FdoUInt16 *, double *);
    bool			get_bitstring	(FdoCommonParse *pParse);
    bool			get_hexstring	(FdoCommonParse *pParse);

    /// Lexical analyzer state
    FdoString*		m_line;			// Points to parsed string
    FdoInt32        m_lineLength;   // cached length of m_line, to avoid scanning string at every if_getch() call
    FdoInt32		m_cc;			// Current position in the input string
    wchar_t			m_ch;			// Current character in the input string
    FdoInt32		m_prevToken;	// Previous token type for internal use
};

#endif // _LEX_H_


