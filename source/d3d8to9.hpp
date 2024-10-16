/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#pragma once

#include <vector>
#include <unordered_set>
#include "d3d8.hpp"
#include "interface_query.hpp"

class Direct3D8 : public IDirect3D8
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

	virtual HRESULT STDMETHODCALLTYPE RegisterSoftwareDevice(void *pInitializeFunction) override;
	virtual UINT STDMETHODCALLTYPE GetAdapterCount() override;
	virtual HRESULT STDMETHODCALLTYPE GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER8 *pIdentifier) override;
	virtual UINT STDMETHODCALLTYPE GetAdapterModeCount(UINT Adapter) override;
	virtual HRESULT STDMETHODCALLTYPE EnumAdapterModes(UINT Adapter, UINT Mode, D3DDISPLAYMODE *pMode) override;
	virtual HRESULT STDMETHODCALLTYPE GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE *pMode) override;
	virtual HRESULT STDMETHODCALLTYPE CheckDeviceType(UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed) override;
	virtual HRESULT STDMETHODCALLTYPE CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) override;
	virtual HRESULT STDMETHODCALLTYPE CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType) override;
	virtual HRESULT STDMETHODCALLTYPE CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) override;
	virtual HRESULT STDMETHODCALLTYPE GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS8 *pCaps) override;
	virtual HMONITOR STDMETHODCALLTYPE GetAdapterMonitor(UINT Adapter) override;
	virtual HRESULT STDMETHODCALLTYPE CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS8 *pPresentationParameters, IDirect3DDevice8 **ppReturnedDeviceInterface) override;

private:
	IDirect3D9 *const ProxyInterface;
	static const UINT MaxAdapters = 8;
	UINT CurrentAdapterCount = 0;
	UINT CurrentAdapterModeCount[MaxAdapters] = { 0 };
	std::vector<D3DDISPLAYMODE> CurrentAdapterModes[MaxAdapters];
};

class Direct3DDevice8 : public IDirect3DDevice8
{
	Direct3DDevice8(const Direct3DDevice8 &) = delete;
	Direct3DDevice8 &operator=(const Direct3DDevice8 &) = delete;

public:
	Direct3DDevice8(Direct3D8 *d3d, IDirect3DDevice9 *ProxyInterface, DWORD BehaviorFlags, BOOL EnableZBufferDiscarding = FALSE);
	~Direct3DDevice8();

	IDirect3DDevice9 *GetProxyInterface() const { return ProxyInterface; }

	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void **ppvObj) override;
	virtual ULONG STDMETHODCALLTYPE AddRef() override;
	virtual ULONG STDMETHODCALLTYPE Release() override;

	virtual HRESULT STDMETHODCALLTYPE TestCooperativeLevel() override;
	virtual UINT STDMETHODCALLTYPE GetAvailableTextureMem() override;
	virtual HRESULT STDMETHODCALLTYPE ResourceManagerDiscardBytes(DWORD Bytes) override;
	virtual HRESULT STDMETHODCALLTYPE GetDirect3D(IDirect3D8 **ppD3D8) override;
	virtual HRESULT STDMETHODCALLTYPE GetDeviceCaps(D3DCAPS8 *pCaps) override;
	virtual HRESULT STDMETHODCALLTYPE GetDisplayMode(D3DDISPLAYMODE *pMode) override;
	virtual HRESULT STDMETHODCALLTYPE GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters) override;
	virtual HRESULT STDMETHODCALLTYPE SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface8 *pCursorBitmap) override;
	virtual void STDMETHODCALLTYPE SetCursorPosition(UINT XScreenSpace, UINT YScreenSpace, DWORD Flags) override;
	virtual BOOL STDMETHODCALLTYPE ShowCursor(BOOL bShow) override;
	virtual HRESULT STDMETHODCALLTYPE CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS8 *pPresentationParameters, IDirect3DSwapChain8 **ppSwapChain) override;
	virtual HRESULT STDMETHODCALLTYPE Reset(D3DPRESENT_PARAMETERS8 *pPresentationParameters) override;
	virtual HRESULT STDMETHODCALLTYPE Present(const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion) override;
	virtual HRESULT STDMETHODCALLTYPE GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface8 **ppBackBuffer) override;
	virtual HRESULT STDMETHODCALLTYPE GetRasterStatus(D3DRASTER_STATUS *pRasterStatus) override;
	virtual void STDMETHODCALLTYPE SetGammaRamp(DWORD Flags, const D3DGAMMARAMP *pRamp) override;
	virtual void STDMETHODCALLTYPE GetGammaRamp(D3DGAMMARAMP *pRamp) override;
	virtual HRESULT STDMETHODCALLTYPE CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture8 **ppTexture) override;
	virtual HRESULT STDMETHODCALLTYPE CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture8 **ppVolumeTexture) override;
	virtual HRESULT STDMETHODCALLTYPE CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture8 **ppCubeTexture) override;
	virtual HRESULT STDMETHODCALLTYPE CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer8 **ppVertexBuffer) override;
	virtual HRESULT STDMETHODCALLTYPE CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer8 **ppIndexBuffer) override;
	virtual HRESULT STDMETHODCALLTYPE CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, BOOL Lockable, IDirect3DSurface8 **ppSurface) override;
	virtual HRESULT STDMETHODCALLTYPE CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, IDirect3DSurface8 **ppSurface) override;
	virtual HRESULT STDMETHODCALLTYPE CreateImageSurface(UINT Width, UINT Height, D3DFORMAT Format, IDirect3DSurface8 **ppSurface) override;
	virtual HRESULT STDMETHODCALLTYPE CopyRects(IDirect3DSurface8 *pSourceSurface, const RECT *pSourceRectsArray, UINT cRects, IDirect3DSurface8 *pDestinationSurface, const POINT *pDestPointsArray) override;
	virtual HRESULT STDMETHODCALLTYPE UpdateTexture(IDirect3DBaseTexture8 *pSourceTexture, IDirect3DBaseTexture8 *pDestinationTexture) override;
	virtual HRESULT STDMETHODCALLTYPE GetFrontBuffer(IDirect3DSurface8 *pDestSurface) override;
	virtual HRESULT STDMETHODCALLTYPE SetRenderTarget(IDirect3DSurface8 *pRenderTarget, IDirect3DSurface8 *pNewZStencil) override;
	virtual HRESULT STDMETHODCALLTYPE GetRenderTarget(IDirect3DSurface8 **ppRenderTarget) override;
	virtual HRESULT STDMETHODCALLTYPE GetDepthStencilSurface(IDirect3DSurface8 **ppZStencilSurface) override;
	virtual HRESULT STDMETHODCALLTYPE BeginScene() override;
	virtual HRESULT STDMETHODCALLTYPE EndScene() override;
	virtual HRESULT STDMETHODCALLTYPE Clear(DWORD Count, const D3DRECT *pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil) override;
	virtual HRESULT STDMETHODCALLTYPE SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix) override;
	virtual HRESULT STDMETHODCALLTYPE GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix) override;
	virtual HRESULT STDMETHODCALLTYPE MultiplyTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix) override;
	virtual HRESULT STDMETHODCALLTYPE SetViewport(const D3DVIEWPORT8 *pViewport) override;
	virtual HRESULT STDMETHODCALLTYPE GetViewport(D3DVIEWPORT8 *pViewport) override;
	virtual HRESULT STDMETHODCALLTYPE SetMaterial(const D3DMATERIAL8 *pMaterial) override;
	virtual HRESULT STDMETHODCALLTYPE GetMaterial(D3DMATERIAL8 *pMaterial) override;
	virtual HRESULT STDMETHODCALLTYPE SetLight(DWORD Index, const D3DLIGHT8 *pLight) override;
	virtual HRESULT STDMETHODCALLTYPE GetLight(DWORD Index, D3DLIGHT8 *pLight) override;
	virtual HRESULT STDMETHODCALLTYPE LightEnable(DWORD Index, BOOL Enable) override;
	virtual HRESULT STDMETHODCALLTYPE GetLightEnable(DWORD Index, BOOL *pEnable) override;
	virtual HRESULT STDMETHODCALLTYPE SetClipPlane(DWORD Index, const float *pPlane) override;
	virtual HRESULT STDMETHODCALLTYPE GetClipPlane(DWORD Index, float *pPlane) override;
	virtual HRESULT STDMETHODCALLTYPE SetRenderState(D3DRENDERSTATETYPE State, DWORD Value) override;
	virtual HRESULT STDMETHODCALLTYPE GetRenderState(D3DRENDERSTATETYPE State, DWORD *pValue) override;
	virtual HRESULT STDMETHODCALLTYPE BeginStateBlock() override;
	virtual HRESULT STDMETHODCALLTYPE EndStateBlock(DWORD *pToken) override;
	virtual HRESULT STDMETHODCALLTYPE ApplyStateBlock(DWORD Token) override;
	virtual HRESULT STDMETHODCALLTYPE CaptureStateBlock(DWORD Token) override;
	virtual HRESULT STDMETHODCALLTYPE DeleteStateBlock(DWORD Token) override;
	virtual HRESULT STDMETHODCALLTYPE CreateStateBlock(D3DSTATEBLOCKTYPE Type, DWORD *pToken) override;
	virtual HRESULT STDMETHODCALLTYPE SetClipStatus(const D3DCLIPSTATUS8 *pClipStatus) override;
	virtual HRESULT STDMETHODCALLTYPE GetClipStatus(D3DCLIPSTATUS8 *pClipStatus) override;
	virtual HRESULT STDMETHODCALLTYPE GetTexture(DWORD Stage, IDirect3DBaseTexture8 **ppTexture) override;
	virtual HRESULT STDMETHODCALLTYPE SetTexture(DWORD Stage, IDirect3DBaseTexture8 *pTexture) override;
	virtual HRESULT STDMETHODCALLTYPE GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue) override;
	virtual HRESULT STDMETHODCALLTYPE SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value) override;
	virtual HRESULT STDMETHODCALLTYPE ValidateDevice(DWORD *pNumPasses) override;
	virtual HRESULT STDMETHODCALLTYPE GetInfo(DWORD DevInfoID, void *pDevInfoStruct, DWORD DevInfoStructSize) override;
	virtual HRESULT STDMETHODCALLTYPE SetPaletteEntries(UINT PaletteNumber, const PALETTEENTRY *pEntries) override;
	virtual HRESULT STDMETHODCALLTYPE GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY *pEntries) override;
	virtual HRESULT STDMETHODCALLTYPE SetCurrentTexturePalette(UINT PaletteNumber) override;
	virtual HRESULT STDMETHODCALLTYPE GetCurrentTexturePalette(UINT *PaletteNumber) override;
	virtual HRESULT STDMETHODCALLTYPE DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount) override;
	virtual HRESULT STDMETHODCALLTYPE DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount) override;
	virtual HRESULT STDMETHODCALLTYPE DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void *pVertexStreamZeroData, UINT VertexStreamZeroStride) override;
	virtual HRESULT STDMETHODCALLTYPE DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices, UINT PrimitiveCount, const void *pIndexData, D3DFORMAT IndexDataFormat, const void *pVertexStreamZeroData, UINT VertexStreamZeroStride) override;
	virtual HRESULT STDMETHODCALLTYPE ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer8 *pDestBuffer, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE CreateVertexShader(const DWORD *pDeclaration, const DWORD *pFunction, DWORD *pHandle, DWORD Usage) override;
	virtual HRESULT STDMETHODCALLTYPE SetVertexShader(DWORD Handle) override;
	virtual HRESULT STDMETHODCALLTYPE GetVertexShader(DWORD *pHandle) override;
	virtual HRESULT STDMETHODCALLTYPE DeleteVertexShader(DWORD Handle) override;
	virtual HRESULT STDMETHODCALLTYPE SetVertexShaderConstant(DWORD Register, const void *pConstantData, DWORD ConstantCount) override;
	virtual HRESULT STDMETHODCALLTYPE GetVertexShaderConstant(DWORD Register, void *pConstantData, DWORD ConstantCount) override;
	virtual HRESULT STDMETHODCALLTYPE GetVertexShaderDeclaration(DWORD Handle, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE GetVertexShaderFunction(DWORD Handle, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer8 *pStreamData, UINT Stride) override;
	virtual HRESULT STDMETHODCALLTYPE GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer8 **ppStreamData, UINT *pStride) override;
	virtual HRESULT STDMETHODCALLTYPE SetIndices(IDirect3DIndexBuffer8 *pIndexData, UINT BaseVertexIndex) override;
	virtual HRESULT STDMETHODCALLTYPE GetIndices(IDirect3DIndexBuffer8 **ppIndexData, UINT *pBaseVertexIndex) override;
	virtual HRESULT STDMETHODCALLTYPE CreatePixelShader(const DWORD *pFunction, DWORD *pHandle) override;
	virtual HRESULT STDMETHODCALLTYPE SetPixelShader(DWORD Handle) override;
	virtual HRESULT STDMETHODCALLTYPE GetPixelShader(DWORD *pHandle) override;
	virtual HRESULT STDMETHODCALLTYPE DeletePixelShader(DWORD Handle) override;
	virtual HRESULT STDMETHODCALLTYPE SetPixelShaderConstant(DWORD Register, const void *pConstantData, DWORD ConstantCount) override;
	virtual HRESULT STDMETHODCALLTYPE GetPixelShaderConstant(DWORD Register, void *pConstantData, DWORD ConstantCount) override;
	virtual HRESULT STDMETHODCALLTYPE GetPixelShaderFunction(DWORD Handle, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE DrawRectPatch(UINT Handle, const float *pNumSegs, const D3DRECTPATCH_INFO *pRectPatchInfo) override;
	virtual HRESULT STDMETHODCALLTYPE DrawTriPatch(UINT Handle, const float *pNumSegs, const D3DTRIPATCH_INFO *pTriPatchInfo) override;
	virtual HRESULT STDMETHODCALLTYPE DeletePatch(UINT Handle) override;

	AddressLookupTable *ProxyAddressLookupTable;

private:
	void ApplyClipPlanes();
	void ReleaseShadersAndStateBlocks();

	Direct3D8 *const D3D;
	IDirect3DDevice9 *const ProxyInterface;
	INT CurrentBaseVertexIndex = 0;
	const BOOL ZBufferDiscarding = FALSE;
	DWORD CurrentVertexShaderHandle = 0, CurrentPixelShaderHandle = 0;
	IDirect3DSurface9 *pCurrentRenderTarget = nullptr;
	bool PaletteFlag = false;
	bool IsRecordingState = false;
	bool IsMixedVPModeDevice = false;

	static constexpr size_t MAX_CLIP_PLANES = 6;
	float StoredClipPlanes[MAX_CLIP_PLANES][4] = {};
	DWORD ClipPlaneRenderState = 0;

	// Store Shader Handles and State Block Tokens so they can be destroyed later to mirror D3D8 behavior
	std::unordered_set<DWORD> PixelShaderHandles, VertexShaderHandles, StateBlockTokens;
	unsigned int VertexShaderAndDeclarationCount = 0;
};

class Direct3DSwapChain8 : public IDirect3DSwapChain8, public AddressLookupTableObject
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

	virtual HRESULT STDMETHODCALLTYPE Present(const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion) override;
	virtual HRESULT STDMETHODCALLTYPE GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface8 **ppBackBuffer) override;

private:
	Direct3DDevice8 *const Device;
	IDirect3DSwapChain9 *const ProxyInterface;
};

class Direct3DTexture8 : public IDirect3DTexture8, public AddressLookupTableObject
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

	virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override;
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

	virtual HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DSURFACE_DESC8 *pDesc) override;
	virtual HRESULT STDMETHODCALLTYPE GetSurfaceLevel(UINT Level, IDirect3DSurface8 **ppSurfaceLevel) override;
	virtual HRESULT STDMETHODCALLTYPE LockRect(UINT Level, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE UnlockRect(UINT Level) override;
	virtual HRESULT STDMETHODCALLTYPE AddDirtyRect(const RECT *pDirtyRect) override;

private:
	Direct3DDevice8 *const Device;
	IDirect3DTexture9 *const ProxyInterface;
};
class Direct3DCubeTexture8 : public IDirect3DCubeTexture8, public AddressLookupTableObject
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

	virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override;
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

	virtual HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DSURFACE_DESC8 *pDesc) override;
	virtual HRESULT STDMETHODCALLTYPE GetCubeMapSurface(D3DCUBEMAP_FACES FaceType, UINT Level, IDirect3DSurface8 **ppCubeMapSurface) override;
	virtual HRESULT STDMETHODCALLTYPE LockRect(D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE UnlockRect(D3DCUBEMAP_FACES FaceType, UINT Level) override;
	virtual HRESULT STDMETHODCALLTYPE AddDirtyRect(D3DCUBEMAP_FACES FaceType, const RECT *pDirtyRect) override;

private:
	Direct3DDevice8 *const Device;
	IDirect3DCubeTexture9 *const ProxyInterface;
};
class Direct3DVolumeTexture8 : public IDirect3DVolumeTexture8, public AddressLookupTableObject
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

	virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override;
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

	virtual HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DVOLUME_DESC8 *pDesc) override;
	virtual HRESULT STDMETHODCALLTYPE GetVolumeLevel(UINT Level, IDirect3DVolume8 **ppVolumeLevel) override;
	virtual HRESULT STDMETHODCALLTYPE LockBox(UINT Level, D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE UnlockBox(UINT Level) override;
	virtual HRESULT STDMETHODCALLTYPE AddDirtyBox(const D3DBOX *pDirtyBox) override;

private:
	Direct3DDevice8 *const Device;
	IDirect3DVolumeTexture9 *const ProxyInterface;
};

class Direct3DSurface8 : public IDirect3DSurface8, public AddressLookupTableObject
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

	virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override;
	virtual HRESULT STDMETHODCALLTYPE GetContainer(REFIID riid, void **ppContainer) override;
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DSURFACE_DESC8 *pDesc) override;
	virtual HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE UnlockRect() override;

private:
	Direct3DDevice8 *const Device;
	IDirect3DSurface9 *const ProxyInterface;
};

class Direct3DVolume8 : public IDirect3DVolume8, public AddressLookupTableObject
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

	virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override;
	virtual HRESULT STDMETHODCALLTYPE GetContainer(REFIID riid, void **ppContainer) override;
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DVOLUME_DESC8 *pDesc) override;
	virtual HRESULT STDMETHODCALLTYPE LockBox(D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE UnlockBox() override;

private:
	Direct3DDevice8 *const Device;
	IDirect3DVolume9 *const ProxyInterface;
};

class Direct3DVertexBuffer8 : public IDirect3DVertexBuffer8, public AddressLookupTableObject
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

	virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override;
	virtual DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override;
	virtual DWORD STDMETHODCALLTYPE GetPriority() override;
	virtual void STDMETHODCALLTYPE PreLoad() override;
	virtual D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override;

	virtual HRESULT STDMETHODCALLTYPE Lock(UINT OffsetToLock, UINT SizeToLock, BYTE **ppbData, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE Unlock() override;
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DVERTEXBUFFER_DESC *pDesc) override;

private:
	Direct3DDevice8 *const Device;
	IDirect3DVertexBuffer9 *const ProxyInterface;
};

class Direct3DIndexBuffer8 : public IDirect3DIndexBuffer8, public AddressLookupTableObject
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

	virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) override;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) override;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) override;
	virtual DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) override;
	virtual DWORD STDMETHODCALLTYPE GetPriority() override;
	virtual void STDMETHODCALLTYPE PreLoad() override;
	virtual D3DRESOURCETYPE STDMETHODCALLTYPE GetType() override;

	virtual HRESULT STDMETHODCALLTYPE Lock(UINT OffsetToLock, UINT SizeToLock, BYTE **ppbData, DWORD Flags) override;
	virtual HRESULT STDMETHODCALLTYPE Unlock() override;
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DINDEXBUFFER_DESC *pDesc) override;

private:
	Direct3DDevice8 *const Device;
	IDirect3DIndexBuffer9 *const ProxyInterface;
};

#include <fstream>

#ifndef D3D8TO9NOLOG
extern std::ofstream LOG;
#endif
