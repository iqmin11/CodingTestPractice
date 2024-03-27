#include <iostream>
#include <vector>
#include <queue>

int Data[10][10] =
{
	{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 1, 0, 2, 3, 4, 5, 6, 7, 8, 9 },
	{ 2, 2, 0, 3, 4, 5, 6, 7, 8, 9 },
	{ 3, 3, 3, 0, 4, 5, 6, 7, 8, 9 },
	{ 4, 4, 4, 4, 0, 5, 6, 7, 8, 9 },
	{ 5, 5, 5, 5, 5, 0, 6, 7, 8, 9 },
	{ 6, 6, 6, 6, 6, 6, 0, 7, 8, 9 },
	{ 7, 7, 7, 7, 7, 7, 7, 0, 8, 9 },
	{ 8, 8, 8, 8, 8, 8, 8, 8, 0, 9 },
	{ 9, 9, 9, 9, 9, 9, 9, 9, 9, 0 },
};

std::priority_queue<std::pair<long long, std::pair<int, int>>> EdgeInfo; //Cost, 연결 노드 정보 (최소 코스트 간선부터 그리디하게 돌기 때문에 pq를 사용)
std::vector<int> Parent; //사실상 자기가 속한 집합의 이름
//(Parent[a] = b) -> a가 속한 집합은 b이다...인데 정확하게 그걸 뜻하는것은 아니고, 진짜 소속을 찾기 위해서는 Find함수를 만들어야함

int FindParent(int Value) //재귀식으로 탐색하여 가장 뿌리 집합을 찾아줌
{
	if (Parent[Value] == Value) //인덱스와 값이 같으면 초기에 설정한 뿌리집합
	{
		return Value;
	}
	Parent[Value] = FindParent(Parent[Value]); //다르다면 뿌리집합을 찾을때까지 재귀
	return Parent[Value];
}

void Union(int FirstParent, int SecondParent) //나는 FindParent를 두번하는것이 마음에 들지 않아서 아예 인자로 Parent를 받게 하였습니다.
{
	//그냥 Union하고자 하는 원소를 인자로 받고, 안에서 Parent를 찾아준 후 설정하는것도 가능하지만, 어차피 이전단계에서 Parent는 찾아 놓아야함
	if (FirstParent < SecondParent) //일관된 규칙으로 합집합 연산을 해야하나???
	{
		Parent[SecondParent] = FirstParent;
	}
	else
	{
		Parent[FirstParent] = SecondParent;
	}
}

void MST_Kruskal(int N) //간선의 개수
{
	int EdgeCount = 0;
	while (!EdgeInfo.empty() && EdgeCount < N - 1)
	{
		int CheckCost = -EdgeInfo.top().first;
		int FirstNode = EdgeInfo.top().second.first;
		int SecondNode = EdgeInfo.top().second.second;
		EdgeInfo.pop();

		int FirstParent = FindParent(FirstNode);
		int SecondParent = FindParent(SecondNode);
		if (FirstParent != SecondParent) //이과정에서 어차피 Find를 해줘야함. 두 원소가 서로소 관계인지 아닌지 파악하는 부분, 서로소라면 순회하지않기때문에
		{
			Union(FirstParent, SecondParent); //두 집합을 합치고
			
			//간선을 연결하게됨
			//여기서 목적으로 하고있는 연산을 진행하면 됩니다. 간선을 모은다던지, 최소코스트를 계산한다던지..
			++EdgeCount;
		}
	}
}

int main()
{
	Parent.resize(10); //노드의 개수만큼 생성

	for (int i = 0; i < 10; i++)
	{
		Parent[i] = i; //뿌리집합 설정
		for (int j = 0; j < i; j++)
		{
			EdgeInfo.push(std::make_pair(-Data[i][j], std::make_pair(i, j))); //오름차순 정렬을 위해 코스트를 -Data로 입력
		}
	}

	MST_Kruskal(10);
}