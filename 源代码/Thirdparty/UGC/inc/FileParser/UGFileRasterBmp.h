
/*!
    **************************************************************************************
     \file     UGFileRasterBmp.h
    **************************************************************************************
     \author   艾国
     \brief    BMP文件解析类                
     \remarks   它从 UGFileRaster类继承                                                                    <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  艾国    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/

#if !defined(AFX_UGFILERASTERBMP_H__A42B6B70_BD1B_4C71_8676_2BB3AFD97FD6__INCLUDED_)
#define AFX_UGFILERASTERBMP_H__A42B6B70_BD1B_4C71_8676_2BB3AFD97FD6__INCLUDED_


#include "UGFileParseRaster.h"
#include "FileParser/UGFileLibBmp.h"
#include "Base/UGFileStream.h"
#include "Base/UGMemoryStream.h"

namespace UGC {

	class UGImgScanline;
	class UGImage;
	
class FILEPARSER_API UGFileRasterBmp : public UGFileParseRaster  
{
public:
	UGFileRasterBmp();
	virtual ~UGFileRasterBmp();

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
	//! \brief 读取一个扫描行的数据
	UGuchar *pBmpData;
	//! \brief 读写文件类
	UGFileLibBmp m_bmp;
	//! \brief Bmp的象素格式或称类型
	BitmapType m_type;
	//! \brief 存储对照表（ColorTable）
	UGuchar *pColorTable;
	
};

} //namespace UGC

#endif // !defined(AFX_UGFILERASTERBMP_H__A42B6B70_BD1B_4C71_8676_2BB3AFD97FD6__INCLUDED_)
