//문제 주소 : https://www.acmicpc.net/problem/1202

#include <iostream>
#include <queue>
#include <algorithm>
#include <set>

int N, K;
std::priority_queue<std::pair<long long, long long>> pq;
std::multiset<long long> Limits;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		long long Weight, Value;
		std::cin >> Weight >> Value;

		pq.push(std::make_pair(Value, Weight));
	}

	for (int i = 0; i < K; i++)
	{
		long long temp;
		std::cin >> temp;
		Limits.insert(temp);
	}

	long long Answer = 0;

	while (K > 0 && !pq.empty())
	{
		long long CurValue = pq.top().first;
		long long CurWeight = pq.top().second;
		pq.pop();
		
		//이진탐색으로 가능한 가장 효율적인 가방 찾기
		auto FindIter = Limits.lower_bound(CurWeight);

		if (FindIter == Limits.end())
		{
			continue;
		}

		Limits.erase(FindIter);
		Answer += CurValue;
		--K;
	}

	std::cout << Answer;

	return 0;
}