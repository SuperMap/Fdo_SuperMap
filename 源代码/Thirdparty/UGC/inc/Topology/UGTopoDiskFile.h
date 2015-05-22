#ifndef UGTOPODISKFILE_H
#define UGTOPODISKFILE_H

#include "Base/UGFileStream.h"
#include "Topology/UGTopoFile.h"

namespace UGC {

class TOPOLOGY_API UGTopoDiskFile : public UGTopoFile  
{
	UGFileStream m_DiskFile;
public:
	UGTopoDiskFile();
	virtual ~UGTopoDiskFile();
	
	UGchar m_TmpPath[255];
	UGchar m_TempFileName[255];
	
	//! \brief创建临时文件
	UGbool Open();
	//{{//////////////////////////////////////////////////////////////
	//! \brief 设置文件记录大小和记录数
	//! \details 文件总长度为(dRecordsCount * dRecordSize)
	//! \param dRecordSize 文件记录大小
    //! \param dRecordsCount 文件记录数
	void Set(UGuint dwRecordSize, UGuint dwRecordsCount);
	//}}//////////////////////////////////////////////////////////////
	
	//! \brief 偏移
	//! \param lOff 记录数偏移量
    //! \param nFrom 偏移的起始位置CFile::Seek
	UGint Seek(UGint lOff, UGuint nFrom = UGFromStart);
	
	//{{此函数将改变当前文件指针的位置到文件开始///////////////////
	//! \param dwNewLen 记录数
	void SetLength(UGuint dwNewLen);
	//}}///////////////////////////////////////////////////////////
	//！ \brief 返回记录数
	UGuint GetLength() const;
	
	//! \param nCount 读取的记录数
	void Read(void* lpBuf, UGuint nCount = 1);
	//! \param nCount 写入的记录数
	void Write(const void* lpBuf, UGuint nCount = 1);
	
	//! \param nIndex 记录索引号（以０为开始）
    //! \param nCount 读取的记录数
	void ReadAt(void* lpBuf, UGuint nIndex, UGuint nCount = 1);
	//! \param nIndex 记录索引号（以０为开始）
    //! \param nCount 写入的记录数
	void WriteAt(const void* lpBuf, UGuint nIndex, UGuint nCount = 1);
	
	void * operator[](UGuint nIndex);
	void Flush();
	void Close();
};

}

#endif
