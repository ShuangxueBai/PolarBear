//!< polar bear
#ifndef POLAR_BEAR_DEBUG_HELPER_H
#define POLAR_BEAR_DEBUG_HELPER_H
#include <iostream>
#include <exception>
#include "base/PBplatform.h"

namespace PB_Debug_Info
{

#ifdef PB_DEBUG_HELPER_USE

extern void StringFormat(const char* s);

template<typename T, typename... Args>
void StringFormat(const char *s, T value, Args... args)
{
	while (*s)
	{
		if ('%' == *s && *(++s) != '%')
		{
			// add some format eg.std::dec or std::hex or std::oct.
			std::cout << value;
			StringFormat(*s ? ++s : s, args...);
			return;
		}
		std::out << *s++;
	}//end while
	throw std::logic_error("extra arguments provided to console out debug information!");
}


template<typename T, typename... Args>
void ConsoleOutInfo(const char* s, T value, Args... args)
{
	StringFormat(s, value, args...);
	std::cout;
}


extern void ConsoleOutDebugInfo(const char* s, ...);


#else



#endif

}

#endif

