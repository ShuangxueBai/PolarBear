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
		int x;
		int y;
	};

	struct pbvector2f
	{
		float x;
		float y;
	};

	struct pbvector2d
	{
		double x;
		double y;
	};

	struct pbvector3i
	{
		int x;
		int y;
		int z;
	};

	struct pbvector3f
	{
		float x;
		float y;
		float z;
	};

	struct pbvector3d
	{
		double x;
		double y;
		double z;
	};

	BASE_EXT inline pbvector2i operator+(const pbvector2i& v1, const pbvector2i& v2);
	BASE_EXT inline pbvector2i operator-(const pbvector2i& v1, const pbvector2i& v2);
	BASE_EXT inline pbvector2i operator*(int n, const pbvector2i& v);
	BASE_EXT inline pbvector2i operator*(const pbvector2i& v, int n);
	BASE_EXT inline pbvector2i operator/(const pbvector2i& v, int n);
	BASE_EXT inline bool operator==(const pbvector2i& v1, const pbvector2i& v2);
	BASE_EXT inline bool operator!=(const pbvector2i& v1, const pbvector2i& v2);
	BASE_EXT inline void normalize(pbvector2i& v);
	BASE_EXT inline int mag(const pbvector2i& v);
	BASE_EXT inline int distance(const pbvector2i& v1, const pbvector2i& v2);
	BASE_EXT inline int dot(const pbvector2i& v1, const pbvector2i& v2);

	BASE_EXT inline pbvector2f operator+(const pbvector2f& v1, const pbvector2f& v2);
	BASE_EXT inline pbvector2f operator-(const pbvector2f& v1, const pbvector2f& v2);
	BASE_EXT inline pbvector2f operator*(const pbvector2f& v, float n);
	BASE_EXT inline pbvector2f operator*(float n, const pbvector2f& v);
	BASE_EXT inline pbvector2f operator/(const pbvector2f& v, float n);
	BASE_EXT inline bool operator==(const pbvector2f& v1, const pbvector2f& v2);
	BASE_EXT inline bool operator!=(const pbvector2f& v1, const pbvector2f& v2);
	BASE_EXT inline void normalize(pbvector2f& v);
	BASE_EXT inline float mag(const pbvector2f& v);
	BASE_EXT inline float distance(const pbvector2f& v1, const pbvector2f& v2);
	BASE_EXT inline float dot(const pbvector2f& v1, const pbvector2f& v2);

	BASE_EXT inline pbvector2d operator+(const pbvector2d& v1, const pbvector2d& v2);
	BASE_EXT inline pbvector2d operator-(const pbvector2d& v1, const pbvector2d& v2);
	BASE_EXT inline pbvector2d operator*(const pbvector2d& v, double n);
	BASE_EXT inline pbvector2d operator*(double n, const pbvector2d& v);
	BASE_EXT inline pbvector2d operator/(const pbvector2d& v, double n);
	BASE_EXT inline bool operator==(const pbvector2d& v1, const pbvector2d& v2);
	BASE_EXT inline bool operator!=(const pbvector2d& v1, const pbvector2d& v2);
	BASE_EXT inline void normalize(pbvector2d& v);
	BASE_EXT inline double mag(const pbvector2d& v);
	BASE_EXT inline double distance(const pbvector2d& v1, const pbvector2d& v2);
	BASE_EXT inline double dot(const pbvector2d& v1, const pbvector2d& v2);

	BASE_EXT inline pbvector3i operator+(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline pbvector3i operator-(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline pbvector3i operator*(const pbvector3i& v, int n);
	BASE_EXT inline pbvector3i operator*(int n, const pbvector3i& v);
	BASE_EXT inline pbvector3i operator/(const pbvector3i& v, int n);
	BASE_EXT inline bool operator==(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline bool operator!=(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline void normalize(pbvector3i& v);
	BASE_EXT inline int mag(const pbvector3i& v);
	BASE_EXT inline int distance(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline pbvector3i cross(const pbvector3i& v1, const pbvector3i& v2);
	BASE_EXT inline int dot(const pbvector3i& v1, const pbvector3i& v2);

	BASE_EXT inline pbvector3f operator+(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline pbvector3f operator-(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline pbvector3f operator*(const pbvector3f& v, float n);
	BASE_EXT inline pbvector3f operator*(float n, const pbvector3f& v);
	BASE_EXT inline pbvector3f operator/(const pbvector3f& v, float n);
	BASE_EXT inline bool operator==(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline bool operator!=(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline void normalize(pbvector3f& v);
	BASE_EXT inline float mag(const pbvector3f& v);
	BASE_EXT inline float distance(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline pbvector3f cross(const pbvector3f& v1, const pbvector3f& v2);
	BASE_EXT inline float dot(const pbvector3f& v1, const pbvector3f& v2);

	BASE_EXT inline pbvector3d operator+(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline pbvector3d operator-(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline pbvector3d operator*(const pbvector3d& v, double n);
	BASE_EXT inline pbvector3d operator*(double n, const pbvector3d& v);
	BASE_EXT inline pbvector3d operator/(const pbvector3d& v, double n);
	BASE_EXT inline bool operator==(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline bool operator!=(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline void normalize(pbvector3d& v);
	BASE_EXT inline double mag(const pbvector3d& v);
	BASE_EXT inline double distance(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline pbvector3d cross(const pbvector3d& v1, const pbvector3d& v2);
	BASE_EXT inline double dot(const pbvector3d& v1, const pbvector3d& v2);

}

POLAR_BEAR_END

#endif