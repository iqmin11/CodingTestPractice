//문제 주소 : https://www.acmicpc.net/problem/13904

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;

	std::cin >> N;

	std::vector<std::pair<int, int>> Data;
	Data.resize(N);

	int MaxDeadline = INT32_MIN;
	for (int i = 0; i < N; i++)
	{
		std::cin >> Data[i].second;
		std::cin >> Data[i].first;

		MaxDeadline = std::max(MaxDeadline, Data[i].first);
	}

	std::priority_queue<std::pair<int, int>> pq;

	for (int i = 0; i < N; i++)
	{
		pq.push(Data[i]);
	}

	std::vector<int> DateScore;
	DateScore.resize(MaxDeadline + 1, -1);

	while (!pq.empty())
	{
		int CurDate = pq.top().second;
		int CurScore = pq.top().first;

		while (DateScore[CurDate] != -1 || CurDate > 0)
		{
			CurDate--;
		}

	}

	int Answer = 0;

	

	std::cout << Answer;

	return 0;
}