#include <iostream>

int Data[10] = { 1,2,3,4,5,6,7,8,9,10 };
int N = 10;
int M = 5;

int main()
{
	//�������� = ���ӵ� �����͸� ��� �˰���
	//������ �����͸� �ִ� ����, ���� �����͸� ���� �������� ����

	//Data�迭���� ���� M�� ���ӵ� �κ������� ��ִ��� ���ϰ��� �Ҷ�, ��� �ؾ��ұ�?

	//for while ������ ¥���� �Ѵ�, left�� ���� ������ for������, Right�� ���ϴ� ������ while������

	int Right = 0;
	int PartialAdd = 0;
	int Answer = 0;

	for (int Left = 0; Left < N; Left++)
	{
		//�������� ���ϴ� ����
		// 1. PartialAdd �� M���� �������̴�
		// 2. Right�� ������ ���� �ʾƾ� �Ѵ�.
		while (PartialAdd < M && Right < N)
		{
			//�߿�!! ù��°���� üũ�� �ؾ��ϱ� ������

			//�ְ�
			PartialAdd += Data[Right];

			//������Ű�� ���·� �����Ѵ�.
			Right++;

			//�׷� ���⼭ ���ų� Ŭ������ ����.
		}

		//������
		if (PartialAdd == M)
		{
			Answer++;
		}

		//Left�� �����Ѵ�
		PartialAdd -= Data[Left];
	}

	//�糡�� �������� ������ ���̴� ��������
	/*int left = 0;
	int right = N - 1;
	int count = 0;

	while (left < right)
	{
		int CheckValue = Arr[left] + Arr[right];

		if (CheckValue == X)
		{
			count++;
			left++;
			right--;
		}
		else if (CheckValue < X)
		{
			left++;
		}
		else if (CheckValue > X)
		{
			right--;
		}
	}*/
	

	return 0;
}