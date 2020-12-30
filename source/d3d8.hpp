/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#pragma once

#include "d3d8types.hpp"

#ifndef interface
#define interface struct
#endif

interface DECLSPEC_UUID("1DD9E8DA-1C77-4D40-B0CF-98FEFDFF9512") IDirect3D8;
interface DECLSPEC_UUID("7385E5DF-8FE8-41D5-86B6-D7B48547B6CF") IDirect3DDevice8;
interface DECLSPEC_UUID("928C088B-76B9-4C6B-A536-A590853876CD") IDirect3DSwapChain8;
interface DECLSPEC_UUID("1B36BB7B-09B7-410A-B445-7D1430D7B33F") IDirect3DResource8;
interface DECLSPEC_UUID("B4211CFA-51B9-4A9F-AB78-DB99B2BB678E") IDirect3DBaseTexture8;
interface DECLSPEC_UUID("E4CDD575-2866-4F01-B12E-7EECE1EC9358") IDirect3DTexture8;
interface DECLSPEC_UUID("3EE5B968-2ACA-4C34-8BB5-7E0C3D19B750") IDirect3DCubeTexture8;
interface DECLSPEC_UUID("4B8AAAFA-140F-42BA-9131-597EAFAA2EAD") IDirect3DVolumeTexture8;
interface DECLSPEC_UUID("B96EEBCA-B326-4EA5-882F-2FF5BAE021DD") IDirect3DSurface8;
interface DECLSPEC_UUID("BD7349F5-14F1-42E4-9C79-972380DB40C0") IDirect3DVolume8;
interface DECLSPEC_UUID("8AEEEAC7-05F9-44D4-B591-000B0DF1CB95") IDirect3DVertexBuffer8;
interface DECLSPEC_UUID("0E689C9A-053D-44A0-9D92-DB0E3D750F86") IDirect3DIndexBuffer8;

// MinGW support
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IDirect3D8, 0x1DD9E8DA, 0x1C77, 0x4D40, 0xB0, 0xCF, 0x98,0xFE,0xFD,0xFF,0x95,0x12)
__CRT_UUID_DECL(IDirect3DDevice8, 0x7385E5DF, 0x8FE8, 0x41D5, 0x86, 0xB6, 0xD7,0xB4,0x85,0x47,0xB6,0xCF)
__CRT_UUID_DECL(IDirect3DSwapChain8, 0x928C088B, 0x76B9, 0x4C6B, 0xA5, 0x36, 0xA5,0x90,0x85,0x38,0x76,0xCD)
__CRT_UUID_DECL(IDirect3DResource8, 0x1B36BB7B, 0x09B7, 0x410A, 0xB4, 0x45, 0x7D,0x14,0x30,0xD7,0xB3,0x3F)
__CRT_UUID_DECL(IDirect3DBaseTexture8, 0xB4211CFA, 0x51B9, 0x4A9F, 0xAB, 0x78, 0xDB,0x99,0xB2,0xBB,0x67,0x8E)
__CRT_UUID_DECL(IDirect3DTexture8, 0xE4CDD575, 0x2866, 0x4F01, 0xB1, 0x2E, 0x7E,0xEC,0xE1,0xEC,0x93,0x58)
__CRT_UUID_DECL(IDirect3DCubeTexture8, 0x3EE5B968, 0x2ACA, 0x4C34, 0x8B, 0xB5, 0x7E,0x0C,0x3D,0x19,0xB7,0x50)
__CRT_UUID_DECL(IDirect3DVolumeTexture8, 0x4B8AAAFA, 0x140F, 0x42BA, 0x91, 0x31, 0x59,0x7E,0xAF,0xAA,0x2E,0xAD)
__CRT_UUID_DECL(IDirect3DSurface8, 0xB96EEBCA, 0xB326, 0x4EA5, 0x88, 0x2F, 0x2F,0xF5,0xBA,0xE0,0x21,0xDD)
__CRT_UUID_DECL(IDirect3DVolume8, 0xBD7349F5, 0x14F1, 0x42E4, 0x9C, 0x79, 0x97,0x23,0x80,0xDB,0x40,0xC0)
__CRT_UUID_DECL(IDirect3DVertexBuffer8, 0x8AEEEAC7, 0x05F9, 0x44D4, 0xB5, 0x91, 0x00,0x0B,0x0D,0xF1,0xCB,0x95)
__CRT_UUID_DECL(IDirect3DIndexBuffer8, 0x0E689C9A, 0x053D, 0x44A0, 0x9D, 0x92, 0xDB,0x0E,0x3D,0x75,0x0F,0x86)
#endif

interface IDirect3D8 : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE RegisterSoftwareDevice(void *pInitializeFunction) = 0;
	virtual UINT STDMETHODCALLTYPE GetAdapterCount() = 0;
	virtual HRESULT STDMETHODCALLTYPE GetAdapterIdentifier(UINT Adapter, DWORD Flags, D3DADAPTER_IDENTIFIER8 *pIdentifier) = 0;
	virtual UINT STDMETHODCALLTYPE GetAdapterModeCount(UINT Adapter) = 0;
	virtual HRESULT STDMETHODCALLTYPE EnumAdapterModes(UINT Adapter, UINT Mode, D3DDISPLAYMODE *pMode) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetAdapterDisplayMode(UINT Adapter, D3DDISPLAYMODE *pMode) = 0;
	virtual HRESULT STDMETHODCALLTYPE CheckDeviceType(UINT Adapter, D3DDEVTYPE CheckType, D3DFORMAT DisplayFormat, D3DFORMAT BackBufferFormat, BOOL bWindowed) = 0;
	virtual HRESULT STDMETHODCALLTYPE CheckDeviceFormat(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, DWORD Usage, D3DRESOURCETYPE RType, D3DFORMAT CheckFormat) = 0;
	virtual HRESULT STDMETHODCALLTYPE CheckDeviceMultiSampleType(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT SurfaceFormat, BOOL Windowed, D3DMULTISAMPLE_TYPE MultiSampleType) = 0;
	virtual HRESULT STDMETHODCALLTYPE CheckDepthStencilMatch(UINT Adapter, D3DDEVTYPE DeviceType, D3DFORMAT AdapterFormat, D3DFORMAT RenderTargetFormat, D3DFORMAT DepthStencilFormat) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetDeviceCaps(UINT Adapter, D3DDEVTYPE DeviceType, D3DCAPS8 *pCaps) = 0;
	virtual HMONITOR STDMETHODCALLTYPE GetAdapterMonitor(UINT Adapter) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateDevice(UINT Adapter, D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D3DPRESENT_PARAMETERS8 *pPresentationParameters, IDirect3DDevice8 **ppReturnedDeviceInterface) = 0;
};

interface IDirect3DDevice8 : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE TestCooperativeLevel() = 0;
	virtual UINT STDMETHODCALLTYPE GetAvailableTextureMem() = 0;
	virtual HRESULT STDMETHODCALLTYPE ResourceManagerDiscardBytes(DWORD Bytes) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetDirect3D(IDirect3D8 **ppD3D8) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetDeviceCaps(D3DCAPS8 *pCaps) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetDisplayMode(D3DDISPLAYMODE *pMode) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCreationParameters(D3DDEVICE_CREATION_PARAMETERS *pParameters) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetCursorProperties(UINT XHotSpot, UINT YHotSpot, IDirect3DSurface8 *pCursorBitmap) = 0;
	virtual void STDMETHODCALLTYPE SetCursorPosition(UINT XScreenSpace, UINT YScreenSpace, DWORD Flags) = 0;
	virtual BOOL STDMETHODCALLTYPE ShowCursor(BOOL bShow) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateAdditionalSwapChain(D3DPRESENT_PARAMETERS8 *pPresentationParameters, IDirect3DSwapChain8 **ppSwapChain) = 0;
	virtual HRESULT STDMETHODCALLTYPE Reset(D3DPRESENT_PARAMETERS8 *pPresentationParameters) = 0;
	virtual HRESULT STDMETHODCALLTYPE Present(const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface8 **ppBackBuffer) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetRasterStatus(D3DRASTER_STATUS *pRasterStatus) = 0;
	virtual void STDMETHODCALLTYPE SetGammaRamp(DWORD Flags, const D3DGAMMARAMP *pRamp) = 0;
	virtual void STDMETHODCALLTYPE GetGammaRamp(D3DGAMMARAMP *pRamp) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateTexture(UINT Width, UINT Height, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DTexture8 **ppTexture) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateVolumeTexture(UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DVolumeTexture8 **ppVolumeTexture) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateCubeTexture(UINT EdgeLength, UINT Levels, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DCubeTexture8 **ppCubeTexture) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateVertexBuffer(UINT Length, DWORD Usage, DWORD FVF, D3DPOOL Pool, IDirect3DVertexBuffer8 **ppVertexBuffer) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateIndexBuffer(UINT Length, DWORD Usage, D3DFORMAT Format, D3DPOOL Pool, IDirect3DIndexBuffer8 **ppIndexBuffer) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateRenderTarget(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, BOOL Lockable, IDirect3DSurface8 **ppSurface) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateDepthStencilSurface(UINT Width, UINT Height, D3DFORMAT Format, D3DMULTISAMPLE_TYPE MultiSample, IDirect3DSurface8 **ppSurface) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateImageSurface(UINT Width, UINT Height, D3DFORMAT Format, IDirect3DSurface8 **ppSurface) = 0;
	virtual HRESULT STDMETHODCALLTYPE CopyRects(IDirect3DSurface8 *pSourceSurface, const RECT *pSourceRectsArray, UINT cRects, IDirect3DSurface8 *pDestinationSurface, const POINT *pDestPointsArray) = 0;
	virtual HRESULT STDMETHODCALLTYPE UpdateTexture(IDirect3DBaseTexture8 *pSourceTexture, IDirect3DBaseTexture8 *pDestinationTexture) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetFrontBuffer(IDirect3DSurface8 *pDestSurface) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetRenderTarget(IDirect3DSurface8 *pRenderTarget, IDirect3DSurface8 *pNewZStencil) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetRenderTarget(IDirect3DSurface8 **ppRenderTarget) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetDepthStencilSurface(IDirect3DSurface8 **ppZStencilSurface) = 0;
	virtual HRESULT STDMETHODCALLTYPE BeginScene() = 0;
	virtual HRESULT STDMETHODCALLTYPE EndScene() = 0;
	virtual HRESULT STDMETHODCALLTYPE Clear(DWORD Count, const D3DRECT *pRects, DWORD Flags, D3DCOLOR Color, float Z, DWORD Stencil) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetTransform(D3DTRANSFORMSTATETYPE State, D3DMATRIX *pMatrix) = 0;
	virtual HRESULT STDMETHODCALLTYPE MultiplyTransform(D3DTRANSFORMSTATETYPE State, const D3DMATRIX *pMatrix) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetViewport(const D3DVIEWPORT8 *pViewport) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetViewport(D3DVIEWPORT8 *pViewport) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetMaterial(const D3DMATERIAL8 *pMaterial) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetMaterial(D3DMATERIAL8 *pMaterial) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetLight(DWORD Index, const D3DLIGHT8 *pLight) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetLight(DWORD Index, D3DLIGHT8 *pLight) = 0;
	virtual HRESULT STDMETHODCALLTYPE LightEnable(DWORD Index, BOOL Enable) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetLightEnable(DWORD Index, BOOL *pEnable) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetClipPlane(DWORD Index, const float *pPlane) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetClipPlane(DWORD Index, float *pPlane) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetRenderState(D3DRENDERSTATETYPE State, DWORD Value) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetRenderState(D3DRENDERSTATETYPE State, DWORD *pValue) = 0;
	virtual HRESULT STDMETHODCALLTYPE BeginStateBlock() = 0;
	virtual HRESULT STDMETHODCALLTYPE EndStateBlock(DWORD *pToken) = 0;
	virtual HRESULT STDMETHODCALLTYPE ApplyStateBlock(DWORD Token) = 0;
	virtual HRESULT STDMETHODCALLTYPE CaptureStateBlock(DWORD Token) = 0;
	virtual HRESULT STDMETHODCALLTYPE DeleteStateBlock(DWORD Token) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateStateBlock(D3DSTATEBLOCKTYPE Type, DWORD *pToken) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetClipStatus(const D3DCLIPSTATUS8 *pClipStatus) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetClipStatus(D3DCLIPSTATUS8 *pClipStatus) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetTexture(DWORD Stage, IDirect3DBaseTexture8 **ppTexture) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetTexture(DWORD Stage, IDirect3DBaseTexture8 *pTexture) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD *pValue) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetTextureStageState(DWORD Stage, D3DTEXTURESTAGESTATETYPE Type, DWORD Value) = 0;
	virtual HRESULT STDMETHODCALLTYPE ValidateDevice(DWORD *pNumPasses) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetInfo(DWORD DevInfoID, void *pDevInfoStruct, DWORD DevInfoStructSize) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetPaletteEntries(UINT PaletteNumber, const PALETTEENTRY *pEntries) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetPaletteEntries(UINT PaletteNumber, PALETTEENTRY *pEntries) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetCurrentTexturePalette(UINT PaletteNumber) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCurrentTexturePalette(UINT *PaletteNumber) = 0;
	virtual HRESULT STDMETHODCALLTYPE DrawPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount) = 0;
	virtual HRESULT STDMETHODCALLTYPE DrawIndexedPrimitive(D3DPRIMITIVETYPE PrimitiveType, UINT MinIndex, UINT NumVertices, UINT StartIndex, UINT PrimitiveCount) = 0;
	virtual HRESULT STDMETHODCALLTYPE DrawPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, const void *pVertexStreamZeroData, UINT VertexStreamZeroStride) = 0;
	virtual HRESULT STDMETHODCALLTYPE DrawIndexedPrimitiveUP(D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertexIndices, UINT PrimitiveCount, const void *pIndexData, D3DFORMAT IndexDataFormat, const void *pVertexStreamZeroData, UINT VertexStreamZeroStride) = 0;
	virtual HRESULT STDMETHODCALLTYPE ProcessVertices(UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, IDirect3DVertexBuffer8 *pDestBuffer, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreateVertexShader(const DWORD *pDeclaration, const DWORD *pFunction, DWORD *pHandle, DWORD Usage) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetVertexShader(DWORD Handle) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetVertexShader(DWORD *pHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE DeleteVertexShader(DWORD Handle) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetVertexShaderConstant(DWORD Register, const void *pConstantData, DWORD ConstantCount) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetVertexShaderConstant(DWORD Register, void *pConstantData, DWORD ConstantCount) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetVertexShaderDeclaration(DWORD Handle, void *pData, DWORD *pSizeOfData) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetVertexShaderFunction(DWORD Handle, void *pData, DWORD *pSizeOfData) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer8 *pStreamData, UINT Stride) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetStreamSource(UINT StreamNumber, IDirect3DVertexBuffer8 **ppStreamData, UINT *pStride) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetIndices(IDirect3DIndexBuffer8 *pIndexData, UINT BaseVertexIndex) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetIndices(IDirect3DIndexBuffer8 **ppIndexData, UINT *pBaseVertexIndex) = 0;
	virtual HRESULT STDMETHODCALLTYPE CreatePixelShader(const DWORD *pFunction, DWORD *pHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetPixelShader(DWORD Handle) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetPixelShader(DWORD *pHandle) = 0;
	virtual HRESULT STDMETHODCALLTYPE DeletePixelShader(DWORD Handle) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetPixelShaderConstant(DWORD Register, const void *pConstantData, DWORD ConstantCount) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetPixelShaderConstant(DWORD Register, void *pConstantData, DWORD ConstantCount) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetPixelShaderFunction(DWORD Handle, void *pData, DWORD *pSizeOfData) = 0;
	virtual HRESULT STDMETHODCALLTYPE DrawRectPatch(UINT Handle, const float *pNumSegs, const D3DRECTPATCH_INFO *pRectPatchInfo) = 0;
	virtual HRESULT STDMETHODCALLTYPE DrawTriPatch(UINT Handle, const float *pNumSegs, const D3DTRIPATCH_INFO *pTriPatchInfo) = 0;
	virtual HRESULT STDMETHODCALLTYPE DeletePatch(UINT Handle) = 0;
};

interface IDirect3DSwapChain8 : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE Present(const RECT *pSourceRect, const RECT *pDestRect, HWND hDestWindowOverride, const RGNDATA *pDirtyRegion) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetBackBuffer(UINT iBackBuffer, D3DBACKBUFFER_TYPE Type, IDirect3DSurface8 **ppBackBuffer) = 0;
};

interface IDirect3DResource8 : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) = 0;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) = 0;
	virtual DWORD STDMETHODCALLTYPE SetPriority(DWORD PriorityNew) = 0;
	virtual DWORD STDMETHODCALLTYPE GetPriority() = 0;
	virtual void STDMETHODCALLTYPE PreLoad() = 0;
	virtual D3DRESOURCETYPE STDMETHODCALLTYPE GetType() = 0;
};

interface IDirect3DBaseTexture8 : public IDirect3DResource8
{
	virtual DWORD STDMETHODCALLTYPE SetLOD(DWORD LODNew) = 0;
	virtual DWORD STDMETHODCALLTYPE GetLOD() = 0;
	virtual DWORD STDMETHODCALLTYPE GetLevelCount() = 0;
};

interface IDirect3DTexture8 : public IDirect3DBaseTexture8
{
	virtual HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DSURFACE_DESC8 *pDesc) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetSurfaceLevel(UINT Level, IDirect3DSurface8 **ppSurfaceLevel) = 0;
	virtual HRESULT STDMETHODCALLTYPE LockRect(UINT Level, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE UnlockRect(UINT Level) = 0;
	virtual HRESULT STDMETHODCALLTYPE AddDirtyRect(const RECT *pDirtyRect) = 0;
};

interface IDirect3DCubeTexture8 : public IDirect3DBaseTexture8
{
	virtual HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DSURFACE_DESC8 *pDesc) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetCubeMapSurface(D3DCUBEMAP_FACES FaceType, UINT Level, IDirect3DSurface8 **ppCubeMapSurface) = 0;
	virtual HRESULT STDMETHODCALLTYPE LockRect(D3DCUBEMAP_FACES FaceType, UINT Level, D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE UnlockRect(D3DCUBEMAP_FACES FaceType, UINT Level) = 0;
	virtual HRESULT STDMETHODCALLTYPE AddDirtyRect(D3DCUBEMAP_FACES FaceType, const RECT *pDirtyRect) = 0;
};

interface IDirect3DVolumeTexture8 : public IDirect3DBaseTexture8
{
	virtual HRESULT STDMETHODCALLTYPE GetLevelDesc(UINT Level, D3DVOLUME_DESC8 *pDesc) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetVolumeLevel(UINT Level, IDirect3DVolume8 **ppVolumeLevel) = 0;
	virtual HRESULT STDMETHODCALLTYPE LockBox(UINT Level, D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE UnlockBox(UINT Level) = 0;
	virtual HRESULT STDMETHODCALLTYPE AddDirtyBox(const D3DBOX *pDirtyBox) = 0;
};

interface IDirect3DSurface8 : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) = 0;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetContainer(REFIID riid, void **ppContainer) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DSURFACE_DESC8 *pDesc) = 0;
	virtual HRESULT STDMETHODCALLTYPE LockRect(D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE UnlockRect() = 0;
};

interface IDirect3DVolume8 : public IUnknown
{
	virtual HRESULT STDMETHODCALLTYPE GetDevice(IDirect3DDevice8 **ppDevice) = 0;
	virtual HRESULT STDMETHODCALLTYPE SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData) = 0;
	virtual HRESULT STDMETHODCALLTYPE FreePrivateData(REFGUID refguid) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetContainer(REFIID riid, void **ppContainer) = 0;
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DVOLUME_DESC8 *pDesc) = 0;
	virtual HRESULT STDMETHODCALLTYPE LockBox(D3DLOCKED_BOX *pLockedVolume, const D3DBOX *pBox, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE UnlockBox() = 0;
};

interface IDirect3DVertexBuffer8 : public IDirect3DResource8
{
	virtual HRESULT STDMETHODCALLTYPE Lock(UINT OffsetToLock, UINT SizeToLock, BYTE **ppbData, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE Unlock() = 0;
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DVERTEXBUFFER_DESC *pDesc) = 0;
};

interface IDirect3DIndexBuffer8 : public IDirect3DResource8
{
	virtual HRESULT STDMETHODCALLTYPE Lock(UINT OffsetToLock, UINT SizeToLock, BYTE **ppbData, DWORD Flags) = 0;
	virtual HRESULT STDMETHODCALLTYPE Unlock() = 0;
	virtual HRESULT STDMETHODCALLTYPE GetDesc(D3DINDEXBUFFER_DESC *pDesc) = 0;
};
