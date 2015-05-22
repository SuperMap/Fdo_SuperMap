#ifndef UGENGDEFS_H
#define UGENGDEFS_H

#include "Base/ugdefs.h"
#include "Geometry/UGGeoRegion.h"
namespace UGC
{

	
#define UGMAXONCEGEOSIZE	20971520
#define UGMAXROOTLEAFSIZE   1258496

#define UGRTREEEDITED		5
	
/* zengzm: ugdefs中有了, 这里就注释掉吧 	
#define __STR2__(x) #x
#define __STR1__(x) __STR2__(x)
#define __LOC__ __FILE__ "("__STR1__(__LINE__)") : "
*/	

//===================================================================================================================
//{{图层字段定义 
//===================================================================================================================
//		宏名				字段名				类型			说明		适用的图层类型
//...................................................................................................................
#define LF_OBJ_ID		"SmID"			// (dbLong)			内部编号	(All)
#define LF_USER_ID		"SmUserID"		// (dbLong)			用户编号	(All)
#define LF_TREE_INDEX	"SmKey"			// (dbLong)			四叉数索引	ALL Geometry Dataset.   
#define LF_LT_KEY		"SmLTKey"		// (dbLong)			网格索引	All Geometry Dataset.
#define LF_RB_KEY		"SmRBKey"		// (dbLong)			网格索引	All Geometry Dataset.
#define LF_GEO_POS		"SmGeoPos"		// (dbLong)			Geometry的位置	All Geometry Dataset.
#define LF_GEOMETRY		"SmGeometry"	// (dbLongBinary)	几何数据	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_GEO_TYPE		"SmGeoType"		// (dbSingle)		对象的类型	ltCAD ,because geometry data can't distinguish type of itself
#define LF_SDRI_W		"SmSdriW"		// (dbDouble)		最小横坐标	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_SDRI_N		"SmSdriN"		// (dbDouble)		最小纵坐标	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_SDRI_E		"SmSdriE"		// (dbDouble)		最大横坐标	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_SDRI_S		"SmSdriS"		// (dbDouble)		最大纵坐标	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_GRANULE		"SmGranule"		//(dbDouble)		对象颗粒度  ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_CHECKED_USER_ID	"SmCheckedUserID"	//(dbLong)	登录用户ID	(ALL)
#define LF_EDIT_STATE	"SmEditState"	//(dbInteger)		编辑状态	(ALL)
#define LF_SDRI_T		"SmSdriT"		// (dbDouble)		最小高程	ltTin
#define LF_SDRI_B		"SmSdriB"		// (dbDouble)		最大高程	ltTin
#define LF_SDRI_I		"SmSdriI"		// (dbDouble)		大小索引	ltNetwork, ltLine, ltRegion, ltTin, ltText
#define LF_NODE_ID		"SmNodeID"		// (dbLong)			节点编号，	ltNetwork,以前默认使用SmID,现在单独建立一个字段
#define LF_FNODE		"SmFNode"		// (dbLong)			起始节点	ltNetwork
#define LF_TNODE		"SmTNode"		// (dbLong)			终止节点	ltNetwork
#define LF_RESISTANCE_A	"SmResistanceA"	// (dbDouble)		正方向阻力	ltNetwork
#define LF_RESISTANCE_B	"SmResistanceB"	// (dbDouble)		负方向阻力	ltNetwork
#define LF_X			"SmX"			// (dbDouble)		点横坐标的	ltPoint & ltPoint3D
#define LF_Y			"SmY"			// (dbDouble)		点的纵坐标	ltPoint & ltPoint3D
#define LF_Z			"SmZ"			// (dbDouble)		点的高程	ltPoint3D
#define LF_LENGTH		"SmLength"		// (dbDouble)		长度		ltLine& Network
#define LF_AREA			"SmArea"		// (dbDouble)		面积		ltRegion
#define LF_PERIMETER	"SmPerimeter"	// (dbDouble)		周长		ltRegion 
#define LF_ASPECT		"SmAspect"		// (dbDouble)		坡向		ltTin
#define LF_SLOPE		"SmSlope"		// (dbDouble)		坡度		ltTin
#define LF_TOPO_ERROR	"SmTopoError"	// (dbLong)			拓扑错误	ltNetwork, ltLine
#define LIB_SMID		"SmLibTileID"

#define LF_CONJOINT_POINTS		"SmConjointPoints"	// (dbLongBinary)			TIN节点的临近点集合	ltPointGL
#define	LF_POINT_COLOR			"SmPointColor"		//TIN节点的颜色，负值表示无效

//{{ route数据集及其Section表的字段
#define LF_ROUTE_ID				"SmRouteID"
#define LF_USER_ROUTE_ID		"SmUserRouteID"

#define LF_SECTION_ARC			"SmEdgeID"
#define LF_SECTION_FROM_MEASURE "SmFromMeasure"	
#define LF_SECTION_TO_MEASURE	"SmToMeasure"	
#define LF_SECTION_FROM_POS		"SmFromPos"		
#define LF_SECTION_TO_POS		"SmToPos"		

//}}

//{{
#define LF_MATCH_ERROR "SmMatchError" // 使用CSmDataSource::UpdateFromLcaPnts()方法
                                          // 从标志点匹配属性数据到其他数据集时（面），
                                          // 记录下匹配点数目。
                                             
//}}

//{{
#define LF_TOPO_LPOLY  "SmTopoLPolygon"
#define LF_TOPO_RPOLY  "SmTopoRPolygon"

//}}
//					0	- 无错误
//					1	- 起始节点是悬节点
//					2	- 终止节点是悬节点
//					3	- 两个节点都是悬节点
//					其他- 由王红定义...)

/*
#define LF_RASTER_LEVEL		"SmRLevel"		// (dbLong)			栅格分辨率			ltRaster
#define LF_RASTER_INDEX_X		"SmRIndexX"		// (dbLong)			栅格块X索引(列号)	ltRaster
#define LF_RASTER_INDEX_Y		"SmRIndexY"		// (dbLong)			栅格块Y索引(行号)	ltRaster

#define LF_SYMBOL_STYLE			"SmSStyle"
#define LF_SYMBOL_SIZE			"SmSSize"
#define LF_SYMBOL_ROTATION		"SmSRotation"
#define LF_SYMBOL_TEXT			"SmSText"

#define LF_PEN_STYLE			"SmPStyle"
#define LF_PEN_WIDTH			"SmPWidth"
#define LF_PEN_COLOR			"SmPColor"

#define LF_BRUSH_STYLE			"SmBStyle"
#define LF_BRUSH_FRONT_COLOR	"SmBFColor"
#define LF_BRUSH_BACK_COLOR		"SmBBColor"
 */

//===================================================================================================================
//}}图层字段定义
//===================================================================================================================

#if PACKAGE_TYPE==PACKAGE_UGC


//说明：定义一些在引擎中需要使用的系统表的名字

//===============================================================================
//			宏名					名称						说明		
//................................................................................
#define		TN_REGISTER_TABLE		"SmRegister"			//数据库中矢量数据集的注册表，记所有矢量数据集的信息	
#define		TN_IMGREGISTER_TABLE	"SmImgRegister"			//数据库中影像数据集的注册表，记所有影像数据集的信息	
#define     TN_DATASOURCE_INFO		"SmDataSourceInfo"		//数据源信息表
#define		TN_META_ELEM_TABLE		"SmMetaElementTable"	//数据源中存放所有元数据的表
#define		TN_USERS				"SmUsers"				//存放长事务用户
#define		TN_TABLE_FIELDINFO		"SmFieldInfo"			//存放字段相关的信息，如别名、Format等



//说明：定义一些在引擎中需要使用的存储过程名.

//===============================================================================
//			宏名					名称						说明		
//................................................................................
#define		SP_CREATE_USER			"smsp_CreateUser"		//创建用户的存储过程
#define		SP_CREATE_DATASET		"smsp_CreateDataset"	//创建数据集的存储过程
#define		SP_DELETE_DATASET		"smsp_DeleteDataset"	//删除数据集的存储过程
#define		SP_SET_BOUNDS			"smsp_SetBounds"		//设置数据集范围存储过程
#define		SP_COPY_DATASET			"smsp_CopyDataset"		//本地复制数据集的存储过程
#define		SP_CREATE_DATABASE		"smsp_CreateDatabase"	//创建新的数据源的存储过程

//SmRegister表中的字段=======================================================================
//			宏名				字段名					类型			说明	
//...........................................................................................
#define		RF_ID				"SmDatasetID"		//(dbLong)		//Dataset ID
#define		RF_DATASET_NAME		"SmDatasetName"		//(dbText)		//Dataset Name
#define		RF_TABLE_NAME		"SmTableName"		//(dbText)		//Geomey and Properties Table Name
#define		RF_INDEX_TABLE_NAME	"SmIndexTableName"	//(dbText)		//Index Table Name
#define		RF_SUB_TABLE_NAME	"SmSubTableName"	//(dbText)		//Sub Table name
#define		RF_IS_SUB			"SmIsSub"			//(dbChar)		//Is/Not sub table
#define		RF_DATASET_TYPE		"SmDatasetType"		//(dbInteger)	//Dataset's type
#define		RF_RECORD_COUNT		"SmRecordCount"		//(dbInteger)	//Object count in dataset.
#define		RF_INDEX_LEVEL		"SmIndexLevel"		//(dbInteger)	//Index level of the dataset.
#define		RF_LEFT				"SmLeft"			//(dbLong)		//Dataset Bounds' Left
#define		RF_RIGHT			"SmRight"			//(dbLong)		//Dataset Bounds' Right
#define		RF_TOP				"SmTop"				//(dbLong)		//Dataset Bounds' Top
#define		RF_BOTTOM			"SmBottom"			//(dbLong)		//Dataset Bounds' Bottom
#define		RF_MAXZ				"SmMaxZ"			//(dbDouble)	//Max Z Value of Dataset
#define		RF_MINZ				"SmMinZ"			//(dbDouble)	//Min Z Value fo Dataset
#define		RF_GRID_SIZE		"SMGRIDSIZE"		//(dbDouble)	//Grid Size fo Dataset, Used for Index.
#define		RF_USER_ID			"SmUserID"			//(dbInteger)	//Long transaction user id.
#define		RF_DT_VERSION		"SmDtVersion"		//(dbInteger)	//Data updated version.
#define		RF_OPTION			"SmOption"			//(dbInteger)	//Option of the dataset.
#define		RF_ENC_TYPE			"SmEncType"			//(dbInteger)	//Spatial data encoded type.
#define		RF_DESCRIPTION		"SmDescription"		//(dbText)		//Description of the dataset.
#define		RF_THUMB			"SmThumb"			//(dbLongBinary)//Thumb of the dataset.
#define		RF_TOLERANCE_FUZZY	"SmToleranceFuzzy"	//(dbDouble)	//Fuzzy tolerance of the dataset.
#define		RF_TOLERANCE_DANGLE	"SmToleranceDangle"	//(dbDouble)	//Dangle tolerance of the dataset.
#define		RF_TOLERANCE_NODESNAP "SmToleranceNodeSnap"	//(dbDouble)//NodeSnap tolerance of the dataset.
#define		RF_TOLERANCE_SMALL_POLYGON	"SmToleranceSmallPolygon"	//(dbDouble)	//Small polygon tolerance of the dataset
#define		RF_TOLERANCE_GRAIN	"SmToleranceGrain"	//(dbDouble)	//Grain tolerance of the dataset.
#define		RF_LASTUPDATE		"SmLastUpdate"		//(dbDate)		//The lastupdate time of the dataset.
#define		RF_MAX_GEOMETRY_SIZE	"SmMaxGeometrySize"	//(dbDouble)//The max geometry size of the dataset.
#define		RF_ONCE_FETCH_COUNT	"SmOnceFetchCount"	//(dbInteger)	//Once fetch count from server.
#define		RF_OPTIMIZE_COUNT	"SmOptimizeCount"	//(dbInteger)	//Optimize parameter of the dataset.
#define		RF_OPTIMIZE_RATIO	"SmOptimizeRatio"	//(dbFloat)		//Optimize parameter of the dataset.
//...........................................................................................

//SmImgRegister表中的字段=======================================================================
//			宏名				字段名					类型			说明	
//...........................................................................................
//#define		RF_ID					"SmDatasetID"		//(dbLong)		//Dataset ID
//#define		RF_DATASET_NAME			"SmDatasetName"		//(dbText)		//Dataset Name
//#define		RF_TABLE_NAME			"SmTableName"		//(dbText)		//Geomey and Properties Table Name
//#define		RF_DATASET_TYPE			"SmDatasetType"		//(dbInteger)	//Dataset's type
//#define		RF_OPTION				"SmOption"			//(dbInteger)	//Option of the dataset.
#define		RF_PIXEL_FORMAT				"SmPixelFormat"		//(dbInteger)	//Pixel format of the raster.
#define		RF_WIDTH					"SmWidth"			//(dbInteger)	//Width(pixels) of the raster.
#define		RF_HEIGHT					"SmHeight"			//(dbInteger)	//Height(pixels) of the raster.
#define		RF_E_BLOCK_SIZE				"SmeBlockSize"		//(dbInteger)	//e block size of the raster.
#define		RF_MAX_BLOCK_SIZE			"SmMaxBlockSize"	//(dbInteger)	//Max block size of the raster.
//#define		RF_MAXZ					"SmMaxZ"			//(dbDouble)	//Max Z Value of Dataset
//#define		RF_MINZ					"SmMinZ"			//(dbDouble)	//Min Z Value of Dataset
#define		RF_PYRAMID					"SmPyramid"			//(dbText)		//Parymid table name of the raster.
#define		RF_PYRAMID_LEVEL			"SmPyramidLevel"	//(dbInteger)	//Parymid level of the dataset.
#define		RF_BLOCK_SIZE				"SmBlockSizes"		//(dbInteger)	//Block size of the raster.
#define		RF_PALETTE					"SmPalette"			//(dbLongBinary)//Palette of the raster.
#define		RF_GEO_LEFT					"SmGeoLeft"			//(dbDouble)	//Dataset Bounds' Left
#define		RF_GEO_RIGHT				"SmGeoRight"		//(dbDouble)	//Dataset Bounds' Right
#define		RF_GEO_TOP					"SmGeoTop"			//(dbDouble)	//Dataset Bounds' Top
#define		RF_GEO_BOTTOM				"SmGeoBottom"		//(dbDouble)	//Dataset Bounds' Bottom
#define		RF_CLIP_REGION				"SmClipRegion"		//(dbLongBinary)//Clip region of raster.
#define		RF_TOLERANCE_SMALLPOLYGON	"SmToleranceSmallPolygon" 
//...........................................................................................


//SmDataSourceInfo表中的字段=======================================================================
//			宏名				字段名					类型			说明	
//...........................................................................................
#define		DF_VERSION			"SmVersion"			//dbLong		数据源版本号
#define		DF_FLAG				"SmFlag"			//dbLong		数据源标志
#define		DF_COORDSYS			"SmCoordSys"		//dbLong		坐标系
#define		DF_COORDUNIT		"SmCoordUnit"		//dbLong		坐标单位
#define		DF_DISTANCEUNIT		"SmDistanceUnit"	//dbLong		长度单位
#define		DF_PROJECTINFO		"SmProjectInfo"		//dbLongBinary	//投影系参数
#define		DF_DSDESCRIPTION	"SmDsDescription" 
//...........................................................................................

//SmFieldInfo表中的字段=======================================================================
//			宏名				字段名					类型			说明	
//...........................................................................................
#define		SMF_FIELD_ID		"SmID"				//dbInteger		字段ID
#define		SMF_TABLE_NAME		"SmTableName"		//dbText		数据表名
#define		SMF_DATASET_ID		"SmDatasetID"		//dbLong		数据集的ID
#define		SMF_FIELD_NAME		"SmFieldName"		//dbText		字段名
#define		SMF_FIELD_CAPTION	"SmFieldCaption"	//dbText		字段别名
#define		SMF_FIELD_TYPE		"SmFieldType"		//dbLong		字段的类型
#define		SMF_FIELD_FORMAT	"SmFieldFormat"		//dbText		字段显示格式
#define		SMF_FIELD_SIGN		"SmFieldSign"		//dbLong		字段标识，如NodeID,FNode,TNode,EdgeID,RouteID等
#define		SMF_FIELD_SIZE		"SmFieldSize"		//dbLong		字段长度
#define		SMF_FIELD_DOMAIN	"SmFieldDomain"		//dbText		字段值域
#define		SMF_FIELD_UPDATABLE	"SmFieldUpdatable"	//dbBoolean		字段值是否可修改
//...........................................................................................

//时序数据库需要使用的字段=======================================================================
//			宏名				字段名					类型			说明	
//...........................................................................................
#define		SEQ_START			"SmSequenceStart"	//dbDate		开始时间点
#define		SEQ_END				"SmSequenceEnd"		//dbDate		结束时间点
#define		SEQ_STATE			"SmSequenceState"	//dbBoolean		时序状态
#define		SEQ_ORG_ID			"SmSequenceOrgID"	//dbLong		时序编辑的最原始的SMID
//...........................................................................................

enum DatasetState
{
	dsCheckedOut	= 0x00000001,
	dsLocked		= 0x00000002		
};

enum LongTransState
{
	ltsAdded		= 0x00000001,
	ltsModified		= 0x00000002,
	ltsDeleted		= 0x00000004
};

enum SpatialQueryOption
{
	SQInner			= 0x00000001,
	SQMaybe			= 0x00000002,
	SQOuter			= 0x00000004
};

struct UG_INDEX_ITEM
{
	UGuint left, top, right, bottom;
	UGuint nID;
	UGuint nPos;
};

struct UG_CAD_INDEX_ITEM
{
	UGuint left, top, right, bottom;
	UGuint nID;
	UGuint nPos;
	UGuint nType;
};

struct UG_SUPER_INDEX_ITEM
{
	UGuint left, top, right, bottom;
	UGuint nID;
	UGuint nPos;
	UGuint nType;
	UGuint dwX;
	UGuint dwY;
	UGdouble dZ;
};

struct UG_META_ELEMENT
{
	UGint nOID;
	UGint nLevel;
	UGint nParent;
	UGint nChild;
	UGint nPrevID;
	UGint nNextID;
	UGString strName;
	UGString strValue;

	UG_META_ELEMENT()
	{
		nOID = 0;
		nLevel = 0;
		nParent = 0;
		nChild = 0;
		nPrevID = 0;
		nNextID = 0;
		strName = "";
		strValue = "";
	}
};

struct UG_DATASET_TIER_NAME
{
	UGString strDataset;
	int nTileID;
	UG_DATASET_TIER_NAME()
	{
		strDataset = "";
		nTileID    = -1;
	}
};

#endif // end declare ugc sdk
}
#endif
