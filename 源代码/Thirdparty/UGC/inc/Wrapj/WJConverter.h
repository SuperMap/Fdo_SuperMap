#pragma once

#include "WrapJ.h"
#include "Wrapj/License/UGLicense.h"

class CWJConverter
{
private:
	CWJConverter(void);
	~CWJConverter(void);

	//JNI to UGC Type
public:
	inline static UGbool ToUGBoolean(jboolean value)
	{
		return (UGbool)value;
	};
	
	inline static UGbyte ToUGByte(jbyte value)
	{
		return (UGbyte)value;
	};
	

	inline static UGint ToUGInt(jint value)
	{
		return (UGint)value;
	};
	
	inline static UGlong ToUGLong(jlong value)
	{
		return (UGlong)value;
	};
		
	inline static UGshort ToUGShort(jshort value)
	{
		return (UGshort)value;
	};
	
	inline static UGdouble ToUGDouble(jdouble value)
	{
		return (UGdouble)value;
	};
	
	
	inline static UGfloat ToUGFloat(jfloat value)
	{
		return (UGfloat)value;
	};
		
	inline static UGColor ToUGColor(jint value)
	{
		UGint color = ToUGInt(value);
		color &= 0x00FFFFFF;
		UGint r = (color & 0x00FF0000) >> 16;
		UGint g = (color & 0x0000FF00) >> 8;
		UGint b = color & 0x000000FF;
		color = UGRGB((UGchar)r,(UGchar)g,(UGchar)b);
		return (UGColor) color;
	};
	
	//这是一般情况下的转换用函数
	static UGString ToUGString(JNIEnv * env, const jstring& value);
	//这个函数只是给查询专用的，因为查询的时候，数据集的编码与当前字符的编码不一定相同
	//如果涉及到给UGQueryDef.m_strFilter赋值的操作,都用这个转换
	static UGString ToUGStringOnlyForQuery(JNIEnv * env, const jstring& value);

	
	
	//UGC to JNI Type
public:
	inline static jboolean ToJniBoolean(UGbool value)
	{
		return (jboolean)value;
	};

	inline static jbyte ToJniByte(UGbyte value)
	{
		return (jbyte)value;
	};
		
	inline static jint ToJniInt(UGint value)
	{
		return (jint)value;
	};

	inline static jlong ToJniLong(UGlong value)
	{
		return (jlong)value;
	};

	inline static jshort ToJniShort(UGshort value)
	{
		return (jshort)value;
	};

	inline static jdouble ToJniDouble(UGdouble value)
	{
		return (jdouble)value;
	};

	inline static jfloat ToJniFloat(UGfloat value)
	{
		return (jfloat)value;
	};

	inline static jint ToJniColor(UGColor value)
	{		
		 
		UGint r = UGREDVAL(value);		
		UGint g = UGGREENVAL(value);
		UGint b = UGBLUEVAL(value);
		UGint color = (0xFF000000) | (r<<16) | (g<<8) |(b);
		return ToJniInt(color);
	};
	
	inline static jstring ToJavaTime(JNIEnv * env,UGTime &ugTime)
	{
		UGString strTime = ugTime.Format("%Y-%m-%d %H:%M:%S");
		return CWJConverter::ToJniString(env,strTime);
	}
	
	inline static UGTime ToUGTime(JNIEnv * env,jstring javaTime)
	{
		UGString strTime = CWJConverter::ToUGString(env,javaTime);
		UGTime ugTime;
		ugTime.ParseDateTime(strTime,"%Y-%m-%d %H:%M:%S");
		return ugTime;
	}
	
	static jstring ToJniString(JNIEnv * env, UGString& value);

	//static UGint *ToJniBits(UGImage *pImage);
	
	//static void SplitString(UGString str,UGString strSplit);
	static UGString JoinString(const UGStrings &arr,UGString strJoin);

	static Module ParseObjectsDevelopModule(UGString module);

	static Module ParseObjectsRuntimeModule(UGString module);

	static Module ParseObjectsModule(UGString module);
	
};
