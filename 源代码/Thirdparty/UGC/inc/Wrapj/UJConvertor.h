// UJConvertor.h: interface for the UJConvertor class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UJCONVERTOR_H__62F918C3_6484_4EC5_83D3_A65708BEC9C3__INCLUDED_)
#define AFX_UJCONVERTOR_H__62F918C3_6484_4EC5_83D3_A65708BEC9C3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Wrapj/SuperMapStubH.h"

class UJConvertor  
{
public:
	UJConvertor();
	virtual ~UJConvertor();
public:
	inline static UGbool ToUGBoolean(jboolean value)
	{
		return (UGbool)value;
	};

	inline static jboolean ToJniBoolean(UGbool value)
	{
		return (jboolean)value;
	};
	
	inline static UGbyte ToUGByte(jbyte value)
	{
		return (UGbyte)value;
	};
	inline static jbyte ToJniByte(UGbyte value)
	{
		return (jbyte)value;
	};

	inline static UGint ToUGInt(jint value)
	{
		return (UGint)value;
	};
	inline static jint ToJniInt(UGint value)
	{
		return (jint)value;
	};
	
	inline static UGlong ToUGLong(jlong value)
	{
		return (UGlong)value;
	};
	inline static jlong ToJniLong(UGlong value)
	{
		return (jlong)value;
	};

	
	inline static UGshort ToUGShort(jshort value)
	{
		return (UGshort)value;
	};
	inline static jshort ToJniShort(UGshort value)
	{
		return (jshort)value;
	};



	inline static UGdouble ToUGDouble(jdouble value)
	{
		return (UGdouble)value;
	};
	
	inline static jdouble ToJniDouble(UGdouble value)
	{
		return (jdouble)value;
	};

	
	inline static UGfloat ToUGFloat(jfloat value)
	{
		return (UGfloat)value;
	};
	
	inline static jfloat ToJniFloat(UGfloat value)
	{
		return (jfloat)value;
	};
	
	static UGString ToUGString(JNIEnv * env, const jstring& value);
	
	static jstring ToJniString(JNIEnv * env, const UGString& value);

	inline static UGColor ToUGColor(jint value)
	{
		UGint color = ToUGInt(value);
		color &= 0x00FFFFFF;
		UGint r = (color & 0x00FF0000) >> 16;
		UGint g = (color & 0x0000FF00) >> 8;
		UGint b = color & 0x000000FF;
		//color = (r >> 16) | (g) | (b<< 16);
		color = UGRGB((UGchar)r,(UGchar)g,(UGchar)b);
		return (UGColor) color;
	};
	
	inline static jint ToJniColor(UGColor value)
	{		
		 
		UGint r = UGREDVAL(value);		
		UGint g = UGGREENVAL(value);
		UGint b = UGBLUEVAL(value);
		UGint color = (0xFF000000) | (r<<16) | (g<<8) |(b);
		return ToJniInt(color);
	};

private:
//	static UGTextCodec m_Mbcs2Ucs;
};

#endif // !defined(AFX_UJCONVERTOR_H__62F918C3_6484_4EC5_83D3_A65708BEC9C3__INCLUDED_)
