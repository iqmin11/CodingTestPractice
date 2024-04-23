//https://www.acmicpc.net/problem/2437

#include <iostream>
#include <vector>
#include <algorithm>

//�� ������ ��Ģ�� ã�°� �ʹ� ��Ƴ�

int main()
{
	int N;

	std::cin >> N;

	std::vector<long long> Arr;
	Arr.resize(N);

	for (int i = 0; i < N; i++)
	{
		std::cin >> Arr[i];
	}

	std::sort(Arr.begin(), Arr.end());

	long long Sum = 1;

	for (int i = 0; i < N; i++)
	{
		if (Sum < Arr[i]) //������ �ø� ���� ���԰� ���� �ø� ���� ������ �պ��� ũ��, ���ӵ� ���Ը� ������
		{
			break;
		}
		Sum += Arr[i]; //������� ���� ���￡ �ø��鼭
	}

	std::cout << Sum;

	return 0;
}