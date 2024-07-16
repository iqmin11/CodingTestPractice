//문제 주소 : https://www.acmicpc.net/problem/2110

#include <iostream>
#include <vector>
#include <algorithm>

bool Check(int Dist, const std::vector<int>& HouseInfo, int C)
{
	int Prev = 0;
	--C;

	for (int Next = 0; Next < HouseInfo.size(); Next++)
	{
		if (HouseInfo[Next] - HouseInfo[Prev] < Dist)
		{
			//설치 불가능
			continue;
		}

		//설치 가능
		Prev = Next;
		if (--C == 0)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, C;
	std::cin >> N >> C;

	std::vector<int> House;
	House.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> House[i];
	}

	std::sort(House.begin(), House.end());

	//이진탐색, 조건 성립하는 최대거리를 찾는다

	int Left = 1;
	int Right = House.back() - House.front();

	int Answer = INT32_MIN;

	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;

		if (Check(Mid, House, C))
		{
			//갱신하고 늘려봐
			Answer = std::max(Answer, Mid);
			Left = Mid + 1;
		}
		else //안한다면
		{
			//줄여
			Right = Mid - 1;
		}
	}

	std::cout << Answer;

	return 0;
}