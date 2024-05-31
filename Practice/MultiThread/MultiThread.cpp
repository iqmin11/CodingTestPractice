#include <iostream>
#include <thread>
#include <vector>
#include <mutex>

void FuncA()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "A������" << std::endl;
	}
}

void FuncB()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "B������" << std::endl;
	}
}

void FuncC()
{
	for (size_t i = 0; i < 10; i++)
	{
		std::cout << "C������" << std::endl;
	}
}

void PartSum(int Start, int End, int* Result)
{
	for (size_t i = Start; i <= End; i++)
	{
		*Result += i;
	}
}

//100���� 1�� ����
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
		Mutex.lock(); //lock��
		Result += 1; //�ڵ�� �ѹ��� �� �����常 ������ ���� �� ����(�Ӱ迵���� �� �� �ִ� ����)
		Mutex.unlock(); //unlock������
		//unlock�� ���ϸ� deadlock������ �߻�
	}
}

void MutexLockGuardTestSum(int& Result, std::mutex& Mutex)
{
	for (size_t i = 1; i <= 1000000; i++)
	{
		//RAII������ ������ ������ lock
		std::lock_guard<std::mutex> lock(Mutex); //�ش� ���������� ����� lock�� �Ҹ�, �Ҹ��ڿ��� unlock ȣ��
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
	//join : �ش� �����尡 ����ɶ� ���� main�� �������� �ʰڴ�
	//Detach : main �����ϸ� �״�� ���� (������� ���Ʈ �ȳ�)
	//�ش� �����带 �����Ų ���ð� ������� ������ �����尡 �ǵ��� ����ڴٶ� ���̾�. ��������

	//��Ƽ�����带 �̿��� ���� ��
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

	////��Ƽ������ �޸� ���� ����
	//{
	//	int Count = 0;
	//	std::vector<std::thread> Threads;
	//	Threads.reserve(4);

	//	for (int i = 0; i < 4; i++)
	//	{
	//		Threads.push_back(std::thread(ErrorTestSum, std::ref(Count))); //���� �޸𸮿� �����͸� �Է��� ������¸� ����
	//	}
	//	
	//	for (size_t i = 0; i < 4; i++)
	//	{
	//		Threads[i].join();
	//	}
	//	std::cout << Count << std::endl;
	//}

	////���ؽ��� Ȱ���Ͽ� ���� �޸� ���� �ؼ�
	//{
	//	int Count = 0;
	//	std::mutex Mutex; // ��ȣ ����(mutual exclusion)
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

	////������ �׽�Ʈ
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

	////���ڼ�(Atomic �׽�Ʈ)
	////���ڼ��̶� CPU�� ��ɾ� 1���� ó���ϴ� �������, �߰��� �ٸ� �����尡 ����� ������ ���� ������ ����.
	////���ڿ� ���� ���̻� �ɰ� ������ ����
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