#include <iostream>
#include <vector>
#include <algorithm>

unsigned long long DP[21];

int main()
{
	DP[0] = 1;
	DP[1] = 1;

	for (size_t i = 2; i <= 20; i++)
	{
		DP[i] = i * DP[i - 1];
	}

	int N, S;
	std::cin >> N >> S;
	std::vector<int> Fac;
	Fac.resize(N);
	for (int i = 0; i < N; i++)
	{
		Fac[i] = i + 1;
	}

	if (S == 1)
	{
		unsigned long long Comp;
		std::cin >> Comp;
		std::vector<int> Rank; // Rank[i] = i 랭킹의 숫자
		std::vector<int> Answer;
		Rank.resize(N + 1, 0);

		for (int i = 0; i < N; i++)
		{
			Rank[i + 1] = i + 1;
		}

		for (int i = 1; i <= N-1; i++)
		{
			unsigned long long Quo = Comp / DP[N - i];
			Comp = Comp % DP[N - i];

			Answer.push_back(Rank[Quo] + 1);

			//for (int j = Quo; j < Rank.size(); j++)
			//{
			//}
		}
	}
	else
	{
		unsigned long long count = 0;
		std::vector<int> Comp;
		std::vector<int> Rank; // Rank[i] = i 숫자의 랭킹

		Comp.reserve(N);
		Rank.resize(N+1, 0);

		for (int i = 0; i < N; i++)
		{
			int temp;
			std::cin >> temp;

			Comp.push_back(temp);
			Rank[i + 1] = i + 1;
		}

		// 1 2 3 4 5

		for (int i = 1; i <= N - 1; i++)
		{
			count += DP[N - i] * (Rank[Comp[i - 1]] - 1);
			Rank[Comp[i - 1]] = -1;
			for (int j = Comp[i - 1] + 1; j < Rank.size(); j++)
			{
				--Rank[j];
			}
		}

		count++;

		std::cout << count;
		//	DP[N - 1] * (Comp[0].Rank - 1) + 
		//	DP[N - 2] * (Comp[1].Rank - 1) + 
		//	DP[N - 3] * (Comp[2].Rank - 1) + 
		//	DP[N - 4] * (Comp[3].Rank - 1) +
		//  ... DP[N - (N-1)] * (Comp[N - (N-1)] - 1);

		
	}

	return 0;
}

//int main()
//{
//	DP[0] = 1;
//	DP[1] = 1;
//
//	for (size_t i = 2; i <= 20; i++)
//	{
//		DP[i] = i * DP[i - 1];
//	}
//
//	int N, S;
//	std::cin >> N >> S;
//	std::vector<int> Fac;
//	Fac.resize(N);
//	for (int i = 0; i < N; i++)
//	{
//		Fac[i] = i + 1;
//	}
//
//	std::vector<int> FacRev;
//	FacRev.resize(N, N + 1);
//
//	unsigned long long countMax = 1;
//
//	for (size_t i = 1; i <= N; i++)
//	{
//		countMax *= i;
//	}
//
//	if (S == 1)
//	{
//		int Comp;
//		std::cin >> Comp;
//		int count = 0;
//
//		do
//		{
//			count++;
//			if (count == Comp)
//			{
//				for (int i = 0; i < Fac.size(); i++)
//				{
//					std::cout << Fac[i] << " ";
//				}
//				break;
//			}
//
//			if (count == (countMax - Comp) + 1)
//			{
//				for (int i = 0; i < Fac.size(); i++)
//				{
//					std::cout << FacRev[i] - Fac[i] << " ";
//				}
//				break;
//			}
//
//		} while (std::next_permutation(Fac.begin(), Fac.end()));
//
//
//	}
//	else
//	{
//		unsigned long long count = 0;
//		std::vector<int> Comp;
//		std::vector<int> CompMax;
//
//		Comp.reserve(N);
//		CompMax.resize(N, N + 1);
//
//		for (int i = 0; i < N; i++)
//		{
//			int temp;
//			std::cin >> temp;
//
//			Comp.push_back(temp);
//		}
//
//		do
//		{
//			count++;
//
//			FacRev = CompMax;
//
//			for (size_t i = 0; i < FacRev.size(); i++)
//			{
//				FacRev[i] = FacRev[i] - Fac[i];
//			}
//
//			if (Comp == Fac)
//			{
//				break;
//			}
//
//			if (Comp == FacRev)
//			{
//				count = (countMax - count) + 1;
//				break;
//			}
//
//		} while (std::next_permutation(Fac.begin(), Fac.end()));
//
//		std::cout << count;
//	}
//
//	return 0;
//}