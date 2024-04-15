//https://www.acmicpc.net/problem/1799

#include <iostream>
#include <vector>

int N;
std::vector<bool> IsVisit0; //ÁÂ»ó ¿ìÇÏ
std::vector<bool> IsVisit1; //¿ì»ó ÁÂÇÏ
std::vector<int> Grid;
int MaxBishopCount = INT32_MIN;
int BishopCount = 0;

void DebugRender()
{
	std::cout << "//////////////////////////////\n";
	for (size_t i = 0; i < N; i++)
	{
		for (size_t j = 0; j < N; j++)
		{
			std::cout << Grid[i * N + j];
		}
		std::cout << '\n';
	}
	std::cout << "//////////////////////////////\n";
}

void BT(int CurIndex)
{
	if (CurIndex == N * N)
	{
		MaxBishopCount = std::max(MaxBishopCount, BishopCount);
		return;
	}

	if (Grid[CurIndex] != 1)
	{
		BT(CurIndex + 1);
		return;
	}

	int CurX = CurIndex % N;
	int CurY = CurIndex / N;

	if (IsVisit0[(N - 1) - CurX + CurY] || IsVisit1[CurX + CurY])
	{
		BT(CurIndex + 1);
		return;
	}

	IsVisit0[(N - 1) - CurX + CurY] = true;
	IsVisit1[CurX + CurY] = true;
	++BishopCount;
	Grid[CurX + CurY * N] = 9;

	BT(CurIndex + 1);

	IsVisit0[(N - 1) - CurX + CurY] = false;
	IsVisit1[CurX + CurY] = false;
	--BishopCount;
	Grid[CurX + CurY * N] = 1;

	BT(CurIndex + 1);
}

int main()	
{
	std::cin >> N;

	IsVisit0.resize(2 * N);
	IsVisit1.resize(2 * N);
	Grid.resize(N * N);
	
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> Grid[i * N + j];
		}
	}

	BT(0);

	std::cout << MaxBishopCount;
	
	return 0;
}