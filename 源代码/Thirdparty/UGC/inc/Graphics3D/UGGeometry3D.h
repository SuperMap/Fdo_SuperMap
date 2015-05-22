// UGGeometry3D.h: interface for the UGGeometry3D class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGGEOMETRY3D_H)
#define UGGEOMETRY3D_H

#include "Geometry/UGGeometry.h"

namespace UGC{
class UGStyle3D;
class GRAPHICS3D_API UGGeometry3D :public UGGeometry
{
public:
	UGGeometry3D();
	virtual ~UGGeometry3D();
public:
	//! \brief 得到维度
	virtual UGint GetDimension() const;
	
	//! \brief 得到类型
	virtual UGGeometry::Type GetType() const;

	//! \brief 清空地理数据
	virtual void Clear();

	//! \brief 生成XML格式的信息
	virtual UGString ToXML()  const;
	
	//! \brief 从XML字符串中生成Geometry
	virtual UGbool FromXML(UGString& strXML);

	//! \brief 几何对象是否有效
	virtual UGbool IsValid() const;
	
	//{{Inherited from parend and these functions have nothing to do with the Geometry3D		
	//! \brief 得到内点（在Geometry内部，靠近中央的点）
	virtual UGPoint2D GetInnerPoint() const{return UGPoint2D(0,0);};
		
	//! \brief 得到空间数据
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount) const{return FALSE;};
		
	//! \brief 点击测试
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const{return FALSE;};
	
	//! \brief 缩放
	virtual void Inflate( UGdouble dRatioX, UGdouble dRatioY){};
	
	//! \brief 缩放
	virtual void Inflate( UGdouble dRatio){};
	
	//! \brief 平移
	virtual void Offset( UGdouble dX, UGdouble dY){};
	
	//! \brief 平移
	virtual void Offset( UGdouble dOffset){};
	
	//! \brief 平移
	virtual void Offset( const UGSize2D &szOffset){};
	
	//! \brief 旋转
	virtual void Rotate(const UGPoint2D& pntOrigin, const UGdouble& dAngle){};
	
	//! \brief 旋转
	virtual void Rotate( const UGPoint2D& pntOrigin, const UGdouble& dCosAngle, const UGdouble& dSinAngle,double dAngle = 0){};
	//}}

protected:

	virtual UGbool SaveGeoData( UGStream& stream, UGDataCodec::CodecType eCodecType ) const;
	
	virtual UGbool LoadGeoData( UGStream& stream );

protected:

	UGStyle3D* m_pStyle3D;
};

}

#endif // !defined(UGGeometry3D)
