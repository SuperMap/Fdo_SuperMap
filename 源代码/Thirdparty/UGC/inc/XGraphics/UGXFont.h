// UGXFont.h: interface for the UGXFont class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGXFONT_H__66E87E99_9568_4A9D_92EC_1EB60B912DC1__INCLUDED_)
#define AFX_UGXFONT_H__66E87E99_9568_4A9D_92EC_1EB60B912DC1__INCLUDED_

#include "Graphics/UGFont.h"
#include "XGraphics/UGFreeTypeLib.h"
#include "Base/UGTextCodec.h"

namespace UGC
{
class UGXGraphics;
class UGPoint;
class XGRAPHICS_API UGXFont : public UGFont  
{
public:
	UGXFont();
	virtual ~UGXFont();

	// 创建字体
	virtual UGbool Create();
	
	// 创建字体并设置字体的属性(名字,大小,样式,编码等).	
	virtual UGbool Create(const UGFontData& FontData);
	virtual UGbool Create(const UGString& strName,
			UGint nHeight = 40, 
			UGint nWidth = 0,
			UGint nWeight = 0, 
			UGint nAngle = 0, 
			UGbool bBold = false, 
			UGbool bItalic = false,
			UGint nItalicAngle = 0,
			UGbool bUnderline = false, 
			UGbool bStrikeOut = false,
			UGbool bOutline = false, 
			UGbool bShadow = false,
			UGTextCodec::Charset nCharset = UGTextCodec::GB18030);
	
	// 删除字体
	virtual void DeleteObject();

	void Draw_Bitmap(UGXGraphics&, void*, UGint, UGint);

	void DrawString(UGXGraphics&, UGint, UGint, const UGString&, UGint, UGint);
	
	//modified by xielin 2007-08-16 加一个参数，把Graphics传入，主要为了字体内容缓存
	UGbool GetTextExtent(UGXGraphics&,const UGString&, UGint&, UGint&, UGint&);
	
private:
	static inline UGFreeTypeLib::FaceStyle convertStyle(const UGFontData &);
	void _computeBounds(UGint&, UGint&, FT_Vector&, FT_Vector&, UGint&, UGPoint&, 
		UGPoint&, UGPoint&, UGPoint&,UGint,UGint,UGint nPaintOption,UGint nMaxDxE = 0);
	//! \brief 判断是否可以用上次的缓存数据
	UGbool IsCanUserCacheFontInfo(UGXGraphics&,const UGString&);
	//! \brief 准备缓存数据，主要是把字形通过freetype读出出来，生成image，和字的位置等信息
	UGbool PreFontInfo(UGXGraphics&,const UGString&);
	
	//deleted by xielin 2007-10-18这个变量没用了
	//UGTextCodec m_TextCodec;
	UGbool m_bImitateBold;
	UGbool m_bImitateItalic;
	UGdouble m_dSin_a;
	UGdouble m_dCos_a;
	void* m_Face;

	UGbool m_bNeedRelease;
	//added by lugw 2007-04-07 是否采用反走样
	UGbool m_bAnti;

};

}

#endif // !defined(AFX_UGXFONT_H__66E87E99_9568_4A9D_92EC_1EB60B912DC1__INCLUDED_)
