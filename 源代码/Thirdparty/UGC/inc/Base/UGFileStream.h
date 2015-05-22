/* 	\file UGFileStream.h
	\brief 文件流类
	\author Fox、艾国、曾志明
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
	\sa UGStream UGMemoryStream。
*/

/*	修改记录 1
	修改人：曾志明
	修改原因：增加对超过4G的流的管理
	具体修改：把Position从int32改为int64
	修改时间：2004-7-12

   修改记录 2
	修改人：  艾国
	修改原因：增加对文件的双向的操作，也增加了一些接口，修改了原来一些bug，同时进行了性能的优化
	具体修改：具体看头文件的注释
	最后修改时间：2005-6-17
*/

#ifndef UGFILESTREAM_H
#define UGFILESTREAM_H
#include "UGStream.h"

namespace UGC {

//! \brief 文件流类
/**	如果用UGStreamSave模式打开文件时，只能往文件中保存内容，不能在文件中读取数据，
如果用UGStreamLoad模式打开文件时，只能读取文件，只有用UGStreamLoadSave模式打开文件即可以读也可以写。
（1）、用只写模式打开
 UGFileStream fileStream;
 UGString strFileName  = "D:/Data/file/fileStreamLoad.txt";
 UGchar pch[10];
 for( i = 0; i < 10; i++)
 {
  pch[i] = 'a' + i;
 }
 if (fileStream.Open(strFileName, UGStreamSave)) //如果文件存在，文件里的内容将丢失
 {
  fileStream.Save(pch, 10);//正确
  fileStream.SetPosition(5, UGFromStart);
  fileStream.Load(pch, 4); //这样就会产生错误
  fileStream.Close();
 }
（2）、用只写模式打开
 UGFileStream fileStream;
 UGString strFileName  = "D:/Data/file/fileStreamLoad.txt";
 UGchar pch[10];
 for( i = 0; i < 10; i++)
 {
  pch[i] = 'a' + i;
 }
 if (fileStream.Open(strFileName, UGStreamLoad)) 
 {
  fileStream.Load(pch, 10);//正确
  fileStream.Save(pch, 4); //错误，这里不能把此内容写进文件里
  fileStream.Close();
 }
（3）、用读写模式打开
 UGFileStream fileStream;
 UGString strFileName  = "D:/Data/file/fileStreamLoad.txt";
 UGchar pch[10];
 for( i = 0; i < 10; i++)
 {
  pch[i] = 'a' + i;
 }
 if (fileStream.Open(strFileName, UGStreamLoadSave))
 {
  fileStream.Save(pch, 10); //把pch中的内容保存在文件里，如果原来文件存在，并且文件中有内容，会修改原来的内容
  fileStream.SetPosition(0, UGFromStart);
  fileStream.Load(pch, 10);//正确
  fileStream.Close();
 }
*/
class BASE_API UGFileStream : public UGStream  
{
public:	
	UGFileStream();
	virtual ~UGFileStream();	
	
	//! \brief 打开文件流。
	/** \param filename 指定文件名[in]。
		\param save_or_load 指定打开的方式，只读、只写或读写[in]。
		\param size 缓存的大小[in]。
	*/
	UGbool Open(const UGchar* filename, UGStreamDirection save_or_load, UGuint size=8192);			

	//! \brief 关闭文件流。
	virtual UGbool Close();
	
	//! \brief 设置文件指针的位置，如果超过文件大小，会导致文件增长。
	/** \param offset 偏移量[in]。
		\param whence 起始位置[in]。
	*/
	virtual UGbool SetPosition(UGlong offset,UGWhence whence=UGFromStart);	
	
	//! \brief 得到文件长度 add by aiguo
	virtual UGulong GetLength();

	// added by zengzm 2005-09-09
	//! \brief 判断是否已到文件尾
	virtual UGbool IsEOF() const;


	//! \brief 判断文件流是否处于打开状态。
	/** \return 打开状态返回true,关闭状态返回false。
	*/
	UGbool IsOpen() const;

	/// Save single items to stream
	UGFileStream& operator<<(const UGuchar& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGchar& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGushort& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGshort& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGuint& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGint& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGfloat& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGdouble& v){ UGStream::operator<<(v); return *this; }
#ifdef UG_LONG
	UGFileStream& operator<<(const UGlong& v){ UGStream::operator<<(v); return *this; }
	UGFileStream& operator<<(const UGulong& v){ UGStream::operator<<(v); return *this; }
#endif
	
	/// Save arrays of items to stream
	UGFileStream& Save(const UGuchar* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGchar* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGushort* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGshort* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGuint* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGint* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGfloat* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGdouble* p,UGuint n){ UGStream::Save(p,n); return *this; }
#ifdef UG_LONG
	UGFileStream& Save(const UGlong* p,UGuint n){ UGStream::Save(p,n); return *this; }
	UGFileStream& Save(const UGulong* p,UGuint n){ UGStream::Save(p,n); return *this; }
#endif
	
	/// Load single items from stream
	UGFileStream& operator>>(UGuchar& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGchar& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGushort& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGshort& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGuint& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGint& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGfloat& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGdouble& v){ UGStream::operator>>(v); return *this; }
#ifdef UG_LONG
	UGFileStream& operator>>(UGlong& v){ UGStream::operator>>(v); return *this; }
	UGFileStream& operator>>(UGulong& v){ UGStream::operator>>(v); return *this; }
#endif
	
	/// Load arrays of items from stream
	UGFileStream& Load(UGuchar* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGchar* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGushort* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGshort* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGuint* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGint* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGfloat* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGdouble* p,UGuint n){ UGStream::Load(p,n); return *this; }
#ifdef UG_LONG
	UGFileStream& Load(UGlong* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGFileStream& Load(UGulong* p,UGuint n){ UGStream::Load(p,n); return *this; }
#endif

private:
	UGint file;
protected:
	virtual UGuint WriteBuffer(UGuint count);
	virtual UGuint ReadBuffer(UGuint count);
	//{{Add by aiguo 主要是解决在UGStreamLoadSave模式下，Load和Save混乱的问题，这里主要是设置一些标志来控制Load和Save.
	virtual void SetSignLoadSave(UGint nSign);
	//}}
};

}

#endif

