// UG3DGeometry.h: interface for the UG3DGeometry class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UG3DGEOMETRY_H)
#define UG3DGEOMETRY_H
namespace UGC{

#include "Geometry/UGGeometry.h"


class GRAPHICS3D_API UG3DGeometry  :public UGGeometry
{
public:
	UG3DGeometry();
	virtual ~UG3DGeometry();
public:
	//! \brief 清空地理数据
	virtual void Clear();
	
	//! \brief 得到维度
	virtual UGint GetDimension() const;
	
	//! \brief 得到类型
	virtual Type GetType() const;
	
	//! \brief 得到内点（在Geometry内部，靠近中央的点）
	virtual UGPoint2D GetInnerPoint() const;
	
	//! \brief 生成XML格式的信息
	virtual UGString ToXML()  const;
	
	//! \brief 从XML字符串中生成Geometry
	virtual UGbool FromXML(UGString& strXML);
	
	//! \brief 得到空间数据
	virtual UGbool GetSpatialData(UGAutoPtr<UGPoint2D>& pPoints, 
		UGAutoPtr<UGint>& pPolyCount, UGint& nSubCount) const;
	
	//! \brief 几何对象是否有效
	virtual UGbool IsValid() const;
	
	//! \brief 点击测试
	virtual UGbool HitTest( const UGPoint2D &pntHitTest, UGdouble dTolerance) const;
	
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
	virtual void Rotate(const UGPoint2D& pntOrigin, const UGdouble& dAngle);
	
	//! \brief 旋转
	virtual void Rotate( const UGPoint2D& pntOrigin, const UGdouble& dCosAngle, const UGdouble& dSinAngle,double dAngle = 0);
protected:
	virtual UGbool SaveGeoData( UGStream& stream, UGDataCodec::CodecType eCodecType ) const;
	
	virtual UGbool LoadGeoData( UGStream& stream );
	
	

};

}

#endif // !defined(UG3DGEOMETRY_H)
