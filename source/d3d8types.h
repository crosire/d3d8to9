#pragma once

#include <d3d9.h>

typedef D3DCLIPSTATUS9 D3DCLIPSTATUS8;
typedef D3DLIGHT9 D3DLIGHT8;
typedef D3DMATERIAL9 D3DMATERIAL8;
typedef D3DVIEWPORT9 D3DVIEWPORT8;

struct D3DADAPTER_IDENTIFIER8
{
	char Driver[MAX_DEVICE_IDENTIFIER_STRING];
	char Description[MAX_DEVICE_IDENTIFIER_STRING];
	LARGE_INTEGER DriverVersion;
	DWORD VendorId, DeviceId, SubSysId;
	DWORD Revision;
	GUID DeviceIdentifier;
	DWORD WHQLLevel;
};
struct D3DCAPS8
{
	D3DDEVTYPE DeviceType;
	UINT AdapterOrdinal;
	DWORD Caps, Caps2, Caps3;
	DWORD PresentationIntervals;
	DWORD CursorCaps;
	DWORD DevCaps;
	DWORD PrimitiveMiscCaps;
	DWORD RasterCaps;
	DWORD ZCmpCaps;
	DWORD SrcBlendCaps;
	DWORD DestBlendCaps;
	DWORD AlphaCmpCaps;
	DWORD ShadeCaps;
	DWORD TextureCaps;
	DWORD TextureFilterCaps;
	DWORD CubeTextureFilterCaps;
	DWORD VolumeTextureFilterCaps;
	DWORD TextureAddressCaps;
	DWORD VolumeTextureAddressCaps;
	DWORD LineCaps;
	DWORD MaxTextureWidth, MaxTextureHeight;
	DWORD MaxVolumeExtent;
	DWORD MaxTextureRepeat;
	DWORD MaxTextureAspectRatio;
	DWORD MaxAnisotropy;
	float MaxVertexW;
	float GuardBandLeft, GuardBandTop, GuardBandRight, GuardBandBottom;
	float ExtentsAdjust;
	DWORD StencilCaps;
	DWORD FVFCaps;
	DWORD TextureOpCaps;
	DWORD MaxTextureBlendStages;
	DWORD MaxSimultaneousTextures;
	DWORD VertexProcessingCaps;
	DWORD MaxActiveLights;
	DWORD MaxUserClipPlanes;
	DWORD MaxVertexBlendMatrices;
	DWORD MaxVertexBlendMatrixIndex;
	float MaxPointSize;
	DWORD MaxPrimitiveCount;
	DWORD MaxVertexIndex;
	DWORD MaxStreams;
	DWORD MaxStreamStride;
	DWORD VertexShaderVersion;
	DWORD MaxVertexShaderConst;
	DWORD PixelShaderVersion;
	float MaxPixelShaderValue;
};
struct D3DPRESENT_PARAMETERS8
{
	UINT BackBufferWidth, BackBufferHeight;
	D3DFORMAT BackBufferFormat;
	UINT BackBufferCount;
	D3DMULTISAMPLE_TYPE MultiSampleType;
	D3DSWAPEFFECT SwapEffect;
	HWND hDeviceWindow;
	BOOL Windowed;
	BOOL EnableAutoDepthStencil;
	D3DFORMAT AutoDepthStencilFormat;
	DWORD Flags;
	UINT FullScreen_RefreshRateInHz, FullScreen_PresentationInterval;
};
struct D3DSURFACE_DESC8
{
	D3DFORMAT Format;
	D3DRESOURCETYPE Type;
	DWORD Usage;
	D3DPOOL Pool;
	UINT Size;
	D3DMULTISAMPLE_TYPE MultiSampleType;
	UINT Width, Height;
};
struct D3DVOLUME_DESC8
{
	D3DFORMAT Format;
	D3DRESOURCETYPE Type;
	DWORD Usage;
	D3DPOOL Pool;
	UINT Size;
	UINT Width, Height, Depth;
};
