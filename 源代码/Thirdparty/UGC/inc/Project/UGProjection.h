//========================================================================
// 项目名：			SuperMap Universal GIS class (UGC) Library 0.9
// 作  者：			张立立
// 单  位：			北京超图地理信息技术有限公司
// 最后修改时间：	以文件日期为准
//------------------------------------------------------------------------
//版权声明:         版权所有 1996-2003 北京超图地理信息技术有限公司，保留所有权利 
//	                Copyright (c) 1996-2003 The SuperMap GIS Technologies, Inc. 
//	                All rights reserved
// 重要声明：		1. 
//					2. 
//					
//------------------------------------------------------------------------
// 文件名：			UGProjection.h
// 类  名：			UGProjection
// 父  类：			
// 子  类：			

// 功能说明：		投影方法定义
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

#if !defined(UGC_SMPROJECTION_H__0EBE9968_FA20_4C93_A922_7DAD98A06FF5__INCLUDED_)
#define UGC_SMPROJECTION_H__0EBE9968_FA20_4C93_A922_7DAD98A06FF5__INCLUDED_


//// #include "SmImport.h"

#include "Base/UGThread.h"
#include "Base/UGString.h"

#include "UGPjCon.h"

namespace UGC{


class PROJECT_API UGProjection  
{
	friend class UGPrjFactory;
public:
	//! \brief 默认构造函数
	UGProjection();
	//! \brief 根据投影方式类型构造投影方式对象
	UGProjection(EmPrjObjectType eTypeID);
	virtual ~UGProjection();
	UGProjection(const UGProjection& Projection);
	UGProjection& operator = (const UGProjection& Projection);
	UGbool operator == (const UGProjection& Projection) const;
	UGbool operator != (const UGProjection& Projection) const;
	
	//! \brief 获取投影方式类型
	EmPrjObjectType GetProjectionType() const;
	//! \brief 设置投影方式类型并重构投影方式对象
	UGbool SetTypeID(EmPrjObjectType nTypeID);

	//! \brief 获取投影方式名称
	UGString GetProjectionName() const;

	//! \brief 输出为XML字符串
	UGString ToXML(UGint nVersion = 0) const;
	//! \brief 读取XML字符串为投影方式对象
	UGbool FromXML(const UGString& strPrjXml, UGint nVersion = 0);

	//! \brief 从配置文件读取投影方式信息 dongfei 2007-04-04	
	UGbool FromConfigure( EmPrjObjectType nTypeID,UGint nVersion = 0);


private:
	EmPrjObjectType m_eTypeID;
	UGString m_strName;
	UGMutex	 m_mutex;
};

}//namespace UGC



#endif // !defined(UGC_SMPROJECTION_H__0EBE9968_FA20_4C93_A922_7DAD98A06FF5__INCLUDED_)
