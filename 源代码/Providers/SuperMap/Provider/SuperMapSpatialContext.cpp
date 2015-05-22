/** \file	 SuperMapSpatialContext.cpp
*  \brief    该类主要负责存储SuperMap物理数据源的空间语义信息
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-14
*/

#include "SuperMap.h"

SuperMapSpatialContext::SuperMapSpatialContext() 
:
	m_Name(SPATIALCONTEXT_DEFAULT_NAME),
	m_Description(L""),
	m_CoordSysName(SPATIALCONTEXT_CSYS_DEFAULT_NAME),
	m_Wkt(SPATIALCONTEXT_CSYS_DEFAULT_WKT),
	m_ExtentType(FdoSpatialContextExtentType_Static),
	m_XYTolerance(SPATIALCONTEXT_DEFAULT_XY_TOLERANCE),
	m_ZTolerance(SPATIALCONTEXT_DEFAULT_Z_TOLERANCE),
	/// added 2007-11-23
	m_ProjectName(L""),
	m_DatumName(L""),
	m_SpheroidName(L""),
	m_PrimeMeridian(L""),
	m_Unit(L"")
{
	// added for 初始化成员变量
	m_dSemiMajor = 0.0;
	m_dInvflattening = 0.0;
	m_dFalseEasting = 0.0;
	m_dFalseNorthing = 0.0;
	m_dCentralMeridian = 0.0;
	m_dCentralParallel = 0.0;
	m_dStandardParallel1 = 0.0;
	m_dStandardParallel2 = 0.0;
	m_dScaleFactor = 0.0;
	m_dAzimuth = 0.0;
	m_dFirstPointLongitude = 0.0;
	m_dSecondPointLongitude = 0.0;
	m_eType = UGC::SPATIALREF_NONEARTH; // 初始化为没有地理参照的坐标系 SPATIALREF_NONEARTH

	FdoPtr<FdoFgfGeometryFactory> factory = FdoFgfGeometryFactory::GetInstance();
	FdoPtr<FdoIEnvelope> envelope = factory->CreateEnvelopeXY(
		SPATIALCONTEXT_DEFAULT_MINX,
		SPATIALCONTEXT_DEFAULT_MINY,
		SPATIALCONTEXT_DEFAULT_MAXX,
		SPATIALCONTEXT_DEFAULT_MAXY);
	FdoPtr<FdoIGeometry> geometry = factory->CreateGeometry(envelope);
	m_Extent = factory->GetFgf(geometry);
}

SuperMapSpatialContext::~SuperMapSpatialContext()
{
}

FdoString* SuperMapSpatialContext::GetName()
{
	return m_Name;
}

void SuperMapSpatialContext::SetName(FdoString *name)
{
	m_Name = name;
}

FdoString* SuperMapSpatialContext::GetDescription()
{
	return m_Description;
}

void SuperMapSpatialContext::SetDescription(FdoString *desc)
{
	m_Description = desc;
}

FdoString* SuperMapSpatialContext::GetCoordSysName()
{
	// 如果不是经纬度和投影坐标系类型就返回空
	if (m_eType != UGC::SPATIALREF_EARTH_LONGITUDE_LATITUDE 
		&& m_eType != UGC::SPATIALREF_EARTH_PROJECTION)   // 支持经纬度坐标,投影坐标的WKT格式返回
	{
		return L"";
	}
	else
	{
		return m_CoordSysName;
	}
		
}

void SuperMapSpatialContext::SetCoordSysName(FdoString *csName)
{
	m_CoordSysName = csName;
}

FdoString* SuperMapSpatialContext::GetCoordinateSystemWkt()
{
	//TODO::代码再次优化

// WKT范例：
// 1.经纬度坐标：L"GEOGCS[\"GCS_WGS_1984\",DATUM[\"D_WGS_1984\",SPHEROID[\"WGS_1984\",6378137,298.257223563]],PRIMEM[\"Greenwich\",0],UNIT[\"Degree\",0.0174532925199433]]";
// 2.投影坐标：  L"PROJCS[UTM 17 (WGS84) in Northern hemisphere,GEOGCS[WGS 84,DATUM[WGS_1984,SPHEROID[WGS_1984,6378137,298.257223563]],PRIMEM[Greenwich,0],UNIT[DMSH,0.0174532925199433]],PROJECTION[Transverse_Mercator],PARAMETER[latitude_of_origin,0],PARAMETER[central_meridian,-81],PARAMETER[scale_factor,0.9996],PARAMETER[false_easting,500000],PARAMETER[false_northing,0]]"
	
	if (m_eType != UGC::SPATIALREF_EARTH_LONGITUDE_LATITUDE 
		&& m_eType != UGC::SPATIALREF_EARTH_PROJECTION)   // 支持经纬度坐标,投影坐标的WKT格式返回
		return L"";
	if(m_Wkt == SPATIALCONTEXT_CSYS_DEFAULT_WKT)
	{
		//如果是西安80坐标系需调整椭球体参数才能识别 !!! 
		if(0 == wcscmp(m_CoordSysName, L"GCS_XiAn_1980"))
		{
			m_SpheroidName = L"Xian_1980";
			m_dSemiMajor = 6378140.0;
			m_dInvflattening = 298.257;
		}

		FdoStringP str1 = L"GEOGCS";
		FdoStringP str2 = L"DATUM";
		FdoStringP str3 = L"SPHEROID";
		FdoStringP str4 = L"PRIMEM";
		FdoStringP str5 = L"UNIT";
		FdoStringP str6 = L"[";
		FdoStringP str7 = L"]";
		FdoStringP str8 = L",";
		FdoStringP str9,str10;
		FdoStringP str11 = L"0";
		str9 = str9.Format(L"%f", m_dSemiMajor);
		str10 = str10.Format(L"%f", m_dInvflattening);

		//由于关键字要加引号
		FdoStringP yinhao = L"\"";

		//两种投影的公共WKT串
		FdoStringP tmpWkt;
		tmpWkt = str1 + str6 + yinhao + m_CoordSysName + yinhao + str8 + str2 + str6 + yinhao + m_DatumName + yinhao
			    + str8 + str3 + str6 + yinhao + m_SpheroidName + yinhao + str8 + str9 + str8 + str10 + str7 + str7 
				+ str8 + str4 + str6 + yinhao + m_PrimeMeridian + yinhao + str8 + str11 + str7 + str8 + str5 + str6 
				+ yinhao + m_GeoUnit + yinhao + str8 + m_GeoUnitFactor + str7 + str7;
		
		if(m_eType == UGC::SPATIALREF_EARTH_LONGITUDE_LATITUDE) // 如果数据源坐标系是经纬度坐标系
		{	
			m_Wkt = tmpWkt;
		}
		else if(m_eType == UGC::SPATIALREF_EARTH_PROJECTION) // 如果数据源坐标系是投影坐标系
		{
			FdoStringP str13 = L"PROJCS";
		    FdoStringP str14 = L"PARAMETER";
		    //投影参数
			FdoStringP str15,str16,str17,str18,str19,str20,str21,str22,str23,str24;
			str15 = str15.Format(L"%f", m_dFalseEasting);
			str16 = str16.Format(L"%f", m_dFalseNorthing);
			str17 = str17.Format(L"%f", m_dCentralMeridian);
			str18 = str18.Format(L"%f", m_dCentralParallel);
			str19 = str19.Format(L"%f", m_dStandardParallel1);
			str20 = str20.Format(L"%f", m_dStandardParallel2);
			str21 = str21.Format(L"%f", m_dScaleFactor);
			str22 = str22.Format(L"%f", m_dAzimuth);
			str23 = str23.Format(L"%f", m_dFirstPointLongitude);
			str24 = str24.Format(L"%f", m_dSecondPointLongitude);
			FdoStringP str25 = L"\"False_Easting\"";
			FdoStringP str26 = L"\"False_Northing\"";
			FdoStringP str27 = L"\"Central_Meridian\"";
			FdoStringP str28 = L"\"Latitude_Of_Origin\"";  //L"\"central_parallel\"";
			FdoStringP str29 = L"\"Standard_Parallel_1\""; //L"\"Standard_Parallel1\"";  
			FdoStringP str30 = L"\"Standard_Parallel_2\""; // L"\"Standard_Parallel2\"";  
			FdoStringP str31 = L"\"Scale_Factor\"";
			FdoStringP str32 = L"\"Azimuth\"";
			FdoStringP str33 = L"\"Latitude_Of_1st_Point\"";   //L"\"First_Point_Longitude\"";   
			FdoStringP str34 = L"\"Latitude_Of_2nd_Point\"";   //L"\"Second_Point_Longitude\""; 

			FdoStringP str35 = L"PROJECTION";
			
			//构造投影参数WKT串
			FdoStringP prjParams;
			prjParams = str14 + str6 + str25 + str8 + str15 + str7 + str8
				      + str14 + str6 + str26 + str8 + str16 + str7 + str8
					  + str14 + str6 + str27 + str8 + str17 + str7 + str8
					  + str14 + str6 + str28 + str8 + str18 + str7 + str8
					  + str14 + str6 + str29 + str8 + str19 + str7 + str8
					  + str14 + str6 + str30 + str8 + str20 + str7 + str8
					  + str14 + str6 + str31 + str8 + str21 + str7 + str8
					  + str14 + str6 + str32 + str8 + str22 + str7 + str8 
					  + str14 + str6 + str33 + str8 + str23 + str7 + str8
					  + str14 + str6 + str34 + str8 + str24 + str7 ;
			m_Wkt = str13 + str6 + yinhao + m_Name + yinhao + str8 + tmpWkt + str8 + str35 + str6 + yinhao 
				  + m_ProjectName + yinhao + str7 + str8  + prjParams 
				  + str8 + str5 + str6 + yinhao + m_Unit + yinhao + str8 + m_UnitFactor + str7 + str7;
		}	
	}
	TRACE(_T("WKT名称 ： [%ls]。\n"), m_Wkt);
	return m_Wkt;
}

void SuperMapSpatialContext::SetCoordinateSystemWkt(FdoString *wkt)
{
	m_Wkt = wkt;
}

FdoSpatialContextExtentType SuperMapSpatialContext::GetExtentType ()
{
	return m_ExtentType;
}

void SuperMapSpatialContext::SetExtentType (FdoSpatialContextExtentType type)
{
    m_ExtentType = type;
}

FdoByteArray* SuperMapSpatialContext::GetExtent ()
{
    return FDO_SAFE_ADDREF(m_Extent.p);
}

void SuperMapSpatialContext::SetExtent (FdoByteArray * extent)
{
    FDO_SAFE_ADDREF(extent);
    m_Extent = extent;
}

double SuperMapSpatialContext::GetXYTolerance ()
{
    return (m_XYTolerance);
}

void SuperMapSpatialContext::SetXYTolerance (double tol)
{
    m_XYTolerance = tol;
}

double SuperMapSpatialContext::GetZTolerance ()
{
    return (m_ZTolerance);
}

void SuperMapSpatialContext::SetZTolerance (double tol)
{
    m_ZTolerance = tol;
}




