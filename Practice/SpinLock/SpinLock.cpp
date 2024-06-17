#include <iostream>
#include <thread>

int Race = 0;

//test and set �Լ� ����
//��� �����尡 �����ϰ� Ȯ���� �� �ִ� Lock
std::atomic_flag Lock = ATOMIC_FLAG_INIT;

void SpinLockTest()
{
	for (size_t i = 0; i < 100000; i++)
	{
		while (Lock.test_and_set(std::memory_order::memory_order_acquire))
		{
			//Unlock���°� �ƴ϶��
			//���ǹ����� ����ؼ� ���� �ɷ��ִ����� üũ(busy_wait)
		}

		Race += 1;

		Lock.clear(); //������ ���ϸ� ���� ���⼭ �ݳ�
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