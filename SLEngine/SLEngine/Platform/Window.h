#pragma once

#include "stdafx.h"

NS_SL_BEGIN

class TutorialBase {
public:
	virtual bool OnWindowSizeChanged()
	{
		return true;
	}
	virtual bool Draw()
	{
		return true;
	}

	virtual bool ReadyToDraw() const final {
		return CanRender;
	}

	TutorialBase() :
		CanRender(false) {
	}

	virtual ~TutorialBase() {
	}

protected:
	bool CanRender;
};

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
	bool              RenderingLoop(TutorialBase &tutorial) const;
	WindowParameters  GetParameters() const;

private:
	WindowParameters  Parameters;
};

NS_SL_END
