#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy)
{
	std::priority_queue<int, vector<int>, greater<int>> pq;
	int CurCount = 0;

	for (size_t i = 0; i < enemy.size(); i++)
	{
		pq.push(enemy[i]);

		if (pq.size() > k)
		{
			CurCount += pq.top();
			pq.pop();
		}

		if (CurCount > n)
		{
			return i;
		}
	}
	return enemy.size();
}



int main()
{
	solution(10, 1, { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5 ,5 ,5 ,5 ,5 ,5 ,5 ,5 });
}