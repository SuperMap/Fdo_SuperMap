// UGFileImageGeoRef.h: interface for the UGFileImageGeoRef class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEIMAGEGEOREF_H__D14F5D26_D913_4F71_8A44_10E64926CAEB__INCLUDED_)
#define AFX_UGFILEIMAGEGEOREF_H__D14F5D26_D913_4F71_8A44_10E64926CAEB__INCLUDED_

#include "Algorithm/UGRect2D.h"
#include "Base/UGString.h"

namespace UGC {


class UGFileImageGeoRef
{
public:
	UGFileImageGeoRef();
	virtual ~UGFileImageGeoRef();
public:
	enum
	{
		GeoRefFile_NONE= 0, //用户没有指定影像坐标参考文件的类型
		GeoRefFile_DOM = 1, //类型为 dom, 国标地理坐标文件
		GeoRefFile_TFW = 2, //类型为 tfw, TIFF地理坐标文件
		GeoRefFile_SMC = 3, //类型为 smc（supermap自定义，xml文档）
		GeoRefFile_GB = 4//真正的国标地理坐标文件，上面的dom是以前错误的理解，文件后缀是img
	};

public:
	//! brief 把strRefFileName改为正确的后缀名，各个子类必须实现
	virtual void SetExtName(UGString& strRefFileName) = 0;
	
	//! brief 打开参考文件
	UGbool Open(UGString strRefFileName, UGString strImageFileName);
	
	//! brief 设置高、宽（导出专用）
	void SetHeightWidth(UGlong nImageHeight, UGlong nImageWidth);
	
	//! brief 设置参考文件类型
	void SetType(UGint nType );

	//! brief 写出参考文件
	virtual UGbool WriteGeoRefInfo(UGRect2D rectBounds, UGlong lUnit) = 0;
	
	//! brief 读取参考文件
	virtual UGbool ReadGeoRefInfo(UGRect2D &rectBounds, UGlong &lUnit) = 0;
	
protected:
	//! brief 要读取或者生成的影像地理坐标参考文件的全路径
	UGString m_strRefFileName; 

	//! brief 对应的要读取或者生成的影像文件的名字
	UGString m_strImageFileName;

	//! brief 影像高度
	UGlong m_nImageHeight;

	//! brief 影像宽度
	UGlong m_nImageWidth;
	
	//! brief 参考文件类型
	UGint m_nType;
	
protected:
	//以下两个函数实现单位在符号和数值之间的相互转化，因为各个影像参考文件的格式不同，因而必须由各个子类自己实现。
	
	//! brief 知道单位的字符表示，转化为数值形式（与supermap的规定兼容）
	virtual UGlong UnitConvert(UGString strUnit) = 0; 
	
	//! brief 知道单位的数值表示形式（与supermap的规定兼容），转化为字符形式
	virtual UGString UnitConvert(UGlong lUnit) = 0;

};

}

#endif // !defined(AFX_UGFILEIMAGEGEOREF_H__D14F5D26_D913_4F71_8A44_10E64926CAEB__INCLUDED_)
