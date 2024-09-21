#include <iostream>
#include <vector>

void PrintArr(const std::vector<int>& Arr)
{
	for (int i = 0; i < Arr.size(); i++)
	{
		std::cout << Arr[i] << ' ';
	}
	std::cout << std::endl;
}

void BubbleSort(std::vector<int>& Arr)
{
	for (int i = 0; i < Arr.size() - 1; i++)
	{
		for (int j = 0; j < Arr.size() - i - 1; j++)
		{
			if (Arr[j] > Arr[j + 1])
			{
				std::swap(Arr[j], Arr[j + 1]);
			}
		}
	}
}

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