//문제 주소 : https://www.acmicpc.net/problem/2240

#include <iostream>
#include <vector>

int DP[1001][31];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//DP[a][b] = a초에 이동을 b번 했을때 최대 개수

	int T, W;
	std::cin >> T >> W;

	std::vector<int> DropInfo(T + 1);

	for (int i = 1; i <= T; i++)
	{
		std::cin >> DropInfo[i];
	}


	if (DropInfo[1] == 1)
	{
		DP[1][0] = 1;
		DP[1][1] = 0;
	}
	else
	{
		DP[1][0] = 0;
		DP[1][1] = 1;
	}

	int Answer = 1;

	for (int t = 2; t <= T; t++)
	{
		for (int w = 0; w <= std::min(t, W); w++)
		{
			int CurPos = w % 2; //현재 위치가 1이다
			int DropPos = DropInfo[t] - 1;
			bool IsCatch = CurPos == DropPos;

			DP[t][w] = (w == 0 ? DP[t - 1][w] : std::max(DP[t - 1][w], DP[t - 1][w - 1])) + static_cast<int>(IsCatch);
			
			Answer = std::max(DP[t][w], Answer);
		}
	}

	std::cout << Answer;

	return 0;
}