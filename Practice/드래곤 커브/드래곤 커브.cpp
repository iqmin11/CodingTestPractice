//https://www.acmicpc.net/problem/15685

#include <iostream>
#include <vector>

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

int main()
{
	int N;
	std::cin >> N;

	for (size_t i = 0; i < N; i++)
	{
		int x, y, d, g;
		std::cin >> x >> y >> d >> g;
		std::pair<int, int> StartPos = std::make_pair(x,y);
		std::pair<int, int> Dir = std::make_pair(dx[d], dy[d]);
		std::vector<std::vector<std::pair<int, int>>> Generation;
		Generation[0].push_back({ 0, 0 });
		Generation[0].push_back(std::make_pair(Dir.first, Dir.second));
	}
}