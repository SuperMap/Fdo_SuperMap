/* 
	\file UGRenderTarget.h
	\brief 文件内容的简要描述。
	\author 文件作者
	\attention
	Copyright(c) 1996-2007 SuperMap GIS Technologies,Inc.<br>
	All Rights Reserved
	<b>更新说明：。</b>
	<em>1、第一条说明。</em>
	<em>2、第二条说明。</em>
*/

#if !defined(AFX_UGRENDERTARGET_H__3E5C0D45_C40D_4902_AFCB_E918ED708515__INCLUDED_)
#define AFX_UGRENDERTARGET_H__3E5C0D45_C40D_4902_AFCB_E918ED708515__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Scene/UGPrerequisites.h"
#include "Scene/UGViewport.h"
#include "Base/UGString.h"
#include "Base/UGTime.h"
#include "Base/UGDict.h"
#include "Scene/UGMomentumCamera.h"
#include "Base/UGTextStyle.h"

namespace UGC
{

class SCENE_API UGRenderTarget  
{

public:

	// 状态枚举常量
    enum StatFlags
    {
        SF_NONE           = 0,
        SF_FPS            = 1,
        SF_AVG_FPS        = 2,
        SF_BEST_FPS       = 4,
        SF_WORST_FPS      = 8,
        SF_TRIANGLE_COUNT = 16,
        SF_ALL            = 0xFFFF
    };

	// 帧状态
    struct FrameStats
    {
        UGfloat lastFPS;
        UGfloat avgFPS;
        UGfloat bestFPS;
        UGfloat worstFPS;
        UGulong bestFrameTime;
        UGulong worstFrameTime;
        UGint triangleCount;
    };
	
public:

	UGRenderTarget();

	virtual ~UGRenderTarget();
	
	
	virtual const UGString& GetName(void) const;
	virtual void GetMetrics(UGuint& width, UGuint& height, UGuint& colourDepth);

	virtual UGuint GetWidth(void) const;
	virtual UGuint GetHeight(void) const;
	virtual UGuint GetColourDepth(void) const;
	
	virtual void Update();
	virtual void SetRenderTargetsFont(const UGTextStyle& textStyle);


	virtual UGViewport* AddViewport(UGMomentumCamera* cam, UGint ZOrder = 0, UGfloat left = 0.0f, UGfloat top = 0.0f,
		                           UGfloat width = 1.0f, UGfloat height = 1.0f);

	virtual UGushort GetNumViewports(void) const;
	
	virtual UGViewport* GetViewport(UGushort index);
	
	virtual void RemoveViewport(UGint ZOrder);
	
	virtual void RemoveAllViewports(void);
	
	virtual void GetStatistics(UGfloat& lastFPS, UGfloat& avgFPS,
		                       UGfloat& bestFPS, UGfloat& worstFPS) const;
	
	virtual const FrameStats& GetStatistics(void) const;
	
	virtual UGfloat GetLastFPS() const;
	
	virtual UGfloat GetAverageFPS() const;

	virtual UGfloat GetBestFPS() const;
	
	virtual UGfloat GetWorstFPS() const;
	
	virtual UGulong GetBestFrameTime() const;
	
	virtual UGulong GetWorstFrameTime() const;
		
	virtual void ResetStatistics(void);
	
	virtual void GetCustomAttribute(const UGString& name, void* pData);
	
	virtual void SetDebugText(const UGString& text);

	const UGString& GetDebugText() const;
	
	virtual void SetPriority(UGuchar priority) { m_nPriority = priority; }
	
	virtual UGuchar GetPriority() const { return m_nPriority; }
	
	virtual UGbool IsActive() const;

	virtual void SetActive(UGbool state);

	virtual void SetAutoUpdated(UGbool autoupdate);

	virtual UGbool IsAutoUpdated(void) const;

//	virtual void writeContentsToFile(const UGString& filename) = 0;

	virtual UGString WriteContentsToTimestampedFile(const UGString& filenamePrefix, const UGString& filenameSuffix);
	
//	virtual UGbool requiresTextureFlipping() const = 0;

	virtual UGint GetTriangleCount(void) const;
	
	virtual void NotifyCameraRemoved(const UGMomentumCamera* cam);
	
	virtual UGbool IsPrimary(void) const;
	
	class Impl
	{
	protected:
		~Impl() {};
	};

	virtual Impl* GetImpl();

protected:
	void UpdateStats(void);
	void DestroyAllViewports();


protected:

	// 目标名称
	UGString m_strName;
	
	// 目标优先级
	UGuchar m_nPriority;
	
	UGuint m_nWidth;
	UGuint m_nHeight;
	UGuint m_nColourDepth;
	UGbool m_bIsDepthBuffered;
	
	FrameStats m_Stats;

	UGTime* m_Timer;
	UGString m_strDebugText;
	UGlong m_nLastSecond;
	UGlong m_nLastTime;

	UGuint m_nFrameCount;

	UGbool m_bActive;
	UGbool m_bAutoUpdate;
	typedef UGDict<UGint, UGViewport *> UGViewportMap;
	UGViewportMap m_ViewportMap;

	
};

}


#endif // !defined(AFX_UGRENDERTARGET_H__3E5C0D45_C40D_4902_AFCB_E918ED708515__INCLUDED_)
