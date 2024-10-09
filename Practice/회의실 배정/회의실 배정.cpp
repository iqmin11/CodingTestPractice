//문제 주소 : https://www.acmicpc.net/problem/1931

#include <iostream>
#include <queue>

struct Cmp
{
	bool operator()(const std::pair<int, int>& Left, const std::pair<int, int>& Right)
	{
		if (Left.second == Right.second)
		{
			return Left.first > Right.first;
		}

		return Left.second > Right.second;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Cmp> pq;
	int N;
	std::cin >> N;

	for (int i = 0; i < N; i++)
	{
		std::pair<int, int> temp;
		std::cin >> temp.first >> temp.second;
		pq.push(std::move(temp));
	}

	int Answer = 0;
	std::pair<int, int> Prev = std::make_pair(0, 0);
	while (!pq.empty())
	{
		std::pair<int, int> Cur = pq.top();
		pq.pop();

		if (Prev.second > Cur.first)
		{
			continue;
		}
		
		Prev = Cur;
		Answer++;
	}

	std::cout << Answer;

	return 0;
}