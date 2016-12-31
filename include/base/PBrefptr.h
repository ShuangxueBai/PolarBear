#ifndef POLAR_BEAR_REF_PTR_H
#define POLAR_BEAR_REF_PTR_H

#include <type_traits>
#include "base/PBref.h"

POLAR_BEAR_BEGIN

#define PB_REF_PTR_SAFE_RETAIN(ptr) \
	do{ \
	 if(ptr){\
	   const_cast<PBref*>(static_cast<const PBref*>(ptr))->retain(); \
	 	 	 } \
			} while (0)\

#define PB_REF_PTR_SAFE_RELEASE(ptr)\
	do{ \
	   if(ptr){\
	   const_cast<PBref*>(static_cast<const PBref*>(ptr))->release(); \
	   	   	   	   	   }\
					}while(0)\

#define PB_REF_PTR_SAFE_RELEASE_NULL(ptr)\
	do{\
	 if(ptr){\
	 const_cast<PBref*>(static_cast<const PBref*>(ptr))->release(); \
	 ptr = nullptr;\
	 	 	 }\
			}while(0)\



template<typename T>
class PBrefPtr
{
public:
	inline PBrefPtr() :_pRef(nullptr){}
	inline PBrefPtr(PBrefPtr<T> && other)
	{
		_pRef = other._pRef;
		other._pRef = nullptr;
	}

	inline PBrefPtr(T* ptr)
		:_pRef(const_cast<typename std::remove_const<T>::type*>(ptr))
	{
		PB_REF_PTR_SAFE_RETAIN(_pRef);
	}

	inline PBrefPtr(std::nullptr_t ptr) : _pRef(nullptr)
	{

	}

	inline PBrefPtr(const PBrefPtr<T> & other) : _pRef(other._pRef)
	{
		PB_REF_PTR_SAFE_RETAIN(_pRef);
	}

	inline ~PBrefPtr()
	{
		PB_REF_PTR_SAFE_RELEASE_NULL(_pRef);
	}

	inline void reset() { PB_REF_PTR_SAFE_RELEASE_NULL(_pRef); }

	inline void swap(PBrefPtr<T>& other)
	{
		if (this != &other)
		{
			PBref* pTmp = _pRef;
			_pRef = other._pRef;
			other._pRef = pTmp;
		}
	}


	inline PBrefPtr<T> & operator=(const PBrefPtr<T>& other)
	{
		if (other._pRef != _pRef)
		{
			PB_REF_PTR_SAFE_RETAIN(other._pRef);
			PB_REF_PTR_SAFE_RELEASE(_pRef);
			_pRef = other._pRef;
		}
		return *this;
	}

	inline PBrefPtr<T> & operator=(PBrefPtr<T> && other)
	{
		if (&other != this)
		{
			PB_REF_PTR_SAFE_RELEASE(_pRef);
			_pRef = other._pRef;
			other._pRef = nullptr;
		}
		return *this;
	}

	inline PBrefPtr<T> & operator=(T* other)
	{
		if (other != this)
		{
			PB_REF_PTR_SAFE_RETAIN(other);
			PB_REF_PTR_SAFE_RELEASE(_pRef);
			_pRef = const_cast<typename std::remove_const<T>::type*>(other);
		}
		return *this;
	}

	inline PBrefPtr<T> & operator=(std::nullptr_t other)
	{
		PB_REF_PTR_SAFE_RELEASE_NULL(_pRef);
		return *this;
	}

	inline T* refPtr() { return reinterpret_cast<T*>(_pRef); }

	inline operator T*() const { return reinterpret_cast<T*>(_pRef); }

	inline operator bool() const { return _pRef != nullptr;  }

	inline T& operator * () const 
	{
		//assert _pRef is not null.
		return reinterpret_cast<T&>(*_pRef);
	}
	inline T* operator -> () const
	{
		//assert _pRef is not null
		return reinterpret_cast<T*>(_pRef);
	}

	inline bool operator == (const PBrefPtr<T>& other)
	{
		return _pRef == other._pRef;
	}

	inline bool operator == (const T* otherptr)
	{
		return _pRef == otherptr;
	}

	inline bool operator == (typename std::remove_const<T>::type* otherptr)
	{
		return _pRef == otherptr;
	}

	inline bool operator == (const std::nullptr_t nullRefptr)
	{
		return _pRef == nullRefptr;
	}

	inline bool operator != (const PBrefPtr<T>& other)
	{
		return _pRef != other._pRef;
	}

	inline bool operator != (const T* otherptr)
	{
		return _pRef != otherptr;
	}

	inline bool operator != (typename std::remove_const<T>::type* otherptr)
	{
		return _pRef != otherptr;
	}

	inline bool operator != (std::nullptr_t nullRefptr)
	{
		return _pRef == nullRefptr;
	}

	inline bool operator > (const PBrefPtr<T>& other)
	{
		return _pRef > other._pRef;
	}

	inline bool operator > (const T* otherptr)
	{
		return _pRef > otherptr;
	}

	inline bool operator > (typename std::remove_const<T>::type* otherptr)
	{
		return _pRef > otherptr;
	}

	inline bool operator > (std::nullptr_t nullRefptr)
	{
		return _pRef > nullRefptr;
	}

	inline bool operator < (const PBrefPtr<T>& other)
	{
		return _pRef < other._pRef;
	}

	inline bool operator < (const T* otherptr)
	{
		return _pRef < otherptr;
	}

	inline bool operator < (std::nullptr_t nullRefptr)
	{
		return _pRef < nullRefptr;
	}

	inline bool operator <= (const PBrefPtr<T>& other)
	{
		return _pRef <= other._pRef;
	}

	inline bool operator <= (const T* otherptr)
	{
		return _pRef <= otherptr;
	}

	inline bool operator <= (typename std::remove_const<T>::type* otherptr)
	{
		return _pRef <= otherptr;
	}

	inline bool operator <= (std::nullptr_t nullRefptr)
	{
		return _pRef <= nullRefptr;
	}

	inline bool operator >= (const PBrefPtr<T>& other)
	{
		return _pRef >= other._pRef;
	}

	inline bool operator >= (const T* otherptr)
	{
		return _pRef >= otherptr;
	}

	inline bool operator >= (typename std::remove_const<T>::type* otherptr)
	{
		return _pRef >= otherptr;
	}

	inline bool operator >= (std::nullptr_t nullRefptr)
	{
		return _pRef >= nullRefptr;
	}

private:
	PBref* _pRef;
};

POLAR_BEAR_END

#endif