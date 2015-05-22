
/*!
    **************************************************************************************
     \file     UGFileParseRaster.h
    **************************************************************************************
     \author   艾国
     \brief    文件解析栅格类               
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


#if !defined(AFX_UGFileParseRaster_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_)
#define AFX_UGFileParseRaster_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_


#include "UGFileParse.h"
#include "Geometry/UGImgScanline.h"
#include "Geometry/UGImgBlock.h"
#include "Base/UGColorset.h"


namespace UGC {

class FILEPARSER_API UGFileParseRaster : public UGFileParse  
{
public:
	UGFileParseRaster();
	virtual ~UGFileParseRaster();

public:
	//////////////////////////////////////////////////////////////////////////
	// 公共设置函数
	//////////////////////////////////////////////////////////////////////////

	//! \brief 设置导入栅格的名字
	void SetImageName(const UGString& strDatasetImage);

	//! \brief 设置导入栅格数据的类型
	void SetGridDataType(UGint nGridDataType);

	//! \brief 设置导入或导出影像数据时，所带的影像坐标参考文件的名字
	void SetImageGeoRefFileName(const UGString& strImageGeoRefFileName);

	//! \brief 设置导入或导出影像数据时，所带的影像坐标参考文件的类型
	void SetImageGeoRefFileType(UGint nImageGeoRefFileType);

	//////////////////////////////////////////////////////////////////////////
	// 公共询问车和设置函数
	//////////////////////////////////////////////////////////////////////////

	//! \brief 是否多波段
	UGbool IsMultiBand() const;

	//! \brief 是否是扫描行存贮
	UGbool IsScanline() const;

	//! \brief 	是否是扫描行相反存贮
	virtual UGbool IsReverse() const;

	//! \brief 设置波段的个数
	void SetBandCount(UGint nBandCount);

	//! \brief 得到波段的个数
	UGint GetBandCount() const;

	//! \brief 设置象素的格式
	void SetPixelFormat(PixelFormat nPixelFormat);
	//! \brief 返回象素的格式
	PixelFormat GetPixelFormat() const;

	//! \brief 设置影像宽度
	void SetWidth(UGint nWidth);
	//! \brief 返回影像宽度
	UGint GetWidth() const;

	//! \brief 设置影像高度
	void SetHeight(UGint nHeight);
	//! \brief 返回影像高度
	UGint GetHeight() const;

	//! \brief 设置横向分块总数(包含余数)
	void SetColBlocks(UGint nColBlocks); 
	//! \brief 得到横向分块总数(包含余数)
	UGint GetColBlocks() const;

	//! \brief 设置纵向分块总数(包含余数)
	void SetRowBlocks(UGint nRowBlocks);
	//! \brief 得到纵向分块总数(包含余数)
	UGint GetRowBlocks() const;

	//! \brief 设置影象的Bounds
	void SetBounds(const UGRect2D& re2Bound);
	//! \brief 得到影象的Bounds
	UGRect2D GetBounds() const;

	//! \brief 设置影像分块边长
	void SetIBlockSize(UGint nBlockSize); 
	//! \brief 返回影像分块边长
	UGint GetIBlockSize() const; 

	//! \brief 设置调色板
	void SetColorset(const UGColorset& Palette);
	//! \brief 得到调色板
	UGColorset GetColorset() const;

	//! \brief 设置导出的数据类型
	void SetDatasetType(UGint nDatasetType);
	//! \brief 得到导入的数据类型
	UGint GetDatasetType() const;

	//! \brief 设置数据源的单位或影象的单位
	void SetUnit(UGint lUnit);
	//! \brief 得到数据源的单位或影象的单位
	UGint GetUnit() const;

	//! \brief 获取栅格数据的 nodata
	virtual UGint GetNoValue();
	
	//////////////////////////////////////////////////////////////////////////
	// 读去函数
	//////////////////////////////////////////////////////////////////////////
	//! \brief 准备开始读取栅格数据,在调用ReadData之前必须调用
	virtual UGbool BeginRead(UGint nIndex = 1);
	//! \brief 读取一个扫描行的数据
	virtual UGbool ReadScanLine(UGImgScanline& imgScanline, UGint nRowIndex, UGint nBandIndex = 0) {return FALSE;};
	//! \brief 读取一个Block数据
	virtual UGbool ReadBlock(UGImgBlock* pImgBlock, UGint nRowBlockIndex, UGint nColBlockIndex, UGint nBandIndex = 0) {return FALSE;};
	//! \brief 结束读取栅格数据,在调用ReadData之后必须调用(释放东东)
	virtual void EndRead();
	
	//////////////////////////////////////////////////////////////////////////
	// 写入函数
	//////////////////////////////////////////////////////////////////////////
	//! \brief 准备开始写数据,在调用WriteData之前必须调用
	virtual UGbool BeginWrite();
	//! \brief 写入一个扫描行的数据
	virtual UGbool WriteScanLine(UGint nRowIndex, UGImgScanline& imgScanline) {return FALSE;};
	//! \brief 结束写数据,在调用WriteData之后必须调用
	virtual void EndWrite();
	//! \brief 删除文件（如果文件导出失败）
	virtual void DeleteFile(const UGString& strFileName);

protected:
	//! \brief 	导出image数据集时，指定生成的影像参考文件的名字
	UGString m_strImageGeoRefFileName; 

	//! \brief	导出image数据集时，指定生成的影像参考文件的类型
	UGint m_nImageGeoRefFileType;

	//! \brief	转入image文件时，生成的image类型的数据集的名字
	UGString m_strDatasetImage;

	//! \brief 	转入影像数据后，每个栅格的数据类型（几个字节来表示一个栅格数据），有预定义的宏
	UGint m_nGridDataType; 

protected:
	//! \brief 	影象的宽
	UGint m_nWidth;
	//! \brief 	影象的高
	UGint m_nHeight;
	//! 横向分块总数(包含余数)
	UGint m_nColBlocks;		
	//! 纵向分块总数(包含余数)
	UGint m_nRowBlocks;
	//! 影象的Bounds
	UGRect2D m_rc2Bounds;
	//! \brief 	影象的象素格式
	UGint m_nPixelFormat;
	//! \brief 	影象的Block大小
	UGint m_nBlockSize;
	//! \brief 	影象的调色版
	UGColorset m_Colorset;

	//! \brief 数据源的单位或影象的单位
	UGint m_nUnit;

	//! \brief 	影象的波段个数
	UGint m_nBandCount;
	//! \brief 	影象的数据类型，如8位用一个byte
	UGint m_nDatasetType;
	//! \brief 	影象对照表实体个数
	UGint m_nColorEntryCount;

	//! \brief 	是否多波段的标志
	UGbool m_bIsMultiBand;
	//! \brief 	是否是扫描行，否则是块状型
	UGbool m_bIsScanline;
	//! \brief 	是否是扫描行相反存贮
	UGbool m_bIsReverse;

};

} //namespace UGC

#endif // !defined(AFX_UGFileParseRaster_H__392553F8_7BF9_4668_BD97_4211091FEF20__INCLUDED_)
