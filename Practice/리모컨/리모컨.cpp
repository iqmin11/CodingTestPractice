//https://www.acmicpc.net/problem/1107

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<bool> Remotecon; //�ش� ���ǿ��´� ���� ã��

bool IsPossible(int Num)
{
	std::string temp = std::to_string(Num);
	for (int i = 0; i < temp.size(); i++)
	{
		if (!Remotecon[temp[i] - '0'])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int N, M; //N ���ڿ� ���� �����

	std::cin >> N >> M;

	Remotecon.resize(10, true);

	for (int i = 0; i < M; i++) 
	{
		int temp;
		std::cin >> temp;
		Remotecon[temp] = false;
	}

	//���ڸ� ã��
	int MostNearNum = 0;

	//��찡 �ΰ� ����
	//1. �׳� ���� ��ư�� ������ ���
	int Case1 = std::abs(N - 100);

	//2. ���� ����� ���ڷ� ������ ����Ű ��ư�� ������ ��� 
	int Case2 = static_cast<int>(std::to_string(MostNearNum).size()) + std::abs(MostNearNum - N);

	//���� �� ���� ��ư�� �����°� ��
	int Answer = std::min(Case1, Case2);

	std::cout << Answer;

	return 0;
}