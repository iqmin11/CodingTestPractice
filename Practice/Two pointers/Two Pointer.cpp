#include <iostream>

int Data[10] = { 1,2,3,4,5,6,7,8,9,10 };
int N = 10;
int M = 5;

int main()
{
	//투포인터 = 연속된 데이터를 담는 알고리즘
	//오른쪽 데이터를 넣는 조건, 왼쪽 데이터를 빼는 조건으로 구성

	//Data배열에서 합이 M인 연속된 부분집합이 몇개있는지 구하고자 할때, 어떻게 해야할까?

	//for while 구조로 짜려고 한다, left를 빼는 과정은 for문으로, Right를 더하는 과정은 while문으로

	int Right = 0;
	int PartialAdd = 0;
	int Answer = 0;

	for (int Left = 0; Left < N; Left++)
	{
		//오른쪽을 더하는 조건
		// 1. PartialAdd 가 M보다 작을때이다
		// 2. Right가 범위를 넘지 않아야 한다.
		while (PartialAdd < M && Right < N)
		{
			//중요!! 첫번째부터 체크를 해야하기 때문에

			//넣고
			PartialAdd += Data[Right];

			//증가시키는 형태로 가야한다.
			Right++;

			//그럼 여기서 같거나 클때까지 돈다.
		}

		//같으면
		if (PartialAdd == M)
		{
			Answer++;
		}

		//Left를 빼야한다
		PartialAdd -= Data[Left];
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