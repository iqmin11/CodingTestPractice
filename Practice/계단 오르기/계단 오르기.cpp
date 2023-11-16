#include <iostream>
#include <vector>
#include <set>
//규칙 1. 계단은 한칸 또는 두칸씩 올라갈 수 있다.
//규칙 2. 연속 세번 한칸씩 올라가는 것은 금지된다
//규칙 3. 마지막 칸은 꼭 밟아야한다
//-> 마지막칸을 밟는 경우의 수
//1. 전전칸을 밟고 마지막칸을 밟음
//2. 전칸을 밟고 마지막칸을 밟음
//cf 전전칸 전칸 마지막칸은 금지
//그러므로 2.의 경우의 수는
// 전전전칸 전칸 마지막칸의 경우 밖에 없음

int DP[100001] = {};

int main()
{
	int N;
	std::cin >> N;
	std::vector<int> StairScore;
	StairScore.reserve(N + 1);
	StairScore.emplace_back(0);

	for (size_t i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		StairScore.emplace_back(temp);
	}

	DP[0] = 0;
	DP[1] = StairScore[1];
	DP[2] = StairScore[1] + StairScore[2];
	for (size_t i = 3; i <= N; i++)
	{
		DP[i] = std::max(DP[i - 3] + StairScore[i - 1] + StairScore[i], DP[i - 2] + StairScore[i]);
	}

	std::cout << DP[N];

	return 0;

}