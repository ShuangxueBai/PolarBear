#include "precompile.h"

POLAR_BEAR_USE_NAMESPACE;

using std::cin;
using std::cout;
using std::endl;


#define DEBUG_OUT_ITEM { \
     cout << "Enter any one...." << endl; \
     cin.clear(); \
     cin.get();    \
     cin.sync(); }


#if 0

int main(int argc, char** argv)
{


	PBobject* mainP = new PBobject();
	if (1)
	{
		PBrefPtr<PBobject> p = mainP;
		cout << p->getReferenceCount() << endl;
		PBrefPtr<PBobject> p2 = p;
		cout << p->getReferenceCount() << endl;
		cout << p2->getReferenceCount() << endl;
	}

	cout << mainP->getReferenceCount() << endl;
	if (mainP)
		delete mainP;
	mainP = nullptr;


	//test memory allocate
	InitMemAllocPool();

	pbvoidpt pBuffer = nullptr;
	pBuffer = MemoryAlloc(512);

	memset(pBuffer, 0, 512);
	MemoryFree(pBuffer);

	DestroyMemAllocPool();

	DEBUG_OUT_ITEM
	return 0;
}

#endif


#if 0

#include <string>
#include <future>
#include <iostream>
#include <functional>
#include <thread>
#include <chrono>
using namespace std;

int countdown(int from, int to)
{
	for (int i=from; i!=to; ++i)
	{
		std::cout << i << '\n';
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}//end for
	std::cout << "Lift off!\n";
	return from - to;
}

int main(int argv, char** argc)
{
	std::packaged_task<int(int, int)> tsk(countdown);
	std::future<int> ret = tsk.get_future();

	std::thread th(std::move(tsk), 10, 0);

	int value = ret.get();

	std::cout << "The countdown lasted for " << value << " seconds. \n";

	th.join();

	DEBUG_OUT_ITEM;
	return 0;
}

#endif

#if 0

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <future>

using namespace std;

bool is_prime(int x) {
	for (int i = 2; i < x; ++i) if (x%i == 0) return false;
	return true;
}

int main()
{

	std::future<bool> fut = std::async(is_prime, 4444333322);

	cout << "checking please wait " << endl;
	chrono::milliseconds span(100);
	while (fut.wait_for(span) == std::future_status::timeout)
	{
		cout << '.' << std::flush;
	}//end while

	bool x = fut.get();

	cout << "\n 4444333322 " << (x ? "is" : "is not") << "prime. \n";
	return 0;
}

#endif

#if 0

#include <iostream>
#include <future>
#include <chrono>

using namespace std;

int get_value() { return 10; }

int main()
{
	std::future<int> fut = std::async(get_value);
	std::shared_future<int> shfut = fut.share();

	cout << "value" << shfut.get() << '\n';
	cout << "its double: " << shfut.get() * 2 << '\n';
	return 0;
}

#endif

#if 0

#include <iostream>
#include <thread>
#include <chrono>
#include <future>
#include <mutex>
#include <condition_variable>
#include <atomic>

using namespace std;


std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void print_id(int id) {
	std::unique_lock<std::mutex> lck(mtx);
	while (!ready)
	{
		cv.wait(lck);
	}//end while
	std::cout << "thread" << id << endl;
}

void go() {
	std::unique_lock<std::mutex> lck(mtx);
	std::notify_all_at_thread_exit(cv, std::move(lck));
	ready = true;
	cv.notify_all();
}

int main()
{
	std::thread threads[10];

	for (int i=0; i<10; ++i)
	{
		threads[i] = std::thread(print_id, i);
	}

	std::cout << "10 threads ready to race... \n";
	std::thread(go).detach();
	for (auto& th : threads) th.join();
	return 0;
}


#endif



