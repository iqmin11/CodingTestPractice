//문제 주소 : https://www.acmicpc.net/problem/5582

#include <iostream>
#include <vector>

int DP[4000][4000];

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::string Str1;
	std::string Str2;
	std::cin >> Str1 >> Str2;

	int X = Str1.size();
	int Y = Str2.size();

	int Answer = 0;
	for (int y = 0; y < Y; y++)
	{
		for (int x = 0; x < X; x++)
		{
			if (Str1[x] != Str2[y])
			{
				continue;
			}

			if (x == 0 || y == 0)
			{
				DP[y][x]++;
			}
			else
			{
				DP[y][x] = DP[y - 1][x - 1] + 1;
			}

			Answer = std::max(Answer, DP[y][x]);
		}
	}

	std::cout << Answer;
	return 0;
}