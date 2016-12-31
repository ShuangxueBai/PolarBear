#ifndef _polar_bear_export_h
#define _polar_bear_export_h

#ifdef _WIN32
#ifdef POLAR_BEAR_EXPORT 
#define POLARBEAR_EXT __declspec(dllexport)
#else
#define POLARBEAR_EXT __declspec(dllimport)
#endif
#else
#define POLARBEAR_EXT
#endif

#endif