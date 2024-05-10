//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/154540

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

std::vector<std::vector<bool>> IsVisit;
std::vector<std::string> Grid;

int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

int XSize = 0;
int YSize = 0;

int DFS(std::pair<int, int> CurIndex)
{
    IsVisit[CurIndex.second][CurIndex.first] = true;
    int Result = Grid[CurIndex.second][CurIndex.first] - '0';

    for (int i = 0; i < 4; i++)
    {
        int CheckX = CurIndex.first + dx[i];
        int CheckY = CurIndex.second + dy[i];

        if (CheckX < 0 || CheckY < 0 || CheckX >= XSize || CheckY >= YSize)
        {
            continue;
        }

        if (IsVisit[CheckY][CheckX])
        {
            continue;
        }

        if (Grid[CheckY][CheckX] == 'X')
        {
            continue;
        }

        Result += DFS(std::make_pair(CheckX, CheckY));
    }

    return Result;
}

vector<int> solution(vector<string> maps)
{
    Grid = maps;
    YSize = Grid.size();
    XSize = Grid[0].size();
    IsVisit.resize(YSize);
    for (int y = 0; y < YSize; y++)
    {
        IsVisit[y].resize(XSize, false);
    }

    vector<int> answer;
    for (int y = 0; y < YSize; y++)
    {
        for (int x = 0; x < XSize; x++)
        {
            if (IsVisit[y][x] || Grid[y][x] == 'X')
            {
                continue;
            }

            answer.push_back(DFS(std::make_pair(x, y)));
        }
    }

    if (answer.empty())
    {
        return { -1 };
    }

    std::sort(answer.begin(), answer.end());
    return answer;
}