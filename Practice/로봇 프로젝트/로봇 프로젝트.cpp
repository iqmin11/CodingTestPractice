//문제 주소 : https://www.acmicpc.net/problem/3649

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	while (true)
	{
		int Width, N;

		std::cin >> Width >> N;

		if (std::cin.eof())
		{
			return 0;
		}

		Width *= 10000000;

		std::vector<int> Blocks;
		Blocks.resize(N);

		for (int i = 0; i < N; i++)
		{
			std::cin >> Blocks[i];
		}

		std::sort(Blocks.begin(), Blocks.end());

		int left = 0;
		int right = N - 1;
		int CheckValue = 0;

		while (left < right)
		{
			CheckValue = Blocks[left] + Blocks[right];

			if (CheckValue == Width)
			{
				std::cout << "yes " << Blocks[left] << " " << Blocks[right] << '\n';
				break;
			}
			else if (CheckValue < Width)
			{
				left++;
			}
			else if (CheckValue > Width)
			{
				right--;
			}
		}

		if (CheckValue != Width)
		{
			std::cout << "danger" << '\n';
		}
	}
	
	return 0;
}