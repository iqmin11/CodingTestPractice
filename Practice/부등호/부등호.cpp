//문제 주소 : https://www.acmicpc.net/problem/2529

#include <iostream>
#include <deque>
#include <vector>
#include <map>
#include <functional>

int k;
std::vector<char> Cmd;
int Size;
std::map<char, std::function<bool(int, int)>> FunctionTable;
bool UseNumTable[10] = { false, };

std::deque<int> Path;
std::deque<std::string> AllPath;
void BT(int CurCheckIndex)
{
	if (Size == Path.size())
	{
		AllPath.push_back(std::string());
		for (auto i : Path)
		{
			AllPath.back().push_back(i + '0');
		}
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		if (UseNumTable[i] == true)
		{
			continue;
		}

		if (!Path.empty())
		{
			if (!FunctionTable[Cmd[CurCheckIndex]](Path.back(), i))
			{
				continue;
			}
		}

		Path.push_back(i);
		UseNumTable[i] = true;
		BT(CurCheckIndex + 1);
		UseNumTable[i] = false;
		Path.pop_back();
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	std::cin >> k;
	Size = k + 1;

	for (int i = 0; i < k; i++)
	{
		char temp;
		std::cin >> temp;
		Cmd.push_back(temp);
	}

	FunctionTable.insert(std::make_pair('<', [](int Left, int Right)
		{
			return Left < Right;
		}));

	FunctionTable.insert(std::make_pair('>', [](int Left, int Right)
		{
			return Left > Right;
		}));

	BT(-1);

	std::cout << AllPath.back() << '\n';
	std::cout << AllPath.front();
	
	return 0;
}