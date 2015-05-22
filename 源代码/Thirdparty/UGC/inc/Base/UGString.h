/* 
	\file UGString.h
	\brief 字符串类
	\author 李同堂、曾志明
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：modified by zengzm 2007-3-12 UGString不要从std::string继承，而应该是包裹在内
	以避免绑定在 stl上；即UGString的用户应该依赖于UGString的接口，而不是实现（依赖倒置原理）。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#ifndef UGSTRING_H
#define UGSTRING_H

#include "ugdefs.h"
#include "UGArray.h"
#include "UGStream.h"
// by zengzm 注意: 这里应该避免把MFC的头文件Include进来(既便添加了WIN32宏),因为MFC把LoadString作为宏
// 在MBCS方式下会变为LoadStringA,导致编译不过.

namespace UGC {

class UGString;

typedef const UGchar* LPCTSTR;
typedef UGArray<UGString> UGStrArray;
typedef UGArray<UGString> UGStrings; 


//! \brief 字符串类
//!	\remarks 除非有特殊说明，UGString的接口尽可能和MFC的CString保持一致
//! \attention UGString仅支持多字节编码的字符串，宽字节编码的字符串类为UGStringW。
class BASE_API UGString
{
	friend class UGProgress;

public:
	//! \brief 默认构造函数。
	UGString();
	//! \brief 拷贝构造函数。
	//! \param str UGString类型的字符串
	UGString(const UGString& str);	
	//! \brief 用std::string来构造。
	//! \param str std::string类型的字符串,主要用于和UGMarkup等进行匹配
	UGString(const std::string& str);	
	//! \brief 用C 字符串构造。	
	//! \param pstr C字符串参数
	UGString(const UGchar* pstr);
	//! \brief 指定C字符串的长度来构造。
	//! \param pstr C字符串参数
	//! \param nSize 指定使用的字节长度
	UGString(const UGchar* pstr, UGint nSize);
	//! \brief 指定特定字符（指定可重复个数）来构造，。
	//! \param ch 指定的字符
	//! \param nRepeat 重复次数,默认为1
	//! \remarks explicit用于防止隐形的转化
	explicit UGString(UGchar ch, UGint nRepeat=1);
	//! \brief 转换为LPCTSTR，通常用于和从SFC移植而来的代码兼容。
	operator LPCTSTR() const;
	//! \brief 得到C字符串。
	//! \return 返回C字符串。
	const UGchar * Cstr() const;

	//! \brief 得到指定索引的字符。
	//! \param nIndex 指定的索引
	//! \return 返回指定索引的字符。
	UGchar GetAt(UGint nIndex) const;		
	//! \brief 设置指定索引的字符
	//! \param nIndex 指定的索引
	//! \param ch 要设置的字符
	void SetAt(UGint nIndex, UGchar ch);

	//! \brief 得到指定索引的字符。
	//! \param  nIndex 指定的索引
	//! \return 返回指定索引的字符
	UGchar operator[](UGint nIndex) const;
	//! \brief 设置指定索引的字符的引用，支持str[i]='a'
	//! \param nIndex 指定的索引
	//! \return 返回指定索引的字符的引用
	UGchar& operator[](UGint nIndex);

	//! \brief 确保有指定字节个数的内存空间
	//! \remarks 如果原有空间不够, 内存空间会增加
	//! \remarks 如果原有空间比指定的大, 也不会释放空间
	//! \param nCapacity 可容纳的字节个数
	void SetCapacity(UGint nCapacity);
	//! \brief 得到目前所有空间(包括已经使用的和保留的)所占用的字节个数
	//! \return 返回目前所有空间(包括已经使用的和保留的)所占用的字节个数
	UGint GetCapacity() const; 

	//! \brief 得到字符串长度
	//! \return 返回字符串长度,即字节个数
	UGint GetLength() const;	
	//! \brief 设置字符串长度
	//! \remarks 如果长度变小,会自动截断; 如果长度变大,会填充0x00, 但Length会变长。内部调用string的resize实现。
	//! \param nLength 要设置的字符串长度(字节个数)
	void SetLength(UGint nLength);

	//! \brief 追加数据，内部采用string的append实现。
	//! \param pch 要追加的字符串指针
	//! \param nSize 要追加的字节个数
	void Append(const UGchar* pch, UGint nSize);	

	//! \brief 把字符串内容转换为大写，不会修改非ASCII字符
	//! \return 返回自身的引用,支持连写
	UGString& MakeUpper();
	//! \brief 把字符串内容转换为小写，不会修改非ASCII字符
	//! \return 返回自身的引用,支持连写
	UGString& MakeLower();
	//! \brief 把字符串逆转，支持中间带有中文（MBCS）的转换，如"ab中c"可转换为"c中ba"，日文没有测试过
	//! \return 返回自身的引用,支持连写
	UGString& MakeReverse();
	
	//! \brief 取出字符串对象左边的若干长度的子字符串
	//! \param nCount 字节个数
	//! \return 返回左边指定长度的子字符串
	UGString Left(UGint nCount) const;
	//! \brief 取出字符串对象最右边的若干长度的子字符串
	//! \param nCount 字节个数
	//! \return 返回右边指定长度的子字符串
	UGString Right(UGint nCount) const;
	//! \brief 从字符串对象中取出从中间某索引起的子字符串对象
	//! \param nFirst 指定的中间的索引序号
	//! \return 返回从中间指定的索引开始,到最后的子字符串
	UGString Mid(UGint nFirst) const;
	//! \brief 从字符串对象中取出从中间某索引起、一定长度的子字符串对象；索引序号从0起
	//! \param nFirst nFirst 指定的中间的索引序号
	//! \param nCount 要取出的字节个数
	//! \return 返回从中间指定的索引开始,指定长度的子字符串
	UGString Mid(UGint nFirst,UGint nCount) const;

	//! \brief 删除从指定索引起的若干数目的字符，索引序号从0起
	//! \param nIndex 指定的开始删除的索引
	//! \param nCount 指定要删除的字节个数
	//! \return 删除了指定字节个数之后,字符串对象的长度
	UGint Delete(UGint nIndex,UGint nCount=1);
	//! \brief 在指定的索引之前插入字符串
	//! \param nIndex 指定的索引
	//! \param pstr 要插入的字符串
	//! \return 插入后,字符串的长度
	UGint Insert(UGint nIndex,const UGchar * pstr);	
	//! \brief 在指定的索引之前插入若干数目的字符
	//! \param nIndex 指定的索引
	//! \param ch 指定的字符
	//! \param nCount 字符重复的次数
	//! \return 插入后,字符串的长度
	UGint Insert(UGint nIndex,UGchar ch,UGint nCount=1);
	//! \brief 删除字符串对象中等于指定字符的字符
	//! \param ch 要删除的字符
	//! \return 返回删除的字符的个数
	UGint Remove(UGchar ch);		

	//! \brief 删除字符串对象左边的空格（0x09－0x0D或0x20）
	//! \return 删除后,字符串对象的引用,以支持连写
	UGString& TrimLeft();
	//! \brief 删除字符串对象左边的指定字符
	//! \param ch 要删除的字符
	//! \return 删除后,字符串对象的引用,以支持连写
	UGString& TrimLeft(UGchar ch);
	//! \brief 删除字符串对象左边属于指定字符集合的字符
	//! \remarks 对于字符集合,是要删除左边的存在于字符集合中的每一个字符
	//!			UGString("? *?? ab* ?").TrimLeft("? *") == UGString("ab* ?")
	//! \param pstr 指定的字符串集合
	//! \return 删除后,字符串对象的引用,以支持连写
	UGString& TrimLeft(const UGchar* pstr);
	//! \brief 删除字符串对象右边的空格（0x09－0x0D或0x20）
	//! \return 删除后,字符串对象的引用,以支持连写
	UGString& TrimRight();
	//! \brief 删除字符串对象右边的指定字符
	//! \param ch 指定的字符
	//! \return 删除后,字符串对象的引用,以支持连写
	UGString& TrimRight(UGchar ch);
	//! \brief 删除字符串对象右边属于指定字符集合的字符
	//! \remarks 对于字符集合,是要删除右边的存在于字符集合中的每一个字符
	//!			UGString("? *?? ab?* ?").TrimRight("? *") == UGString("? *?? ab")
	//! \param pstr 指定的字符串集合
	//! \return 删除后,字符串对象的引用,以支持连写
	UGString& TrimRight(const UGchar* pstr);
	
	//! \brief 判断字符串是否为空
	//! \return 为空,返回true;不为空,返回false
	UGbool IsEmpty() const;	
	//! \brief 清空字符串
	void Empty();

	//! \brief 比较函数，字符串对象和一个字符串比较大小
	//! \remarks 区分大小写，按照内部值依顺序比较
	//! \param lpsz 要比较的字符串指针
	//! \return 小于返回负数；等于返回0；大于返回正数</returns>
	UGint Compare(const UGchar* lpsz) const;
	//modified by xielin 2007-10-17下面这个函数还是开放出来，否则linux下有问题
	//! \brief 比较函数，字符串对象和一个字符串比较大小
	//! \remarks 不区分大小写，按照内部值依顺序比较
	//! \param lpsz 要比较的字符串指针
	//! \return 小于返回负数；等于返回0；大于返回正数</returns>
 	UGint CompareNoCase(const UGchar* lpsz) const;

	//added by xielin 2007-10-15 性能优化过的比较函数，测试发现引擎了大量使用比较函数，
	//以前的效率比较低，成为影响效率的瓶颈之一，这里做一个新的效率比较高的比较函数
	//! \brief 比较函数，字符串对象和一个字符串比较大小
	//! \remarks 不区分大小写，按照内部值依顺序比较
	//! \param str 要比较的字符串
	//! \return 小于返回负数；等于返回0；大于返回正数</returns>
	UGint CompareNoCase(const UGString& str) const;
	
	//! \brief 从某位置开始，查找指定的字符
	//!	\param ch 要查找的字符[in]。
	//!	\param nStart 查找起始位置，对应的字符会被查找[in]。
	//!	\return 返回找到的字符的索引值，从0算起。找不到返回-1
	UGint Find(UGchar ch,UGint nStart=0) const;		

	//! \brief 从某位置开始，查找完全相等的子字符串
	//!	\param lpszSub 要查找的子字符串[in]。
	//!	\param nStart 查找起始位置，对应的子字符串会被查找[in]。
	//!	\return 返回找到的子字符串的索引值，从0算起。找不到返回-1
	UGint Find(const UGchar* lpszSub, UGint nStart=0) const;

	//! \brief 从后向前查找指定的字符
	//!	\param ch 要查找的字符[in]。
	//!	\return 返回找到的字符的索引值，从0算起;找不到返回-1
	UGint ReverseFind(UGchar ch) const;	
	
	//! \brief 查找第一个“既在字符串对象中，又在指定的字符集合中”的字符的位置。
	//!	\param lpszCharSet 指定的字符集合[in]。
	//!	\return 返回找到的字符的索引，从0算起。找不到返回-1
	UGint FindOneOf(const UGchar* lpszCharSet) const;	

	//! \brief 得到字符串对象中，从第0个字符起，到不符合指定字符集合中的字符为止的子字符串。
	//! \param lpszCharSet 指定的字符集合[in]。
	//!	\return 返回符合条件的子字符串。
	//!	\remarks example: UGString("acbdabc").SpanIncluding("abc") == UGString("acb")。
	UGString SpanIncluding(const UGchar* lpszCharSet) const;		

	//! \brief 得到字符串对象中，从第0个字符起，到符合指定字符集合中的字符为止的子字符串。
	//! \param lpszCharSet 指定的字符集合[in]。
	//!	\return 返回符合条件的子字符串。
	//!	\remarks example: UGString("acbdabc").SpanExcluding("d") == UGString("acb")。
	UGString SpanExcluding(const UGchar* lpszCharSet) const;
		
	//! \brief 替换函数，把字符串对象中指定的字符替换为新的字符。
	//! \param chOld 指定要被替换的字符[in]。
	//!	\param chNew 新的字符[in]。
	//!	\return 返回替换的次数。
	//! \remarks 比较时区分大小写。
	UGint Replace(UGchar chOld,UGchar chNew);

	//! \brief 替换函数，把字符串对象中指定的子字符串替换为新的字符串
	//! \param lpszOld 指定要被替换的子字符串[in]。
	//!	\param lpszNew 新的字符串[in]。
	//!	\return 返回替换的次数。
	//!	\remarks 比较时区分大小写。
	UGint Replace(const UGchar* lpszOld,const UGchar* lpszNew);

	//! \brief 获取字符串对象的Hash值
	//! \remarks 一般用不上，仅供一些特殊类内部使用
	//! \return 返回构造的hash值,和具体的字符串的内容相关
	UGuint HashVal() const;
	
	//! \brief 根据资源ID装载字符串资源。
	//! \param nID 用来装载字符串资源的资源ID[in]。
	//! \remarks 由于MFC把LoadString等当成宏来处理，很多需要用到MFC的工程，
	//!			在使用LoadString的时候，都会发生编译不过的情况;这时,请使用LoadResString;
	//!			以后大家都尽量使用LoadResString,LoadString下一个版本将被取消.
	//!	\return 装载成功，返回true；失败返回false。
	UGbool LoadResString(UGuint nID);	

	//! \brief 根据资源ID装载字符串资源。
	//! \param nID 用来装载字符串资源的资源ID[in]。
	//!	\return 装载成功，返回true；失败返回false。
	UGbool LoadString(UGuint nID);	

	//! \brief 格式化函数，类似于sprintf。
	//!	\param fmt 用来表达格式的字符串[in]。
	//!	\param ... 可选参数[in]。
	//!	\remarks 不能将UGString作为参数传进该函数，而必须调用UGString的Cstr函数得到C字符串。
	//!			 不能将UGlong、UGulong等64位整数作为参数传入该函数,而应该先强制转化为32位整数
	void Format(const UGchar* fmt,...);
	//! \brief 格式化函数，类似于sprintf。
	//!	\param nID 用作表达格式的字符串的资源的ID[in]。
	//!	\param ... 可选参数[in]。
	//!	\remarks 不能将UGString作为参数传进该函数，而必须调用UGString的Cstr函数得到C字符串。
	//!			 不能将UGlong、UGulong等64位整数作为参数传入该函数,而应该先强制转化为32位整数
	void Format(UGuint nID,...);

	//! \brief 字符串赋值函数。
	const UGString& operator=(const UGString& str);	

	UGString operator+(const UGchar ch) const;
	UGString operator+(const UGchar* pch) const;
	UGString operator+(const UGString& str) const;

	const UGString& operator+=(const UGString& str);
	const UGString& operator+=(const UGchar ch);
	const UGString& operator+=(const UGchar* pch);

	bool operator==(const UGchar* pch) const;
	bool operator==(const UGString& str) const;

	bool operator!=(const UGchar* pch) const;
	bool operator!=(const UGString& str) const;

	bool operator<(const UGString& str) const;

	friend BASE_API UGString operator+(UGchar ch, const UGString &str);
	friend BASE_API UGString operator+(const UGchar* pch, const UGString &str);
	
	//! \brief 把long型的数据转化为字符串
	//! \param lVal 要转化的long型数据
	//! \param base 进制,默认为10进制,还支持16进制;其它暂时不支持
	//! \return 返回转化后的字符串
	//! \remarks 当base为16进制时,转化后的结果前面会加0X,字母都为大写
	//! 用这种方式间接支持long型数据的Format,即先转化为UGString,再用%s进行格式化
	//! 采用静态函数，返回UGString的方式，以便于调用的代码连写
	static UGString From(UGlong lVal, UGint base=10);
	static UGString From(UGulong lVal, UGint base=10);
	static UGString From(UGint nVal, UGint base=10);
	static UGString From(UGuint nVal, UGint base=10);
	//friend BASE_API UGString UGLongToString(UGlong lVal, UGint base=10);
	//friend BASE_API UGString UGULongToString(UGulong lVal, UGint base=10);
	
	//Convert string to a integer number, assuming given number base
	//! \brief 把字符串转换为Int型数值
	//friend BASE_API UGint UGIntVal(const UGString& s,UGint base=10);
	UGint ToInt(UGint base=10) const;

	//! \brief 把字符串转换为无符号Int型数值
	//friend BASE_API UGuint UGUIntVal(const UGString& s,UGint base=10);
	UGuint ToUInt(UGint base=10) const;

	
	//! \brief 把字符串转换为Long型数值
	//! \param s 要转化的字符串
	//! \param base 进制,默认为10进制,还支持16进制;其它暂时不支持
	//friend BASE_API UGlong UGLongVal(const UGString& s,UGint base=10);
	UGlong ToLong(UGint base=10) const;

	//! \brief 把字符串转换为无符号Long型数值
	//! \param s 要转化的字符串
	//! \param base 进制,默认为10进制,还支持16进制;其它暂时不支持
	//friend BASE_API UGulong UGULongVal(const UGString& s,UGint base=10);
	UGulong ToULong(UGint base=10) const;
	
	//Convert string into real number
	//! \brief 把字符串转换为Float型数值
	//friend BASE_API UGfloat UGFloatVal(const UGString& s);
	UGfloat ToFloat() const;

	//! \brief 把字符串转换为Double型数值
	//friend BASE_API UGdouble UGDoubleVal(const UGString& s);	
	UGdouble ToDouble() const;
	
	//! \brief 把字符串按照指定的分隔符分割为一个字符串数组。
	//! \param dest 生成的字符串数组[out]。
	//!	\param delims 指定的分隔符，默认为回车换行[in]。
	//!	\param bKeepEmptyString 是否保留分割后 空的字符串, 如字符串";"通过';'分割后,dest数组的size
	//! 在保留空字符串的时候为2, 不保留的时候为0; 
	//!	\return 分割后字符串数组的size。
	UGint Split(UGStrings &dest,const UGString& delims="\r\n", UGbool bKeepEmptyString=FALSE) const;
		
	//! \brief 把字符串保存到流中
	friend BASE_API UGStream& operator<<(UGStream& store,const UGString& s);
		
	//! \brief 从流中读出字符串
	friend BASE_API UGStream& operator>>(UGStream& store,UGString& s);

	//!brief 设置/获取ugstring里面的字符真正的字符集，做转换的时候有用
	void SetCharset(UGint enCharset);
	UGint GetCharset();
	//!brief 把自身转换成制定编码的字符串
	UGbool ChangeCharset(UGint eCharset);
private:
	// added by zengzm 2007-3-19 故意只定义不实现，避免拿UGString直接和NULL等进行比较
	// 因为在linux平台上，会导致程序崩溃
	bool operator==(int n) const;

private:
	void FormatV(const UGchar* fmt, va_list argList);

	std::string m_string; // 内部采用std的string实现
	UGint m_Charset;
};

}

#endif
