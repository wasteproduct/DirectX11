#pragma once

#include <d3d11.h>

#pragma comment(lib,"d3d11.lib")

class Direct3D
{
public:
	Direct3D();
	~Direct3D();

	void Initialize(HWND hWnd);
	void Release(void);

private:
	ID3D11Device * device;
	ID3D11DeviceContext *deviceContext;
	IDXGISwapChain *swapChain;
};

