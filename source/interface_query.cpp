/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#define INITGUID

#include "d3d8to9.hpp"

REFIID ConvertREFIID(REFIID riid)
{
	return (riid == __uuidof(Direct3D8)) ? IID_IDirect3D9 :
		(riid == __uuidof(Direct3DDevice8)) ? IID_IDirect3DDevice9 :
		(riid == __uuidof(Direct3DTexture8)) ? IID_IDirect3DTexture9 :
		(riid == __uuidof(Direct3DCubeTexture8)) ? IID_IDirect3DCubeTexture9 :
		(riid == __uuidof(Direct3DVolumeTexture8)) ? IID_IDirect3DVolumeTexture9 :
		(riid == __uuidof(Direct3DVertexBuffer8)) ? IID_IDirect3DVertexBuffer9 :
		(riid == __uuidof(Direct3DIndexBuffer8)) ? IID_IDirect3DIndexBuffer9 :
		(riid == __uuidof(Direct3DSurface8)) ? IID_IDirect3DSurface9 :
		(riid == __uuidof(Direct3DVolume8)) ? IID_IDirect3DVolume9 :
		(riid == __uuidof(Direct3DSwapChain8)) ? IID_IDirect3DSwapChain9 :
		riid;
}

void genericQueryInterface(REFIID riid, LPVOID *ppvObj, Direct3DDevice8* pDevice)
{
	if (!ppvObj || !*ppvObj || !pDevice)
	{
		return;
	}

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

#define QUERYINTERFACE(x) \
	if (riid == __uuidof(x)) \
		{ \
			*ppvObj = pDevice->ProxyAddressLookupTable->FindAddress<x>(*ppvObj); \
			return; \
		}

	QUERYINTERFACE(Direct3DTexture8);
	QUERYINTERFACE(Direct3DCubeTexture8);
	QUERYINTERFACE(Direct3DVolumeTexture8);
	QUERYINTERFACE(Direct3DVertexBuffer8);
	QUERYINTERFACE(Direct3DIndexBuffer8);
	QUERYINTERFACE(Direct3DSurface8);
	QUERYINTERFACE(Direct3DVolume8);
	QUERYINTERFACE(Direct3DSwapChain8);
}
