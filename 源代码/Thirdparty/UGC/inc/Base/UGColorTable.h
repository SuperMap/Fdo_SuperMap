/*! \file 		UGColorTable.h
*   \brief 		分层设色颜色集 
*   \remarks 	与UGColorset的结合,支持分层设色和计算光照颜色
*   \author 	LIWENLONG 
*   \date 	2005-02-24 08:56:16
*	\attention
*   Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br> 
*        All Rights Reserved 

*    <b>更新说明：</b><br> 
*/ 


#ifndef UGColorTable_H
#define UGColorTable_H

#include "ugdefs.h"
#include "UGString.h"
#include "UGArray.h"
#include "UGColorset.h"

namespace UGC {

class BASE_API UGColorTable
{
public:
	UGColorTable();
	virtual ~UGColorTable();

public:

	UGbool FromXML(const UGString& strXML, UGint nVersion = 0);
	UGString ToXML(UGint nVersion = 0, const UGString& strElemName = ("")) const;
	
	//! \brief 		得到颜色数
	//! \return 	UGint
	//! \remarks 		
	UGint GetSize();

	//! \brief 		设置颜色数
	//! \return 	void
	//! \param 		nNewValue
	//! \remarks 		
	void SetSize(UGint nNewValue);

	//! \brief 		把颜色nColor加入颜色集
	//! \return 	UGlong
	//! \param 		nColor
	//! \remarks 		
	UGlong AddColor(UGColor nColor);

	//! \brief 		添加颜色
	//! \return 	UGlong
	//! \param 		Red
	//! \param 		Green	Red,Green,Blue是RGB分量
	//! \param 		Blue
	//! \remarks 		
	UGlong Add(UGuchar Red, UGuchar Green, UGuchar Blue);

	//! \brief 		转成ColorFolder
	//! \return 	UGbool
	//! \param 		&colorFolder
	//! \remarks 		
	UGbool ToColorset(UGColorset &colorset);

	//! \brief 		转入ColorFolder
	//! \return 	UGbool
	//! \param 		&colorFolder
	//! \remarks 		
	UGbool FromColorset(const UGColorset &colorset);

	//! \brief 		根据索引取得颜色
	//! \return 	UGColor
	//! \param 		nIndex
	//! \remarks 		
	UGColor GetRGB(UGint nIndex);

	//! \brief 		修改颜色集中的颜色
	//! \return 	void
	//! \param 		nIndex
	//! \param 		nNewValue
	//! \remarks 		
	void SetColor(UGint nIndex, UGint nNewValue);

#if PACKAGE_TYPE==PACKAGE_UGC

	//! \brief 		根据高度取得颜色分量，可以应用于分层设色
	//! \return 	UGbool
	//! \param 		z
	//! \param 		r
	//! \param 		g
	//! \param 		b
	//! \remarks 		
	UGbool GetColor(UGdouble z,UGdouble& r,UGdouble& g,UGdouble& b);
	
		
	//! \brief 		根据法向量计算光照 float NormalV0是包含法向量的三元数组(x,y,z).
	//! \return 	UGfloat
	//! \param 		NormalV0[]
	//! \remarks 		
	UGfloat GetLightRatio(UGfloat NormalV0[]);

	//! \brief 		得到光照后的颜色
	//! \return 	UGlong
	//! \param 		z			高程:根据高程值->高程颜色
	//! \param 		NormalV0[]	NormalV0法向量三元组:  法向量->光照比例
	//! \remarks 		
	UGlong GetLightenColor(UGdouble z,UGfloat NormalV0[]);
	
	//! \brief 		最小z高度
	//! \return 	UGdouble
	//! \remarks 		
	UGdouble GetZFloor()const;

	//! \brief 		设置最小z高度
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetZFloor(UGdouble newValue);

	//! \brief 		最大z高度
	//! \return 	UGdouble
	//! \remarks 		
	UGdouble GetZCeiling()const;

	//! \brief 		设置最大z高度
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetZCeiling(UGdouble newValue);

	//! \brief 		获得水线高度
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	UGdouble GetWaterLevel();

	//! \brief 		设置水线高度
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetWaterLevel(UGdouble newValue);

	//! \brief 		光源的x方向
	//! \return 	UGfloat
	//! \remarks 		
	UGfloat GetLightX();

	//! \brief 		设置光源的x方向
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetLightX(UGfloat newValue);

	//! \brief 		光源的y方向
	//! \return 	UGfloat
	//! \remarks 		
	UGfloat GetLightY();

	//! \brief 		设置光源的y方向
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetLightY(UGfloat newValue);

	//! \brief 		光源的z方向
	//! \return 	UGfloat
	//! \remarks 		
	UGfloat GetLightZ();

	//! \brief 		设置光源的z方向
	//! \return 	void
	//! \param 		newValue
	//! \remarks 		
	void SetLightZ(UGfloat newValue);

	//! \brief 		颜色集颠倒排序
	//! \return 	void
	//! \remarks 		
	void SwapIndex();

	//! \brief 		颜色红蓝分量互变
	//! \return 	void
	//! \remarks 		
	void SwapRedBlue();

	//! \brief 		创建灰色渐变颜色集，颜色数由当前m_Colorset的数目决定
	//! \return 	UGint
	//! \remarks 		
	UGint CreateGrey();

	//! \brief 		创建红色渐变颜色集，颜色数由当前m_Colorset的数目决定
	//! \return 	UGlong
	//! \remarks 		
	UGint CreateRed();

	//! \brief 		创建绿色渐变颜色集，颜色数由当前m_Colorset的数目决定
	//! \return 	UGint
	//! \remarks 		
	UGint CreateGreen();

	//! \brief 		创建蓝色渐变颜色集，颜色数由当前m_Colorset的数目决定
	//! \return 	UGuint
	//! \remarks 		
	UGint CreateBlue();

	//! \brief 		创建地形渐变颜色集，颜色数由当前m_Colorset的数目决定
	//! \return 	UGint
	//! \remarks 	如果设置水线，那么要初始化两个COLORSET	
	UGint CreateDefault();
	
	//! \brief 		打开文件，读入颜色集
	//! \return 	UGlong
	//! \param 		strFileName
	//! \remarks 	尚未实现	
	UGlong Open(LPCTSTR strFileName);

	//! \brief 		把颜色集写入文件
	//! \return 	UGlong
	//! \param 		strFileName
	//! \remarks 	尚未实现
	UGlong Save(LPCTSTR strFileName);
	
		//! \brief 		根据高度取得颜色，可以应用于分层设色
	//! \return 	UGColor
	//! \param 		dZValue
	//! \remarks 		
	UGColor GetColor(UGdouble dZValue);
	
		//! \brief 		生成渐变颜色集
	//! \return 	UGint
	//! \param 		nCount				颜色数
	//! \param 		nStockGradientStyle 颜色集类型
	//! \param 		FALSE				是否反向
	//! \remarks 		
	UGint CreateStockGradient(UGint nCount, UG_ENUM_STOCK_GRADIENT_SET_STYLE nStockGradientStyle, UGbool bReverse = FALSE);

	//! \brief 		计算渐变颜色集
	//! \return 	UGint
	//! \param 		nCount		颜色数量	
	//! \param 		colorStart
	//! \param 		colorEnd	开始和结束颜色值
	//! \remarks 	如果返回0表示创建颜色集合不成功。	
	UGint CreateGradient(UGint nCount, UGColor colorStart,UGColor colorEnd);

	//! \brief 		根据高度取得颜色
	//! \return 	UGColor
	//! \param 		ZValue
	//! \remarks 		
	UGColor InterColor(UGdouble ZValue);
	
		//! \brief 		取得红颜色分量
	//! \return 	UGshort
	//! \param 		nIndex
	//! \remarks 		
	UGshort GetRed(UGint nIndex);

	//! \brief 		设置红颜色分量
	//! \return 	void
	//! \param 		nIndex
	//! \param 		nNewValue
	//! \remarks 		
	void SetRed(UGint nIndex,UGuchar nNewValue);

	//! \brief 		取得绿颜色分量
	//! \return 	UGshort
	//! \param 		nIndex
	//! \remarks 		
	UGshort GetGreen(UGint nIndex);

	//! \brief 		设置绿颜色分量
	//! \return 	void
	//! \param 		nIndex
	//! \param 		nNewValue
	//! \remarks 		
	void SetGreen(UGint nIndex,UGuchar nNewValue);

	//! \brief 		取得蓝颜色分量
	//! \return 	UGshort
	//! \param 		nIndex
	//! \remarks 		
	UGshort GetBlue(UGint nIndex);

	//! \brief 		设置颜色分量
	//! \return 	void
	//! \param 		nIndex
	//! \param 		nNewValue
	//! \remarks 		
	void SetBlue(UGint nIndex,UGuchar nNewValue);

private:
	UGColor InterColor(UGColorset &colorset,UGdouble dUpperLimit,UGdouble dLowerLimit,UGdouble ZValue);
#endif // end declare ugc sdk

	UGColorTable(const UGColorTable&);
	UGColorTable& operator=(const UGColorTable&);

public:
	UGColorset m_Colorset;
	
#if PACKAGE_TYPE==PACKAGE_UGC
public:
	UGColorset m_ColorsetWater;
protected:
	//光照向量.
	UGfloat	m_dLightX,m_dLightY,m_dLightZ;

	UGdouble m_dZMax, m_dZFloor,m_dZWaterLevel;

private:
	UGbool m_bWaterLevel;
#endif // end declare ugc sdk
};

}

#endif
