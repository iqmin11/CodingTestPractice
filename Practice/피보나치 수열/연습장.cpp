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

int main()
{
	std::vector<int> Arr = { 3,5,9,7,2,1 };
	PrintArr(Arr);
	BubbleSort(Arr);
	PrintArr(Arr);

    return 0;
}