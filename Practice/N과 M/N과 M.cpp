#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

int main()
{
	int N, M;

	std::cin >> N >> M;

	std::vector<int> Seq;

	Seq.resize(N);

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> Seq[i];
	}

	std::sort(Seq.begin(), Seq.end());

	std::set<std::vector<int>> Answer;
	std::vector<int> Contain;
	Contain.resize(M);

	do
	{
		for (size_t i = 0; i < M; i++)
		{
			Contain[i] = Seq[i];
		}

		Answer.insert(Contain);

	} while (std::next_permutation(Seq.begin(), Seq.end()));

	for (auto& i: Answer)
	{
		for (auto& j : i)
		{
			std::cout << j << ' ';
		}
		std::cout << '\n';
	}

	return 0;
}