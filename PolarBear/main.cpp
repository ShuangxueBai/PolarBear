
#if 0
#include <iostream>
using namespace std;

int main(int argc, char** argv)
{
	cout << "Hello Polar Bear!" << endl;
	cout << "......" << endl;
	cin.clear();
	cin.sync();
	cin.get();
	return 0;
}

#endif

#if 0 //Learn C++ 11 Thread libs.

#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <vector>
#include <assert.h>
using namespace std;


std::atomic<bool> x, y;
std::atomic<int> z;

void write_x()
{
	x.store(true, std::memory_order_seq_cst);
}

void write_y()
{
	y.store(true, std::memory_order_seq_cst);
}

void read_x_then_y()
{
	while (!x.load(std::memory_order_seq_cst));
	if (y.load(std::memory_order_seq_cst))
		++z;
}

void read_y_then_x()
{
	while (!y.load(std::memory_order_seq_cst));
	if (x.load(std::memory_order_seq_cst))
		++z;
}

int main()
{
	x = false;
	y = false;
	z = 0;
	std::thread a(write_x);
	std::thread b(write_y);
	std::thread c(read_x_then_y);
	std::thread d(read_y_then_x);
	a.join();
	b.join();
	c.join();
	d.join();
	assert(z.load(std::memory_order_seq_cst) != 0);
	cout << "Enter any keys..." << endl;
	cin.clear();
	cin.get();
	cin.sync();
	return 0;
}


#endif

#if 0
#include <atomic>
#include <thread>
#include <assert.h>
#include <iostream>

std::atomic<bool> x, y;
std::atomic<int> z;

void write_x_then_y()
{
	x.store(true, std::memory_order_relaxed);
	y.store(true, std::memory_order_relaxed);
}

void read_y_then_x()
{
	while (!y.load(std::memory_order_relaxed));
	if (x.load(std::memory_order_relaxed))
		++z;
}

int main()
{
	x = false;
	y = false;
	z = 0;
	std::thread a(write_x_then_y);
	std::thread b(read_y_then_x);
	a.join();
	b.join();
	assert(z.load() != 0);

	std::cout << "Enter any keys...." << std::endl;
	std::cin.clear();
	std::cin.get();
	std::cin.sync();
	return 0;
}

#endif


#if 0
#include <thread>
#include <atomic>
#include <iostream>

std::atomic<int> x(0), y(0), z(0);
std::atomic<bool> go(false);

const unsigned int loop_count = 10;

struct read_values 
{
	int x, y, z;
};

read_values values1[loop_count];
read_values values2[loop_count];
read_values values3[loop_count];
read_values values4[loop_count];
read_values values5[loop_count];

void increment(std::atomic<int>* var_to_inc, read_values* values)
{
	while (!go)
		std::this_thread::yield();
	for (unsigned int i = 0; i < loop_count; ++i)
	{
		values[i].x = x.load(std::memory_order_relaxed);
		values[i].y = y.load(std::memory_order_relaxed);
		values[i].z = z.load(std::memory_order_relaxed);
		var_to_inc->store(i + 1, std::memory_order_relaxed);
		std::this_thread::yield();
	}
}

void read_vals(read_values* values)
{
	while (!go)
		std::this_thread::yield();
	for (unsigned int i = 0; i < loop_count; ++i)
	{
		values[i].x = x.load(std::memory_order_relaxed);
		values[i].y = y.load(std::memory_order_relaxed);
		values[i].z = z.load(std::memory_order_relaxed);
		std::this_thread::yield();
	}
}

void print(read_values* v)
{
	for (unsigned int i = 0; i < loop_count; ++i)
	{
		if (i)
			std::cout << ",";
		std::cout << "(" << v[i].x << "," << v[i].y << "," << v[i].z << ")";
	}
	std::cout << std::endl;
}

int main()
{
	std::thread t1(increment, &x, values1);
	std::thread t2(increment, &y, values2);
	std::thread t3(increment, &z, values3);
	std::thread t4(read_vals, values4);
	std::thread t5(read_vals, values5);

	go = true;

	t5.join();
	t4.join();
	t3.join();
	t2.join();
	t1.join();

	print(values1);
	print(values2);
	print(values3);
	print(values4);
	print(values5);

	std::cout << "Enter any keys..." << std::endl;
	std::cin.clear();
	std::cin.get();
	std::cin.sync();
	return 0;
}







#endif

#if 0

#include <atomic>
#include <thread>
#include <mutex>
#include <iostream>
#include <exception>
#include <stack>

using namespace std;

struct empty_stack : std::exception
{
	const char* what() const throw();
};

template<typename T>
class threadsafe_stack
{
private:
	std::stack<T> _data;
	mutable std::mutex m;
public:
	threadsafe_stack() {}
	threadsafe_stack(const threadsafe_stack& other)
	{
		std::lock_guard<std::mutex> lock(other.m);
		_data = other._data;
	}

	void push(T new_value)
	{
		std::lock_guard<std::mutex> lock(m);
		_data.push(std::move(new_value));
	}

	std::shared_ptr<T> pop()
	{
		std::lock_guard<std::mutex> lock(m);
		if (_data.empty()) throw empty_stack();
		std::shared_ptr<T> const res(std::make_shared<T>(std::move(_data.top())));
		_data.pop();
		return res;
	}

	void pop(T& value)
	{
		std::lock_guard<std::mutex> lock(m);
		if (_data.empty()) throw empty_stack();
		value = std::move(_data->top());
		_data.pop();
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lock(m);
		return _data.empty();
	}

};

#endif

#if 0
#include <iostream>
#include <thread>;
#include <mutex>
#include <condition_variable>
#include <queue>

using namespace std;

template<typename T>
class threadsafe_queue
{
private:
	mutable std::mutex mut;
	queue<std::shared_ptr<T> > data_queue;
	condition_variable data_cond;

public:
	threadsafe_queue()
	{}

	void wait_and_pop(T& value)
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk, [this] {return !data_queue.empty(); });
		value = std::move(*data_queue.front());
		data_queue.pop();
	}

	bool try_pop(T& value)
	{
		std::lock_guard<mutex> lk(mut);
		if (data_queue.empty())
			return false;
		value = std::move(data_queue.front());
		data_queue.pop();
		return true;
	}

	std::shared_ptr<T> wait_and_pop()
	{
		std::unique_lock<std::mutex> lk(mut);
		data_cond.wait(lk, [this] {return !data_queue.empty(); });
		std::shared_ptr<T> res = data_queue.front();
		data_queue.pop();
		return res;
	}

	std::shared_ptr<T> try_pop()
	{
		std::lock_guard<std::mutex> lk(mut);
		if (data_queue.empty())
			return std::shared_ptr<t>();
		std::shared_ptr<T> res = data_queue.front();
		data_queue.pop();
		return res;
	}

	void push(T new_value)
	{
		std::shared_ptr<T> d(std::make_shared<T>(std::move(new_value)));
		std::lock_guard<std::mutex> lk(mut);
		data_queue.push(d);
		data_cond.notify_one();
	}

	bool empty() const
	{
		std::lock_guard<std::mutex> lk(mut);
		return data_queue.empty();
	}

};

#endif

#if 1

#include <iostream>
#include <thread>
using namespace std;

int main()
{
	
	cout << "Enter any key....." << endl;
	cin.clear();
	cin.get();
	cin.sync();

	return 0;
}

#endif

