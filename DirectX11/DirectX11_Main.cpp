#include "DirectX11_Main.h"
#include <assert.h>


DirectX11_Main::DirectX11_Main()
	:d3d(nullptr)
{
}


DirectX11_Main::~DirectX11_Main()
{
}

void DirectX11_Main::Initialize(HWND hWnd)
{
	d3d = new Direct3D;
	assert(d3d != nullptr);
	d3d->Initialize(hWnd);
}

void DirectX11_Main::Release(void)
{
	if (d3d)
	{
		d3d->Release();
		delete d3d;
		d3d = nullptr;
	}
}

void DirectX11_Main::Update(void)
{
}

void DirectX11_Main::Render(void)
{
}
