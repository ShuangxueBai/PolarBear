//PBbase

#ifndef POLAR_BEAR_PLATFORM_H
#define POLAR_BEAR_PLATFORM_H


#define POLAR_BEAR_BEGIN namespace PolarBear {
#define POLAR_BEAR_END }
#define POLAR_BEAR_USE_NAMESPACE using namespace PolarBear


#ifdef _WIN32

#ifdef POLAR_BEAR_BASE_EXPORT 
#define BASE_EXT __declspec(dllexport)
#else
#define BASE_EXT __declspec(dllimport)
#endif
#else
#define BASE_EXT
#endif

#endif



