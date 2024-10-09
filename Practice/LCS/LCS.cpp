//문제 주소 : https://www.acmicpc.net/problem/9251

#include <iostream>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string Str0, Str1;
	std::cin >> Str0 >> Str1;

	std::vector<std::vector<int>> DP(Str0.size() + 1);
	for (int i = 0; i <= Str0.size(); i++)
	{
		DP[i].resize(Str1.size() + 1, 0);
	}

	for (int i = 0; i < Str0.size(); i++)
	{
		for (int j = 0; j < Str1.size(); j++)
		{
			if (Str0[i] == Str1[j])
			{
				DP[i + 1][j + 1] = DP[i][j] + 1;
			}
			else
			{
				DP[i + 1][j + 1] = std::max(DP[i + 1][j], DP[i][j + 1]);
			}
		}
	}

	std::cout << DP[Str0.size()][Str1.size()];

	return 0;
}