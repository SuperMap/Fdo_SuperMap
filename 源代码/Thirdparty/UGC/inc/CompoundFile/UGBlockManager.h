/*! \file UGBlockManager.h
 *  \brief 块分配和管理类.
 *  \author 郭其超,陈俊华
 *  \bug

 *	<b>更新说明：</b>\n
	<em>1、2003-11-1 首次完成代码编写.\n</em>
*/   

#if !defined(AFX_SMSSBLOCKMANAGER_H__66F92503_D443_4EA0_926B_637F819C18D3__INCLUDED_)
#define AFX_SMSSBLOCKMANAGER_H__66F92503_D443_4EA0_926B_637F819C18D3__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGArray.h"
#include "UGFileDisk.h"

namespace UGC{


///	\brief	UGBlockManager，提供文件块的分配，管理和回收功能。
/// \remark	块的大小可以根据数据情况设置，默认是8k。
class UGBlockManager  
{
	friend class UGStorehouse;
public:
	///	\brief 默认构造函数
	UGBlockManager();
	///	\brief 默认析构函数
	virtual ~UGBlockManager();

private:
	///	\brief 拷贝构造函数，不实现
	UGBlockManager(const UGBlockManager &src);
	///	\brief 默认赋值操作，不实现 
	UGBlockManager &operator=(const UGBlockManager &src);

public:
	/// \brief 申请多个块
	/// \param nBlockCount 申请分配的块数
	/// \param arBlockNums 分配出来的块的ID数组
	/// \return 分配成功则返回true,否则返回false.
	/// \remarks 如果有空块就利用后面的空块，空块不够就到文件最后分配
	UGbool AllocBlock( UGint nBlockCount, UGArray<UGint>& arBlockNums );

	/// \brief 释放一个块
	/// \param nBlockID 需要释放的块的ID
	/// \return 成功则返回true,否则返回false
	/// \remarks 释放块并没有释放文件空间，可以下次继续分配出来使用。
	UGbool FreeBlock( UGint nBlockID );	

public: //inline 函数
	
	/// \brief 获取对象占内存的字节数
	/// \return 对象占内存的字节数
	UGint GetSize();

	/// \brief 获取文件的指针
	/// \return 文件的指针
	/// \remarks 外部不能删除获取出来的指针
	/// \remark inline函数
	UGFileDisk *GetFile() const;

	/// \brief 获取分块的字节数
	/// \return 分块的字节数
	/// \remarks 分块的字节数在创建文件的时候指定，以后不能修改。
	/// \remark inline函数
	UGint GetBlockSize() const;

	/// \brief 获取分块数量
	/// \return 分块数量
	/// \remarks 包括已经使用的块和空的块
	/// \remark inline函数
	UGint GetBlockCount() const;

protected: 
	/// \brief 文件指针
	UGFileDisk *m_pFile;

	/// \brief 空块序号数组
	UGArray<UGint> m_arFreeBlocks;

	/// \brief 总块数,包括已经使用的块和空的块。	
	UGint m_nBlocksCount;

	/// \brief 块的大小
	UGint m_nBlockSize;
};


inline UGFileDisk *UGBlockManager::GetFile() const
{
	return m_pFile;
}

inline UGint UGBlockManager::GetBlockCount() const
{
	return m_nBlocksCount;
}

inline UGint UGBlockManager::GetBlockSize() const 
{
	return m_nBlockSize;
}

}

#endif // !defined(AFX_SMBLOCKMANAGER_H__66F92503_D443_4EA0_926B_637F819C18D3__INCLUDED_)
