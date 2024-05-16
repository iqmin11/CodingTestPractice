//���� �ּ� : https://www.acmicpc.net/problem/15686

#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <deque>

int N, M;
std::vector<std::pair<int, int>> StartPos;
std::vector<std::pair<int, int>> ChickenPos;

//0 ~ M-1���� �ε������� ������ �ε��� ����

std::deque<int> Select;
std::vector<std::deque<int>> SelectChicken;
void BT(int CurIndex)
{
	if (Select.size() == M)
	{
		SelectChicken.push_back(Select);
		return;
	}

	for (int i = CurIndex; i < ChickenPos.size(); i++)
	{
		Select.push_back(i);
		BT(i + 1);
		Select.pop_back();
	}
}

//������ ġŲ���� �ָ� ġŲ�Ÿ��� ����
int ChickenDist(const std::deque<int>& SelectIndex)
{
	int Result = 0;
	//�� ������ ���� ����� ġŲ�� �Ÿ�
	for (int i = 0; i < StartPos.size(); i++)
	{
		int MostNear = INT32_MAX;
		for (int j = 0 ; j < SelectIndex.size(); j++)
		{
			MostNear = std::min(MostNear, std::abs(ChickenPos[SelectIndex[j]].first - StartPos[i].first) + std::abs(ChickenPos[SelectIndex[j]].second - StartPos[i].second));
		}

		Result += MostNear;
	}

	return Result;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int Check;
			std::cin >> Check;
			if (Check == 1)
			{
				StartPos.push_back(std::make_pair(j, i));
			}
			else if (Check == 2)
			{
				ChickenPos.push_back(std::make_pair(j, i));
			}
		}
	}

	//ChickenPos���� M�� ����..BT�� ��������
	BT(0);

	int Answer = INT32_MAX;

	//���� ��� �� ġŲ �Ÿ� ���
	for (auto& i : SelectChicken)
	{
		Answer = std::min(Answer, ChickenDist(i));
	}

	std::cout << Answer;
	
	return 0;
}