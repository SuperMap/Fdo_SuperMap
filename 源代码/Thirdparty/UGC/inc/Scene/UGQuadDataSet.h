// UGQuadDataset.h: interface for the UGQuadDataset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGQUADDataset_H__57354CBC_0666_400A_81A6_D7D2D040F237__INCLUDED_)
#define AFX_UGQUADDataset_H__57354CBC_0666_400A_81A6_D7D2D040F237__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGPrerequisites.h"
#include "Scene/UGRenderObject.h"
#include "Scene/UGVectorDatasetAtr.h"
namespace UGC
{
class UGDataset;
class SCENE_API UGQuadDataset: public UGRenderObject
{
public:
	UGQuadDataset(const UGVectorDatasetAtr& DatasetAtr);
	UGQuadDataset();
	virtual ~UGQuadDataset();
	virtual void Release();
	virtual void Initialize();
	virtual void Update();
	virtual void Render();	
	void SetNeedTestVisible(UGbool bNeedTestVisible);
	// 这个函数是把数据集设置到显示集中去，如果bImmediately=FALSE数据并不立即加载到显示窗口，等需要显示
	//的时候才加载，所以数据集设置后，不可立即释放数据集， 如果bImmediately=TRUE则数据立即加载到现实窗口
	//数据集可以在连接后释放
	void ConnectDataset(const UGVectorDatasetAtr& DatasetAtr,UGbool bImmediately=TRUE);
	UGVectorDatasetAtr GetConnectDataset();
	// 用于加载非数据集数据的时候，添加自己构造的点，添加完毕后要使用这个函数标志数据已经加载
	void SetDataLoaded(UGbool bLoaded=TRUE);
	virtual void AddDataFromDataset(const UGVectorDatasetAtr& DatasetAtr);
protected:
	UGbool m_bNeedTestVisible;
	UGVectorDatasetAtr m_DatasetAtr;
};
}

#endif // !defined(AFX_UGQUADDataset_H__57354CBC_0666_400A_81A6_D7D2D040F237__INCLUDED_)
