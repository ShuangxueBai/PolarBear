#ifndef _polar_bear_scene_export_h
#define _polar_bear_scene_export_h

#ifdef _WIN32
#ifdef PBSCENE_EXPORTS
#define SCENE_EXT __declspec(dllexport)
#else
#define SCENE_EXT __declspec(dllimport)
#endif
#else
#define SCENE_EXT
#endif

#endif