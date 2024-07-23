//문제 주소 : https://www.acmicpc.net/problem/10830

#include <iostream>
#include <vector>
#include <map>

int N;
long long B;
std::vector<std::vector<int>> Matrix;
int Mod = 1000;
std::map<long long, std::vector<std::vector<int>>, std::greater<long long>> DP; //Matrix의 n승을 저장

std::vector<std::vector<int>> MulMatrix(const std::vector<std::vector<int>> Left, const std::vector<std::vector<int>> Right)
{
	std::vector<std::vector<int>> Result;
	Result.resize(N);
	for (int i = 0; i < N; i++)
	{
		Result[i].resize(N, 0);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				Result[i][j] = ((Result[i][j] % Mod) + ((Left[i][k] * Right[k][j]) % Mod)) % Mod;
			}
		}
	}

	return Result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> B;
	Matrix.resize(N);
	for (int i = 0; i < N; i++)
	{
		Matrix[i].resize(N);
		for (int j = 0; j < N; j++)
		{
			std::cin >> Matrix[i][j];
		}
	}

	long long Pow = 1LL;
	DP[Pow] = Matrix;

	while (true)
	{
		Pow <<= 1LL;

		if (Pow > B)
		{
			break;
		}

		DP[Pow] = MulMatrix(DP[Pow >> 1LL], DP[Pow >> 1LL]);
	}

	std::vector<std::vector<int>> Answer(N);
	for (int i = 0; i < N; i++)
	{
		Answer[i].resize(N, 0);
		Answer[i][i] = 1;
	}

	while (B > 0)
	{
		for (auto& i : DP)
		{
			if (i.first > B)
			{
				continue;
			}

			Answer = MulMatrix(i.second, Answer);
			B -= i.first;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cout << Answer[i][j] << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}