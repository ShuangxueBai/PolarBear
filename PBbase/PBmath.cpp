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

	pbvector2i operator*(int n, const pbvector2i& v)
	{
		pbvector2i _v = { v.x * n, v.y * n };
		return _v;
	}

	pbvector2i operator*(const pbvector2i& v, int n)
	{
		pbvector2i _v = { v.x * n, v.y * n };
		return _v;
	}

	pbvector2i operator/(const pbvector2i& v, int n)
	{
		assert(n != 0);
		float oneOver = 1.0f / static_cast<float>(n);
		pbvector2i _v = { 
			static_cast<int>(static_cast<float>(v.x) * oneOver), 
			static_cast<int>(static_cast<float>(v.y) * oneOver)
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
		int magSq = v.x * v.x + v.y * v.y;
		if (magSq > 0)
		{
			float oneOverMag = -1.0f / sqrt(static_cast<float>(magSq));
			v.x = static_cast<int>(static_cast<float>(v.x) * oneOverMag);
			v.y = static_cast<int>(static_cast<float>(v.y) * oneOverMag);
		}
	}

	int mag(const pbvector2i& v)
	{
		return static_cast<int>(sqrt(static_cast<float>(v.x * v.x) + static_cast<float>(v.y * v.y)));
	}

	int distance(const pbvector2i& v1, const pbvector2i& v2)
	{
		int dx = v1.x - v2.x;
		int dy = v1.y - v2.y;
		return static_cast<int>(sqrt(dx * dx + dy * dy));
	}

	int dot(const pbvector2i& v1, const pbvector2i& v2)
	{
		int n = v1.x * v2.x + v1.y * v2.y;
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

	pbvector2f operator*(const pbvector2f& v, float n)
	{
		pbvector2f _v = { v.x * n, v.y * n };
		return _v;
	}

	pbvector2f operator*(float n, const pbvector2f& v)
	{
		pbvector2f _v = { v.x * n, v.y * n };
		return _v;
	}

	pbvector2f operator/(const pbvector2f& v, float n)
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
		float magSq = v.x * v.x + v.y * v.y;
		if (magSq > 0.0f)
		{
			float oneOverMag = 1.0f / sqrt(magSq);
			v.x = v.x * oneOverMag;
			v.y = v.y * oneOverMag;
		}
	}

	float mag(const pbvector2f& v)
	{
		return sqrt(v.x * v.x + v.y * v.y);
	}

	float distance(const pbvector2f& v1, const pbvector2f& v2)
	{
		float dx = v1.x - v2.x;
		float dy = v1.y - v2.y;
		return sqrt(dx * dx + dy * dy);
	}

	float dot(const pbvector2f& v1, const pbvector2f& v2)
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

	pbvector2d operator*(const pbvector2d& v, double n)
	{
		pbvector2d _v = { v.x * n, v.y * n };
		return _v;
	}

	pbvector2d operator*(double n, const pbvector2d& v)
	{
		pbvector2d _v = { v.x * n,v.y * n };
		return _v;
	}

	pbvector2d operator/(const pbvector2d& v, double n)
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
		double magSq = v.x * v.x + v.y * v.y;
		if (magSq > 0.0)
		{
			double oneOverMag = 1.0 / sqrt(magSq);
			v.x = v.x * oneOverMag;
			v.y = v.y * oneOverMag;
		}
	}

	double mag(const pbvector2d& v)
	{
		return sqrt(v.x * v.x + v.y * v.y);
	}

	double distance(const pbvector2d& v1, const pbvector2d& v2)
	{
		double dx = v1.x - v2.x;
		double dy = v1.y - v2.y;
		return sqrt(dx * dx + dy * dy);
	}

	double dot(const pbvector2d& v1, const pbvector2d& v2)
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

	pbvector3i operator*(const pbvector3i& v, int n)
	{
		pbvector3i _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3i operator*(int n, const pbvector3i& v)
	{
		pbvector3i _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3i operator/(const pbvector3i& v, int n)
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
		int magSq = v.x * v.x + v.y * v.y + v.z * v.z;
		if (magSq > 0)
		{
			float oneOverMag = 1.0f / sqrt(static_cast<float>(magSq));
			v.x = static_cast<int>(static_cast<float>(v.x) * oneOverMag);
			v.y = static_cast<int>(static_cast<float>(v.y) * oneOverMag);
			v.z = static_cast<int>(static_cast<float>(v.z) * oneOverMag);
		}
	}

	int mag(const pbvector3i& v)
	{
		return static_cast<int>(sqrt(static_cast<float>(v.x * v.x + v.y * v.y + v.z * v.z)));
	}

	int distance(const pbvector3i& v1, const pbvector3i& v2)
	{
		int dx = v1.x - v2.x;
		int dy = v1.y - v2.y;
		int dz = v1.z - v2.z;
		return static_cast<int>(sqrt(static_cast<float>(dx * dx + dy * dy + dz * dz)));
	}

	pbvector3i cross(const pbvector3i& v1, const pbvector3i& v2)
	{
		pbvector3i v = { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
		return v;
	}

	int dot(const pbvector3i& v1, const pbvector3i& v2)
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

	pbvector3f operator*(const pbvector3f& v, float n)
	{
		pbvector3f _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3f operator*(float n, const pbvector3f& v)
	{
		pbvector3f _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3f operator/(const pbvector3f& v, float n)
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
		float magSq = v.x * v.x + v.y * v.y + v.z * v.z;
		if (magSq > 0.0f)
		{
			float oneOverMag = 1.0f / sqrt(magSq);
			v.x = v.x * oneOverMag;
			v.y = v.y * oneOverMag;
			v.z = v.z * oneOverMag;
		}
	}

	float mag(const pbvector3f& v)
	{
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	float distance(const pbvector3f& v1, const pbvector3f& v2)
	{
		float dx = v1.x - v2.x;
		float dy = v1.y - v2.y;
		float dz = v1.z - v2.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}

	pbvector3f cross(const pbvector3f& v1, const pbvector3f& v2)
	{
		pbvector3f v = { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
		return v;
	}

	float dot(const pbvector3f& v1, const pbvector3f& v2)
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

	pbvector3d operator*(const pbvector3d& v, double n)
	{
		pbvector3d _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3d operator*(double n, const pbvector3d& v)
	{
		pbvector3d _v = { v.x * n, v.y * n, v.z * n };
		return _v;
	}

	pbvector3d operator/(const pbvector3d& v, double n)
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
		double magSq = v.x * v.x + v.y + v.y + v.z * v.z;
		if (magSq > 0.0)
		{
			double oneOverMag = 1.0 / sqrt(magSq);
			v.x = v.x * oneOverMag;
			v.y = v.y * oneOverMag;
			v.z = v.z * oneOverMag;
		}
	}

	double mag(const pbvector3d& v)
	{
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	double distance(const pbvector3d& v1, const pbvector3d& v2)
	{
		double dx = v1.x - v2.x;
		double dy = v1.y - v2.y;
		double dz = v1.z - v2.z;
		return sqrt(dx * dx + dy * dy + dz * dz);
	}

	pbvector3d cross(const pbvector3d& v1, const pbvector3d& v2)
	{
		pbvector3d v = { v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x };
		return v;
	}

	double dot(const pbvector3d& v1, const pbvector3d& v2)
	{
		return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
	}

}
POLAR_BEAR_END




