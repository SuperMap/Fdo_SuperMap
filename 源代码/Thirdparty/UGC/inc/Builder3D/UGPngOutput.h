// UGPngOutput.h: interface for the UGPngOutput class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGPNGOUTPUT_H__22587CC6_DCEE_4C06_8353_FB059129ED2C__INCLUDED_)
#define AFX_UGPNGOUTPUT_H__22587CC6_DCEE_4C06_8353_FB059129ED2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGFileStream.h"
#include "png.h"
#include "Base/UGMemoryStream.h"
namespace UGC
{

class BUILDER3D_API UGPngOutput  
{
public:
	UGPngOutput();
	virtual ~UGPngOutput();
	// 输出成32位png
	UGbool OutputDirect(UGString strFileName,UGuchar* pData,UGint nWidth,UGint nHeight);
	
private:
	
	UGFileStream m_FilePng;
	png_structp m_pPngStruct;
	png_infop m_pPngInfo;
	png_colorp m_pPngPalette;
	UGbool m_bRead;		//读还是写？
	UGMemoryStream m_MemoryStream;
	//! \brief 是否是OutputDirect函数调用SavePngHeader()函数，因为OutputDirect调用就需要特殊处理，把RGBA->RGB,数据转换就不需要了
	UGbool m_bOutputDirect;
private:
	void Close();
	UGbool OpenForWrite(const UGString& strFileName,UGint nWidth,UGint nHeight);
	//! \brief 保存Png的文件头
	UGbool SavePngHeader(int nWidth,int nHeight);
	 

};
}

#endif // !defined(AFX_UGPNGOUTPUT_H__22587CC6_DCEE_4C06_8353_FB059129ED2C__INCLUDED_)
