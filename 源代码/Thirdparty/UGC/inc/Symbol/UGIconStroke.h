// UGIconStroke.h:

#ifndef UG_ICONSTROKE_H
#define UG_ICONSTROKE_H

#include "Graphics/UGGraphics.h"

namespace UGC 
{

class SYMBOL_API UGIconStroke  
{
public:
	UGIconStroke();
	~UGIconStroke();

	UGIconStroke(const UGIconStroke& iconStroke);
	void operator = (const UGIconStroke& iconStroke);

public:
	struct IconHeader  // 6字节
	{
		UGushort idReserved; // Reserved, must be 0
		UGushort idType;     // resource type (1 for icons)
		UGushort idCount;    // how many images?
	};

	struct IconDirEntry // 16字节
	{
		UGbyte	    bWidth;               // Width of the image
		UGbyte	    bHeight;              // Height of the image (times 2)
		UGbyte	    bColorCount;          // Number of colors in image (0 if >=8bpp)
		UGbyte	    bReserved;            // Reserved
		UGushort	wPlanes;              // Color Planes
		UGushort	wBitCount;            // Bits per pixel
		UGuint	    dwBytesInRes;         // how many bytes in this resource?
		UGuint	    dwImageOffset;        // where in the file is this image
	};

	struct BitmapInfoHeader
	{
        UGint      biSize;
        UGint      biWidth;
        UGint      biHeight;
        UGushort   biPlanes;
        UGushort   biBitCount;
        UGint      biCompression;
        UGint      biSizeImage;
        UGint      biXPelsPerMeter;
        UGint      biYPelsPerMeter;
        UGint      biClrUsed;
        UGint      biClrImportant;
	};

public:
	UGbool Load(UGStream& stream, UGuint nVersion = 0);
	UGbool Save(UGStream& stream, UGuint nVersion = 0) const;
	
	void Draw(UGGraphics& graphics, const UGPoint& pntCenter, UGint nWidth, UGint nHeight, const UGdouble dAngle, UGbool bHighlight/*是否高亮显示*/, UGint nTransPercent = 100) const;
	void   ClearImageData();
	void   GetSize(UGint& nWidth, UGint& nHeight) const;

	//! 读取Icon文件中的Icon图像数据
	UGbool LoadIconImage(UGStream& stream);
	//! 将Icon图像数据保存为Icon文件
	UGbool SaveIconImage(UGStream& stream)const;

	//! 保存为Icon文件后，整个Icon文件的字节数
	UGuint GetBytesOfSavingIconFile() const;

protected:
	UGbool Load_Version2003(UGStream& stream);
	UGbool Load_Version2005(UGStream& stream);
    UGbool Save_Version2005(UGStream& stream) const;
	UGbool Save_Version2003(UGStream& stream) const;

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

private:

	//! Icon的位图数据
	UGImage::UGImageData* m_pImageXORMaskData;
	UGImage::UGImageData* m_pImageANDMaskData;
};

}

#endif
