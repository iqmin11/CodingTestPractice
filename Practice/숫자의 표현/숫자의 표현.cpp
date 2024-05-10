//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/12924

#include <string>
#include <vector>

using namespace std;

int solution(int n)
{
	int right = 1;
	int PartAdd = 0;
	int count = 0;

	for (size_t left = 1; left <= n; left++)
	{
		while (PartAdd < n && right <= n)
		{
			PartAdd += right;
			right++;
		}

		if (PartAdd == n)
		{
			count++;
		}

		PartAdd -= left;
	}

	return count;
}