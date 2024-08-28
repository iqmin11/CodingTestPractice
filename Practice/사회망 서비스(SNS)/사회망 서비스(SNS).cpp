//문제 주소 : https://www.acmicpc.net/problem/2533

#include <iostream>
#include <vector>
#include <queue>

int N;
std::vector<std::vector<int>> LinkedInfo;

struct Cmp
{
	bool operator()(int Left, int Right)
	{
		return LinkedInfo[Left].size() < LinkedInfo[Right].size();
	}
};

std::priority_queue<int, std::vector<int>, Cmp> pq;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	LinkedInfo.resize(N + 1);
	for (int i = 0; i < N - 1; i++)
	{
		int Parent, Child;

		std::cin >> Parent >> Child;

		LinkedInfo[Parent].push_back(Child);
		LinkedInfo[Child].push_back(Parent);
	}

	for (int i = 1; i <= N; i++)
	{
		pq.push(i);
	}

	int a = 0;

	return 0;
}