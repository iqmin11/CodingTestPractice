#include <iostream>
#include <mutex>
#include <thread>

//RAII패턴을 활용한 락
class MyLockGaurd
{
public:
	MyLockGaurd() = delete;

	MyLockGaurd(const MyLockGaurd&) = delete;
	MyLockGaurd(MyLockGaurd&&) = delete;
	MyLockGaurd operator=(const MyLockGaurd&) = delete;
	MyLockGaurd operator=(MyLockGaurd&&) = delete;
	
	MyLockGaurd(std::mutex& _Mtx)
		: MTX(_Mtx)
	{
		//생성자를 호출할 때 락
		MTX.lock();
	}

	~MyLockGaurd()
	{
		//소멸자를 호출할 때 언락
		MTX.unlock();
	}

	std::mutex& MTX;
};

int main()
{

	return 0;
}