#ifndef TOPOMEMFILE_H
#define TOPOMEMFILE_H

#include "Base/UGMemoryStream.h"
#include "Topology/UGTopoFile.h"

namespace UGC {

class TOPOLOGY_API UGTopoMemFile : public UGTopoFile
{
	//UGMemoryStream m_MemFile;
	UGMemoryStream m_loadFile;
	UGMemoryStream m_saveFile;
	UGuchar * m_pBuffer;
public:
	UGTopoMemFile();
	virtual ~UGTopoMemFile();
	
	UGbool Open();

	//{{//////////////////////////////////////////////////////////////
	//dRecordSize为文件记录大小，dRecordsCount为记录数
	//文件总长度为(dRecordsCount * dRecordSize)
	void Set(UGuint dwRecordSize, UGuint dwRecordsCount);
	//}}//////////////////////////////////////////////////////////////

	// lOff	为记录数偏移量，nFrom 参数CFile::Seek
	UGint Seek(UGint lOff, UGuint nFrom = UGFromStart);

	//{{此函数将改变当前文件指针的位置到文件开始///////////////////
	//dwNewLen为记录数
	void SetLength(UGuint dwNewLen);
	//}}///////////////////////////////////////////////////////////
	//返回记录数
	UGuint GetLength() const;
	
	//nCount为读取的记录数
	void Read(void* lpBuf, UGuint nCount = 1);
	//nCount为写入的记录数
	void Write(const void* lpBuf, UGuint nCount = 1);

	//nIndex为记录索引号（以０为开始），nCount为读取的记录数
	void ReadAt(void* lpBuf, UGuint nIndex, UGuint nCount = 1);
	//nIndex为记录索引号（以０为开始），nCount为写入的记录数
	void WriteAt(const void* lpBuf, UGuint nIndex, UGuint nCount = 1);

	void Flush();
	void Close();
};

}

#endif
