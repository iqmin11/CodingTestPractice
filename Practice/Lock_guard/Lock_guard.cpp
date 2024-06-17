#include <iostream>
#include <mutex>
#include <thread>

//RAII������ Ȱ���� ��
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
		//�����ڸ� ȣ���� �� ��
		MTX.lock();
	}

	~MyLockGaurd()
	{
		//�Ҹ��ڸ� ȣ���� �� ���
		MTX.unlock();
	}

	std::mutex& MTX;
};

int main()
{

	return 0;
}