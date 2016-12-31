//!Polar Bear
#ifndef POLAR_BEAR_TYPES_H
#define POLAR_BEAR_TYPES_H

#include "base/PBplatform.h"

typedef char pbchar;
typedef short pbshort;
typedef int pbint;
typedef long pblong;
typedef long long pbllong;

typedef unsigned char pbuchar;
typedef unsigned short pbushort;
typedef unsigned int pbuint;
typedef unsigned long pbulong;
typedef unsigned long long pbullong;

typedef float pbfloat;
typedef double pbdouble;

#if defined(PB_OS_WIN)

typedef pbchar  pbint8;
typedef pbshort pbint16;
typedef pbint   pbint32;
typedef pbllong pbint64;

typedef pbuchar  pbuint8;
typedef pbushort pbuint16;
typedef pbuint   pbuint32;
typedef pbullong pbuint64;

#elif defined(PB_OS_MAC)

#elif defined(PB_OS_LINUX)

#elif defined(PB_OS_UNIX)

#endif

typedef pbuint8 pbbyte;

#endif


