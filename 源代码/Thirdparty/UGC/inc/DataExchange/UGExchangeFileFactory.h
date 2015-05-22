
/*!
    **************************************************************************************
     \file     UGExchangeFileFactory.h
    **************************************************************************************
     \author   艾国
     \brief    数据转换工厂类               
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


#if !defined(AFX_UGEXCHANGEFILEFACTORY_H__E7DB7397_F9F0_4010_AB23_8747F0C75E9F__INCLUDED_)
#define AFX_UGEXCHANGEFILEFACTORY_H__E7DB7397_F9F0_4010_AB23_8747F0C75E9F__INCLUDED_


#include "Base/ugdefs.h"



namespace UGC {

	class UGExchangeVector;
	class UGExchangeRaster;

class DATAEXCHANGE_API UGExchangeFileFactory  
{
public:
	UGExchangeFileFactory();
	~UGExchangeFileFactory();

public:
	////! \brief 创建数量交换文件
	static UGExchangeVector* CreateExchangeVector(UGint nFileType);

	//! \brief	创建栅格交换文件
	static UGExchangeRaster* CreateExchangeRaster(UGint nFileType);

	//! \brief	释放矢量文件
	static void DestroyExchangeVector(UGExchangeVector* pExchangeVector);

	//! \brief	释放栅格文件
	static void DestroyExchangeRaster(UGExchangeRaster* pExchangeRaster);
};



} //namespace UGC


#endif // !defined(AFX_UGEXCHANGEFILEFACTORY_H__E7DB7397_F9F0_4010_AB23_8747F0C75E9F__INCLUDED_)
