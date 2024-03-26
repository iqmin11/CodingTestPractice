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
			return mid; // 초항 반환
		}
		else if (CheckValue < N)
		{
			left = mid + 1;
			//mid를 크게
		}
		else
		{
			right = mid - 1;
			//mid를 작게
		}
	}

	return -1;
}

int main()
{
	std::cin >> N >> L; //길이가 L이고 합이 N인것을 찾는다면? 못찾으면 -1 반환, 초항찾기

	long long Lenth = L;
	long long FirstNum = -1;

	while (Lenth <= 100) //적은 Lenth부터 체크 // 최악 100 * log 1000000000
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
