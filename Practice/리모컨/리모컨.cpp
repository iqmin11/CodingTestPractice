//https://www.acmicpc.net/problem/1107

#include <iostream>
#include <vector>
#include <cmath>

int N, M;
std::vector<bool> IsAbleNum;

int main()
{
	std::cin >> N >> M;
	IsAbleNum.resize(M, true);

	for (int i = 0; i < M; i++)
	{
		int temp;
		std::cin >> temp;

		IsAbleNum[temp] = false; //���峭 ����
	}

	//TODO : ���峪�� ���� ���ڷ� ���� ����� ���� �����.. ����Ž������ �����ұ�?
	//�� ������ ������ ���밪�� �ɰ�
	//���� �� �ִ� ���� ���� ����



	return 0;
}