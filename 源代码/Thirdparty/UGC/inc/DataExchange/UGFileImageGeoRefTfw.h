// UGFileImageGeoRefTfw.h: interface for the UGFileImageGeoRefTfw class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEIMAGEGEOREFTFW_H__3E03ADDD_C9F3_4A28_A1D2_55CD7F74FB49__INCLUDED_)
#define AFX_UGFILEIMAGEGEOREFTFW_H__3E03ADDD_C9F3_4A28_A1D2_55CD7F74FB49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UGFileImageGeoRef.h"

namespace UGC {

class UGFileImageGeoRefTfw : public UGFileImageGeoRef  
{
public:
	UGFileImageGeoRefTfw();
	virtual ~UGFileImageGeoRefTfw();

public:
	//! brief 把strRefFileName改为正确的后缀名，各个子类必须实现
	virtual void SetExtName(UGString& strRefFileName);
	
	//! brief 写出参考文件
	virtual UGbool WriteGeoRefInfo(UGRect2D rectBounds, UGlong lUnit);
	
	//! brief 读取参考文件
	virtual UGbool ReadGeoRefInfo(UGRect2D &rectBounds, UGlong &lUnit);
	
protected:
	//以下两个函数实现单位在符号和数值之间的相互转化，因为各个影像参考文件的格式不同，因而必须由各个子类自己实现。
	
	//! brief 知道单位的字符表示，转化为数值形式（与supermap的规定兼容）
	virtual UGlong UnitConvert(UGString strUnit); 
	
	//! brief 知道单位的数值表示形式（与supermap的规定兼容），转化为字符形式
	virtual UGString UnitConvert(UGlong lUnit);
};

}
#endif // !defined(AFX_UGFILEIMAGEGEOREFTFW_H__3E03ADDD_C9F3_4A28_A1D2_55CD7F74FB49__INCLUDED_)
