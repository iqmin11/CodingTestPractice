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

		IsAbleNum[temp] = false; //고장난 숫자
	}

	//TODO : 고장나지 않은 숫자로 가장 가까운 숫자 만들기.. 이진탐색으로 가능할까?
	//비교 기준은 차이의 절대값이 될것
	//만들 수 있는 가장 작은 값은



	return 0;
}