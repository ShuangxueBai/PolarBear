#include <stdio.h>
#include <stdarg.h>
#include "base/PBdebugHelper.h"

#ifdef PB_DEBUG_HELPER_USE

#ifdef PB_OS_WIN
#include <windows.h>
#endif

void ConsoleOutDebugInfo(const char* s, ...)
{
	char buf[4096] = { 0 };
	va_list args;
	va_start(args, s);
	_vsnprintf_s(buf, sizeof(buf) - 1, 4096, s, args);
	va_end(args);
#ifdef PB_OS_WIN
	OutputDebugStringA(buf);
#endif 

}

#else



#endif


