#include <iostream>
#include <vector>
#include <map>

int main()
{
	//예시 데이터 테이블
	std::vector<std::vector<int>> DataTable =
	{
		{3, 4, 5, 6, 0, 1, 2},
		{1, 2, 3, 4, 5, 6, 0},
		{2, 3, 4, 5, 6, 0, 1},
		{6, 0, 1, 2, 3, 4, 5},
		{4, 5, 6, 0, 1, 2, 3},
		{0, 1, 2, 3, 4, 5, 6},
		{5, 6, 0, 1, 2, 3, 4},
	};

	//세번째 열(DataTable[2])을 index화 하고 싶어 => 데이터들을 색인으로 쓰겠다는 말 -> 어떻게?
	
	//이렇게
	std::map<int, std::vector<int>*> C_2Index;
	
	for (int i = 0; i < 7; i++)
	{
		C_2Index.insert(std::make_pair(DataTable[i][2], &DataTable[i]));
	}
	// => 정렬이 가능한 어떤 자료구조를 사용해도 상관 없지만, 일반적으로 B-tree 계열의 자료구조를 사용
	// 정렬이 가능한 자료구조를 사용하는 이유.
	// 1) 이진 탐색(또는 M진 탐색??)을 사용할 수 있다(검색속도 O(logN))
	// 2) 범위 기반 데이터를 찾을 수 있다
	 
	//Hash Table의 경우, 자료가 순차적으로 정렬되지 않음. 그렇기 때문에 범위 기반 데이터를 Find할 수 없다.
	//그러나 검색 속도가 O(1)이기 때문에 범위 기반 데이터를 찾을 필요 없는 Index는 Hash Table로 index화 하면 빠르다.

	//자료 Read
	//ex ) C_2가 0인 Tuple의 첫번째(C_0) 열의 자료를 갖고 오고싶어

	auto FindIter = C_2Index.find(0);
	if (FindIter == C_2Index.end())
	{
		return; // 검색 실패
	}

	std::vector<int>* FindTuple = FindIter->second;
	int& FindValue = (*FindTuple)[0];

	//자료 write
	//ex) 찾아온 자료 5를 7로 바꾸고싶어
	FindValue = 7;
}