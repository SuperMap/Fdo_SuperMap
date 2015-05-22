/*! \file	 UGDatasetRaster.h
 *  \brief	 栅格数据集定义文件
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGDatasetRaster.h,v 1.42 2007/12/25 08:52:17 liwl Exp $
 */

#ifndef UGDATASETRASTER_H
#define UGDATASETRASTER_H

#include "Base/ugdefs.h"
#include "UGDataset.h"
#include "Algorithm/UGRect2D.h"
#include "Algorithm/UGRect.h"
#include "Geometry/UGImgScanline.h"
#include "Geometry/UGImgBlock.h"
#include "UGDatasetRasterInfo.h"
#include "Geometry/UGGeoRegion.h"
#include "UGRecordset.h"
#include "Algorithm/UGPoint.h"
#include "Base/UGColorTable.h"
#include "Base/UGThread.h"
#include "UGImgBlocksManager.h"

namespace UGC {

//! 栅格数据集
class ENGINE_API UGDatasetRaster : public UGDataset
{
public:
	//! 构造函数
	UGDatasetRaster();

	//! 析构函数
	virtual ~UGDatasetRaster();

public:

	//! 返回数据集类型
	virtual DatasetType GetType() const{
		return (DatasetType)m_RasterInfo.m_nType;
	}

	//! 返回数据集名(可以和表名不同)
	virtual UGString GetName() {
		return m_RasterInfo.m_strName;
	}

	//! 返回最小高程
	virtual UGdouble GetMinZ() {
		return m_RasterInfo.m_dMinZ;
	}
	
	//! 设置最小高程
	virtual void SetMinZ(UGdouble d) {
		m_RasterInfo.m_dMinZ = d;
		SetModifiedFlag();
	}
	
	//! 返回最大高程
	virtual UGdouble GetMaxZ() {
		return m_RasterInfo.m_dMaxZ;
	}
	
	//! 设置最大高程
	virtual void SetMaxZ(UGdouble d) {
		m_RasterInfo.m_dMaxZ = d;
		SetModifiedFlag();
	}

	//! 获取数据集描述信息
	virtual UGString GetDescription() const;

	//! 设置数据集描述信息
	virtual void SetDescription(const UGString& /*strDesc*/);

	//! 得到栅格数据的极值。
	//注意：如果栅格数据的值发生变化，此函数不会重新计算极值，
	//必须先调用CalculateExtremum，重新计算极值才可以。
	void GetExtremum(UGdouble& dMax, UGdouble& dMin)
	{
		dMax = GetMaxZ();
		dMin = GetMinZ();
	}

	//! 返回数据集的维数
	virtual UGint GetDimension() {
		return 2;
	}
	
	//! 判断是否是矢量数据集
	virtual UGbool IsVector() {return FALSE;}
	//! 判断是否是topo数据集
	virtual UGbool IsTopoDataset(){return FALSE;};

	//! 判断是否是栅格数据集
	virtual UGbool IsRaster(){return TRUE;};

	virtual UGbool IsLinkTable(){return FALSE;};

	//! 得到调色板
	UGColorset GetColorset(){
		return m_RasterInfo.m_Colorset;
	}

	//! 设置调色板
	void SetColorset(const UGColorset& Colorset) {
		m_RasterInfo.m_Colorset = Colorset;
		SetModifiedFlag();
	}
	
	//! 返回空间数据编码方式
	virtual UGDataCodec::CodecType GetCodecType() {
		return m_RasterInfo.m_nCodecType;
	}
	
	//! 设置空间数据编码方式
	virtual void SetCodecType(UGDataCodec::CodecType c) {
		m_RasterInfo.m_nCodecType = c;
		SetModifiedFlag();
	}

	virtual UGint GetOptions() {
		return m_RasterInfo.m_nOptions;
	}

	UGDatasetRasterInfo* GetInfo();
	
	//! 获取宽度
	UGint GetWidth() const {
		return m_RasterInfo.m_nWidth;
	}
	
	//! 获取高度
	UGint GetHeight() const {
		return m_RasterInfo.m_nHeight;
	}
	
	//! 返回数据集的范围
	virtual const UGRect2D& GetBounds() const {
		return m_RasterInfo.m_rc2Bounds;
	}
	
	//! 设置数据集的范围
	virtual void SetBounds(const UGRect2D& r) {
		m_RasterInfo.m_rc2Bounds = r;
		SetModifiedFlag();
	}

	
	//! Image横向的Block数目
	UGint GetRowBlockCount() const {		
		return (UGint)UGCEIL(((UGdouble)m_RasterInfo.m_nHeight)/
			m_RasterInfo.m_eBlockSize);
	}
	
	//! Image纵向的Block数目
	UGint GetColBlockCount() const {
		return (UGint)UGCEIL(((UGdouble)m_RasterInfo.m_nWidth)/
			m_RasterInfo.m_eBlockSize);
	}

	//! 卸载指定Block
	virtual UGbool ReleaseBlock(UGint nIndex);

	//! 卸载所有已放入内存的块
	virtual void ReleaseAllBlock();

	//! 获取无效值
	UGdouble GetNoValue() const{
		return m_RasterInfo.m_dbNoValue;
	}

	//! brief 设置无值
	void SetNoValue(UGdouble dbNoValue)
	{
		m_RasterInfo.m_dbNoValue = dbNoValue;
		SetModifiedFlag();
	}

	//! Image的象素格式
	PixelFormat GetPixelFormat() const {
		return m_RasterInfo.m_ePixelFormat;
	}

	//! Block的边长
	UGDatasetRasterInfo::IBSizeOption GetBlockSize() const {
		return m_RasterInfo.m_eBlockSize;
	}

	//! 获取缓冲区的地址
	UGbyte * GetBlockCache() const{
		return m_pBlockCache;
	}

	//! 获取Block的Byte容量
	UGint GetBlockByteSize() const{
		return (GetBlockSize()*GetBlockSize()*UGToolkit::GetBitCount(GetPixelFormat())+7)/8;
	}

	//! 获取Pixel
	UGColor GetPixel(UGint X,UGint Y);
	
	//! 设置Pixel
	void SetPixel(UGint X,UGint Y,UGColor nColor);
	
	//! 获取Value
	UGdouble GetValue(UGint X,UGint Y);
	
	//! 设置Value
	void SetValue(UGint X,UGint Y,UGdouble dValue);
	
	//! 得到扫描线
	UGbool GetScanline(UGint nRowIndex,UGImgScanline& ScanLine, UGint nStartCol = 0);
	
	//! 通过行列索引设置扫描线
	UGbool SetScanline(UGint nRowIndex,UGint nColIndex,
		const UGImgScanline& ScanLine) ;


	//! 获取Block,pImgBlock内存在这个函数中分配，调用者别忘了释放
	UGbool GetBlockAt(UGint nBlockRow,UGint nBlockCol,
		UGImgBlock*& pImgBlock);
	
	//! 通过地理范围缓存数据
	UGbool CacheByGeoRef(const UGRect2D& rc2FocusedArea);

	//! 通过Block缓存数据
	virtual UGbool CacheByBlock(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight) {
		return FALSE;
	}

	//! 通过Pixel缓存数据
	UGbool CacheByPixel(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight);

	//! 通过地理范围估计缓存数据的大小
	UGint EstimateCachSizeByGeoRef(const UGRect2D& rc2FocusedArea);

	//! 通过Block估计缓存数据的大小
	UGint EstimateCachSizeByBlock(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight);

	//! 通过Pixel估计缓存数据的大小
	UGint EstimateCachSizeByPixel(UGint nLeft,UGint nTop,
		UGint nWidth,UGint nHeight) ;

	//{{ 金字塔的相关操作  ***
	//! 当前数据集的影像金字塔的各层指针数组
	UGDatasets& GetPyramidDatasets() {
		return m_PyramidDatasets;
	}

	//! \brief	得到某层金字塔数据集
	UGDatasetRaster * GetPyramidTier(UGint nImgWidth,UGint nDeviceWidth);

	//! 判断数据集是否有某个选项信息
	virtual UGbool HasFlag(UGint nOption);

#if PACKAGE_TYPE==PACKAGE_UGC
	virtual UGbool BuildPyramid(UGbool bShhowProgress) =0;
	virtual UGbool RemovePyramids() = 0;
	//}} 金字塔的相关操作  ***
#endif // end declare ugc sdk

	//! 创建MrSID的外部连接,
	//! bFileMode是指以文件共享的方式还是存储在数据库中的方式
	UGbool CreateMrSIDLink(const UGString& strImgPathName,
		UGbool bFileMode = TRUE) {
		//wait to implement
		return FALSE;
	}

	//! 创建ECW的外部连接
	UGbool CreateECWLink(const UGString& strImgPathName,
		UGbool bFileMode = TRUE) {
		//wait to implement
		return FALSE;
	}

	//! 合法关联文件检查
	UGbool IsValidExternalFileLink() {
		//wait to implement
		return FALSE;
	}

	//! 取得关联文件名
	UGString GetLinkFileName() const {
		return m_strLinkFileName;
	}
	
	//! 读入指定块数据
	virtual UGImgBlock* LoadBlock(UGint nRowBlock,UGint nColBlock) = 0;
    
	//! pImgBlock存盘
	virtual UGbool SaveBlock(UGImgBlock* pImgBlock);


	//视口变换.===========================================================

	void PrepareGeoRefrence();		//初始化GeoRefernce

	//! 象素坐标转为地理坐标
	void ImgToXY(const UGPoint& pntImg,UGPoint2D& pntXY);

	//! 象素坐标转为地理坐标
	void ImgToXY(const UGRect& rectImg,UGRect2D& rectXY);

	//! 地理坐标转为象素坐标
	void XYToImg(const UGPoint2D& pntXY,UGPoint& pntImg);

	//! 地理坐标转为象素坐标
	void XYToImg(const UGRect2D& rectXY,UGRect& rectImg);
	
	//! 获取裁减区域
	UGGeoRegion* GetClipRegion() const {
		return m_pClipRgn;
	}

	//! 设置裁减区域
	void SetClipRegion(UGGeoRegion* pClipRgn);
	
	UGDatasetRaster* GetParentDataset() const{
		return m_pParentDataset;
	}

	//! \brief 		设置影像的地理坐标索引
	//! \return 	void
	//! \param 		&rc2GeoReference
	//! \remarks 		
	void SetGeoReference(const UGRect2D &rc2GeoReference);


	//! \brief 		获取影像的地理坐标索引
	//! \return 	UGRect2D
	//! \remarks 		
	UGRect2D GetGeoReference();	

	//!	\brief	栅格数据集的追加
	UGbool Append(UGDatasetRaster *pSrcRaster);
	
	UGbool CalculateExtremum(
		UGDatasetRaster * pDtGrid, 
		UGdouble &dMax, 
		UGdouble& dMin, 
		UGPoint * pMaxPt = NULL, 
		UGPoint * pMinPt = NULL){
	
		//wait to implement
		return FALSE;
	}

	UGbool CalculateExtremum(
		UGdouble &dMax,
		UGdouble& dMin, 
		UGRecordset * pRsRegion = NULL,
		UGPoint * pMaxPt = NULL, 
		UGPoint * pMinPt = NULL);
	
	//! \brief 		
	//! \return 	UGColorTable*
	//! \remarks 		
	UGColorTable* GetColorTable();
	
	//! \brief 		设置分层设色颜色表
	UGbool SetGridColorTable(UGColorTable* pColorTable=NULL);

	void SetParentDataset(UGDatasetRaster* pParent) {
		this->m_pParentDataset = pParent;
	}

protected:

	UGint EncodeBlock(UGImgBlock * pImgBlock);
	UGbool DecodeBlock(UGImgBlock * pImgBlock, const UGbyte * pByte,UGint nRawSize);

	//! 设置数据集的选项信息
	virtual void SetOptions(UGint nOptions) {
		m_RasterInfo.m_nOptions = nOptions;
		SetModifiedFlag();
	}

	UGImgBlock * GetBlockByPos(UGint nIndex);
	UGbool	SetBlockByPos(UGint nIndex,UGImgBlock *pImgBlock);

private:

	UGbool CalculateExtremumByRegion(UGdouble &dMax,
		UGdouble& dMin,
		UGGeoRegion * pRegion = NULL, 
		UGPoint * pMaxPt = NULL, 
		UGPoint * pMinPt = NULL) ;
	
	//栅格与影像是类似但是不同的
	void GridToXY(const UGPoint& pntImg,UGPoint2D& pntXY);
	void XYToGrid(const UGPoint2D& pntXY,UGPoint& pntImg);

public:
	//!当前地理坐标到影像坐标的映射比例.
	UGSize2D m_ImgRatio;

 #if PACKAGE_TYPE==PACKAGE_UGC
 	//!栅格分层设色颜色集
 	UGColorTable m_ColorTable;
#endif // end declare ugc sdk
//为实现多线程出图，对于以下变量设置到drawing类中处理，在此改为私有，不对外开发
// 	
// 	//!专题图显示模式
// 	//0, theme none; 1, theme unique; 2, theme range;
// 	UGint m_nDrawMode;
// 
// 	//!分段专题图的KEYS
// 	UGArray <UGdouble> *m_pAryDoubleKeys;
// 
// 	//!单值专题图的KEYS,也用ugdouble来存储吧。
// 	UGArray <UGdouble> *m_pAryIntKeys;
// 
// 	//!专题图风格
// 	UGColorset *m_pStyles;
// 
// 	//!专题图默认风格
// 	UGColor m_DefaultStyle;
// #endif // end declare ugc sdk
// 
// 	// 没有办法为了不破坏虚函数显示接口，亮度、对比度先这样加吧。
// 	UGColor m_NoDataStyle;
// 	
// 	UGchar m_btBrightness;
// 	UGchar m_btContrast;	
// 	UGbyte m_btBackColorTolerance;
// 	UGColor m_BackColor;
protected:
	//! Raster信息
	UGDatasetRasterInfo m_RasterInfo;
	
	//! 本地内存中缓存的Block集合
	UGImgBlocksManager m_ImgManager; 
	
	//! 裁减区域
	UGGeoRegion* m_pClipRgn;
	
	UGRect2D m_rcViewGeoRef;	//显示参考坐标

	UGbool m_bGeoReferencePrepared;	//地理参考坐标是否以

	UGMutex m_mutexBlock;

private:
	//! 如果金字塔影像库，必须填充各层影像数据集
	UGDatasets m_PyramidDatasets;

	//! 如果是本数据集是金字塔的一层，必须给父图层的指针
	UGDatasetRaster* m_pParentDataset;

	//! 文件的相对路径,连接外部文件使用
	UGString m_strLinkFileName;
	
	//! 存放当前Block的指针
	UGImgBlock *m_pBlock; 
	
	//! 用于压缩的缓存区
	UGbyte * m_pBlockCache;

	//! 缓存区的大小
	UGuint m_nBlockCacheSize;

	#if PACKAGE_TYPE==PACKAGE_UGC
	
	//!专题图显示模式
	//0, theme none; 1, theme unique; 2, theme range;
	UGint m_nDrawMode;

	//!分段专题图的KEYS
	UGArray <UGdouble> *m_pAryDoubleKeys;

	//!单值专题图的KEYS,也用ugdouble来存储吧。
	UGArray <UGdouble> *m_pAryIntKeys;

	//!专题图风格
	UGColorset *m_pStyles;

	//!专题图默认风格
	UGColor m_DefaultStyle;
#endif // end declare ugc sdk

	// 没有办法为了不破坏虚函数显示接口，亮度、对比度先这样加吧。
	UGColor m_NoDataStyle;
	
	UGchar m_btBrightness;
	UGchar m_btContrast;	
	UGbyte m_btBackColorTolerance;
	UGColor m_BackColor;
/*	
//{{added by yanmb 2007.3.17 用于内存调整
public:
	//内存调度模式
	enum MemoryAdjustMode{
			Seq		= 0,		//由上而下调度
			Rev		= 1,		//由下而上调度
			Dual	= 2,		//双向调度
			Protect = 3		//保护访问区调度	
	};

	UGbool AdjustMemory();
protected:
	MemoryAdjustMode m_nMode;	//内存调度模式
	UGuint m_dwMemoUsed;
	UGuint m_dwMemoLimited;//已使用内存和最小内存阈值

	UGuint GetBestMemo();	//得到最佳内存限量
	//内存调度
	inline UGbool AdjustMemorySeq();	//由上而下调度
	inline UGbool AdjustMemoryRev();	//由下而上调度
	inline UGbool AdjustMemoryDual();	//双向调度
	inline UGbool AdjustMemoryProtect();//保护访问区调度

//}}added by yanmb 2007.3.17 用于内存调整
*/	

};

}

#endif


