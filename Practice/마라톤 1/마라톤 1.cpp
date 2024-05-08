//문제 주소 : https://www.acmicpc.net/problem/10655

#include <iostream>
#include <cmath>
#include <vector>

int CalDist(std::pair<int, int> Start, std::pair<int, int> Dest)
{
	int Result = std::abs(Start.first - Dest.first) + std::abs(Start.second - Dest.second);
	return Result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N;
	std::cin >> N;
	std::vector<std::pair<int, int>> Points;
	Points.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Points[i].first >> Points[i].second;
	}

	int WholeDist = 0;
	int MaxDiffer = INT32_MIN;
	for (int i = 0; i < N - 2; i++)
	{
		std::pair<int, int> Point1 = Points[i];
		std::pair<int, int> Point2 = Points[i + 1];
		std::pair<int, int> Point3 = Points[i + 2];


		int Dist1 = CalDist(Point1, Point2);
		int Dist2 = CalDist(Point2, Point3);
		int Dist3 = CalDist(Point3, Point1);
		WholeDist += Dist1;
		if (i == N - 3)
		{
			WholeDist += Dist2;
		}

		MaxDiffer = std::max(MaxDiffer, std::abs(Dist1 + Dist2 - Dist3));
	}

	std::cout << WholeDist - MaxDiffer;

	return 0;
}