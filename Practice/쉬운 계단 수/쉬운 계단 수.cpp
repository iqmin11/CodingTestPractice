//문제 주소 : https://www.acmicpc.net/problem/10844

#include <iostream>
#include <numeric>

//int DP[101] = {}; // DP[a] = n 길이 a의 계단수는 n개
//길이 a의 계단수는 길이 a-1의 계단수로 만들어짐
//기본적으로 위로 올라가는 계단수 하나, 밑으로 내려가는 계단수 하나가 있기때문에 a * 2개의 계단수가 만들어지지만
//계단수가 0이나 9로 끝난다면 1개의 계단수밖에 파생시킬 수 없다. 그걸 어떻게 구분하냐가 관건일 듯
//그럼 이렇게 해보자

int DP[101][10]; //DP[a][b] = n // b로 끝나는 길이 a의 계단수는 n개

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	for (int i = 1; i <= 9; i++)
	{
		DP[1][i] = 1;
	}

	int Mod = 1000000000;

	for (int i = 2; i <= 100; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (j == 0) 
			{
				DP[i][j] = DP[i - 1][j + 1] % Mod;
			}
			else if (j == 9)
			{
				DP[i][j] = DP[i - 1][j - 1] % Mod;
			}
			else
			{
				DP[i][j] = (DP[i - 1][j - 1] % Mod + DP[i - 1][j + 1] % Mod) % Mod;
			}
		}
	}

	int Answer = 0;
	for (int i = 0; i < 10; i++)
	{
		Answer += DP[N][i] % Mod;
		Answer %= Mod;
	}

	std::cout << Answer;

	return 0;
}