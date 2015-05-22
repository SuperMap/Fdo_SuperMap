// UGFileDisk.h: interface for the UGFileDisk class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEDISK_H__4F97CCA5_FFAB_4C66_AEED_9A8EA686FDDE__INCLUDED_)
#define AFX_UGFILEDISK_H__4F97CCA5_FFAB_4C66_AEED_9A8EA686FDDE__INCLUDED_

#include "Base/UGString.h"
#include "Base/UGFileStream.h"

namespace UGC{

class COMPOUNDFILE_API UGFileDisk  
{
public:
	UGFileDisk();
	~UGFileDisk();
protected:
	// modified by zengzm 2007-4-6 还是用以前的file来实现, 这个东东是复合文档用, 也不要求跨平台,用FileStream隐患太大
	// modified by zengzm 2007-3-26 用UGFileStream来实现
	int m_file;
	//UGFileStream m_file;

public:
	UGbool Open(const UGString& strName, UGStreamDirection nDirection);
	UGbool IsOpen() const;
	void Close();

	UGlong Seek(UGlong nOffset,UGWhence whence);
	UGlong GetPosition();
	UGlong GetLength();
	void SetLength(UGlong nLength);
	
	UGint Read(UGuchar* p,UGint nSize);
	void Write(UGuchar* p,UGint nSize);

	UGbool Flush();
};

}
#endif // !defined(AFX_UGFILEDISK_H__4F97CCA5_FFAB_4C66_AEED_9A8EA686FDDE__INCLUDED_)
