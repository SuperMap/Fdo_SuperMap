/** \file	 SuperMapSpatialContextReader.h
*  \brief    该类用来实现空间语义读取接口：FdoISpatialContextReader
*  \author	 周 旭
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2007-11-14
*/

#ifndef __SUPERMAP_SPATIAL_CONTEXT_READER_H__
#define __SUPERMAP_SPATIAL_CONTEXT_READER_H__

#ifdef _WIN32
#pragma once
#endif

class SuperMapSpatialContextReader:
	public FdoISpatialContextReader
{
public:
	SuperMapSpatialContextReader(SuperMapSpatialContextCollection* spatialContextColl);
	virtual ~SuperMapSpatialContextReader();
	
	// FdoIDisposable 接口实现
	virtual void Dispose();

	// FdoISpatialContextReader 接口实现
	
    /// <summary>Gets the name of the spatial context currently being read.</summary>
    /// <returns>Returns the name of the spatial context.</returns> 
    virtual FdoString* GetName ();

    /// <summary>Gets the description of the spatial context currently being read.</summary>
    /// <returns>Returns the description of the spatial context.</returns> 
    virtual FdoString* GetDescription ();

    /// <summary>Gets the name of the coordinate system of the spatial context currently
    /// being read. If the result is a null or empty string, the coordinate system is
    /// unknown to the spatial context.</summary>
    /// <returns>Returns the coordinate system name of the spatial context.</returns> 
    virtual FdoString* GetCoordinateSystem ();

    /// <summary>Gets the name of the coordinate system in OpenGIS SRS WKT format of the spatial context currently
    /// being read. If the result is an empty string, the coordinate system WKT description is
    /// not available.</summary>
    /// <returns>Returns the coordinate system description in WKT of of the spatial context.</returns> 
    virtual FdoString* GetCoordinateSystemWkt ();

    /// <summary>Gets the extent type of the spatial context currently being read.</summary>
    /// <returns>Returns the extent type.</returns> 
    virtual FdoSpatialContextExtentType GetExtentType ();

    /// <summary>Gets the extent of the spatial context currently being read as a byte
    /// array in FGF format.</summary>
    /// <param name="length">Output the length of the returned byte array.</param> 
    /// <returns>Returns the extent as a byte array in FGF format.</returns> 
    virtual FdoByteArray* GetExtent ();

    /// <summary>Gets the tolerance value for XY ordinates of the spatial context
    /// currently being read. Tolerances are used in some geometric tests,
    /// mostly for equality between coordinates.  This occurs frequently in spatial
    /// queries, especially with "on boundary" or "just touching" conditions.
    /// It is also an objective amount that can be used when formulating step
    /// distances for parametric curve interpolation.</summary>
    /// <returns>Returns the tolerance</returns>
    virtual const double GetXYTolerance ();

    /// <summary>Gets the tolerance value for Z ordinates of the spatial context
    /// currently being read. Tolerances are used in some geometric tests,
    /// mostly for equality between coordinates.  This occurs a frequently in spatial
    /// queries, especially with "on boundary" or "just touching" conditions.
    /// It is also an objective amount that can be used when formulating step
    /// distances for parametric curve interpolation.</summary>
    /// <returns>Returns the tolerance</returns>
    virtual const double GetZTolerance ();

    /// <summary>Returns true if the spatial context currently being read is the active
    /// spatial context.</summary>
    /// <returns>Returns true if the current spatial context is the active one.</returns> 
    virtual const bool IsActive ();

    /// <summary>Advances the reader to the next item. The default position of the reader
    /// is prior to the first item. Thus, you must call ReadNext to begin
    /// accessing any data.</summary>
    /// <returns>Returns true if there is a next item.</returns> 
    virtual bool ReadNext ();

protected:
    void validate ();

protected:
	FdoPtr<SuperMapSpatialContextCollection> m_spatialContextColl;
	FdoPtr<SuperMapSpatialContext> m_context;
	int m_curIndex;
};

#endif // __SUPERMAP_SPATIAL_CONTEXT_READER_H__

/*  demo阶段参考代码
/// 为了测试方便，暂时在此处实现FDOISpatialContextReader
class SuperMapSpatialContextReader :
    public FdoISpatialContextReader
{

protected:
	
	ShpSpatialContextCollectionP	mSpatialContextColl;
    ShpSpatialContextP				mContext; // the current read context
	int								mCurrIndex;
	
	FdoStringP mName;
    FdoStringP mDescription;
    FdoStringP mCoordSysName;
    FdoStringP mWkt;
    FdoSpatialContextExtentType mExtentType;
    FdoPtr<FdoByteArray> mExtent;
	bool				 mIsExtentUpdated;
	bool				 mIsFromConfigFile;
    double mXYTolerance;
    double mZTolerance;


public:
	SuperMapSpatialContextReader (){}
	virtual ~SuperMapSpatialContextReader (void){}

    //
    // FdoIDisposable interface
    //

    /// <summary>Closes the FdoISpatialContextReader object, freeing any resources it may
    /// be holding.</summary>
    /// <returns>Returns nothing</returns> 
	virtual void Dispose ()
	{
		TRACE(_T("调用 SuperMapSpatialContextReader::Dispose() 。\n"));
		delete this;
	}

    //
    // FdoISpatialContextReader interface
    //

    /// <summary>Gets the name of the spatial context currently being read.</summary>
    /// <returns>Returns the name of the spatial context.</returns> 
	virtual FdoString* GetName ()
	{ 
		TRACE(_T("调用 SuperMapSpatialContextReader::GetName():GCS_WGS_1984  。\n"));
		return L"GCS_WGS_1984" ; 
	}

    /// <summary>Gets the description of the spatial context currently being read.</summary>
    /// <returns>Returns the description of the spatial context.</returns> 
	virtual FdoString* GetDescription ()
	{
		TRACE(_T("调用 SuperMapSpatialContextReader::GetDescription():空间语义描述 。\n"));
		return L"GCS_WGS_1984";
	}

    /// <summary>Gets the name of the coordinate system of the spatial context currently
    /// being read. If the result is a null or empty string, the coordinate system is
    /// unknown to the spatial context.</summary>
    /// <returns>Returns the coordinate system name of the spatial context.</returns> 
	virtual FdoString* GetCoordinateSystem ()
	{
		TRACE(_T("调用 SuperMapSpatialContextReader::GetCoordinateSystem():GCS_WGS_1984 。\n"));
		return L"GCS_WGS_1984";
	}

    /// <summary>Gets the name of the coordinate system in OpenGIS SRS WKT format of the spatial context currently
    /// being read. If the result is an empty string, the coordinate system WKT description is
    /// not available.</summary>
    /// <returns>Returns the coordinate system description in WKT of of the spatial context.</returns> 
	virtual FdoString* GetCoordinateSystemWkt ()
	{
		TRACE(_T("调用 SuperMapSpatialContextReader::GetCoordinateSystemWkt():空间语义坐标系名称（WKT格式） 。\n"));
		return L"GEOGCS[GCS_WGS_1984,DATUM[D_WGS_1984,SPHEROID[WGS_1984,6378137,298.257223563]],PRIMEM[Greenwich,0],UNIT[Degree,0.0174532925199433]]"	;
	}

    /// <summary>Gets the extent type of the spatial context currently being read.</summary>
    /// <returns>Returns the extent type.</returns> 
	virtual FdoSpatialContextExtentType GetExtentType ()
	{
		TRACE(_T("调用 SuperMapSpatialContextReader::GetExtentType():FdoSpatialContextExtentType_Static 。\n"));
		return FdoSpatialContextExtentType_Static;
	}

    /// <summary>Gets the extent of the spatial context currently being read as a byte
    /// array in FGF format.</summary>
    /// <param name="length">Output the length of the returned byte array.</param> 
    /// <returns>Returns the extent as a byte array in FGF format.</returns> 
	virtual FdoByteArray* GetExtent ()
	{
		TRACE(_T("调用 SuperMapSpatialContextReader::GetExtent() 。\n"));
		return mExtent.p;
	}

    /// <summary>Gets the tolerance value for XY ordinates of the spatial context
    /// currently being read. Tolerances are used in some geometric tests,
    /// mostly for equality between coordinates.  This occurs frequently in spatial
    /// queries, especially with "on boundary" or "just touching" conditions.
    /// It is also an objective amount that can be used when formulating step
    /// distances for parametric curve interpolation.</summary>
    /// <returns>Returns the tolerance</returns>
	virtual const double GetXYTolerance ()
	{
		TRACE(_T("调用 SuperMapSpatialContextReader::GetXYTolerance() 。\n"));
		return 0.00100;
	}

    /// <summary>Gets the tolerance value for Z ordinates of the spatial context
    /// currently being read. Tolerances are used in some geometric tests,
    /// mostly for equality between coordinates.  This occurs a frequently in spatial
    /// queries, especially with "on boundary" or "just touching" conditions.
    /// It is also an objective amount that can be used when formulating step
    /// distances for parametric curve interpolation.</summary>
    /// <returns>Returns the tolerance</returns>
	virtual const double GetZTolerance ()
	{
		TRACE(_T("调用 SuperMapSpatialContextReader::GetZTolerance() 。\n"));
		return 0.00100;
	}

    /// <summary>Returns true if the spatial context currently being read is the active
    /// spatial context.</summary>
    /// <returns>Returns true if the current spatial context is the active one.</returns> 
	virtual const bool IsActive ()
	{
		TRACE(_T("调用 SuperMapSpatialContextReader::IsActive() 。\n"));
		return true;
	}

    /// <summary>Advances the reader to the next item. The default position of the reader
	/// is prior to the first item. Thus, you must call ReadNext to begin
	/// accessing any data.</summary>
	/// <returns>Returns true if there is a next item.</returns> 
	virtual bool ReadNext ()
	{
		TRACE(_T("调用 SuperMapSpatialContextReader::ReadNext() 。\n"));
		
		bool	rc = false;
		static int i = 0;
		if ( i < 2)
		{
			rc = true;
			i++;
		}
		return ( rc );
	}

}; //end for test
*/

