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
#include <math.h>	// for pow()
#include <limits.h>	// LONG_MAX and LONG_MIN
#include <time.h>
#include <wctype.h>
#include <StringUtility.h>
#include <Fdo/Expression/StringValue.h>
#include <Fdo/Expression/Int32Value.h>
#include <Fdo/Expression/DoubleValue.h>
#include <Fdo/Expression/BooleanValue.h>
#include <Fdo/Expression/DateTimeValue.h>
#include <Parse/Parse.h>
#include <Parse/Lex.h>

#define CHR_NULL	'\0'

// keywords must be in alphabetic order since they are binary searched
// the tokens themselves don't have to be in order
static FdoKeyWord g_aKeyWords[] =
{
  L"AND",		     FdoToken_AND,			// BinaryLogicalOperations
  L"AS",		     FdoToken_AS,			// AS used for alias
  L"BETWEEN",		 FdoToken_BETWEEN,
  L"BEYOND",         FdoToken_BEYOND,		// DistanceOperations
  L"CONTAINS",       FdoToken_CONTAINS,		// SpatialOperations
  L"COVEREDBY",      FdoToken_COVEREDBY,	// SpatialOperations
  L"CROSSES",        FdoToken_CROSSES,		// SpatialOperations
  L"DATE",           FdoToken_DATE,			// DateTime
  L"DISJOINT",       FdoToken_DISJOINT,		// SpatialOperations
  L"ENVELOPEINTERSECTS",     FdoToken_ENVELOPEINTERSECTS,	// SpatialOperations
  L"EQUALS",         FdoToken_EQUALS,		// SpatialOperations
  L"FALSE",          FdoToken_FALSE,		// Boolean
  L"GEOMFROMTEXT",   FdoToken_GEOMFROMTEXT,	// GeometryValue
  L"IN",             FdoToken_IN,			// ConditionType
  L"INSIDE",	     FdoToken_INSIDE,		// SpatialOperations
  L"INTERSECTS",     FdoToken_INTERSECTS,	// SpatialOperations
  L"LIKE",           FdoToken_LIKE,			// ConditionType
  L"NOT",            FdoToken_NOT,			// UnaryLogicalOperations
  L"NULL",           FdoToken_NULL,			// ConditionType
  L"OR",             FdoToken_OR,			// BinaryLogicalOperations
  L"OVERLAPS",       FdoToken_OVERLAPS,		// SpatialOperations
  L"RELATE",         FdoToken_RELATE,	 	// future use
  L"TIME",           FdoToken_TIME,			// DateTime
  L"TIMESTAMP",      FdoToken_TIMESTAMP,	// DateTime
  L"TOUCHES",        FdoToken_TOUCHES,		// SpatialOperations
  L"TRUE",           FdoToken_TRUE,			// Boolean
  L"WITHIN",         FdoToken_WITHIN,		// SpatialOperations
  L"WITHINDISTANCE", FdoToken_WITHINDISTANCE, // DistanceOperations

  (FdoString*)0,  FdoToken_Undefined
};
#define KEYWORDCOUNT   (sizeof(g_aKeyWords)/sizeof(g_aKeyWords[0])-1)

#ifdef _DEBUG
void FdoLex::PrintToken(FdoInt32 token)
{
	printf(" ");
	switch (token)
	{
	case FdoToken_Undefined:
		printf("Undefined");
		break;
	case FdoToken_End:
		printf("End");
		break;
	case FdoToken_Start:
		printf("Start");
		break;
	case FdoToken_Error:
		printf("!!!!Error!!!! invalid token");
		break;
	case FdoToken_Literal:
		printf("Literal=");
		if (!m_data)
		{
			printf("NULL");
		}
		else
		{
			// check if null
			if (m_data->IsNull())
				printf("NULL");
			else
			{
				// print type and value
				switch (m_data->GetDataType())
				{
				case FdoDataType_String:
					printf("%S (string)", ((FdoStringValue*)m_data)->GetString());
					break;
				case FdoDataType_Int16:
				case FdoDataType_Int32:
				case FdoDataType_Int64:
					printf("%d (FdoInt32)", ((FdoInt32Value*)m_data)->GetInt32());
					break;
				case FdoDataType_Single:
				case FdoDataType_Double:
					printf("%g (double)", ((FdoDoubleValue*)m_data)->GetDouble());
					break;
				// date, time, timestamp
				case FdoDataType_DateTime:
                    {
                        FdoDateTime dt = ((FdoDateTimeValue*)m_data)->GetDateTime();
					    printf("%d-%d-%d-%d-%d-%f (datetime)", (FdoInt32)dt.year, (FdoInt32)dt.month, (FdoInt32)dt.day, 
                            (FdoInt32)dt.hour, (FdoInt32)dt.minute, dt.seconds);
                    }
					break;
				case FdoDataType_Boolean:
					if (((FdoBooleanValue*)m_data)->GetBoolean())
						printf("true (boolean)");
					else
						printf("false (boolean)");
					break;
				case FdoDataType_Byte:
				case FdoDataType_Decimal:
				case FdoDataType_BLOB:
				case FdoDataType_CLOB:
				default:
					printf("(unknown type)");
					break;
				}
			}
		}
		break;

	case FdoToken_IDENTIFIER:
		printf("Identifier=\"%S\"", ((FdoStringValue*)m_data)->GetString());
		break;
	case FdoToken_PARAMETER:
		printf("Parameter=\"%S\"", ((FdoStringValue*)m_data)->GetString());
		break;

	case FdoToken_Add:
		printf("Add");
		break;
	case FdoToken_Subtract:
		printf("Subtract");
		break;
	case FdoToken_Multiply:
		printf("Star");
		break;
	case FdoToken_Divide:
		printf("Div");
		break;
	case FdoToken_Negate:
		printf("Negate");
		break;
	case FdoToken_EQ:
		printf("EQ");
		break;
	case FdoToken_NE:
		printf("NE");
		break;
	case FdoToken_LT:
		printf("LT");
		break;
	case FdoToken_LE:
		printf("LE");
		break;
	case FdoToken_GT:
		printf("GT");
		break;
	case FdoToken_GE:
		printf("GE");
		break;
	case FdoToken_LeftParenthesis:
		printf("LeftParenthesis");
		break;
	case FdoToken_RightParenthesis:
		printf("RightParenthesis");
		break;
	case FdoToken_Comma:
		printf("Comma");
		break;
	case FdoToken_Dot:
		printf("Dot");
		break;
	case FdoToken_Colon:
		printf("Colon");
		break;

	default:
		{
			// Keywords
			FdoInt32 i;
			for (i=0; i<KEYWORDCOUNT; i++)
			{
				if (g_aKeyWords[i].token == token)
				{
					printf("%S (keyword)\n", g_aKeyWords[i].word);
					return;
				}
			}
		}
		printf("UNDEFINED TOKEN IN TEST CODE--check FdoToken enumerations\n");
		break;
	}
	printf("\n");
}
#endif

//////////////////////////////////////////////////////////////////////////////
static FdoInt32 CompareInsensitive(FdoString* pToken, FdoString* pucString)
{
	if (!pucString && !pToken)
		return 0;

	if (!pucString	&& pToken)
		return 1;

	if (pucString && !pToken)
		return -1;

	return FdoStringUtility::StringCompareNoCase(pToken, pucString);
}

//  Search for token in the keyword array
static FdoInt32 findtoken 
(
FdoString*			token,              // string token to find
const FdoKeyWord	words[],			// array of keyword/token pairs
FdoInt32			number_of_words     // number of patterns
)
{
    register FdoInt32 ii;             // Indexes are also needed. Sometimes ...  
    register FdoInt32 jj;
    register FdoInt32 kk;

    // Split tokens array in two parts and select appropriate part 
    ii  = 0 ;
    jj  = number_of_words-1 ;

    kk = (ii + jj) / 2;
    while (ii <= jj) 
	{
        if (CompareInsensitive(token, words[kk].word) <= 0) 
            jj = kk-1 ;
        
        if (CompareInsensitive(token, words[kk].word) >= 0) 
            ii = kk+1 ;
        
        kk = (ii + jj) / 2;
    }

    if (CompareInsensitive(token, words[kk].word) == 0) 
        return kk;
    else 
        return -1;  // Token not found
}

FdoInt32 FdoLex::FindKeyWord(FdoString* word, FdoKeyWord* aKeyWords, FdoInt32 cCount)
{
    FdoInt32 ii;

    if ((ii = findtoken(word, aKeyWords, cCount)) >= 0) 
         return aKeyWords[ii].token;
    
    return FdoToken_Undefined;
}

//  return -1 if sign is true and 1 if it is false
inline FdoInt32 ifac(bool sign) 
{
   return sign ? (-1) : 1;
}

inline double make_double(FdoUInt32 n, FdoUInt32 f, FdoInt32 m)
{
	return ((double)n+(double)f*pow(10.0, -(double)m));
}

FdoLex::FdoLex(FdoCommonParse *pParse, FdoString* str)
{
	m_line = str;
    m_lineLength = (FdoInt32)FdoStringUtility::StringLength(m_line);  // cache length for performance
	m_prevToken = FdoToken_Start;
	m_lastToken = FdoToken_Start;
	m_token = FdoToken_Start;
	m_cprev = 0;
	m_cc = 0;
	m_data = NULL; //FdoDataValue::Create();

	m_ch = if_getch(pParse);   // Get first character from input string
    pParse->fdo_constraint_yylineno = 1;
}  

FdoLex::~FdoLex() 
{
	FDO_SAFE_RELEASE(m_data);
}

FdoInt32 FdoLex::GetToken(FdoCommonParse *pParse) 
{
    wchar_t		savech;               // save character 
    wchar_t     wordOnStack[maxCharLength];  // Word from input  (stored on stack, limited size)
    wchar_t		*wordOnHeap = NULL;          // Word from input  (stored on heap, unlimited size)
	FdoInt32	column = pParse->fdo_constraint_yylineno;

    try {
start:;
		m_cprev = m_cc;              // Save start position of the previous symbol
        m_lastToken = m_token;       // Save pedecessor
    
        m_ch = find_nonblank(pParse);   // Get next not blank character 
    
        if (m_ch == '\0') {        // Stream is over 
            m_token = FdoToken_End;
            m_prevToken = m_token;
            return m_token;
        }

#ifdef _WIN32
		if (m_ch == '\'' || m_ch == 8216) 
#else
		if (m_ch == '\'' || m_ch == 145) 
#endif
		{        
			// Character literal constant is single quoted
#ifdef _WIN32
			if (!get_string(pParse, wordOnHeap, m_ch == '\'' ? '\'' : 8217)) 
#else
			if (!get_string(pParse, wordOnHeap, m_ch == '\'' ? '\'' : 146)) 
#endif
			{
               // Error !!! Wrong string format
                delete[] wordOnHeap;
                throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_4_STRINGINCORRECTLYFORMATTED)));
            }
			FDO_SAFE_RELEASE(m_data);
			m_data = FdoStringValue::Create(wordOnHeap);
            m_token = m_prevToken = FdoToken_Literal;
            delete[] wordOnHeap;  // TODO: we could optimize this by somehow giving FdoStringValue the ownership of 'wordOnHeap' instead of copying it unnecessarily.
            return m_token;
        }
   
#ifdef _WIN32 
        if (m_ch == '\"' || m_ch == 8220) 
#else
        if (m_ch == '\"' || m_ch == 147) 
#endif
		{
			// double quoted identifier 
#ifdef _WIN32
			if (!get_string(pParse, wordOnHeap, m_ch == '\"' ? '\"' : 8221)) 
#else
			if (!get_string(pParse, wordOnHeap, m_ch == '\"' ? '\"' : 148)) 
#endif
			{
               // Error !!! Wrong string format
               delete[] wordOnHeap;
               throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_4_STRINGINCORRECTLYFORMATTED)));
            }
            if (FdoStringUtility::StringLength(wordOnHeap) == 0) 
			{
               delete[] wordOnHeap;
               throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_9_WRONGTOKEN)));
            }
			// SetDelimited() need to keep track if it's quoted then it
			// is case sensitive and can't be a keyword
			FDO_SAFE_RELEASE(m_data);
			m_data = FdoStringValue::Create(wordOnHeap);
            m_token = m_prevToken = FdoToken_IDENTIFIER;
            delete[] wordOnHeap;  // TODO: we could optimize this by somehow giving FdoStringValue the ownership of 'wordOnHeap' instead of copying it unnecessarily.
            return m_token;
        }

        if (m_ch == 'B' && nextchar()  == '\'') 
		{
			// Bit string literal
            m_ch = if_getch(pParse);    // Get '
            if (!get_bitstring(pParse)) 
			{
               // Error !!! Wrong bit string format
               throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_4_STRINGINCORRECTLYFORMATTED)));
            }
            m_token = m_prevToken = FdoToken_Literal;
            return m_token;
        }
    
        if (m_ch == 'X' && nextchar() == '\'') 
		{
			// Hex string literal
            m_ch = if_getch(pParse);    // Get '
            if (get_hexstring(pParse) == false) 
			{
               // Error !!! Wrong hex string format
               throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_4_STRINGINCORRECTLYFORMATTED)));
            }
            m_token = m_prevToken = FdoToken_Literal;
            return m_token;
        }
    
        // Is it keyword or identifier?
        if (iswalpha(m_ch)) 
		{
		    // Get keyword or identifier
            getword(pParse, wordOnStack, sizeof(wordOnStack)/sizeof(wchar_t));

            // Is it a set function?
            FdoInt32   tktmp;             // Token temporary
            if ((tktmp = FindKeyWord(wordOnStack, g_aKeyWords, KEYWORDCOUNT)) != FdoToken_Undefined)
			{
				m_token = tktmp;
                //
                // Proceed some special cases:
                // date literal, time literal, timestamp literal and
                // interval literal 
                //
                if (m_token == FdoToken_DATE) 
				{
					FdoUInt16 y, m, d;
    
                    m_ch = find_nonblank(pParse);
					// if ' follows DATE then it is date literal
                    if (m_ch == '\'') 
					{
						column = pParse->fdo_constraint_yylineno;
						m_ch = if_getch(pParse);
						if (get_date(pParse, &y, &m, &d) == false) 
						{
							// Error !!! Wrong date value
							throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
						}
						if (m_ch == '\'') 
						{
							FdoDateTime	dt((FdoInt16)y, (FdoInt8)m, (FdoInt8)d);

							FDO_SAFE_RELEASE(m_data);
							m_data = FdoDateTimeValue::Create(dt);
							m_token = FdoToken_Literal; //DateTime;
							m_ch = if_getch(pParse);
						} 
						else 
						{
							// Error !!! Date string is not terminated
							throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_6_MISSINGQUOTE_d), column));
						}
                    }
    
                } 
				else if (m_token == FdoToken_TIME)
				{
					FdoUInt16	h, m; 
					double	s;
    
					m_ch = find_nonblank(pParse);
					// if ' follows TIME than that is time literal
					if (m_ch == '\'') 
					{    
						column = pParse->fdo_constraint_yylineno;
						// Get next character after '
						m_ch = if_getch(pParse);            
						if (!get_time(pParse, &h, &m, &s)) 
						{
							// Error !!! Wrong time value
							throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
						}
    
						if (m_ch == '\'') 
						{
							FdoDateTime	dt((FdoInt8)h, (FdoInt8)m, (float)s);

							FDO_SAFE_RELEASE(m_data);
							m_data = FdoDateTimeValue::Create(dt);
							m_token = FdoToken_Literal; //DateTime;
							m_ch = if_getch(pParse);
						} 
						else 
						{
							// Error !!! Time string is not terminated
							throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_6_MISSINGQUOTE_d), column));
						}
					}
    
                } 
				else if (m_token == FdoToken_TIMESTAMP) 
				{ 
					// if ' follows TIMESTAMP then that is datetime literal
    				FdoUInt16 y, m, d, h, mt;
					double s;
    
					m_ch = find_nonblank(pParse);
					if (m_ch == '\'') 
					{
						column = pParse->fdo_constraint_yylineno;
						m_ch = if_getch(pParse);      
						if (!get_timestamp(pParse, &y, &m, &d, &h, &mt, &s)) 
						{
							// Error !!! Wrong timestamp value
							throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
						}
    
						if (m_ch == '\'') 
						{
							FdoDateTime	dt((FdoInt16)y, (FdoInt8)m, (FdoInt8)d, (FdoInt8)h, (FdoInt8)mt, (float)s);

							FDO_SAFE_RELEASE(m_data);
							m_data = FdoDateTimeValue::Create(dt);
							m_token = FdoToken_Literal; //DateTime;
							m_ch = if_getch(pParse);
						} 
						else 
						{
							// Error !!! Timestamp string is not terminated
							throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_6_MISSINGQUOTE_d), column));
						}
					}
 				} 
            } 
			else 
			{
				// note, this is different than the SQL analyzer which
				// keeps each name separated by Dots as separate tokens
				// we make a.b.c into one identifier instead of three
				while (m_ch == '.')
				{
  					FdoInt32 iLen = (FdoInt32)FdoStringUtility::StringLength(wordOnStack);
  					wordOnStack[iLen] = m_ch;
  					wordOnStack[iLen+1] = CHR_NULL;
					m_ch = if_getch(pParse);
					if (iswalpha(m_ch)) 
					{
						// Get identifier (can't be keyword)
  						wchar_t	nextword[maxCharLength];
  						getword(pParse, nextword, sizeof(nextword)/sizeof(wchar_t));
  						FdoStringUtility::StringConcatenate(wordOnStack, nextword);
					}
				}

				// This is non-quoted identifier!!!
				FDO_SAFE_RELEASE(m_data);
				m_data = FdoStringValue::Create(wordOnStack);
                m_token = FdoToken_IDENTIFIER;
            }
        } 
		// Is it a numeric constant?
		else if (iswdigit(m_ch)) 
		{
			// m_token is real or integer number
            getnumber(pParse, false);
        } 
		else if (m_ch == '|' && nextchar() == '|') 
		{    
			// Concatenate is treated as binary addition
            m_token = FdoToken_Add;
            if_getch(pParse);       // Skip next |
            m_ch = if_getch(pParse);  // Read next character
    
        } 
		else if (m_ch == '<' || m_ch == '>') 
		{
            // Comparision operators
           wchar_t	cch ;      // Temporary char
    
            cch = m_ch ;
            m_ch = if_getch(pParse);
            if (m_ch == '=') 
			{
				if (cch == '<') {
                    m_token = FdoToken_LE ;
                } else {
                    m_token = FdoToken_GE ;
                }
                m_ch = if_getch(pParse);
    
            } 
			else if (m_ch == '>') 
			{
                if (cch == '<') {
                    m_token = FdoToken_NE ;
                    m_ch = if_getch(pParse);
                }
            } 
			else 
			{
                if (cch == '<') {
                    m_token = FdoToken_LT ;
                } else {
                    m_token = FdoToken_GT ;
                }
            }
    
        }
		// synonym for <> (NotEqualTo)
		else if (m_ch == '!' && nextchar() == '=') 
		{
            m_token = FdoToken_NE;
            if_getch(pParse); // Skip =
            m_ch = if_getch(pParse);  // Read next character
    
        } 
		else if (m_ch == '=') {
            /* Equal operator */
            m_token = FdoToken_EQ;
            m_ch = if_getch(pParse);
    
        } else if (m_ch == '*') {           /* Star */
            m_token = FdoToken_Multiply;
            m_ch = if_getch(pParse);
    
        } else if (m_ch == '/') {           /* Slash */
            m_token = FdoToken_Divide;
            m_ch = if_getch(pParse);
    
        } else if (m_ch == ',') {           /* Comma */
            m_token = FdoToken_Comma;
            m_ch = if_getch(pParse);
    
        } 
		else if (m_ch == '.') 
		{           
			// Dot. Look ahead one symbol. If it is digit, than get 
			// number from input stream, otherwise assume Dot
            if (iswdigit(nextchar())) 
			{
                getnumber(pParse, false);
            } 
			else 
			{
                m_token = FdoToken_Dot;
                m_ch = if_getch(pParse);
            }
        } 
		else if (m_ch == ':') 
		{
			// TODO: allow quoted string support
			// Colon. Start of parameter reference 
            m_ch = if_getch(pParse);
            if (iswalpha(m_ch)) 
			{
				// Get parameter name
	            getword(pParse, wordOnStack, sizeof(wordOnStack)/sizeof(wchar_t));
				FDO_SAFE_RELEASE(m_data);
				m_data = FdoStringValue::Create(wordOnStack);
				m_token = FdoToken_PARAMETER;
            } 
			else 
			{
				m_token = FdoToken_Colon;
            }
        } 

		else if (m_ch == '(') {           // Left parenthesis
            m_token = FdoToken_LeftParenthesis;
            m_ch = if_getch(pParse);
    
        } else if (m_ch == ')') {           // Right parenthesis
            m_token = FdoToken_RightParenthesis;
            m_ch = if_getch(pParse);
    
        } else if (m_ch == '[') {           // Left Square Brackets
            m_token = FdoToken_LeftSquareBrackets;
            m_ch = if_getch(pParse);
    
        } else if (m_ch == ']') {           // Right Square Brackets
            m_token = FdoToken_RightSquareBrackets;
            m_ch = if_getch(pParse);
    
        } else if ( (m_ch == '-' || m_ch == '+') &&
                    (m_prevToken == FdoToken_LeftParenthesis ||
					 m_prevToken == FdoToken_Start ||
                     m_prevToken == FdoToken_Add ||
					 m_prevToken == FdoToken_Subtract ||
                     m_prevToken == FdoToken_Multiply ||
					 m_prevToken == FdoToken_Divide ||
                     m_prevToken == FdoToken_Start ||
                     m_prevToken == FdoToken_Comma ||
                     m_prevToken == FdoToken_EQ ||
                     m_prevToken == FdoToken_NE ||
                     m_prevToken == FdoToken_GT ||
                     m_prevToken == FdoToken_GE ||
                     m_prevToken == FdoToken_LT ||
					 m_prevToken == FdoToken_LE
					)
				  ) 
		{
            // Minus or plus. Define whether it is an unary or binary operator
            savech = m_ch;
    
            m_ch = if_getch(pParse);
            m_ch = find_nonblank(pParse);
    
            if (iswdigit(m_ch) || m_ch == '.') 
			{
                /* next symbol is number: unary */
				// unary plus is ignored entirely
				getnumber(pParse, savech == '-' ? true : false);
            }
			else if (savech == '-') 
			{
                m_token = FdoToken_Negate;
            }
			else
			{
                goto start;
            }
    
        } else if (m_ch == '+') {           /* Add */
            m_token = FdoToken_Add;
            m_ch = if_getch(pParse);
    
        } else if (m_ch == '-') {           /* Subtract */
            m_token = FdoToken_Subtract;
            m_ch = if_getch(pParse);
        } 
		else 
		{                          /* Nothing */
            m_token = FdoToken_Error;
            m_ch = if_getch(pParse);
        }
        m_prevToken = m_token;
    } 
	catch (FdoException* exception)
	{
        m_token = FdoToken_Error;
        throw exception;
    }
    return m_token;
}

//  Return next character from the input stream.
//  Next character becomes current
const wchar_t FdoLex::if_getch(FdoCommonParse *pParse) 
{
	wchar_t	c;

	if (m_cc >= m_lineLength) 
	{
		c = '\0';
	}
	else 
	{
		c = m_line[m_cc++];
		pParse->fdo_constraint_yylineno++;
		if (c == '\n' || c == '\r') 
			c = ' ';
	}
	return c;
}

//  Get Word from input stream
void FdoLex::getword(FdoCommonParse *pParse, wchar_t* pstr, FdoInt32 maxCharacters)
{
    // TODO: check maximum length
	while (iswalnum(m_ch) || m_ch == '_') 
	{
		*pstr = m_ch;
        pstr++;
        m_ch = if_getch(pParse);
	}
    *pstr = '\0';
}

// Get digits from input stream.
// This outputs characters to buffer with range checking, but no NULL termination.
// TODO: range checking
wchar_t* FdoLex::getdigits(FdoCommonParse *pParse, wchar_t* pstr)
{
	while (iswdigit(m_ch)) 
	{
		*pstr = m_ch;
		pstr++;
		m_ch = if_getch(pParse);
	}
	return pstr; 
} 

// Get unsigned number
FdoUInt32 FdoLex::get_unsigned(FdoCommonParse *pParse)
{
    wchar_t		str[maxCharLength];		// Input char storage
	wchar_t*	pStr=str;

	// Get numbers from input stream 
	pStr = getdigits(pParse, pStr);
	*pStr = CHR_NULL;
	if (FdoStringUtility::StringLength(str) == 0)
	{
		return (FdoUInt32) -1;      // No digits in input stream 
	}
	// TODO: wtoi is NOT ANSI
#ifdef _WIN32
	return (FdoUInt32) _wtoi(str);
#else
        return (FdoUInt32) wcstol(str, NULL, 10);
#endif
}

//  Get number
bool FdoLex::getnumber(FdoCommonParse *pParse, bool sign)
{
// TODO: rewrite with my AutoSketch code
//    static char buffer [64];

    bool		dot;					// Dot flag
    double      rnum;					// Real number 
    FdoInt64    i64num;
    wchar_t		str[maxCharLength];		// Input char storage
	wchar_t*	pstr = str;

	if (sign)
	{
		*pstr = '-';
		pstr++;
	}

    m_token = FdoToken_Literal;
    dot = false;

   	// Get numbers from input stream 
	pstr = getdigits(pParse, pstr);
    if (m_ch == '.') 
	{
		// Point follows: Real number 
		*pstr = m_ch;
		pstr++;
        m_ch = if_getch(pParse);
        // Some RDBMS's (e.g. SqlServer) put dots after integers that don't
        // fit in an int32. Therefore, ignore the dot if it is not followed
        // by a digit. This allows dot-terminated integers, outside the int32 range,
        // to be parsed as int64.
        if ( iswdigit(m_ch) ) {
            pstr = getdigits(pParse, pstr);
            dot = true;
        }
        else {
            pstr--;
        }
    } 
	else 
	{
		dot = false;
	}

    if (towupper(m_ch) == 'E') 
	{
		// E follows: Float point 
		*pstr = m_ch;
		pstr++;
        m_ch = if_getch(pParse);
        if (m_ch == '-' || m_ch =='+')  
		{
			*pstr = m_ch;
			pstr++;
            m_ch = if_getch(pParse);
        }
        if (!iswdigit(m_ch)) 
		{
            // Exponent shall contain digits
            throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_1_INVALIDDIGIT)));
        }
        pstr = getdigits(pParse, pstr);
		*pstr = CHR_NULL;
#ifdef _WIN32
        rnum = _wtof(str);
#else
        rnum =  wcstod(str, NULL);
#endif
    } 
	else if (dot == false) 
	{        
		// Integer number 
		*pstr = CHR_NULL;

#ifdef _WIN32
        i64num = _wtoi64( str );
#else
        i64num = atoll ( (const char*) FdoStringP(str) );   
#endif


        FdoStringP checkStr = FdoStringP::Format(
#ifdef _WIN32
            L"%I64d",
#else
            L"%lld",
#endif
            i64num
        );


        if ( checkStr == str ) {
            if (i64num <= LONG_MAX && i64num >= LONG_MIN) 
		    {
			    try  
			    {
				    FDO_SAFE_RELEASE(m_data);
				    m_data = FdoInt32Value::Create((FdoInt32)i64num);
	                return true;
			    } catch (...) {
			    }
            }
            else 
            {
			    try  
			    {
				    FDO_SAFE_RELEASE(m_data);
				    m_data = FdoInt64Value::Create(i64num);
	                return true;
			    } catch (...) {
			    }
            }
        }

#ifdef _WIN32
        rnum = _wtof(str);
#else
        wchar_t *end;
        rnum =  wcstod(str, NULL);
#endif
    }
	else 
	{
		*pstr = CHR_NULL;
#ifdef _WIN32
        rnum = _wtof(str);
#else
        rnum =  wcstod(str, NULL);
#endif
    }
	FDO_SAFE_RELEASE(m_data);
	m_data = FdoDoubleValue::Create(rnum);
	return true;
}

//  Get character string enclosed in quotes
bool FdoLex::get_string 
(
FdoCommonParse* pParse,
wchar_t*&		str,      // output buffer
wchar_t			quote     // quote symbol 
)
{
	FdoInt32	column = pParse->fdo_constraint_yylineno;

    // set up an initial empty buffer:
    FdoInt32 iBufferMaxSize = 0;
    FdoInt32 iBufferCurSize = 0;
    str = NULL;

	while ((m_ch = if_getch(pParse)) != '\0')
	{
        // Grow buffer, if necessary:
        if (iBufferCurSize == iBufferMaxSize)
        {
            FdoInt32 iNewBufferMaxSize = iBufferMaxSize==0 ? 4000 : 2 * iBufferMaxSize;
            wchar_t  *newBuffer = new wchar_t[iNewBufferMaxSize];
            if (str)
            {
                memcpy(newBuffer, str, sizeof(wchar_t) * iBufferCurSize);
                delete[] str;
            }
            str = newBuffer;
            iBufferMaxSize = iNewBufferMaxSize;
        }

        // Handle quote characters; two quotes in a row is equivalent to one literal quote character,
        // while one quote in a row represents the end of the literal string:
		if (m_ch == quote)
		{
			// If symbol is quote then look ahead for another quote:
			m_ch = if_getch(pParse);
			if (m_ch != quote)
			{
				str[iBufferCurSize] = CHR_NULL;
				return true;
			}
		}

        // Copy the character into given buffer:
		str[iBufferCurSize] = m_ch;
        iBufferCurSize++;
	}

    // If we get here, the string literal was not properly terminated with a quote character:
    delete[] str;
	throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_6_MISSINGQUOTE_d), column));
}

//   Get date string
bool FdoLex::get_date 
(
    FdoCommonParse*   pParse,
	FdoUInt16*	y, 
	FdoUInt16*	m, 
	FdoUInt16*	d
)
{
	FdoUInt32			store;            // integer number storage 
	static FdoUInt16	mdays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	// Get years value 

	if ((store = get_unsigned(pParse)) == (FdoUInt32) -1) 
	{
		// Error !!! Wrong year value
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
	}
	if (m_ch != '-') 
	{
		// Error !!! Wrong datetime string format
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
	}
	*y = (FdoUInt16) store;

	m_ch = if_getch(pParse);   // get next symbol 

	// Get months value 
	store = get_unsigned(pParse);
	if (store < 1 || store > 12) 
	{
		// Error !!! Wrong month value
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_3_DATETIMEOUTOFRANGE)));
	}
	if (m_ch != '-') 
	{
		// Error !!! Wrong datetime string format
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
	}

	*m = (FdoUInt16) store;

	m_ch = if_getch(pParse);   /* get next symbol */

	/* Get days value */
	store = get_unsigned(pParse);

	/* Check day value */
	if (store == (FdoUInt32) -1) 
	{
		// Error !!! Wrong day value
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
	}

	if (*y % 4 == 0 && !(*y % 100 == 0 && *y % 400 != 0) && *m == 2) 
	{
		// Leap year February
        if (store > 29) 
		{
			// Error !!! Wrong day value
			throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_3_DATETIMEOUTOFRANGE)));
		}
	} 
	else if (store > mdays[*m - 1]) 
	{ 
		// Error !!! Wrong day value
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
	}
	*d = (FdoUInt16) store;
	return true;
} 

//  Get second value
bool FdoLex::get_second(FdoCommonParse *pParse, double *sf)
{
	FdoUInt16	s;        // Seconds value
	FdoUInt32	f;        // Fraction
	FdoInt32			st  = 0;  // Fraction start
	FdoInt32			en  = 0;  // Fraction end


	/* Get seconds value */
	f = (FdoUInt16) 0;
	s = (FdoUInt16) get_unsigned(pParse);
	if (s == (FdoUInt16) -1) {
		// Error !!! Negative second value
		return false; 
	}

	if (m_ch == '.') {  /* seconds fraction */
		m_ch = if_getch(pParse);
		st = m_cc;
		f = get_unsigned(pParse); /* Get fraction */
		en = m_cc;
		if (f == (FdoUInt32) -1) {
			// Error !!! Negative second fraction
			throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_3_DATETIMEOUTOFRANGE)));
		}
	}
	* sf = make_double (s, f, en - st);

	return true; 

}

// Get time value
bool FdoLex::get_timevalue(
    FdoCommonParse  *   pParse,
	FdoUInt16 	*	h, 
	FdoUInt16 	*	m, 
	double 	*	s 
)
{
	FdoUInt16 		store;     /* Storage for numbers */

	/* Get hours value */
	store = (FdoUInt16) get_unsigned(pParse);
	if (store > 23) {
		// Error !!! Wrong hour value
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_3_DATETIMEOUTOFRANGE)));
	}
	if (m_ch != ':' && m_ch != '-') {
		// Error !!! Wrong datetime format
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
	}
	*h = store;

	m_ch = if_getch(pParse);   /* get next symbol */

	/* Get minutes value */
	store = (FdoUInt16) get_unsigned(pParse);
	if (store > 59) {
		// Error !!! Wrong minute value
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_3_DATETIMEOUTOFRANGE)));
	}
	if (m_ch != ':' && m_ch != '-') {
		// Error !!! Wrong datetime string format
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
	}
	*m = store;
	m_ch = if_getch(pParse);   /* get next symbol */

	// Get seconds value 
	if (get_second(pParse, s) == false) {   
		// Error !!! Wrong second 
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_3_DATETIMEOUTOFRANGE)));
	}

	if (*s >= 60.0 && *s < 0) {
		// Error !!! Wrong second value
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_3_DATETIMEOUTOFRANGE)));
	}
	return true;
}

//  Get time 
bool FdoLex::get_time(
    FdoCommonParse  *   pParse,
	FdoUInt16		*	h, 
	FdoUInt16		*	m, 
	double		*	s 
)
{
	// Get time value 
	if (! get_timevalue(pParse, h, m, s)) {
		// Error !!! Wrong time value
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
	}
	return true;    /* return to caller */
}

//  Get timestamp value
bool FdoLex::get_timestamp(
    FdoCommonParse  *   pParse,
	FdoUInt16		*	y, 
	FdoUInt16		*	m, 
	FdoUInt16		*	d,
	FdoUInt16		*	h, 
	FdoUInt16		*	mt, 
	double		*	s 
)
{
	/* Get date value */
	if (get_date (pParse, y, m, d) == false) {
		// Error !!! Wrong date value
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
	}

	if (m_ch != ' ' && m_ch != '-') {
		// Error !!! Wrong format
		throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_2_INVALIDDATETIME)));
	}
	m_ch = if_getch(pParse);   /* get next symbol */
	return get_time(pParse, h, mt, s);
}

//  Get bit string
bool FdoLex::get_bitstring(FdoCommonParse *pParse)
{
	FdoInt32			len         = 0;
//	FdoInt32			rlen        = 0;
	char buffer [256];

//	memset(buffer, 0, 256);
	for (FdoInt32 i=0; i<256; i++)
		buffer[i] = 0;

	m_ch = if_getch(pParse);
	while (m_ch != '\'') 
	{
		if (m_ch == '1') {
			buffer[len / 8] |= (0x80 >> (len % 8));

		} else if (m_ch != '0') {
			// Error !!! Wrong binary digit
			throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_8_INVALIDBITDIGIT)));
		}
		len ++;
		if (len > maxBinaryLength) {
			// Error !!! Bit string is too long
			throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_5_STRINGTOOLONG)));
		}
		m_ch = if_getch(pParse);
	}
	m_ch = if_getch(pParse);  /* get next character after ' */

//TODO:	m_aBit.StoreValue (buffer, len, &rlen);
//TODO:	m_aData = (CQryData *) &m_aBit;

	return true; 
  
}

//  Get hex string
bool FdoLex::get_hexstring(FdoCommonParse *pParse)
{
	char buffer[256];
	FdoInt32			val;                   // value of hex number 
	FdoInt32			len  = 0;
//	FdoInt32			rlen = 0;

//	memset(buffer, 0, 256);
	for (FdoInt32 i=0; i<256; i++)
		buffer[i] = 0;
	m_ch = if_getch(pParse);
	while (m_ch != '\'') {
		m_ch = towupper(m_ch);
		if (iswxdigit(m_ch)) {
			if (m_ch >= '0' && m_ch <= '9') 
				val = (FdoInt32)(m_ch - '0');
			else 
				val = (FdoInt32)(m_ch - 'A' + 10);
			
			if (len % 2 == 0) 
				buffer[len / 2] |= (val << 4);
			else
				buffer[len / 2] |= val;

		} else {
			// Error !!! Wrong Hexadecimal digit
			throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_7_INVALIDHEXDIGIT)));
		}

		len ++;
			if (len > maxBinaryLength) {
				// Error !!! String too long
				throw FdoException::Create(NlsMsgGetFdo(FDO_NLSID(PARSE_5_STRINGTOOLONG)));
			}
			m_ch = if_getch(pParse);
	}
	m_ch = if_getch(pParse);  /* get next character after ' */

//TODO:	m_aBit.StoreValue(buffer, len*4, &rlen);
//TODO:	m_aData = (CQryData *) &m_aBit;

	return true;
  
} // end of get_hexstring()

//  Find first non-blank symbol
const wchar_t FdoLex::find_nonblank(FdoCommonParse *pParse) 
{
	// skip whitespace
	while (m_ch == ' ' || m_ch == '\t')  
	{
		m_ch = if_getch(pParse) ;
	}
	return m_ch;
}

//  Return next character after the current one
const wchar_t FdoLex::nextchar(void) const 
{
	return m_line[m_cc];
}

//  Return previous character before the current one
const wchar_t FdoLex::prevchar(void) const 
{
	wchar_t	c;
	return (m_cc<2) ? c = '\0': m_line[m_cc-2];
}

// used by FdoIdentifier::ToString to determine if quotes are required.
bool IsKeyWord(FdoString* word)
{
    return findtoken(word, g_aKeyWords, KEYWORDCOUNT) >= 0;
}


