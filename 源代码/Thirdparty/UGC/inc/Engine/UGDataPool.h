// UGDataPool.h: interface for the UGDataPool class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATAPOOL_H__C7A7F855_B011_4769_8E30_FD51EEF9A26D__INCLUDED_)
#define AFX_UGDATAPOOL_H__C7A7F855_B011_4769_8E30_FD51EEF9A26D__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Engine/UGDatasetVector.h"
#include "Engine/UGDataSource.h"

//=====================================================================================
#define EVTINFTB		"EventInfo"			//保存所有事件表信息的表名
#define EVTTB			"EventTable"			//唯一的事件表表名
#define EVTTBNAME		"EventTbName"		//事件表的表名
#define EVTTBID			"EvtTbID"			//事件表的id
#define CUREVTID		"CurrentEvt"		//当前事件的id
#define EVTCOUNT		"EventCount"		//事件的数目
#define LASTEVTID		"LstEventID"		//最新的EventID
#define FIRSTEVTID		"FrtEventID"		//最早的EventID

#define OBJINFTB		"ObjInf"			//保存所有对象表信息的表名
#define OBJTBNAME		"ObjTbName"			//对象表的表名
#define DATASETHANDLE   "DatasetHandle"         //数据集的指针
#define OBJTBID			"ObjTbID"			//对象表的ID
#define OBJTBREF		"ObjTbRef"			//对象表引用计数
#define OBJTBISSDB      "objTbIsSDB"		//是否保存了sdb数据集的数据	
#define OBJTBHASSTYLE   "objTbHasStyle"	    //是否有[smEvtGeoStyle]字段

#define	EVTID			"EventID"			//事件的id
#define EVTACTION		"EventAction"       //事件对应的Action值
#define EVTLAYER		"EventLayer"		//事件所发生的图层
#define EVTNOTE			"EventNote"			//事件的说明
#define EVTORDERID		"EventOrdID"		//事件先后顺序
#define SUBEVTID		"SubEventID"		//子事件的id，added by xielin 用于一个事件中有几个子事件的情况

#define	OBJID			"ObjectID"		//对象的id
#define EVTOPERATOR		"ObjOperator"		//事件中对象所作的操作
#define EVTGEOINDEX		"ObjIndexPos"	    //事件中几何对象在sdb中的索引

#define NOTTHISTB     0						//表不存在
#define EVTTYPETB		1						//事件表	
#define OBJTYPETB     2						//对象表

#define TEXTFIELDSIZE   80						//文本类型的字段长度

#define HANDLETEXTSIZE  8						//因为udb不支持8个字节的整型，存指针只能用text来存

#define SDBENGINE       1                       //是否时SDB引擎
#define GEOHASSTYLE     2                       //几何对象是否有SYTLE
//=====================================================================================



namespace UGC
{

class ENGINE_API UGDataPool  
{
public:
	UGDataPool();
	virtual ~UGDataPool();

public:
	UGbool ClearEvtTable(	                        //清空一个事件表 
		UGString strEvtTbName);                  //事件表的名称

	UGbool CreateObjectTableFromDataset(          //通过一个数据集建立对象表 
		UGDatasetVector * pDtV);

	UGbool CreateDatabase(						//创建并打开数据库,如果名字为空，系统会起一个随机的名字
		 UGString strDbName="");				//数据库名
	void DestoryDatabase();						//关闭并删除数据库
	UGbool OpenDatabase();						//打开数据库
	UGbool CloseDatabase();						//关闭数据库

	UGbool GetTbNameFromID(	                    //通过表的ID来获得表名
		UGString & strTbName,					//表名
		UGint  nTbType,							//表的类型，SMEVTTYPETB（事件表）或SMOBJTYPETB（对象表）
		const UGint & nTbID);					//表的ID
												//成功返回TRUE,失败返回FALSE

	UGint GetTbSize(                             //取得一个表的大小   
		UGString strTbName);                    //表名  
	
	UGint GetTbType(								//判断一个表的类型
		UGString strTableName,                   //表名
		UGint & lTableID);					    //表的ID
												//该函数返回值含义:
	                                            //-1:出错了，数据库没有打开
												//SMNOTTHISTB，表不存在；
												//SMEVTTYPETB，Event表；
												//SMOBJTYPETB, Object表。

	UGbool GetDatasetHandleFromObjTbName(	            //根据object表名取得数据集的指针
		const UGString & strObjTbName,           //对象表名
		UGlong & lDatasetHandle);                //数据集指针

	UGbool GetObjTbNameFromDatasetHandle(             //根据数据集指针取得obj表的名称
		const UGlong & lDatasetHandle,           //数据集指针
		UGString & strObjTbName);                //对象表的名称
	
	UGbool CreateEventTable(	                    //新建一个EventTable
		UGString strTbName,                      //EventTable的表名
		UGFieldInfos * pFieldInfoList);       //字段列表

	UGbool DeleteEventTable(						//删除一个保存地图操作的表，当地图
		                                        //关闭时要记住调用他哦
		UGString strTableName);					//表名
	
	
	
	UGbool Purge();								//清理数据库中所有的表

	//*******************************************************************************************//
	//一般objTable和数据集一一对应，当objTable对应的数据集所关联的图层全部关闭时方可删除此对象表 //
	//*******************************************************************************************//	
	UGbool DeleteObjTable(						//删除一个保存几何对象及其属性的表，
	                                        	//当一个图层被干掉时，需要调用此表
		UGString strObjTbName); 				    //图层名

	UGbool ReleaseObjTable(						//释放一个对象表,数据集释放的时候对应的东东都释放
		UGDataset* pDt);					//表名
		
	UGint SetMaxEventCount(						//设置最多能保存多少个编辑Event
		 UGint lEventCount);						//Event的个数
	UGint GetMaxEventCount();					//取得最多能保存多少个编辑Event
	UGint SetMaxEventSize(						//设置最多能保存多少个编辑对象（记录）
		 UGint lEventSize);						//Event的个数
	UGint GetMaxEventSize();						//取得最多能保存多少个编辑对象（记录）

	UGDatasetVector* GetEventInfoDv();
	
	UGDatasetVector* GetObjInfoDv();


protected: 
	UGString m_strDbName;						//数据库文件的名称	
	UGint m_nNextObjTbKey;						//生成的下一个对象表的关键字
public:
	UGint m_nMaxEventCount;						//最大的保存编辑事件的个数
	UGint m_nMaxEventSize;						//一个表中最大保存编辑对象（记录）的个数
	UGDataSource* m_pDatasource;

};


}
#endif // !defined(AFX_UGDATAPOOL_H__C7A7F855_B011_4769_8E30_FD51EEF9A26D__INCLUDED_)
