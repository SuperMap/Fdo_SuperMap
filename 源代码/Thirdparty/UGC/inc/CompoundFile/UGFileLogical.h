/*============================================================
 项目名：                   eSuperMap 2.0
 单  位：                   北京超图地理信息技术有限公司
 最后修改时间：				以文件日期为准
-------------------------------------------------------------------------------------
 重要声明：                1. 类库使用范围为eSuperMap GIS软件开发组成员，未经许可不得擅自传播。
                           2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
-------------------------------------------------------------------------------------
 文件名：                   SeFile.h SeFile.cpp
 类  名：                   UGFileLogical
 父  类：                   无
 子  类：                   无
 功能说明：                 pmf逻辑文件类
 调用说明：                 
 注意：                  
============================================================*/

#if !defined(AFX_SMSSFile_H__381A7817_0336_4A9F_8F9E_A36ADFDED596__INCLUDED_)
#define AFX_SMSSFile_H__381A7817_0336_4A9F_8F9E_A36ADFDED596__INCLUDED_

#include "Base/UGString.h"
#include "Base/UGArray.h"

namespace UGC {

const UGchar T_FOLDER = 0x01;
const UGchar T_FILE = 0x10;

class UGBlockManager;
class UGFolder;

// modified by zengzm 2007-4-7 UGFile和Base中UGFile 重名, 因此换一个名字
//class COMPOUNDFILE_API UGFile
class COMPOUNDFILE_API UGFileLogical
{
	friend class UGStorehouse;
public:
	UGFileLogical();
	~UGFileLogical();

private:
	UGFileLogical(const UGFileLogical& src);	
	UGFileLogical& operator =(const UGFileLogical &src);
	void ApplyBlock( UGint nCount = 1 );

public:
	
	void Destroy();
	
	void WriteInfo(UGFileLogical *pInfoFile , UGint nVersion);
	
	void ReadInfo(UGFileLogical *pInfoFile ,  UGint nVersion);

	//打开保存了块信息的文件
	UGbool Open( const UGString& strFileName, const UGFolder* pFolder);

	UGuint Read( void* lpBuf, UGuint nCount );
	
	void Write( const void* lpBuf, UGuint nCount );

	//读取大块数据(超过一个block size)
	

	//在内存中修改的内容保存到文件
	void Flush();
	
	void Close();
	
	UGuint SeekToEnd();
	
	void SeekToBegin();

	UGuint Seek( UGint lOff, UGuint nFrom );
	
	UGuint GetLength() const;

	void SetLength( UGuint dwNewLen );
	
	void SetFileName( const UGString& strNewName );
	
	UGString GetFileName() const;
	
	UGuint GetPosition() const;	
	
	UGbool IsOpen();

	void SetBlockManager( UGBlockManager* pBlockManager );

	UGint GetSize() const;

public://static functions

	//size 保存字符所占字节数，
	static UGbool ReadString(UGFileLogical *pFile,UGString & strInfo);

	//先写入字符所占字节数
	static UGbool WriteString(UGFileLogical *pFile,UGString & strInfo);

protected:	
	//文件名，保存在信息文件里
	UGString m_strName;
		
	//文件指针的位置
	UGint m_nPosition;

	//文件的大小
	UGint m_nLength;

	//最后一个数据块剩余空间
	UGint m_nLastBlank;

	//是否打开的标志
	UGbool m_bOpen;

	//缓冲区---------------------------------------------
	UGuchar *m_pDataBuffer;

	//正在读取的块的索引
	UGint m_nCachedBlockIndex;

	//文件占用块的信息，保存在信息文件里
	UGArray<UGint> m_arBlocks;
	
	//块管理器的指针
	UGBlockManager* m_pBlockManager;
};

inline UGuint UGFileLogical::GetPosition() const
{
	return m_nPosition;
}

inline UGString UGFileLogical::GetFileName() const
{
	return m_strName;
}
	
inline UGuint UGFileLogical::SeekToEnd()
{
	m_nPosition = m_nLength;
	return m_nPosition;
}

inline void UGFileLogical::SeekToBegin()
{
	m_nPosition = 0;
}

inline UGuint UGFileLogical::GetLength() const
{
	return m_nLength;
}

inline void UGFileLogical::SetBlockManager(UGBlockManager* pBlockManager)
{
	m_pBlockManager = pBlockManager;
}

}
#endif // !defined(AFX_SeFile_H__381A7817_0336_4A9F_8F9E_A36ADFDED596__INCLUDED_)
