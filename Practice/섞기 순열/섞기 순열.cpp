//https://www.acmicpc.net/problem/2487

#include <iostream>
#include <vector>

int N;
std::vector<int> CardCount; //CardCount[a] = ī�� a�� ������ �ѹ��� ���� ����, ������ ã�� �������� -1
int ShuffleCount = 0; //���� Ƚ��
int FindCount = 0; //������ ã�� ����

void CardShuffle(std::vector<int>& Card, const std::vector<int>& Shuffle)
{
	++ShuffleCount;
	std::vector<int> temp = Card;
	for (int i = 0; i < N; i++)
	{
		Card[i] = temp[Shuffle[i]];
		if (Card[i] == i && CardCount[i] == -1) //������ ã��
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

//ī����� �ڱ⸸�� ����������, �� ī�帶�� ������ ���ϰ�, �� �������� �ּҰ������ ��ü ī���� ����
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