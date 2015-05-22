 #ifndef UGDGRAPHICS_H
#define UGDGRAPHICS_H
#include "Graphics/UGGraphics.h"

namespace UGC {

//模拟弧段的点的个数
#define ARCPOINTCOUNT 28	

class UGRAPHICS_API UGDGraphics : public UGGraphics,private UGDImage
{
public:
	UGDGraphics();
	UGDGraphics(UGint w,UGint h,UGColor c = UGRGB(255,255,255));
	virtual ~UGDGraphics();

public:
	class UGRAPHICS_API UGDFont:public UGGraphics::UGFont
	{
		friend class UGDGraphics;
	public:
		virtual UGbool Set(const std::string& f,UGint h = 20, UGint w = 0, UGint r = 0, 
			UGbool b = FALSE, UGbool i = FALSE, 
			UGbool u = FALSE, UGbool s = FALSE,
			UGTextCodec::Charset c = UGTextCodec::GB2312);
		
		virtual std::string GetFamily() const;
		virtual UGint GetHeight() const;
		virtual UGint GetWidth() const;
		virtual UGint GetRotation() const;
		virtual UGbool IsBold() const;
		virtual UGbool IsItalic() const;
		virtual UGbool IsUnderline() const;
		virtual UGbool IsStrikeOut() const;
		virtual UGTextCodec::Charset GetCharset() const;
		
		virtual void SetSize(UGint h,UGint w = 0);
		virtual void SetRotation(UGint r);
		virtual void SetBold(UGbool b);
		virtual void SetItalic(UGbool i);
		virtual void SetUnderline(UGbool u);
		virtual void SetStrikeOut(UGbool s);	
		virtual void SetCharset(UGTextCodec::Charset c);

		void DrawString(UGDGraphics& im,UGint x,UGint y,const std::string& str,UGint align = 0);
		UGbool GetExtent(const std::string& str,UGint& cx,UGint& cy,UGint& bl);

	private:	
		void Draw_Bitmap(UGDGraphics& im,void* bmp,UGint x,UGint y);
		
	private:
		UGint m_nHeight;		
		UGint m_nWidth;	
		UGint m_nRotation;
		UGbool m_bBold;
		UGbool m_bItalic;
		UGbool m_bUnderline;
		UGbool m_bStrikeOut;
		UGTextCodec::Charset m_eCharset;
		std::string m_strFamily;
		void* m_Face;
	private:
		UGbool m_bImitateBold;
		UGbool m_bImitateItalic;
		UGdouble m_dSin_a;
		UGdouble m_dCos_a;
		UGTextCodec m_TextCodec;
	private:
		UGDFont();
	private:
		UGDFont(const UGDFont&);
		UGDFont& operator=(const UGDFont&);
	};

public:
	virtual UGColor GetPixel(UGint x,UGint y) const;
	virtual void DrawPoint(UGint x,UGint y);
	virtual void DrawLine(UGint x1,UGint y1,UGint x2,UGint y2);
	virtual void DrawPolyline(const UGPoint* p,UGint n);
	
	virtual void DrawPolyPolyline(const UGPoint* p,UGint* pPntCount,UGint nCount);
	virtual void DrawPolygon(const UGPoint* p,UGint n);
	virtual void DrawPolyPolygon(const UGPoint* p,UGint* pPntCount,UGint nCount);
	virtual void DrawRect(UGint x1,UGint y1,UGint x2,UGint y2);
	virtual void DrawEllipse(UGint cx, UGint cy, UGint w, UGint h);
	virtual void DrawArc(UGint cx, UGint cy, UGint w, UGint h, UGint s, UGint e);
	virtual void DrawRoundRect(UGint x1,UGint y1,UGint x2,UGint y2,UGint aw,UGint ah);
	
	virtual void DrawImage(UGDImage& src,UGint dstX,UGint dstY,
		UGint srcX,UGint srcY,UGint srcW,UGint srcH);
	
	virtual void FillPolygon(const UGPoint* p,UGint n);
	virtual void FillPolyPolygon(const UGPoint* p,UGint* pPntCount,UGint nCount);
	virtual void FillRect(UGint x1,UGint y1,UGint x2,UGint y2);
	virtual void FillArc(UGint cx, UGint cy, UGint w, UGint h, UGint s, UGint e);
	virtual void FillEllipse(UGint cx,UGint cy,UGint w,UGint h);
	virtual void FillRoundRect(UGint x1,UGint y1,UGint x2,UGint y2,UGint aw,UGint ah);
	
	virtual void DrawString(UGint x,UGint y,const std::string& str);
	
	virtual void SetClip(UGint cl,UGint ct,UGint cr,UGint cb);
	virtual void GetClip(UGint& cl,UGint& ct,UGint& cr,UGint& cb) const;	
	
	virtual TextAlign GetTextAlign() const;
	virtual void SetTextAlign(TextAlign a);
	
	virtual CapStyle GetCapStyle() const;
	virtual CapStyle SetCapStyle(CapStyle c);
	
	virtual JoinStyle GetJoinStyle() const;
	virtual JoinStyle SetJoinStyle(JoinStyle j);
	
	virtual UGColor SetForeground(UGColor c);
	virtual UGColor GetForeground() const;
	
	virtual UGColor SetBackground(UGColor c);
	virtual UGColor GetBackground() const;
	
	virtual BackMode GetBackMode() const;
	virtual BackMode SetBackMode(BackMode b);
	
	virtual UGuint SetLineWidth(UGuint w);
	virtual UGuint GetLineWidth() const;
	
	virtual PenStyle SetPenStyle(PenStyle p);
	virtual PenStyle GetPenStyle() const;
	
	virtual BrushStyle SetBrushStyle(BrushStyle b);
	virtual BrushStyle GetBrushStyle() const;
	
	virtual UGFont& Font();
	virtual const UGFont& Font() const;
	
	virtual void SetStipple(UGDImage* s);
	virtual void SetTile(UGDImage* t);	
	
	virtual UGint GetWidth() const;
	virtual UGint GetHeight() const;
	
	virtual UGint GetBrushOpacity() const;
	virtual void SetBrushOpacity(UGint pct);
	
	virtual UGint GetGradientAngle() const;
	virtual void SetGradientAngle(UGint g);
	
	virtual void GetGraidentOffset(UGint& dx,UGint& dy) const;
	virtual void SetGradientOffset(UGint dx,UGint dy);	
	
	virtual void Output(UGDImage& im) const;

private:
	UGbool HitClip(UGint x,UGint y) const;
	static UGbool Clip1D (UGint& x1, UGint& y1, UGint& x2, UGint& y2, UGint mindim,UGint maxdim);
	void DrawZeroLine(UGint x1,UGint y1,UGint x2,UGint y2);
	void DrawWidthLine(UGint x1,UGint y1,UGint x2,UGint y2,CapStyle startCap,CapStyle endCap);
	void DrawBevelJoin(UGint x1,UGint y1,UGint x2,UGint y2,UGint x3,UGint y3);
	void DrawMiterJoin(UGint x1,UGint y1,UGint x2,UGint y2,UGint x3,UGint y3);
	void ZeroLineSetPixel(UGint x,UGint y,UGint& pos);
	void RegionSetPixel(UGint x,UGint y);
	static void AlphaBlend(UGColor& d,UGColor s,UGint pct);	
	void GetGradientLinearValue(UGColor& dc,UGint x,UGint y) const;
	void GetGradientRadialValue(UGColor& dc,UGint x,UGint y) const;
	void GetGradientConicalValue(UGColor& dc,UGint x,UGint y) const;
	void GetGradientSquareValue(UGColor& dc,UGint x,UGint y) const;

private:	
	UGint* m_pPolyInts;
	UGint m_nPolyAllocated;
	UGPoint m_arrPointsForDrawArc[ARCPOINTCOUNT];
	UGPoint m_arrPointsForFillArc[ARCPOINTCOUNT];
	UGPoint m_arrPointsForWidthLine[4];
private:
	static const UGuchar m_arrDash[][24];
	static const UGuchar m_arrHatch[][64];
private:
	UGColor m_clrForeground;	
	UGColor m_clrBackground;
	UGuint m_nThickness;
	TextAlign m_eAlign;
	CapStyle m_eCapStyle;
	JoinStyle m_eJoinStyle;
	PenStyle m_ePenStyle;
	BrushStyle m_eBrushStyle;	
	UGint m_nClipX1,m_nClipY1;
	UGint m_nClipX2,m_nClipY2;
	BackMode m_eBackMode;	
	UGDImage* m_pStipple;	
	UGDImage* m_pTile;
	
	//填充时的画刷半透明分量[0,100]
	UGint m_nBrushOpacity;

	//渐变填充参数
	UGint m_nGradientOffsetX;
	UGint m_nGradientOffsetY;
	UGint m_nGradientAngle;

	//填充矩形和多边形时的最小外接矩形
	UGint m_nFillMinX,m_nFillMinY;
	UGint m_nFillMaxX,m_nFillMaxY;

	UGDFont m_Font;
private:
	UGDGraphics(const UGDGraphics&);
	UGDGraphics& operator=(const UGDGraphics&);
};

}

#endif

