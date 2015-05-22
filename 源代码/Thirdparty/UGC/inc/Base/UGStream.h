/* 
	\file UGStream.h
	\brief 流的虚基类，一般作为存取函数的引用型参数，不可实例化。
	实例化时，内存流采用UGMemoryStream，文件流采用UGFileStream。
	范例程序请参考UGMemoryStream和UGFileStream头文件。
	\author Fox、艾国、曾志明
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
	\sa UGMemoryStream UGFileStream。
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

#ifndef UGSTREAM_H
#define UGSTREAM_H
#include "ugdefs.h"

namespace UGC {

//! \brief 流的操作模式
enum UGStreamDirection
{
	UGStreamDead=0,
	//! \brief 只写
	UGStreamSave=1,
	//! \brief 只读
	UGStreamLoad=2,
	//! \brief 读写
	UGStreamLoadSave = 3  //add aiguo
};

//! \brief 流的状态
enum UGStreamStatus 
{
	//! \brief 状态良好
	UGStreamOK=0,
	//! \brief 读取时已到流的尾部
	UGStreamEnd=1,
	//! \brief 写入时流已经写满
	UGStreamFull=2,
	//! \brief 流不可写
	UGStreamNoWrite=3,
	//! \brief 流不可读
	UGStreamNoRead=4,
	//! \brief 内存分配错误
	UGStreamAlloc=5,
	//! \brief 流内部的数据格式错误
	UGStreamFormat=6,
	UGStreamFailure=7
};

//! \brief 流在设置位置（SetPosition）时的起始位置。
enum UGWhence 
{
	//! \brief 开始处。
	UGFromStart=0,
	//! \brief 当前位置。
	UGFromCurrent=1,
	//! \brief 结尾处。
	UGFromEnd=2
};

//! \brief 流的虚基类，一般作为存取函数的引用型参数，不可实例化。
/**
	\remarks 实例化时，内存流采用UGMemoryStream，文件流采用UGFileStream。
*/
class BASE_API UGStream 
{
public:
	//! \brief 默认构造函数。
	UGStream();	

	//! \brief 析构函数，特意设置为纯虚函数，因为UGStream本身不可实例化。
	virtual ~UGStream()=0;	
	
	//! \brief 关闭流。
	virtual UGbool Close();
	
	//! \brief 流的刷新，仅对文件流有效，即把缓存中的内容写入到文件中。
	virtual UGbool Flush();  	

	//! \brief 得到流全部空间的大小，文件流时等同于内部缓存区的大小。
	UGuint GetSpace() const;	

	//! \brief 设置流的空间大小，内存流时只能在空间由流所有时使用，文件流时则改变缓存区大小。
	/** \param space 设置的空间大小值[in]。
		\attention 对内存流，在内存空间不由流所有时调用，会发生Assert错误。
	*/
	void SetSpace(UGuint space);  		

	//! \brief 得到当前流的状态。
	UGStreamStatus GetStatus() const { return code; }  	

	//! \brief 判断流是否已到结尾，主要供文件流使用
	virtual UGbool IsEOF() const { return code!=UGStreamOK; }  

	//! \brief 设置流已经发生了某种错误。
	/** \param err 设置的错误类型[in]。
		\remarks 一般不需要使用。
	*/
	void SetError(UGStreamStatus err);  

	//! \brief 得到流是只读、只写或者读写。
	UGStreamDirection GetDirection() const { return dir; }  	
	
	//! \brief 得到当前指针的位置，以byte为单位。
	UGulong GetPosition() const { return pos; }  
	
	//! \brief 设置当前指针的位置。
	/**
	对文件流，如果要设置的位置超过原来文件大小，会导致文件长度增加，
	对内存流，如果要设置的位置超过内存空间大小，且内存由流所有，会导致内存空间重新分配，
		内存空间不为流所有，则流会处于Full状态
		\param offset 偏移量[in]。
		\param whence 偏移量的起始位置[in]。
	*/
	virtual UGbool SetPosition(UGlong offset,UGWhence whence=UGFromStart);	
	
	//{{ Add by aiguo
	//! \brief 对于文件流，得到文件长度；对于内存流，得到流中实际有效数据的长度（小于等于内存空间）。
	virtual UGulong GetLength() { return m_lActualPos; };	
	//}}
	
	// deleted by zengzm 2006-3-9 改变是否交换字节顺序的东东太危险，还是内部自己判断，暂时封存
	// void SwapBytes(UGbool s){ swap=s; }

	//! \brief 得到是否需要进行字节顺序的交换。
	//! \remarks 我们的数据都采用LittleEndian方式存储，在BigEndian的CPU中需要进行字节顺序交换。
	UGbool SwapBytes() const; 	
	
	UGStream& operator<<(const UGuchar& v);
	UGStream& operator<<(const UGchar& v){ return *this << reinterpret_cast<const UGuchar&>(v); }
	UGStream& operator<<(const UGushort& v);
	UGStream& operator<<(const UGshort& v){ return *this << reinterpret_cast<const UGushort&>(v); }
	UGStream& operator<<(const UGuint& v);
	UGStream& operator<<(const UGint& v){ return *this << reinterpret_cast<const UGuint&>(v); }
	UGStream& operator<<(const UGfloat& v){ return *this << reinterpret_cast<const UGuint&>(v); }
	UGStream& operator<<(const UGdouble& v);
#ifdef UG_LONG
	UGStream& operator<<(const UGlong& v){ return *this << reinterpret_cast<const UGdouble&>(v); }
	UGStream& operator<<(const UGulong& v){ return *this << reinterpret_cast<const UGdouble&>(v); }
#endif
	
	UGStream& Save(const UGuchar* p,UGuint n);
	UGStream& Save(const UGchar* p,UGuint n){ return Save(reinterpret_cast<const UGuchar*>(p),n); }
	UGStream& Save(const UGushort* p,UGuint n);
	UGStream& Save(const UGshort* p,UGuint n){ return Save(reinterpret_cast<const UGushort*>(p),n); }
	UGStream& Save(const UGuint* p,UGuint n);
	UGStream& Save(const UGint* p,UGuint n){ return Save(reinterpret_cast<const UGuint*>(p),n); }
	UGStream& Save(const UGfloat* p,UGuint n){ return Save(reinterpret_cast<const UGuint*>(p),n); }
	UGStream& Save(const UGdouble* p,UGuint n);
#ifdef UG_LONG
	UGStream& Save(const UGlong* p,UGuint n){ return Save(reinterpret_cast<const UGdouble*>(p),n); }
	UGStream& Save(const UGulong* p,UGuint n){ return Save(reinterpret_cast<const UGdouble*>(p),n); }
#endif
	
	UGStream& operator>>(UGuchar& v);
	UGStream& operator>>(UGchar& v){ return *this >> reinterpret_cast<UGuchar&>(v); }
	UGStream& operator>>(UGushort& v);
	UGStream& operator>>(UGshort& v){ return *this >> reinterpret_cast<UGushort&>(v); }
	UGStream& operator>>(UGuint& v);
	UGStream& operator>>(UGint& v){ return *this >> reinterpret_cast<UGuint&>(v); }
	UGStream& operator>>(UGfloat& v){ return *this >> reinterpret_cast<UGuint&>(v); }
	UGStream& operator>>(UGdouble& v);
#ifdef UG_LONG
	UGStream& operator>>(UGlong& v){ return *this >> reinterpret_cast<UGdouble&>(v); }
	UGStream& operator>>(UGulong& v){ return *this >> reinterpret_cast<UGdouble&>(v); }
#endif
	
	UGStream& Load(UGuchar* p,UGuint n);
	UGStream& Load(UGchar* p,UGuint n){ return Load(reinterpret_cast<UGuchar*>(p),n); }
	UGStream& Load(UGushort* p,UGuint n);
	UGStream& Load(UGshort* p,UGuint n){ return Load(reinterpret_cast<UGushort*>(p),n); }
	UGStream& Load(UGuint* p,UGuint n);
	UGStream& Load(UGint* p,UGuint n){ return Load(reinterpret_cast<UGuint*>(p),n); }
	UGStream& Load(UGfloat* p,UGuint n){ return Load(reinterpret_cast<UGuint*>(p),n); }
	UGStream& Load(UGdouble* p,UGuint n);
#ifdef UG_LONG
	UGStream& Load(UGlong* p,UGuint n){ return Load(reinterpret_cast<UGdouble*>(p),n); }
	UGStream& Load(UGulong* p,UGuint n){ return Load(reinterpret_cast<UGdouble*>(p),n); }
#endif

private:
	// modified by zengzm 2007-3-27 改为静态变量,只需要判断一次,提高运行效率
	// static UGbool swap;
	// UGbool swap;
protected:
	UGuchar           *begptr;
	UGuchar           *endptr;
	UGuchar           *wrptr;
	UGuchar           *rdptr;
	// UGuint			 pos;
	UGulong			 pos;
	
	//文件的实际长度,主要用在内存文件中
	// modified by zengzm 2007-3-28 改为无符号型
	//UGlong m_lActualPos; //Add by aiguo
	UGulong m_lActualPos;
	
	UGStreamDirection  dir;
	UGStreamStatus     code;
	UGbool             owns;
	
	//Add by aiguo
	enum UGSignLoadSave 
	{
		UGSignStreamLoad =0,
		UGSignStreamSave =1
	};
	//{{//Add by aiguo,在这种UGStreamLoadSave模式下Load和Save和标识
	UGSignLoadSave     SignLoadSave; 
	//}}
private:
	UGStream(const UGStream&);
	UGStream &operator=(const UGStream&);
	
protected:
	// modified by zengzm 2007-3-9 这个函数被子类调用，外面不直接使用
	UGbool Open(UGStreamDirection save_or_load, UGuint size=8192,  UGuchar* data=NULL);  	
	
	virtual UGuint WriteBuffer(UGuint count);
	virtual UGuint ReadBuffer(UGuint count);
	
	
	//{{Add by aiguo 主要是解决在UGStreamLoadSave模式下，Load和Save混乱的问题，这里主要是设置一些标志来控制Load和Save.
	virtual void SetSignLoadSave(UGint nSign);
	//}}
};


}

#endif


