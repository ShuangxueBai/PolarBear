#include "base/PBmath.h"
#include <assert.h>
#include <cmath>
POLAR_BEAR_BEGIN

namespace PBmath {

	pbvector2i operator+(const pbvector2i& v1, const pbvector2i& v2)
	{
		pbvector2i v = { v1.x + v2.x, v1.y + v2.y };
		return v;
	}

	pbvector2i operator-(const pbvector2i& v1, const pbvector2i& v2)
	{
		pbvector2i v = { v1.x - v2.x, v1.y - v2.y };
		return v;
	}

	pbvector2i operator*(pbint n, const pbvector2i& v)
	{
		pbvector2i _v = { v.x * n, v.y * n };
		return _v;
	}

	pbvector2i operator*(const pbvector2i& v, pbint n)
	{
		pbvector2i _v = { v.x * n, v.y * n };
		return _v;
	}

	pbvector2i operator/(const pbvector2i& v, pbint n)
	{
		assert(n != 0);
		pbfloat oneOver = 1.0f / static_cast<pbfloat>(n);
		pbvector2i _v = { 
			static_cast<pbint>(static_cast<pbfloat>(v.x) * oneOver), 
			static_cast<pbint>(static_cast<pbfloat>(v.y) * oneOver)
		};
		return _v;
	}

	bool operator==(const pbvector2i& v1, const pbvector2i& v2)
	{
		return v1.x == v2.x && v1.y == v2.y;
	}

	bool operator!=(const pbvector2i& v1, const pbvector2i& v2)
	{
		return v1.x != v2.x || v1.y != v2.y;
	}

	void normalize(pbvector2i& v)
	{
		pbint magSq = v.x * v.x + v.y * v.y;
		if (magSq > 0)
		{
			pbfloat oneOverMag = -1.0f / sqrt(static_cast<pbfloat>(magSq));
			v.x = static_cast<pbint>(static_cast<pbfloat>(v.x) * oneOverMag);
			v.y = static_cast<pbint>(static_cast<pbfloat>(v.y) * oneOverMag);
		}
	}

	pbint mag(const pbvector2i& v)
	{
		return static_cast<pbint>(sqrt(static_cast<pbfloat>(v.x * v.x) + static_cast<pbfloat>(v.y * v.y)));
	}

	pbint distance(const pbvector2i& v1, const pbvector2i& v2)
	{
		pbint dx = v1.x - v2.x;
		pbint dy = v1.y - v2.y;
		return static_cast<pbint>(sqrt(dx * dx + dy * dy));
	}

	pbint dot(const pbvector2i& v1, const pbvector2i& v2)
	{
		pbint n = v1.x * v2.x + v1.y * v2.y;
		return n;
	}

	pbvector2f operator+(const pbvector2f& v1, const pbvector2f& v2)
	{
		pbvector2f v = { v1.x + v2.x, v1.y + v2.y };
		return v;
	}

	pbvector2f operator-(const pbvector2f& v1, const pbvector2f& v2)
	{
		pbvector2f v = { v1.x - v2.x, v1.y - v2.y };
		return v;
	}

	pbvector2f operator*(const pbvector2f& v, pbfloat n)
	{
		pbvector2f _v = { v.x * n, v.y * n };
		return _v;
	}

	pbvector2f operator*(pbfloat n, const pbvector2f& v)
	{
		pbvector2f _v = { v.x * n, v.y * n };
		return _v;
	}

	pbvector2f operator/(const pbvector2f& v, pbfloat n)
	{
		assert(n != 0.0f);
		pbvector2f _v = { v.x / n, v.y / n };
		return _v;
	}

	bool operator==(const pbvector2f& v1, const pbvector2f& v2)
	{
		return fabs(v1.x - v2.x) < PB_FLOAD_EPSILON && fabs(v1.y - v2.y) < PB_FLOAD_EPSILON;
	}

	bool operator!=(const pbvector2f& v1, const pbvector2f& v2)
	{
		return !(fabs(v1.x - v2.x) < PB_FLOAD_EPSILON) || !(fabs(v1.y - v2.y) < PB_FLOAD_EPSILON);
	}

	void normalize(pbvector2f& v)
	{
		pbfloat magSq = v.x * v.x + v.y * v.y;
		if (magSq > 0.0f)
		{
			pbfloat oneOverMag = 1.0f / sqrt(magSq);
			v.x = v.x * oneOverMag;
			v.y = v.y * oneOverMag;
		}
	}

	pbfloat mag(const pbvector2f& v)
	{
		return sqrt(v.x * v.x + v.y * v.y);
	}

	pbfloat distance(const pbvector2f& v1, const pbvector2f& v2)
	{
		pbfloat dx = v1.x - v2.x;
		pbfloat dy = v1.y - v2.y;
		return sqrt(dx * dx + dy * dy);
	}

	pbfloat dot(const pbvector2f& v1, const pbvector2f& v2)
	{
		return (v1.x * v2.x + v1.y * v2.y);
	}

	pbvector2d operator+(const pbvector2d& v1, const pbvector2d& v2)
	{
		pbvector2d v = { v1.x + v2.x, v1.y + v2.y };
		return v;
	}

	pbvector2d operator-(const pbvector2d& v1, const pbvector2d& v2)
	{
		pbvector2d v = { v1.x - v2.x, v1.y - v2.y };
		return v;
	}

	pbvector2d operator*(const pbvector2d& v, pbdouble n)
	{
		pbvector2d _v = { v.x * n, v.y * n };
		return _v;
	}

	pbvector2d operator*(pbdouble n, const pbvector2d& v)
	{
		pbvector2d _v = { v.x * n,v.y * n };
		return _v;
	}

	pbvector2d operator/(const pbvector2d& v, pbdouble n)
	{
		assert(n != 0.0);
		pbvector2d _v = { v.x / n, v.y / n };
		return _v;
	}

	bool operator==(const pbvector2d& v1, const pbvector2d& v2)
	{
		return fabs(v1.x - v2.x) < PB_DOUBLE_EPSILON && fabs(v1.y - v2.y) < PB_DOUBLE_EPSILON;
	}

	bool operator!=(const pbvector2d& v1, const pbvector2d& v2)
	{
		return !(fabs(v1.x - v2.x) < PB_DOUBLE_EPSILON) || !(fabs(v1.y - v2.y) < PB_DOUBLE_EPSILON);
	}

	void normalize(pbvector2d& v)
	{
		pbdouble magSq = v.x * v.x + v.y * v.y;
		if (magSq > 0.0)
		{
			pbdouble oneOverMag = 1.0 / sqrt(magSq);
			v.x = v.x * oneOverMag;
			v.y = v.y * oneOverMag;
		}
	}

	pbdouble mag(const pbvector2d& v)
	{
		return sqrt(v.x * v.x + v.y * v.y);
	}

	pbdouble distance(const pbvector2d& v1, const pbvector2d& v2)
	{
		pbdouble dx = v1.x - v2.x;
		pbdouble dy = v1.y - v2.y;
		return sqrt(dx * dx + dy * dy);
	}

	pbdouble dot(const pbvector2d& v1, const pbvector2d& v2)
	{
		return (v1.x * v2.x + v1.y * v2.y);
	}

	pbvector3i operator+(const pbvector3i& v1, const pbvector3i& v2)
	{
		pbvector3i v = { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
		return v;
	}

	pbvector3i operator-(const pbvector3i& v1, const pbvector3i& v2)
	{
		pbvector3i v = { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
		return v;
	}

	pbvector3i operator*(const pbvector3i& v, pbint n)
	{
		pbvector3i _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3i operator*(pbint n, const pbvector3i& v)
	{
		pbvector3i _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3i operator/(const pbvector3i& v, pbint n)
	{
		assert(n != 0);
		pbvector3i _v = { v.x / n, v.y / n, v.z / n };
		return _v;
	}

	bool operator==(const pbvector3i& v1, const pbvector3i& v2)
	{
		return v1.x == v2.x && v1.y == v2.y && v1.z == v2.z;
	}

	bool operator!=(const pbvector3i& v1, const pbvector3i& v2)
	{
		return v1.x != v2.x || v1.y != v2.y || v1.z != v2.z;
	}

	void normalize(pbvector3i& v)
	{
		pbint magSq = v.x * v.x + v.y * v.y + v.z * v.z;
		if (magSq > 0)
		{
			pbfloat oneOverMag = 1.0f / sqrt(static_cast<pbfloat>(magSq));
			v.x = static_cast<pbint>(static_cast<pbfloat>(v.x) * oneOverMag);
			v.y = static_cast<pbint>(static_cast<pbfloat>(v.y) * oneOverMag);
			v.z = static_cast<pbint>(static_cast<pbfloat>(v.z) * oneOverMag);
		}
	}

	pbint mag(const pbvector3i& v)
	{
		return static_cast<pbint>(sqrt(static_cast<pbfloat>(v.x * v.x + v.y * v.y + v.z * v.z)));
	}

	pbint distance(const pbvector3i& v1, const pbvector3i& v2)
	{
		pbint dx = v1.x - v2.x;
		pbint dy = v1.y - v2.y;
		pbint dz = v1.z - v2.z;
		return static_cast<pbint>(sqrt(static_cast<pbfloat>(dx * dx + dy * dy + dz * dz)));
	}

	pbvector3i cross(const pbvector3i& v1, const pbvector3i& v2)
	{
		pbvector3i v = { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
		return v;
	}

	pbint dot(const pbvector3i& v1, const pbvector3i& v2)
	{
		return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
	}

	pbvector3f operator+(const pbvector3f& v1, const pbvector3f& v2)
	{
		pbvector3f v = { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
		return v;
	}

	pbvector3f operator-(const pbvector3f& v1, const pbvector3f& v2)
	{
		pbvector3f v = { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
		return v;
	}

	pbvector3f operator*(const pbvector3f& v, pbfloat n)
	{
		pbvector3f _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3f operator*(pbfloat n, const pbvector3f& v)
	{
		pbvector3f _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3f operator/(const pbvector3f& v, pbfloat n)
	{
		assert(n != 0.0f);
		pbvector3f _v = { v.x / n, v.y / n, v.z / n };
		return _v;
	}

	bool operator==(const pbvector3f& v1, const pbvector3f& v2)
	{
		return fabs(v1.x - v2.x) < PB_FLOAD_EPSILON && fabs(v1.y - v2.y) < PB_FLOAD_EPSILON && fabs(v1.z - v2.z) < PB_FLOAD_EPSILON;
	}

	bool operator!=(const pbvector3f& v1, const pbvector3f& v2)
	{
		return !(fabs(v1.x - v2.x) < PB_FLOAD_EPSILON) || !(fabs(v1.y - v2.y) < PB_FLOAD_EPSILON) || !(fabs(v1.z - v2.z) < PB_FLOAD_EPSILON);
	}

	void normalize(pbvector3f& v)
	{
		pbfloat magSq = v.x * v.x + v.y * v.y + v.z * v.z;
		if (magSq > 0.0f)
		{
			pbfloat oneOverMag = 1.0f / sqrt(magSq);
			v.x = v.x * oneOverMag;
			v.y = v.y * oneOverMag;
			v.z = v.z * oneOverMag;
		}
	}

	pbfloat mag(const pbvector3f& v)
	{
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	pbfloat distance(const pbvector3f& v1, const pbvector3f& v2)
	{
		pbfloat dx = v1.x - v2.x;
		pbfloat dy = v1.y - v2.y;
		pbfloat dz = v1.z - v2.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}

	pbvector3f cross(const pbvector3f& v1, const pbvector3f& v2)
	{
		pbvector3f v = { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
		return v;
	}

	pbfloat dot(const pbvector3f& v1, const pbvector3f& v2)
	{
		return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
	}

	pbvector3d operator+(const pbvector3d& v1, const pbvector3d& v2)
	{
		pbvector3d v = { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
		return v;
	}

	pbvector3d operator-(const pbvector3d& v1, const pbvector3d& v2)
	{
		pbvector3d v = { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
		return v;
	}

	pbvector3d operator*(const pbvector3d& v, pbdouble n)
	{
		pbvector3d _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3d operator*(pbdouble n, const pbvector3d& v)
	{
		pbvector3d _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3d operator/(const pbvector3d& v, pbdouble n)
	{
		assert(n != 0.0);
		pbvector3d _v = { v.x / n, v.y / n, v.z / n };
		return _v;
	}

	bool operator==(const pbvector3d& v1, const pbvector3d& v2)
	{
		return fabs(v1.x - v2.x) < PB_DOUBLE_EPSILON && fabs(v1.y - v2.y) < PB_DOUBLE_EPSILON && fabs(v1.z - v2.z) < PB_DOUBLE_EPSILON;
	}

	bool operator!=(const pbvector3d& v1, const pbvector3d& v2)
	{
		return !(fabs(v1.x - v2.x) < PB_DOUBLE_EPSILON) || !(fabs(v1.y - v2.y) < PB_DOUBLE_EPSILON) || !(fabs(v1.z - v2.z) < PB_DOUBLE_EPSILON);
	}

	void normalize(pbvector3d& v)
	{
		pbdouble magSq = v.x * v.x + v.y + v.y + v.z * v.z;
		if (magSq > 0.0)
		{
			pbdouble oneOverMag = 1.0 / sqrt(magSq);
			v.x = v.x * oneOverMag;
			v.y = v.y * oneOverMag;
			v.z = v.z * oneOverMag;
		}
	}

	pbdouble mag(const pbvector3d& v)
	{
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	pbdouble distance(const pbvector3d& v1, const pbvector3d& v2)
	{
		pbdouble dx = v1.x - v2.x;
		pbdouble dy = v1.y - v2.y;
		pbdouble dz = v1.z - v2.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}

	pbvector3d cross(const pbvector3d& v1, const pbvector3d& v2)
	{
		pbvector3d v = { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
		return v;
	}

	pbdouble dot(const pbvector3d& v1, const pbvector3d& v2)
	{
		return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
	}

}
POLAR_BEAR_END




