// UGImgToolkit.h: interface for the UGImgToolkit class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGIMGTOOLKIT_H__21224E42_7983_49CB_99BC_9792CA94305F__INCLUDED_)
#define AFX_UGIMGTOOLKIT_H__21224E42_7983_49CB_99BC_9792CA94305F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ugdefs.h"


namespace UGC{


class BASE_API UGImgToolkit  
{
public:
	UGImgToolkit();
	virtual ~UGImgToolkit();

public:
	//==============================================================
	//根据象素格式和象素宽度计算DWORD对齐的按照BYTE计的实际需要宽度.
	static UGint AlignWidth(PixelFormat PixelFormat,UGint lPixelWidth);
	static UGint AlignWidthByte(PixelFormat PixelFormat,UGint lPixelWidth);
	static UGint AlignWidthWord(PixelFormat PixelFormat,UGint lPixelWidth);
	
	static UGushort BitCount(PixelFormat PixelFormat);		//根据格式计算位数.
	static UGushort PaletteSize(PixelFormat PixelFormat);	//得到需要的调色板大小.
	static PixelFormat Bit2Format(UGushort wBitCount);		//根据位数返回格式.
	
	#if PACKAGE_TYPE==PACKAGE_UGC
	//色彩空间转换------------------------------------------------------------
	static UGint RGB2CMY(UGint color);
	static UGint CMY2RGB(UGint color);
	static UGint RGB2YIQ(UGint color);
	static UGint YIQ2RGB(UGint color);
	static UGint RGB2YUV(UGint color);
	static UGint YUV2RGB(UGint color);
	static UGint RGB2YCC(UGint color);
	static UGint YCC2RGB(UGint color);
	#endif // end declare ugc API


};
}

#endif // !defined(AFX_UGIMGTOOLKIT_H__21224E42_7983_49CB_99BC_9792CA94305F__INCLUDED_)

