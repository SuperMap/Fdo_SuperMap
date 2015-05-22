// ElemImgHeader.h: interface for the UGSdbImgHeader class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ELEMImgHeader_H__D9758FBA_30E0_11D3_A626_0080C8EE6685__INCLUDED_)
#define AFX_ELEMImgHeader_H__D9758FBA_30E0_11D3_A626_0080C8EE6685__INCLUDED_

#include "Base/ugdefs.h"
#include "Algorithm/UGRect2D.h"
#include "Engine/UGDatasetRasterInfo.h"


namespace UGC{

class UGRecordHeader;

class  UGSdbImgHeader  
{
public:
	UGSdbImgHeader();
	~UGSdbImgHeader();

public:

	enum ImgGridViewMode
	{
		VIEWMODE_IMAGE,
		VIEWMODE_GRID,
		VIEWMODE_GRID_COLOR,
		VIEWMODE_GRID_COLOR_LEVEL,
		VIEWMODE_GRID_COLOR_RANGE,
		VIEWMODE_GRID_LEVEL,
		VIEWMODE_GRID_RANGE,
			
		VIEWMODE_FACE,
		VIEWMODE_FACE_COLOR,
		VIEWMODE_FACE_COLOR_LEVEL,
		VIEWMODE_FACE_COLOR_RANGE,
		VIEWMODE_FACE_COLOR_IMAGE,
		VIEWMODE_FACE_LEVEL,
		VIEWMODE_FACE_RANGE,
		VIEWMODE_FACE_TEXTURE
	};
	
	enum ImgDataType
	{
		IMGDT_IMAGE = 0,			//影像数据.
		IMGDT_MRSID_LINK = 16,		//连接的外部影像文件.
		IMGDT_AMI_LINK = 17,		//连接的外部影像文件.
		IMGDT_ECW_LINK = 18,		//连接的外部影像文件.
		
		IMGDT_GRID = 2,			//GRID.
		IMGDT_DEM = 3,			//DEM.
		IMGDT_TREND = 4,		//TREND SURFACE.
		IMGDT_COST = 5,			//distance cost surface.
		IMGDT_APPRAISAL = 6,	//评价结果.
		IMGDT_BUFFER = 7,		//缓冲区结果.-*
		IMGDT_BASIN = 256,		//盆地水淹分析结果.
		IMDDT_VISIBILITY = 257,	//可视区域分析结果.
	};
	
	struct ImgHistogram
	{
		UGuint ColorIndex;
		UGuint dwCount; 	
	};
	
	enum ImgCompression
	{
		IMGCOM_NONE = 0,	//没有压缩.
		IMGCOM_RLE = 2,		//RLE压缩.
		IMGCOM_LZW = 4,		//LZW压缩.
		IMGDT_JPEG = 8,		//JPEG压缩.
		IMGDT_WAVE = 16,	//小波变换压缩.
	};

protected:
	UGint m_lSize;		//本文件头长度.
	UGint m_lTypeFlag;	//文件格式标志码,"AMIF".
	UGint m_lVersion;	//文件格式版本号.
	ImgDataType m_eDataType;	//影像数据或GRID数据,DEM数据.
	PixelFormat m_PixelFormat;	//象素的格式.
	UGint m_lWidth;
	UGint m_lHeight;
	UGint m_lWidthBytes;
	
	UGDatasetRasterInfo::IBSizeOption m_eBlockSize;	//影像分块边长(象素单位)
	UGint m_lBlockSizes;			//影像分块大小(字节单位)
	ImgColorSpace m_ColorSpace;	//色彩空间类型.
	UGint m_lColBlocks;				//横向分块总数(包含余数).
	UGint m_lRowBlocks;				//纵向分块总数(包含余数).
	UGint m_lIndexOffset;			//块索引信息开始的偏移量.
	UGRect2D m_rcGeoReference;		//影像的地理坐标索引.
	UGint m_lSampleDistance;			//采样间隔.
	ImgHistogram m_HistogramRed[256];		//图像直方图-红色.
	ImgHistogram m_HistogramGreen[256];		//图像直方图-绿色.
	ImgHistogram m_HistogramBlue[256];		//图像直方图-蓝色.
	UGuint m_dwColorMax;		//颜色最大值.分别在RGB中,GRID则为UGuint值.
	UGuint m_dwColorMin;		//颜色最小值.分别在RGB中,GRID则为UGuint值.
	UGdouble m_dAverage;	//平均值.
	UGdouble m_Variance;	//变差系数.
	CRect m_rcThumbSize;
//DEM使用.
	UGint m_lBackColor;	//创建表面模型使用.
	UGint m_lColorLevel;	//颜色分级的级数.
	ImgGridViewMode m_eViewMode;
	CRect m_rc3DView;	//当前立体显示的视野范围.
	UGdouble m_dXRatio;	//CELL的X比例.根据参照范围计算.
	UGdouble m_dYRatio;	//CELL的Y比例.根据参照范围计算.
	UGdouble m_dZRatio;	//CELL的Z比例.由用户指定,缺省为1.0(即真实高程).
	UGint m_crBegin;		//渐变色开始颜色.
	UGint m_crEnd;		//渐变色结束颜色.
	UGint m_crFloor;		//最低面以下颜色.
	UGfloat m_fZFloor;	//最低(海平面)限制高度.
	UGfloat m_fZMax;		//最大限制高度.
	UGint m_lTrendSquare;	//趋势分析的分块大小.
	UGint m_lTrendSmooth;	//趋势分析的平滑范围.
	ImgCompression m_Compression;	//压缩方式.
	UGchar m_FilePath[256];	//文件的相对路径,连接外部文件使用.

public:
	void operator = (const UGSdbImgHeader &value);
	UGbool GetRecordHeader(UGRecordHeader *pRcdHdr);	//保存记录头到内存块
	void FromRasterInfo(const UGDatasetRasterInfo& ugRasterInfo,UGint nNoValue);
	void ToRasterInfo(UGDatasetRasterInfo& ugRasterInfo,UGint& nNowValue);

};



}

#endif // !defined(AFX_ELEMImgHeader_H__D9758FBA_30E0_11D3_A626_0080C8EE6685__INCLUDED_)
