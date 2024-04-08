#include <iostream>

//�ݽð� +, �ð� -, ���� 0
int CCW(std::pair<int, int> Point1, std::pair<int, int> Point2, std::pair<int, int> Point3)
{
	int Scalar = (Point1.first * Point2.second + Point2.first * Point3.second + Point3.first * Point1.second)
		- (Point1.second * Point2.first + Point2.second * Point3.first + Point3.second * Point1.first);
	return Scalar;
}

//���� ���� ����
bool Intersect(std::pair<std::pair<int, int>, std::pair<int, int>> Line1, std::pair<std::pair<int, int>, std::pair<int, int>> Line2)
{
	std::pair<int, int>& P1 = Line1.first;
	std::pair<int, int>& P2 = Line1.second;
	std::pair<int, int>& P3 = Line2.first;
	std::pair<int, int>& P4 = Line2.second;

	int P1P2 = CCW(P1, P2, P3) * CCW(P1, P2, P4);
	int P3P4 = CCW(P3, P4, P1) * CCW(P3, P4, P2);

	//�б�1. �� ���� �������� ����
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

		return P3 <= P2 && P1 <= P4; //�� ������ ������ �ִ°�
	}

	//�������� �������� �ʴ´ٸ�
	//���� 1�� �������� �ð�, �ݽð� / ���� 2�� �������� �ð�, �ݽð谡 ������ ���� (0�� ���ü���)
	return P1P2 <= 0 && P3P4 <= 0;
}