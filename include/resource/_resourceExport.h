#ifndef _polar_bear_resource_export_h
#define _polar_bear_resource_export_h

#ifdef _WIN32
#ifdef POLAR_BEAR_RESOURCE_EXPORT 
#define RESOURCE_EXT __declspec(dllexport)
#else
#define RESOURCE_EXT __declspec(dllimport)
#endif
#else
#define RESOURCE_EXT
#endif

#endif