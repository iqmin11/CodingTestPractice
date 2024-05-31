#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void FuncA()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "A쓰레드" << std::endl;
	}
}

void FuncB()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "B쓰레드" << std::endl;
	}
}

void FuncC()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "C쓰레드" << std::endl;
	}
}

void PartSum(int Start, int End, int* Result)
{
	for (size_t i = Start; i <= End; i++)
	{
		*Result += i;
	}
}

//100만번 1을 더함
void ErrorTestSum(int& Result)
{
	for (size_t i = 1; i <= 1000000; i++)
	{
		Result += 1;
	}
}

void MutexTestSum(int& Result, std::mutex& Mutex)
{
	for (size_t i = 1; i <= 1000000; i++)
	{
		Mutex.lock(); //lock과
		Result += 1; //코드는 한번에 한 쓰레드만 권한을 얻을 수 있음(임계영역에 들어갈 수 있는 권한)
		Mutex.unlock(); //unlock사이의
		//unlock을 안하면 deadlock현상이 발생
	}
}

void MutexLockGuardTestSum(int& Result, std::mutex& Mutex)
{
	for (size_t i = 1; i <= 1000000; i++)
	{
		//RAII디자인 패턴을 따르는 lock
		std::lock_guard<std::mutex> lock(Mutex); //해당 스코프에서 벗어나면 lock이 소멸, 소멸자에서 unlock 호출
		Result += 1; 
	}
}

void AtomicTestSum(std::atomic<int>& Result)
{
	for (size_t i = 1; i <= 1000000; i++)
	{
		Result += 1;
	}
}

int main()
{
	std::cout << "MainStart" << std::endl;
	std::thread ThreadA(FuncA);
	ThreadA.detach();
	//join : 해당 쓰레드가 종료될때 까지 main을 종료하지 않겠다
	//Detach : main 종료하면 그대로 종료 (명시적인 어썰트 안남)
	//해당 쓰레드를 실행시킨 스택과 관계없이 별개의 쓰레드가 되도록 만들겠다란 뜻이야. 떼버린다

	//멀티쓰레드를 이용한 병렬 합
	//{
	//	std::vector<std::thread> Threads;
	//	std::vector<int> Results;
	//	Threads.reserve(4);
	//	Results.resize(4, 0);

	//	for (int i = 0; i < 4; i++)
	//	{
	//		Threads.push_back(std::thread(PartSum, 1 + (i * 25), 25 + (i * 25), &(Results[i])));
	//		Threads[i].join();
	//	}

	//	int Result = 0;
	//	for (size_t i = 0; i < 4; i++)
	//	{
	//		Result += Results[i];
	//	}

	//	std::cout << Result << std::endl;
	//}

	////멀티쓰레드 메모리 공유 문제
	//{
	//	int Count = 0;
	//	std::vector<std::thread> Threads;
	//	Threads.reserve(4);

	//	for (int i = 0; i < 4; i++)
	//	{
	//		Threads.push_back(std::thread(ErrorTestSum, std::ref(Count))); //같은 메모리에 데이터를 입력해 경쟁상태를 만듬
	//	}
	//	
	//	for (size_t i = 0; i < 4; i++)
	//	{
	//		Threads[i].join();
	//	}
	//	std::cout << Count << std::endl;
	//}

	////뮤텍스를 활용하여 공유 메모리 문제 해소
	//{
	//	int Count = 0;
	//	std::mutex Mutex; // 상호 배제(mutual exclusion)
	//	std::vector<std::thread> Threads;
	//	Threads.reserve(4);

	//	for (int i = 0; i < 4; i++)
	//	{
	//		Threads.push_back(std::thread(MutexTestSum, std::ref(Count), std::ref(Mutex)));
	//	}

	//	for (size_t i = 0; i < 4; i++)
	//	{
	//		Threads[i].join();
	//	}
	//	std::cout << Count << std::endl;
	//}

	////락가드 테스트
	//{
	//	int Count = 0;
	//	std::mutex Mutex;
	//	std::vector<std::thread> Threads;
	//	Threads.reserve(4);

	//	for (int i = 0; i < 4; i++)
	//	{
	//		Threads.push_back(std::thread(MutexLockGuardTestSum, std::ref(Count), std::ref(Mutex)));
	//	}

	//	for (size_t i = 0; i < 4; i++)
	//	{
	//		Threads[i].join();
	//	}
	//	std::cout << Count << std::endl;
	//}

	////원자성(Atomic 테스트)
	////원자성이란 CPU가 명령어 1개로 처리하는 명령으로, 중간에 다른 쓰레드가 끼어들 여지가 없는 연산을 말함.
	////원자와 같이 더이상 쪼갤 여지가 없음
	//{
	//	std::atomic<int> Count = 0;
	//	std::vector<std::thread> Threads;
	//	Threads.reserve(4);

	//	for (int i = 0; i < 4; i++)
	//	{
	//		Threads.push_back(std::thread(AtomicTestSum, std::ref(Count)));
	//	}

	//	for (size_t i = 0; i < 4; i++)
	//	{
	//		Threads[i].join();
	//	}
	//	std::cout << Count << std::endl;
	//}
	
	std::cout << "MainEnd" << std::endl;
	return 0;
}