//=====================================================================================
// 项目名：			SuperMap Foundation Class (SFC) Library 2.0
// 作  者：			程新荣,王尔琪
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为SuperMap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			SmDatasetRaster.h, SmDatasetRaster.cpp
// 类  名：			CDatasetRaster
// 父  类：			CSmDataset
// 子  类：			各个引擎的影像数据集类，如SDB的CSdbDatasetRaster, Oracle的COrcDatasetRaster等
// 功能说明：		栅格，影像数据集管理
// 调用说明：		本类是虚基类，不能直接使用，需要子类的实例调用相关函数
//=====================================================================================

 
#if !defined(AFX_SMMEMRASTER_H__0FD41E37_3273_11D3_A62A_0080C8EE6685__INCLUDED_)
#define AFX_SMMEMRASTER_H__0FD41E37_3273_11D3_A62A_0080C8EE6685__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Engine/UGDatasetRaster.h"
#include "Geometry/UGImgBlock.h"
#include "MemoryEngine/UGMemDataSource.h"

namespace UGC
{

class MEMENGINE_API UGMemRaster : public UGDatasetRaster
{
	friend class UGMemDataSource;
public:
	UGMemRaster();	
	UGMemRaster(UGMemDataSource *pDataSource);
	virtual ~UGMemRaster();
 
public:
	//! 打开数据集
	virtual UGbool Open();

	//! 关闭数据集
	virtual void Close();

	//! 返回最后更新时间
	virtual UGTime GetDateLastUpdated();

	//! 返回创建时间
	virtual UGTime GetDateCreated();

	//! 数据集重命名,只改变数据集名,表名不变
	virtual UGbool Rename(const UGString& strNewName);

	//! 保存数据集信息
	virtual UGbool SaveInfo();

	//! 刷新数据集信息
	virtual UGbool RefreshInfo();

	//! 返回数据集对应表名
	virtual UGString GetTableName();

	virtual UGbool BuildPyramid(UGbool bShhowProgress);
	virtual UGbool RemovePyramids();
	
	//! 读入指定块数据
	virtual UGImgBlock* LoadBlock(UGint nRowBlock,UGint nColBlock);
    
	//! pImgBlock存盘
	virtual UGbool SaveBlock(UGImgBlock* pImgBlock);

public:
	UGbool Create(UGMemRaster *pDatasetParent, const UGDatasetRasterInfo & rInfo);

};

}

#endif // !defined(AFX_SMMEMRASTER_H__0FD41E37_3273_11D3_A62A_0080C8EE6685__INCLUDED_)
