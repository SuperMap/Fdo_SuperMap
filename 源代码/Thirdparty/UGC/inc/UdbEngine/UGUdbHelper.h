// UGUdbHelper.h: interface for the UGUdbHelper class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGUDBHELPER_H__34732331_7E94_4757_90FC_18E85E97349E__INCLUDED_)
#define AFX_UGUDBHELPER_H__34732331_7E94_4757_90FC_18E85E97349E__INCLUDED_


#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Engine/UGDataset.h"
#include "Engine/UGDatasetVectorInfo.h"
#include "Engine/UGDatasetRasterInfo.h"

namespace UGC{

class UDBENGINE_API UGUdbHelper  
{
public:
	UGUdbHelper();

	virtual ~UGUdbHelper();

	UGbool GetInsertSQL();

	UGbool GetUpdateSQL();

	//! \brief 得到创建失量数据注册表SMRegister的SQL语句。
	//! \return 创建失量数据注册表SMRegister的SQL语句。
	//! \remarks 。
	//! \attention 。
	UGString GetSmRegisterSQL();

	//! \brief 得到创建栅格数据注册表SmImgRegister的SQL语句。
	//! \return 创建栅格数据注册表SmImgRegister的SQL语句。
	//! \remarks 。
	//! \attention 。
	UGString GetSmImgRegisterSQL();

	//! \brief 得到创建数据源注册表SmDataSourceInfo的SQL语句。
	//! \return 创建数据源注册表SmDataSourceInfo的SQL语句。
	//! \remarks 。
	//! \attention 。
	UGString GetSmDataSourceInfoSQL();

	//! \brief 得到创建字段注册表SmFieldInfo的SQL语句。
	//! \return 创建字段注册表SmFieldInfo的SQL语句。
	//! \remarks 。
	//! \attention 。
	UGString GetSmFieldInfoSQL();

	//! \brief 得到创建失量数据集的SQL语句。
	//! \param vInfo 失量数据集信息。
	//! \return 创建失量数据集的SQL语句。
	//! \remarks 。
	//! \attention 。
	UGString GetCreateVectorSQL(UGDatasetVectorInfo vInfo);
	
	//! \brief 得到创建栅格数据集的SQL语句。
	//! \param rInfo 栅格数据集信息[in]。
	//! \return 。
	//! \remarks 。
	//! \attention 。
	UGString GetCreateRasterSQL(UGDatasetRasterInfo rInfo);
};
}

#endif // !defined(AFX_UGUDBHELPER_H__34732331_7E94_4757_90FC_18E85E97349E__INCLUDED_)

