#ifndef _polar_bear_render_export_h
#define _polar_bear_render_export_h

#ifdef _WIN32
#ifdef POLAR_BEAR_RENDER_EXPORT 
#define RENDER_EXT __declspec(dllexport)
#else
#define RENDER_EXT __declspec(dllimport)
#endif
#else
#define RENDER_EXT
#endif

#endif