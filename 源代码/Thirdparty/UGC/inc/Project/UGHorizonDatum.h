//========================================================================
// 项目名：			SuperMap Universal GIS class (UGC) Library 0.9
// 作  者：			张立立
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以版本更新完成日期为准
//------------------------------------------------------------------------
//版权声明:         版权所有 1996-2003 北京超图地理信息技术有限公司，保留所有权利 
//	                Copyright (c) 1996-2003 The SuperMap GIS Technologies, Inc. 
//	                All rights reserved

// 重要声明：		1. 
//					2. 
//					
//------------------------------------------------------------------------
// 文件名：			SmHorizonDatum.h
// 类  名：			UGHorizonDatum
// 父  类：			UGDatum
// 子  类：			

// 功能说明：		大地水平参照系定义
// 调用说明：		
/*-------------------------------------版本更新---------------------------
V 0.92
作    者：输入作者（或修改者）名字
完成日期：2002年10月20日
更新说明：

V 0.91
作    者：输入作者（或修改者）名字
完成日期：2001年7月20日
更新说明：

V 0.9 
原作者  ：张立立
完成日期：
========================================================================*/

#if !defined(UGC_SMHORIZONDATUM_H__5081C85C_BFE6_4BB0_891B_F59372DE57A6__INCLUDED_)
#define UGC_SMHORIZONDATUM_H__5081C85C_BFE6_4BB0_891B_F59372DE57A6__INCLUDED_


//// #include "SmImport.h"
#include "Base/UGThread.h"
#include "Base/UGString.h"

#include "UGDatum.h"
#include "UGSpheroid.h"

namespace UGC{



class PROJECT_API UGHorizonDatum : public UGDatum  
{
	friend class UGPrjFactory;
public:
	//! \brief 默认构造函数
	UGHorizonDatum();
	//! \brief 根据水平参考系类型构造水平参考系
	UGHorizonDatum(EmHorizonDatumType m_nTypeID );
	//! \brief 根据椭球体参数和水平参考系名称构造水平参考系
	UGHorizonDatum(const UGSpheroid& Spheroid,const UGString& strName);
	UGHorizonDatum(const UGHorizonDatum& HorizonDatum);
	
	UGHorizonDatum& operator =  (const UGHorizonDatum& HorizonDatum);
	UGbool operator == (const UGHorizonDatum& HorizonDatum) const;
	UGbool operator != (const UGHorizonDatum& HorizonDatum) const;

	virtual ~UGHorizonDatum();
	//! \brief 设置水平参考系类型
	//! \remarks 设置水平参考系类型后，会根据此类型重新构造水平参考系
	UGbool SetTypeID(EmHorizonDatumType nTypeID);
	//! \brief 获取水平参考系类型
	EmHorizonDatumType GetTypeID() const;

	//! \brief 获取参考系名称
	UGString GetDatumName() const;
	//! \brief 设置参考系名称
	void SetDatumName(const UGString& strName);

	//! \brief 获取椭球体对象
	const UGSpheroid& GetSpheroid() const;
	//! \brief 设置椭球体参数
	UGbool SetSpheroid(const UGSpheroid& spheroid);
	
	//! \brief 输出为XML字符串
	UGString ToXML(UGint nVersion = 0)const;
	//! \brief 从XML字符串读入水平参考系
	UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

//	UGString ToXMLEx(UGint nVersion = 0)const;
	
	//! \brief 从配置文件读取投影坐标系信息 dongfei 2007-04-04	
	UGbool FromConfigure(EmHorizonDatumType nTypeID,UGint nVersion = 0);

protected:	
	EmHorizonDatumType m_eTypeID;//类型
	UGString m_strName;//名字
	UGSpheroid m_Spheroid;//椭球参数

	UGMutex m_mutex;
};

}//namespace UGC


#endif // !defined(UGC_SMHORIZONDATUM_H__5081C85C_BFE6_4BB0_891B_F59372DE57A6__INCLUDED_)
