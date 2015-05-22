
/*!
    **************************************************************************************
     \file     UGFileRasterPng.h
    **************************************************************************************
     \author   艾国
     \brief    Png文件解析类                
     \remarks   它从 UGFileRaster类继承                                                                         <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  艾国    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGFILERASTERPNG_H__F54AF582_8A49_46E4_9139_A8DF579D2E7F__INCLUDED_)
#define AFX_UGFILERASTERPNG_H__F54AF582_8A49_46E4_9139_A8DF579D2E7F__INCLUDED_


#include "UGFileParseRaster.h"
#include "png.h"
#include "Base/UGFileStream.h"
#include "Base/UGMemoryStream.h"

namespace UGC {

	class UGMemoryStream;
	class UGImage;

class FILEPARSER_API UGFileRasterPng : public UGFileParseRaster  
{
public:
	UGFileRasterPng();
	virtual ~UGFileRasterPng();
public:


	//! \brief 		输出UGImage内容到PNG文件.
	//! \return 	UGbool  
	//! \param 		strFileName  输出的文件路径
	//! \param 		pImage       
	//! \remarks 		
	UGbool OutputDirect(UGString strFileName, UGImage* pImage);
public:

	//////////////////////////////////////////////////////////////////////////
	// 读去函数
	//////////////////////////////////////////////////////////////////////////
	//! \brief 准备读取一个数据文件
	virtual UGbool OpenForRead(const UGString& strFileName);
	//! \brief 准备开始读取栅格数据,在调用ReadData之前必须调用
	virtual UGbool BeginRead(UGint nIndex = 1);

	//! \brief 读取一个扫描行的数据
	virtual UGbool ReadScanLine(UGImgScanline& imgScanline, UGint nRowIndex, UGint nBandIndex = 0);

	//! \brief 结束读取栅格数据,在调用ReadData之后必须调用(释放东东)
	virtual void EndRead();

	//////////////////////////////////////////////////////////////////////////
	// 写入函数
	//////////////////////////////////////////////////////////////////////////
	//! \brief 准备写入一个数据文件
	virtual UGbool OpenForWrite(const UGString& strFileName);
	//! \brief 准备开始写数据,在调用WriteData之前必须调用
	virtual UGbool BeginWrite();

	//! \brief 写入一个扫描行的数据
	virtual UGbool WriteScanLine(UGint nRowIndex, UGImgScanline& imgScanline);

	//! \brief 结束写数据,在调用WriteData之后必须调用
	virtual void EndWrite();
	//! \brief 关闭数据
	virtual void Close();

private:

	UGFileStream m_FilePng;
	png_structp m_pPngStruct;
	png_infop m_pPngInfo;
	png_colorp m_pPngPalette;
	UGbool m_bRead;		//读还是写？
	UGMemoryStream m_MemoryStream;
	//! \brief 是否是OutputDirect函数调用SavePngHeader()函数，因为OutputDirect调用就需要特殊处理，把RGBA->RGB,数据转换就不需要了
	UGbool m_bOutputDirect;
private:
	//! \brief 保存Png的文件头
	UGbool SavePngHeader();
	
};


} //namespace UGC

#endif // !defined(AFX_UGFILERASTERPNG_H__F54AF582_8A49_46E4_9139_A8DF579D2E7F__INCLUDED_)
