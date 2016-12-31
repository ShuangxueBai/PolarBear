#include "base/PBwindow.h"
#include "PBwindowImp.h"

POLAR_BEAR_BEGIN

int PBwindow::Init()
{
	return PBwindowImp::Init();
}

void PBwindow::Terminate()
{
	PBwindowImp::Terminate();
}

PBwindow* PBwindow::Create(const unsigned int w /* = 600 */, const unsigned int h /* = 400 */, const char* title /* = nullptr */)
{
	return new PBwindow(w, h, title);
}

void PBwindow::MainLoop()
{
	PBwindowImp::MainLoop();
}

void PBwindow::RegisterDrawCallbackFunc(std::function<void(void)> pFunc)
{
	PBwindowImp::RegisterDrawCallback(pFunc);
}

PBwindow::PBwindow(const unsigned int w /* = 600 */, const unsigned int h /* = 400 */, const char* title /* = nullptr */)
	: _imp(new PBwindowImp(w, h, title))
{

}

PBwindow::~PBwindow()
{
	PB_DELETE_PTR(_imp)
}

void PBwindow::makeContextWindow()
{
	_imp->makeContextWindow();
}

POLAR_BEAR_END
