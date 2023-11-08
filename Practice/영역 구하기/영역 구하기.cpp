#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <list>
//DFS 그리드 방식이 다르다네, 다른방식도 배워야겠다
//맵으로만드니까 존나느리긴함
//혼자서 2중배열로 만들어볼것

int M = 0;
int N = 0;

struct Node
{
	Node(){} // 이게 있어야 map []오퍼레이터 사용 가능

	Node(std::pair<int, int> _Pos)
		: Pos(_Pos)
	{
		SetLinkNodes();
	}

	void SetLinkNodes()
	{
		if (Pos.first + 1 < N)
			LinkNodes.insert(std::make_pair(Pos.first + 1, Pos.second));
		if (Pos.first - 1 >= 0)
			LinkNodes.insert(std::make_pair(Pos.first - 1, Pos.second));
		if (Pos.second + 1 < M)
			LinkNodes.insert(std::make_pair(Pos.first, Pos.second + 1));
		if (Pos.second - 1 >= 0)
			LinkNodes.insert(std::make_pair(Pos.first, Pos.second - 1));
	}

	std::pair<int, int> Pos = std::pair<int, int>(); // x,y int2보다 나은점->오퍼레이터를 따로 만들 필요가 없다->key값으로 사용 가능
	std::set<std::pair<int, int>> LinkNodes = std::set<std::pair<int, int>>();
	bool IsVisit = false;
};

std::map<std::pair<int, int>, Node> Grid = std::map<std::pair<int, int>, Node>();

int DFS(std::pair<int, int> _StartPos)
{
	int Count = 0;
	if (!Grid[_StartPos].IsVisit) // 현재 탐색하는 인덱스에 방문한 적이 없다면
	{
		Count++;
		Grid[_StartPos].IsVisit = true; // 방문했다고 바꾸고

		for (auto& i : Grid[_StartPos].LinkNodes) // 연결된 노드를 돌면서
		{
			Count += DFS(i); // 현재 탐색 노드를 StartIndex로한 DFS
		}
	}
	return Count;
}

int main()
{
	std::cin >> M >> N;

	//그리드 생성
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			std::pair<int, int> tempPos = std::make_pair(x, y);
			Grid.insert(std::make_pair(tempPos, Node(tempPos)));
		}
	}

	//영역 색칠
	int K;
	std::cin >> K;
	for (int i = 0; i < K; i++)
	{
		std::pair<int, int> tempMin;
		std::pair<int, int> tempMax;
		std::cin >> tempMin.first >> tempMin.second;
		std::cin >> tempMax.first >> tempMax.second;
		
		for (int y = tempMin.second; y < tempMax.second; y++)
		{
			for (int x = tempMin.first; x < tempMax.first; x++)
			{
				std::pair<int, int> tempPos = std::make_pair(x,y);
				Grid.find(tempPos)->second.IsVisit = true;
			}
		}
	}
	
	int CountTerra = 0;
	std::list<int> Sizes = std::list<int>(); //영역사이즈모음

	//모든 노드에서 DFS시작
	for (int y = 0; y < M; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int SizeOfTerra = 0; //연결된노드로 슉슉 갈때마다 카운트가 올라가는놈 (구역의 크기)
			std::pair<int, int> StartPos = std::make_pair(x, y);
			bool StartVisitValue = Grid[StartPos].IsVisit; // 시작지점이 false였는지를 저장

			if (!StartVisitValue) //DFS 처음 시작하는곳이 만약 IsVisit false면 구역 하나임
			{
				CountTerra++;
			}
			SizeOfTerra = DFS(StartPos);
			if (!StartVisitValue) //DFS 처음 시작하는곳이 IsVisit false였을 경우에만 영역사이즈를 푸시백
			{
				Sizes.push_back(SizeOfTerra);
			}
		}
	}

	std::vector<int> Sizes_vec = std::vector<int>(Sizes.begin(), Sizes.end()); //영역사이즈모음
	std::sort(Sizes_vec.begin(), Sizes_vec.end()); // 오름차순 정렬

	// 출력
	std::cout << CountTerra << std::endl;
	for (int i = 0; i < Sizes_vec.size(); i++)
	{
		std::cout << Sizes_vec[i] << " ";
	}

	return 0;
}