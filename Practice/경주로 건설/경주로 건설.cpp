#include <string>
#include <vector>
#include <iostream>

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

std::vector<std::vector<bool>> IsVisit;
int RecordCost = 0;
int MinCost = INT32_MAX;
int VirtualMinCost = 0;
int R, C;

std::vector<std::pair<int, int>> RecordStack;
void DFS(std::pair<int, int> _Start, const vector<vector<int>>& _Board)
{
    if (MinCost == VirtualMinCost)
    {
        return;
    }

    IsVisit[_Start.second][_Start.first] = true;
    RecordStack.emplace_back(_Start);

    int CurAddCost = 0;

    if (RecordStack.size() >= 3)
    {
        auto CompIter = RecordStack.end();
        CompIter -= 3;
        std::pair<int, int> CompValue = *CompIter;
        if (CompValue.first != _Start.first && CompValue.second != _Start.second)
        {
            CurAddCost = 500;
            RecordCost += CurAddCost;
        }
    }

    if (_Start.first == C - 1 && _Start.second == R - 1)
    {
        MinCost = std::min(MinCost, RecordCost + (static_cast<int>(RecordStack.size()) - 1) * 100);

        IsVisit[_Start.second][_Start.first] = false;
        RecordStack.pop_back();
        RecordCost -= CurAddCost;
        return;
    }

    for (int i = 0; i < 4; ++i)
    {
        int CheckX = _Start.first + dx[i];
        int CheckY = _Start.second + dy[i];

        if (CheckX < 0 || CheckY < 0 || CheckX >= C || CheckY >= R)
        {
            continue;
        }

        if (_Board[CheckY][CheckX] == 1 || IsVisit[CheckY][CheckX])
        {
            continue;
        }

        DFS(std::make_pair(CheckX, CheckY), _Board);
    }

    IsVisit[_Start.second][_Start.first] = false;
    RecordStack.pop_back();
    RecordCost -= CurAddCost;
}

int solutionDFS(vector<vector<int>> board)
{
    R = board.size();
    C = board[0].size();

    RecordStack.reserve(R * C);
    VirtualMinCost = ((R - 1 + C - 1) * 100) + 500;

    IsVisit.resize(R);
    for (int i = 0; i < R; ++i)
    {
        IsVisit[i].resize(C, false);
    }

    DFS(std::make_pair(0, 0), board);

    return MinCost;
}