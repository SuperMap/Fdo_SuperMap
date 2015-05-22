
/*!
    **************************************************************************************
     \file     UGFileLibBmp.h
    **************************************************************************************
     \author   艾国
     \brief    BMP文件读写类                
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


#if !defined(AFX_UGFILELIBBMP_H__BC4F4E2F_4082_47BB_887F_357D3DD3DA7F__INCLUDED_)
#define AFX_UGFILELIBBMP_H__BC4F4E2F_4082_47BB_887F_357D3DD3DA7F__INCLUDED_


#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGFileStream.h"

namespace UGC{


enum BitmapType
{
  NO_BITMAP,
  BITMAP_1_BPP,
  BITMAP_2_BPP,
  BITMAP_4_BPP,
  BITMAP_8_BPP,
  BITMAP_16_BPP,
  BITMAP_24_BPP,
  BITMAP_32_BPP
};



enum BitmapError
{
  BITMAP_ERROR_OPEN_FILE,
  BITMAP_ERROR_SAVE_FILE,
  BITMAP_ERROR_FILE
};


#define BITMAP_BUFOR_SIZE 0x4000
#define BMP_BITMAPFILEHEADER_SIZE 0x0E
#define BMP_TYPE_B 0x42
#define BMP_TYPE_M 0x4D
#define BMP_OLD_SIZE 0x0C
#define BMP_NEWWIN_SIZE 0x28
#define BMP_NEWOS2_SIZE 0x40
#define BMP_NO_COMPRESSION 0x00
#define BMP_RLE8_COMP 0x01
#define BMP_RLE4_COMP 0x02
#define BMP_END_OF_LINE 0x00
#define BMP_END_OF_BITMAP 0x01
#define BMP_DELTA 0x02


class UGFileLibBmp  
{
public:
	UGFileLibBmp();
	~UGFileLibBmp();
public:
	//! \brief 准备读取一个数据文件
	UGbool OpenForRead(const UGString& strName, UGuchar *&pColorTable, UGint &nWidth, UGint &nHeight,BitmapType &eType);


	void LoadScanline(UGuchar *&img, UGint width, UGint height, UGint heightIndex);

	//! \brief 准备写入一个数据文件
	UGbool OpenForWrite(const UGString& strName, UGuchar *pColorTable, UGint nWidth, UGint nHeight,
				   BitmapType eType, UGbool rle = FALSE);

	//! \brief 保存一个扫描行
	void SaveScanline(UGuchar *img, UGint width, BitmapType type);

	//! \brief 关闭文件
	void Close();

	//! \brief save all bmp data
	void saveBMP(UGuchar* img, UGint nSize);
private:

	//load bmp 
	void loadBMP1 (UGuchar *&img, UGint width, UGint height, UGint heightIndex);
	void loadBMP4 (UGuchar *&img, UGint width, UGint height, UGint heightIndex);
	void loadBMP8 (UGuchar *&img, UGint width, UGint height, UGint heightIndex);
	void loadBMP16(UGuchar *&img, UGint width, UGint height, UGint heightIndex);
	void loadBMP24(UGuchar *&img, UGint width, UGint height, UGint heightIndex);
	void loadBMP32(UGuchar *&img, UGint width, UGint height, UGint heightIndex);



	//save bmp
	void saveBMP1 (UGuchar *img, UGint width);
	void saveBMP4 (UGuchar *img, UGint width);
	void saveBMP8 (UGuchar *img, UGint width);
	void saveBMP16(UGuchar *img, UGint width);
	void saveBMP24(UGuchar *img, UGint width);
	void saveBMP32(UGuchar *img, UGint width);

private:
	UGFileStream m_BmpFile;
	UGuchar *m_pImage;
	UGint m_bcBitCount;
	UGint m_biCompression;
	//作为临时变量来存贮压缩编码的长度
	UGuchar *m_pImageTemp;
	//做为压缩编码的标志
	UGbool m_bSigne;
};

} //namespace UGC



#endif // !defined(AFX_UGFILELIBBMP_H__BC4F4E2F_4082_47BB_887F_357D3DD3DA7F__INCLUDED_)


