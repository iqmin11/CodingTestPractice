#include <iostream>

int DP[100001];

int Func(int _Value)
{
	DP[1] = 0;

	for (size_t i = 2; i <= _Value; i++)
	{
		// DP[i] ���� i�� 1�� �Ǳ����� �ּ� ����Ƚ���� ����Ǵ°Ű�
		// DP[i] �� DP[i - 1] �� ����Ǿ��ִ� �ּҿ���Ƚ�� + 1 �� ����  
		DP[i] = DP[i - 1] + 1;

		// i �� 3���� ������ �������ٸ� 
		if (i % 3 == 0) 
		{
			// DP[i / 3]    
			DP[i] = std::min(DP[i], DP[i / 3] + 1);
		}

		if (i % 2 == 0)
		{
			DP[i] = std::min(DP[i], DP[i / 2] + 1);
		}										
	}

	return DP[_Value];
}

int main()
{
	//int DP(int _Parameter)


	//for (size_t i = 2; i <= 10; i++)
	//{
	//	int a = i - 1;
	//	DP[i] = DP[a] + 1;
	//	if (i % 3 == 0)
	//	{
	//		int b = i / 3;
	//		DP[i] = std::min(DP[i], DP[b] + 1);
	//	}

	//	if (i % 2 == 0)
	//	{
	//		int c = i / 2;
	//		DP[i] = std::min(DP[i], DP[c] + 1);
	//	}
	//}
	return 0;
}