#ifndef _polar_bear_base_export_h
#define _polar_bear_base_export_h

#ifdef _WIN32
#ifdef PBBASE_EXPORTS 
#define BASE_EXT __declspec(dllexport)
#else
#define BASE_EXT __declspec(dllimport)
#endif
#else
#define BASE_EXT
#endif

#endif