//문제 주소 : https://www.acmicpc.net/problem/1563

#include <iostream>
#include <string>
#include <vector>

int N;
int Mod = 1000000;
std::string Info;
int Case = 0;

//지각 카운트
int LateCount = 0;

//연속된 결석 카운트

void BT(int CurIndex, int PrevNum = -1, int PrevContinueousCount = 0)
{
	if (CurIndex >= N)
	{
		std::cout << Info << std::endl;
		Case++;
		return;
	}

	for (int  i = 0; i < 3; i++)
	{
		Info[CurIndex] = '0' + static_cast<char>(i);

		if (i == 1)
		{
			if (LateCount + 1 >= 2)
			{
				continue;
			}

			++LateCount;
		}

		if (PrevContinueousCount == 2 && i == 2)
		{
			continue;
		}

		if (i == 2)
		{
			BT(CurIndex + 1, i, PrevContinueousCount + 1);
			continue;
		}
		
		BT(CurIndex + 1, i, 0);

		if (i == 1)
		{
			LateCount--;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	//Info.resize(N);
	//BT(0);

	std::vector<std::vector<std::vector<int>>> DP(N + 1); //DP[L][E][C] //길이, 끝숫자, 1의 갯수

	for (int i = 0; i <= N; i++)
	{
		DP[i].resize(3);
		for (int j = 0; j < 3; j++)
		{
			DP[i][j].resize(2);
		}
	}

	DP[0][0][0] = 0;
	DP[0][0][1] = 0;
	DP[0][1][0] = 0;
	DP[0][1][1] = 0;
	DP[0][2][0] = 0;
	DP[0][2][1] = 0;
	
	if (N >= 1)
	{
		DP[1][0][0] = 1;
		DP[1][0][1] = 0;
		DP[1][1][0] = 0;
		DP[1][1][1] = 1;
		DP[1][2][0] = 1;
		DP[1][2][1] = 0;
	}

	if (N >= 2)
	{
		DP[2][0][0] = 2;
		DP[2][0][1] = 1;
		DP[2][1][0] = 0;
		DP[2][1][1] = 2;
		DP[2][2][0] = 2;
		DP[2][2][1] = 1;
	}

	for (int L = 3; L <= N; L++)
	{
		DP[L][0][0] = (DP[L - 1][0][0] + DP[L - 1][1][0] + DP[L - 1][2][0]) % Mod;
		DP[L][0][1] = (DP[L - 1][0][1] + DP[L - 1][1][1] + DP[L - 1][2][1]) % Mod;
		DP[L][1][0] = 0;
		DP[L][1][1] = (DP[L - 1][0][0] + DP[L - 1][1][0] + DP[L - 1][2][0]) % Mod;
		DP[L][2][0] = (DP[L - 2][0][0] + DP[L - 2][1][0] + DP[L - 1][0][0] + DP[L - 1][1][0]) % Mod;
		DP[L][2][1] = (DP[L - 2][0][1] + DP[L - 2][1][1] + DP[L - 1][0][1] + DP[L - 1][1][1]) % Mod;
	}
	
	int Answer = 0;
	for (int E = 0; E < 3; E++)
	{
		for (int C = 0; C < 2; C++)
		{
			Answer += DP[N][E][C] % Mod;
		}
	}

	std::cout << Answer % Mod;

	return 0;
} 