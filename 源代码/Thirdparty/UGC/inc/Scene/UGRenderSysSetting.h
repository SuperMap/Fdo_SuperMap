// UGRenderSysSetting.h: interface for the UGRenderSysSetting class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGRENDERSYSSETTING_H__1878181D_E55D_4DF5_AB67_35B3A4AF38E3__INCLUDED_)
#define AFX_UGRENDERSYSSETTING_H__1878181D_E55D_4DF5_AB67_35B3A4AF38E3__INCLUDED_

#include "Base/ugdefs.h"
#include "Base/UGString.h"
#include "Base/UGList.h"

namespace UGC 
{
typedef struct _UGD3DDISPLAYMODE
{
    UGuint            Width;
    UGuint            Height;
    UGuint            RefreshRate;
    UGuint       Format;
} UGD3DDISPLAYMODE;
typedef struct _UGD3DPRESENT_PARAMETERS_
{
    UGuint                BackBufferWidth;
    UGuint                BackBufferHeight;
    UGuint           BackBufferFormat;
    UGuint                BackBufferCount;

    UGuint			MultiSampleType;

	// 修改描述：修改unsigned long 为UGC数据类型UGint
    // 修改人:luofx
	// 修改日期:2007.8.16
	// unsigned long               MultiSampleQuality;
	UGint               MultiSampleQuality;

    UGuint       SwapEffect;
    void*                hDeviceWindow;
    UGint                Windowed;
    UGint                EnableAutoDepthStencil;
    UGuint           AutoDepthStencilFormat;

	// 修改描述：修改unsigned long 为UGC数据类型
    // 修改人:luofx
	// 修改日期:2007.8.16
    //unsigned long       Flags;
	UGint       Flags;

    /* FullScreen_RefreshRateInHz must be zero for Windowed mode */
    UGuint                FullScreen_RefreshRateInHz;
    UGuint                PresentationInterval;
} UGD3DPRESENT_PARAMETERS;

struct DXUTDeviceSettings
{
    UGuint AdapterOrdinal;
    UGuint DeviceType;
    UGuint AdapterFormat;
    UGuint BehaviorFlags;
    UGD3DPRESENT_PARAMETERS pp;
};

typedef UGArray<UGuint> DepthStencilArray;

class SCENE_API UGRenderSysSetting  
{
public:
	UGRenderSysSetting();
	virtual ~UGRenderSysSetting();
	
	//D3D的setting
public:
	virtual void D3DDeviceTypes(UGuint AdapterOrdinal, UGArray<UGuint> &arr){}
	virtual void D3DDeviceWindowed(UGuint AdapterOrdinal, UGuint DeviceType, UGbool arr[]){}
	virtual void D3DAdapterFormat(UGuint AdapterOrdinal, UGuint DeviceType, UGArray<UGuint> &arr){}
	virtual void D3DGetAdapterDisplayMode(UGuint AdapterOrdinal, UGD3DDISPLAYMODE &mode){}
	virtual void D3DGetDesktopResolution(UGuint AdapterOrdinal, UGuint *pWidth, UGuint *pHeight){}
	virtual void D3DGetDisplayModeList(UGuint AdapterOrdinal, UGArray<UGD3DDISPLAYMODE> &arr){}
	virtual void D3DGetValidBBFByWinAndAF(UGuint AdapterOrdinal, UGuint DeviceType,
		UGbool bWindowed,UGuint AdapterFormat, UGArray<UGuint> &arr){}
	virtual void D3DGetPossibleVertexProcessingList( UGbool* pbSoftwareVP, UGbool* pbHardwareVP, 
		UGbool* pbPureHarewareVP, UGbool* pbMixedVP ){}
	virtual void D3DGetValidDStencilByWinAndAFAndBBF(UGuint AdapterOrdinal, UGuint DeviceType,
		UGbool bWindowed,UGuint AdapterFormat, UGuint BackBufferFormat, UGArray<DepthStencilArray> &arr){}
	virtual void D3DGetValidmsTypeByDStencil(UGuint AdapterOrdinal, UGuint DeviceType,
		UGbool bWindowed,UGuint AdapterFormat, UGuint BackBufferFormat, UGuint DepthStencil,UGArray<UGuint> &arr){}
	virtual UGuint D3DGetMaxQualityBymsType(UGuint AdapterOrdinal, UGuint DeviceType,
		UGbool bWindowed,UGuint AdapterFormat, UGuint BackBufferFormat, UGuint msType){return 0;}
	virtual UGuint D3DGetDevCaps(UGuint AdapterOrdinal, UGuint DeviceType){return 0;}

	virtual UGString D3DDeviceTypeToString(UGuint devType){return "";}
	virtual UGString D3DFormatToString(UGuint format, UGbool bWithPrefix ) {return "";}
	virtual UGString D3DMultisampleTypeToString(UGuint MultiSampleType){return "";}
	virtual UGString D3DVertexProcessingTypeToString(UGuint vpt){return "";}

	UGArray<UGString> m_arrAdapterDescription;
	DXUTDeviceSettings m_d3dDeviceSetting;
};
}
#endif // !defined(AFX_UGRENDERSYSSETTING_H__1878181D_E55D_4DF5_AB67_35B3A4AF38E3__INCLUDED_)
