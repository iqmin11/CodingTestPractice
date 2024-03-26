//https://www.acmicpc.net/problem/1024
#include <iostream>

long long N, L;

long long BinarySearch(long long Lenth)
{
	long long left = 0;
	long long right = N;

	while (left <= right)
	{
		long long mid = (left + right) / 2;
		long long CheckValue = Lenth * (2 * mid + (Lenth - 1)) / 2;

		if (CheckValue == N)
		{
			return mid; // ���� ��ȯ
		}
		else if (CheckValue < N)
		{
			left = mid + 1;
			//mid�� ũ��
		}
		else
		{
			right = mid - 1;
			//mid�� �۰�
		}
	}

	return -1;
}

int main()
{
	std::cin >> N >> L; //���̰� L�̰� ���� N�ΰ��� ã�´ٸ�? ��ã���� -1 ��ȯ, ����ã��

	long long Lenth = L;
	long long FirstNum = -1;

	while (Lenth <= 100) //���� Lenth���� üũ // �־� 100 * log 1000000000
	{
		FirstNum = BinarySearch(Lenth);
		if (FirstNum != -1)
		{
			break;
		}
		++Lenth;
	}

	if (FirstNum == -1)
	{
		std::cout << FirstNum;
		return 0 ;
	}

	for (size_t i = 0; i < static_cast<size_t>(Lenth); i++)
	{
		std::cout << FirstNum + i << " ";
	}
}
