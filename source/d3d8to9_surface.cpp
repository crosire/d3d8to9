/**
 * Copyright (C) 2015 Patrick Mours. All rights reserved.
 * License: https://github.com/crosire/d3d8to9#license
 */

#include "d3d8to9.hpp"

Direct3DSurface8::Direct3DSurface8(Direct3DDevice8 *Device, IDirect3DSurface9 *ProxyInterface) :
	Device(Device), ProxyInterface(ProxyInterface)
{
	Device->ProxyAddressLookupTable->SaveAddress(this, ProxyInterface);
}
Direct3DSurface8::~Direct3DSurface8()
{
}

HRESULT STDMETHODCALLTYPE Direct3DSurface8::QueryInterface(REFIID riid, void **ppvObj)
{
	if (ppvObj == nullptr)
		return E_POINTER;

	if (riid == __uuidof(IDirect3DSurface8) ||
		riid == __uuidof(IUnknown))
	{
		AddRef();
		*ppvObj = static_cast<IDirect3DSurface8 *>(this);

		return S_OK;
	}

	const HRESULT hr = ProxyInterface->QueryInterface(ConvertREFIID(riid), ppvObj);
	if (SUCCEEDED(hr))
		GenericQueryInterface(riid, ppvObj, Device);

	return hr;
}
ULONG STDMETHODCALLTYPE Direct3DSurface8::AddRef()
{
	return ProxyInterface->AddRef();
}
ULONG STDMETHODCALLTYPE Direct3DSurface8::Release()
{
	return ProxyInterface->Release();
}

HRESULT STDMETHODCALLTYPE Direct3DSurface8::GetDevice(IDirect3DDevice8 **ppDevice)
{
	if (ppDevice == nullptr)
		return D3DERR_INVALIDCALL;

	Device->AddRef();

	*ppDevice = Device;

	return D3D_OK;
}
HRESULT STDMETHODCALLTYPE Direct3DSurface8::SetPrivateData(REFGUID refguid, const void *pData, DWORD SizeOfData, DWORD Flags)
{
	return ProxyInterface->SetPrivateData(refguid, pData, SizeOfData, Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DSurface8::GetPrivateData(REFGUID refguid, void *pData, DWORD *pSizeOfData)
{
	return ProxyInterface->GetPrivateData(refguid, pData, pSizeOfData);
}
HRESULT STDMETHODCALLTYPE Direct3DSurface8::FreePrivateData(REFGUID refguid)
{
	return ProxyInterface->FreePrivateData(refguid);
}
HRESULT STDMETHODCALLTYPE Direct3DSurface8::GetContainer(REFIID riid, void **ppContainer)
{
	const HRESULT hr = ProxyInterface->GetContainer(ConvertREFIID(riid), ppContainer);
	if (SUCCEEDED(hr))
		GenericQueryInterface(riid, ppContainer, Device);

	return hr;
}
HRESULT STDMETHODCALLTYPE Direct3DSurface8::GetDesc(D3DSURFACE_DESC8 *pDesc)
{
	if (pDesc == nullptr)
		return D3DERR_INVALIDCALL;

	D3DSURFACE_DESC SurfaceDesc;

	const HRESULT hr = ProxyInterface->GetDesc(&SurfaceDesc);
	if (FAILED(hr))
		return hr;

	ConvertSurfaceDesc(SurfaceDesc, *pDesc);

	return D3D_OK;
}
HRESULT STDMETHODCALLTYPE Direct3DSurface8::LockRect(D3DLOCKED_RECT *pLockedRect, const RECT *pRect, DWORD Flags)
{
	return ProxyInterface->LockRect(pLockedRect, pRect, Flags);
}
HRESULT STDMETHODCALLTYPE Direct3DSurface8::UnlockRect()
{
	return ProxyInterface->UnlockRect();
}
