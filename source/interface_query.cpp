/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#define INITGUID
#include "d3d8to9.hpp"

AddressLookupTable::~AddressLookupTable()
{
	for (const auto &cache : AddressCache)
		for (const auto &entry : cache)
			entry.second->DeleteMe();
}

void GenericQueryInterface(REFIID riid, LPVOID *ppvObj, Direct3DDevice8 *pDevice)
{
	if (ppvObj == nullptr || *ppvObj == nullptr || pDevice == nullptr)
		return;

	if (riid == __uuidof(Direct3D8))
	{
		Direct3D8 *pD3D8 = nullptr;
		if (SUCCEEDED(pDevice->GetDirect3D(&pD3D8)) && pD3D8)
		{
			*ppvObj = pD3D8;
			pD3D8->Release();
			return;
		}
	}

	if (riid == __uuidof(Direct3DDevice8))
	{
		*ppvObj = pDevice;
		return;
	}

#define QUERY_INTERFACE(x) \
	if (riid == __uuidof(x)) \
	{ \
		*ppvObj = pDevice->ProxyAddressLookupTable->FindAddress<x>(*ppvObj); \
		return; \
	}

	QUERY_INTERFACE(Direct3DTexture8);
	QUERY_INTERFACE(Direct3DCubeTexture8);
	QUERY_INTERFACE(Direct3DVolumeTexture8);
	QUERY_INTERFACE(Direct3DVertexBuffer8);
	QUERY_INTERFACE(Direct3DIndexBuffer8);
	QUERY_INTERFACE(Direct3DSurface8);
	QUERY_INTERFACE(Direct3DVolume8);
	QUERY_INTERFACE(Direct3DSwapChain8);
}

REFIID ConvertREFIID(REFIID riid)
{
	if (riid == __uuidof(Direct3D8))
		return IID_IDirect3D9;
	if (riid == __uuidof(Direct3DDevice8))
		return IID_IDirect3DDevice9;
	if (riid == __uuidof(Direct3DTexture8))
		return IID_IDirect3DTexture9;
	if (riid == __uuidof(Direct3DCubeTexture8))
		return IID_IDirect3DCubeTexture9;
	if (riid == __uuidof(Direct3DVolumeTexture8))
		return IID_IDirect3DVolumeTexture9;
	if (riid == __uuidof(Direct3DVertexBuffer8))
		return IID_IDirect3DVertexBuffer9;
	if (riid == __uuidof(Direct3DIndexBuffer8))
		return IID_IDirect3DIndexBuffer9;
	if (riid == __uuidof(Direct3DSurface8))
		return IID_IDirect3DSurface9;
	if (riid == __uuidof(Direct3DVolume8))
		return IID_IDirect3DVolume9;
	if (riid == __uuidof(Direct3DSwapChain8))
		return IID_IDirect3DSwapChain9;
	return riid;
}
