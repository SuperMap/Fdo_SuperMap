// UGD3DEnum.h: interface for the UGD3DEnum class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_UGD3DENUM_H__5716DD76_3E3B_4ADA_9A89_F6C71C6B1128__INCLUDED_)
#define AFX_UGD3DENUM_H__5716DD76_3E3B_4ADA_9A89_F6C71C6B1128__INCLUDED_

#include "Base/UGArray.h"
#include "Base/UGList.h"
#include "Scene/UGRenderSys.h"
#include "d3d9.h"
#include "d3dx9math.h"


namespace UGC
{
//--------------------------------------------------------------------------------------
// Finding valid device settings
//--------------------------------------------------------------------------------------
enum DXUT_MATCH_TYPE
{
    DXUTMT_IGNORE_INPUT = 0,  // Use the closest valid value to a default 
    DXUTMT_PRESERVE_INPUT,    // Use input without change, but may cause no valid device to be found
    DXUTMT_CLOSEST_TO_INPUT   // Use the closest valid value to the input 
};
struct DXUTMatchOptions
{
    DXUT_MATCH_TYPE eAdapterOrdinal;
    DXUT_MATCH_TYPE eDeviceType;
    DXUT_MATCH_TYPE eWindowed;
    DXUT_MATCH_TYPE eAdapterFormat;
    DXUT_MATCH_TYPE eVertexProcessing;
    DXUT_MATCH_TYPE eResolution;
    DXUT_MATCH_TYPE eBackBufferFormat;
    DXUT_MATCH_TYPE eBackBufferCount;
    DXUT_MATCH_TYPE eMultiSample;
    DXUT_MATCH_TYPE eSwapEffect;
    DXUT_MATCH_TYPE eDepthFormat;
    DXUT_MATCH_TYPE eStencilFormat;
    DXUT_MATCH_TYPE ePresentFlags;
    DXUT_MATCH_TYPE eRefreshRate;
    DXUT_MATCH_TYPE ePresentInterval;
};

//--------------------------------------------------------------------------------------
class UGD3DEnumAdapterInfo;
class UGD3DEnumDeviceInfo;
struct UGD3DEnumDeviceSettings;
struct UD3DEnumDSMSConflict;

class UGD3DEnumDeviceInfo
{
public:
    ~UGD3DEnumDeviceInfo();

    UINT AdapterOrdinal;
    D3DDEVTYPE DeviceType;
    D3DCAPS9 Caps;
    
    UGArray<UGD3DEnumDeviceSettings*> deviceSettingsList; 
};
class UGD3DEnumAdapterInfo
{
public:
    ~UGD3DEnumAdapterInfo();

    UINT AdapterOrdinal;
    D3DADAPTER_IDENTIFIER9 AdapterIdentifier;
    WCHAR szUniqueDescription[256];

    UGArray<D3DDISPLAYMODE> displayModeList; // Array of supported D3DDISPLAYMODEs
    UGArray<UGD3DEnumDeviceInfo*> deviceInfoList; // Array of CD3DEnumDeviceInfo* with unique supported DeviceTypes
};
struct UGD3DEnumDSMSConflict
{
    D3DFORMAT DSFormat;
    D3DMULTISAMPLE_TYPE MSType;
};
struct UGD3DEnumDeviceSettings
{
    UINT AdapterOrdinal;
    D3DDEVTYPE DeviceType;
    D3DFORMAT AdapterFormat;
    D3DFORMAT BackBufferFormat;
    BOOL Windowed;

    UGArray<UGuint> depthStencilFormatList; // List of D3DFORMATs
    UGArray<D3DMULTISAMPLE_TYPE> multiSampleTypeList; // List of D3DMULTISAMPLE_TYPEs
    UGArray<DWORD> multiSampleQualityList; // List of number of quality levels for each multisample type
    UGArray<UINT> presentIntervalList; // List of D3DPRESENT flags
    UGArray<UGD3DEnumDSMSConflict> DSMSConflictList; // List of CD3DEnumDSMSConflict

    UGD3DEnumAdapterInfo* pAdapterInfo;
    UGD3DEnumDeviceInfo* pDeviceInfo;
};

class UGD3DEnum  
{
public:
	UGD3DEnum();
	virtual ~UGD3DEnum();

	HRESULT Enumerate(IDirect3D9* pD3D, HWND hwnd);	
	UGArray<UGD3DEnumAdapterInfo*> &GetAdapterInfoList();
	UINT ColorChannelBits( D3DFORMAT fmt );
	void GetAdapterDisplayMode(UINT Adapter,D3DDISPLAYMODE* pMode);
	void GetPossibleVertexProcessingList( UGbool* pbSoftwareVP, UGbool* pbHardwareVP, 
		UGbool* pbPureHarewareVP, UGbool* pbMixedVP );
	UINT DXUTDepthBits( D3DFORMAT fmt );
	UINT DXUTStencilBits( D3DFORMAT fmt );
	
public:
	IDirect3D9* m_pD3D;
	HWND m_hwnd;
private:		

	UINT m_nMinWidth;
    UINT m_nMinHeight;
    UINT m_nMaxWidth;
    UINT m_nMaxHeight;
    UINT m_nRefreshMin;
    UINT m_nRefreshMax;	
	UINT m_nMultisampleQualityMax;

	bool m_bSoftwareVP;
    bool m_bHardwareVP;
    bool m_bPureHarewareVP;
    bool m_bMixedVP;

	UGArray<UGD3DEnumAdapterInfo*> m_AdapterInfoList;  	
	bool m_bRequirePostPixelShaderBlending;
	UGArray<D3DFORMAT> m_DepthStecilPossibleList;
	UGArray<D3DMULTISAMPLE_TYPE> m_MultiSampleTypeList;
	UGArray<UINT> m_PresentIntervalList;

	void ClearAdapterInfoList();		
	HRESULT EnumerateDevices( UGD3DEnumAdapterInfo* pAdapterInfo, 
		UGArray<D3DFORMAT>* pAdapterFormatList );
	HRESULT EnumerateDeviceSettings( UGD3DEnumAdapterInfo* pAdapterInfo, 
		UGD3DEnumDeviceInfo* pDeviceInfo, 
		UGArray<D3DFORMAT>* pAdapterFormatList );
	void BuildDepthStencilFormatList( UGD3DEnumDeviceSettings* pDeviceSettings );
	void BuildMultiSampleTypeList( UGD3DEnumDeviceSettings* pDeviceSettings );
	void BuildDSMSConflictList( UGD3DEnumDeviceSettings* pDeviceSettings );
	void BuildPresentIntervalList( UGD3DEnumDeviceInfo* pDeviceInfo, 
                                                UGD3DEnumDeviceSettings* pDeviceSettings );

	void SetPossibleVertexProcessingList( bool bSoftwareVP, 
		bool bHardwareVP, bool bPureHarewareVP, bool bMixedVP );
	void ResetPossibleDepthStencilFormats();
    void ResetPossibleMultisampleTypeList();
    void ResetPossiblePresentIntervalList();
};
}
#endif // !defined(AFX_UGD3DENUM_H__5716DD76_3E3B_4ADA_9A89_F6C71C6B1128__INCLUDED_)
