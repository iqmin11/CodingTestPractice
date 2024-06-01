//���� �ּ� : https://www.acmicpc.net/problem/13335

#include <iostream>
#include <queue>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, BridgeLen, BridgeMaxWeight;

	std::cin >> N >> BridgeLen >> BridgeMaxWeight;

	std::vector<int> Truck;
	Truck.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Truck[i];
	}


	//��߽ð� + �ٸ����� = �����ð�
	std::queue<std::pair<int, int>> Bridge; //�����ð�, ����
	int CurTruckCount = 0;
	int CurTime = 1;
	int CurWeight = 0;

	for (int i = 0; i < N; CurTime++)
	{
		//�ٸ����� �ö���ִ� ���� ������������
		if (!Bridge.empty())
		{
			if (Bridge.front().first == CurTime)
			{
				CurWeight -= Bridge.front().second;
				CurTruckCount -= 1;
				Bridge.pop();
			}
		}

		if (CurWeight + Truck[i] > BridgeMaxWeight)
		{
			continue;
		}

		if (CurTruckCount + 1 > BridgeLen)
		{
			continue;
		}

		//�ٸ����� Ʈ���� �ö� �� ����
		Bridge.push(std::make_pair(CurTime + BridgeLen, Truck[i]));
		CurWeight += Truck[i];
		CurTruckCount += 1;

		i++;
	}

	std::cout << Bridge.back().first;

	return 0;
}