// UGColorset.h: interface for the UGColorset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(UGCOLORSET_H)
#define UGCOLORSET_H
#include "ugdefs.h"
#include "UGArray.h"
#include "UGStream.h"

namespace UGC{
#define MAXCOLORCOUNT 0x7fff

typedef struct UGRGB16  // 16位色彩
{
	UGushort b : 5;		// 蓝，占5位
	UGushort g : 6;		// 绿，占6位	
	UGushort r : 5;		// 红，占5位

}UGRGB16, *LPUGRGB16;

typedef struct UGRGB24  //24位真彩
{
	UGbyte blue;		//蓝，占8位
	UGbyte green;		//绿，占8位
	UGbyte red;			//红，占8位	
}UGRGB24, *LPUGRGB24;

#if PACKAGE_TYPE==PACKAGE_UGC

typedef enum tagSM_ENUM_STOCK_GRADIENT_SET_STYLE//渐变颜色
{
	gtBlackWhite,			//黑->白
	gtRedWhite,				//红->白
	gtGreenWhite,			//绿->白
	gtBlueWhite,			//蓝->白
	gtYellowWhite,			//黄->白
	gtPinkWhite,			//粉红->白
	gtCyanWhite,			//青->白
	gtRedBlack,				//红->黑
	gtGreenBlack,			//绿->黑
	gtBlueBlack,			//蓝->黑
	gtYellowBlack,			//黄->黑
	gtPinkBlack,			//粉红->黑
	gtCyanBlack,			//青->黑
	gtYellowRed,			//黄->红
	gtYellowGreen,			//黄->绿
	gtYellowBlue,			//黄->蓝
	gtGreenBlue,			//绿->蓝
	gtGreenRed,				//绿->黑
	gtBlueRed,				//蓝->红
	gtPinkRed,				//青->红
	gtPinkBlue,				//青->蓝
	gtCyanBlue,				//青->蓝
	gtCyanGreen,			//青->绿
	gtRainbow,				//彩->虹
	gtGreenOrangeViolet,	//绿->桔黄->紫罗兰	
	gtTerrain,				//地形渐变,用于三维显示效果较好
	gtSpectrum				//光谱渐变
}UG_ENUM_STOCK_GRADIENT_SET_STYLE;	
#endif // end declare ugc sdk

class BASE_API UGColorset:public UGArray<UGColor>
{
public:
	UGColorset();
	virtual ~UGColorset();
	
	void SetColorSize(UGint nSize);

#if PACKAGE_TYPE==PACKAGE_UGC
public:
	//! \brief 		生成渐变颜色集
	//! \return 	UGint 
	//! \param 		nCount  颜色数
	//! \param 		nIndex  颜色集类型
	//! \remarks 	如果返回0表示创建颜色集合不成功。	
	UGint MakeStockRandom(UGint nCount, UGint nIndex,UGbool bReverse = FALSE);
	
	//! \brief 		生成渐变颜色
	//! \return 	UGint
	//! \param 		nCount			颜色数
	//! \param 		btRedStart		
	//! \param 		btRedEnd
	//! \param 		btGreenStart    R,G,B各分量起始值，终止值
	//! \param 		btGreenEnd
	//! \param 		btBlueStart
	//! \param 		btBlueEnd
	//! \param 		FALSE			是否灰度
	//! \remarks 	如果返回0表示创建颜色集合不成功。	
	UGint MakeRandom(UGint nCount, UGbyte btRedStart,UGbyte btRedEnd,
								UGbyte btGreenStart, UGbyte btGreenEnd,
								UGbyte btBlueStart,UGbyte btBlueEnd,
								UGbool bIsGray = FALSE);

	//! \brief 		生成渐变颜色集
	//! \return 	UGint
	//! \param 		nCount					颜色数
	//! \param 		nStockGradientStyle     颜色集类型
	//! \param 		bReverse=FALSE			是否反向
	//! \remarks 	如果返回0表示创建颜色集合不成功。	
	UGint MakeStockGradient(UGint nCount, UG_ENUM_STOCK_GRADIENT_SET_STYLE nStockGradientStyle, UGbool bReverse=FALSE);
	
	//! \brief 		生成渐变颜色集
	//! \return 	UGint
	//! \param 		&arrayControlColors  
	//! \param 		&arrayIntervals
	//! \remarks 	计算多控制点非等距渐变颜色集，其中：arrayControlColors为控制点颜色集合,
	//!				arrayIntervals数组记录每俩个控制点颜色之间的颜色数量，可以为0。因此
	//!				arrayIntervals数组的大小必须等于arrayControlColors数组大小减去一，即：
	//!				arrayIntervals.GetSize()+1 == arrayControlColors.GetSize()。如果成功，
	//!				本函数返回生成的颜色集合大小，该大小应该等于arrayIntervals中各项之和。
	UGint MakeGradient(UGColorset &arrayControlColors, UGArray<UGint> &arrayIntervals);
	

	//! \brief 		计算多控制点等距渐变颜色集
	//! \return 	UGint
	//! \param 		nCount				nCount为要生成的颜色集合中的颜色数量
	//! \param 		&arrayCotrolColors	为控制点颜色集合
	//! \remarks 	如果返回0表示创建颜色集合不成功	
	UGint MakeGradient(UGint nCount, UGColorset &arrayCotrolColors);
		

	//! \brief 		
	//! \return 	UGint
	//! \param 		nCount		颜色数量	
	//! \param 		colorStart
	//! \param 		colorEnd	开始和结束颜色值
	//! \remarks 	如果返回0表示创建颜色集合不成功。	
	UGint MakeGradient(UGint nCount, UGColor colorStart, UGColor colorEnd);

	//! \brief	完全假随机序列
	UGint MakeRandom(UGint nCount);

	//! \brief	Colorset的存取
	UGbool Load(UGStream& stream);

	//! \brief	Colorset的存取
	UGbool Save(UGStream& stream);
	
#endif // end declare ugc API
	
};
}

#endif // !defined(UGCOLORSET_H)
