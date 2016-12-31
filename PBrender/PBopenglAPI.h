//! Polar Bear
#ifndef POLAR_BEAR_OPENGL_API_H
#define POLAR_BEAR_OPENGL_API_H



#define GLEW_STATIC


#include "PBrenderAPI.h"
class GLFWwindow;
class PBopenglAPI : public PBrenderAPI
{
public:

	static PBrenderAPI* GetInstance();

	virtual void init() override;
	virtual void destroy() override;

protected:
	PBopenglAPI();
	~PBopenglAPI();


private:
	static PBopenglAPI* _instance;

	GLFWwindow* _window = nullptr;

};



#endif