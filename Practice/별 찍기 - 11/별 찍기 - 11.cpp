//문제 주소 : https://www.acmicpc.net/problem/2448

#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> Target;

void DrawRecursive(int R, std::pair<int, int> Pivot) //삼각형의 크기, 피봇(x,y)
{
	if (R == 3)
	{
		//그림 그리기
		Target[Pivot.second][Pivot.first] = '*';
		Target[Pivot.second + 1][Pivot.first - 1] = '*';
		Target[Pivot.second + 1][Pivot.first + 1] = '*';
		Target[Pivot.second + 2][Pivot.first - 2] = '*';
		Target[Pivot.second + 2][Pivot.first - 1] = '*';
		Target[Pivot.second + 2][Pivot.first] = '*';
		Target[Pivot.second + 2][Pivot.first + 1] = '*';
		Target[Pivot.second + 2][Pivot.first + 2] = '*';

		return;
	}

	int NextTriHight = R / 2;
	DrawRecursive(NextTriHight, Pivot);//가운데 위 삼각형
	DrawRecursive(NextTriHight, std::make_pair(Pivot.first - NextTriHight, Pivot.second + NextTriHight));//왼쪽 아래 삼각형
	DrawRecursive(NextTriHight, std::make_pair(Pivot.first + NextTriHight, Pivot.second + NextTriHight));//오른쪽 아래 삼각형
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	//세로 N 가로 2N - 1
	int R, C;
	std::cin >> R;
	C = 2 * R - 1;
	
	Target.resize(R);
	for (int i = 0; i < R; i++)
	{
		Target[i].resize(C, ' ');
	}

	//하나의 재귀싸이클은 삼각형 세개를 그리는 것으로 이루어져 있음.
	DrawRecursive(R, std::make_pair(R - 1, 0));

	for (int i = 0; i < R; i++)
	{
		std::cout << Target[i] << '\n';
	}

	return 0;
}