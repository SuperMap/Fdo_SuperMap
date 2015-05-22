#ifndef INCLUDE_GEOMETRY_UGGEORECTOBLIQUE_H_HEADER_INCLUDED_BE220BE3
#define INCLUDE_GEOMETRY_UGGEORECTOBLIQUE_H_HEADER_INCLUDED_BE220BE3

#include "UGGeoRect.h"
#include "UGGeometry.h"

namespace UGC {

//! \attention UGGeoRectOblique被UGGeoRect取代, 请使用UGGeoRect
class GEOMETRY_API UGGeoRectOblique : public UGGeometry
{
private:
	// by zengzm 2007-4-25 UGGeoRectOblique是斜椭圆, UGC中的UGGeoRect已经是斜椭圆了,这个东东就不需要了,
	// 这里暂且留着做一个参考,以后 删掉就OK了.
    UGGeoRectOblique();

    virtual ~UGGeoRectOblique();


public: //pure virtual 

	virtual void Clear();

	virtual UGint GetDimension() const;

	virtual Type GetType() const;

	virtual UGPoint2D GetInnerPoint() const;
	
//	virtual UGGeoLine* GetInnerLine() const;

	virtual UGdouble GetPerimeter() const;

	virtual UGdouble GetArea() const;

	virtual UGdouble GetLength() const;
	
	virtual UGbool ConvertToLine( UGGeoLine &GeoLine, UGlong nSegmentCount = 0 ) const;

	virtual UGbool ConvertToRegion( UGGeoRegion &GeoRegion, UGlong nSegmentCount = 0 ) const;

	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;


	virtual UGString ToXML()  const;

	virtual UGbool FromXML(const UGString& strXML);

	virtual UGbool GetSpatial(UGAutoPtr<UGPoint2D>& pPoints, 
				UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount) const;
public:

    UGbool MakeRectOblique( const UGPoint2D &pntCenter, const UGSize2D& szSize, UGlong nAngle );

    UGbool MakeRectOblique( const UGGeoRect& Rect, UGlong nAngle );


	UGbool MakeRectOblique( const UGRect2D& rcRect, UGlong nAngle );

    UGPoint2D GetCenterPoint()const ;

    void SetCenterPoint( const UGPoint2D& pntCenter );

	UGdouble GetHeight() const;

	UGbool SetHeight( UGdouble dHeight );

	UGdouble GetWidth() const;

	UGbool SetWidth( UGdouble dWidth );

    UGlong GetAngle() const ;

    void SetAngle( UGlong nAngle );

   
protected:
	virtual UGRect2D ComputeBounds() const;
	
	/*virtual UGRect2D GetBoundsInside() const;

	virtual void SetBoundsInside( const UGRect2D & rcBounds );*/

	virtual UGbool SaveGeoData(UGStream& stream, UGDataCodec::CodecType eCodecType,UGbool bSDBPlus = FALSE) const;

	virtual UGbool LoadGeoData( UGStream& stream , UGDataCodec::CodecType eCodecType = UGDataCodec::encNONE ,UGbool bSDBPlus = FALSE);



	//========================================================
	//! \brief 		获取几何对象的参考点，供对几何对象的操作函数使用
	//! \return 	UGint		如果获取的点不是拷贝，返回0，否则返回1
	//! \param 		pPoints		点串指针
	//! \param 		nCount		点串中点的个数
	//! \remarks 	如果返回1，几何对象的操作函数需要调用SetReferencePoints	
	virtual UGint GetReferencePoints( UGPoint2D*& pPoints, UGint& nCount );
	

	//========================================================
	//! \brief 		设置几何对象的参考点，对几何对象点的操作需要写回对象
	//! \return 	UGbool		设置成功返回true，否则返回false
	//! \param 		pPoints		点串指针
	//! \param 		nCount		点串中点的个数
	//! \remarks 	大多数不需要实现这个函数，对于获取的参考点不是直接指向对象本身点的对象需要实现该函数	
	virtual UGbool SetReferencePoints( UGPoint2D* pPoints, UGint nCount );

private:
	UGPoint2D m_pntCenter;
	
	UGdouble m_dWidth;

	UGdouble m_dHeight;

	UGlong m_nAngle;

};

} // namespace UGC



#endif /* INCLUDE_GEOMETRY_UGGEORECTOBLIQUE_H_HEADER_INCLUDED_BE220BE3 */
