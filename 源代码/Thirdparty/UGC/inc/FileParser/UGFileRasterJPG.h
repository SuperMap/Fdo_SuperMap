// UGFileRasterJPG.h: interface for the UGFileRasterJPG class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILERASTERJPG_H__D1BCD366_327D_46C2_9E20_6B81156E56C5__INCLUDED_)
#define AFX_UGFILERASTERJPG_H__D1BCD366_327D_46C2_9E20_6B81156E56C5__INCLUDED_

#ifdef WIN32
extern "C"
{
	#define JPEG_CJPEG_DJPEG	/* define proper options in jconfig.h */
	#define JPEG_INTERNAL_OPTIONS	/* cjpeg.c,djpeg.c need to see xxx_SUPPORTED */
	#include "jinclude.h"
	#include "jpeglib.h"
	#include "jerror.h"
}
#else
extern "C"
{
	#define JPEG_CJPEG_DJPEG	/* define proper options in jconfig.h */
	#define JPEG_INTERNAL_OPTIONS	/* cjpeg.c,djpeg.c need to see xxx_SUPPORTED */
	#include "../../LibShared/jpeg/include/jinclude.h"
	#include "../../LibShared/jpeg/include/jpeglib.h"
	#include "../../LibShared/jpeg/include/jerror.h"
}
#endif

#include "Graphics/UGImage.h"
#include "UGFileParseRaster.h"


namespace UGC {
class FILEPARSER_API UGFileRasterJPG : public UGFileParseRaster  
{
public:
	UGFileRasterJPG();
	virtual ~UGFileRasterJPG();

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

	//! \brief 关闭数据
	virtual void Close();

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

private:
	UGint m_quality;
	FILE *m_File;

	struct jpeg_decompress_struct m_dinfo;
	struct jpeg_compress_struct m_cinfo;
	struct jpeg_error_mgr m_jerr;
	JSAMPROW row_pointer[1];	// pointer to JSAMPLE row[s]
};

}
#endif // !defined(AFX_UGFILERASTERJPG_H__D1BCD366_327D_46C2_9E20_6B81156E56C5__INCLUDED_)
