//문제 주소 : https://www.acmicpc.net/problem/9019

#include <iostream>
#include <string>
#include <queue>
#include <functional>

int Mod = 10000;

bool IsVisit[10000];
std::vector<std::string> Paths;

std::vector<std::function<int(int)>> FunctionTable;
std::vector<char> CmdTable;

void ClearVisitCheck()
{
	for (int i = 0; i < 10000; i++)
	{
		IsVisit[i] = false;
	}
}

int D(int Regi)
{
	return (Regi * 2) % Mod;
}

int S(int Regi)
{
	Regi = Regi - 1;

	if (Regi < 0)
	{
		Regi = 9999;
	}

	return Regi;
}

int L(int Regi)
{
	int Mod = Regi % 1000;
	int Quo = Regi / 1000;

	return (Mod * 10) + Quo;
}

int R(int Regi)
{
	int Mod = Regi % 10;
	int Quo = Regi / 10;

	return Quo + (Mod * 1000);
}

int T;

std::string BFS(int Start, int Dest)
{
	std::queue<int> q;
	IsVisit[Start] = true;
	q.push(Start);

	while (!q.empty())
	{
		int CurNode = q.front();
		const std::string& CurPath = Paths[CurNode];
		q.pop();

		if (CurNode == Dest)
		{
			return CurPath;
		}

		for (int i = 0; i < 4; i++)
		{
			int CheckNode;
			std::string CheckPath = CurPath;
			CheckNode = FunctionTable[i](CurNode);
			CheckPath.push_back(CmdTable[i]);

			if (IsVisit[CheckNode])
			{
				continue;
			}

			q.push(CheckNode);
			IsVisit[CheckNode] = true;
			Paths[CheckNode] = CheckPath;
		}
	}

	return std::string();
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	FunctionTable.reserve(4);
	FunctionTable.push_back(D);
	FunctionTable.push_back(S);
	FunctionTable.push_back(L);
	FunctionTable.push_back(R);
	
	CmdTable.reserve(4);
	CmdTable.push_back('D');
	CmdTable.push_back('S');
	CmdTable.push_back('L');
	CmdTable.push_back('R');
	
	std::cin >> T;

	for (int t = 0; t < T; t++)
	{
		ClearVisitCheck();
		Paths.clear();
		Paths.resize(10000);
		int Start, Dest;
		std::cin >> Start >> Dest;

		std::string Path = BFS(Start, Dest);

		std::cout << Path << '\n';
	}

	return 0;
}