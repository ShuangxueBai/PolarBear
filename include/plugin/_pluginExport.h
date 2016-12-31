#ifndef _polar_bear_plugin_export_h
#define _polar_bear_plugin_export_h

#ifdef _WIN32
#ifdef POLAR_BEAR_PLUGIN_EXPORT 
#define PLUGIN_EXT __declspec(dllexport)
#else
#define PLUGIN_EXT __declspec(dllimport)
#endif
#else
#define PLUGIN_EXT
#endif

#endif