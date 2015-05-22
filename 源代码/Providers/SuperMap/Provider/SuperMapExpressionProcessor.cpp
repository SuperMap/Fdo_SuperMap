
/** \file	 SuperMapExpressionProcessor.cpp
*  \author	 Âí¿¡
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/

#include "SuperMap.h"

#define SM_FILTER_OPEN_PARENTH " ( "
#define SM_FILTER_CLOSE_PARENTH " ) "

// For arthmetic operation
#define SM_FILTER_ARITHMETIC_PLUS    " + "
#define SM_FILTER_ARITHMETIC_MINUS   " - "
#define SM_FILTER_ARITHMETIC_MULT    " * "
#define SM_FILTER_ARITHMETIC_DIV     " / "

SuperMapExpressionProcessor::SuperMapExpressionProcessor(void)
{

}

SuperMapExpressionProcessor::~SuperMapExpressionProcessor(void)
{

}
SuperMapExpressionProcessor::SuperMapExpressionProcessor(SuperMapFilterStringBuffer *pStringBuff, UGC::UGEngineType DsEnginetype)
{
	m_pStringBuff = pStringBuff;
	m_DsEngineType = DsEnginetype;
}

void SuperMapExpressionProcessor::ProcessExpresion( FdoExpression* Expr)
{
	Expr->Process(this); ////recursion call, left or right Filter
}

void SuperMapExpressionProcessor::AppendString(const char *Str)
{
	if(NULL != Str)
	{
		m_pStringBuff->AppendString(Str);
	}
}

void SuperMapExpressionProcessor::PrependString(const char *Str)
{
	if(NULL != Str)
	{
		m_pStringBuff->PrependString(Str);
	}
}

void SuperMapExpressionProcessor::ProcessBinaryExpression(FdoBinaryExpression& expr)
{
	FdoPtr<FdoExpression> lftExpr = expr.GetLeftExpression();
    FdoPtr<FdoExpression> rgtExpr = expr.GetRightExpression();
    if( lftExpr == NULL  )
	{
        throw FdoException::Create(NlsMsgGet(SUPERMAP_FILTER_MISSING_EXPRESSION, "FdoBinaryExpression is missing the left expression"));
	}
    if( rgtExpr == NULL )
	{
        throw FdoException::Create(NlsMsgGet(SUPERMAP_FILTER_MISSING_EXPRESSION, "FdoBinaryExpression is missing the right expression"));
	}
    AppendString( SM_FILTER_OPEN_PARENTH );
    ProcessExpresion( lftExpr );
    switch( expr.GetOperation() )
    {
        case FdoBinaryOperations_Add: 
			AppendString( SM_FILTER_ARITHMETIC_PLUS );
            break;
        case FdoBinaryOperations_Subtract: 
			AppendString( SM_FILTER_ARITHMETIC_MINUS );
            break;

        case FdoBinaryOperations_Multiply: 
			AppendString( SM_FILTER_ARITHMETIC_MULT );
            break;

        case FdoBinaryOperations_Divide: 
			AppendString( SM_FILTER_ARITHMETIC_DIV );
            break;

        default:
			throw FdoException::Create(NlsMsgGet(SUPERMAP_FILTER_BINARY_EXPRESSION_NOT_SUPPORTED, "ProcessBinaryExpression unsupported binary expression"));
    }
    ProcessExpresion( rgtExpr );
    AppendString( SM_FILTER_CLOSE_PARENTH );
}

void SuperMapExpressionProcessor::ProcessUnaryExpression(FdoUnaryExpression& expr)
{
	FdoPtr<FdoExpression>uniExpr = expr.GetExpression();
    if( uniExpr == NULL )
	{
        throw FdoException::Create(NlsMsgGet(SUPERMAP_FILTER_MISSING_EXPRESSION, "FdoUnaryExpression is missing expression"));
	}

    if( expr.GetOperation() == FdoUnaryOperations_Negate )
    {
        AppendString( " ( - ( " );
        ProcessExpresion( uniExpr );
        AppendString( " ) ) ");
    }
    else
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_FILTER_ONLY_SUPPORT_NEGATE, "FdoUnaryExpression supports only the negate operation"));
	}
}

void SuperMapExpressionProcessor::ProcessFunction(FdoFunction& expr)
{
	FdoStringP fname = expr.GetName();
	AppendString( fname );

	AppendString("( "); 
	FdoPtr<FdoExpressionCollection> exprCol = expr.GetArguments();
	for(int i=0; i<exprCol->GetCount(); i++ )
	{
		if( i!= 0 )
		{
			AppendString( ", " );
		}
		FdoPtr<FdoExpression>exp = exprCol->GetItem( i );
		ProcessExpresion( exp );
	}
	AppendString( SM_FILTER_CLOSE_PARENTH );
}

void SuperMapExpressionProcessor::ProcessIdentifier(FdoIdentifier& expr)
{
	AppendString( SuperMapUtil::WcharToString( (expr.GetName()) ).c_str() );
}

void SuperMapExpressionProcessor::ProcessComputedIdentifier(FdoComputedIdentifier& expr)
{
	FdoPtr<FdoExpression>pExpr = expr.GetExpression();
    if( pExpr == NULL )
	{
		throw FdoException::Create(NlsMsgGet(SUPERMAP_FILTER_MISSING_EXPRESSION, "FdoComputedIdentifier is missing the expression"));
	}

    AppendString( SM_FILTER_OPEN_PARENTH );
    ProcessExpresion( pExpr );
    AppendString( SM_FILTER_CLOSE_PARENTH );
}

void SuperMapExpressionProcessor::ProcessParameter(FdoParameter& expr)
{

}

void SuperMapExpressionProcessor::ProcessBooleanValue(FdoBooleanValue& expr)
{
	if( expr.IsNull() )
	{  
		AppendString( "NULL" );
		return;
	}
	char *strBoolean = NULL;
	switch(m_DsEngineType) //because different engine type has different datatime format
	{
	case UGC::SDB:
	case UGC::SDBPlus:
		if( expr.GetBoolean() )
		{
			strBoolean = " true ";
		}
		else
		{
			strBoolean = " false ";
		}
		break;

	case UGC::Oracle:  //three type for oralce
	case UGC::OraclePlus:
	case UGC::OracleSpatial:
		if( expr.GetBoolean() )
		{
			strBoolean = " 1 ";
		}
		else
		{
			strBoolean = " 0 ";
		}
		break;

	case UGC::SQLPlus: //type for SQL Server
		if( expr.GetBoolean() )
		{
			strBoolean = " 1 ";
		}
		else
		{
			strBoolean = " 0 ";
		}
		break;

	default:
		break;
	}//switch
	AppendString( strBoolean );
}

void SuperMapExpressionProcessor::ProcessByteValue(FdoByteValue& expr)
{
	if( expr.IsNull() )
	{  
		AppendString( "NULL" );
	}
	else
	{
		char   val[2];
		val[0] = expr.GetByte();
		val[1] = '\0';
		AppendString( "'" );
		AppendString( val );
		AppendString( "'" );
	}
}

void SuperMapExpressionProcessor::ProcessDateTimeValue(FdoDateTimeValue& expr)
{
	if( expr.IsNull() )
	{  
		AppendString( "NULL" );
		return;
	}

	FdoDateTime dt = expr.GetDateTime(); 
	char *strTimebegin = NULL;
	char * strTimeend = NULL;
	char    tmpValue[124];

	switch(m_DsEngineType) //because different engine type has different datatime format
	{
	case UGC::SDB:
	case UGC::SDBPlus:
		strTimebegin = " #";
		strTimeend = "# ";
		if( dt.IsDateTime() )
		{ 
			sprintf( tmpValue,"%d-%d-%d %d:%d:%d",dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.seconds); 
		}
		if( dt.IsDate() )
		{
			sprintf( tmpValue,"%d-%d-%d",dt.year, dt.month, dt.day);
		}
		if( dt.IsTime() )
		{
			sprintf( tmpValue,"%d:%d:%d",dt.hour, dt.minute, dt.seconds);
		}
		break;

	case UGC::Oracle:  //three type for oralce
	case UGC::OraclePlus:
	case UGC::OracleSpatial:
		strTimebegin = " TO_DATE(";
		if( dt.IsDateTime() )
		{ 
			sprintf( tmpValue,"'%d-%d-%d %d:%d:%d'",dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.seconds); 
			strTimeend = ",'YYYY-MM-DD HH24:MI:SS') ";
		}
		if( dt.IsDate() )
		{
			sprintf( tmpValue,"'%d-%d-%d'",dt.year, dt.month, dt.day);
			strTimeend = ",'YYYY-MM-DD') ";
		}
		if( dt.IsTime() )
		{
			sprintf( tmpValue,"'%d:%d:%d'",dt.hour, dt.minute, dt.seconds);
			strTimeend = ",'HH24:MI:SS') ";
		}
		break;

	case UGC::SQLPlus: //type for SQL Server
		strTimebegin = " '";
		strTimeend = "' ";
		if( dt.IsDateTime() )
		{ 
			sprintf( tmpValue,"%d-%d-%d %d:%d:%d",dt.year, dt.month, dt.day, dt.hour, dt.minute, dt.seconds); 
		}
		if( dt.IsDate() )
		{
			sprintf( tmpValue,"%d-%d-%d",dt.year, dt.month, dt.day);
		}
		if( dt.IsTime() )
		{
			sprintf( tmpValue,"%d:%d:%d",dt.hour, dt.minute, dt.seconds);
		}
		break;

	default:
		break;
	}//switch

	AppendString( strTimebegin );	  
	AppendString( tmpValue );
	AppendString( strTimeend );
	return;
}

void SuperMapExpressionProcessor::ProcessDecimalValue(FdoDecimalValue& expr)
{
	if( expr.IsNull() )
	{
		AppendString( "NULL" );
	}
	else
	{
		char    tmpValue[124];
		sprintf(tmpValue,"%.10f",expr.GetDecimal());
		AppendString( tmpValue );
	}
}

void SuperMapExpressionProcessor::ProcessDoubleValue(FdoDoubleValue& expr)
{
	if( expr.IsNull() )
	{
		AppendString( "NULL" );
	}
	else
	{
		char    tmpValue[124];
		sprintf(tmpValue,"%.10f",expr.GetDouble());
		AppendString( tmpValue );
	}
}

void SuperMapExpressionProcessor::ProcessInt16Value(FdoInt16Value& expr)
{
	if( expr.IsNull() )
	{
		AppendString( "NULL" );
	}
	else
	{
		char    tmpValue[124];
		sprintf(tmpValue,"%d",(int)expr.GetInt16());
		AppendString( tmpValue );
	}
}

void SuperMapExpressionProcessor::ProcessInt32Value(FdoInt32Value& expr)
{
	if( expr.IsNull() )
	{
		AppendString( "NULL" );
	}
	else
	{
		char    tmpValue[124];
		sprintf(tmpValue,"%ld",(long)expr.GetInt32());
		AppendString( tmpValue );
	}
}

void SuperMapExpressionProcessor::ProcessInt64Value(FdoInt64Value& expr)
{
	if( expr.IsNull() )
	{  
		AppendString( "NULL" );
		return; 
	}

	char    tmpValue[124];

#ifdef _WIN32
	strncpy( tmpValue, _i64toa( (FdoInt64)(dynamic_cast<FdoInt64Value&>(expr)).GetInt64(),tmpValue, 10 ), 123 );
	tmpValue[123]='\0';
#else

	sprintf(tmpValue, "%lld", (FdoInt64)(dynamic_cast<FdoInt64Value&>(expr)).GetInt64());
#endif
	AppendString(tmpValue);
}

void SuperMapExpressionProcessor::ProcessSingleValue(FdoSingleValue& expr)
{
	if( expr.IsNull() )
	{  
		AppendString( "NULL" );
	}
	else
	{
		char    tmpValue[124];
		sprintf(tmpValue,"%.8f",expr.GetSingle());
		AppendString( tmpValue );
	}
}

void SuperMapExpressionProcessor::ProcessStringValue(FdoStringValue& expr)
{
	if( expr.IsNull() )
	{  
		AppendString( "NULL" );
	}
	else
	{
		FdoStringP fstr = expr.ToString();
		AppendString( SuperMapUtil::WcharToString(fstr).c_str() );
	}
}

void SuperMapExpressionProcessor::ProcessBLOBValue(FdoBLOBValue& expr)
{
	if( expr.IsNull() )
    {  
      AppendString( "NULL" );
      return; 
    }
	throw FdoException::Create(NlsMsgGet(SUPERMAP_FILTER_NOT_SUPPORTED_EXPRESSION, "Unsupported FDO type in expression"));
}

void SuperMapExpressionProcessor::ProcessCLOBValue(FdoCLOBValue& expr)
{
	if( expr.IsNull() )
    {  
      AppendString( "NULL" );
      return; 
    }
    throw FdoException::Create(NlsMsgGet(SUPERMAP_FILTER_NOT_SUPPORTED_EXPRESSION, "Unsupported FDO type in expression"));
}

void SuperMapExpressionProcessor::ProcessGeometryValue(FdoGeometryValue& expr)
{

}
