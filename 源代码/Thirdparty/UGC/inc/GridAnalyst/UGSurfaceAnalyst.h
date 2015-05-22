// UGSurfaceAnalyst.h: interface for the UGSurfaceAnalyst class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGSURFACEANALYSIS_H__ADE3F4E8_DA63_47E2_8C2C_2C14A7657EDE__INCLUDED_)
#define AFX_UGSURFACEANALYSIS_H__ADE3F4E8_DA63_47E2_8C2C_2C14A7657EDE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "GridAnalyst/UGRasterAnalystEnv.h"
#include "Engine/UGDatasetRaster.h"

namespace UGC {

class GRIDANALYST_API UGSurfaceAnalyst  : public UGRasterAnalystEnv
{
public:

	UGSurfaceAnalyst();
	virtual ~UGSurfaceAnalyst();

public:
	UGDatasetVector* IsoLine(UGDatasetRaster* pInputRaster, 
							 UGdouble dInterval,
							 const UGString& strOutputVectorName = (""),
							 UGbool bCADDataset = FALSE,
							 UGdouble dBase = 0.0f, 
							 UGint nSmoothDegree = 3,
							 UGint nSmoothMethod = 0,
							 UGdouble dTolerance = 0.0,
							 UGbool bForIsoPolygon = FALSE);

	UGDatasetVector* IsoLine(UGDatasetVector* pPointDataset,  // 输入的点数据集
								const UGString& strPointField,   // 点数据集的属性字段名称
								UGGeoRegion* pClipRegion,    // 裁剪面数据集
								UGdouble dResolution,             // 需要设置中间结果dem的分辨率							
								UGdouble dInterval,               // 相邻等值线的差
								UGdouble dBase = 0.0f,            // 等值线开始位置
								const UGString& strOutputVectorName = (""),  // 输出等值线数据集的名称
								UGdouble dFilterTolerance = 0.0,  // 提取等值线时采样过滤参数，该参数越大，结果点越少。
								UGint nSmoothDegree = 3,          // 如果输出结果为线数据集需要输入光滑程度
								UGbool bForIsoPolygon = FALSE);         

	UGDatasetVector* IsoPolygon(UGDatasetVector* pPointDataset,  // 输入的点数据集
								const UGString& strPointField,   // 点数据集的属性字段名称
								UGGeoRegion* pClipRegion,    // 裁剪面数据集
								UGdouble dResolution,             // 需要设置中间结果dem的分辨率							
								UGdouble dInterval,               // 相邻等值线的差
								UGdouble dBase = 0.0f,            // 等值线开始位置
								const UGString& strOutputVectorName = (""),  // 输出等值线数据集的名称
								UGdouble dFilterTolerance = 0.0,  // 提取等值线时采样过滤参数，该参数越大，结果点越少。
								UGint nSmoothDegree = 3);			// 如果输出结果为线数据集需要输入光滑程度

private:
	
	UGbool CalcContourValue( UGdouble dMinZ, UGdouble dMaxZ, UGdouble dBase, UGdouble dInterval,
		                          UGdouble& dMinContour, UGdouble& dMaxContour, UGint& nCountContour );

	UGbool AddBoundEdge(UGDatasetRaster* pInputRaster, UGRecordset* pRecordsetIsolines, UGdouble dMin, UGdouble dInterval);

	UGbool ContourContained(UGdouble dValue1, UGdouble dValue2, UGdouble dMin, UGdouble dInterval);

};

}

#endif // !defined(AFX_UGSURFACEANALYSIS_H__ADE3F4E8_DA63_47E2_8C2C_2C14A7657EDE__INCLUDED_)

