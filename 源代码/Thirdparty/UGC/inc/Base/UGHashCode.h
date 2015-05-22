// UGHashCode.h: interface for the UGHashCode class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGHASHCODE_H__655A005A_77A3_426D_B890_151E99E6F0F3__INCLUDED_)
#define AFX_UGHASHCODE_H__655A005A_77A3_426D_B890_151E99E6F0F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Base/ugdefs.h"
#include "Base/UGString.h"
namespace UGC {
class BASE_API UGHashCode  
{
public:
	UGHashCode();
	virtual ~UGHashCode();
public:
	static UGint LONGToHashCode(UGlong nValue);
	static UGint ShortToHashCode(UGshort nValue);
	static UGint StringToHashCode(const UGString& strValue);
	static UGint BoolToHashCode(UGbool bValue);
	static UGint PointerToHashCode(void* pValue);
	static UGint DoubleToHashCode(UGdouble dValue);
	static UGint FloatToHashCode(UGfloat fValue);
	static UGint ByteToHashCode(UGbyte btValue);

	//! \brief 快速把字符串转化为HashCode
	//! \remarks 由于要和SFC保持兼容,StringToHashCode中进行了Unicode的转化,非常费时
	//! 其它不需要保持兼容的地方,可以用这个函数,速度快很多
	static UGint FastStringToHashCode(const UGString& strValue);
};
}
#endif // !defined(AFX_UGHASHCODE_H__655A005A_77A3_426D_B890_151E99E6F0F3__INCLUDED_)
