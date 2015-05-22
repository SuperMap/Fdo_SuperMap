// UGDataHistory.h: interface for the UGDataHistory class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGDATAHISTORY_H__2D9823AA_E642_44D1_980A_A3807F5DD64F__INCLUDED_)
#define AFX_UGDATAHISTORY_H__2D9823AA_E642_44D1_980A_A3807F5DD64F__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Engine/UGRecordset.h"
#include "Engine/UGDataPool.h"

namespace UGC
{
	//编辑历史信息,包含操作的什么图层,操作的对象id数组,操作的类型
struct EditHistoryInfo {
	UGDatasetVector* pDatasetVector;
	UGArray<UGint> nIDs;
	UGint nOptType;
};


class ENGINE_API UGDataHistory  
{
public:
	UGDataHistory();
	virtual ~UGDataHistory();
public:
	enum OptType{				//对象操作类型
			OPT_ADDNEW=0,		//添加新对象
			OPT_MODIFIED=1,		//对象有所改变
			OPT_DELETE=2,		//对象被删除
	};

public:
	UGbool RemoveAllEvent();
	UGbool Goto(
		UGint nEventIndex);							  //	

	UGbool GetEventInfo(                                //取得事件信息
		UGint nEventIndex,                             //事件的索引
		UGint & nAction,                               //
		UGint & nLayerIndex,                           //事件所在图层，如果事件发生在多个图层，那么只返回最后一个图层的索引
		UGString & strNote);							  //事件说明	

	UGint GetCurrentIndex();                           //当前事件的索引

	UGint GetCapacity();                               //设置一个对象表中最大能容纳的记录数

	UGint GetMaxEvtCount();                            //取得最大事件数

	UGint SetCapacity(                                 //设置一个对象表中最大能容纳的记录数
		UGint lMaxSize);

	UGint SetMaxEvtCount(                              //设置最大事件数
		UGint lEvtCount);

	UGbool RemoveEvent(	                              //按照索引删除事件
		int lEvtIndex);								  //事件的索引

	UGbool BeginEvent(								  //开始一个事件	
		UGint nAction=0,								  //当前的action,如果为0
													  //表示使用绑定地图当前的action			
		UGString strEvtNote="");					  //事件的说明	

	void EndEvent(									  //结束一个事件
		UGbool bRecord=TRUE);							  //是否对刚才发生的事件进行记录	
	

	//******************************************************************************//
   //*			此函数必须在beginevent和EndEvent之间调用,可以进行多之调用。		  *//
  //******************************************************************************//
	UGbool SetEvtInfo(								  //设置事件的内容	
		OptType etype,								  //对象的操作类型
		UGRecordset* pRecordset);		  //对象所在记录集，不能为NULL


	UGbool GoBack();									  //后退，撤销当前的事件，
													  //回到上一事件，成功返回true	

	UGbool GoForward();                                 //前进，恢复下一事件

	UGbool CanGoForward();							  //是否可以前进	

	UGbool CanGoBack();								  //是否可以回退		

	
	UGint GetEvtCount();								  //取得事件总数	
	
	//added by xielin 2007-05-23 
	//! \brief 数据集释放的时候调用该接口
	UGbool OnDatasetDestory(UGDataset* pDt);
	
	//! \brief 得到编辑的历史信息数组
	UGArray<EditHistoryInfo> GetEditHistoryInfo();

protected:
	UGDataPool * m_pDataPool;
	UGString m_strEvtTbName;							  //事件表的名称
	UGbool m_bEvtBegin;								  //事件是否已经开始	
	UGint m_nAction;									  //事件的action	
	UGString m_strEvtNote;							  //事件的说明
	UGArray<UGint> m_arEvtIndex;				  //事件的索引	
	UGint m_nCurEvtIndex;							  //当前事件的索引	
	//{{qiuli 03.5.6
	UGbool m_bGoback;
	//}}qiuli 03.5.6

	UGArray<EditHistoryInfo> m_aryEditHistoryInfo;   //保存edit操作的历史记录信息,内部使用,不开放

private://抱歉啦，仅供内部使用！ 
	
	//在数据集中修改记录集中包含的对象
	void ModifyGeometry(UGRecordset *pRs,				//记录集
						UGDatasetVector *pDtV);			//数据集

	//在数据集中添加记录集中包含的对象   
	void AddNewGeometry(UGRecordset *pRs,				//记录集
						UGDatasetVector *pDtV); 			//数据集
 
	//在数据集中删除记录集中包含的对象 
	void DeleteGeometry(UGRecordset *pRs,				//记录集
						UGDatasetVector * pDtV);			//数据集

};

}
#endif // !defined(AFX_UGDATAHISTORY_H__2D9823AA_E642_44D1_980A_A3807F5DD64F__INCLUDED_)
