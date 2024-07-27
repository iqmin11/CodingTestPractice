#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	//���� ���� ������ 1�� �ƴϸ� 0��
	//1���� ���Ҵٸ�, 0�� �ִٸ�... 0�̶� ����
	//0�� ������ ����
	//1�� �������� �ڱ� �ڽ��� ������ ������ �׳� ���δ°� �� ū ������.

	int N;
	std::cin >> N;

	//(����)�� (0), (���)�� ������...
	std::priority_queue<int> Plus;
	std::priority_queue<int, std::vector<int>, std::greater<int>> Minus;
	std::priority_queue<int> Zero;
	std::priority_queue<int> One;

	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		if (temp < 0)
		{
			Minus.push(temp);
		}
		else if (temp > 1)
		{
			Plus.push(temp);
		}
		else if (temp == 1)
		{
			One.push(temp);
		}
		else
		{
			Zero.push(temp);
		}
	}

	//�����ϰ�, ���밪�� ū�𳢸� ���� ���ϰ�..
	int Answer = 0;
	std::vector<int> temp(2);

	while (Minus.size() >= 2)
	{
		int Loop = 2;
		while (Loop-- > 0)
		{
			temp[Loop] = Minus.top();
			Minus.pop();
		}

		Answer += temp[0] * temp[1];
	}

	if (!Minus.empty() && !Zero.empty())
	{
		Minus.pop();
		Zero.pop();
	}

	while (Plus.size() >= 2)
	{
		int Loop = 2;
		while (Loop-- > 0)
		{
			temp[Loop] = Plus.top();
			Plus.pop();
		}

		Answer += temp[0] * temp[1];
	}

	while (!Minus.empty())
	{
		Answer += Minus.top();
		Minus.pop();
	}

	while (!Plus.empty())
	{
		Answer += Plus.top();
		Plus.pop();
	}

	while (!One.empty())
	{
		Answer += One.top();
		One.pop();
	}

	std::cout << Answer;

	return 0;
}