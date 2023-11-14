#include <iostream>
#include <vector>
#include <algorithm>

int N, H; //길이와 높이(동굴)
std::vector<int> UpObs; //석순
std::vector<long long> DownObs; //종유석

void Init()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
}

int main()
{
	Init();

	std::cin >> N >> H;
	UpObs.reserve(N);
	DownObs.reserve(N);

	//장애물 그리기
	for (size_t i = 0; i < N; i++)
	{
		int ObstacleSize;
		std::cin >> ObstacleSize;

		if (i % 2 == 0) //짝수 인덱스일 경우
		{
			UpObs.emplace_back(ObstacleSize);
		}
		else // 홀수 인덱스일 경우
		{
			DownObs.emplace_back(ObstacleSize);
		}
	}

	std::sort(UpObs.begin(), UpObs.end());
	std::sort(DownObs.begin(), DownObs.end());
	int MinCount = INT32_MAX;
	int SameObsPath = 1;

	for (int i = 0; i < H; i++)
	{
		long long ObstacleCount = 0;

		//동굴 인덱스(높이기준)가 i일때 i + 1(진짜 높이)이상인게 몇개?
		ObstacleCount += UpObs.end() - std::lower_bound(UpObs.begin(), UpObs.end(), i + 1);
		//i일때 동굴높이 H  - i 
		ObstacleCount += DownObs.end() - std::lower_bound(DownObs.begin(), DownObs.end(), H - i);

		if (MinCount > ObstacleCount)
		{
			MinCount = ObstacleCount;
			SameObsPath = 1;
			continue;
		}
		else if (MinCount == ObstacleCount)
		{
			SameObsPath++;
		}
	}

	std::cout << MinCount << " " << SameObsPath;

	return 0;
}