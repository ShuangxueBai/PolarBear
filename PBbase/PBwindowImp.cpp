#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glfw3.lib")

#include "PBwindowImp.h"

POLAR_BEAR_BEGIN

std::function<void(void)> PBwindowImp::_drawFunc = nullptr;

int PBwindowImp::Init()
{
	return glfwInit();
}

void PBwindowImp::Terminate()
{
	glfwTerminate();
}

void PBwindowImp::MainLoop()
{
	while (PBwindowImp::GetContextWindow() && !glfwWindowShouldClose(PBwindowImp::GetContextWindow()))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		if (PBwindowImp::_drawFunc)
			_drawFunc();

		glfwSwapBuffers(PBwindowImp::GetContextWindow());
		glfwPollEvents();
	}
}

static GLFWwindow* s_window = nullptr;
void PBwindowImp::SetContextWindow(GLFWwindow* window)
{
	s_window = window;
}

GLFWwindow* PBwindowImp::GetContextWindow()
{
	return s_window;
}

void PBwindowImp::RegisterDrawCallback(std::function<void(void)> pFunc)
{
	PBwindowImp::_drawFunc = pFunc;
}

PBwindowImp::PBwindowImp(const unsigned int w, const unsigned int h, const char* title /* = nullptr */)
	: _window(nullptr)
{
	GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
	const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

	_window = glfwCreateWindow(w, h, title, nullptr, nullptr);
}

PBwindowImp::~PBwindowImp()
{

}

void PBwindowImp::makeContextWindow()
{
	PBwindowImp::SetContextWindow(_window);
}

POLAR_BEAR_END
