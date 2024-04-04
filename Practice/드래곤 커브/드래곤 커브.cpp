//https://www.acmicpc.net/problem/15685

#include <iostream>
#include <list>
#include <set>

int dx[] = {1,0,-1,0};
int dy[] = {0,-1,0,1};

void RotateVertex(std::pair<int, int>& Vertex) // 0,0기준 회전
{
	std::pair<int, int> temp = Vertex;
	Vertex.first = -temp.second;
	Vertex.second = temp.first;
}

void MoveVertex(std::pair<int, int>& Vertex, const std::pair<int, int>& Move)
{
	Vertex.first += Move.first;
	Vertex.second += Move.second;
}

int main()
{
	int N;
	std::cin >> N;
	std::set<std::pair<int, int>> AllVertex;

	for (size_t i = 0; i < N; i++)
	{
		int x, y, d, g;
		std::cin >> x >> y >> d >> g;
		std::pair<int, int> StartPos = std::make_pair(x,y);
		std::pair<int, int> Dir = std::make_pair(dx[d], dy[d]);

		//0세대 설정
		int Generation = 0;
		std::list<std::pair<int, int>> PrevVertexs;
		std::list<std::pair<int, int>> CurVertexs;
		CurVertexs.push_back({0,0});
		CurVertexs.push_back(Dir);
		std::pair<int, int> VertexEnd = Dir;

		while (++Generation <= g)
		{
			PrevVertexs = CurVertexs;
			std::pair<int, int> RotateVertexEnd = std::pair<int, int>({ -100000, -100000 });
			for (auto& i : PrevVertexs)
			{
				std::pair<int, int> temp = i;
				RotateVertex(i);
				if (temp == VertexEnd)
				{
					RotateVertexEnd = i;
				}
			}

			//MoveVertex
			std::pair<int, int> MoveVector;
			MoveVector.first = VertexEnd.first - RotateVertexEnd.first;
			MoveVector.second = VertexEnd.second - RotateVertexEnd.second;
			for (auto& i : PrevVertexs)
			{
				MoveVertex(i, MoveVector);
				CurVertexs.push_back(i);
			}

			VertexEnd = PrevVertexs.front();
		}

		for (auto& i : CurVertexs)
		{
			i.first += StartPos.first;
			i.second += StartPos.second;
			AllVertex.insert(i);
		}
	}

	auto EndIter = AllVertex.end();
	int Count = 0;
	for (auto i : AllVertex)
	{
		bool Condition1 = AllVertex.find(std::make_pair(i.first + 1, i.second)) == EndIter;
		bool Condition2 = AllVertex.find(std::make_pair(i.first + 1, i.second + 1)) == EndIter;
		bool Condition3 = AllVertex.find(std::make_pair(i.first, i.second + 1)) == EndIter;

		if (Condition1 || Condition2 || Condition3)
		{
			continue;
		}

		Count++;
	}

	std::cout << Count;

}