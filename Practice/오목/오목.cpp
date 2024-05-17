//���� �ּ� : https://www.acmicpc.net/problem/2615

#include <iostream>
#include <vector>
#include <set>

std::vector<std::vector<int>> Grid;
std::vector<std::vector<std::vector<bool>>> IsVisit;

//���ʺ��� �˻縦�ؾߵƱ� ������ set���� ����
std::set<std::pair<int, int>> BlackPos;
std::set<std::pair<int, int>> WhitePos;

//���ʿ��� ���������� Ž�� ������ ���
//�̷��� �ϸ� ���� ������ �׻� ���� ������ ��
int dx[] = { 0, 1, 1, 1 };
int dy[] = { 1, 1, 0, -1 };

int Depth = 0;
bool IsWin[3] = {false, false, false};
void DFS(std::pair<int, int> CurPos, int CheckColor, int PrevDir = -1)
{
	//�ٵϵ��� ������������ �׹����� �� üũ�� ���̱� ������ �׹����� �� true�� �湮üũ��
	if (PrevDir == -1)
	{
		for (int i = 0; i < 4; i++)
		{
			IsVisit[CurPos.second][CurPos.first][i] = true;
		}
	}
	else
	{
		IsVisit[CurPos.second][CurPos.first][PrevDir] = true;
	}

	Depth++;

	bool IsEnd = true;

	for (int Dir = 0; Dir < 4; Dir++)
	{
		if(PrevDir != -1) //�������̸� �׹��� �� üũ �ؾ���
		{
			if (PrevDir != Dir) //�������� �ƴϸ� ���� ���⸸ üũ
			{
				continue;
			}
		}

		int CheckX = CurPos.first + dx[Dir];
		int CheckY = CurPos.second + dy[Dir];

		if (CheckX < 0 || CheckY < 0 || CheckX >= 19 || CheckY >= 19)
		{
			continue;
		}

		if (IsVisit[CheckY][CheckX][Dir]) //������ ����� �湮üũ
		{
			continue;
		}

		if (Grid[CheckY][CheckX] != CheckColor)
		{
			continue;
		}

		//������ ������ ���κ��� �ƴϾ�
		IsEnd = false;
		DFS(std::make_pair(CheckX, CheckY), CheckColor, Dir);
	}

	if (IsEnd) //�� �� ���� ���ٸ� Ž���� ���� ���� �� �κ��̶�� ��
	{
		if (Depth == 5) // �׶��� ���̰� 5���
		{
			IsWin[CheckColor] = true; //�̰��
		}
	}

	Depth--;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

	Grid.resize(19);
	IsVisit.resize(19);
	for (int y = 0; y < 19; y++)
	{
		Grid[y].resize(19, 0);
		IsVisit[y].resize(19);
		for (int x = 0; x < 19; x++)
		{
			//������ ����� �湮üũ(4����)
			IsVisit[y][x].resize(4, false);
			std::cin >> Grid[y][x];
			if (Grid[y][x] == 1)
			{
				BlackPos.insert(std::make_pair(x, y));
			}
			else if (Grid[y][x] == 2)
			{
				WhitePos.insert(std::make_pair(x, y));
			}
		}
	}

	for (auto i : BlackPos)
	{
		//������ �湮üũ�� ������µ� ������ ����..?

		DFS(i, 1);
		if (IsWin[1])
		{
			std::cout << 1 << "\n";
			std::cout << i.second + 1 << " " << i.first + 1;
			break;
		}
	}

	for (auto i : WhitePos)
	{
		//������ �湮üũ�� ������µ� ������ ����..?

		DFS(i, 2);
		if (IsWin[2])
		{
			std::cout << 2 << "\n";
			std::cout << i.second + 1 << " " << i.first + 1;
			break;
		}
	}

	if (IsWin[1] == false && IsWin[2] == false)
	{
		std::cout << 0 << "\n";
	}

	return 0;
}