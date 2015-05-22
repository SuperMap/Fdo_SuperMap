/* 
	\file UG3DLineSet.h
	\brief 线集类，具有统一的风格。
	\author 马柳青
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/


#if !defined(AFX_UG3DLINESET_H__A7885671_BEB3_4550_8793_31AF22BB8CF8__INCLUDED_)
#define AFX_UG3DLINESET_H__A7885671_BEB3_4550_8793_31AF22BB8CF8__INCLUDED_

#include "base/ugdefs.h"
#include "Scene/UGRenderable.h"
#include "Algorithm/UGPoint2D.h"
#include "Engine/UGDataset.h"
#include "Scene/UG3DLine.h"
#include "Scene/UGQuadDataset.h"
#include "Scene/UG3DStyle.h"

//! \brief 类的简要说明。
//! \remarks 备注信息。
namespace UGC
{
class SCENE_API UG3DLineSet: public UGQuadDataset
{
public:
	//! \brief 构造函数
	UG3DLineSet();
	//! \brief 析构函数
	virtual ~UG3DLineSet();
	//! \brief 释放
	virtual void Release();
	//! \brief 初始化
	virtual void Initialize();
	//! \brief 更新
	virtual void Update();
	//! \brief
	virtual void Render();
	//! \brief 添加单个线对象
	void AddLine(UG3DLine* pLine);
	//! \brief 得到线对象的风格
	UG3DLineStyle& GetLineStyle();
	//! \brief 设置线对象的风格
	void SetLineStyle(const UG3DLineStyle& lineStyle);
	//! \brief 
	virtual void AddDataFromDataset(const UGVectorDatasetAtr& DatasetAtr);
	virtual UGbool InterSectWithRadial(const UGVector3R& nearPos, const UGVector3R& farPos);
	virtual void SetPickStatus(UGbool status);
	virtual void NotifyActiveCamera(UGCameraBase* pActiveCamera);

	UG3DLine *Get3DLine();	
	//! \brief 移出所有子对象
	void RemoveAllSubLines();
protected:
	//! \brief 从矢量数据集中添加线对象
	void AddDatasetLines(const UGVectorDatasetAtr& DatasetAtr);
	
	//! \brief 子对象
	UGList<UG3DLine*> m_SubLines;
	//! \brief 线对向风格
	UG3DLineStyle m_LineStyle;
	// added by luofx
	UGVectorDatasetAtr m_DatasetAtr;
	//! \brief 
	UGbool m_bNeedTestVisible;


};
}


#endif // !defined(AFX_UG3DLINESET_H__A7885671_BEB3_4550_8793_31AF22BB8CF8__INCLUDED_)
