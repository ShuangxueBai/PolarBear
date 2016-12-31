
#define GLEW_STATIC

#include "glm/glm.hpp"
#include "glm/ext.hpp"
#include "glew/glew.h"
#include "glfw/glfw3.h"
#include "PBopenglAPI.h"


#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "glfw3.lib")


PBopenglAPI* PBopenglAPI::_instance = nullptr;

PBrenderAPI* PBopenglAPI::GetInstance()
{
	PB_RETURN_SINGLE_INSTANCE(_instance, PBopenglAPI)
}

PBopenglAPI::PBopenglAPI()
{

}

PBopenglAPI::~PBopenglAPI()
{

}

void PBopenglAPI::init()
{
	glewInit();
}

void PBopenglAPI::destroy()
{
	
}

