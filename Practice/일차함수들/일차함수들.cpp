//문제 주소 : https://www.acmicpc.net/problem/25426

#include <iostream>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	unsigned long long N;
	std::cin >> N;
	std::priority_queue<std::pair<unsigned long long, unsigned long long>> pq;

	for (int i = 0; i < N; i++)
	{
		std::pair<unsigned long long, unsigned long long> temp;
		std::cin >> temp.first >> temp.second;
		
		pq.push(temp);
	}

	unsigned long long Answer = 0;

	while (!pq.empty())
	{
		std::pair<unsigned long long, unsigned long long> Top = pq.top();
		pq.pop();
		Answer += (Top.first * N) + Top.second;
		N--;
	}

	std::cout << Answer;

	return 0;
}