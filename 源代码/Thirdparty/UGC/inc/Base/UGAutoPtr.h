/*! \file	 UGAutoPtr.h
 *  \brief	 半智能指针
 *  \author	 ugc team
 *  \attention 
 *  Copyright(c) 1996-2004 SuperMap GIS Technologies,Inc.<br>
 *  All Rights Reserved
 *  \version $Id: UGAutoPtr.h,v 1.9 2007/07/10 03:23:47 zengzm Exp $
 */

#if !defined(AFX_UGAUTOPTR_H__8844E5E9_172A_4931_913C_5B1322A01112__INCLUDED_)
#define AFX_UGAUTOPTR_H__8844E5E9_172A_4931_913C_5B1322A01112__INCLUDED_

#include "ugdefs.h"

namespace UGC {

//! \brief 半智能指针
template<typename T>
class UGEXPORT UGAutoPtr
{
private:
	//! \brief 禁止拷贝构造函数和赋值函数
	UGAutoPtr(const UGAutoPtr& autoPtr);
	void operator=(const UGAutoPtr& autoPtr);

public:
	//! \brief 构造函数
	UGAutoPtr() {
		m_pData = NULL;
		m_bAutoDelete = FALSE;
	}

	//! \brief 析构函数
	~UGAutoPtr() {
		Release();
	}

public:
	//! \brief 设置数据指针
	//! \remarks 使用时必须根据实际情况绝对是否让智能指针删除内部保存的指针
	void SetData(const T* pData, UGbool bAutoDelete) {
		Release(); // 先Release一下，以支持循环使用
		m_pData = pData;
		m_bAutoDelete = bAutoDelete;
	}
	
	const T* GetData() const
	{
		return m_pData;
	}
	
	//! \brief 自动转换函数
	//operator const T*() const {
	//	return m_pData;
	//}

	//const T* operator->() {
	//	return m_pData;
	//}

	const T& operator[](UGint nIndex) {
		return m_pData[nIndex];
	}

	void Release(){
		if (m_bAutoDelete) {
			T* pData = (T*)m_pData;
			delete []pData;
		}
		m_pData = NULL;
		m_bAutoDelete = FALSE;
	}
		
private:
	const T* m_pData;
	UGbool m_bAutoDelete;
};

}

#endif 

