#include <iostream>

//반시계 +, 시계 -, 직선 0
int CCW(std::pair<int, int> Point1, std::pair<int, int> Point2, std::pair<int, int> Point3)
{
	int Scalar = (Point1.first * Point2.second + Point2.first * Point3.second + Point3.first * Point1.second)
		- (Point1.second * Point2.first + Point2.second * Point3.first + Point3.second * Point1.first);
	return Scalar;
}

//선분 교차 검증
bool Intersect(std::pair<std::pair<int, int>, std::pair<int, int>> Line1, std::pair<std::pair<int, int>, std::pair<int, int>> Line2)
{
	std::pair<int, int>& P1 = Line1.first;
	std::pair<int, int>& P2 = Line1.second;
	std::pair<int, int>& P3 = Line2.first;
	std::pair<int, int>& P4 = Line2.second;

	int P1P2 = CCW(P1, P2, P3) * CCW(P1, P2, P4);
	int P3P4 = CCW(P3, P4, P1) * CCW(P3, P4, P2);

	//분기1. 두 점이 일직선상에 존재
	if (P1P2 == 0 && P3P4 == 0)
	{
		if (P1 > P2)
		{
			std::swap(P1, P2);
		}

		if (P3 > P4)
		{
			std::swap(P3, P4);
		}

		return P3 <= P2 && P1 <= P4; //두 선분이 포개져 있는가
	}

	//일직선상에 존재하지 않는다면
	//선분 1을 기준으로 시계, 반시계 / 선분 2를 기준으로 시계, 반시계가 나오면 교차 (0이 나올수도)
	return P1P2 <= 0 && P3P4 <= 0;
}