
/*!
    **************************************************************************************
     \file     UGExchangeToolkit.h
    **************************************************************************************
     \author   艾国
     \brief    数据转换小工具类             
     \remarks                                                                          <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  艾国    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/

#if !defined(AFX_UGEXCHANGETOOLKIT_H__257C21F3_D61B_45B9_81B4_5E17F9BFFE2B__INCLUDED_)
#define AFX_UGEXCHANGETOOLKIT_H__257C21F3_D61B_45B9_81B4_5E17F9BFFE2B__INCLUDED_

#include "Algorithm/UGRect2D.h"
#include "Base/ugdefs.h"

namespace UGC {


	class UGDatasetRaster;
	
class UGExchangeToolkit  
{

public:
	UGExchangeToolkit();
	~UGExchangeToolkit();
public:
	//! \brief 判断是否为矢量格式
	//! \return 返回true表示是矢量格式; 返回false表示是栅格格式
	static UGbool IsVector(UGint nFileType);
	//! \brief 	得到影象的波段
	static UGint GetBandCount(UGDatasetRaster *pDatasetRaster, UGint nFileType);

	//! \brief 	得到影象的数据类型
	static UGint GetDataType(UGDatasetRaster *pDatasetRaster, UGint nFileType);

	//! \brief 调整一下矩形
	static void AdjustBound(UGRect2D &rect);
};

} //namespace UGC

#endif // !defined(AFX_UGEXCHANGETOOLKIT_H__257C21F3_D61B_45B9_81B4_5E17F9BFFE2B__INCLUDED_)
