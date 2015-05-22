
/*!
    **************************************************************************************
     \file     UGFileParse.h
    **************************************************************************************
     \author   艾国
     \brief    文件解析基类                 
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


#if !defined(AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
#define AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_

#include "Base/ugexports.h"
#include "Base/UGString.h"
#include "Base/UGVariant.h"
#include "Base/UGArray.h"
#include "Algorithm/UGRect2D.h"




namespace UGC {

class FILEPARSER_API UGFileParse  
{
public:
	UGFileParse();
	virtual ~UGFileParse();

public:

	//! \brief 设置临时路径
	virtual void SetTempPath(const UGString& strTempPath);

	//! \brief	设置导出的版本
	virtual void SetImportVersion(UGint nVersion);

	//! \brief	设置一个其他的参数（可以是特殊的格式和用户自定义参数）
	virtual void SetOneParam(const UGString& strFileType, const UGString& strName, const UGVariant& varValue);
public:


	//////////////////////////////////////////////////////////////////////////
	// 读取函数
	//////////////////////////////////////////////////////////////////////////

	//! \brief 准备读取一个数据文件
	virtual UGbool OpenForRead(const UGString& strFileName);

	//! \brief 得到图层的数目
	virtual UGint GetLayerCount();
	
	//! \brief 得到指定序号的图层信息。
	virtual UGbool GetLayerInfo(UGint nIndex, UGString& strLayerName, 
							  UGint& nLayerType, UGString& strSubName);


	//////////////////////////////////////////////////////////////////////////
	// 写入函数
	//////////////////////////////////////////////////////////////////////////
	//! \brief 准备写入一个数据文件

	virtual UGbool OpenForWrite(const UGString& strFileName);

	//! \brief 设置图层数量。
	virtual void SetLayerCount(UGint nCount);

	//! \brief 设置指定图层序号的图层信息。
	virtual void SetLayerInfo(UGint nIndex, 
					const UGString& strLayerName, UGint nLayerType, 
					const UGRect2D& rcBounds, 
					const UGString& strSubName);

	//! \brief 关闭文件
	virtual void Close();
	
protected:
	
	//! \brief 临时文件目录
	UGString m_strTempPath;

	//! \brief 设置版本
	UGint m_nVersion;
};

} //namespace UGC

#endif // !defined(AFX_UGFILEPARSE_H__F2ACB033_F582_4263_B9E9_DCA2E56F87DE__INCLUDED_)
