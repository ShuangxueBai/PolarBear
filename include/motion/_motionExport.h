#ifndef _polar_bear_motion_export_h
#define _polar_bear_motion_export_h


#ifdef _WIN32
#ifdef PBMOTION_EXPORTS
#define PBMOTION_EXT __declspec(dllexport)
#else
#define PBMOTION_EXT __declspec(dllimport)
#endif
#else
#define PBMOTION_EXT
#endif

#endif