//https://www.acmicpc.net/problem/17386

#include <iostream>

//반시계 +, 시계 -, 직선 0
long long CCW(std::pair<long long, long long> Point1, std::pair<long long, long long> Point2, std::pair<long long, long long> Point3)
{
	long long Scalar = (Point1.first * Point2.second + Point2.first * Point3.second + Point3.first * Point1.second)
		 - (Point1.second * Point2.first + Point2.second * Point3.first + Point3.second * Point1.first);
	return Scalar;
}

bool Intersect(std::pair<std::pair<long long, long long>, std::pair<long long, long long>> Line1, std::pair<std::pair<long long, long long>, std::pair<long long, long long>> Line2)
{
	std::pair<long long, long long>& P1 = Line1.first;
	std::pair<long long, long long>& P2 = Line1.second;
	std::pair<long long, long long>& P3 = Line2.first;
	std::pair<long long, long long>& P4 = Line2.second;

	//조건 1. 선분 1을 기준으로 시계, 반시계 / 선분 2를 기준으로 시계, 반시계가 나오면 교차
	long long P1P2Condition1 = CCW(P1, P2, P3);
	long long P1P2Condition2 = CCW(P1, P2, P4);

	long long P3P4Condition1 = CCW(P3, P4, P1);
	long long P3P4Condition2 = CCW(P3, P4, P2);

	//두 점이 일직선상에 존재
	if ((P1P2Condition1 == 0 || P1P2Condition2 == 0) && (P3P4Condition1 == 0 || P3P4Condition2 == 0))
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

	return !((P1P2Condition1 > 0 && P1P2Condition2 > 0) || (P1P2Condition1 < 0 && P1P2Condition2 < 0))
		&& !((P3P4Condition1 > 0 && P3P4Condition2 > 0) || (P3P4Condition1 < 0 && P3P4Condition2 < 0));
}

int main()
{
	std::pair<std::pair<long long, long long>, std::pair<long long, long long>> Line1;
	std::pair<std::pair<long long, long long>, std::pair<long long, long long>> Line2;

	std::cin >> Line1.first.first >> Line1.first.second >> Line1.second.first >> Line1.second.second;
	std::cin >> Line2.first.first >> Line2.first.second >> Line2.second.first >> Line2.second.second;

	std::cout << Intersect(Line1, Line2);

	return 0;
}