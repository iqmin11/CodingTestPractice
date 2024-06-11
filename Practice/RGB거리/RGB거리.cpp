//문제 주소 : https://www.acmicpc.net/problem/1149

#include <iostream>
#include <vector>

int DP[1001][3]; //a번째 집의 색이 b일때 최소 가격

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<std::vector<int>> House;
	House.resize(N + 1);

	for (int i = 1; i <= N; i++)
	{
		House[i].resize(3);
		for (int Color = 0; Color < 3; Color++)
		{
			std::cin >> House[i][Color];
		}
	}

	int Answer = INT32_MAX;

	for (int i = 1; i <= N; i++)
	{
		for (int Cur = 0; Cur < 3; Cur++)
		{
			int MinValue = INT32_MAX;

			for (int Prev = 0; Prev < 3; Prev++)
			{
				if (Cur == Prev)
				{
					continue;
				}

				MinValue = std::min(MinValue, DP[i - 1][Prev]);
			}

			DP[i][Cur] = MinValue + House[i][Cur];

			if (i == N)
			{
				Answer = std::min(Answer, DP[i][Cur]);
			}
		}
	}

	std::cout << Answer;

	return 0;
}