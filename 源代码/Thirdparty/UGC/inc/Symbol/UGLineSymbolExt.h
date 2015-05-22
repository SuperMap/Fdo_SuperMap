#ifndef UGLINESYMBOLEXT_H
#define UGLINESYMBOLEXT_H

#include "Graphics/UGGraphics.h"
#include "Algorithm/UGPoint2D.h"

// yujiang
#define hypot _hypot

namespace UGC {
	
class UGLineSymParam;
class UGMarkerSymbolLib;

/** 线型扩展(UGLineSymbolExt)，一个线型扩展由1~5个Token组成(目前最多只支持5个)
	@remarks
	1。系统提供9种内部定义的修饰符，如下：
		Token_Arrow	      --->非填充箭头	  
		Token_ArrowSolid  --->实填充箭头
		Token_Arrow3	  --->40%填充箭头 
		Token_Arrow4	  --->60%填充箭头 
		Token_Rhombic	  --->实填充菱形(◆)
		Token_Ellipse	  --->非填充椭圆(○)
		Token_Rect		  --->非填充矩形(□)
		Token_EllipseSolid--->实填充椭圆(●)
		Token_RectSolid	  --->实填充矩形(■)

     2。除了使用9种内部定义的修饰符;
		也可以使用点符号库中的点符号作为自定义的扩展修饰符(CustomizedToken)；
	
	 3。系统中仅支持扩展修饰符的5种分布位置，如下：
        Token_Head           --->首部 		    
		Token_Tail           --->尾部
		Token_MiddlePoint    --->中间节点
		Token_LineCenter     --->线段中心
		Token_PolyLineCenter --->折线中心

     4。一个UGLineSymbolExt最多可以存储5个不同位置的token数据信息(UGExtTokenData)，
		一个token数据信息记录了token的：
		1.高度；2.宽度；3.旋转角度；
		4.图形符号ID;

     5。5个位置的Token数据信息在m_TokenDatas中按以下顺序存储
		(note:若某个位置上没有Token的话，就不存储Token数据信息)：
		  Token_Head           = 0,  //首部
		  Token_Tail           = 1,  //尾部
		  Token_MiddlePoint    = 2,  //中间节点
		  Token_LineCenter     = 3,  //线段中心
		  Token_PolyLineCenter = 4   //折线中心
*/
class SYMBOL_API UGLineSymbolExt  
{
	
public:
    //! 内部定义的修饰符的类型ID
	enum TokenID
	{
		    Token_NULL             = 0,
			Token_Arrow		       = 1,   //＞非填充箭头
			Token_ArrowSolid        = 2,   //填充箭头
			Token_Arrow3	       = 3,   //40%填充箭头
			Token_Arrow4	       = 4,   //60%填充箭头
			Token_Rhombic	       = 5,   //◆填充菱形
			Token_Ellipse	       = 6,   //○非填充椭圆
			Token_Rect		       = 7,   //□非填充矩形
			Token_EllipseSolid     = 8,   //●填充椭圆
			Token_RectSolid	       = 9,   //■填充矩形
			Token_Customized_Start = 10   //大于等于Token_Customized_Start的TokenID是自定义点符号
	};	
	
    //! 修饰符所在的位置
	enum TokenPos
	{
			TPos_Head           = 0,  //首部
			TPos_Tail           = 1,  //尾部
			TPos_MiddlePoint    = 2,  //中间节点
			TPos_SegmentCenter  = 3,  //线段中心
			TPos_PolyLineCenter = 4,  //折线中心
			Token_Supported_Max  = 5   //系统支持的最大个数的标志 
	};
	
public:
	//! 线型扩展修饰符的数据信息
	struct UGExtTokenData
	{
		UGuchar  m_nWidth;     /// 宽度(单位:0.1mm)
		UGuchar  m_nHeight;    /// 高度(单位:0.1mm)
		UGshort  m_nRotation;  /// 旋转角度(单位:0.1度)
		UGint    m_nTokenID;   /// m_nTokenID>=Token_ID_End(10) 表示使用自定义的点符号
		
		UGExtTokenData()
		{
			memset( this, 0, sizeof(UGExtTokenData) );
		}
	};
	
	public:
		UGLineSymbolExt();
		~UGLineSymbolExt();
		
	public:
		UGbool Load(UGStream& stream, UGuint nVersion = 0);
		UGbool Save(UGStream& stream, UGuint nVersion = 0) const;
		void Draw(UGGraphics& graphics, const UGPoint* pPoints, UGint nCount, const UGLineSymParam& params);
		
		//! 是否包含有Token符号存在
		UGbool IsContainingTokens();
		
		//! 检测m_nTokenPosInfo上的对应于pos参数的标志位，判断在该位置上是否有Token存在
		UGbool IsHavingTokenAt(TokenPos pos) const;
		
		//! 得到pos位置对应的Token数据信息在m_TokenDatas中的索引，若没有返回-1
		UGint TokenPos2DataIndex(TokenPos pos) const;
		
		//! 返回该线型扩展中的Token的个数
		UGint GetTokenCount() const;
		
		UGbool GetExtTokenData(TokenPos pos, UGExtTokenData& Data) const;
		void SetExtTokenData(TokenPos pos, const UGExtTokenData& Data);
		
		UGbool RemoveExtTokenData(TokenPos pos);
		UGuchar GetExtTokenPosInfo() const;
		
		UGbool MovePointSymID(UGint nAddNum);
		UGbool IsUsedPointSym(UGint nSymID) const;
		//! 是否包含有自定义的Token(自定义的Token也即使用了点符号的Token)
		UGbool IsContainCustomizedToken() const;  
		void Clear();
		
	protected:
		//! 设置Token位置信息的标志位
		void SetPosInfoFlag(TokenPos pos, UGbool bSetting = TRUE);
		void AddTokenData(TokenPos pos, const UGExtTokenData& Data);
		
	protected:
	    //! 求一个线段的长度
	    inline UGdouble SegmentLength(UGdouble xPntStart, UGdouble yPntStart, 
								      UGdouble xPntEnd, UGdouble yPntEnd);
		//! 求线段上的某个点，该点偏离线段起点(PntStart)的距离为offsetLen(如果距离为负，则是反方向延长线上的点)
		inline UGPoint2D CalcOffsetPntOnSegment(UGdouble xPntStart, UGdouble yPntStart, 
			                                    UGdouble xPntEnd,   UGdouble yPntEnd, UGdouble offsetLen);
		//! 求垂直于线段, 起点为pntAnchor, 高度为 dHeight 的点的坐标
		inline UGPoint2D CalcVerticalPntOfSegment( UGdouble xPntStart,  UGdouble yPntStart, 
			                                       UGdouble xPntEnd,    UGdouble yPntEnd, 
			                                       UGdouble xPntAnchor, UGdouble yPntAnchor, 
			                                       UGdouble dHeight );

		// 计算一条折线的中心点的位置，并返回中心点所在的线段的索引号
		UGint CalcPolyLineCenter(const UGPoint* pPoints, UGint nCount, UGPoint2D& ptCenter );
		
		//! 构建箭头：根据参数计算出绘制箭头所需的3个或4个控制点，存储在pntsBuf中
		void CreateArrow(  UGGraphics& graphics, UGPoints& pntsBuf, const UGExtTokenData& TokenData, UGdouble dIndentRatio/*箭头尾端的缩进比例系数*/,
			               UGdouble dScaleRatio/*大小的缩放比例*/, const UGPoint2D& ptAnchor, const UGPoint2D& ptStart, const UGPoint2D& ptEnd );

		//! 构建菱形：
		void CreateRhombic( UGGraphics& graphics, UGPoints& pntsBuf, const UGExtTokenData& TokenData,UGdouble dScaleRatio/*大小的缩放比例*/,
			               const UGPoint2D& ptAnchor, const UGPoint2D& ptStart, const UGPoint2D& ptEnd );

		//! 构建矩形
		void CreateRect( UGGraphics& graphics, UGPoints& pntsBuf, const UGExtTokenData& TokenData,UGdouble dScaleRatio/*大小的缩放比例*/,
			               const UGPoint2D& ptAnchor, const UGPoint2D& ptStart, const UGPoint2D& ptEnd );

		
		
	protected:
		UGPen* CreateNewPen( UGGraphics& graphics, UGuint width, UGColor color );
		UGBrush* CreateNewBrush( UGGraphics& graphics, UGColor color ); 
		
		
		void DrawTokens(UGGraphics& graphics, const UGPoint* pPoints, UGint nCount, 
			const UGLineSymParam& DrawingParam, TokenPos pos, const UGExtTokenData& TokenData);
		
		//绘制装饰
		//! graphics-绘图对象
		//! TokenData-装饰
		//! DrawingParam-绘制参数
		//! ptAnchor-装饰绘制位置
		//! ptStart-装饰所在线段的起点
		//! ptEnd-装饰所在线段的终点
		void DrawOneToken(UGGraphics& graphics,
			const UGExtTokenData& TokenData,
			const UGLineSymParam& DrawingParam,
			const UGPoint2D& ptAnchor,
			const UGPoint2D& ptStart,
			const UGPoint2D& ptEnd );

		//! 绘制自定义符号(参数意义和DrawOneToken的参数意义一致)
		void DrawCustomizedToken(UGGraphics& graphics,
			const UGExtTokenData& TokenData,
			const UGLineSymParam& DrawingParam,
			const UGPoint2D& ptAnchor,
			const UGPoint2D& ptStart,
			const UGPoint2D& ptEnd);
		
	protected:
		/** Token位置信息，其后面的5个比特位记录了5个位置上是否有Token
	     7 6 5 4 3 2 1 0---------- 0 首部(Token_Head) 	
		       | | | +------------ 1 尾部(Token_Tail)
		       | | +-------------- 2 中间节点(Token_MiddlePoint)
		       | +---------------- 3 线段中心(Token_LineCenter)
		       +------------------ 4 折线中心(Token_PolyLineCenter)
		*/
		UGuchar m_nTokenPosInfo;

		//! 最多存放5个Token信息，根据m_nTokenPos的标志位来存取相应的
		UGArray<UGExtTokenData> m_TokenDatas;
};
	
inline UGdouble UGLineSymbolExt::SegmentLength(UGdouble xPntStart, UGdouble yPntStart, 
													  UGdouble xPntEnd,   UGdouble yPntEnd )
{
	UGdouble dLen = hypot( xPntEnd - xPntStart, yPntEnd - yPntStart );
	if ( UGIS0(dLen) ) 
	{
		return 0;
	}
	
	return dLen;
}
	
inline UGPoint2D UGLineSymbolExt::CalcOffsetPntOnSegment(UGdouble xPntStart, UGdouble yPntStart, 
														UGdouble xPntEnd, UGdouble yPntEnd, UGdouble offsetLen)
{// 求线段上的某个点，该点偏离线段起点一定距离
	// offsetLen有可能是负值，为负值就是求线段上反方向延长线上的点

	UGdouble deltX = xPntEnd - xPntStart;
	UGdouble deltY = yPntEnd - yPntStart;

	//加一个判断，add by xll
	if(UGIS0(deltX) && UGIS0(deltY))
	{
		return UGPoint2D( xPntEnd,yPntEnd); 
	}
	//UGASSERT( !( UGIS0(deltX) && UGIS0(deltY) ) ); // 不能都为0啊

	UGdouble ratio = offsetLen / hypot(deltX, deltY);
	
	return UGPoint2D( xPntStart + ratio * deltX , 
			          yPntStart + ratio * deltY ); 
}

inline UGPoint2D UGLineSymbolExt::CalcVerticalPntOfSegment( UGdouble xPntStart,  UGdouble yPntStart, 
										   UGdouble xPntEnd,    UGdouble yPntEnd, 
										   UGdouble xPntAnchor, UGdouble yPntAnchor, 
										   UGdouble dHeight )
{
	//垂足点(xPntAnchor,yPntAnchor)在线段上的

	UGdouble deltX = xPntEnd - xPntStart;
	UGdouble deltY = yPntEnd - yPntStart;

	UGdouble ratio = dHeight / hypot(deltX, deltY);

	return UGPoint2D( xPntAnchor - ratio * deltY , 
					  yPntAnchor + ratio * deltX );
}

}

#endif

