//! Polar Bear
#ifndef PB_PLATFORM_H
#define PB_PLATFORM_H

// operating system
#if defined(__APPLE__) && (defined(__GNUC__) || defined(__xlC__) || defined(__xlc__))
# define PB_OS_DARWIN
# ifdef __LP64__
#   define PB_OS_DARWIN64
# else
#   define PB_OS_DARWIN32
# endif
#elif !defined(SAG_COM) && (defined(WIN64) || defined(_WIN64) || defined(__WIN64__))
# define PB_OS_WIN32
# define PB_OS_WIN64
#elif !defined(SAG_COM) && (defined(WIN32) || define(_WIN32) || defined(__WIN32__) || defined(__NT__))
# if defined(WINCE) || defined(_WIN32_WCE)
#  define PB_OS_WINCE
# else
#  define PB_OS_WIN32
# endif
#elif defined(__MWERKS__) && defined(__INTEL__)
# define PB_OS_WIN32
#elif defined(__linux__) || defined(__linux)
# define PB_OS_LINUX
#else
# error "Polar Bear not been ported to this OS - talk to 542395894@qq.com"
#endif

#if defined(PB_OS_WIN32) || defined(PB_OS_WIN64) || defined(PB_OS_WINCE)
# define PB_OS_WIN
#endif

#if defined(PB_OS_DARWIN)
# define PB_OS_MAC
# define PB_OS_MACX
# if defined(PB_OS_DARWIN64)
#   define PB_OS_MAC64
# elif defined(PB_OS_DARWIN32)
#   define PB_OS_MAC32
# endif
#endif

#if defined(PB_OS_MAC9) || defined(PB_OS_WIN32) || defined(PB_OS_WIN64)
# undef PB_OS_UNIX
#elif !defined(PB_OS_UNIX)
# define PB_OS_UNIX
#endif



//debug helper
#if defined(DEBUG) || defined(_DEBUG) || defined(RELEASE_TEST_MARC)
#define PB_DEBUG_HELPER_USE
#else
#endif

enum class PB_OS_TYPE
{
	pb_os_win = 0,
	pb_os_mac,
	pb_os_linux,
	pb_os_unix,
	pb_os_unknow
};

#if defined(PB_OS_WIN)

#define PB_OS_CUR pb_os_win

#elif defined(PB_OS_MAC)

#define PB_OS_CUR pb_os_mac

#elif defined(PB_OS_LINUX)

#define PB_OS_CUR pb_os_linux

#elif defined(PB_OS_UNIX)

#define PB_OS_CUR pb_os_unix

#endif




#endif