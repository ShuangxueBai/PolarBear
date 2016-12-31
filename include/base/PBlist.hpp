//!Polar Bear
#ifndef POLAR_BEAR_LIST_H
#define POLAR_BEAR_LIST_H
#include <assert.h>
#include "base/_baseExport.h"
#include "PBdefine.h"

POLAR_BEAR_BEGIN

template<typename T>
struct _listNode
{
	T _value;
	_listNode* _next = nullptr;
};

template<typename T>
class _pbList
{
public:

	void push(const size_t& index, const T& value)
	{
		assert(_count > 0 && index < _count);
		_listNode<T>* p = _head;
		for (size_t i = 0; i < index; ++i)
		{
			p = p->_next;
		}//end for

		_listNode<T>* n = new _listNode<T>;
		n->_value = value;
		
		n->_next = p->_next;
		p->_next = n;
		
		if (p == _tail)
			_tail = n;
		return;
	}

	void push_front(const T& value)
	{
		_listNode* node = new _listNode;
		node->_value = value;
		if (nullptr == _head)
		{
			_head = node;
			_tail = node;
		}
		else
		{
			node->_next = _head;
			_head = node;
		}
		++_count;
	}

	void push_back(const T& value)
	{
		_listNode* node = new _listNode;
		node->_value = value;
		if (nullptr == _tail)
		{
			_head = node;
			_tail = node;
		}
		else
		{
			_tail->_next = node;
			_tail = node;
		}
		++_count;
	}

	T pop(const size_t& index)
	{
		assert(0 != _count && index < _count);
		_listNode<T>* p = _head;
		_listNode<T>* f = p;
		size_t i = 0;
		
		while (p)
		{
			if (index == i)
				break;
			++i;
			f = p;
			p = p->_next;
		}//end while
		
		if (p == _head)
			return pop_front();
		
		if (p == _tail)
			return pop_back();
		
		f->_next = p->_next;
		p->_next = nullptr;
		T v = p->_value;
		delete p;
		--_count;
		return v;
	}

	T pop_front()
	{
		assert(_count > 0);
		_listNode<T> *p = _head;
		if (_count == 1)
		{
			_tail = nullptr;
		}
		_head = _head->_next;
		p->_next = nullptr;
		T v = p->_value;
		delete p;
		--_count;
		return v;
	}

	T pop_back()
	{
		assert(_count > 0);
		if (_count == 1)
		{
			_head = nullptr;
		}

		_listNode<T> *p = _head;
		while (p->_next != _tail)
		{
			p = p->_next;
		}// end while

		T v = _tail->_value;
		p->_next = nullptr;
		delete _tail;
		_tail = p;
		--_count;
		return v;
	}

	const size_t count() const { return _count; }

	void clear()
	{
		for (size_t i = 0; i < _count; ++i )
		{
			_listNode<T>* t = _head;
			_head = _head->_next;
			delete t;
		}//end for
	}

private:
	size_t _count = 0;
	_listNode<T>* _head = nullptr;
	_listNode<T>* _tail = nullptr;
};


template<typename T>
struct _dbListNode
{
	T _value;
	_dbListNode* _prev = nullptr;
	_dbListNode* _next = nullptr;
};

template<typename T>
class PBdbList
{
public:
	
	void push(const size_t& index, const T& value)
	{
		assert(_count > 0 && index < _count);
		_dbListNode<T>* p = _head;
		for (size_t i = 0; i < index; ++i)
		{
			p = p->_next;
		}//end for

		_dbListNode<T>* n = new _dbListNode<T>;
		n->_value = value;

		n->_next = p->_next;
		p->_next = n;
		n->_prev = p;

		if (n->_next != nullptr)
		{
			n->_next->_prev = n;
		}

		if (p == _tail)
			_tail = n;
		return;
	}

	void push_front(const T& value)
	{
		_dbListNode* node = new _dbListNode;
		node->_value = value;
		if (nullptr == _head)
		{
			_head = node;
			_tail = node;
		}
		else
		{
			node->_next = _head;
			_head->_prev = node;
			_head = node;
		}
	}

	void push_back(const T& value)
	{
		_dbListNode* node = new _dbListNode;
		node->_value = value;
		if (nullptr == _tail)
		{
			_head = node;
			_tail = node;
		}
		else
		{
			node->_prev = _tail;
			_tail->_next = node;
			_tail = node;
		}
	}

	T pop(const size_t& index)
	{
		assert(0 != _count && index < _count);
		_dbListNode<T>* p = _head;
		size_t i = 0;
		while (p)
		{
			if(i == index)
				break;
			++i;
		}//end while

		if (p == _head)
			return pop_front();

		if (p == _tail)
			return pop_back();

		_dbListNode<T>* f = p->_prev;
		_dbListNode<T>* n = p->_next;

		f->_next = n;
		n->_prev = f;

		p->_prev = nullptr;
		p->_next = nullptr;
		
		T v = p->_value;
		--_count;
		delete p;
		return v;
	}

	T pop_front()
	{
		assert(_count > 0);
		_dbListNode<T>* p = _head;

		_head = _head->_next;
		if (nullptr != _head)
		{
			_head->_prev = nullptr;
		}
		else
		{
			_tail = nullptr;
		}

		--_count;
		T v = p->_value;
		delete p;
		return v;
	}
	
	T pop_back()
	{
		assert(_count > 0);
		_dbListNode<T>* p = _tail;

		_tail = _tail->_prev;
		if (nullptr != _tail)
		{
			_tail->_next = nullptr;
		}
		else
		{
			_head = nullptr;
		}

		--_count;
		T v = p->_value;
		delete p;
		return v;
	}

	T& atRef(const size_t& index)
	{
		assert(0 != _count && index < _count);
		_dbListNode<T>* p = _head;
		size_t i = 0;
		while (i != index)
		{
			p = p->_next;
			++i;
		}//end while
		return p->_value;
	}

	T at(const size_t& index) const
	{
		T& r = atRef(index);
		return r;
	}

	const size_t count() const { return _count; }

	void clear()
	{
		for (size_t i = 0; i < _count; ++i)
		{
			_dbListNode<T>* t = _head;
			_head = _head->_next;
			delete t;
		}//end for
	}

private:
	size_t _count = 0;
	_dbListNode<T>* _head = nullptr;
	_dbListNode<T>* _tail = nullptr;
};

POLAR_BEAR_END
#endif