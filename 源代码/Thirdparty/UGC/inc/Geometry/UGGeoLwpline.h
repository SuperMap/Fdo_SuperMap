#ifndef INCLUDE_GEOMETRY_UGGEOLWPLINE_H_HEADER_INCLUDED_BE2202E0
#define INCLUDE_GEOMETRY_UGGEOLWPLINE_H_HEADER_INCLUDED_BE2202E0

#include "UGGeometry.h"

namespace UGC {

class GEOMETRY_API UGGeoLwpline : public UGGeometry
{
 private: // by zengzm 2007-4-10 UGGeoLwpline 暂时也不开发
/* by zengzm 2007-8-24 暂时用不到的就先都注释起来, 以后要支持再开放
    UGGeoLwpline();

    virtual ~UGGeoLwpline();

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
	//{{ Deleted by GUOQC at [2005-02-22 16:44:54]
	// * 修改原因及必要说明
	//Del virtual UGbool Save(UGStream& stream, UGDataCodec::CodecType eCodecType=UGDataCodec::encNONE) const;
	//Del 
	//Del virtual UGbool Load(UGStream& stream);
	//}} Deleted by GUOQC at [2005-02-22 16:44:54]
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
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

public:	
	//Projection..
	virtual void PJConvert( UGRefTranslator *pPJTranslator, UGbool bForward = true);
	virtual void PJForward( UGPrjCoordSys *pCoordSys );
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );
	
public:
	UGbool Make(const UGGeoLwpline& geoLwpline);

    UGbool Make(const UGPoint2D *pPoints, const UGSize2D* pWidths, UGdouble *pBulge, UGbool bIsClosed, UGint pointCount, float fConstantWidth);

    UGint GetCtrlPointCount();

    UGPoint2D* GetCtrlPoints();

    UGSize2D *GetWidths();

    UGdouble *GetBulges();

    float *GetConstantWidth();

    UGbool IsClosed();

//    UGbool ConstructGeometry(UGGeometry*& pGeometry, CSmDrawParamaters *pDrawParam = NULL);

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
	
	UGint m_nPointCount;

	UGArray<UGPoint2D> m_Points;

	UGArray<UGSize2D> m_Widths;

	UGArray<UGdouble> m_Bulges;

	UGbool m_bClosed;

	float m_fConstantWidth;
// by zengzm 2007-8-24 暂时用不到的就先都注释起来, 以后要支持再开放
  */
};

} // namespace UGC



#endif /* INCLUDE_GEOMETRY_UGGEOLWPLINE_H_HEADER_INCLUDED_BE2202E0 */
