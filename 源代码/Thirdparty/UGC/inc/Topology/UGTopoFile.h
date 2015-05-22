#ifndef UGTOPOFILE_H
#define UGTOPOFILE_H

#include "Base/UGStream.h"

namespace UGC {
	
class TOPOLOGY_API UGTopoFile
{
public:
	UGTopoFile();
	virtual ~UGTopoFile();
	
	virtual UGbool Open() = 0;
	
	//{{//////////////////////////////////////////////////////////////
	//dRecordSize为文件记录大小，dRecordsCount为记录数
	//文件总长度为(dRecordsCount * dRecordSize)
	virtual void Set(UGuint dwRecordSize, UGuint dwRecordsCount) = 0;
	//}}//////////////////////////////////////////////////////////////
	
	// lOff	为记录数偏移量，nFrom 参数CFile::Seek
	virtual UGint Seek(UGint lOff, UGuint nFrom = UGFromStart) = 0;
	
	//{{此函数将改变当前文件指针的位置到文件开始///////////////////
	//dwNewLen为记录数
	virtual void SetLength(UGuint dwNewLen) = 0;
	//}}///////////////////////////////////////////////////////////
	//返回记录数
	virtual UGuint GetLength() const = 0;
	
	//nCount为读取的记录数
	virtual void Read(void* lpBuf, UGuint nCount = 1) = 0;
	//nCount为写入的记录数
	virtual void Write(const void* lpBuf, UGuint nCount = 1) = 0;
	
	//nIndex为记录索引号（以0为开始），nCount为读取的记录数
	virtual void ReadAt(void* lpBuf, UGuint nIndex, UGuint nCount = 1) = 0;
	//nIndex为记录索引号（以0为开始），nCount为写入的记录数
	virtual void WriteAt(const void* lpBuf, UGuint nIndex, UGuint nCount = 1) = 0;
	
	virtual void Flush() = 0;
	virtual void Close() = 0;
	
protected:
	UGuint m_dwRecordSize;
	UGuint m_dwRecordsCount;
	UGuint m_nCurrentIndex;
};

}

#endif
