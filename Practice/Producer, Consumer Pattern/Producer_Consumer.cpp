#include <condition_variable>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <queue>
#include <semaphore>

class JobQueue
{

public:
	//producer
	void PushJob(std::string Str)
	{
		{
			std::lock_guard<std::mutex> Lock(MTX);
			std::cout << Str;
			SharedQueue.push(std::move(Str));
		}
		
		CV.notify_one();
	}

	//consumer
	std::string PopJob()
	{
		std::unique_lock<std::mutex> Lock(MTX);
		while (SharedQueue.empty())
		{
			CV.wait(Lock);
		}

		std::string temp = std::move(SharedQueue.front());
		SharedQueue.pop();
		return temp;
	}

private:
	std::queue<std::string> SharedQueue;
	std::mutex MTX;
	std::condition_variable CV;
};

int main()
{
	JobQueue StrJobQueue;

	std::thread T1([&]()
		{
			for (size_t i = 0; i < 100; i++)
			{
				StrJobQueue.PushJob("T1Job\n");
			}
		});

	std::thread T2([&]()
		{
			for (size_t i = 0; i < 100; i++)
			{
				StrJobQueue.PushJob("T2Job\n");
			}
		});

	std::thread T3([&]()
		{
			for (size_t i = 0; i < 100; i++)
			{
				StrJobQueue.PopJob();
				std::cout << "T3\n";
			}
		});

	std::thread T4([&]()
		{
			for (size_t i = 0; i < 100; i++)
			{
				StrJobQueue.PopJob();
				std::cout << "T4\n";
			}
		});
	
	T1.join();
	T2.join();
	T3.join();
	T4.join();

	return 0;
}