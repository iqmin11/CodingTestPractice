//문제 주소 : https://www.acmicpc.net/problem/11279

#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::priority_queue<int> Heap;
	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;

		if (temp == 0)
		{
			if (!Heap.empty())
			{
				std::cout << Heap.top() << '\n';
				Heap.pop();
				continue;
			}

			std::cout << 0 << '\n';
		}
		else
		{
			Heap.push(temp);
		}
	}

	return 0;
}