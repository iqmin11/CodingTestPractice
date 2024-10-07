//문제 주소 : https://www.acmicpc.net/problem/2630

#include <iostream>
#include <vector>

int N;
std::vector<std::vector<int>> Paper;

//void DebugRenderer(std::pair<int, int> LeftTop, std::pair<int, int> RightBot)
//{
//	std::cout << "//////////////////////" << std::endl;
//	
//	for (int y = LeftTop.second; y <= RightBot.second; y++)
//	{
//		for (int x = LeftTop.first; x <= RightBot.first; x++)
//		{
//			std::cout << Paper[y][x] << ' ';
//		}
//		std::cout << std::endl;
//	}
//
//	std::cout << "//////////////////////" << std::endl;
//}

std::pair<int, int> Recursive(std::pair<int, int> LeftTop, std::pair<int, int> RightBot, int Size)
{
	int Color = Paper[LeftTop.second][LeftTop.first];

	//DebugRenderer(LeftTop, RightBot);

	if (Size == 1)
	{
		if (Color == 0)
		{
			return std::make_pair(1, 0);
		}
		else
		{
			return std::make_pair(0, 1);
		}
	}

	bool IsSame = true;

	for (int y = LeftTop.second; y <= RightBot.second; y++)
	{
		for (int x = LeftTop.first; x <= RightBot.first; x++)
		{
			if (Paper[y][x] != Color)
			{
				IsSame = false;
				break;
			}
		}

		if (!IsSame)
		{
			break;
		}
	}

	if (IsSame)
	{
		if (Color == 0)
		{
			return std::make_pair(1, 0);
		}
		else
		{
			return std::make_pair(0, 1);
		}
	}
	
	int MidX = (LeftTop.first + RightBot.first) / 2;
	int MidY = (LeftTop.second + RightBot.second) / 2;
	int HalfSize = Size / 2;
	std::pair<int, int> Result(0, 0);
	
	std::pair<int, int> temp0 = Recursive(LeftTop, std::make_pair(MidX, MidY), HalfSize);
	std::pair<int, int> temp1 = Recursive(std::make_pair(MidX + 1, LeftTop.second), std::make_pair(RightBot.first, MidY), HalfSize);
	std::pair<int, int> temp2 = Recursive(std::make_pair(LeftTop.first, MidY + 1), std::make_pair(MidX, RightBot.second), HalfSize);
	std::pair<int, int> temp3 = Recursive(std::make_pair(MidX + 1, MidY + 1), RightBot, HalfSize);

	Result.first += temp0.first;
	Result.first += temp1.first;
	Result.first += temp2.first;
	Result.first += temp3.first;

	Result.second += temp0.second;
	Result.second += temp1.second;
	Result.second += temp2.second;
	Result.second += temp3.second;

	return Result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	Paper.resize(N);
	for (int y = 0; y < N; y++)
	{
		Paper[y].resize(N);
		for (int x = 0; x < N; x++)
		{
			std::cin >> Paper[y][x];
		}
	}

	std::pair<int, int> Result = Recursive(std::make_pair(0, 0), std::make_pair(N - 1, N - 1), N);

	std::cout << Result.first << '\n' << Result.second;

	return 0;
}