/** \file	 SuperMapStreamReader.h
*  \author	 马俊
*  \attention 
*  Copyright &copy;  1996-2007 SuperMap GIS Technologies,Inc.<br>
*  All Rights Reserved
*  \version 1.0
*  \date 2008-01-03
*/

#ifndef __SUPERMAP_STREAMREADER_H__
#define __SUPERMAP_STREAMREADER_H__
#ifdef _WIN32
#pragma once
#endif // _WIN32

/*! \class SuperMapStreamReader SuperMapStreamReader.h
	\brief 用于读取影像数据集中的数据，在调用Raster的GetStreamReader时，返回该类的对象
    return 影像数据集中数据的读取是按影像块来读取的，调用该类中的ReadNext来完成
*/

class SuperMapStreamReader : public FdoBLOBStreamReader
{
public:
	SuperMapStreamReader(UGC::UGDatasetRaster *pDatasetRaster, FdoRasterDataModel* datamodel);

protected:
	virtual void Dispose();

public:
	/// \brief
    /// Get the size of a stream.
    /// 
    /// \return
    /// Returns the size of the data source in number of items 
    /// 
    virtual FdoInt64   GetLength();   

    /// \brief
    ///  Skips a number of items 
    /// 
    /// \param offset 
    /// Number of items to skip. Must be a positive number
    /// 
    /// \return
    /// Returns nothing 
    /// 
    virtual void       Skip(const FdoInt32 offset);  
      
    /// \brief
    ///  Get the current index in the stream 
    /// 
    /// \return
    /// Returns the current index in the stream in number of items 
    /// 
    virtual FdoInt64   GetIndex();  

    /// \brief
    ///  Reset the current index in the stream. Allows re-reading 
    /// 
    /// \return
    /// Returns nothing 
    /// 
    virtual void       Reset();      
     
    /// \brief
    ///  Reads in the next block of items. Use ReadNext( buffer) to read in 
    /// the entire stream. 
    /// 
    /// \param buffer 
    /// Buffer holding data read in
    /// \param offset 
    /// Index in the buffer indicating the beginning of the output buffer. 
    /// The caller is responsable for allocating a buffer of a proper size.
    /// \param count 
    /// Number of items to be read in. If -1 read the entire stream.
    /// Throws "invalid parameter"  exception if not a positive value or -1.
    /// 
    /// \return
    ///  Returns the number of items actually read in. When 0 (zero) then the 
    /// end-of-stream was reached. 
    /// 

    virtual FdoInt32   ReadNext( FdoByte* buffer, 
                                        const FdoInt32 offset = 0,
                                        const FdoInt32 count = -1);

    /// \brief
    ///  Reads in the next block of items. Use ReadNext( buffer) to read in 
    /// the entire stream. The caller is responsible to create/dispose the FdoArray. 
    /// 
    /// \param buffer 
    /// FdoArray object holding data read in. Cannot be NULL
    /// \param offset 
    /// Index in the array indicating the beginning of the output buffer. 
    /// If the end of the buffer, then read in appending mode (store at the end). 
    /// Otherwise, overwrite the buffer. Throws "invalid parameter" exception if not in this range.
    /// \param count 
    /// Number of items to be read in. If -1 read the entire stream.
    /// Throws "invalid parameter"  exception if not a positive value or -1.
    /// 
    /// \return
    ///  Returns number of items read.
    /// 
    virtual FdoInt32    ReadNext(  FdoArray<FdoByte> * &buffer, 
                                            const FdoInt32 offset = 0,
                                            const FdoInt32 count = -1 ); 

public:
	~SuperMapStreamReader(void);

public:
	/*
		\brief 使用比率和函数映射的方法对原图像进行重采样
		\param[out] buffer 指向像素值的数组，已经计算了偏移量
		\param[in] nFileXlen 原图像的宽度
		\param[in] nFileYLen 原图像的高度
		\param[in] nViewXLen 显示区域的宽度
		\param[in] nViewYLen 显示区域的高度
		\param[in] nImgColorType 影像颜色类型
		\param[in] nCount 从流中读的字节数
		\return int 返回流中读取的字节数
 		\note buffer 不能为空
	*/
	int  FuncRatioResample(FdoByte* buffer, int nFileXlen, int nFileYLen, 
		int nViewXLen, int nViewYLen, int nImgColorType, int nCount);

	/*
		\brief 判断给定图像是否是带有调色板信息的图像
		\return bool 是调色板图像返回真，否则返回假
	*/
	bool IsPalletteImage();

private:
	UGC::UGDatasetRaster *m_pDatasetRaster;		//指向栅格数据集的指针
	FdoInt64 m_nStreamIndex;					//流中读出的像素的索引
	FdoPtr<FdoRasterDataModel> m_dataModel;		//指向栅格图像支持的数据模型
	int m_nBytesPerPixel;						//图像中每个像素的字节数
	enum ImgColorType
	{
		IMGMONO			= 1,	//单值
		IMGRGB4			= 2,	//4 bits
		IMGGRAY			= 3,	//灰度
		IMGRGB16		= 4,	//16 bits
		IMGRGB24		= 5,	//24 bits
		IMGRGB32		= 6,	//32 bits
		IMGRGB48		= 7,	//48 bits
		IMGRGB64		= 8,	//64 bits
		IMGRGBFLOAT 	= 9,    //32 bits float
		IMGRGBDOUBLE	= 10,	//64 bits double 
	};

	enum BytesPerPixel
	{
		ONEBYTEPIXEL		= 1,	//一个字节
		THREEBYTESPIXEL		= 3,	//三个字节
		FOURBYTESPIXEL		= 4,	//四个字节
		SIXBYTESPERPIXEL	= 6,	//六个字节
		EIGHTBYTESPERPIXEL	= 8		//八个字节
	};
};

#endif // __SUPERMAP_STREAMREADER_H__
