#ifndef _polar_bear_file_system_export_h
#define _polar_bear_file_system_export_h

#ifdef _WIN32
#ifdef PBFILESYSTEM_EXPORTS 
#define FILESYSTEM_EXT __declspec(dllexport)
#else
#define FILESYSTEM_EXT __declspec(dllimport)
#endif
#else
#define FILESYSTEM_EXT
#endif



#endif