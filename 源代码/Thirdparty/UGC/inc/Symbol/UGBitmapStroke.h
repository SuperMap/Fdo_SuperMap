// UGBitmapStroke.h:

#ifndef UG_BITMAPSTROKE_H
#define UG_BITMAPSTROKE_H

#include "Graphics/UGGraphics.h"

namespace UGC {
	
class SYMBOL_API UGBitmapStroke  
{
public:
	UGBitmapStroke();
	~UGBitmapStroke();
	UGBitmapStroke(const UGBitmapStroke& bitmapStroke);
	void operator = (const UGBitmapStroke& bitmapStroke);
	
public:
	//! \brief 清空位图数据
	void   Clear();
	//! \brief 读取位图信息
	UGbool Load(UGStream& stream, UGuint nVersion = 0);
	//! \brief 保存位图信息
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;

	//! \brief 在逻辑坐标pntCenter处绘制该Bitmap笔划
	void Draw( UGGraphics& graphics, const UGPoint& pntCenter,
		       UGint nWidth, UGint nHeight, const UGdouble dAngle,  UGbool bHighlight/*是否高亮显示*/, UGint nTransPercent = 100) const;

	//! \brief 个数位图的高度和宽度
	void GetSize( UGint& nWidth, UGint& nHeight )
	{
		if ( m_pImageData == NULL )
		{
			nWidth = nHeight = 0;
		}
		else
		{
			nWidth  = m_pImageData->nWidth;
			nHeight = m_pImageData->nHeight;
		} 
	}

	//! \brief 读取SFC5.0版本位图信息
	UGbool LoadBmp(UGStream& stream);
	//! \brief 保存SFC5.0版本位图信息
	UGbool SaveBmp(UGStream& stream) const;

	//! \brief 保存为Bitmap文件时的字节数
	UGuint GetBytesOfSavingBmpFile() const;

protected:
	//! 透明绘制位图，将其中一种颜色(由参数clrTransparent指定)相对于背景图透明显示
	void TransparentDraw(UGGraphics& graphics, UGImage* pImgSrc, 
		                 UGint xStart, UGint yStart, UGColor clrTransparent, UGint nTransPercent = 100) const;

	UGbool LoadImageData(UGStream& stream, UGImage::UGImageData*& pImageData);
	UGbool SaveImageData(UGStream& stream, UGImage::UGImageData* pImageData) const;
	//! \brief 计算旋转后的Bounds和锚点
	/**
	\param nWidth         原图宽度[in]
	\param nHeight        原图高度[in]
	\param pntAnchor      原图锚点[in]
	\param dAngle         旋转角度[in]
	\param nNewWidth      新图宽度[in\out]
	\param nNewHeight     新图高度[in\out]
	\param pntNewAnchor   新图锚点[in\out]
	*/
	void CalculateRotateBounds(const UGint nWidth, const UGint nHeight,const UGPoint pntAnchor, const UGdouble dAngle,UGint& nNewWidth,UGint& nNewHeight,UGPoint& pntNewAnchor)const;
	
protected:
	//! bmp的位图数据
	UGImage::UGImageData* m_pImageData;
};
	
}

#endif
