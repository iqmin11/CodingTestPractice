//https://www.acmicpc.net/problem/2487

#include <iostream>
#include <vector>

int N;
std::vector<int> CardCount; //CardCount[a] = 카드 a가 궤적을 한바퀴 도는 숫자, 궤적을 찾지 못했으면 -1
int ShuffleCount = 0; //섞은 횟수
int FindCount = 0; //궤적을 찾은 갯수

void CardShuffle(std::vector<int>& Card, const std::vector<int>& Shuffle)
{
	++ShuffleCount;
	std::vector<int> temp = Card;
	for (int i = 0; i < N; i++)
	{
		Card[i] = temp[Shuffle[i]];
		if (Card[i] == i && CardCount[i] == -1) //궤적을 찾음
		{
			CardCount[i] = ShuffleCount;
			++FindCount;
		}
	}
}

long long GCD(long long left, long long right)
{
	long long Mod = left % right;
	if (Mod == 0)
	{
		return right;
	}
	return GCD(right, Mod);
}

long long LCM(long long left, long long right)
{
	return left * right / GCD(left, right);
}

//카드들은 자기만의 궤적이있음, 각 카드마다 궤적을 구하고, 그 궤적들의 최소공배수가 전체 카드의 궤적
int main()
{
	std::cin >> N;

	std::vector<int> Card;
	Card.resize(N);
	CardCount.resize(N, -1);
	
	for (int i = 0; i < N; i++)
	{
		Card[i] = i;
	}

	std::vector<int> Shuffle;
	Shuffle.resize(N);

	for (int i = 0; i < N; i++)
	{
		int temp;
		std::cin >> temp;
		Shuffle[i] = temp - 1;
	}

	while (FindCount != N)
	{
		CardShuffle(Card, Shuffle);
	}
	
	int LCMValue = CardCount[0];
	for (int i = 1; i < N; i++)
	{
		LCMValue = LCM(LCMValue, CardCount[i]);
	}

	std::cout << LCMValue;
}