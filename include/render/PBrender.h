//!Polar Bear
#ifndef POLAR_BEAR_RENDER_H
#define POLAR_BEAR_RENDER_H
#include "_renderExport.h"

struct RENDER_EXT PBrender
{
	virtual void init() = 0;
	virtual void destroy() = 0;

};

#endif