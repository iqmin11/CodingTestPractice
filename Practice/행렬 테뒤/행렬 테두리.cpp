//https://school.programmers.co.kr/learn/courses/30/lessons/77485

#include <iostream>
#include <string>
#include <vector>

using namespace std;

std::vector<std::vector<int>> Grid;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int Rotation(const vector<int>& Querie)
{
    int StartY = Querie[0] - 1;
    int StartX = Querie[1] - 1;
    int EndY = Querie[2] - 1;
    int EndX = Querie[3] - 1;

    int Temp = Grid[StartY][StartX];
    int MinValue = Temp;

    int CurCheckX = StartX;
    int CurCheckY = StartY;

    for (int i = 0; i < 4; i++)
    {
        while (true)
        {
            int NextX = CurCheckX + dx[i];
            int NextY = CurCheckY + dy[i];

            if (StartX > NextX || EndX < NextX || StartY > NextY || EndY < NextY)
            {
                break;
            }

            MinValue = std::min(MinValue, Grid[CurCheckY][CurCheckX]);
            Grid[CurCheckY][CurCheckX] = Grid[NextY][NextX];

            CurCheckX = NextX;
            CurCheckY = NextY;
        }
    }

    Grid[StartY][StartX + 1] = Temp;

    return MinValue;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries)
{
    Grid.resize(rows);

    int index = 1;
    for (int i = 0; i < rows; ++i)
    {
        Grid[i].resize(columns);
        for (int j = 0; j < columns; ++j)
        {
            Grid[i][j] = index++;
        }
    }

    vector<int> answer;
    for (int i = 0; i < queries.size(); ++i)
    {
        answer.push_back(Rotation(queries[i]));
    }

    return answer;
}