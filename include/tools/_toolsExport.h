#ifndef _polar_bear_tools_export_h
#define _polar_bear_tools_export_h

#ifdef _WIN32
#ifdef PBTOOLS_EXPORT 
#define TOOLS_EXT __declspec(dllexport)
#else
#define TOOLS_EXT __declspec(dllimport)
#endif
#else
#define TOOLS_EXT
#endif

#endif