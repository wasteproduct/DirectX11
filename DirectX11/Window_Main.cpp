#include <Windows.h>
#include "DirectX11_Main.h"
#include <assert.h>

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASS lpWndClass;
	ZeroMemory(&lpWndClass, sizeof(WNDCLASS));

	lpWndClass.cbClsExtra = 0;
	lpWndClass.cbWndExtra = 0;
	lpWndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	lpWndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	lpWndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	lpWndClass.hInstance = hInstance;
	lpWndClass.lpfnWndProc = WndProc;
	lpWndClass.lpszClassName = L"DirectX 11";
	lpWndClass.lpszMenuName = L"DirectX 11";
	lpWndClass.style = CS_HREDRAW | CS_VREDRAW;

	RegisterClass(&lpWndClass);

	HWND hWnd;
	hWnd = CreateWindow(L"DirectX 11", L"DirectX 11", WS_OVERLAPPEDWINDOW, CW_USEDEFAULT,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);

	ShowWindow(hWnd, nCmdShow);

	MSG message;
	ZeroMemory(&message, sizeof(MSG));

	DirectX11_Main *main = nullptr;
	main = new DirectX11_Main;
	assert(main != nullptr);
	main->Initialize(hWnd);

	while (1)
	{
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE))
		{
			if (message.message == WM_QUIT)break;

			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else
		{
			main->Update();
			main->Render();
		}
	}

	main->Release();
	delete main;
	main = nullptr;

	UnregisterClass(L"DirectX 11", hInstance);

	return (int)message.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
