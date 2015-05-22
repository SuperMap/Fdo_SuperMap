/*! \file UGStorehouse.h
 *  \brief SuperMap Structure Storage 复合文档类
 *  \author 郭其超,陈俊华
 *  \bug

 *	<b>更新说明：</b>\n
	<em>1、2003-11-1 首次完成代码编写.\n</em>
*/ 
#if !defined(AFX_SMSSSTOREHOUSE_H__813097E5_AA81_4CF3_991C_4BCA52D7800F__INCLUDED_)
#define AFX_SMSSSTOREHOUSE_H__813097E5_AA81_4CF3_991C_4BCA52D7800F__INCLUDED_

#include "UGBlockManager.h"
#include "UGFolder.h"


namespace UGC{

/// \brief 文件标识，"SMSS"
const UGuint STORE_HOUSE_FLAG =	0x83778383;  

/// \brief 文件版本号,2003-10-20
const UGuint STORE_HOUSE_VERSION = 20031020;  

/// \brief 复合文档类，提供创建，打开，保存等功能。
/// \remark SuperMap Structure Storage (SSS)技术就是在一个普通的文件内实现
/// \remarks 虚拟的目录结构，一个目录下可以具有多个子目录或者文件
class COMPOUNDFILE_API UGStorehouse 
{
public:	
	UGStorehouse();
	~UGStorehouse();
	static const UGuint m_FileHeaderSize; //8192
public:
	UGbool Create(const UGString& strName,UGint nBlockSize=8192);

	UGbool Open(const UGString& strName,UGStreamDirection nFlag);

	void Close(UGbool bAutoSave=true);

	UGbool Save();

	UGbool IsOpen() const;	

	UGFolder *GetRootFolder();
	const UGFileDisk* GetFile() const;

protected:
	UGBlockManager m_BlockManager;

	//根目录
	UGFolder m_RootFolder;

	//信息文件对象，
	//里面的所有文件和文件夹的信息都保存在这里
	UGFileLogical m_InfoFile;

private:
	UGFileDisk* m_pFile;
	
	UGuint m_nOpenFlag;
};

}
#endif // !defined(AFX_SMSTOREHOUSE_H__813097E5_AA81_4CF3_991C_4BCA52D7800F__INCLUDED_)
