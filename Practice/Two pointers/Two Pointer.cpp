#include <iostream>

int Data[10] = { 1,2,3,4,5,6,7,8,9,10 };
int N = 10;
int M = 5;

int main()
{
	int right = 0;
	int PartAdd = 0;
	int count = 0;

	for (size_t left = 0; left < N; left++)
	{
		while (PartAdd < M && right < N)
		{
			PartAdd += Data[right];
			right++;
		}

		if (PartAdd == M)
		{
			count++;
		}

		PartAdd -= Data[left];
	}


	//양끝을 기준으로 범위를 줄이는 투포인터
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