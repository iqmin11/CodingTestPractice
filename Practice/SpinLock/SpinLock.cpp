#include <iostream>
#include <thread>

int Race = 0;

//test and set 함수 지원
//모든 쓰레드가 접근하고 확인할 수 있는 Lock
std::atomic_flag Lock = ATOMIC_FLAG_INIT;

void SpinLockTest()
{
	for (size_t i = 0; i < 100000; i++)
	{
		while (Lock.test_and_set(std::memory_order::memory_order_acquire))
		{
			//Unlock상태가 아니라면
			//조건문에서 계속해서 락이 걸려있는지를 체크(busy_wait)
		}

		Race += 1;

		Lock.clear(); //할일을 다하면 락을 여기서 반납
	}
	std::cout << Race << std::endl;
}

int main()
{
	std::cout << "Main Start" << std::endl;

	std::thread A(SpinLockTest);
	std::thread B(SpinLockTest);
	std::thread C(SpinLockTest);
	A.join();
	B.join();
	C.join();

	std::cout << "Main End" << std::endl;
}