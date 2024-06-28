//문제 주소 : https://www.acmicpc.net/problem/1041

#include <iostream>
#include <vector>
#include <numeric>

int main()
{
	long long N;
	std::cin >> N;

	std::vector<long long> Dice;
	Dice.resize(6);
	long long OneMin = INT32_MAX;
	long long TwoMin = INT32_MAX;
	long long ThreeMin = INT32_MAX;
	long long OneMax = INT32_MIN;

	for (size_t i = 0; i < 6; i++)
	{
		std::cin >> Dice[i];
		OneMin = std::min(OneMin, Dice[i]);
		OneMax = std::max(OneMax, Dice[i]);
	}

	if (N == 1)
	{
		std::cout << std::accumulate(Dice.begin(), Dice.end(), 0) - OneMax;
		return 0;
	}

	TwoMin = std::min(TwoMin, Dice['A' - 'A'] + Dice['B' - 'A']);
	TwoMin = std::min(TwoMin, Dice['A' - 'A'] + Dice['E' - 'A']);
	TwoMin = std::min(TwoMin, Dice['A' - 'A'] + Dice['C' - 'A']);
	TwoMin = std::min(TwoMin, Dice['A' - 'A'] + Dice['D' - 'A']);
	TwoMin = std::min(TwoMin, Dice['F' - 'A'] + Dice['B' - 'A']);
	TwoMin = std::min(TwoMin, Dice['F' - 'A'] + Dice['E' - 'A']);
	TwoMin = std::min(TwoMin, Dice['F' - 'A'] + Dice['C' - 'A']);
	TwoMin = std::min(TwoMin, Dice['F' - 'A'] + Dice['D' - 'A']);
	TwoMin = std::min(TwoMin, Dice['B' - 'A'] + Dice['C' - 'A']);
	TwoMin = std::min(TwoMin, Dice['B' - 'A'] + Dice['D' - 'A']);
	TwoMin = std::min(TwoMin, Dice['E' - 'A'] + Dice['C' - 'A']);
	TwoMin = std::min(TwoMin, Dice['E' - 'A'] + Dice['D' - 'A']);


	ThreeMin = std::min(ThreeMin, Dice['A' - 'A'] + Dice['B' - 'A'] + Dice['C' - 'A']);
	ThreeMin = std::min(ThreeMin, Dice['A' - 'A'] + Dice['B' - 'A'] + Dice['D' - 'A']);
	ThreeMin = std::min(ThreeMin, Dice['A' - 'A'] + Dice['E' - 'A'] + Dice['C' - 'A']);
	ThreeMin = std::min(ThreeMin, Dice['A' - 'A'] + Dice['E' - 'A'] + Dice['D' - 'A']);
	ThreeMin = std::min(ThreeMin, Dice['F' - 'A'] + Dice['B' - 'A'] + Dice['C' - 'A']);
	ThreeMin = std::min(ThreeMin, Dice['F' - 'A'] + Dice['B' - 'A'] + Dice['D' - 'A']);
	ThreeMin = std::min(ThreeMin, Dice['F' - 'A'] + Dice['E' - 'A'] + Dice['C' - 'A']);
	ThreeMin = std::min(ThreeMin, Dice['F' - 'A'] + Dice['E' - 'A'] + Dice['D' - 'A']);

	std::cout << (ThreeMin * 4) + (TwoMin * ((N - 2) * 8 + 4)) + (OneMin * ((N - 2) * (N - 2) * 5 + (N - 2) * 4));
	return 0;
}