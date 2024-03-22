//https://www.acmicpc.net/problem/1389
#include <iostream>
#include <vector>
#include <map>

int N, M;
std::vector<std::vector<int>> Cost; //Cost[a][b] a���� b�� ���� ���, �������� ���� ��� INT16_MAX

std::vector<std::vector<int>> FW()
{
	std::vector<std::vector<int>> Dist = Cost; //Cost[a][b] a���� b�ΰ��� �ּҺ��

	for (size_t k = 0; k < N; k++) //���İ��� ���
	{
		for (size_t i = 0; i < N; i++) //���۳��
		{
			for (size_t j = 0; j < N; j++) //�������
			{
				//�׳� ���� ���, ���İ��� ����� ��
				Dist[i][j] = std::min(Dist[i][j], Dist[i][k] + Dist[k][j]);
			}
		}
	}

	return Dist;
}

int main()
{

	std::cin >> N >> M;
	Cost.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		Cost[i].resize(N, INT16_MAX);
	}

	for (size_t i = 0; i < N; i++)
	{
		Cost[i][i] = 0;
	}

	for (size_t i = 0; i < M; i++)
	{
		std::pair<int, int>  Pair;
		std::cin >> Pair.first >> Pair.second;
		--Pair.first;
		--Pair.second;

		Cost[Pair.first][Pair.second] = 1;
		Cost[Pair.second][Pair.first] = 1;
	}
	
	std::vector<std::vector<int>> MinDist = FW();
	std::map<int, int> Result; //��, ����
	
	for (size_t i = 0; i < N; i++)
	{
		int Sum = 0;
		for (size_t j = 0; j < N; j++)
		{
			Sum += MinDist[i][j];
		}
		Result.insert(std::make_pair(Sum, i));
	}

	std::cout << Result.begin()->second + 1;
}
