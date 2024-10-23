//문제 주소 : https://www.acmicpc.net/problem/1026

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;

	std::vector<std::vector<int>> Nums(2);
	for (int i = 0; i < 2; i++)
	{
		Nums[i].resize(N);
		for (int j = 0; j < N; j++)
		{
			std::cin >> Nums[i][j];
		}
	}

	std::sort(Nums[0].begin(), Nums[0].end());
	std::sort(Nums[1].begin(), Nums[1].end(), std::greater<int>());

	int Answer = 0;

	for (int i = 0; i < N; i++)
	{
		Answer += (Nums[0][i] * Nums[1][i]);
	}

	std::cout << Answer;

	return 0;
}