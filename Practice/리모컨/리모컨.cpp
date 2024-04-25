//https://www.acmicpc.net/problem/1107

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

std::vector<bool> Remotecon; //해당 조건에맞는 숫자 찾기

bool IsPossible(int Num)
{
	std::string temp = std::to_string(Num);
	for (int i = 0; i < temp.size(); i++)
	{
		if (!Remotecon[temp[i] - '0'])
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int N, M; //N 숫자와 가장 가까운

	std::cin >> N >> M;

	Remotecon.resize(10, true);

	for (int i = 0; i < M; i++) 
	{
		int temp;
		std::cin >> temp;
		Remotecon[temp] = false;
	}

	//숫자를 찾고
	int MostNearNum = 0;

	//경우가 두개 있음
	//1. 그냥 방향 버튼만 누르는 경우
	int Case1 = std::abs(N - 100);

	//2. 가장 가까운 숫자로 간다음 방향키 버튼을 누르는 경우 
	int Case2 = static_cast<int>(std::to_string(MostNearNum).size()) + std::abs(MostNearNum - N);

	//둘중 더 적은 버튼을 누르는게 답
	int Answer = std::min(Case1, Case2);

	std::cout << Answer;

	return 0;
}