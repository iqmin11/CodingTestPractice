#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<std::pair<int, int>>> DebugGrid; //x,y로 합시다
int N, k;

void DebugingFunc()
{
	//while (true)
	{
		DebugGrid.resize(N);
		std::vector<std::pair<int, int>> OneDimension;
		OneDimension.reserve(N * N);
		for (size_t y = 0; y < N; y++)
		{
			DebugGrid[y].reserve(N);
			for (size_t x = 0; x < N; x++)
			{
				std::pair<int, int> push = std::make_pair(x + 1, y + 1);
				DebugGrid[y].emplace_back(push);
				OneDimension.emplace_back(push);
			}
		}

		std::sort(OneDimension.begin(), OneDimension.end(), [](std::pair<int, int> _Left, std::pair<int, int> _Right)
			{
				int LeftMulValue = _Left.first * _Left.second;
				int RightMulValue = _Right.first * _Right.second;
				return LeftMulValue < RightMulValue;
			});

		std::vector<int> MulValue;
		MulValue.reserve(N * N);
		for (size_t i = 0; i < OneDimension.size(); i++)
		{
			MulValue.emplace_back(OneDimension[i].first * OneDimension[i].second);
			std::cout << "(" << OneDimension[i].first << "," << OneDimension[i].second << ")";
		}

		std::cout << std::endl;

		for (size_t i = 0; i < MulValue.size(); i++)
		{
			std::cout << "(" << MulValue[i] << ")";
		}

		std::cout << std::endl;

		for (size_t i = 0; i < MulValue.size(); i++)
		{
			std::cout << "(" << i + 1 << ")";
		}

		std::cout << std::endl;
	}
}

uint64_t Check(const uint64_t& _Value)
{
}

int main()
{
	std::cin >> N >> k;
	DebugingFunc();
	
	uint64_t Left = 0;
	uint64_t Right = N * N - 1;
	uint64_t Mid = 0;

	while (Left >= Right)
	{
		Mid = (Right + Left) / 2;

		if (k == Mid)
		{

		}

		if (k < Mid)
		{
			Left = Mid + 1;
		}

		if (k > Mid)
		{
			Right = Mid - 1;
		}
	}


	return 0;
}