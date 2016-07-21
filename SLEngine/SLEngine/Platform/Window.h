#pragma once

#include "stdafx.h"

NS_SL_BEGIN

class Application;

// ************************************************************ //
// WindowParameters                                             //
//                                                              //
// OS dependent window parameters                               //
// ************************************************************ //
struct WindowParameters {
	HINSTANCE           Instance;
	HWND                Handle;

	WindowParameters()
	:Instance(),
	 Handle()
	{
	}
};

// ************************************************************ //
// Window                                                       //
//                                                              //
// OS dependent window creation and destruction class           //
// ************************************************************ //
class Window {
public:
	Window();
	~Window();

	bool              Create(LPCWSTR title);
	bool              RenderingLoop(Application* pApplication) const;
	WindowParameters  GetParameters() const;

private:
	WindowParameters  Parameters;
};

NS_SL_END
