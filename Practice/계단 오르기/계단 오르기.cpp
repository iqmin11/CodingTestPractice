#include <iostream>
#include <vector>
#include <set>
//��Ģ 1. ����� ��ĭ �Ǵ� ��ĭ�� �ö� �� �ִ�.
//��Ģ 2. ���� ���� ��ĭ�� �ö󰡴� ���� �����ȴ�
//��Ģ 3. ������ ĭ�� �� ��ƾ��Ѵ�
//-> ������ĭ�� ��� ����� ��
//1. ����ĭ�� ��� ������ĭ�� ����
//2. ��ĭ�� ��� ������ĭ�� ����
//cf ����ĭ ��ĭ ������ĭ�� ����
//�׷��Ƿ� 2.�� ����� ����
// ������ĭ ��ĭ ������ĭ�� ��� �ۿ� ����

int DP[100001] = {};

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> StairScore;
	StairScore.reserve(N + 1);
	StairScore.emplace_back(0);

	for (size_t i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		StairScore.emplace_back(temp);
	}

	DP[0] = 0;
	DP[1] = StairScore[1];
	DP[2] = StairScore[1] + StairScore[2];
	for (size_t i = 3; i <= N; i++)
	{
		DP[i] = std::max(DP[i - 3] + StairScore[i - 1] + StairScore[i], DP[i - 2] + StairScore[i]);
	}

	std::cout << DP[N];

	return 0;

}