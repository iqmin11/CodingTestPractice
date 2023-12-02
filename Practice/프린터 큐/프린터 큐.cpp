#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int main()
{
	int T, N, M;
	std::cin >> T;


	for (size_t k = 0; k < T; k++)
	{
		std::priority_queue<std::pair<int, int>> pq;

		std::cin >> N >> M;
		std::vector<int> score;
		
		score.resize(N);

		for (size_t i = 0; i < N; i++)
		{
			std::cin >> score[i];
		}

		for (size_t i = 0; i < N; i++)
		{
			pq.push({ score[i], i });
		}

		for (size_t i = 0; i < N; i++)
		{
			if (pq.top().second == M)
			{
				int a = i;
			}
			pq.pop();
		}
	}


	



	

	return 0;
}