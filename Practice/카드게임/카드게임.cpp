//문제 주소 : https://www.acmicpc.net/problem/2621

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	int NumCount[10] = {};
	std::map<char, int> ColorCount;
	ColorCount.insert(std::make_pair('R', 0));
	ColorCount.insert(std::make_pair('B', 0));
	ColorCount.insert(std::make_pair('Y', 0));
	ColorCount.insert(std::make_pair('G', 0));

	std::vector<std::string> Cards;
	
	for (int i = 0; i < 5; i++)
	{
		Cards.push_back(std::string());
		for (int j = 0; j < 2; j++)
		{
			char temp;
			std::cin >> temp;
			Cards[i].push_back(temp);
		}

		//색
		++ColorCount[Cards[i][0]];

		//숫자
		++NumCount[Cards[i][1] - '0'];
	}

	std::sort(Cards.begin(), Cards.end(), [](const std::string& Left, const std::string& Right)
		{
			return Left[1] < Right[1];
		});

	int TopNum = Cards[4][1] - '0';

	int FourCardCount = 0;
	int FourCardNum = -1;
	int TripleCount = 0;
	int TripleCardNum = -1;
	int PairCount = 0;
	std::vector<int> PairCardNum;

	for (int i = 1; i < 10; i++)
	{
		if (NumCount[i] == 4)
		{
			FourCardCount++;
			FourCardNum = i;
		}
		else if (NumCount[i] == 3)
		{
			TripleCount++;
			TripleCardNum = i;
		}
		else if (NumCount[i] == 2)
		{
			PairCount++;
			PairCardNum.push_back(i);
		}
	}

	bool IsFlush = false;

	for (auto Count : ColorCount)
	{
		if (Count.second == 5)
		{
			IsFlush = true;
		}
	}

	bool IsStraight = true;

	for (int i = 1; i < 5; i++)
	{
		if (Cards[i][1] - Cards[i - 1][1] != 1)
		{
			IsStraight = false;
			break;
		}
	}

	int Score = 0;

	if (IsFlush && IsStraight) // 스트레이트 플러쉬
	{
		Score = 900 + TopNum;
	}
	else if (FourCardCount == 1) // 포카드
	{
		Score = 800 + FourCardNum;
	}
	else if (PairCount == 1 && TripleCount == 1) // 풀하우스
	{
		Score = 700 + TripleCardNum * 10 + PairCardNum[0];
	}
	else if (IsFlush) // 플러쉬
	{
		Score = 600 + TopNum;
	}
	else if (IsStraight) // 스트레이트
	{
		Score = 500 + TopNum;
	}
	else if (TripleCount == 1) // 트리플
	{
		Score = 400 + TripleCardNum;
	}
	else if (PairCount == 2) // 투페어
	{
		Score = 300 + PairCardNum[1] * 10 + PairCardNum[0];
	}
	else if (PairCount == 1) // 원페어
	{
		Score = 200 + PairCardNum[0];
	}
	else // 탑
	{
		Score = 100 + TopNum;
	}

	std::cout << Score;

	return 0;
}