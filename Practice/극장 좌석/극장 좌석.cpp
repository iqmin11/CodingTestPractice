//문제 주소 : https://www.acmicpc.net/problem/2302

#include <iostream>

int DP[41];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N , M;
	
	std::cin >> N >> M;

	DP[0] = 1;
	DP[1] = 1;

	for (int i = 2; i <= N; i++)
	{
		DP[i] = DP[i - 1] + DP[i - 2];
	}

	int PrevCheck = 0;
	int CurCheck = 0;
	int Answer = 1;
	for (int i = 0; i < M; i++)
	{
		PrevCheck = CurCheck;
		std::cin >> CurCheck;

		Answer *= DP[CurCheck - PrevCheck - 1];
	}
	
	Answer *= DP[N - CurCheck];

	std::cout << Answer;

	return 0;
}