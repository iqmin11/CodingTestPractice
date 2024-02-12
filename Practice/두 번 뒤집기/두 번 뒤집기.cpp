#include <iostream>
#include <vector>
#include <stack>

void Reverse(std::vector<int>& Arr, size_t StartIndex, size_t EndIndex)
{
	std::stack<int> Stack;

	for (size_t i = StartIndex; i <= EndIndex; i++)
	{
		Stack.push(Arr[i]);
	}

	for (size_t i = StartIndex; i <= EndIndex; i++)
	{
		Arr[i] = Stack.top();
		Stack.pop();
	}
}

void DebugRender(const std::vector<int>& Arr)
{
	std::cout << "Case1 : ";
	for (size_t i = 0; i < Arr.size(); i++)
	{
		std::cout << Arr[i] << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	size_t N;
	std::cin >> N;
	std::vector<int> Arr;
	Arr.resize(N);

	for (size_t i = 0; i < Arr.size(); i++)
	{
		std::cin >> Arr[i];
	}

	size_t StartIndex = 0;
	size_t EndIndex = 0;
	
	std::vector<int> SortedArr;
	SortedArr.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		SortedArr[i] = i + 1;
	}

	
}