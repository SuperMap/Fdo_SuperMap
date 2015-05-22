/*! \file	 UGDatasetRasterInfo.h
 *  \brief	 栅格数据集信息定义
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetRasterInfo.h,v 1.7 2007/09/24 08:01:57 zhouqin Exp $
 */

#ifndef UGDATASETRASTERINFO_H
#define UGDATASETRASTERINFO_H

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Algorithm/UGRect2D.h"
#include "Base/UGColorset.h"
#include "Geometry/UGDataCodec.h"

namespace UGC {

//! 栅格数据集信息
class ENGINE_API UGDatasetRasterInfo  
{
public:
	
	//! 影像块大小选项
	enum IBSizeOption {
		IBS_64				= 64,	//! 64*64
		IBS_128				= 128,	//! 128*128
		IBS_256				= 256,	//! 256*256
		IBS_512				= 512,	//! 512*512
		IBS_1024			= 1024,	//! 1024*1024
		IBS_2048			= 2048,	//! 2048*2048
		IBS_4096			= 4096,	//! 4096*4096
		IBS_8192			= 8192	//! 8192*8192
	};

	
public:
	//! 构造函数
	UGDatasetRasterInfo();

	//! 析构函数
	~UGDatasetRasterInfo();

	void operator=(const UGDatasetRasterInfo& rInfo);


public:
	//! 数据集名称
	UGString m_strName;

	//! 底层表名称
	UGString m_strTableName;
	
	//! 数据集类型
	UGint m_nType;

	//! 选项信息
	UGint m_nOptions;

	//! 象素的格式
	PixelFormat m_ePixelFormat;

	//! 影像宽度
	UGint m_nWidth;

	//! 影像高度
	UGint m_nHeight;

	//! 影像行字节数
	UGint m_nWidthBytes;

	//! 影像分块边长
	IBSizeOption m_eBlockSize;

	//! 数据集的Bounds
	UGRect2D m_rc2Bounds;
		
	//! 数据编码类型
	UGDataCodec::CodecType m_nCodecType;	

	//! 横向分块总数(包含余数)
	UGint m_nColBlocks;		
	
	//! 纵向分块总数(包含余数)
	UGint m_nRowBlocks;		
	
	//! 三维Bounds的最小值
	UGdouble m_dMinZ;
	
	//! 三维Bounds的最大值
	UGdouble m_dMaxZ;	
	//! 调色板
	UGColorset m_Colorset;

	//! 无效值，如果某一点的值是m_NoValue,将认为这一点没有值
	UGdouble m_dbNoValue;

	UGString m_strDescription;	//对数据集的描述信息
};

}

#endif

