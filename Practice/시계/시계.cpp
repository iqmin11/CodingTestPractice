//문제 주소 : https://www.acmicpc.net/problem/2082

#include <iostream>
#include <vector>

std::vector<std::vector<std::vector<char>>> Nums =
{
	{
		{'#','#','#'},
		{'#','.','#'},
		{'#','.','#'},
		{'#','.','#'},
		{'#','#','#'},
	},
	{
		{'.','.','#'},
		{'.','.','#'},
		{'.','.','#'},
		{'.','.','#'},
		{'.','.','#'},
	},
	{
		{'#','#','#'},
		{'.','.','#'},
		{'#','#','#'},
		{'#','.','.'},
		{'#','#','#'},
	},
	{
		{'#','#','#'},
		{'.','.','#'},
		{'#','#','#'},
		{'.','.','#'},
		{'#','#','#'},
	},
	{
		{'#','.','#'},
		{'#','.','#'},
		{'#','#','#'},
		{'.','.','#'},
		{'.','.','#'},
	},
	{
		{'#','#','#'},
		{'#','.','.'},
		{'#','#','#'},
		{'.','.','#'},
		{'#','#','#'},
	},
	{
		{'#','#','#'},
		{'#','.','.'},
		{'#','#','#'},
		{'#','.','#'},
		{'#','#','#'},
	},
	{
		{'#','#','#'},
		{'.','.','#'},
		{'.','.','#'},
		{'.','.','#'},
		{'.','.','#'},
	},
	{
		{'#','#','#'},
		{'#','.','#'},
		{'#','#','#'},
		{'#','.','#'},
		{'#','#','#'},
	},
	{
		{'#','#','#'},
		{'#','.','#'},
		{'#','#','#'},
		{'.','.','#'},
		{'#','#','#'},
	},
}; //어떤 숫자가 어떤 발광다이오드 형태로 나타나는가

bool CanChange(const std::vector<std::vector<char>>& Prev, const std::vector<std::vector<char>>& Next)
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (Prev[i][j] == '#' && Next[i][j] == '.')
			{
				return false;
			}
		}
	}

	return true;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::vector<std::vector<std::vector<char>>> Clock;
	Clock.resize(4);
	for (int i = 0; i < 4; i++)
	{
		Clock[i].resize(5);
		for (int j = 0; j < 5; j++)
		{
			Clock[i][j].resize(3);
		}
	}


	for (int k = 0; k < 5; k++)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				std::cin >> Clock[i][k][j];
			}
		}
	}
	
	std::vector<int> Time(4);

	for (int i = 0; i < 4; i++)
	{
		for (int Num = 0; Num < 10; Num++)
		{
			if (!CanChange(Clock[i], Nums[Num]))
			{
				continue;
			}
			Time[i] = Num;
			break;
		}
	}

	std::cout << Time[0] << Time[1] << ':' << Time[2] << Time[3];

	return 0;
}