/**  \file UGLayersRecordsetsManager.h
   \brief 实现Layers中记录集的管理
   \author lugw
   \attention 
   Copyright(c) 1996-2007 SuperMap GIS Technologies, Inc.<br>
   All Rights Reserved.
 */ 

#if !defined(AFX_UGLAYERSRECORDSETSMANAGER_H__EE094C5F_85C5_441B_9AB8_CCA855D24FEE__INCLUDED_)
#define AFX_UGLAYERSRECORDSETSMANAGER_H__EE094C5F_85C5_441B_9AB8_CCA855D24FEE__INCLUDED_

#include "Base/ugdefs.h"
#include "UGLayer.h"


namespace UGC
{

	struct UGRecordsetWithLayer 
	{
		UGRecordset* pRecordset;
		UGArray<UGLayer*> pLayerArray;
		UGRecordsetWithLayer()
		{
			pRecordset = NULL;
			pLayerArray.RemoveAll();
		};
	};

	struct UGDatasetWithRecordset
	{
		UGDatasetVector* pDv;
		UGArray<UGRecordsetWithLayer> pRecordsetArray;
		UGDatasetWithRecordset()
		{
			pDv = NULL;
			pRecordsetArray.RemoveAll();
		};
	};

class UGLayersRecordsetsManager  
{
public:
	UGLayersRecordsetsManager();
	virtual ~UGLayersRecordsetsManager();
	//! \brief 得到对应图层的Recordset，内部负责管理Recordset
	/**
	函数功能详细描述
	\param Layers       该Layers下的所有图层[in] 
	\param pos          当前绘制层位置[in]
	\param pLayer       当前绘制层[in]
	\param pGraphics    当前显示引擎[in]
	\param pDrawing     当前绘制参数[in]
	\param bTemp        该记录集是否为临时[in/out]
	\return 该层记录集
	*/
	UGRecordset* FindRecordsetWithLayer(UGList<UGLayer*> Layers, UGLayer* pLayer, UGGraphics* pGraphics, UGDrawing *pDrawing, UGbool& bTemp);

	//! \brief 获取当前地图保存的记录集大小
	UGuint GetSize();
	//! \brief 清空地图所有的记录集
	void RemoveAll();

protected:

	UGbool GetQueryDef(UGList<UGLayer*> Layers, UGLayer* pLayer, UGGraphics* pGraphics, UGDrawing *pDrawing, UGRecordsetWithLayer& RecordsetWithLayerTemp);
	UGbool AddRecordsetWithLayer(UGRecordsetWithLayer& RecordsetWithLayerTemp,UGbool bFindDv);

	UGbool AppendQueryDefFields(UGQueryDef& qfTo,UGQueryDef& qfFrom);

private:
	UGArray<UGDatasetWithRecordset> m_pDatasetWithRecordset;
	UGArray<UGDatasetVector*> m_pDifDatasetsVector;
	UGuint m_nSize;
};

}

#endif // !defined(AFX_UGLAYERSRECORDSETSMANAGER_H__EE094C5F_85C5_441B_9AB8_CCA855D24FEE__INCLUDED_)
