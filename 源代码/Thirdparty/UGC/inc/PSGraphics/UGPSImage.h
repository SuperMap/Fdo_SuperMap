// UGPSImage.h: interface for the UGPSImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPSIMAGE_H__3DC0B4F2_F1F7_4EF2_92C2_0698AE246393__INCLUDED_)
#define AFX_UGPSIMAGE_H__3DC0B4F2_F1F7_4EF2_92C2_0698AE246393__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Graphics/UGImage.h"

namespace UGC
{
class UGPSImage : public UGImage  
{	
public:
	UGPSImage();
	
	virtual ~UGPSImage();

	virtual UGbool Create(
			UGint nWidth,
			UGint nHeight,
			UGuint nPlanes, 
			UGuint nBitcount, 
			const UGPalette& palette,
			const void* pBits);

	virtual UGbool Create(const UGImageData & BitmapData);

	virtual UGbool CreateCompatibleImage(UGGraphics *pGraphics, 
		UGint nWidth, UGint nHeight);

	virtual void DeleteObject();

	virtual UGbool Load(UGuint nIDResource);
	
	virtual UGbool GetImageData(UGImageData& ImageData) ;
	
	virtual UGuint GetBits(UGuint unCount, void *pBits) const;

	virtual UGuint SetBits(UGuint unCount, const void *pBits);

	virtual UGColor GetPixel(UGint x, UGint y) const;

	virtual UGColor SetPixel(UGint x, UGint y, UGColor color);

	virtual UGbool IsMonochrom() const;

	virtual void Scale(UGint w, UGint h, UGbool bIsResample=TRUE);
	
	virtual void PrepareBuffer();
	UGColor getPixel(UGint x, UGint y)const;

protected:
	static void render_true_N_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_true_24(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_true_16_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_true_32(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_true_8_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_index_4_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_index_8_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_index_N_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_gray_8_dither(void *xim,UGuchar *img,UGint width,UGint height) ;
	static void render_gray_N_dither(void *xim,UGuchar *img, UGint width, UGint height) ; 
	static void render_mono_1_dither(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_true_N_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_true_16_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_true_8_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_index_4_fast(void *xim,UGuchar *img,UGint width, UGint height) ;
	static void render_index_8_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_index_N_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_gray_8_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_gray_N_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
	static void render_mono_1_fast(void *xim,UGuchar *img, UGint width, UGint height) ;
//	static void render(XImage *xim, int depth, UGuchar *m_buf, UGint w, UGint h);

	static void hscalergba(UGuchar *dst,const UGuchar *src,UGint dw,UGint dh,UGint sw,UGint sh) ;
	static void vscalergba(UGuchar *dst,const UGuchar *src,UGint dw,UGint dh,UGint sw,UGint sh) ;
	static void scalenearest(UGColor *dst, const UGColor *src, UGint dw, UGint dh, UGint sw, UGint sh);

	
	UGColor getPixel1(UGint x, UGint y)const;
	UGColor getPixel4(UGint x, UGint y)const;
	UGColor getPixel8(UGint x, UGint y)const;
	UGColor getPixel16(UGint x, UGint y)const;
	UGColor getPixel24(UGint x, UGint y)const;
	UGColor getPixel32(UGint x, UGint y)const;
	UGbool setPixel(UGint x, UGint y,UGColor value);
	UGbool setPixel1(UGint x, UGint y, UGColor value);
	UGbool setPixel4(UGint x, UGint y, UGColor value);
	UGbool setPixel8(UGint x, UGint y, UGColor value);
	UGbool setPixel16(UGint x, UGint y, UGColor value);
	UGbool setPixel24(UGint x, UGint y, UGColor value);
	UGbool setPixel32(UGint x, UGint y, UGColor value);

	// 是否是从m_BitmapData.pBits => m_buf,
	// 默认是从m_buf => m_BitmapData.pBits
	void updateBuffer(UGbool direction = FALSE);
	void updatePixmap();
	
private:
	UGbool m_bNeedRelease;
	UGbool m_bIsReverse;
	UGImageData m_ImageData;
	UGColor *m_buf;
};
}
#endif // !defined(AFX_UGPSIMAGE_H__3DC0B4F2_F1F7_4EF2_92C2_0698AE246393__INCLUDED_)
