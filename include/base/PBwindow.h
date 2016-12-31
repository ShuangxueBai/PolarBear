//! Polar Bear
#ifndef POLAR_BEAR_WINDOW_H
#define POLAR_BEAR_WINDOW_H

#include "base/_baseExport.h"
#include "PBdefine.h"
#include <functional>

POLAR_BEAR_BEGIN

class PBwindowImp;
class BASE_EXT PBwindow
{
public:

	static PBwindow* Create(const unsigned int w = 600, const unsigned int h = 400, const char* title = nullptr);
	static int Init();
	static void Terminate();
	static void MainLoop();
	static void RegisterDrawCallbackFunc(std::function<void(void)> pFunc);

	void makeContextWindow();
	~PBwindow();
protected:
	PBwindow(const unsigned int w = 600, const unsigned int h = 400, const char* title = nullptr);
private:
	PBwindowImp* _imp;
};

POLAR_BEAR_END

#endif