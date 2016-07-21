
#include "stdafx.h"
#include "Window.h"
#include <thread>
#include "Application.h"

NS_SL_BEGIN

Window::Window()
:Parameters()
{
}

WindowParameters Window::GetParameters() const {
	return Parameters;
}

#define TUTORIAL_NAME (_T("API without Secrets: Introduction to Vulkan"))

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_SIZE:
	case WM_EXITSIZEMOVE:
		PostMessage(hWnd, WM_USER + 1, wParam, lParam);
		break;
	case WM_KEYDOWN:
	case WM_CLOSE:
		PostMessage(hWnd, WM_USER + 2, wParam, lParam);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

Window::~Window()
{
	if (Parameters.Handle)
	{
		DestroyWindow(Parameters.Handle);
	}

	if (Parameters.Instance)
	{
		UnregisterClass(TUTORIAL_NAME, Parameters.Instance);
	}
}

bool Window::Create(LPCWSTR title) {
	Parameters.Instance = GetModuleHandle(nullptr);

	// Register window class
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = Parameters.Instance;
	wcex.hIcon = NULL;
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = TUTORIAL_NAME;
	wcex.hIconSm = NULL;

	if (!RegisterClassEx(&wcex)) {
		return false;
	}

	// Create window
	Parameters.Handle = CreateWindow(TUTORIAL_NAME, title, WS_OVERLAPPEDWINDOW, 20, 20, 500, 500, nullptr, nullptr, Parameters.Instance, nullptr);
	if (!Parameters.Handle) {
		return false;
	}

	return true;
}

bool Window::RenderingLoop(Application* pApplication) const {
	// Display window
	ShowWindow(Parameters.Handle, SW_SHOWNORMAL);
	UpdateWindow(Parameters.Handle);

	// Main message loop
	MSG message;
	bool loop = true;
	bool resize = false;
	bool result = true;

	LARGE_INTEGER nLast;
	QueryPerformanceCounter(&nLast);

	LARGE_INTEGER nNow;


	

	while (loop) {
		if (PeekMessage(&message, NULL, 0, 0, PM_REMOVE)) {
			// Process events
			switch (message.message) {
				// Resize
			case WM_USER + 1:
				resize = true;
				break;
				// Close
			case WM_USER + 2:
				loop = false;
				break;
			}
			TranslateMessage(&message);
			DispatchMessage(&message);
		}
		else {
			// Draw
			if (resize) {
				resize = false;
				if (!pApplication->OnWindowSizeChanged()) {
					result = false;
					break;
				}
			}
			if (pApplication->ReadyToDraw())
			{
				QueryPerformanceCounter(&nNow);

				LONGLONG sInterval = nNow.QuadPart - nLast.QuadPart;
				LARGE_INTEGER sIntervalNeed = pApplication->getInterval();
				if (sInterval > sIntervalNeed.QuadPart)
				{
					nLast.QuadPart = nNow.QuadPart - (nNow.QuadPart % sIntervalNeed.QuadPart);

					Time::GetInstance()->setDelta((float)sInterval / (float)pApplication->getFreq().QuadPart);

					if (!pApplication->Draw()) {
						result = false;
						break;
					}

					//// Update world
					//WorldManager::GetInstance()->getWorldCur()->onUpdate();

					//// Draw world
					//VulkanManager::GetInstance()->getVulkanAgent()->Draw();
				}

				//if (!pApplication->Draw()) {
				//	result = false;
				//	break;
				//}
			}
			else {
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
			}
		}
	}

	return result;
}

NS_SL_END
