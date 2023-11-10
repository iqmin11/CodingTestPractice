#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);

	size_t N;
	std::cin >> N;

	std::vector<int> v0;
	v0.resize(N);
	for (size_t i = 0; i < N; i++)
	{
		std::cin >> v0[i];
	}
	std::sort(v0.begin(), v0.end());

	size_t M;
	std::cin >> M;
	for (size_t i = 0; i < M; i++)
	{
		int find;
		std::cin >> find;
		std::cout << std::binary_search(v0.begin(), v0.end(), find) << '\n';
	}

	return 0;
}