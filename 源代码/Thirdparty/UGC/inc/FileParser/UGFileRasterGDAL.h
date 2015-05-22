
/*!
    **************************************************************************************
     \file     UGFileRasterGDAL.h
    **************************************************************************************
     \author   周芹
     \brief    Gdal文件解析类               
     \remarks   所有栅格解析类都从它继承                                                                       <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  艾国    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/

#if !defined(AFX_UGFILERASTERGDAL_H__9E8BA4C7_A34C_41EB_A4A0_61965343C3BF__INCLUDED_)
#define AFX_UGFILERASTERGDAL_H__9E8BA4C7_A34C_41EB_A4A0_61965343C3BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "gdal_priv.h"
#include "FileParser/UGFileParseRaster.h"

namespace UGC{


class UGFileRasterGDAL : public UGFileParseRaster  
{
public:
	UGFileRasterGDAL();
	virtual ~UGFileRasterGDAL();

public:	
	
	//////////////////////////////////////////////////////////////////////////
	// UGFileParse 中的方法
	//////////////////////////////////////////////////////////////////////////
	
	//! \brief 准备读取一个数据文件
	virtual UGbool OpenForRead(const UGString& strFileName);


public:
	//////////////////////////////////////////////////////////////////////////
	// 继承 UGFileParseRaster 的方法
	//////////////////////////////////////////////////////////////////////////
	

	//////////////////////////////////////////////////////////////////////////
	// 读去函数
	//////////////////////////////////////////////////////////////////////////

	//! \brief 获取栅格数据的 nodata
	virtual UGint GetNoValue();

	//! \brief 准备开始读取栅格数据,在调用ReadData之前必须调用
	virtual UGbool BeginRead(UGint nIndex = 1);

	//! \brief 读取一个扫描行的数据
	virtual UGbool ReadScanLine(UGImgScanline& imgScanline, UGint nRowIndex, UGint nBandIndex = 0);
	
	//! \brief 读取一个Block数据
	virtual UGbool ReadBlock(UGImgBlock* pImgBlock, UGint nRowBlockIndex, UGint nColBlockIndex, UGint nBandIndex = 0);
	
	//! \brief 结束读取栅格数据,在调用ReadData之后必须调用(释放东东)
	virtual void EndRead();

	//! \brief 关闭文件
	virtual void Close();
	
private:
	//! \brief 读取象素的格式
	PixelFormat ReadPixelFormat();

	//! \brief 得到调色板
	UGColorset ReadColorset();

	//! \brief 读取Bounds
	UGRect2D ReadBounds();
	
private:
	
	//! \brief 打开文件后 gdal 数据集指针
	GDALDataset  *m_pgDataset;

	//! \brief Band指针
	GDALRasterBand  *m_pgBand;
};

}
#endif // !defined(AFX_UGFILERASTERGDAL_H__9E8BA4C7_A34C_41EB_A4A0_61965343C3BF__INCLUDED_)
