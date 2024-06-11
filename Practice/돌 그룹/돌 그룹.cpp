//문제 주소 : https://www.acmicpc.net/problem/12886

#include <iostream>
#include <set>
#include <queue>
#include <algorithm>

bool IsVisit[1001][1001];
int Sum = 0;

bool BFS(std::pair<int, int> StartIndex)
{
	std::queue<std::pair<int, int>> q;
	//IsVisit[StartIndex.first][StartIndex.second] = true;
	q.push(StartIndex);

	while (!q.empty())
	{
		int a = q.front().first;
		int b = q.front().second;
		int c = Sum - a - b;

		q.pop();

		if (a == b && b == c)
		{
			return true;
		}

		int Low = a;
		int High = b;

		if (Low > High)
		{
			std::swap(Low, High);
		}

		if (Low != High && !IsVisit[Low][High])
		{
			IsVisit[Low][High] = true;
			q.push(std::make_pair(Low + Low, High - Low));
		}

		Low = a;
		High = c;

		if (Low > High)
		{
			std::swap(Low, High);
		}

		if (Low != High && !IsVisit[Low][High])
		{
			IsVisit[Low][High] = true;
			q.push(std::make_pair(Low + Low, High - Low));
		}

		Low = b;
		High = c;

		if (Low > High)
		{
			std::swap(Low, High);
		}

		if (Low != High && !IsVisit[Low][High])
		{
			IsVisit[Low][High] = true;
			q.push(std::make_pair(Low + Low, High - Low));
		}
	}
	
	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int StartIndex[3];

	for (size_t i = 0; i < 3; i++)
	{
		std::cin >> StartIndex[i];
		Sum += StartIndex[i];
	}
	
	if (Sum % 3 != 0)
	{
		std::cout << 0;
		return 0;
	}

	std::cout << BFS({ StartIndex[0] , StartIndex[1] });

	return 0;
}