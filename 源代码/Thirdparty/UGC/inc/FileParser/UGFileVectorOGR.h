// UGFileVectorOGR.h: interface for the UGFileVectorOGR class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGFILEVECTOROGR_H__93BBC489_7396_4FB0_BAD3_7C9A44BBCD16__INCLUDED_)
#define AFX_UGFILEVECTOROGR_H__93BBC489_7396_4FB0_BAD3_7C9A44BBCD16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "FileParser/UGFileParseVector.h"
#include "Engine/UGDataset.h"
#include "ogrsf_frmts.h"
#include "gdal_priv.h"


namespace UGC {

class UGFileVectorOGR : public UGFileParseVector  
{
public:
	UGFileVectorOGR();
	virtual ~UGFileVectorOGR();
	
public:
	//////////////////////////////////////////////////////////////////////////
	// 读取函数
	//////////////////////////////////////////////////////////////////////////
	
	//! \brief 准备读取一个数据文件
	virtual UGbool OpenForRead(const UGString& strFileName);
	
	//! \brief 得到图层的数目
	virtual UGint GetLayerCount();
	
	//! \brief 得到指定序号的图层信息。
	virtual UGbool GetLayerInfo(UGint nIndex, UGString& strLayerName, 
		UGint& nLayerType, UGString& strSubName);
	
	//! \brief 关闭文件
	virtual void Close();
	
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
	virtual UGbool IsEOF();
	
	//! \brief 开始读取一条记录，
	virtual void BeginReadOneRecord();
	
	//! \brief 读取一条记录中的几何对象
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
	// 公共询问函数
	//////////////////////////////////////////////////////////////////////////
	//! \brief 是否有导入的数据集的名字根据图层来命名，否则按照用户给出的名字来命名
	//! 有些数据导入时是一套数据
	virtual UGbool IsDatasetNameByLayer();

//public:
//	//! \brief 定位到当前 Layer
//	void GetLayerAt(UGint nIndex);


private:
	//! \brief m_pOGRDS 与 当前文件对应 
	OGRDataSource  *m_pOGRDS;
	
	//! \brief 当前图层
	OGRLayer *m_pLayer;

	//! \brief 当前记录
	OGRFeature *m_pFeature;

	//! \brief OGRDriver名
	UGString m_strDriver;

	//! \brief 当前记录的字段信息
	OGRFeatureDefn *m_poFDefn;

	//! \brief 图层的记录数
	UGint m_nFeatureCount;

private:
	//! \breif 判断是否作为单一图层处理
	UGbool IsSingleLayer();
	
	//! \brief 得到数据集类型,在 GetLayerInfo()中调用
	UGbool GetDatasetType(OGRwkbGeometryType ogrGeoType, UGDataset::DatasetType &datasetType);

	//! \breif 字段信息转换
	UGbool OGRFieldDefnToUGCFieldInfo(OGRFieldDefn *ogrFieldDefn, UGFieldInfo &fieldInfo);

	//! \brief 以下几个函数都是用来将 OGR 的几何对象转换成 UGC 的几何对象
		typedef std :: vector<UGPoint2D> UGVecPoint2Ds;
		typedef std :: vector<UGint> UGVecInts;

		//! \brief 从OGRPolygon 中得到构面的点串和点数
		void ConverPolygon( OGRPolygon *poPolygon, UGVecPoint2Ds& points, UGVecInts& PolyCount)const;

		//! \brief 由 OGRLineString 转 UGGeoLine
		void ConvertLine(OGRLineString *poPolyline, UGPoint2D *&pPoints, int &nPointCount);
		
		//! \brief 由 OGRGeometryCollection 转 UGGeoCompound
		void ConvertCollection(OGRGeometryCollection *poCollection, UGGeoCompound *pGeoCompoud);

	//! \brief m_pFeature(Label) 中构造Text
	UGbool MakeTextFromFeature(UGString &strText, UGPoint2D &pntAnchor, UGTextStyle &textStyle);

	//! \brief 得到几何对象的风格
	UGbool MakeStyleFromFeature(UGString &strText, UGStyle &geoStyle);

	//坐标转换中，Project适用于一般数据，但是GeoCoordSys 需要针对不同外部文件处理，目前只处理了 shapefile和mif/mid，miftab
	//!\brief 投影参数转换	在 virtual UGbool GetSpatialRef(UGPrjCoordSys& spatialRef); 中调用
	UGbool OGRPrjToUGC(OGRSpatialReference *poSpatialRef, UGProjection &PJObject, UGPrjParams &PJParams);

	//!\brief Datum 转换	在 virtual UGbool GetSpatialRef(UGPrjCoordSys& spatialRef); 中调用
	void OGRGeoCoordSysToUGC(OGRSpatialReference *poSpatialRef,  UGGeoCoordSys &PJGeoCoordSys);
};

}	//namespace UGC

#endif // !defined(AFX_UGFILEVECTOROGR_H__93BBC489_7396_4FB0_BAD3_7C9A44BBCD16__INCLUDED_)
