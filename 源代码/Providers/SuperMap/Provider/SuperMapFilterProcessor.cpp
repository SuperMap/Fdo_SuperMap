
/** \file	 SuperMapFilterProcessor.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-28
*/

#include "SuperMap.h"

#define SM_FILTER_OPEN_PARENTH " ( "
#define SM_FILTER_CLOSE_PARENTH " ) "

#define SM_FILTER_COMMA " , "
#define SM_FILTER_LOGICAL_AND " AND "
#define SM_FILTER_LOGICAL_OR " OR "
#define SM_FILTER_LOGICAL_NOT " NOT "
#define SM_FILTER_IN " IN "
#define SM_FILTER_IS_NULL " IS NULL "

// For comparison operation
#define SM_FILTER_EQUAL_OP               " = "
#define SM_FILTER_NOT_EQUAL_OP           " <> "
#define SM_FILTER_GREATER_THAN_OP        " > "
#define SM_FILTER_GREATER_OR_EQUAL_OP    " >= "
#define SM_FILTER_LESS_THAN_OP           " < "
#define SM_FILTER_LESS_OR_EQUAL_OP       " <= "
#define SM_FILTER_LIKE_OP                " LIKE "
#define SM_FILTER_SPATIAL_OP             " 1 < 2 " //spatial conditon, in UGC, spatial condition is not included
												   //in m_strFilter, but fdo do. so here give a always true condition

SuperMapFilterProcessor::SuperMapFilterProcessor(UGC::UGEngineType DsEngineType)
{
	m_pGeometry = NULL;
	m_DsEngineType = DsEngineType;
	m_nSpatialQueryType = UGC::UGSpatialQuery::UGIntersects; //缺省的空间查询类型
}

SuperMapFilterProcessor::~SuperMapFilterProcessor(void)
{

}

void SuperMapFilterProcessor::ProcessFilter(FdoFilter* Filter)
{
	Filter->Process(this); //递归调用，Filter的左或者右
}

void SuperMapFilterProcessor::ProcessExpresion( FdoExpression* Expr, bool bSpatialCondition, 
											    bool bEnvelopeIntersect)
{
	//表达式处理器和该类共用一个解析缓存
	SuperMapExpressionProcessor ExpressionProcessor( &m_StringBuff, m_DsEngineType ); 
	Expr->Process( &ExpressionProcessor );
}

void SuperMapFilterProcessor::AppendString(const char *Str)
{
	m_StringBuff.AppendString(Str);
}

void SuperMapFilterProcessor::PrependString(const char *Str)
{
	m_StringBuff.PrependString(Str);
}

void SuperMapFilterProcessor::ProcessBinaryLogicalOperator(FdoBinaryLogicalOperator& Filter)
{
	FdoPtr<FdoFilter>leftop = Filter.GetLeftOperand(); //left filter
	FdoPtr<FdoFilter>rightop = Filter.GetRightOperand(); //right filter
	//AppendString(SM_FILTER_OPEN_PARENTH); //'('
	if( Filter.GetOperation() == FdoBinaryLogicalOperations_And )
	{
		ProcessFilter( leftop );  
		AppendString( SM_FILTER_LOGICAL_AND );
		ProcessFilter( rightop );
	}
	else
	{   
		ProcessFilter( leftop );
		AppendString( SM_FILTER_LOGICAL_OR );
		ProcessFilter( rightop );
	}
	//AppendString(SM_FILTER_CLOSE_PARENTH);
}

void SuperMapFilterProcessor::ProcessUnaryLogicalOperator(FdoUnaryLogicalOperator& Filter)
{
	FdoPtr<FdoFilter>unaryop = Filter.GetOperand(); //get the operator
	if( unaryop == NULL ) 
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FILTER_MISSING_OPERAND, "FdoUnaryLogicalOperator is missing the operand"));
	}

	AppendString(SM_FILTER_OPEN_PARENTH);
	if ( Filter.GetOperation() == FdoUnaryLogicalOperations_Not )
	{
		AppendString( SM_FILTER_LOGICAL_NOT );
	}
	else
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FILTER_UNARY_ONLY_SUPPORT_NOT, "FdoUnaryLogicalOperator supports only the 'Not' operation"));
	}
	ProcessFilter( unaryop );
	AppendString(SM_FILTER_CLOSE_PARENTH);
}
 
void SuperMapFilterProcessor::ProcessComparisonCondition(FdoComparisonCondition& Filter)
{
	FdoPtr<FdoExpression> leftexp = Filter.GetLeftExpression();
    FdoPtr<FdoExpression> rightexp = Filter.GetRightExpression();
    if( leftexp == NULL  ) 
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FILTER_MISSING_EXPRESSION, "FdoComparisonCondition is missing the left expression"));
	}
    if( rightexp == NULL ) 
	{
		throw FdoException::Create (NlsMsgGet (SUPERMAP_FILTER_MISSING_EXPRESSION, "FdoComparisonCondition is missing the left expression"));
	}

    AppendString( SM_FILTER_OPEN_PARENTH );
    ProcessExpresion( leftexp );

    switch ( Filter.GetOperation() )
    {
        case FdoComparisonOperations_EqualTo: 
          AppendString( SM_FILTER_EQUAL_OP );
        break;

        case FdoComparisonOperations_NotEqualTo: 
          AppendString( SM_FILTER_NOT_EQUAL_OP );
        break;

        case FdoComparisonOperations_GreaterThan: 
          AppendString( SM_FILTER_GREATER_THAN_OP );
        break;

        case FdoComparisonOperations_GreaterThanOrEqualTo: 
          AppendString( SM_FILTER_GREATER_OR_EQUAL_OP );
        break;

        case FdoComparisonOperations_LessThan: 
          AppendString( SM_FILTER_LESS_THAN_OP );
        break;

        case FdoComparisonOperations_LessThanOrEqualTo: 
          AppendString( SM_FILTER_LESS_OR_EQUAL_OP );
        break;

        case FdoComparisonOperations_Like: 
          AppendString( SM_FILTER_LIKE_OP );
        break;

        default:
          throw FdoException::Create (NlsMsgGet (SUPERMAP_FILTER_UNKNOWN_COMPARISION_OPERATION, "FdoComparisonCondition unkown comparison operation"));
        break;
    }
    ProcessExpresion( rightexp );
    AppendString( SM_FILTER_CLOSE_PARENTH );
}

void SuperMapFilterProcessor::ProcessInCondition(FdoInCondition& Filter)
{
	int i;
    FdoPtr<FdoExpression> exp;
    FdoPtr<FdoIdentifier> id = Filter.GetPropertyName();
    if( id == NULL )
	{
        throw FdoException::Create (NlsMsgGet (SUPERMAP_FILTER_MISSING_PROPERTY, "FdoInCondition is missing the property name"));
	}

    FdoPtr<FdoValueExpressionCollection>expressions = Filter.GetValues();
    if( expressions == NULL || expressions->GetCount() <= 0 )
	{
        throw FdoException::Create (NlsMsgGet (SUPERMAP_FILTER_EMPTY_PROPERTY_VALUE, "FdoInCondition has an empty value list"));
	}

    AppendString(SM_FILTER_OPEN_PARENTH);
    ProcessExpresion( id );
    AppendString( SM_FILTER_IN );
    AppendString(SM_FILTER_OPEN_PARENTH);
    for(i=0; i < expressions->GetCount()-1; i++ )
    {
        exp = expressions->GetItem(i);
        ProcessExpresion( exp );
        AppendString( SM_FILTER_COMMA );
    }
    exp = expressions->GetItem( i );
    ProcessExpresion(exp);
    AppendString(SM_FILTER_CLOSE_PARENTH);
    AppendString(SM_FILTER_CLOSE_PARENTH);
}

void SuperMapFilterProcessor::ProcessNullCondition(FdoNullCondition& Filter)
{
	FdoPtr<FdoIdentifier>id = Filter.GetPropertyName();
    if( id == NULL )
	{
        throw FdoException::Create (NlsMsgGet (SUPERMAP_FILTER_MISSING_PROPERTY, "FdoInCondition is missing the property name"));
	}
    AppendString(SM_FILTER_OPEN_PARENTH);
    ProcessExpresion( id );
    AppendString(SM_FILTER_IS_NULL );
    AppendString(SM_FILTER_CLOSE_PARENTH);
}

void SuperMapFilterProcessor::ProcessSpatialCondition(FdoSpatialCondition& Filter)
{
	AppendString(SM_FILTER_SPATIAL_OP); //空间查询时，赋值永真条件

	FdoPtr<FdoExpression> geomexp = Filter.GetGeometry();
	FdoGeometryValue* geomval = dynamic_cast<FdoGeometryValue*>(geomexp.p);

    if (geomval)
    {
        FdoPtr<FdoByteArray> fgf = geomval->GetGeometry();
		SuperMapFgfGeoToUGCGeo FgfGeoToUGCGeo(FDO_SAFE_ADDREF(fgf.p), false, "", 0.0, false, true); 

		m_pGeometry = FgfGeoToUGCGeo.GetGeometry();
		m_GeometryArray.push_back(m_pGeometry);
	}
	switch( Filter.GetOperation() )
	{
		/// Test to see if the geometric property value spatially intersects the
		/// given geometry.
	case FdoSpatialOperations_Intersects:
		m_nSpatialQueryType = UGC::UGSpatialQuery::UGIntersects;
		break;

		/// Test to see if the geometric property value spatially contains the
		/// literal geometric value.
	case FdoSpatialOperations_Contains: 
		m_nSpatialQueryType = UGC::UGSpatialQuery::UGContains;  
		break;

		/// Test to see if the geometric property value spatially crosses the given
		/// geometry.
	case FdoSpatialOperations_Crosses:
		m_nSpatialQueryType = UGC::UGSpatialQuery::UGCrosses;
		break;

		/// Test to see if the geometric property value is spatially
		/// disjoint from the given geometry.
	case FdoSpatialOperations_Disjoint:
		m_nSpatialQueryType = UGC::UGSpatialQuery::UGDisjoint;
		break;

		/// Test to see if the geometric property value spatially overlaps the given
		/// geometry
	case FdoSpatialOperations_Overlaps:
		m_nSpatialQueryType = UGC::UGSpatialQuery::UGOverlaps;
		break;

		/// Test to see if the geometric property value spatially touches the given
		/// geometry.
	case FdoSpatialOperations_Touches:
		m_nSpatialQueryType = UGC::UGSpatialQuery::UGTouches;
		break;

		/// Test to see if the geometric property value is spatially within the
		/// given geometry.
	case FdoSpatialOperations_Within:
		m_nSpatialQueryType = UGC::UGSpatialQuery::UGWithin;  
		break;

		/// Test to see if the geometric property value is spatially equal to the
		/// given geometry.
	case FdoSpatialOperations_Equals:
		m_nSpatialQueryType = UGC::UGSpatialQuery::UGIdentical;
		break;  

		/// Test to see if the geometric property value is covered by the interior
		/// and boundary of the given geometry.
	case FdoSpatialOperations_CoveredBy: //there is no corresponding UGC type!!! now use UGCWithin
		m_nSpatialQueryType = UGC::UGSpatialQuery::UGWithin; 
		break;

		/// Test to see if the geometric property value is inside the interior
		/// of the given geometry, not touching the boundary.
	case FdoSpatialOperations_Inside:   // 参考对象内部的记录
		m_nSpatialQueryType = UGC::UGSpatialQuery::UGContains; // modified by zhouxu 2008-5-4 
		break;

		/// Test to see if the envelope of the referenced geometric property value spatially intersects the
		/// given geometry.
	case FdoSpatialOperations_EnvelopeIntersects:
		m_nSpatialQueryType = UGC::UGSpatialQuery::UGExtentIntersect;
		break;

	default:
		break;  
	}
}

UGC::UGGeometry *SuperMapFilterProcessor::GetGeometry()
{
	return m_pGeometry;
}

int SuperMapFilterProcessor::GetSpatialQueryType()
{
	return m_nSpatialQueryType;
}

void SuperMapFilterProcessor::ProcessDistanceCondition(FdoDistanceCondition& Filter)
{

}
