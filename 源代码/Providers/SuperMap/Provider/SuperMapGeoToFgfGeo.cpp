/** \file	 SuperMapGeoToFgfGeo.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-09
*/

#include "SuperMap.h"

//TODO::m_FdoPoint m_FdoMultiLine m_FdoPolygon 再研究，是否可以用局部变量就可以解决
//TODO:: m_nSubCount m_subPointsCount 最好能改为参数传递的形式

#define SUPERMAP_GEOMETRY_INITIAL_SIZE    1000 // bytes

SuperMapGeoToFgfGeo::SuperMapGeoToFgfGeo(void)
{
}

SuperMapGeoToFgfGeo::~SuperMapGeoToFgfGeo(void)
{
}

SuperMapGeoToFgfGeo::SuperMapGeoToFgfGeo(UGC::UGRecordset *pRecordset)
{
	m_pRecordset = pRecordset;
	m_pElemGeometry = NULL;
	if(m_pRecordset)
	{
		UGC::UGbool bHasGeometry = m_pRecordset->HasGeometry();
		if(bHasGeometry)
		{
			m_pRecordset->GetGeometry(m_pElemGeometry);
		}
	}
	m_pFdoGeoFactory = FdoFgfGeometryFactory::GetInstance();
	m_pRetByteArray = NULL;
	m_nSubCount = 0;
}

// 创建FDO要素, 包括FDO 点、线、面
void SuperMapGeoToFgfGeo::CreateFdoGeo()
{
	if (m_pElemGeometry != NULL)
	{
		//modified by zhoux 2007-11-28
		if(m_pElemGeometry->GetType() != UGC::UGGeometry::GeoText)
		{
			m_pElemGeometry->GetSpatialData(m_points, m_subPointsCount, m_nSubCount);
		}

		if(m_pFdoGeoFactory) 
		{
			switch(m_pElemGeometry->GetType()) 
			{
			case UGC::UGGeometry::GeoPoint:
			case UGC::UGGeometry::GeoText: // added by zhoux
			case UGC::UGGeometry::GeoMultiPoint:
				CreateFdoPoint();
				break;

			case UGC::UGGeometry::GeoLine:
			case UGC::UGGeometry::GeoArc:
			case UGC::UGGeometry::GeoCurve:
			case UGC::UGGeometry::GeoBSpline:
			case UGC::UGGeometry::GeoCardinal:
			case UGC::UGGeometry::GeoEllipticArc:
				CreateFdoMultiLine();
				break;

			case UGC::UGGeometry::GeoRect:
			case UGC::UGGeometry::GeoRectRound:
			case UGC::UGGeometry::GeoCircle:
			case UGC::UGGeometry::GeoEllipse:
			case UGC::UGGeometry::GeoRegion:
			case UGC::UGGeometry::GeoPie:
			case UGC::UGGeometry::GeoChord:
				CreateFdoPolygon();
				break;

			case UGC::UGGeometry::GeoCompound:
				CreateFdoCompoundGeometry();
				break;

			case UGC::UGGeometry::GeoLineM:
			case UGC::UGGeometry::GeoImageBlock:
			case UGC::UGGeometry::GeoIcon:
			case UGC::UGGeometry::GeoEquilateral:
				break;

			default:
				break;

			}//switch
		}//if(m_pFdoGeoFactory)
		delete m_pElemGeometry;
		m_pElemGeometry = NULL;
	}//if (m_pElemGeometry != NULL)
}

void SuperMapGeoToFgfGeo::CreateFdoPoint()
{
	FdoPtr<FdoIPoint> FdoPoint;
	FdoPtr<FdoIMultiPoint> FdoMultiPoint;
	// modified by zhouxu for support GeoText To FdoPoint 2007-11-28
	if(m_pElemGeometry->GetType() != UGC::UGGeometry::GeoText)
	{
		long m = 0;
		for (int i = 0; i <  m_nSubCount; i++)
		{
			for (int j = 0; j < m_subPointsCount[i] ; j ++)
			{
				m_fdoCoordinatesArray.Add(m_points[m].x);
				m_fdoCoordinatesArray.Add(m_points[m].y);
				m++;
			}	  
		}
		if(m_nSubCount == 1) //一个点
		{
			FdoPoint = m_pFdoGeoFactory->CreatePoint(FdoDimensionality_XY, m_fdoCoordinatesArray.GetData());//FDO point			
			m_pRetByteArray = m_pFdoGeoFactory->GetFgf(FdoPoint.p);
		}
		else //多点
		{
			FdoMultiPoint = m_pFdoGeoFactory->CreateMultiPoint(FdoDimensionality_XY, 
				m_fdoCoordinatesArray.GetSize(), 
				m_fdoCoordinatesArray.GetData());//FDO multipoint
			m_pRetByteArray = m_pFdoGeoFactory->GetFgf(FdoMultiPoint.p);
		}
	}
	else 
	{
		if(m_pRecordset)
		{
			//不转化CAD数据集中的文本,因为和CAD数据集中的文本和点区别不开  // 打开复合数据集中的文本 by zhouxu 2008-4-28 
			/*if(m_pRecordset->GetDataset()->GetType() != UGC::UGDataset::CAD) 
			{*/
				// 文本几何类型转点暂时只支持一个子对象的情况
				UGC::UGGeoText* pGeoText = (UGC::UGGeoText*)m_pElemGeometry;
				m_fdoCoordinatesArray.Add(pGeoText->GetSubAnchor(0).x);
				m_fdoCoordinatesArray.Add(pGeoText->GetSubAnchor(0).y);

				FdoPoint = m_pFdoGeoFactory->CreatePoint(FdoDimensionality_XY, m_fdoCoordinatesArray.GetData());
				m_pRetByteArray = m_pFdoGeoFactory->GetFgf(FdoPoint.p);
			//}
		}
	}
}

void SuperMapGeoToFgfGeo::CreateFdoMultiLine()
{
	FdoPtr<FdoILineString> FdoLine;
	FdoPtr<FdoIMultiLineString> FdoMultiLine;
	FdoPtr<FdoLineStringCollection> linecollection; //创建多线

	long m = 0;
	linecollection = FdoLineStringCollection::Create();

	for (int i = 0; i <  m_nSubCount; i++)
	{
		for (int j = 0; j < m_subPointsCount[i] ; j ++)
		{
			m_fdoCoordinatesArray.Add(m_points.GetData()[m].x);
			m_fdoCoordinatesArray.Add(m_points.GetData()[m].y);
			m++;
		}
		FdoLine = m_pFdoGeoFactory->CreateLineString(FdoDimensionality_XY, 
			m_fdoCoordinatesArray.GetSize(), m_fdoCoordinatesArray.GetData()); //创建线串

		linecollection->Add(FdoLine.p); //将线串加入集合中
		m_fdoCoordinatesArray.RemoveAll();
	}

	FdoMultiLine = m_pFdoGeoFactory->CreateMultiLineString(linecollection.p);
	m_pRetByteArray = m_pFdoGeoFactory->GetFgf(FdoMultiLine.p);
}

void SuperMapGeoToFgfGeo::CreateFdoPolygon()
{
	FdoPtr<FdoIPolygon> FdoPolygon;
	FdoPtr<FdoILinearRing> exteriorRing; //多边形外环
	FdoPtr<FdoILinearRing> innerRing; //多边形内环
	FdoPtr<FdoLinearRingCollection> interiorRings; //内环集合

	long m = 0;
	interiorRings = FdoLinearRingCollection::Create();//创建空集合

	for (int i = 0; i <  m_nSubCount; i++)
	{
		for (int j = 0; j < m_subPointsCount[i] ; j ++)
		{
			m_fdoCoordinatesArray.Add(m_points[m].x);
			m_fdoCoordinatesArray.Add(m_points[m].y);
			m++;
		}
		if(i == 0)//create the exteriorRing
		{
			exteriorRing = m_pFdoGeoFactory->CreateLinearRing(FdoDimensionality_XY, 
				m_fdoCoordinatesArray.GetSize(), m_fdoCoordinatesArray.GetData()); //创建外环
		}
		else
		{
			innerRing = m_pFdoGeoFactory->CreateLinearRing(FdoDimensionality_XY, 
				m_fdoCoordinatesArray.GetSize(), m_fdoCoordinatesArray.GetData()); //创建内环，并加入内环集合
			interiorRings->Add(innerRing.p);
		}
		m_fdoCoordinatesArray.RemoveAll();
	}
	FdoPolygon = m_pFdoGeoFactory->CreatePolygon(exteriorRing.p, interiorRings.p); //外环+内环集合
	m_pRetByteArray = m_pFdoGeoFactory->GetFgf(FdoPolygon.p);

	/*long m = 0;
	UGC::UGArray<UGC::UGbyte> ugByteArray;
	int nFdoGeoType = FdoGeometryType_Polygon;
	int nDimenType = FdoDimensionality_XY;
	int nSubCount = m_nSubCount;
	ugByteArray.Append((UGC::UGbyte*) &nFdoGeoType, sizeof(FdoInt32));
	ugByteArray.Append((UGC::UGbyte*) &nDimenType, sizeof(FdoInt32));
	ugByteArray.Append((UGC::UGbyte*) &nSubCount, sizeof(FdoInt32));
	for (int i = 0; i <  nSubCount; i++)
	{
		FdoInt32 nSubPtsCount = m_subPointsCount[i];
		ugByteArray.Append((UGC::UGbyte*) &nSubPtsCount, sizeof(FdoInt32));
		for (int j = 0; j < nSubPtsCount; j ++)
		{					
			m_fdoCoordinatesArray.Add(m_points[m].x);
			m_fdoCoordinatesArray.Add(m_points[m].y);
			m++;
		}
		int nBytesNum = sizeof(double) * m_fdoCoordinatesArray.GetSize();
		ugByteArray.Append((UGC::UGbyte*) m_fdoCoordinatesArray.GetData(), nBytesNum);
		m_fdoCoordinatesArray.RemoveAll();
	}
	m_pRetByteArray = FdoByteArray::Create(ugByteArray.GetData(), ugByteArray.GetSize());*/

}

void SuperMapGeoToFgfGeo::CreateFdoCompoundGeometry()
{
	static UGC::UGArray<UGC::UGPoint2D> points;
	static UGC::UGArray<UGC::UGint> nSubPointsCount;
	UGC::UGint nSubCount = 0;
	//多个组合对象都要调用该函数，而每一个几何对象的数据和另一个几何对象的数据都无关，因此先要清理掉上次结果
	points.RemoveAll();
	nSubPointsCount.RemoveAll();

	//目前仅支持相同类型的子对象组成的组合几何对象 
	if(!IsSameCompoundGeometry(m_pElemGeometry, true))
	{
		return;
	}
	int nGeoType = -1; //返回子对象的类型
	GetCompoundSpatialData(m_pElemGeometry, points, nSubPointsCount, nSubCount, nGeoType);	

	m_points.SetData(points.GetData(), false);
	m_subPointsCount.SetData(nSubPointsCount.GetData(), false);
	m_nSubCount = nSubCount;

	switch(nGeoType) 
	{
	case UGC::UGGeometry::GeoPoint:
	case UGC::UGGeometry::GeoText: 
	case UGC::UGGeometry::GeoMultiPoint:
		CreateFdoPoint();
		break;

	case UGC::UGGeometry::GeoLine:
	case UGC::UGGeometry::GeoArc:
	case UGC::UGGeometry::GeoCurve:
	case UGC::UGGeometry::GeoBSpline:
	case UGC::UGGeometry::GeoCardinal:
	case UGC::UGGeometry::GeoEllipticArc:
		CreateFdoMultiLine();
		break;

	case UGC::UGGeometry::GeoRect:
	case UGC::UGGeometry::GeoRectRound:
	case UGC::UGGeometry::GeoCircle:
	case UGC::UGGeometry::GeoEllipse:
	case UGC::UGGeometry::GeoRegion:
	case UGC::UGGeometry::GeoPie:
	case UGC::UGGeometry::GeoChord:
		CreateFdoPolygon();
		break;

	case UGC::UGGeometry::GeoLineM:
	case UGC::UGGeometry::GeoImageBlock:
	case UGC::UGGeometry::GeoIcon:
	case UGC::UGGeometry::GeoCompound:
	case UGC::UGGeometry::GeoEquilateral:
		break;

	default:
		break;

	}//switch
}

bool SuperMapGeoToFgfGeo::IsSameCompoundGeometry(UGC::UGGeometry *pCompoundGeometry, bool bFirstCall)
{
	if(NULL == pCompoundGeometry)
	{
		return false;
	}

	static int nGeoType;
	if( bFirstCall )//第一次调用，非递归调用
	{
		nGeoType = -1;
	}
	int nCompoundGeoSubNum = pCompoundGeometry->GetSubCount();
	UGC::UGGeometry * pGeometry = NULL;

	for(int i = 0; i < nCompoundGeoSubNum; i++)
	{
		//该几何对象还可能是一个复合对象，即为组合嵌套的关系
		pGeometry = ((UGC::UGGeoCompound *)pCompoundGeometry)->GetGeometry(i); 
		if(NULL == pGeometry)
		{
			return false;
		}

		if(UGC::UGGeometry::GeoCompound != pGeometry->GetType())//不为组合几何对象
		{
			if(-1 == nGeoType)
			{
				nGeoType = pGeometry->GetType();
			}
			else
			{
				if(pGeometry->GetType() != nGeoType)
				{
					return false;
				}
			}
		}
		else //如果用组合嵌套的情况
		{
			if( !IsSameCompoundGeometry(pGeometry, false) ) //递归调用
			{
				return false;
			}
		}
	}
	return true;
}

void SuperMapGeoToFgfGeo::GetCompoundSpatialData(UGC::UGGeometry *pCompoundGeometry, 
												 UGC::UGArray<UGC::UGPoint2D> &points, 
												 UGC::UGArray<UGC::UGint> &nSubPointsCount, 
												 UGC::UGint &nSubCount,
												 UGC::UGint &nGeoType)
{
	if(NULL == pCompoundGeometry)
	{
		return;
	}

	UGC::UGAutoPtr<UGC::UGPoint2D> AutoPoints; 
	UGC::UGAutoPtr<UGC::UGint> AutoSubPointsCount; 
	UGC::UGint AutoSubCount; 

	int nSubPointIndex = 0;
	int nCompoundGeoSubNum = pCompoundGeometry->GetSubCount();
	UGC::UGGeometry * pGeometry = NULL;

	for(int i = 0; i < nCompoundGeoSubNum; i++)
	{
		//该几何对象还可能是一个复合对象，即为组合嵌套的关系
		pGeometry = ((UGC::UGGeoCompound *)pCompoundGeometry)->GetGeometry(i); 
		if(NULL == pGeometry)
		{
			return;
		}
		nGeoType = pGeometry->GetType();
		//如果为简单几何对象的话，直接取坐标信息
		if(nGeoType != UGC::UGGeometry::GeoCompound)
		{
			pGeometry->GetSpatialData(AutoPoints, AutoSubPointsCount, AutoSubCount);
			nSubCount += AutoSubCount;
			for(int i = 0; i< AutoSubCount; i++)
			{
				nSubPointsCount.Add( AutoSubPointsCount[i] );
				for(int j = 0; j < AutoSubPointsCount[i]; j++)
				{
					points.Add( AutoPoints[nSubPointIndex] );
					nSubPointIndex++;
				}
			}
			nSubPointIndex = 0;
			AutoPoints.Release();
			AutoSubPointsCount.Release();
			AutoSubCount = 0;
		}
		else //如果有组合嵌套的情况
		{
			GetCompoundSpatialData(pGeometry, points, nSubPointsCount, nSubCount, nGeoType); //递归调用
		}
	}
}

FdoByteArray *SuperMapGeoToFgfGeo::GetGeometry()
{
	if(m_pRecordset)
	{
		switch(m_pRecordset->GetDataset()->GetType())
		{
			//目前仅支持点、线、面、文本和CAD数据集
		case UGC::UGDataset::Point:
		case UGC::UGDataset::Line:
		case UGC::UGDataset::Region:
		case UGC::UGDataset::CAD:
		case UGC::UGDataset::Text:
			CreateFdoGeo();
			break;

		case UGC::UGDataset::PointZ:
		case UGC::UGDataset::LineZ:
		case UGC::UGDataset::RegionZ:  
		case UGC::UGDataset::LineM:
		case UGC::UGDataset::DEM:
		case UGC::UGDataset::ECW:
		case UGC::UGDataset::Network:
		case UGC::UGDataset::Image:
			break;

		default:
			break;
		}
	}
	if(NULL == m_pRetByteArray)
	{
		return NULL;
	}
	else
	{
		return FDO_SAFE_ADDREF(m_pRetByteArray.p);
	}
}



