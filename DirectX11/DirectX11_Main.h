#pragma once

#include "Direct3D.h"

class DirectX11_Main
{
public:
	DirectX11_Main();
	~DirectX11_Main();

	void Initialize(HWND hWnd);
	void Release(void);
	void Update(void);
	void Render(void);

private:
	Direct3D * d3d;
};

