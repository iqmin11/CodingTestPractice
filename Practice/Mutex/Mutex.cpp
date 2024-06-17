#include <iostream>
#include <thread>
#include <mutex>

int Race = 0;
std::mutex Mutex;

void MutexTest()
{
	for (size_t i = 0; i < 100000; i++)
	{
		//Mutex.lock인 경우 한번에 한 스레드만 접근 가능, 나머지 임계영역에 접근하려는 스레드는 block상태가 됨.(busy wait는 실행상태임)
		Mutex.lock();
		Race += 1;
		Mutex.unlock();
		//lock과 unlock사이는 임계영역이고 해당 실행흐름에는 한번에 한 스레드만 관여할 수 있다
	}

	std::cout << Race << std::endl;
}

int main()
{
	std::cout << "Main Start" << std::endl;

	std::thread A(MutexTest);
	std::thread B(MutexTest);
	std::thread C(MutexTest);
	A.join();
	B.join();
	C.join();

	std::cout << "Main End" << std::endl;
}