//문제 주소 : https://rangsub.tistory.com/15

#include <iostream>
#include <vector>
#include <cmath>

const float PIE = 3.141592653589793238462643383279;

float Distance(std::pair<float, float> Point0, std::pair<float, float> Point1)
{
	return std::sqrtf(std::powf((Point0.first - Point1.first),2) + std::powf(Point0.second - Point1.second, 2));
}

float DotProduct(std::pair<float, float> Vector0, std::pair<float, float> Vector1)
{
	return Vector0.first * Vector1.first + Vector0.second * Vector1.second;
}

std::pair<float, float> VectorNormalize(std::pair<float, float> Vector)
{
	float Size = Distance(std::make_pair(0.f, 0.f), Vector);
	return std::make_pair(Vector.first / Size, Vector.second / Size);
}

float Rad2Deg(float Rad)
{
	return Rad * (180.f / PIE);
}

int solution(int x, int y, int r, int d, std::vector<std::vector<int>> target)
{
	std::pair<float, float> PlayerPos = std::make_pair(0.f, 0.f);
	std::pair<float, float> MousePos = std::make_pair(static_cast<float>(x), static_cast<float>(y));
	std::pair<float, float> NormalizedMouseVector = VectorNormalize(MousePos);
	int CollisionCount = 0;

	for (size_t i = 0; i < target.size(); i++)
	{
		std::pair<float, float> TargetPos = std::make_pair(target[i][0], target[i][1]);
		if (Distance(PlayerPos, TargetPos) > r)
		{
			continue;
		}

		float Radian = std::acosf(DotProduct(NormalizedMouseVector, VectorNormalize(TargetPos)));
		float Degree = Rad2Deg(Radian);
		if (std::abs(Degree) > static_cast<float>(d))
		{
			continue;
		}

		CollisionCount++;
	}

	return CollisionCount;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	solution(1, 1, 10, 60, { {15,3}, {6, 7}, {7, 5}, {-10, -10}, {-15, 30 } });

	return 0;
}