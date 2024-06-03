//문제 주소 : https://www.acmicpc.net/problem/2250

#include <iostream>
#include <vector>
#include <algorithm>

int N;
std::vector<bool> IsVisit;
std::vector<bool> IsRoot;
std::vector<std::vector<int>> LinkedNode;
std::vector<std::vector<int>> Tree; //Tree[level]은 해당 Level 노드의 Column을 정렬하여 저장

int CurColumn = 0;
void DFS(int CurIndex, int CurLevel)
{
	IsVisit[CurIndex] = true;
	if (Tree.size() <= CurLevel)
	{
		Tree.resize(CurLevel + 1);
	}

	for (int i = 0; i < 2; i++)
	{
		if (i == 1)
		{
			//중위 순회
			Tree[CurLevel].push_back(++CurColumn);
		}

		int NextNode = LinkedNode[CurIndex][i];
		
		if (NextNode == -1)
		{
			continue;
		}

		if (IsVisit[NextNode])
		{
			continue;
		}

		DFS(NextNode, CurLevel + 1);
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> N;
	IsVisit.resize(N + 1, false);
	LinkedNode.resize(N + 1, std::vector<int>(2));
	Tree.reserve(N + 1); //최대 노드 갯수의 레벨이 생길 수 있음
	IsRoot.resize(N + 1, true);

	int Sigma = (N + 1) * N / 2;

	for (int i = 1; i <= N; i++)
	{
		int CurNode;
		int LeftChild;
		int RightChild;

		std::cin >> CurNode >> LeftChild >> RightChild;
		LinkedNode[CurNode][0] = LeftChild;
		LinkedNode[CurNode][1] = RightChild;
		
		if (LeftChild != -1)
		{
			if (IsRoot[LeftChild] == true)
			{
				IsRoot[LeftChild] = false;
				Sigma -= LeftChild;
			}
		}

		if (RightChild != -1)
		{
			if (IsRoot[RightChild] == true)
			{
				IsRoot[RightChild] = false;
				Sigma -= RightChild;
			}
		}
	}

	int RootNode = Sigma;

	DFS(RootNode,1);

	int AnswerWidth = INT32_MIN;
	int AnswerRow = -1;

	for (size_t i = 1; i < Tree.size(); i++)
	{
		std::sort(Tree[i].begin(), Tree[i].end());

		int FrontColumn = Tree[i].front();
		int BackColumn = Tree[i].back();
		int CurWidth = BackColumn - FrontColumn + 1;

		if (CurWidth > AnswerWidth)
		{
			AnswerRow = i;
			AnswerWidth = CurWidth;
		}
	}
	
	std::cout << AnswerRow << " " << AnswerWidth;

	return 0;
}