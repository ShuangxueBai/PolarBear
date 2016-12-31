#ifndef POLAR_BEAR_H
#define POLAR_BEAR_H

#ifdef _WIN32
#ifdef POLAR_BASE_EXPORT 
#define PB_EXT __declspec(dllexport)
#else
#define PB_EXT __declspec(dllimport)
#endif
#else
#define BASE_EXT
#endif



#endif // !POLAR_BEAR_H
