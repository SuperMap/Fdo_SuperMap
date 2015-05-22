#ifndef INCLUDE_GEOMETRY_UGGEOEQUILATERAL_H_HEADER_INCLUDED_BE2200C2
#define INCLUDE_GEOMETRY_UGGEOEQUILATERAL_H_HEADER_INCLUDED_BE2200C2

#include "UGGeometry.h"

namespace UGC {

//! \attention UGGeoEquilateral暂不开放,不要使用
class GEOMETRY_API UGGeoEquilateral : public UGGeometry
{
//modified by xielin 暂时不开放UGGeoEquilateral对象，构造函数修改为protected 2007.4.7
protected:
    UGGeoEquilateral();

    virtual ~UGGeoEquilateral();

public: //pure virtual 

	virtual void Clear();

	virtual UGint GetDimension() const;

	virtual Type GetType() const;

	virtual UGPoint2D GetInnerPoint() const;
	
//	virtual UGGeoLine* GetInnerLine() const;

	virtual UGdouble GetArea() const;

	virtual UGdouble GetLength() const;
	
	virtual UGbool ConvertToLine( UGGeoLine &GeoLine, UGint nSegmentCount = 0 ) const;

	virtual UGbool ConvertToRegion( UGGeoRegion &GeoRegion, UGint nSegmentCount = 0 ) const;

	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;

	virtual UGString ToXML()  const;

	virtual UGbool FromXML(const UGString& strXML);

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
	
	//! \brief 旋转，角度单位为度
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dAngle);
	
	//! \brief 旋转，角度单位为度
	virtual void Rotate(const UGPoint2D& pntOrigin, UGdouble dCosAngle,
						UGdouble dSinAngle, UGdouble dAngle = 0);
	
	virtual UGbool Resize(const UGRect2D& rcNewBounds); 

public:
	//Projection..
	virtual void PJConvert( UGRefTranslator *pRefTranslator, UGbool bForward = true);
	virtual void PJForward( UGPrjCoordSys *pCoordSys );
	virtual void PJInverse( UGPrjCoordSys *pCoordSys );	

public:
	UGbool Make(const UGGeoEquilateral& geoEquilateral);

    //角度单位为度
    UGbool Make(const UGPoint2D& pntCenter, UGdouble dRadius, UGint nSideCount, UGdouble dAngle);

    UGPoint2D GetCenterPoint();

    void SetCenterPoint( const UGPoint2D& pntCenter );

    UGdouble GetRadius();

    UGbool SetRadius( UGdouble dRadius);

    UGint GetSideCount();

    UGbool SetSideCount(UGint nSideCount);
	
	//返回值角度单位为度
    UGdouble GetAngle();
	
	//角度单位为度
    void SetAngle(UGdouble dAngle);

protected:
	virtual UGRect2D ComputeBounds() const;
	
	//virtual UGRect2D GetBoundsInside() const;

	//virtual void SetBoundsInside( const UGRect2D & rcBounds );

	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE,UGbool bSDBPlus = FALSE );

private:
	UGPoint2D m_pntCenter;

	UGdouble m_dRadius;
	
	UGint m_nSideCount;
	
	UGint m_nAngle; // 这个角度也有问题, 暂不处理
};

} // namespace UGC



#endif 
