//https://www.acmicpc.net/problem/1725

#include <iostream>
#include <stack>
#include <vector>

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> Histogram;
	Histogram.resize(N);

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> Histogram[i];
	}

	std::stack<int> Stack;
	int RectSize = 0;
	Stack.push(0);

	for (size_t i = 0; i < N; i++)
	{
		while (!Stack.empty() && Histogram[Stack.top()] > Histogram[i])
		{
			int Width = i - Stack.top() - 1;
			int Hight = Histogram[Stack.top()];
			RectSize = std::max(RectSize, Hight * Width);
			Stack.pop();
		}
		Stack.push(i);
	}


	int a = 0;
}