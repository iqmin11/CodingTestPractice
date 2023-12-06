#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	int N, S;
	std::cin >> N >> S;
	std::vector<int> Fac;
	Fac.resize(N);
	for (int i = 0; i < N; i++)
	{
		Fac[i] = i + 1;
	}

	std::vector<int> FacRev;
	FacRev.resize(N, N + 1);

	unsigned long long countMax = 1;

	for (size_t i = 1; i <= N; i++)
	{
		countMax *= i;
	}

	if (S == 1)
	{
		int Comp;
		std::cin >> Comp;
		int count = 0;

		do
		{
			count++;
			if (count == Comp)
			{
				for (int i = 0; i < Fac.size(); i++)
				{
					std::cout << Fac[i] << " ";
				}
				break;
			}

			if (count == (countMax - Comp) + 1)
			{
				for (int i = 0; i < Fac.size(); i++)
				{
					std::cout << FacRev[i] - Fac[i] << " ";
				}
				break;
			}

		} while (std::next_permutation(Fac.begin(), Fac.end()));


	}
	else
	{
		unsigned long long count = 0;
		std::vector<int> Comp;
		std::vector<int> CompMax;

		Comp.reserve(N);
		CompMax.resize(N, N + 1);

		for (int i = 0; i < N; i++)
		{
			int temp;
			std::cin >> temp;

			Comp.push_back(temp);
		}

		do
		{
			count++;

			FacRev = CompMax;
		
			for (size_t i = 0; i < FacRev.size(); i++)
			{
				FacRev[i] = FacRev[i] - Fac[i];
			}

			if (Comp == Fac)
			{
				break;
			}

			if (Comp == FacRev)
			{
				count = (countMax - count) + 1;
				break;
			}

		} while (std::next_permutation(Fac.begin(), Fac.end()));

		std::cout << count;
	}

	return 0;
}