#ifndef POLAR_BEAR_MATH_H
#define POLAR_BEAR_MATH_H

#include "PBdefine.h"
#include "base/PBtypes.h"
#include "base/_baseExport.h"

#define PB_ARRAY_COUNT(a) (sizeof(a[0]) / sizeof(a))

#define PB_MIN(a, b) (((a) < (b)) ? (a) : (b))
#define PB_MAX(a, b) (((a) > (b)) ? (a) : (b))

#define PB_FLOAD_EPSILON 0.000001f
#define PB_DOUBLE_EPSILON 0.00000000000001

POLAR_BEAR_BEGIN

namespace PBmath {

	struct pbvector2i
	{
		pbint x;
		pbint y;
	};

	struct pbvector2f
	{
		pbfloat x;
		pbfloat y;
	};

	struct pbvector2d
	{
		pbdouble x;
		pbdouble y;
	};

	struct pbvector3i
	{
		pbint x;
		pbint y;
		pbint z;
	};

	struct pbvector3f
	{
		pbfloat x;
		pbfloat y;
		pbfloat z;
	};

	struct pbvector3d
	{
		pbdouble x;
		pbdouble y;
		pbdouble z;
	};

	BASE_EXT inline pbvector2i operator+(const pbvector2i& v1, const pbvector2i& v2);
	BASE_EXT inline pbvector2i operator-(const pbvector2i& v1, const pbvector2i& v2);
	BASE_EXT inline pbvector2i operator*(pbint n, const pbvector2i& v);
	BASE_EXT inline pbvector2i operator*(const pbvector2i& v, pbint n);
	BASE_EXT inline pbvector2i operator/(const pbvector2i& v, pbint n);
	BASE_EXT inline bool operator==(const pbvector2i& v1, const pbvector2i& v2);
	BASE_EXT inline bool operator!=(const pbvector2i& v1, const pbvector2i& v2);
	BASE_EXT inline void normalize(pbvector2i& v);
	BASE_EXT inline pbint mag(const pbvector2i& v);
	BASE_EXT inline pbint distance(const pbvector2i& v1, const pbvector2i& v2);
	BASE_EXT inline pbint dot(const pbvector2i& v1, const pbvector2i& v2);

	BASE_EXT inline pbvector2f operator+(const pbvector2f& v1, const pbvector2f& v2);
	BASE_EXT inline pbvector2f operator-(const pbvector2f& v1, const pbvector2f& v2);
	BASE_EXT inline pbvector2f operator*(const pbvector2f& v, pbfloat n);
	BASE_EXT inline pbvector2f operator*(pbfloat n, const pbvector2f& v);
	BASE_EXT inline pbvector2f operator/(const pbvector2f& v, pbfloat n);
	BASE_EXT inline bool operator==(const pbvector2f& v1, const pbvector2f& v2);
	BASE_EXT inline bool operator!=(const pbvector2f& v1, const pbvector2f& v2);
	BASE_EXT inline void normalize(pbvector2f& v);
	BASE_EXT inline pbfloat mag(const pbvector2f& v);
	BASE_EXT inline pbfloat distance(const pbvector2f& v1, const pbvector2f& v2);
	BASE_EXT inline pbfloat dot(const pbvector2f& v1, const pbvector2f& v2);

	BASE_EXT inline pbvector2d operator+(const pbvector2d& v1, const pbvector2d& v2);
	BASE_EXT inline pbvector2d operator-(const pbvector2d& v1, const pbvector2d& v2);
	BASE_EXT inline pbvector2d operator*(const pbvector2d& v, pbdouble n);
	BASE_EXT inline pbvector2d operator*(pbdouble n, const pbvector2d& v);
	BASE_EXT inline pbvector2d operator/(const pbvector2d& v, pbdouble n);
	BASE_EXT inline bool operator==(const pbvector2d& v1, const pbvector2d& v2);
	BASE_EXT inline bool operator!=(const pbvector2d& v1, const pbvector2d& v2);
	BASE_EXT inline void normalize(pbvector2d& v);
	BASE_EXT inline pbdouble mag(const pbvector2d& v);
	BASE_EXT inline pbdouble distance(const pbvector2d& v1, const pbvector2d& v2);
	BASE_EXT inline pbdouble dot(const pbvector2d& v1, const pbvector2d& v2);

	BASE_EXT inline pbvector3i operator+(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline pbvector3i operator-(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline pbvector3i operator*(const pbvector3i& v, pbint n);
	BASE_EXT inline pbvector3i operator*(pbint n, const pbvector3i& v);
	BASE_EXT inline pbvector3i operator/(const pbvector3i& v, pbint n);
	BASE_EXT inline bool operator==(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline bool operator!=(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline void normalize(pbvector3i& v);
	BASE_EXT inline pbint mag(const pbvector3i& v);
	BASE_EXT inline pbint distance(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline pbvector3i cross(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline pbint dot(const pbvector3i& v1, const pbvector3i& v2);

	BASE_EXT inline pbvector3f operator+(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline pbvector3f operator-(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline pbvector3f operator*(const pbvector3f& v, pbfloat n);
	BASE_EXT inline pbvector3f operator*(pbfloat n, const pbvector3f& v);
	BASE_EXT inline pbvector3f operator/(const pbvector3f& v, pbfloat n);
	BASE_EXT inline bool operator==(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline bool operator!=(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline void normalize(pbvector3f& v);
	BASE_EXT inline pbfloat mag(const pbvector3f& v);
	BASE_EXT inline pbfloat distance(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline pbvector3f cross(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline pbfloat dot(const pbvector3f& v1, const pbvector3f& v2);

	BASE_EXT inline pbvector3d operator+(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline pbvector3d operator-(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline pbvector3d operator*(const pbvector3d& v, pbdouble n);
	BASE_EXT inline pbvector3d operator*(pbdouble n, const pbvector3d& v);
	BASE_EXT inline pbvector3d operator/(const pbvector3d& v, pbdouble n);
	BASE_EXT inline bool operator==(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline bool operator!=(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline void normalize(pbvector3d& v);
	BASE_EXT inline pbdouble mag(const pbvector3d& v);
	BASE_EXT inline pbdouble distance(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline pbvector3d cross(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline pbdouble dot(const pbvector3d& v1, const pbvector3d& v2);

}

POLAR_BEAR_END

#endif