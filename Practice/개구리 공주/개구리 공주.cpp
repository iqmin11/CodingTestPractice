#include <iostream>
#include <set>
#include <functional>
#include <queue>
#include <map>
//#include <unordered_set>

int N, K;
std::string Cmd;
//std::set<std::pair<int, int>> Plants;
std::multimap<int, int> Plants_SortedByX;
std::multimap<int, int> Plants_SortedByY;
std::function<bool(std::pair<int, int>, std::pair<int, int>)> IsInRange = nullptr;

bool ConditionA(std::multimap<int, int>::iterator IterX, std::multimap<int, int>::iterator IterY)
{
	if (++IterX == Plants_SortedByX.end())
	{
		return;
	}

	auto IterY = Plants_SortedByY.find(IterX->second);
	//return Cur.first <= Check.first && Cur.second <= Check.second;
}

bool ConditionB(std::pair<int, int> Cur, std::pair<int, int> Check)
{
	return Cur.first <= Check.first && Cur.second >= Check.second;
}

bool ConditionC(std::pair<int, int> Cur, std::pair<int, int> Check)
{
	return Cur.first >= Check.first && Cur.second <= Check.second;
}

bool ConditionD(std::pair<int, int> Cur, std::pair<int, int> Check)
{
	return Cur.first >= Check.first && Cur.second >= Check.second;
}

enum class Command
{
	A = 0,
	B,
	C,
	D
};

//ABCD
int dx[] = {1,1,-1,-1};
int dy[] = {1,-1,1,-1};

void Init()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
}

void Jump(std::multimap<int, int>::iterator Iter0, std::multimap<int, int>::iterator Iter1, Command Cmd)
{
	int CurPosX = Iter0->first;
	int CurPosY = Iter0->second;
	
	//1차함수

	//기울기
	int a = dx[static_cast<int>(Cmd)] / dy[static_cast<int>(Cmd)];

	//상수항
	int b = CurPosY - (a * CurPosX);

	switch (Cmd)
	{
	case Command::A:
		IsInRange = ConditionA;
		break;
	case Command::B:
		IsInRange = ConditionB;
		break;
	case Command::C:
		IsInRange = ConditionC;
		break;
	case Command::D:
		IsInRange = ConditionD;
		break;
	default:
		break;
	}

	int MinDistance = INT32_MAX;
	std::pair<int, int> MinPos = {-1, -1};
	
	int IterCount = 0;
	while (IterCount > N)
	{
		//CheckIter_SortedByX 
	}

	//for (auto i : Plants)
	//{
	//	if (!IsInRange(CurPos, i)) // i가 범위 내에 있는가
	//	{
	//		continue;
	//	}
	//	
	//	if (i.second == a*i.first + b) // i가 함수식을 만족 하는가
	//	{
	//		//거리의 최소값을 도출해야 하는 부분
	//		int CurCheck = std::abs(CurPosX - i.first) + std::abs(CurPosY - i.second);
	//		if (MinDistance > CurCheck)
	//		{
	//			MinDistance = CurCheck;
	//			MinPos = std::make_pair(i.first, i.second);
	//		}
	//	}
	//}

	if (MinPos == std::pair<int, int>(-1, -1))
	{
		return;
	}

	//Plants.erase(MinPos);
	//CurPos = MinPos;
}

int main()
{
	Init();

	std::cin >> N >> K;
	std::cin >> Cmd;

	std::multimap<int, int>::iterator CurPosIter_SortedByX;
	std::multimap<int, int>::iterator CurPosIter_SortedByY;
	int first, second;

	for (size_t i = 0; i < N; i++)
	{
		std::cin >> first >> second;

		auto tempIter0 = Plants_SortedByX.insert(std::make_pair(first, second));
		auto tempIter1 = Plants_SortedByY.insert(std::make_pair(second, first));

		if (i == 0)
		{
			CurPosIter_SortedByX = tempIter0;
			CurPosIter_SortedByY = tempIter1;
		}
	}





	std::queue<char> CmdQ;
	for (size_t i = 0; i < K; i++)
	{
		CmdQ.push(Cmd[i]);
	}

	while (!CmdQ.empty())
	{
		//std::cout << "[" << CurPos.first << "," << CurPos.second << "]" << std::endl;
		char CurCmd = CmdQ.front();
		CmdQ.pop();
		Jump(CurPosIter_SortedByX, CurPosIter_SortedByY, static_cast<Command>(CurCmd - 'A'));
	}

	//std::cout << CurPos.first << " " << CurPos.second;
}