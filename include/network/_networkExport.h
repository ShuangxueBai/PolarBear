#ifndef _polar_bear_network_export_h
#define _polar_bear_network_export_h

#ifdef _WIN32
#ifdef POLAR_BEAR_NETWORK_EXPORT 
#define NETWORK_EXT __declspec(dllexport)
#else
#define NETWORK_EXT __declspec(dllimport)
#endif
#else
#define NETWORK_EXT
#endif


#endif