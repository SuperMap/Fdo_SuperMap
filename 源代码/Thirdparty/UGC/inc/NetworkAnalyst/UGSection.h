// 功能说明：		动态分段路由对象

#ifndef UGSECTION_H
#define UGSECTION_H

#include "Base/ugdefs.h"

namespace UGC {

class NETWORKANALYST_API UGSection
{
public:
	///	构造函数	
	UGSection();

	/// 析构函数
	virtual ~UGSection();
	
	/// 等于操作符
	UGbool operator==(const UGSection& sec);
	
	/// 不等于操作符
	UGbool operator!=(const UGSection& sec);
	
public:
	UGint m_nArcID;			/// 对应的弧段ID
	UGint m_nRouteID;		/// 对应的Route ID
	UGdouble m_dFromMeasure;	/// 起始线标值
	UGdouble m_dToMeasure;	/// 终止线标值
	UGdouble m_dFromPos;		/// 在弧段上的起始位置
	UGdouble m_dToPos;		/// 在弧段上的终止位置
};

}


#endif
