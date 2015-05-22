
/*!
    **************************************************************************************
     \file     UGFileParseToolkit.h
    **************************************************************************************
     \author   艾国
     \brief    文件解析工具类               
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


#if !defined(AFX_UGFILEPARSETOOLKIT_H__AAED9863_4B12_4F48_8406_F32E3EB0CF52__INCLUDED_)
#define AFX_UGFILEPARSETOOLKIT_H__AAED9863_4B12_4F48_8406_F32E3EB0CF52__INCLUDED_

#include "Geometry/UGImgScanline.h"
#include "Base/UGString.h"
#include "Base/UGFileStream.h"
namespace UGC {

class FILEPARSER_API UGFileParseToolkit  
{
public:
	UGFileParseToolkit();
	~UGFileParseToolkit();
public:



	//! \brief 		根据象素格式返回调色板的个数
	//! \return 	UGint
	//! \param 		ePixelFormat
	//! \remark		
	static UGint GetColorCount(PixelFormat ePixelFormat);

	//! \brief 		根据颜色的个数来得到向素格式
	//! \return 	PixelFormat 返回象素的格式
	//! \param 		nColorEntryCount  给出颜色的个数
	//! \remarks 	只有调色板的使用有效	
	static PixelFormat GetPixelFormat(UGint nColorEntryCount);



	//! \brief 		根据BitCount来得到象素格式
	//! \return 	PixelFormat 返回象素格式
	//! \param 		nBitCount  
	//! \remarks 		
	static PixelFormat Bit2Format(UGint nBitCount);
	
	//! \brief 		得到扫描行的字节个数
	//! \return 	UGint
	//! \param 		ePixelFormat 象素的格式
	//! \param 		nWidth       一行象素的个数
	//! \remarks 		
	static UGint GetWidthBytes(PixelFormat ePixelFormat, UGint nWidth);


	//! \brief 		把strReadData分解成nPartCount部分，存储在pStrInfos中输出。pStrInfos应该在外部设置好空间
	//! \return 	UGbool 返回值: True- 这一行的实际part count >=nPartCount; 否则返回false
	//! \param 		&strReadData  字符串数据
	//! \param 		*pStrInfos  存储在pStrInfos中输出， pStrInfos应该在外部设置好空间。
	//! \param 		nPartCount  返回值: True- 这一行的实际part count >=nPartCount; 否则返回false
	//! \param 		&strDelimiter="  strDelimiter分隔符，默认为 逗号（ASCII,）
	//! \remarks 		
	static UGbool SplitOneRow(UGString &strReadData, 
							UGString *pStrInfos, UGint nPartCount, 
							const UGString &strDelimiter=","); 

	static UGString GetExtNameByFileType(UGint nFileType);

};

} // namespace UGC

#endif // !defined(AFX_UGFILEPARSETOOLKIT_H__AAED9863_4B12_4F48_8406_F32E3EB0CF52__INCLUDED_)
