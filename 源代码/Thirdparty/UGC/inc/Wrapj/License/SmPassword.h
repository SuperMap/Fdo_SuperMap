//=====================================================================================
// 项目名：			SuperMap Foundation Class (SFC) Library 2.0
// 作  者：			宋关福,陈俊华
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//-------------------------------------------------------------------------------------
// 重要声明：		1. 类库使用范围为ActiveMap GIS软件开发组成员，未经许可不得擅自传播。
//					2. 类库使用者不得修改本文件内容，否则会导致类库使用错误。
//					
//-------------------------------------------------------------------------------------
// 文件名：			SmPassword.h
// 类  名：			CSmPassword
// 父  类：			
// 子  类：			
// 功能说明：		用于数据加密和产生序列号
// 调用说明：		
//=====================================================================================
// SmPassword.h: interface for the CSmPassword class.
#if !defined(AFX_SMPASSWORD_H__36C41F28_FE6E_43D2_A872_539AC1D3B32B__INCLUDED_)
#define AFX_SMPASSWORD_H__36C41F28_FE6E_43D2_A872_539AC1D3B32B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#pragma warning(disable:4996 4244)

class CSmPassword  
{
	friend class CSmToolkit;
	friend class CSnCreaterDlg;
public:
	
	CSmPassword();
	virtual ~CSmPassword();

public:
	//
	bool GenerateSerialNoWithExpDate(const char* pszUser, const char* pszCompany,
									 const char *pszModule, 
									 unsigned long dwUserID,
									 unsigned long nDate,
									 unsigned long nStartDate,
									 char* pszSerialNo);

public:
	unsigned long GenerateKey(const char *pw);// generate a 32 bit key according to the password(capital) 
	void GenerateStream(unsigned char *stream,unsigned long key);//generate a 256 length byte array according to the key,stream must be a 256 length array.
	void GenerateXorString(unsigned char *src,unsigned char *dest);//generate a string that every char is xor of source sting. src and dest must be a 256 length array. so src's xor is dest, dext's xor is still src.
protected:
	inline void SwapByte(unsigned char& c1,unsigned char& c2);		//swap byte c1<-->c2
};


#endif // !defined(AFX_SMPASSWORD_H__36C41F28_FE6E_43D2_A872_539AC1D3B32B__INCLUDED_)
