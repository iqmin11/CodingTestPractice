//���� �ּ� : https://www.acmicpc.net/problem/2110

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
			//��ġ �Ұ���
			continue;
		}

		//��ġ ����
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

	//����Ž��, ���� �����ϴ� �ִ�Ÿ��� ã�´�

	int Left = 1;
	int Right = House.back() - House.front();

	int Answer = INT32_MIN;

	while (Left <= Right)
	{
		int Mid = (Left + Right) / 2;

		if (Check(Mid, House, C))
		{
			//�����ϰ� �÷���
			Answer = std::max(Answer, Mid);
			Left = Mid + 1;
		}
		else //���Ѵٸ�
		{
			//�ٿ�
			Right = Mid - 1;
		}
	}

	std::cout << Answer;

	return 0;
}