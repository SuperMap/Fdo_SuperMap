/** \file	 SuperMapSpatialContext.h
*  \brief    该类主要负责存储SuperMap物理数据源的空间语义信息
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-14
*/

#ifndef __SUPERMAP_SPATIAL_CONTEXT_H__
#define __SUPERMAP_SPATIAL_CONTEXT_H__

#ifdef _WIN32
#pragma once
#endif

class SuperMapSpatialContext : public FdoDisposable
{

public:
	SuperMapSpatialContext();
	virtual ~SuperMapSpatialContext();

	virtual FdoString* GetName();
	virtual void SetName(FdoString* Name);
	virtual FdoString* GetDescription();
	virtual void SetDescription(FdoString* desc);
	virtual FdoString* GetCoordSysName();
	virtual void SetCoordSysName(FdoString* csName);
	virtual FdoString* GetCoordinateSystemWkt ();
    virtual void SetCoordinateSystemWkt (FdoString* wkt);
	virtual FdoSpatialContextExtentType GetExtentType ();
    virtual void SetExtentType (FdoSpatialContextExtentType type);
	 virtual FdoByteArray* GetExtent ();
    virtual void SetExtent (FdoByteArray* extent);
    virtual double GetXYTolerance ();
    virtual void SetXYTolerance (double tol);
    virtual double GetZTolerance ();
    virtual void SetZTolerance (double tol);

	// To please FdoNamedCollection:
    virtual FdoBoolean CanSetName() { return true; }

private:
	FdoStringP m_Name;             // 存空间语义名
    FdoStringP m_Description;      // 存空间语义描述
    FdoStringP m_CoordSysName;     // 存坐标系名称
    FdoStringP m_Wkt;              // 以WKT方式表示空间语义信息，在第一次调用GetCoordinateSystemWkt时进行初始化

    FdoSpatialContextExtentType m_ExtentType;
    FdoPtr<FdoByteArray> m_Extent;

	double m_XYTolerance;
    double m_ZTolerance;

	/// 必要的空间语义信息（用于输出WKT文本时也需提前设置,共有成员，仅供内部使用）
public:
	FdoStringP m_ProjectName;      //  投影名称
	FdoStringP m_DatumName;        //  基准面名 DATUM
	FdoStringP m_SpheroidName;     //  椭球体名
	double m_dSemiMajor;           //  椭球体长半轴长度
	double m_dInvflattening;       //  椭球体扁率倒数 
	FdoStringP m_PrimeMeridian;    //  本处子午线（0度经线）通常为"Greenwich"
	FdoStringP m_GeoUnit;          //  单位	
	FdoStringP m_GeoUnitFactor;    //  角度单位为到弧度的换算系数，1度 = 0.0174532925199433 弧度。
	FdoStringP m_Unit;
	FdoStringP m_UnitFactor;       //  长度单位为到米的换算系数， 1cm = 0.01m。
	                             

	// 投影参数
	double m_dFalseEasting;			//  0 False easting (X0)
	double m_dFalseNorthing;		//  1 False northing (Y0)
	double m_dCentralMeridian;		//  2 Central meridian, Longitude of origin (LON0)
	double m_dCentralParallel;		//  6 Central parallel, Latitude of origin	(LAT0)

	double m_dStandardParallel1;	//  3 Standard parallel 1, Latitude of 1st point (LAT1)
	double m_dStandardParallel2;	//  4 Standard parallel 2, Latitude of 2nd point (LAT2)

	double m_dScaleFactor;			//  5 Scale factor
	double m_dAzimuth;				//  7 Azimuth

	double m_dFirstPointLongitude;		//  8 Longitude of 1st point (LON1)
	double m_dSecondPointLongitude;		//  9 Longitude of 2nd point  (LON2)

	UGC::EmSpatialRefType m_eType;
};


class SuperMapSpatialContextCollection : public FdoNamedCollection<SuperMapSpatialContext, FdoException>
{
public:
	SuperMapSpatialContextCollection(void){}
	
protected:
	virtual ~SuperMapSpatialContextCollection(void){}

	virtual void Dispose()
	{
		delete this;
	}
};


#endif //__SUPERMAP_SPATIAL_CONTEXT_H__