#include <iostream>
#include <thread>
#include <mutex>

int Race = 0;
std::mutex Mutex;

void MutexTest()
{
	for (size_t i = 0; i < 100000; i++)
	{
		//Mutex.lock�� ��� �ѹ��� �� �����常 ���� ����, ������ �Ӱ迵���� �����Ϸ��� ������� block���°� ��.(busy wait�� ���������)
		Mutex.lock();
		Race += 1;
		Mutex.unlock();
		//lock�� unlock���̴� �Ӱ迵���̰� �ش� �����帧���� �ѹ��� �� �����常 ������ �� �ִ�
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