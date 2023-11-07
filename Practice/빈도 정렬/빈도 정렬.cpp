#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

//다음부턴 맵을 쓸때 []오퍼레이터를 잘 써보도록 하자

int main()
{
	int N, C;
	std::cin >> N;
	std::cin >> C;

	std::map<int, int> C_frequency = std::map<int, int>(); //C의 빈도를 저장 (어떤 숫자가, 몇번)
	std::map<int, int> C_Order = std::map<int, int>(); //C의 순서를 저장
	int Order = 0; //순서 입력용

	for (size_t i = 0; i < N; i++)
	{
		int CurKey = 0;
		std::cin >> CurKey;
		std::pair<std::map<int, int>::iterator, bool> InsertResult = C_frequency.insert(std::make_pair(CurKey, 1));
		if (!InsertResult.second) // bool은 insert 성공 여부이다 성공->true
		{
			InsertResult.first->second++;
		}
		else
		{
			C_Order.insert(std::make_pair(CurKey, ++Order)); // 삽입 성공시 오더를 저장
		}
	}
	
	std::vector<std::pair<int, int>> C_frequency_Vec(C_frequency.begin(), C_frequency.end()); //복사 후 정렬용인데
	//이렇게 초기화가 가능하다고????? 개쩐다

	//for (auto& i : C_frequency)
	//{
	//	C_frequency_Vec.emplace_back(std::make_pair(i.first, i.second)); //맵을 벡터로 복사
	//}

	std::sort(C_frequency_Vec.begin(), C_frequency_Vec.end(), [=](std::pair<int, int> _left, std::pair<int, int> _right)
		{
			if (_left.second == _right.second) //빈도가 같으면
			{
				return C_Order.find(_left.first)->second < C_Order.find(_right.first)->second; //순서 오름차순
			}
			return _left.second > _right.second; //빈도 내림차수 정렬
		});

	for (size_t i = 0; i < C_frequency_Vec.size(); i++)
	{
		for (size_t j = 0; j < C_frequency_Vec[i].second; j++) //빈도만큼 돌면서
		{
			std::cout << C_frequency_Vec[i].first << " "; //출력
		}
	}

	return 0;
}