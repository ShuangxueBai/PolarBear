#ifndef _polar_bear_script_export_h
#define _polar_bear_script_export_h

#ifdef _WIN32
#ifdef POLAR_BEAR_SCRIPT_EXPORT 
#define SCRIPT_EXT __declspec(dllexport)
#else
#define SCRIPT_EXT __declspec(dllimport)
#endif
#else
#define SCRIPT_EXT
#endif

#endif