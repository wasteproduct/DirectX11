#include "Direct3D.h"



Direct3D::Direct3D()
	:device(nullptr), deviceContext(nullptr), swapChain(nullptr)
{
}


Direct3D::~Direct3D()
{
}

void Direct3D::Initialize(HWND hWnd)
{
}

void Direct3D::Release(void)
{
	if (device)
	{
		device->Release();
		delete device;
		device = nullptr;
	}

	if (deviceContext)
	{
		deviceContext->Release();
		delete deviceContext;
		deviceContext = nullptr;
	}

	if (swapChain)
	{
		swapChain->Release();
		delete swapChain;
		swapChain = nullptr;
	}
}
