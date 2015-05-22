// UGXImage.h: interface for the UGXImage class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGXIMAGE_H__593E340E_9333_48FB_AAA5_F913D23C9576__INCLUDED_)
#define AFX_UGXIMAGE_H__593E340E_9333_48FB_AAA5_F913D23C9576__INCLUDED_

#include "Graphics/UGImage.h"
#include "XGraphics/UGXGraphics.h"

namespace UGC
{

class XGRAPHICS_API UGXImage : public UGImage  
{
	friend UGbool UGXGraphics::StretchImage(UGint,UGint,UGint,UGint,UGGraphics*,UGint,UGint,UGint,UGint,UGint); 
	friend UGbool UGXGraphics::StretchImage(UGint,UGint,UGint,UGint,UGint,UGint,UGint,UGint,UGImage::UGImageData&);
	friend UGbool UGXGraphics::DrawImage(UGint,UGint,UGint,UGint,UGGraphics*,UGint,UGint,UGint);
	friend UGImage *UGXGraphics::SelectImage(UGImage*);
	friend class UGXGraphics;
public:
	UGXImage();
	
	virtual ~UGXImage();

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
	UGColor getPixel(UGint x, UGint y,void *pMemBits = NULL);

	//added by xielin 2007-08-24 外部调用其实希望放回一个UGColor的数组，
	//并且在linux下这样效率高很多(2~4倍)，所以增加这样一个接口，在Windows
	//上内部调用还是推荐还是用Bits，而linux上用Colors，外部调用建议都用Colors
	//! \brief 获取UGImage对象内部数据，转换成了UGColor格式,注意，返回的指针
	//! \brief 外部不要删除，内部来管理，目前只支持16位以上颜色
	virtual UGuint* GetColors();

	//! \brief 设置UGImage对象内部数据，目前只支持16位以上颜色,目前要求传入的pColors为ABGR格式，如果有别的需要可以联系xielin进行修改
	virtual void SetColors(UGuint unCount,const UGuint* pColors);

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
	static void render(XImage *xim, int depth, UGuchar *m_buf, UGint w, UGint h);

	static void hscalergba(UGuchar *dst,const UGuchar *src,UGint dw,UGint dh,UGint sw,UGint sh) ;
	static void vscalergba(UGuchar *dst,const UGuchar *src,UGint dw,UGint dh,UGint sw,UGint sh) ;
	static void scalenearest(UGColor *dst, const UGColor *src, UGint dw, UGint dh, UGint sw, UGint sh);

	
	UGColor getPixel1(UGint x, UGint y,void *pMemBits);
	UGColor getPixel4(UGint x, UGint y,void *pMemBits);
	UGColor getPixel8(UGint x, UGint y,void *pMemBits);
	UGColor getPixel16(UGint x, UGint y,void *pMemBits);
	UGColor getPixel24(UGint x, UGint y,void *pMemBits);
	UGColor getPixel32(UGint x, UGint y,void *pMemBits);
	UGbool setPixel(UGint x, UGint y,UGColor value,void *pMemBits);
	UGbool setPixel1(UGint x, UGint y, UGColor value,void *pMemBits);
	UGbool setPixel4(UGint x, UGint y, UGColor value,void *pMemBits);
	UGbool setPixel8(UGint x, UGint y, UGColor value,void *pMemBits);
	UGbool setPixel16(UGint x, UGint y, UGColor value,void *pMemBits);
	UGbool setPixel24(UGint x, UGint y, UGColor value,void *pMemBits);
	UGbool setPixel32(UGint x, UGint y, UGColor value,void *pMemBits);

	// 是否是从m_BitmapData.pBits => m_buf,
	// 默认是从m_buf => m_BitmapData.pBits
	//加几个个参数,不一定要每次都缓存m_BitmapData.pBits和m_buf，太浪费效率了。
	void updateBuffer(void *pBits = NULL,UGuint *pColors = NULL,UGbool direction = FALSE);
	void updatePixmap();

	//added by xielin ^_^ 优化Ximage，等测试ok了写注释
	//需要更新数据，从pixmap中更新数据到缓存的ugcolor中（m_buf）
	UGbool m_bNeedUpdate;
	//是否需要从m_buf转换bits
	UGbool m_bNeedFromColorToBits;
	UGColor *m_buf;

	//! \brief 传出的ARGB格式的Color
	UGuint *m_pARGBBuf;
	//! \brief 传出的ARGB格式的Color的最大大小
	UGint m_nMaxARGBBufCount;

	void SetNeedUpdate(UGbool bNeedUpdate=TRUE);
	UGbool IsNeedUpdate();

	//! \brief 从bits转换成colors，用于stretchImage中参数是ImageData的情况，比以前的用法加快速度
	void ConvertImageDataToColors(const UGImageData & ImageData,UGuint *pColors,UGbool bIsReverse);
private:
	UGbool m_bNeedRelease;
	UGbool m_bIsReverse;
	UGImageData m_ImageData;
	
};

}

#endif // !defined(AFX_UGXIMAGE_H__593E340E_9333_48FB_AAA5_F913D23C9576__INCLUDED_)

