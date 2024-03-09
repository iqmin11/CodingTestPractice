//https://www.acmicpc.net/problem/1715

#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

	for (size_t i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		pq.push(temp);
	}

	int Answer = 0;
	while (true)
	{
		int Left = pq.top();
		pq.pop();
		
		if (pq.empty())
		{
			break;
		}

		int Right = pq.top();
		pq.pop();

		int Plus = Left + Right;
		Answer += Plus;
		
		if (pq.empty())
		{
			break;
		}
		pq.push(Plus);
	}

	std::cout << Answer;

	return 0;
}