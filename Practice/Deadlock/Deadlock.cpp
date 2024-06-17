#include <iostream>
#include <thread>
#include <mutex>
#include <Windows.h>

int Race = 0;
std::mutex MTX1;
std::mutex MTX2;

void Func1()
{
	MTX1.lock();
	std::cout << "T1 Get Lock1\n";
	MTX2.lock(); //대기
	std::cout << "T1 Get Lock2\n";
	Race++;

	MTX1.unlock();
	MTX2.unlock();
}

void Func2()
{
	MTX2.lock();
	std::cout << "T2 Get Lock2\n" << std::endl;
	MTX1.lock(); //대기
	std::cout << "T2 Get Lock1\n" << std::endl;
	Race++;

	MTX1.unlock();
	MTX2.unlock();
}

int main()
{
	std::thread T1(Func1);
	//::Sleep(100);
	std::thread T2(Func2);
	T1.join();
	T2.join();
	return 0;
}