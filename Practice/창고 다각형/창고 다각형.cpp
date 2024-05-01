//문제 주소 : https://www.acmicpc.net/problem/2304

#include <iostream>
#include <map>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::map<int, int> PillarInfo;
	std::pair<int, int> HighestPillar = { -1, INT32_MIN };
	
	for (int i = 0; i < N; i++)
	{
		int Pos, Hight;
		std::cin >> Pos >> Hight;
		std::pair<int, int> PushPillar = std::make_pair(Pos, Hight);
		PillarInfo.insert(PushPillar);
		if (HighestPillar.second < PushPillar.second)
		{
			HighestPillar = PushPillar;
		}
	}

	int Answer = 0;
	auto NextPillar = PillarInfo.begin();
	const std::pair<const int, int>& Comp = HighestPillar;

	for (auto CurPillar = PillarInfo.begin(); *CurPillar != Comp; CurPillar = NextPillar)
	{
		NextPillar = CurPillar;
		++NextPillar;
		while (NextPillar->second < CurPillar->second)
		{
			++NextPillar;
			continue;
		}
		Answer += CurPillar->second * (NextPillar->first - CurPillar->first);
	}

	auto RNextPillar = PillarInfo.rbegin();
	for (auto CurPillar = PillarInfo.rbegin(); *CurPillar != Comp; CurPillar = RNextPillar)
	{
		RNextPillar = CurPillar;
		++RNextPillar;
		while (RNextPillar->second < CurPillar->second)
		{
			++RNextPillar;
			continue;
		}
		Answer += CurPillar->second * (CurPillar->first - RNextPillar->first);
	}

	Answer += HighestPillar.second;

	std::cout << Answer;

	return 0;
}