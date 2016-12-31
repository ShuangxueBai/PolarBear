//! Polar Bear

#ifndef POLAR_BEAR_MATH_HPP
#define POLAR_BEAR_MATH_HPP

#include "PBdefine.h"
#include "base/PBtypes.h"
#include <cmath>
#include <assert.h>

POLAR_BEAR_BEGIN


#define PB_ARRAY_COUNT(a) sizeof(a[0]) / sizeof(a)

#define PB_MIN(a, b) ((a) < (b)) ? (a) : (b)
#define PB_MAX(a, b) ((a) > (b)) ? (a) : (b)

namespace PBmath {

	template<typename T>
	class Vector2
	{
	public:
		Vector2(const T& s) : _a(s), _b(s) {}
		Vector2(const T& a, const T& b) : _a(a), _b(b) {}
		Vector2(const Vector2<T>& v) : _a(v._a), _b(v._b) {}

		Vector2<T>& operator=(const Vector2<T>& v)
		{
			if (this != &v)
			{
				_a = v._a;
				_b = v._b;
			}
			return *this;
		}

		T& x() { return _a; }
		T& y() { return _b; }

		const T& x() const { return _a; }
		const T& y() const { return _b; }

		void xy(const Vector2<T>& v)
		{
			_a = v._a;
			_b = v._b;
		}

		void xy(const T& x, const T& y)
		{
			_a = x;
			_b = y;
		}

	private:
		T _a, _b;
	};
	
	template<typename T>
	Vector2<T> operator+(const Vector2<T>& v1, const Vector2<T>& v2)
	{
		return Vector2<T>(v1.x() + v2.x(), v1.y() + v2.y());
	}

	template<typename T>
	Vector2<T> operator-(const Vector2<T>& v1, const Vector2<T>& v2)
	{
		return Vector2<T>(v1.x() - v2.x(), v1.y() - v2.y());
	}

	template<typename T>
	Vector2<T>  operator*(const Vector2<T>& v, const T& n)
	{
		return Vector2<T>(v.x() * n, v.y() * n);
	}

	template<typename T>
	Vector2<T> operator*(const T& n, const Vector2<T>& v)
	{
		return Vector2<T>(v.x() * n, v.y() * n);
	}

	template<typename T>
	Vector2<T> operator/(const Vector2<T>&  v, const T& n)
	{
		assert(n != 0);
		return Vector2<T>(v.x() / n, v.y() / n);
	}

	template<typename T>
	const T operator*(const Vector2<T>&  v1, const Vector2<T>&  v2)
	{
		return v1.x() * v2.x() + v1.y() * v2.y();
	}

	Vector2<pbfloat> normal(const Vector2<pbfloat>&  v)
	{
		assert(!(v.x() == 0.f && v.y() == 0.f));
		return v / sqrt(v * v);
	}

	Vector2<pbdouble> normal(const Vector2<pbdouble>&  v)
	{
		assert(!(v.x() == 0. && v.y() == 0.f));
		return v / sqrt(v * v);
	}


	template<typename T>
	class Vector3
	{
	public:
		Vector3(const T& s) : _a(s), _b(s), _c(s) {}
		Vector3(const T& a, const T& b, const T& c) : _a(a), _b(b), _c(c) {}
		Vector3(const Vector3<T>& v) : _a(v._a), _b(v._b), _c(v._c) {}

		Vector3<T>& operator=(const Vector3<T>& v)
		{
			if (this != &v)
			{
				_a = v._a;
				_b = v._b;
				_c = v._c
			}
			return *this;
		}

		T& x() { return _a; }
		T& y() { return _b; }
		T& z() { return _c; }

		const T& x() const { return _a; }
		const T& y() const { return _b; }
		const T& z() const { return _c; }

		T& r() { return _a; }
		T& g() { return _b; }
		T& b() { return _c; }

		const T& r() const { return _a; }
		const T& g() const { return _b; }
		const T& b() const { return _c; }


		void xyz(const Vector3<T>& v)
		{
			x() = v.x();
			y() = v.y();
			z() = v.z();
		}

		void xyz(const T& x, const T& y, const T& z)
		{
			x() = x;
			y() = y;
			z() = z;
		}

		void rgb(const Vector3<T>& v)
		{
			r() = v.r();
			g() = v.g();
			b() = v.b();
		}

		void rgb(const T& r, const T& g, const T& b)
		{
			r() = r;
			g() = g;
			b() = b;
		}

	private:
		T _a, _b, _c;
	};

	template<typename T>
	Vector3<T> operator+(const Vector3<T>& v1, const Vector3<T>& v2)
	{
		return Vector3<T>(v1.x() + v2.x(), v1.y() + v2.y(), v1.z() * v2.z());
	}

	template<typename T>
	Vector3<T> operator-(const Vector3<T>& v1, const Vector3<T>& v2)
	{
		return Vector3<T>(v1.x() - v2.x(), v1.y() - v2.y(), v1.z() - v2.z());
	}

	template<typename T>
	Vector3<T> operator*(const Vector3<T>& v, const T& n)
	{
		return Vector3<T>(v.x() * n, v.y() * n, v.z() * n);
	}

	template<typename T>
	Vector3<T> operator*(const T& n, const Vector3<T>& v)
	{
		return Vector3<T>(v.x() * n, v.y() * n, v.z() * n);
	}

	template<typename T>
	const T operator*(const Vector3<T>& v1, const Vector3<T>& v2)
	{
		return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
	}

	template<typename T>
	Vector3<T> operator/(const Vector3<T>& v, const T& n)
	{
		assert(n != 0);
		return Vector3<T>(v.x() / n, v.y() / n, v.z() / n);
	}

	template<typename T>
	const T dot(const Vector3<T>& v1, const Vector3<T>& v2)
	{
		return v1.x() * v2.x() + v1.y() * v2.y() + v1.z() * v2.z();
	}

	template<typename T>
	Vector3<T> cross(const Vector3<T>& v1, const Vector3<T>& v2)
	{
		Vector3<T> v;
		v.x() = v1.y() * v2.z() - v1.z() * v2.y();
		v.y() = v1.z() * v2.x() - v1.x() * v2.z();
		v.z() = v1.x() * v2.y() - v1.y() * v2.z();
		return v;
	}

	Vector3<pbfloat> normal(const Vector3<pbfloat>& v)
	{
		assert(!(v.x() == 0 && v.y() == 0 && v.z() == 0));
		return v / sqrt(v * v);
	}

	Vector3<pbdouble> normal(const Vector3<pbdouble>& v)
	{
		assert(!(v.x() == 0 && v.y() == 0 && v.z() == 0));
		return v / sqrt(v * v);
	}

	template<typename T>
	class Vector4
	{

	private:
		T _a, _b, _c, _d;
	};

}


POLAR_BEAR_END

#endif

