/* 
	\file UG3DPointSet.h
	\brief 三维矢量点集类。
	\author 马柳青
	\attention 点集封装了其内部点的风格，单独点没有风格，点集有风格
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UG3DPOINTSET_H__2D47E261_BD00_4CDA_9BBE_C552F3682332__INCLUDED_)
#define AFX_UG3DPOINTSET_H__2D47E261_BD00_4CDA_9BBE_C552F3682332__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "Scene/UGRenderable.h"
#include "Base/UGThread.h"
#include "Scene/UGColorValue.h"
#include "Base/UGString.h"
#include "Engine/UGDataset.h"
#include "Scene/UGQuadDataset.h"
#include "Scene/UG3DStyle.h"
#include "Scene/UGMovableObject.h"

//! \brief 类的简要说明。
//! \remarks 备注信息。
namespace UGC
{

	class SCENE_API UG3DPointSet: public UGQuadDataset
	{
	public:
		//  点集对象可以直接连接数据集，也可以不连接自己添加点，
		//  设置点集对象所连接的数据集和数据集索引文件
		UG3DPointSet();	
		//! \brief 析构函数
		virtual ~UG3DPointSet();
 
		//! \brief 继承与RenderableObject的纯虚函数
		//! \param &drawArgs [in]	
		virtual void Initialize();
		//! \brief 继承与RenderableObject的纯虚函数
		//! \param &drawArgs [in]	
		virtual void Update();
		//! \brief 继承与RenderableObject的纯虚函数
		//! \param &drawArgs [in]	
		virtual void Render();
		//! \brief 继承与RenderableObject的纯虚函数
		//! \param &drawArgs [in]	
		virtual void Release();

		//! \brief 设置点的风格。
		//! \param 
		void SetPointStyle(const UG3DPointStyle& pointStyle);	
		//! \brief 得到点的风格。
		UG3DPointStyle& GetPointStyle();
		// 添加一个点，注意传入的参数是空间坐标
		void AddPoint(UGReal x,UGReal y,UGReal z);
		// 添加一组点，数组中是按x,z,z排列的,并且都是空间坐标
		void AddPoints(UGReal* pVertex,UGint nCount);
		//删除所有点
		void RemoveAllPoint();
		UGReal *GetVerTex(); 

		virtual void AddDataFromDataset(const UGVectorDatasetAtr& DatasetAtr);

		virtual UGbool InterSectWithRadial(const UGVector3R& nearPos, const UGVector3R& farPos);
	protected:
		// 从关联的数据集中加入点
		void AddDatSetPoints(const UGVectorDatasetAtr& DatasetAtr);
		void RenderEntityPoint(UGReal x,UGReal y,UGReal z);
	private:
		// malq-注意这里存储的都是大地直角坐标系的坐标，而不是经纬度坐标
		//UGList<UGPoint3D*> m_PntList;
		//! \brief  
		UGReal* m_pVertex;
		//! \brief
		UGint m_nVertexCount;
		//! \brief
		UG3DPointStyle m_PointStyle;
		//! \brief
		UGMutex m_mutex;
		//! \brief
		UGTexture* m_pTexture;
		//! \brief
		UGVectorDatasetAtr m_DatasetAtr;
		//! \brief
		UGbool m_bNeedTestVisible;

		// 临时使用
		UGint m_nSelectedPointIndex;
	};
}

#endif // !defined(AFX_UG3DPOINTSET_H__2D47E261_BD00_4CDA_9BBE_C552F3682332__INCLUDED_)
