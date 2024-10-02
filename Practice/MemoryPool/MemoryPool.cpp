#include <iostream>

class MyClass
{
public:
	int x;
	MyClass(int val)
		: x(val)
	{
		std::cout << "MyClass »ý¼º: " << x << std::endl;
	}

	~MyClass()
	{
		std::cout << "MyClass ¼Ò¸ê: " << x << std::endl;
	}
};

int main()
{
	uint8_t StackMemoryPool[1024];

	MyClass* UseInstance0 = new (StackMemoryPool) MyClass(1234567);
	MyClass* UseInstance1 = new (StackMemoryPool + sizeof(MyClass)) MyClass(1234567);
	UseInstance0->~MyClass();
	UseInstance1->~MyClass();

	int a = 0;

	return 0;
}