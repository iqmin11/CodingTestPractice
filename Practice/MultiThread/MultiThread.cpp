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
	// join이나 detach를 쓰지 않으면 생기는 문제.
	// 현재 쓰레드(새로운 스레드를 만든 스코프)는 타겟 쓰레드(새로 만들어진 스레드)를 객체로 만듬. 
	// 쓰레드라는것은 별개의 실행흐름이기 때문에, 타겟쓰레드의 실행 흐름이 끝나지 않았음에도
	// 현재쓰레드에 생성된 타겟 쓰레드 객체가 파괴되는 경우가 생길 수 있음. 의도치 않은 소멸자도 호출 될 것임.
	// 그런 경우를 방지 하기 위해서 join과 detach가 있는 것.
	
	// join : 현재 쓰레드를 Block하고, 타겟 쓰레드의 실행이 끝나는 것을 기다린다. (동기적 흐름)
	// detach : 현재 쓰레드와 타겟 쓰레드를 분리한다. 현재스레드가 끝나고, 타겟 스레드 객체가 파괴되어도,
	//실제 타겟 스레드는 계속해서 실행된다. 메인스레드가 종료되지 않는이상 타겟스레드는 계속 일함 (비동기적 흐름)

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