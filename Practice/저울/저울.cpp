//https://www.acmicpc.net/problem/2437

#include <iostream>
#include <vector>
#include <algorithm>

//이 문제는 규칙을 찾는게 너무 어렵네

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
		if (Sum < Arr[i]) //다음에 올릴 추의 무게가 여태 올린 추의 무게의 합보다 크면, 연속된 무게를 못만듦
		{
			break;
		}
		Sum += Arr[i]; //가벼운것 부터 저울에 올리면서
	}

	std::cout << Sum;

	return 0;
}