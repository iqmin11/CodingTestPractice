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

//class MyClass 
//{
//public:
//	int x;
//	MyClass(int val) 
//		: x(val) 
//	{
//		std::cout << "MyClass ����: " << x << std::endl;
//	}
//	
//	~MyClass() 
//	{
//		std::cout << "MyClass �Ҹ�: " << x << std::endl;
//	}
//};

class MyClass
{
public:
	int x;
	MyClass(MyClass&& val) noexcept
		: x(std::move(val.x))
	{
	}

	MyClass& operator=(MyClass&& val) noexcept
	{
		x = std::move(val.x);
		return *this;
	}
};

int main()
{
	//uint8_t StackMemoryPool[1024];

	//MyClass* UseInstance0 = new (StackMemoryPool) MyClass(1234567);
	//MyClass* UseInstance1 = new (StackMemoryPool + sizeof(MyClass)) MyClass(1234567);
	//UseInstance0->~MyClass();
	//UseInstance1->~MyClass();

	//int a = 0;

	//std::string TestStr = "aaaaabbb";
	//std::string TestStrCpy = TestStr;
	//std::string TestStrMov = std::move(TestStr);
    return 0;
}