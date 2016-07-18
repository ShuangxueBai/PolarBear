#include "precompile.h"
#include "assimp/cimport.h"
#include "assimp/scene.h"
#include "assimp/postprocess.h"

using namespace std;

static void error_callBack(int error, const char* description)
{
	fputs(description, stderr);
}

static void key_callBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_F && action == GLFW_PRESS)
		glfwSetWindowSize(window, 640, 480);
	if (key == GLFW_KEY_G && action == GLFW_PRESS)
	{
		GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
		if (primaryMonitor)
		{
			const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
			glfwSetWindowSize(window, mode->width, mode->height);
		}
	}
}

int main(int argc, char** argv)
{

	GLFWwindow* window = nullptr;

	glfwSetErrorCallback(error_callBack);

	if (!glfwInit())
		return -1;

	GLFWmonitor* primaryMonitor = glfwGetPrimaryMonitor();
	if (!primaryMonitor)
	{
		glfwTerminate();
		return -1;
	}

	const GLFWvidmode* mode = glfwGetVideoMode(primaryMonitor);
	glfwWindowHint(GLFW_RED_BITS, mode->redBits);
	glfwWindowHint(GLFW_GREEN_BITS, mode->greenBits);
	glfwWindowHint(GLFW_BLUE_BITS, mode->blueBits);
	glfwWindowHint(GLFW_REFRESH_RATE, mode->refreshRate);

	const int w = mode->width;
	const int h = mode->height;


	window = glfwCreateWindow(w, h, "Hello World", nullptr, nullptr);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, key_callBack);

	GLenum err = glewInit();
	if (GLEW_OK != err)
	{
		glfwTerminate();
		return -1;
	}


	while (!glfwWindowShouldClose(window))
	{
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();

	cout << "tests project terminated!" << endl;
	cin.clear();
	cin.sync();
	cin.get();
	return 0;

}






