//!< Polar Bear
#ifndef POLAR_BEAR_WINDOW_IMP_H
#define POLAR_BEAR_WINDOW_IMP_H

#include <functional>
#include "PBdefine.h"
#include "glfw/glfw3.h"

POLAR_BEAR_BEGIN

class PBwindowImp
{
public:

	static int Init();
	static void Terminate();
	static void MainLoop();
	static void RegisterDrawCallback(std::function<void(void)> pFunc);
	static void SetContextWindow(GLFWwindow* window);
	static GLFWwindow* GetContextWindow();

	PBwindowImp(const unsigned int w, const unsigned int h, const char* title = nullptr);
	~PBwindowImp();

	void makeContextWindow();

private:
	GLFWwindow* _window;
	static std::function<void(void)> _drawFunc;
};


POLAR_BEAR_END

#endif