/* 
	\file UGMemoryStream.h
	\brief 内存流类
	\author Fox、艾国、曾志明
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
	\sa UGStream UGFileStream。
*/

/*	修改记录 1
	修改人：曾志明
	修改原因：增加对超过4G的流的管理
	具体修改：把Position从int32改为int64
	修改时间：2004-7-12

    修改记录 2
	修改人：  艾国
	修改原因：增加对流的双向的操作，也增加了一些接口，修改了原来一些bug，同时进行了性能的优化
	具体修改：具体看头文件的注释
	最后修改时间：2005-6-17

*/

#ifndef UGMEMORYSTREAM_H
#define UGMEMORYSTREAM_H
#include "UGStream.h"

namespace UGC {

//! \brief 内存流
/**	\remarks 使用方法：
1，外面分配内存，用内存流来操作这块内存，例如：
 {
  UGint i = 0;
  UGuchar pch[20];
  UGuchar pch2[20];
  for(i = 0; i < 20; i++)
  {
   pch2[i] = 'z' -i; 
  }
  UGMemoryStream memStream;
  if (memStream.Open(UGStreamSave, 20, pch))
  {
   memStream.Save(pch2, 20);
   nPos =  memStream.GetPosition();
   memStream.Close();
  }
 }

2，流内部分配内存，这块内存随着内容的增加而增加，例如：
 {
  UGint i = 0;
  UGuchar pch[20];
  for(i = 0; i < 20; i++)
  {
   pch[i] = 'z' -i; 
  }
  UGMemoryStream memStream;
  if (memStream.Open(UGStreamSave, NULL))
  {
   memStream.SetSpace(20); //设置缓存的大小
   memStream.Save(pch, 20);   
   memStream.Close();
  }
 }

 2，用读写方式操作内存流，例如：
 UGMemoryStream stream;
 stream.Open(UGStreamLoadSave);
 UGString str = "abc";
  stream << str;
 stream.SetPosition(0);
 UGString str2;
 stream >> str2;
 assert(str1 == str2);
*/
class BASE_API UGMemoryStream : public UGStream 
{
private:
	// added by zengzm 20087-4-26 定义出来, 不实现, 特意不能使用
	UGMemoryStream(const UGMemoryStream& ms);
	UGMemoryStream& operator=(const UGMemoryStream& ms);

public:	
	UGMemoryStream();		

	//{{封掉这俩个接口 by aiguo
	//UGbool Open(UGStreamDirection save_or_load,UGuchar* data);	
	//UGbool Open(UGStreamDirection save_or_load, UGuint size, UGuchar* data);
	//}}封掉这俩个接口 by aiguo

	//========================================================
	//! \brief 		打开内存流，可以指定每次分配buffer的size，也可以用户传入一个内存
	//! \return 	UGbool    正确返回True，错误返回False
	//! \param 		save_or_load 打开的模式，现在支持三种模式，only save, only load and saveOrload
	//! \param 		size  分配buffer大小，这个对提高性能很重要，内存流的大小每次以size增长
	//! \param 		data  这个参数也很重要，用户可以外面传进来一快内存，用内存流来操作这块内存，
	//                         如果用户传进来一块内存，那么就要和size协同工作，size就是外面传进来的大小
	//! \remarks 	打开内存流，可以指定每次buffer增长的size，也可以用户传入一个内存
	UGbool Open(UGStreamDirection save_or_load, UGuint size=1024, UGuchar* data=NULL);	


	//========================================================
	//! \brief 		得到内存流的指针data和整个buffer的长度
	//              同时要警告路人的是:Take出的内存外面必须负责释放,否则会内存泄露
	//! \return 	void  没有返回值
	//! \param 		data  返回内存流的数据指针
	//! \param 		size  返回整个buffer的size(这里需要注意:是整个buffer的大小,不是实际数据的长度)
	//					  实际数据长度可调用GetLength得到；
	//					  如果是Save模式，还可以调用GetPosition来获得已经存储的数据的大小
	//! \remarks 	得到内存流的指针data和整个buffer的长度	
	void TakeBuffer(UGuchar*& data,UGuint& size);	


	//========================================================
	//! \brief 		外面给内存流一块内存，这时内存流会 把原来内存流中的数据释放
	//! \return 	void
	//! \param 		*data  外面给出的一块内存不能为空
	//! \param 		size   给出这块内存的大小，
	//! \remarks 	要注意的是：外面这块内存交给了内存流，内存流就负责为维护它，当然包括释放了！！！
	//              那么你就会问：如果外面是一块堆栈中的东东，那么后果不就严重了吗？？？？
	//              那你会问：那怎么办，没有办法了吗？？？
	//              呵呵，办法是有的， 拿出你的秘密武器TakeBuffer了，把这块内存交给外面来管理，这样不就可以了！好象很难用啊！！！
	void GiveBuffer(UGuchar *data,UGuint size);	


	//========================================================
	//! \brief 		关闭流
	//! \return 	UGbool 成功返回True,失败返回False
	virtual UGbool Close();	


	//========================================================
	//! \brief 		设置当前指针的位置。
	/** \remark		如果要设置的位置超过内存空间大小，且内存由流所有，会导致内存空间重新分配，
		内存空间不为流所有，则流会处于Full状态
		\param offset 偏移量[in]。
		\param whence 偏移量的起始位置[in]。
	*/
	virtual UGbool SetPosition(UGlong offset,UGWhence whence=UGFromStart);


	//========================================================
	//! \brief 		得到流中实际有效数据的长度（小于等于内存空间） add by aiguo
	virtual UGulong GetLength();


	//========================================================
	//! \brief 		得到内存流中的数据指针, 这个路人要注意的是: 外面可以用此数据,可以通过GetLength来得到数据的长度 
	//              外面不需要释放, 当关闭流会自动释放这块内存
	//! \return 	UGuchar*  返回内存流的首地址
	//! \remarks 	得到内存流中的数据指针,如果实际数据长度为0, 返回NULL指针	
	virtual UGuchar* GetData() const;
		
	UGMemoryStream& operator<<(const UGuchar& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGchar& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGushort& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGshort& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGuint& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGint& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGfloat& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGdouble& v){ UGStream::operator<<(v);  return *this; }
#ifdef UG_LONG
	UGMemoryStream& operator<<(const UGlong& v){ UGStream::operator<<(v);  return *this; }
	UGMemoryStream& operator<<(const UGulong& v){ UGStream::operator<<(v);  return *this; }
#endif
	
	/// Save arrays of items to stream
	UGMemoryStream& Save(const UGuchar* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGchar* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGushort* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGshort* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGuint* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGint* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGfloat* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
	UGMemoryStream& Save(const UGdouble* p,UGuint n){ UGStream::Save(p,n);  return *this;  }
#ifdef UG_LONG
	UGMemoryStream& Save(const UGlong* p,UGuint n){ UGStream::Save(p,n);  return *this; }
	UGMemoryStream& Save(const UGulong* p,UGuint n){ UGStream::Save(p,n);  return *this; }
#endif
	
	/// Load single items from stream
	UGMemoryStream& operator>>(UGuchar& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGchar& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGushort& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGshort& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGuint& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGint& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGfloat& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGdouble& v){ UGStream::operator>>(v); return *this; }
#ifdef UG_LONG
	UGMemoryStream& operator>>(UGlong& v){ UGStream::operator>>(v); return *this; }
	UGMemoryStream& operator>>(UGulong& v){ UGStream::operator>>(v); return *this; }
#endif
	
	/// Load arrays of items from stream
	UGMemoryStream& Load(UGuchar* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGchar* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGushort* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGshort* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGuint* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGint* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGfloat* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGdouble* p,UGuint n){ UGStream::Load(p,n); return *this; }
#ifdef UG_LONG
	UGMemoryStream& Load(UGlong* p,UGuint n){ UGStream::Load(p,n); return *this; }
	UGMemoryStream& Load(UGulong* p,UGuint n){ UGStream::Load(p,n); return *this; }
#endif
	
protected:
	virtual UGuint WriteBuffer(UGuint count);
	virtual UGuint ReadBuffer(UGuint count);
	
	//{{Add by aiguo 主要是解决在UGStreamLoadSave模式下，Load和Save混乱的问题，这里主要是设置一些标志来控制Load和Save.
	virtual void SetSignLoadSave(UGint nSign);
	//}}

	//{{add by aiguo 为了提高效率增加的变量， 原来实现的效率太慢，原因是：
	//如果写入的字节长度大于当前的buffer时，重新分配的大小是原来的大小加上当前要写入的大小，这样效率就比较低
	//举一个极端的例子，如果每次写一个字节进去，那么每次都需要重新分配空间，这样会很慢的，看来fox也不过如此，呵呵！
	UGint m_nBufferSize;
	//}}为了提高效率增加的变量， 原来实现的效率太慢
};

}

#endif

