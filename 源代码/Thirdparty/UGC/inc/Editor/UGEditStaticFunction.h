// UGEditStaticFunction.h: interface for the UGEditStaticFunction class.
//
//=====================================================================================
// 项目名：			SuperMap Universal GIS class (UGC) Library 2.0
// 作  者：			宋关福
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为Supermap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			UGEditStaticFunction.h
// 类  名：			UGEditStaticFunction
// 父  类：			
// 子  类：			
// 功能说明：		提供一组编辑常用的静态函数
// 调用说明：		
//=====================================================================================
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGEDITSTATICFUNCTION_H__0A92950C_5E53_423E_81D5_D4D500A9CAB0__INCLUDED_)
#define AFX_UGEDITSTATICFUNCTION_H__0A92950C_5E53_423E_81D5_D4D500A9CAB0__INCLUDED_

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRect2D.h"
#include "Graphics/UGGraphics.h"
#include "Geometry/UGGeoRegion.h"
#include "Symbol/UGMarkerSymParam.h"


namespace UGC {

class EDITOR_API UGEditStaticFunction  
{
public:
	UGEditStaticFunction();
	virtual ~UGEditStaticFunction();
	
	static UGuint GetWinTextAlign( UGuint align );
    static UGuint GetMyTexyAlign( UGuint align );
    static UGbool DrawText(UGGraphics * pGraphics, UGString & strText, UGPoint &pntOriginal, UGlong lTextWidth, UGlong lTextHeight,
		UGString strFontName, UGColor colorText, UGuint nAlign, UGlong nAngle, UGlong nStyle,UGlong nWeight, UGbyte btCharset = UGTextCodec::GB18030 );
    //modified by xielin test
	static void GetSymParamFromGeoStyle( UGMarkerSymParam& symParam, const UGStyle& geoStyle, const UGString& string );
    static void GetGeoStyleFromSymParam( const UGMarkerSymParam& symParam, UGStyle& geoStyle, UGString& string );
    static void CreateRedundanceRegion( UGGeoRegion* pRgn, const UGPoint2D *pPoints, const UGint* subCountArray, UGlong lSubCount );
    static void CreateRedundanceRegion( UGGeoRegion* pRgn, const UGPoint2D *pPoints, UGlong lPointCount );
	//modified by xielin test end

	//计算样条
	//pPointString:折线的节点数组
	//lTotalPoints:总点数
	//PointsCountPerSection:，每断插入点数
	//modified by xielin test
     static UGbool Spline( UGPoint2Ds &pPointString, UGlong &lTotalPoints , UGuint PointsCountPerSection = 10 );
	//modified by xielin test end

	 //add by xielin 计算符号的bounds
	 static UGRect CalculateMarkerSymbolBounds(UGPoint markerSymbolAnchor,const UGPoint &pntAnchor, UGuint dwSize);

};

}

#endif // !defined(AFX_UGEDITSTATICFUNCTION_H__0A92950C_5E53_423E_81D5_D4D500A9CAB0__INCLUDED_)
