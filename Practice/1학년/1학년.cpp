#include <iostream>
#include <vector>
#include <map>

std::map<int, unsigned long long> DP[101]; // DP[a] = {a,b,c,d,e,f,g} 계산번째의 결과로 나올 수 있는 모든 숫자
//<어떤숫자, 어떤숫자까지 오는데 걸리는 경로의 개수>

int main()
{
	int N, first;
	int Last = 0;
	int Count = 0;
	std::cin >> N >> first;

	DP[1].insert(std::make_pair(first, 1));

	for (size_t i = 2; i <= N - 1; i++)
	{
		int Next;
		std::cin >> Next;

		if (i == N - 1)
		{
			std::cin >> Last;
		}

		for (auto& j : DP[i - 1])
		{
			int AddResult = j.first + Next;
			int SubResult = j.first - Next;

			if (AddResult <= 20)
			{
				DP[i][AddResult] += j.second;
			}

			if (SubResult >= 0)
			{
				DP[i][SubResult] += j.second;
			}
		}
	}

	std::cout << DP[N-1][Last];

	return 0;
}