//! Polar Bear
#ifndef POLAR_BEAR_STRING_H
#define POLAR_BEAR_STRING_H
#include "PBdefine.h"

POLAR_BEAR_BEGIN

class PBchar
{
public:
	PBchar(char c);
	~PBchar();

private:
	unsigned short _c;

};


class PBstring
{
public:
	PBstring(char* s);
	~PBstring();

private:
	PBchar* _s;
};


POLAR_BEAR_END


#endif
