
/*!
    **************************************************************************************
     \file     UGFileParseVector.h
    **************************************************************************************
     \author   艾国
     \brief    文件解析矢量类               
     \remarks   所有矢量解析类都从它继承                                                                       <br>
    ----------------------------------------------------------------------------------<br>
     Revision History :                                                               <br>  
     2005-04-22  艾国    Initial Version.                                           <br>
                                                                                      <br>   
    ----------------------------------------------------------------------------------<br>
     Copyright (c) 1996-2004 SuperMap GIS Technologies,Inc.                           <br>
    ----------------------------------------------------------------------------------<br>

    **************************************************************************************
*/


#if !defined(AFX_UGFileParseVector_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_)
#define AFX_UGFileParseVector_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_



#include "UGFileParse.h"
#include "Base/UGList.h"
#include "Base/UGDict.h"
#include "Engine/UGFieldInfo.h"
#include "Geometry/UGGeoPoint.h"
#include "Geometry/UGGeoLine.h"
#include "Geometry/UGGeoRegion.h"
#include "Geometry/UGGeoText.h"
#include "Geometry/UGGeoCompound.h"
#include "Geometry/UGGeoMultiPoint.h"
#include "UGStyleMapperDefn.h"

namespace UGC {

	class UGGeometry;
	
class FILEPARSER_API UGFileParseVector : public UGFileParse  
{
public:

	UGFileParseVector();
	virtual ~UGFileParseVector();
public:

	//////////////////////////////////////////////////////////////////////////
	// 公共设置函数
	//////////////////////////////////////////////////////////////////////////

	//! brief 设置点风格映射表
	virtual void SetSymbolStyleMapper(UGSymbolStyleMapper SymbolStyleMapper);	
	//! brief 设置线型映射表
	virtual void SetPenStyleMaper(UGPenStyleMapper PenStyleMapper);	
	//! brief 设置填充风格映射表
	virtual void SetBrushStyleMapper(UGBrushStyleMapper BrushStyleMapper);	
	//! brief 设置字体风格映射表
	virtual void SetFontStyleMapper(UGFontStyleMapper FontStyleMapper);

	//! \brief	设置坐标单位			
	virtual void SetDesUnits(UGint nDesUnits);
	//! \brief	设置用户指定要导入的图层的名字集合（基类没有成员变量，派生类来实现）
	virtual void SetLayers(const UGList<UGString>& layers);
	//! \brief	设置导入或导出图层字段名（基类没有成员变量，派生类来实现）
	virtual void SetLayerName(const UGString& strLayerName);
	//! \brief	设置导入或导出搞程字段名（基类没有成员变量，派生类来实现）
	virtual void SetElevationName(const UGString& strElevationName);

	//! \brief	设置导入是否忽略
	virtual void SetIsIgnoreCoordSys(UGbool bIgnoreCoordSys);
	//! \brief	设置导入是否忽略属性
	virtual void SetIsIgnoreAttribute(UGbool bIgnoreAttribute);
	//! \brief	设置导入是否忽略拓扑
	virtual void SetIsIgnoreNetworkTopology(UGbool bIgnoreNetworkTopology);
	//! \brief	设置导入是否忽略风格
	virtual void SetIsIgnoreStyle(UGbool bIgnoreStyle);

	//! \brief 设置导入为CAD数据集，返回值是由IsImportAsCAD函数来决定（CAD数据集专用）
	virtual UGbool SetIsImportAsCAD(UGbool bImportAsCADDataset);
	
	//////////////////////////////////////////////////////////////////////////
	// 公共询问函数
	//////////////////////////////////////////////////////////////////////////

	//! \brief 是否可以导入为CAD数据集
	virtual UGbool IsImportAsCAD();

	//! \brief 是否有投影
	virtual UGbool IsProject();

	//! \brief 是否有导入的数据集的名字根据图层来命名，否则按照用户给出的名字来命名
	//! 有些数据导入时是一套数据
	virtual UGbool IsDatasetNameByLayer();

	//////////////////////////////////////////////////////////////////////////
	// 读取函数
	//////////////////////////////////////////////////////////////////////////

	//! \brief 得到地理参考系统
	virtual UGbool GetSpatialRef(UGPrjCoordSys& spatialRef);

	//! \brief 得到当前图层的对象数
	virtual UGint GetFeatureCount();

	//! \brief 得到当前图层的范围
	virtual UGRect2D GetLayerExtent();

	//! \brief 得到指定图层的字段数目
	virtual UGint GetFieldCount(UGint nLayerIndex);

	//! \brief 得到指定图层、指定字段序号的字段信息
	virtual UGbool GetFieldInfo(UGint nLayerIndex, UGint nFieldIndex, UGFieldInfo &fieldInfo);

	//! \brief 得到指定图层的扩展字段的数目
	virtual UGint GetExtendFieldCount(UGint nLayerIndex);

	//! \brief 得到指定图层、指定字段序号的扩展字段信息
	virtual UGbool GetExtendFieldInfo(UGint nLayerIndex, UGint nFieldIndex, 
							  UGString& strFieldName, UGint& nFieldType, UGint& nFieldSize);

	//! \brief 得到当前记录的、指定序号的扩展字段值。
	virtual UGbool GetExtendFieldValue(UGint nIndex, UGVariant& value);

	

	//! \brief 把读文件的指针重新设置在文件头，这样就可以重新读去文件
	virtual void ResetReading();

	//! \brief 开始读取记录，在第一次调用读取记录前，必须调用。
	virtual void BeginReadRecord();

	//! \brief 是否已经读取到文件尾了，这个作为读取结束的标志
	//! \remarks 这个设计为纯虚函数，因为文件解析类的用户是依靠这个来进行循环的，很重要
	//! \return 返回true,说明已到文件尾,需要结束读取了
	virtual UGbool IsEOF() = 0;

	//! \brief 开始读取一条记录，
	virtual void BeginReadOneRecord();

	//! \brief 读取一条记录中的几何对象。
	//! \remarks 如果返回false，只说明读取这条Geometry有问题，并不代表已经结束
	//! 读取文件是否结束，使用IsEOF进行判断
	virtual UGbool ReadOneGeometry(UGGeometry*& pGeometry);

	//! \brief 得到当前几何对象所在图层的名字，如果该图层不需要转入那么就不需要读取这个几何对象
	virtual UGString GetLayerOfGeometry();

	//! \brief 得到当前记录的、指定序号的字段值。
	virtual UGbool GetFieldValue(UGint nIndex, UGVariant& value);

	//! \brief 结束读取一条记录。
	virtual void EndReadOneRecord();

	//! \brief 得到当前已经处理的数据的百分比
	//! \remarks 由于不提供总记录数的函数,故而进程条需要这个方法
	virtual UGint GetCurrentPercent();

	//! \brief 结束读取所有记录
	virtual void EndReadRecord();


	//////////////////////////////////////////////////////////////////////////
	// 写入函数
	//////////////////////////////////////////////////////////////////////////

	//! \brief 设置地理空间参考系。
	//virtual void SetSpatialRef(const Projection::CSmSpatialRef& spatialRef);
	
	//! \brief 设置指定图层的字段数量。
	virtual void SetFieldCount(UGint nLayerIndex, UGint nFieldCount);
	
	//! \brief 设置指定图层的指定字段序号的字段信息。
	virtual void SetFieldInfo(UGint nLayerIndex, UGint nFieldIndex, 
					const UGString& strFieldName, UGint nFieldType, UGint nFieldSize);

	//! \brief 开始准备写入记录。在真正写入记录前必须调用。
	virtual void BeginWriteRecord();

	//! \brief 准备写入一条记录
	virtual void BeginWriteOneRecord();
	
	//! \brief 写入一条记录的几何对象。
	virtual UGbool WriteOneGeometry(UGGeometry* pGeometry, 
								  const UGString& strLayerName);
	
	//! \brief 设置当前记录的指定序号的字段值。
	virtual void SetFieldValue(UGint nIndex, const UGVariant& value);
	
	//! \brief 结束写入一条记录。
	virtual void EndWriteOneRecord();

	//! \brief 结束 所有的记录的写入
	virtual void EndWriteRecord();
	
protected:
	//! \brief 是否忽略风格
	UGbool m_bIgnoreStyle;

	//! \brief 是否忽略坐标系统
	UGbool m_bIgnoreCoordSys;

protected:
	//! brief 符号对照表。
	UGSymbolStyleMapper m_SymbolStyleMapper;	
	//! brief 线型对照
	UGPenStyleMapper m_PenStyleMapper;	
	//! brief 填充风格对照
	UGBrushStyleMapper m_BrushStyleMapper;	
	//! brief 填充风格对照
	UGFontStyleMapper m_FontStyleMapper;	
};

} //namespace UGC

#endif // !defined(AFX_UGFileParseVector_H__9D5BD937_D091_4D5F_957C_94B8A7A74D92__INCLUDED_)
