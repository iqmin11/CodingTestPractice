//문제 주소 : https://www.acmicpc.net/problem/1034

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int Y, X;
	std::cin >> Y >> X;
	std::vector<std::string> Bits;
	Bits.resize(Y);

	std::map<std::string, int> Count;//어떤 비트가 몇개 있는가, 0의 갯수는 몇개인가

	for (int y = 0; y < Y; y++)
	{
		std::cin >> Bits[y];
		++Count[Bits[y]];
	}

	int K;
	std::cin >> K;

	std::vector<std::string> Rank;
	Rank.reserve(Y);

	for (auto i : Count)
	{
		Rank.push_back(i.first);
	}

	std::sort(Rank.begin(), Rank.end(), [&](const std::string& Left, const std::string& Right)
		{
			if (Count[Left] == Count[Right])
			{
				int LeftZeroCount = 0;
				int RightZeroCount = 0;

				for (int i = 0; i < Left.size(); i++)
				{
					if (Left[i] == '0')
					{
						LeftZeroCount++;
					}

					if (Right[i] == '0')
					{
						RightZeroCount++;
					}
				}

				return LeftZeroCount < RightZeroCount;
			}

			return Count[Left] > Count[Right];
		});

	for (int i = 0; i < Rank.size(); i++)
	{
		int ZeroCount = 0;
		for (int j = 0; j < Rank[i].size(); j++)
		{
			if (Rank[i][j] == '0')
			{
				ZeroCount++;
			}
		}

		if (ZeroCount <= K)
		{
			if ((K - ZeroCount) % 2 == 0)
			{
				std::cout << Count[Rank[i]];
				return 0;
			}
		}
	}

	std::cout << 0;
	return 0;
}