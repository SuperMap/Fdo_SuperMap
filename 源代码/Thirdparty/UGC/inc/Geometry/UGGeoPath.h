#ifndef INCLUDE_GEOMETRY_UGGEOPATH_H_HEADER_INCLUDED_BE22747D
#define INCLUDE_GEOMETRY_UGGEOPATH_H_HEADER_INCLUDED_BE22747D


#include "UGGeometry.h"

namespace UGC {

// 这个东东 还要吗?
class GEOMETRY_API UGGeoPath : public UGGeometry
{
	/* by zengzm 2007-8-24 暂时用不到的就先都注释起来, 以后要支持再开放
public:
	enum PointType
	{
		MoveTo = 1,
		LineTo = 2,
		ArcTo  = 3,
		BezierTo = 4
	};

// modified by zengzm 2007-4-25 这个东东不开放, 不让new出来
private:
    UGGeoPath();

    virtual ~UGGeoPath();

public: //pure virtual 

	virtual void Clear();

	virtual UGint GetDimension() const;

	virtual Type GetType() const;

	virtual UGPoint2D GetInnerPoint() const;
	
//	virtual UGGeoLine* GetInnerLine() const;

	virtual UGdouble GetPerimeter() const;

	virtual UGdouble GetArea() const;

	virtual UGdouble GetLength() const;
	
	virtual UGbool ConvertToLine( UGGeoLine &GeoLine, UGint nSegmentCount = 0 ) const;

	virtual UGbool ConvertToRegion( UGGeoRegion &GeoRegion, UGint nSegmentCount = 0 ) const;

	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;


	//=======================================================
	//{{ Deleted by GUOQC at [2005-02-22 16:45:41]
	// * 修改原因及必要说明
	//Del virtual UGbool Save(UGStream& stream, UGDataCodec::CodecType eCodecType=UGDataCodec::encNONE) const;
	//Del 
	//Del virtual UGbool Load(UGStream& stream);
	//}} Deleted by GUOQC at [2005-02-22 16:45:41]
	//=======================================================
	
	virtual UGString ToXML(GMLVersionType versionType, UGint nPace = 0) const;

	virtual UGbool FromXML(const UGString& strXML, GMLVersionType versionType);

	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
				UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount, UGint nSegmentCount=0) const;
	// 对象是否有效
	virtual UGbool IsValid()const;
	
	//! \brief 缩放
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY);
	
	//! \brief 缩放
	virtual void Inflate( UGdouble dRatio);
	
	//! \brief 平移
	virtual void Offset( UGdouble dX, UGdouble dY);
	
	//! \brief 平移
	virtual void Offset( UGdouble dOffset);
	
	//! \brief 平移
	virtual void Offset( const UGSize2D &szOffset);
	
	//! \brief 旋转
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief 旋转
	virtual void Rotate( const UGPoint2D& pntOrigin, UGdouble dCosAngle, UGdouble dSinAngle, double dAngle = 0);
	
	virtual UGbool Mirror(const UGPoint2D &pntMirror1, const UGPoint2D &pntMirror2);
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

public:
	//Projection..
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);
	virtual void PJForward( UGPrjCoordSys *pCoordSys );
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );
	

public:

    void SetClose(UGbool bClosed = true);

    void SetFill(UGbool bFilled = true);

	UGbool Make(const UGGeoPath& geoPath);

    UGbool Make(UGPoint2D *pPoints, UGbyte *pTypes, UGint nCount, UGbool bClosed = false, UGbool bFilled = false);

    UGbool Make(UGGeoPath &PathObj);

    UGbyte *GetTypes();

    UGint GetSubCount();

    UGint GetPointCount();

    UGPoint2D *GetPoints();

    UGbool GetAt(UGint nIndex, UGPoint2D &pntVertex, PointType &btType);


    UGPoint2D GetStartNode();

    UGPoint2D GetEndNode();

    UGbool Add(const UGPoint2D &pntPoint, UGGeoPath::PointType btType);

    UGbool Add(UGPoint2D *pPoints, UGGeoPath::PointType *pbtType, UGint nCount);

    UGbool InsertAt(UGint nIndex, const UGPoint2D &pntPoint, UGGeoPath::PointType btType);

    UGbool InsertAt(UGint nIndex, UGPoint2D *pPoints, UGGeoPath::PointType *pbtType, UGint nCount);

    UGbool SetAt(UGint nIndex, const UGPoint2D &pntPoint, UGGeoPath::PointType btType);

    UGbool SetAt(UGint nIndex, UGPoint2D *pPoints, UGGeoPath::PointType *pbtType, UGint nCount);

    UGbool RemoveAt(UGint nIndex);

    UGint Remove(UGint nFrom, UGint nCount);

    UGbool RemoveAll();

	
protected:
	virtual UGRect2D ComputeBounds() const;
	

	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE );



	//========================================================
	//! \brief 		获取几何对象的参考点，供对几何对象的操作函数使用
	//! \return 	UGint		如果获取的点不是拷贝，返回0，否则返回1
	//! \param 		pPoints		点串指针
	//! \param 		nCount		点串中点的个数
	//! \remarks 	如果返回1，几何对象的操作函数需要调用SetReferencePoints	
	//virtual UGint GetReferencePoints( UGPoint2D*& pPoints, UGint& nCount );
	

	//========================================================
	//! \brief 		设置几何对象的参考点，对几何对象点的操作需要写回对象
	//! \return 	UGbool		设置成功返回true，否则返回false
	//! \param 		pPoints		点串指针
	//! \param 		nCount		点串中点的个数
	//! \remarks 	大多数不需要实现这个函数，对于获取的参考点不是直接指向对象本身点的对象需要实现该函数	
	//virtual UGbool SetReferencePoints( UGPoint2D* pPoints, UGint nCount );

private:
	UGArray<UGPoint2D> m_Points;
	
	UGArray<UGbyte> m_pTypes;
	
	UGint m_nPointCount;
	
	UGbool m_bClosed;
	
	UGbool m_bFilled;
	// by zengzm 2007-8-24 暂时用不到的就先都注释起来, 以后要支持再开放
	*/
};

} // namespace UGC



#endif /* INCLUDE_GEOMETRY_UGGEOPATH_H_HEADER_INCLUDED_BE22747D */
