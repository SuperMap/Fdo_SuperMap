/** \file	 SuperMapFgfGeoToUGCGeo.cpp
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-12
*/

#include "SuperMap.h"

SuperMapFgfGeoToUGCGeo::SuperMapFgfGeoToUGCGeo(void)
{

}

SuperMapFgfGeoToUGCGeo::~SuperMapFgfGeoToUGCGeo(void)
{

}

//TODO::重构构造参数，可选ENUM类型的值，方便扩展

SuperMapFgfGeoToUGCGeo::SuperMapFgfGeoToUGCGeo
	(FdoByteArray *byteArray, 
	 bool IsTextDataset, 
	 UGC::UGString strText,
	 double textSize, 
	 bool IsCADDataset, 
	 bool IsSpatialCondition) // added by zhoux
{
	m_FgfArray = byteArray;
	m_pUGGeometry = NULL;
	m_IsPointOfTextDataset = IsTextDataset;
	m_strText = strText;
	m_dTextSize = textSize;
	m_IsCADDataset = IsCADDataset;
	m_IsSpatialCondition = IsSpatialCondition;
}

void SuperMapFgfGeoToUGCGeo::CreateUGCPoint(const int *pFgfArray, bool bMultiPoint)
{
	if(NULL == pFgfArray)
	{
		return;
	}

	int nPointNum = 1; // 点数，多点的情况下不为1
	if(bMultiPoint) // 处理多点
	{
		nPointNum = *(pFgfArray++); //点数
		pFgfArray++; //类型
	}
	int nDimenType = *(pFgfArray++); //Dimensionality
	double *pUGCGeoArray = (double*)pFgfArray; //指向起始坐标

	switch(nDimenType)
	{
	case FdoDimensionality_XY: //XY
		CreateUGC_XYPoint(nPointNum, pUGCGeoArray, bMultiPoint);
		break;

	case FdoDimensionality_Z: //XYZ
		CreateUGC_XYZPoint(nPointNum, pUGCGeoArray, bMultiPoint);
		break;

	case FdoDimensionality_M: //XYM
		break;
	case FdoDimensionality_Z | FdoDimensionality_M: //XYZM
		break;
	default:
		break;
	}
}

void SuperMapFgfGeoToUGCGeo::CreateUGC_XYPoint(int nPointNum, double *pUGCGeoArray, bool bMultiPoint)
{

	if(NULL == pUGCGeoArray)
	{
		return;
	}

	UGC::UGArray<UGC::UGPoint2D> UGCPointsArray;
	for(int pointcount = 1; pointcount <= nPointNum; pointcount++)
	{
		UGC::UGPoint2D point;
		point.x = *(pUGCGeoArray++);
		point.y = *(pUGCGeoArray++);
		pUGCGeoArray++; //注意，虽然，FDO维度是二维，但是数组里有Z值，且为0!!! 太奇怪了!!!
		UGCPointsArray.Add(point);
	}

	if(bMultiPoint)
	{
		//m_pUGGeometry = new UGC::UGGeoMultiPoint(); //创建UGC多点
		m_pUGGeometry = new UGC::UGGeoCompound(); //创建UGC多点,使用复合对象的方式，否则不能编辑该多点对象
	}
	else
	{
		m_pUGGeometry = new UGC::UGGeoPoint(); //创建UGC点
	}

	if(m_pUGGeometry)
	{
		UGC::UGbool bCreateRet;
		if(bMultiPoint)
		{
			//bCreateRet = ((UGC::UGGeoMultiPoint *)m_pUGGeometry)->Make(UGCPointsArray.GetData(), nPointNum);
			UGC::UGGeoPoint *pPointGeometry = NULL;	
			for(int pointcount = 1; pointcount <= nPointNum; pointcount++)
			{
				pPointGeometry = new UGC::UGGeoPoint(); 
				bCreateRet = pPointGeometry->Make(UGCPointsArray.GetAt(pointcount - 1));
				if(!bCreateRet)
				{
					delete pPointGeometry;
					pPointGeometry = NULL;
					break;
				}
				((UGC::UGGeoCompound *)m_pUGGeometry)->AddCompound(pPointGeometry);
			}
		}
		else
		{
			bCreateRet = ((UGC::UGGeoPoint *)m_pUGGeometry)->Make(UGCPointsArray.GetAt(0));
		}

		if(!bCreateRet) 
		{
			delete m_pUGGeometry;
			m_pUGGeometry = NULL;
		}
	}
}

// 该函数目前和CreateUGC_XYPoint()函数相同
void SuperMapFgfGeoToUGCGeo::CreateUGC_XYZPoint(int nPointNum, double *pUGCGeoArray, bool bMultiPoint)
{
	CreateUGC_XYPoint(nPointNum, pUGCGeoArray, bMultiPoint);
}

void SuperMapFgfGeoToUGCGeo::CreateUGCLine(const int *pFgfArray, bool bMultiLine)
{
	if(NULL == pFgfArray)
	{
		return;
	}

	int nLineNum = 1; //线数，多线的情况值不为1
	if(bMultiLine) // 处理多线
	{
		nLineNum = *(pFgfArray++); //线数
		pFgfArray++; //线类型
	}
	int nDimenType = *(pFgfArray++); //维数
	int nPointsNum = *(pFgfArray++); //点数
	double *pUGCGeoArray = (double*)pFgfArray; //指向起始坐标

	switch(nDimenType)
	{
	case FdoDimensionality_XY: //XY		
		CreateUGC_XYLine(nLineNum, nPointsNum, pUGCGeoArray);
		break;

	case FdoDimensionality_Z: //XYZ
		CreateUGC_XYZLine(nLineNum, nPointsNum, pUGCGeoArray);
		break;

	case FdoDimensionality_M: //XYM
		break;
	case FdoDimensionality_Z | FdoDimensionality_M: //XYZM
		break;
	default:
		break;
	}
}

void SuperMapFgfGeoToUGCGeo::CreateUGC_XYLine(int nLineNum, int nPointsNum, double *pUGCGeoArray)
{
	if(NULL == pUGCGeoArray)
		return;

	UGC::UGArray<int> nSubPointsNum;
	UGC::UGArray<UGC::UGPoint2D> UGCPointsArray;

	for(int linecount = 1; linecount <= nLineNum; linecount++) //线数
	{
		nSubPointsNum.Add(nPointsNum);
		for(int ptindex = 1; ptindex <= nPointsNum; ptindex++) //每一条线的点数
		{
			UGC::UGPoint2D point;
			point.x = *(pUGCGeoArray++);
			point.y = *(pUGCGeoArray++);
			UGCPointsArray.Add(point);
		}
		int *pNextLine = (int *)pUGCGeoArray; //下一条线的类型
		pNextLine++; //下一条线的维数
		pNextLine++; //下一条线的点数
		nPointsNum = *(pNextLine++);
		pUGCGeoArray = (double *)pNextLine;
	}
	m_pUGGeometry = new UGC::UGGeoLine(); //创建UGC线对象
	if(m_pUGGeometry)
	{
		UGC::UGbool bCreateRet = ((UGC::UGGeoLine *)m_pUGGeometry)->Make(UGCPointsArray.GetData(), nSubPointsNum.GetData(), nLineNum);
		if(!bCreateRet) 
		{
			delete m_pUGGeometry;
			m_pUGGeometry = NULL;
		}
	}
}

//目前用于空间查询，仅忽略第三维，以后可以扩展
void SuperMapFgfGeoToUGCGeo::CreateUGC_XYZLine(int nLineNum, int nPointsNum, double *pUGCGeoArray)
{
	UGC::UGArray<int> nSubPointsNum;
	UGC::UGArray<UGC::UGPoint2D> UGCPointsArray;

	for(int linecount = 1; linecount <= nLineNum; linecount++) //线数
	{
		nSubPointsNum.Add(nPointsNum);
		for(int ptindex = 1; ptindex <= nPointsNum; ptindex++) //每条线点数
		{
			UGC::UGPoint2D point;
			point.x = *(pUGCGeoArray++);
			point.y = *(pUGCGeoArray++);
			pUGCGeoArray++; //目前只忽略第三维
			UGCPointsArray.Add(point);
		}
		int *pNextLine = (int *)pUGCGeoArray; //下一条线类型
		pNextLine++; //下一条线维度
		pNextLine++; //下一条线点数
		nPointsNum = *(pNextLine++);
		pUGCGeoArray = (double *)pNextLine;
	}
	m_pUGGeometry = new UGC::UGGeoLine(); //创建UGC线对象
	if(m_pUGGeometry)
	{
		UGC::UGbool bCreateRet = ((UGC::UGGeoLine *)m_pUGGeometry)->Make(UGCPointsArray.GetData(), nSubPointsNum.GetData(), nLineNum);
		if(!bCreateRet) 
		{
			delete m_pUGGeometry;
			m_pUGGeometry = NULL;
		}
	}
}

void SuperMapFgfGeoToUGCGeo::CreateUGCRegion(const int *pFgfArray, bool bMultiPolygon)
{
	if(NULL == pFgfArray)
	{
		return;
	}
	int nPolygonNum = 1;
	if(bMultiPolygon)
	{
		nPolygonNum = *(pFgfArray++); //多边形数
		pFgfArray++; //多边形类型
	}

	int nDimenType = *(pFgfArray++); //维度
	int nRingNum = *(pFgfArray++); //环数
	int nRingPtsNum = *(pFgfArray++); //第一个环的点数
	double *pUGCGeoArray = (double*)pFgfArray; //指向第一个环的起始坐标

	switch(nDimenType)
	{
	case FdoDimensionality_XY: //XY		
		CreateUGC_XYRegion(nPolygonNum, nRingNum, nRingPtsNum, pUGCGeoArray);
		break;

	case FdoDimensionality_Z: //XYZ 
		CreateUGC_XYZRegion(nPolygonNum, nRingNum, nRingPtsNum, pUGCGeoArray);
		break;

	case FdoDimensionality_M: //XYM
		break;
	case FdoDimensionality_Z | FdoDimensionality_M: //XYZM
		break;
	default:
		break;
	}
}

void SuperMapFgfGeoToUGCGeo::CreateUGC_XYRegion(int nPolygonNum, int nRingNum, int nRingPtsNum, double *pUGCGeoArray)
{
	if(NULL == pUGCGeoArray)
	{
		return;
	}

	UGC::UGArray<UGC::UGPoint2D> UGCPointsArray;
	for(int polygoncount = 1; polygoncount <= nPolygonNum; polygoncount++) //多边形数
	{
		for(int ring = 1; ring <= nRingNum; ring++) //环数
		{
			for(int ptindex = 1; ptindex <= nRingPtsNum; ptindex++) //每个环的点数
			{
				UGC::UGPoint2D point;
				point.x = *(pUGCGeoArray++);
				point.y = *(pUGCGeoArray++);
				UGCPointsArray.Add(point);
			}

			if(NULL == m_pUGGeometry) //还没有创建几何对象
			{
				m_pUGGeometry = new UGC::UGGeoRegion(); //创建几何对象
				if(m_pUGGeometry)
				{
					UGC::UGbool bCreateRet = ((UGC::UGGeoRegion *)m_pUGGeometry)->Make(UGCPointsArray.GetData(), nRingPtsNum);
					if(!bCreateRet) 
					{
						delete m_pUGGeometry;
						m_pUGGeometry = NULL;
					}
				}
			}
			else //如果已经创建了几何对象，仅添加子对象
			{
				UGC::UGbool bAddRet = ((UGC::UGGeoRegion *)m_pUGGeometry)->AddSub(UGCPointsArray.GetData(), nRingPtsNum);
				if(!bAddRet) 
				{
					delete m_pUGGeometry;
					m_pUGGeometry = NULL;
				}

			}
			if(ring < nRingNum)
			{
				int *pNextRingPtsNum = (int *)pUGCGeoArray;
				nRingPtsNum = *(pNextRingPtsNum++);
				pUGCGeoArray = (double *)pNextRingPtsNum;
			}
			UGCPointsArray.RemoveAll();
		}
		int *pNextPolygonType = (int *)pUGCGeoArray; //下一个多边形类型
		pNextPolygonType++; //下一个多边形维数
		pNextPolygonType++; //下一个多边形环数
		nRingNum = *(pNextPolygonType++); //下一个多边形的环数
		nRingPtsNum = *(pNextPolygonType++); //下一个多边形第一个环的点数
		pUGCGeoArray = (double *)pNextPolygonType; 
	}
}


////目前用于空间查询，仅忽略第三维，以后可以扩展
void SuperMapFgfGeoToUGCGeo::CreateUGC_XYZRegion(int nPolygonNum, int nRingNum, int nRingPtsNum, double *pUGCGeoArray)
{
	UGC::UGArray<UGC::UGPoint2D> UGCPointsArray;
	for(int polygoncount = 1; polygoncount <= nPolygonNum; polygoncount++) //多边形个数
	{
		for(int ring = 1; ring <= nRingNum; ring++) //多边形环数
		{
			for(int ptindex = 1; ptindex <= nRingPtsNum; ptindex++) //每个环的点数
			{
				UGC::UGPoint2D point;
				point.x = *(pUGCGeoArray++);
				point.y = *(pUGCGeoArray++);
				pUGCGeoArray++; //仅忽略第三维
				UGCPointsArray.Add(point);
			}
			if(NULL == m_pUGGeometry) //还没有创建几何对象
			{
				m_pUGGeometry = new UGC::UGGeoRegion(); //创建几何对象
				if(m_pUGGeometry)
				{
					UGC::UGbool bCreateRet = ((UGC::UGGeoRegion *)m_pUGGeometry)->Make(UGCPointsArray.GetData(), nRingPtsNum);
					if(!bCreateRet) 
					{
						delete m_pUGGeometry;
						m_pUGGeometry = NULL;
					}
				}
			}
			else //如果已经创建了几何对象，仅添加子对象
			{
				UGC::UGbool bAddRet = ((UGC::UGGeoRegion *)m_pUGGeometry)->AddSub(UGCPointsArray.GetData(), nRingPtsNum);
				if(!bAddRet) 
				{
					delete m_pUGGeometry;
					m_pUGGeometry = NULL;
				}

			}
			if(ring < nRingNum)
			{
				int *pNextRingPtsNum = (int *)pUGCGeoArray;
				nRingPtsNum = *(pNextRingPtsNum++);
				pUGCGeoArray = (double *)pNextRingPtsNum;
			}
			UGCPointsArray.RemoveAll();
		}
		int *pNextPolygonType = (int *)pUGCGeoArray; //下一个多边形类型
		pNextPolygonType++; //下一个多边形维数
		pNextPolygonType++; 
		nRingNum = *(pNextPolygonType++); //下一个多边形环数
		nRingPtsNum = *(pNextPolygonType++); //下一个多边形第一个环的点数
		pUGCGeoArray = (double *)pNextPolygonType; 
	}
}

void SuperMapFgfGeoToUGCGeo::CreateUGCText(const int *pFgfArray)   // added by zhoux
{
	if(NULL == pFgfArray)
	{
		return;
	}
	int nDimenType = *(pFgfArray++); //维数
	double *pUGCGeoArray = (double*)pFgfArray; //起始坐标
	switch(nDimenType)
	{
	case FdoDimensionality_XY: //实际上文本数据集的定位点肯定是二维          
		m_pUGGeometry = new UGC::UGGeoText(); 
		if(m_pUGGeometry)
		{
			UGC::UGPoint2D pointxy;
			pointxy.x = *pUGCGeoArray;
			pUGCGeoArray++;
			pointxy.y = *pUGCGeoArray;
			UGC::UGbool bCreateRet = ((UGC::UGGeoText *)m_pUGGeometry)->Make(m_strText,pointxy);
			UGC::UGTextStyle textStyle;
			textStyle.SetHeight(m_dTextSize);
			((UGC::UGGeoText *)m_pUGGeometry)->SetTextStyle(textStyle);
			if(!bCreateRet) //execute Make not successfully
			{
				TRACE(_T("SuperMapFgfGeoToUGCGeo::文本创建失败!... \n"));
				delete m_pUGGeometry;
				m_pUGGeometry = NULL;
			}
		}
		break;

	case FdoDimensionality_Z: //XYZ
		break;

	case FdoDimensionality_M: //XYM
		break;

	case FdoDimensionality_Z | FdoDimensionality_M: //XYZM
		break;
	default:
		break;
	}

}

UGC::UGGeometry *SuperMapFgfGeoToUGCGeo::GetGeometry()
{
	int *pGeoArray = (int*)m_FgfArray->GetData();
	int nFgfGeoType = *(pGeoArray++);
	switch(nFgfGeoType)
	{
	case FdoGeometryType_Point: //fgf point
		{
			if(m_IsPointOfTextDataset)              // modified by zhouxu
			{
				CreateUGCText(pGeoArray);
			}
			else
			{
				CreateUGCPoint(pGeoArray, false);
			}
			break;
		}
	case FdoGeometryType_MultiPoint: //fgf multipoint
		{
			if(m_IsCADDataset || m_IsSpatialCondition)
			{
				CreateUGCPoint(pGeoArray, true);
			}
			else
			{
				throw FdoException::Create (NlsMsgGet (SUPERMAP_POINT_FEATURE_SOURCE_NOT_SUPPORT_MULTIPOINT, "Multipoint is not supported."));
			}
			break;
		}
	case FdoGeometryType_LineString: //fgf line
		CreateUGCLine(pGeoArray, false);
		break;

	case FdoGeometryType_MultiLineString: //fgf multiline
		CreateUGCLine(pGeoArray, true);
		break;

	case FdoGeometryType_Polygon: //fgf polygon
		CreateUGCRegion(pGeoArray, false);
		break;

	case FdoGeometryType_MultiPolygon: //fgf multipolygon
		CreateUGCRegion(pGeoArray, true);
		break;

	case FdoGeometryType_MultiGeometry: //fgf multigeometry
		break;

	case FdoGeometryType_CurveString: //fgf curve
		break;

	case FdoGeometryType_CurvePolygon: //fgf curve polygon
		break;

	case FdoGeometryType_MultiCurveString: //fgf multi curve
		break;

	case FdoGeometryType_MultiCurvePolygon: //fgf multi curve polygon
		break;

	default:
		break;
	}
	return m_pUGGeometry;
}