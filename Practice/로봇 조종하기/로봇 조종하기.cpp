#include <iostream>
#include <vector>

int N, M;
std::vector<std::vector<int>> Arr;
std::vector<std::vector<int>> DP;
std::vector<std::vector<int>> DP2;
int dx[] = {-1, 0, 1};
int dy[] = {0, 1, 0};

int main()
{
	std::cin >> N >> M;
	Arr.resize(N);
	DP.resize(N);
	DP2.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		Arr[i].resize(M);
		DP[i].resize(M, -101 * N * M);
		DP2[i].resize(M, -101 * N * M);
		for (size_t j = 0; j < M; j++)
		{
			std::cin >> Arr[i][j];
		}
	}
}