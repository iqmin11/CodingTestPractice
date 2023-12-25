#include <iostream>

int Data[10] = { 1,2,3,4,5,6,7,8,9,10 };
int N = 10;
int M = 5;

int main()
{
	int right = 0;
	int PartAdd = 0;
	int count = 0;

	for (size_t left = 0; left < N; left++)
	{
		while (PartAdd < M && right < N)
		{
			PartAdd += Data[right];
			right++;
		}

		if (PartAdd == M)
		{
			count++;
		}

		PartAdd -= Data[left];
	}
	

	return 0;
}