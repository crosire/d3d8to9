/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#pragma once

#include <vector>
#include "d3d8types.hpp"

class DECLSPEC_UUID("1DD9E8DA-1C77-4D40-B0CF-98FEFDFF9512") Direct3D8;
class DECLSPEC_UUID("7385E5DF-8FE8-41D5-86B6-D7B48547B6CF") Direct3DDevice8;
class DECLSPEC_UUID("928C088B-76B9-4C6B-A536-A590853876CD") Direct3DSwapChain8;
class DECLSPEC_UUID("1B36BB7B-09B7-410A-B445-7D1430D7B33F") Direct3DResource8;
class DECLSPEC_UUID("B4211CFA-51B9-4A9F-AB78-DB99B2BB678E") Direct3DBaseTexture8;
class DECLSPEC_UUID("E4CDD575-2866-4F01-B12E-7EECE1EC9358") Direct3DTexture8;
class DECLSPEC_UUID("3EE5B968-2ACA-4C34-8BB5-7E0C3D19B750") Direct3DCubeTexture8;
class DECLSPEC_UUID("4B8AAAFA-140F-42BA-9131-597EAFAA2EAD") Direct3DVolumeTexture8;
class DECLSPEC_UUID("B96EEBCA-B326-4EA5-882F-2FF5BAE021DD") Direct3DSurface8;
class DECLSPEC_UUID("BD7349F5-14F1-42E4-9C79-972380DB40C0") Direct3DVolume8;
class DECLSPEC_UUID("8AEEEAC7-05F9-44D4-B591-000B0DF1CB95") Direct3DVertexBuffer8;
class DECLSPEC_UUID("0E689C9A-053D-44A0-9D92-DB0E3D750F86") Direct3DIndexBuffer8;

// MinGW support
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(Direct3D8, 0x1DD9E8DA, 0x1C77, 0x4D40, 0xB0, 0xCF, 0x98,0xFE,0xFD,0xFF,0x95,0x12)
__CRT_UUID_DECL(Direct3DDevice8, 0x7385E5DF, 0x8FE8, 0x41D5, 0x86, 0xB6, 0xD7,0xB4,0x85,0x47,0xB6,0xCF)
__CRT_UUID_DECL(Direct3DSwapChain8, 0x928C088B, 0x76B9, 0x4C6B, 0xA5, 0x36, 0xA5,0x90,0x85,0x38,0x76,0xCD)
__CRT_UUID_DECL(Direct3DResource8, 0x1B36BB7B, 0x09B7, 0x410A, 0xB4, 0x45, 0x7D,0x14,0x30,0xD7,0xB3,0x3F)
__CRT_UUID_DECL(Direct3DBaseTexture8, 0xB4211CFA, 0x51B9, 0x4A9F, 0xAB, 0x78, 0xDB,0x99,0xB2,0xBB,0x67,0x8E)
__CRT_UUID_DECL(Direct3DTexture8, 0xE4CDD575, 0x2866, 0x4F01, 0xB1, 0x2E, 0x7E,0xEC,0xE1,0xEC,0x93,0x58)
__CRT_UUID_DECL(Direct3DCubeTexture8, 0x3EE5B968, 0x2ACA, 0x4C34, 0x8B, 0xB5, 0x7E,0x0C,0x3D,0x19,0xB7,0x50)
__CRT_UUID_DECL(Direct3DVolumeTexture8, 0x4B8AAAFA, 0x140F, 0x42BA, 0x91, 0x31, 0x59,0x7E,0xAF,0xAA,0x2E,0xAD)
__CRT_UUID_DECL(Direct3DSurface8, 0xB96EEBCA, 0xB326, 0x4EA5, 0x88, 0x2F, 0x2F,0xF5,0xBA,0xE0,0x21,0xDD)
__CRT_UUID_DECL(Direct3DVolume8, 0xBD7349F5, 0x14F1, 0x42E4, 0x9C, 0x79, 0x97,0x23,0x80,0xDB,0x40,0xC0)
__CRT_UUID_DECL(Direct3DVertexBuffer8, 0x8AEEEAC7, 0x05F9, 0x44D4, 0xB5, 0x91, 0x00,0x0B,0x0D,0xF1,0xCB,0x95)
__CRT_UUID_DECL(Direct3DIndexBuffer8, 0x0E689C9A, 0x053D, 0x44A0, 0x9D, 0x92, 0xDB,0x0E,0x3D,0x75,0x0F,0x86)
#endif

#include "interface_query.hpp"

class Direct3D8 : public IUnknown
{
	Direct3D8(const Direct3D8 &) = delete;
	Direct3D8 &operator=(const Direct3D8 &) = delete;

public:
	Direct3D8(IDirect3D9 *ProxyInterface);
	~Direct3D8();

	IDirect3D9 *GetProxyInterface() const { return ProxyInterface; }

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	virtual ULONG STDMETHODCALLTYPE AddRef() override;
	virtual ULONG STDMETHODCALLTYPE Release() override;

	virtual HRESULT STDMETHODCALLTYPE RegisterSoftwareDevice(void *pInitializeFunction);
	virtual UINT STDMETHODCALLTYPE GetAdapterCount();
	virtual HRESULT STDMETHODCALLTYPE GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER8 *pIdentifier);
	virtual UINT STDMETHODCALLTYPE GetAdapterModeCount(UINT Adapter);
	virtual HRESULT STDMETHODCALLTYPE EnumAdapterModes(UINT Adapter, UINT Mode, D3DDISPLAYMODE *pMode);
	virtual HRESULT STDMETHODCALLTYPE GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE *pMode);
	virtual HRESULT STDMETHODCALLTYPE CheckDeviceType(UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed);
	virtual HRESULT STDMETHODCALLTYPE CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat);
	virtual HRESULT STDMETHODCALLTYPE CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType);
	virtual HRESULT STDMETHODCALLTYPE CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat);
	virtual HRESULT STDMETHODCALLTYPE GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS8 *pCaps);
	virtual HMONITOR STDMETHODCALLTYPE GetAdapterMonitor(UINT Adapter);
	virtual HRESULT STDMETHODCALLTYPE CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS8 *pPresentationParameters, Direct3DDevice8 **ppReturnedDeviceInterface);

private:
	IDirect3D9 *const ProxyInterface;
	static const UINT MaxAdapters = 8;
	UINT CurrentAdapterCount = 0;
	UINT CurrentAdapterModeCount[MaxAdapters] = { 0 };
	std::vector<D3DDISPLAYMODE> CurrentAdapterModes[MaxAdapters];
};

class Direct3DDevice8 : public IUnknown
{
	Direct3DDevice8(const Direct3DDevice8 &) = delete;
	Direct3DDevice8 &operator=(const Direct3DDevice8 &) = delete;

public:
	Direct3DDevice8(Direct3D8 *d3d, IDirect3DDevice9 *ProxyInterface, BOOL EnableZBufferDiscarding = FALSE);
	~Direct3DDevice8();

	IDirect3DDevice9 *GetProxyInterface() const { return ProxyInterface; }

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	virtual ULONG STDMETHODCALLTYPE AddRef() override;
	virtual ULONG STDMETHODCALLTYPE Release() override;

	virtual HRESULT STDMETHODCALLTYPE TestCooperativeLevel();
	virtual UINT STDMETHODCALLTYPE GetAvailableTextureMem();
	virtual HRESULT STDMETHODCALLTYPE ResourceManagerDiscardBytes(DWORD Bytes);
	virtual HRESULT STDMETHODCALLTYPE GetDirect3D(Direct3D8 **ppD3D8);
	virtual HRESULT STDMETHODCALLTYPE GetDeviceCaps(D3DCAPS8 *pCaps);
	virtual HRESULT STDMETHODCALLTYPE GetDisplayMode(D3DDISPLAYMODE *pMode);
	virtual HRESULT STDMETHODCALLTYPE GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters);
	virtual HRESULT STDMETHODCALLTYPE SetCursorProperties(UINT XHotSpot, UINT YHotSpot, Direct3DSurface8 *pCursorBitmap);
	virtual void STDMETHODCALLTYPE SetCursorPosition(UINT XScreenSpace, UINT YScreenSpace, DWORD Flags);
	virtual BOOL STDMETHODCALLTYPE ShowCursor(BOOL bShow);
	virtual HRESULT STDMETHODCALLTYPE CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS8 *pPresentationParameters, Direct3DSwapChain8 **ppSwapChain);
	virtual HRESULT STDMETHODCALLTYPE Reset(D3DPRESENT_PARAMETERS8 *pPresentationParameters);
	virtual HRESULT STDMETHODCALLTYPE Present(const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion);
	virtual HRESULT STDMETHODCALLTYPE GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, Direct3DSurface8 **ppBackBuffer);
	virtual HRESULT STDMETHODCALLTYPE GetRasterStatus(D3DRASTER_STATUS *pRasterStatus);
	virtual void STDMETHODCALLTYPE SetGammaRamp(DWORD Flags, const D3DGAMMARAMP *pRamp);
	virtual void STDMETHODCALLTYPE GetGammaRamp(D3DGAMMARAMP *pRamp);
	virtual HRESULT STDMETHODCALLTYPE CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, Direct3DTexture8 **ppTexture);
	virtual HRESULT STDMETHODCALLTYPE CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, Direct3DVolumeTexture8 **ppVolumeTexture);
	virtual HRESULT STDMETHODCALLTYPE CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, Direct3DCubeTexture8 **ppCubeTexture);
	virtual HRESULT STDMETHODCALLTYPE CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, Direct3DVertexBuffer8 **ppVertexBuffer);
	virtual HRESULT STDMETHODCALLTYPE CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, Direct3DIndexBuffer8 **ppIndexBuffer);
	virtual HRESULT STDMETHODCALLTYPE CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, BOOL Lockable, Direct3DSurface8 **ppSurface);
	virtual HRESULT STDMETHODCALLTYPE CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, Direct3DSurface8 **ppSurface);
	virtual HRESULT STDMETHODCALLTYPE CreateImageSurface(UINT Width, UINT Height, D3DFORMAT Format, Direct3DSurface8 **ppSurface);
	virtual HRESULT STDMETHODCALLTYPE CopyRects(Direct3DSurface8 *pSourceSurface, const RECT *pSourceRectsArray, UINT cRects, Direct3DSurface8 *pDestinationSurface, const POINT *pDestPointsArray);
	virtual HRESULT STDMETHODCALLTYPE UpdateTexture(Direct3DBaseTexture8 *pSourceTexture, Direct3DBaseTexture8 *pDestinationTexture);
	virtual HRESULT STDMETHODCALLTYPE GetFrontBuffer(Direct3DSurface8 *pDestSurface);
	virtual HRESULT STDMETHODCALLTYPE SetRenderTarget(Direct3DSurface8 *pRenderTarget, Direct3DSurface8 *pNewZStencil);
	virtual HRESULT STDMETHODCALLTYPE GetRenderTarget(Direct3DSurface8 **ppRenderTarget);
	virtual HRESULT STDMETHODCALLTYPE GetDepthStencilSurface(Direct3DSurface8 **ppZStencilSurface);
	virtual HRESULT STDMETHODCALLTYPE BeginScene();
	virtual HRESULT STDMETHODCALLTYPE EndScene();
	virtual HRESULT STDMETHODCALLTYPE Clear(DWORD Count, const D3DRECT *pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil);
	virtual HRESULT STDMETHODCALLTYPE SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix);
	virtual HRESULT STDMETHODCALLTYPE GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix);
	virtual HRESULT STDMETHODCALLTYPE MultiplyTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix);
	virtual HRESULT STDMETHODCALLTYPE SetViewport(const D3DVIEWPORT8 *pViewport);
	virtual HRESULT STDMETHODCALLTYPE GetViewport(D3DVIEWPORT8 *pViewport);
	virtual HRESULT STDMETHODCALLTYPE SetMaterial(const D3DMATERIAL8 *pMaterial);
	virtual HRESULT STDMETHODCALLTYPE GetMaterial(D3DMATERIAL8 *pMaterial);
	virtual HRESULT STDMETHODCALLTYPE SetLight(DWORD Index, const D3DLIGHT8 *pLight);
	virtual HRESULT STDMETHODCALLTYPE GetLight(DWORD Index, D3DLIGHT8 *pLight);
	virtual HRESULT STDMETHODCALLTYPE LightEnable(DWORD Index, BOOL Enable);
	virtual HRESULT STDMETHODCALLTYPE GetLightEnable(DWORD Index, BOOL *pEnable);
	virtual HRESULT STDMETHODCALLTYPE SetClipPlane(DWORD Index, const float *pPlane);
	virtual HRESULT STDMETHODCALLTYPE GetClipPlane(DWORD Index, float *pPlane);
	virtual HRESULT STDMETHODCALLTYPE SetRenderState(D3DRENDERSTATETYPE State, DWORD Value);
	virtual HRESULT STDMETHODCALLTYPE GetRenderState(D3DRENDERSTATETYPE State, DWORD *pValue);
	virtual HRESULT STDMETHODCALLTYPE BeginStateBlock();
	virtual HRESULT STDMETHODCALLTYPE EndStateBlock(DWORD *pToken);
	virtual HRESULT STDMETHODCALLTYPE ApplyStateBlock(DWORD Token);
	virtual HRESULT STDMETHODCALLTYPE CaptureStateBlock(DWORD Token);
	virtual HRESULT STDMETHODCALLTYPE DeleteStateBlock(DWORD Token);
	virtual HRESULT STDMETHODCALLTYPE CreateStateBlock(D3DSTATEBLOCKTYPE Type, DWORD *pToken);
	virtual HRESULT STDMETHODCALLTYPE SetClipStatus(const D3DCLIPSTATUS8 *pClipStatus);
	virtual HRESULT STDMETHODCALLTYPE GetClipStatus(D3DCLIPSTATUS8 *pClipStatus);
	virtual HRESULT STDMETHODCALLTYPE GetTexture(DWORD Stage, Direct3DBaseTexture8 **ppTexture);
	virtual HRESULT STDMETHODCALLTYPE SetTexture(DWORD Stage, Direct3DBaseTexture8 *pTexture);
	virtual HRESULT STDMETHODCALLTYPE GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue);
	virtual HRESULT STDMETHODCALLTYPE SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value);
	virtual HRESULT STDMETHODCALLTYPE ValidateDevice(DWORD *pNumPasses);
	virtual HRESULT STDMETHODCALLTYPE GetInfo(DWORD DevInfoID, void *pDevInfoStruct, DWORD DevInfoStructSize);
	virtual HRESULT STDMETHODCALLTYPE SetPaletteEntries(UINT PaletteNumber, const PALETTEENTRY *pEntries);
	virtual HRESULT STDMETHODCALLTYPE GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY *pEntries);
	virtual HRESULT STDMETHODCALLTYPE SetCurrentTexturePalette(UINT PaletteNumber);
	virtual HRESULT STDMETHODCALLTYPE GetCurrentTexturePalette(UINT *PaletteNumber);
	virtual HRESULT STDMETHODCALLTYPE DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount);
	virtual HRESULT STDMETHODCALLTYPE DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount);
	virtual HRESULT STDMETHODCALLTYPE DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void *pVertexStreamZeroData, UINT VertexStreamZeroStride);
	virtual HRESULT STDMETHODCALLTYPE DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices, UINT PrimitiveCount, const void *pIndexData, D3DFORMAT IndexDataFormat, const void *pVertexStreamZeroData, UINT VertexStreamZeroStride);
	virtual HRESULT STDMETHODCALLTYPE ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, Direct3DVertexBuffer8 *pDestBuffer, DWORD Flags);
	virtual HRESULT STDMETHODCALLTYPE CreateVertexShader(const DWORD *pDeclaration, const DWORD *pFunction, DWORD *pHandle, DWORD Usage);
	virtual HRESULT STDMETHODCALLTYPE SetVertexShader(DWORD Handle);
	virtual HRESULT STDMETHODCALLTYPE GetVertexShader(DWORD *pHandle);
	virtual HRESULT STDMETHODCALLTYPE DeleteVertexShader(DWORD Handle);
	virtual HRESULT STDMETHODCALLTYPE SetVertexShaderConstant(DWORD Register, const void *pConstantData, DWORD ConstantCount);
	virtual HRESULT STDMETHODCALLTYPE GetVertexShaderConstant(DWORD Register, void *pConstantData, DWORD ConstantCount);
	virtual HRESULT STDMETHODCALLTYPE GetVertexShaderDeclaration(DWORD Handle, void *pData, DWORD *pSizeOfData);
	virtual HRESULT STDMETHODCALLTYPE GetVertexShaderFunction(DWORD Handle, void *pData, DWORD *pSizeOfData);
	virtual HRESULT STDMETHODCALLTYPE SetStreamSource(UINT StreamNumber, Direct3DVertexBuffer8 *pStreamData, UINT Stride);
	virtual HRESULT STDMETHODCALLTYPE GetStreamSource(UINT StreamNumber, Direct3DVertexBuffer8 **ppStreamData, UINT *pStride);
	virtual HRESULT STDMETHODCALLTYPE SetIndices(Direct3DIndexBuffer8 *pIndexData, UINT BaseVertexIndex);
	virtual HRESULT STDMETHODCALLTYPE GetIndices(Direct3DIndexBuffer8 **ppIndexData, UINT *pBaseVertexIndex);
	virtual HRESULT STDMETHODCALLTYPE CreatePixelShader(const DWORD *pFunction, DWORD *pHandle);
	virtual HRESULT STDMETHODCALLTYPE SetPixelShader(DWORD Handle);
	virtual HRESULT STDMETHODCALLTYPE GetPixelShader(DWORD *pHandle);
	virtual HRESULT STDMETHODCALLTYPE DeletePixelShader(DWORD Handle);
	virtual HRESULT STDMETHODCALLTYPE SetPixelShaderConstant(DWORD Register, const void *pConstantData, DWORD ConstantCount);
	virtual HRESULT STDMETHODCALLTYPE GetPixelShaderConstant(DWORD Register, void *pConstantData, DWORD ConstantCount);
	virtual HRESULT STDMETHODCALLTYPE GetPixelShaderFunction(DWORD Handle, void *pData, DWORD *pSizeOfData);
	virtual HRESULT STDMETHODCALLTYPE DrawRectPatch(UINT Handle, const float *pNumSegs, const D3DRECTPATCH_INFO *pRectPatchInfo);
	virtual HRESULT STDMETHODCALLTYPE DrawTriPatch(UINT Handle, const float *pNumSegs, const D3DTRIPATCH_INFO *pTriPatchInfo);
	virtual HRESULT STDMETHODCALLTYPE DeletePatch(UINT Handle);

	AddressLookupTable *ProxyAddressLookupTable;

private:
	void ApplyClipPlanes();

	Direct3D8 *const D3D;
	IDirect3DDevice9 *const ProxyInterface;
	INT CurrentBaseVertexIndex = 0;
	const BOOL ZBufferDiscarding = FALSE;
	DWORD CurrentVertexShaderHandle = 0, CurrentPixelShaderHandle = 0;
	IDirect3DSurface9 *pCurrentRenderTarget = nullptr;
	bool PaletteFlag = false;

	static constexpr size_t MAX_CLIP_PLANES = 6;
	float StoredClipPlanes[MAX_CLIP_PLANES][4] = {};
	DWORD ClipPlaneRenderState = 0;
};

class Direct3DSwapChain8 : public IUnknown, public AddressLookupTableObject
{
	Direct3DSwapChain8(const Direct3DSwapChain8 &) = delete;
	Direct3DSwapChain8 &operator=(const Direct3DSwapChain8 &) = delete;

public:
	Direct3DSwapChain8(Direct3DDevice8 *device, IDirect3DSwapChain9 *ProxyInterface);
	~Direct3DSwapChain8();

	IDirect3DSwapChain9 *GetProxyInterface() const { return ProxyInterface; }

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	virtual ULONG STDMETHODCALLTYPE AddRef() override;
	virtual ULONG STDMETHODCALLTYPE Release() override;

	virtual HRESULT STDMETHODCALLTYPE Present(const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion);
	virtual HRESULT STDMETHODCALLTYPE GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, Direct3DSurface8 **ppBackBuffer);

private:
	Direct3DDevice8 *const Device;
	IDirect3DSwapChain9 *const ProxyInterface;
};

class Direct3DResource8 : public IUnknown
{
public:
	virtual HRESULT STDMETHODCALLTYPE GetDevice(Direct3DDevice8 **ppDevice) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) = 0;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) = 0;
	virtual DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) = 0;
	virtual DWORD STDMETHODCALLTYPE GetPriority() = 0;
	virtual void STDMETHODCALLTYPE PreLoad() = 0;
	virtual D3DRESOURCETYPE STDMETHODCALLTYPE GetType() = 0;
};

class Direct3DBaseTexture8 : public Direct3DResource8
{
public:
	virtual DWORD STDMETHODCALLTYPE SetLOD(DWORD LODNew) = 0;
	virtual DWORD STDMETHODCALLTYPE GetLOD() = 0;
	virtual DWORD STDMETHODCALLTYPE GetLevelCount() = 0;
};
class Direct3DTexture8 : public Direct3DBaseTexture8, public AddressLookupTableObject
{
	Direct3DTexture8(const Direct3DTexture8 &) = delete;
	Direct3DTexture8 &operator=(const Direct3DTexture8 &) = delete;

public:
	Direct3DTexture8(Direct3DDevice8 *device, IDirect3DTexture9 *ProxyInterface);
	~Direct3DTexture8();

	IDirect3DTexture9 *GetProxyInterface() const { return ProxyInterface; }

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	virtual ULONG STDMETHODCALLTYPE AddRef() override;
	virtual ULONG STDMETHODCALLTYPE Release() override;

	virtual HRESULT STDMETHODCALLTYPE GetDevice(Direct3DDevice8 **ppDevice) override;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override;
	virtual DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override;
	virtual DWORD STDMETHODCALLTYPE GetPriority() override;
	virtual void STDMETHODCALLTYPE PreLoad() override;
	virtual D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override;

	virtual DWORD STDMETHODCALLTYPE SetLOD(DWORD LODNew) override;
	virtual DWORD STDMETHODCALLTYPE GetLOD() override;
	virtual DWORD STDMETHODCALLTYPE GetLevelCount() override;

	virtual HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DSURFACE_DESC8 *pDesc);
	virtual HRESULT STDMETHODCALLTYPE GetSurfaceLevel(UINT Level, Direct3DSurface8 **ppSurfaceLevel);
	virtual HRESULT STDMETHODCALLTYPE LockRect(UINT Level, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags);
	virtual HRESULT STDMETHODCALLTYPE UnlockRect(UINT Level);
	virtual HRESULT STDMETHODCALLTYPE AddDirtyRect(const RECT *pDirtyRect);

private:
	Direct3DDevice8 *const Device;
	IDirect3DTexture9 *const ProxyInterface;
};
class Direct3DCubeTexture8 : public Direct3DBaseTexture8, public AddressLookupTableObject
{
	Direct3DCubeTexture8(const Direct3DCubeTexture8 &) = delete;
	Direct3DCubeTexture8 &operator=(const Direct3DCubeTexture8 &) = delete;

public:
	Direct3DCubeTexture8(Direct3DDevice8 *device, IDirect3DCubeTexture9 *ProxyInterface);
	~Direct3DCubeTexture8();

	IDirect3DCubeTexture9 *GetProxyInterface() const { return ProxyInterface; }

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	virtual ULONG STDMETHODCALLTYPE AddRef() override;
	virtual ULONG STDMETHODCALLTYPE Release() override;

	virtual HRESULT STDMETHODCALLTYPE GetDevice(Direct3DDevice8 **ppDevice) override;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override;
	virtual DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override;
	virtual DWORD STDMETHODCALLTYPE GetPriority() override;
	virtual void STDMETHODCALLTYPE PreLoad() override;
	virtual D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override;

	virtual DWORD STDMETHODCALLTYPE SetLOD(DWORD LODNew) override;
	virtual DWORD STDMETHODCALLTYPE GetLOD() override;
	virtual DWORD STDMETHODCALLTYPE GetLevelCount() override;

	virtual HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DSURFACE_DESC8 *pDesc);
	virtual HRESULT STDMETHODCALLTYPE GetCubeMapSurface(D3DCUBEMAP_FACES FaceType, UINT Level, Direct3DSurface8 **ppCubeMapSurface);
	virtual HRESULT STDMETHODCALLTYPE LockRect(D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags);
	virtual HRESULT STDMETHODCALLTYPE UnlockRect(D3DCUBEMAP_FACES FaceType, UINT Level);
	virtual HRESULT STDMETHODCALLTYPE AddDirtyRect(D3DCUBEMAP_FACES FaceType, const RECT *pDirtyRect);

private:
	Direct3DDevice8 *const Device;
	IDirect3DCubeTexture9 *const ProxyInterface;
};
class Direct3DVolumeTexture8 : public Direct3DBaseTexture8, public AddressLookupTableObject
{
	Direct3DVolumeTexture8(const Direct3DVolumeTexture8 &) = delete;
	Direct3DVolumeTexture8 &operator=(const Direct3DVolumeTexture8 &) = delete;

public:
	Direct3DVolumeTexture8(Direct3DDevice8 *device, IDirect3DVolumeTexture9 *ProxyInterface);
	~Direct3DVolumeTexture8();

	IDirect3DVolumeTexture9 *GetProxyInterface() const { return ProxyInterface; }

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	virtual ULONG STDMETHODCALLTYPE AddRef() override;
	virtual ULONG STDMETHODCALLTYPE Release() override;

	virtual HRESULT STDMETHODCALLTYPE GetDevice(Direct3DDevice8 **ppDevice) override;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override;
	virtual DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override;
	virtual DWORD STDMETHODCALLTYPE GetPriority() override;
	virtual void STDMETHODCALLTYPE PreLoad() override;
	virtual D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override;

	virtual DWORD STDMETHODCALLTYPE SetLOD(DWORD LODNew) override;
	virtual DWORD STDMETHODCALLTYPE GetLOD() override;
	virtual DWORD STDMETHODCALLTYPE GetLevelCount() override;

	virtual HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DVOLUME_DESC8 *pDesc);
	virtual HRESULT STDMETHODCALLTYPE GetVolumeLevel(UINT Level, Direct3DVolume8 **ppVolumeLevel);
	virtual HRESULT STDMETHODCALLTYPE LockBox(UINT Level, D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags);
	virtual HRESULT STDMETHODCALLTYPE UnlockBox(UINT Level);
	virtual HRESULT STDMETHODCALLTYPE AddDirtyBox(const D3DBOX *pDirtyBox);

private:
	Direct3DDevice8 *const Device;
	IDirect3DVolumeTexture9 *const ProxyInterface;
};

class Direct3DSurface8 : public IUnknown, public AddressLookupTableObject
{
	Direct3DSurface8(const Direct3DSurface8 &) = delete;
	Direct3DSurface8 &operator=(const Direct3DSurface8 &) = delete;

public:
	Direct3DSurface8(Direct3DDevice8 *device, IDirect3DSurface9 *ProxyInterface);
	~Direct3DSurface8();

	IDirect3DSurface9 *GetProxyInterface() const { return ProxyInterface; }

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	virtual ULONG STDMETHODCALLTYPE AddRef() override;
	virtual ULONG STDMETHODCALLTYPE Release() override;

	virtual HRESULT STDMETHODCALLTYPE GetDevice(Direct3DDevice8 **ppDevice);
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags);
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData);
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid);
	virtual HRESULT STDMETHODCALLTYPE GetContainer(REFIID riid, void **ppContainer);
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DSURFACE_DESC8 *pDesc);
	virtual HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags);
	virtual HRESULT STDMETHODCALLTYPE UnlockRect();

private:
	Direct3DDevice8 *const Device;
	IDirect3DSurface9 *const ProxyInterface;
};

class Direct3DVolume8 : public IUnknown, public AddressLookupTableObject
{
	Direct3DVolume8(const Direct3DVolume8 &) = delete;
	Direct3DVolume8 &operator=(const Direct3DVolume8 &) = delete;

public:
	Direct3DVolume8(Direct3DDevice8 *Device, IDirect3DVolume9 *ProxyInterface);
	~Direct3DVolume8();

	IDirect3DVolume9 *GetProxyInterface() const { return ProxyInterface; }

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	virtual ULONG STDMETHODCALLTYPE AddRef() override;
	virtual ULONG STDMETHODCALLTYPE Release() override;

	virtual HRESULT STDMETHODCALLTYPE GetDevice(Direct3DDevice8 **ppDevice);
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags);
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData);
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid);
	virtual HRESULT STDMETHODCALLTYPE GetContainer(REFIID riid, void **ppContainer);
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DVOLUME_DESC8 *pDesc);
	virtual HRESULT STDMETHODCALLTYPE LockBox(D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags);
	virtual HRESULT STDMETHODCALLTYPE UnlockBox();

private:
	Direct3DDevice8 *const Device;
	IDirect3DVolume9 *const ProxyInterface;
};

class Direct3DVertexBuffer8 : public Direct3DResource8, public AddressLookupTableObject
{
	Direct3DVertexBuffer8(const Direct3DVertexBuffer8 &) = delete;
	Direct3DVertexBuffer8 &operator=(const Direct3DVertexBuffer8 &) = delete;

public:
	Direct3DVertexBuffer8(Direct3DDevice8 *Device, IDirect3DVertexBuffer9 *ProxyInterface);
	~Direct3DVertexBuffer8();

	IDirect3DVertexBuffer9 *GetProxyInterface() const { return ProxyInterface; }

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	virtual ULONG STDMETHODCALLTYPE AddRef() override;
	virtual ULONG STDMETHODCALLTYPE Release() override;

	virtual HRESULT STDMETHODCALLTYPE GetDevice(Direct3DDevice8 **ppDevice) override;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override;
	virtual DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override;
	virtual DWORD STDMETHODCALLTYPE GetPriority() override;
	virtual void STDMETHODCALLTYPE PreLoad() override;
	virtual D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override;

	virtual HRESULT STDMETHODCALLTYPE Lock(UINT OffsetToLock, UINT SizeToLock, BYTE **ppbData, DWORD Flags);
	virtual HRESULT STDMETHODCALLTYPE Unlock();
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DVERTEXBUFFER_DESC *pDesc);

private:
	Direct3DDevice8 *const Device;
	IDirect3DVertexBuffer9 *const ProxyInterface;
};

class Direct3DIndexBuffer8 : public Direct3DResource8, public AddressLookupTableObject
{
	Direct3DIndexBuffer8(const Direct3DIndexBuffer8 &) = delete;
	Direct3DIndexBuffer8 &operator=(const Direct3DIndexBuffer8 &) = delete;

public:
	Direct3DIndexBuffer8(Direct3DDevice8 *Device, IDirect3DIndexBuffer9 *ProxyInterface);
	~Direct3DIndexBuffer8();

	IDirect3DIndexBuffer9 *GetProxyInterface() const { return ProxyInterface; }

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	virtual ULONG STDMETHODCALLTYPE AddRef() override;
	virtual ULONG STDMETHODCALLTYPE Release() override;

	virtual HRESULT STDMETHODCALLTYPE GetDevice(Direct3DDevice8 **ppDevice) override;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override;
	virtual DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override;
	virtual DWORD STDMETHODCALLTYPE GetPriority() override;
	virtual void STDMETHODCALLTYPE PreLoad() override;
	virtual D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override;

	virtual HRESULT STDMETHODCALLTYPE Lock(UINT OffsetToLock, UINT SizeToLock, BYTE **ppbData, DWORD Flags);
	virtual HRESULT STDMETHODCALLTYPE Unlock();
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DINDEXBUFFER_DESC *pDesc);

private:
	Direct3DDevice8 *const Device;
	IDirect3DIndexBuffer9 *const ProxyInterface;
};

#include <fstream>

#ifndef D3D8TO9NOLOG
extern std::ofstream LOG;
#endif
