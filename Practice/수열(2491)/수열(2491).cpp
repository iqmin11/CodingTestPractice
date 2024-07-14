//문제 주소 : https://www.acmicpc.net/problem/2491

#include <iostream>
#include <vector>

int DP[100001][2]; //DP[a][b] 수열이 증가할때와 감소할때를 나누어 체크

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<int> Arr;
	Arr.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	DP[0][0] = 1;
	DP[0][1] = 1;

	int Answer = 1;

	for (int i = 1; i < N; i++)
	{
		DP[i][0] = 1;
		DP[i][1] = 1;

		if (Arr[i] > Arr[i - 1])
		{
			DP[i][1] += DP[i - 1][1];
		}
		else if (Arr[i] < Arr[i - 1])
		{
			DP[i][0] += DP[i - 1][0];
		}
		else
		{
			DP[i][0] += DP[i - 1][0];
			DP[i][1] += DP[i - 1][1];
		}

		Answer = std::max(std::max(Answer, DP[i][0]), DP[i][1]);
	}

	std::cout << Answer;

	return 0;
}