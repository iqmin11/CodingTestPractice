//문제 주소 : https://www.acmicpc.net/problem/15728

#include <iostream>
#include <deque>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int N, K;

	std::cin >> N >> K;

	std::deque<int> ShareCard(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> ShareCard[i];
	}
	std::sort(ShareCard.begin(), ShareCard.end());

	std::deque<int> TeamCard(N);
	for (int i = 0; i < N; i++)
	{
		std::cin >> TeamCard[i];
	}
	std::sort(TeamCard.begin(), TeamCard.end());

	for (int i = 0; i < K; i++)
	{
		int ShareValue[2];
		ShareValue[0] = ShareCard.front();
		ShareValue[1] = ShareCard.back();
		int TeamValue[2];
		TeamValue[0] = TeamCard.front();
		TeamValue[1] = TeamCard.back();
		
		int MaxValue = INT32_MIN;
		int MaxTeamIndex = -1;
		int Result[4];
		Result[0] = ShareValue[0] * TeamValue[0];
		Result[1] = ShareValue[0] * TeamValue[1];
		Result[2] = ShareValue[1] * TeamValue[0];
		Result[3] = ShareValue[1] * TeamValue[1];

		//최대값 찾기
		for (int i = 0; i < 4; i++)
		{
			if (Result[i] > MaxValue)
			{
				MaxValue = Result[i];
				MaxTeamIndex = i % 2;
			}
		}

		if (MaxTeamIndex == 0)
		{
			TeamCard.pop_front();
		}
		else
		{
			TeamCard.pop_back();
		}
	}

	int Result0 = ShareCard.front() * TeamCard.front();
	int Result1 = ShareCard.back() * TeamCard.back();

	int Answer = Result0 > Result1 ? Result0 : Result1;

	std::cout << Answer;

	return 0;
}