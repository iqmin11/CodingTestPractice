//https://school.programmers.co.kr/learn/courses/30/lessons/60063

#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <queue>

using namespace std;

std::set<std::set<std::pair<int, int>>> IsVisit;

int xMax, yMax;
std::pair<int, int> Dest;
int dx[] = { 1, 0, -1, 0 };
int dy[] = { 0, 1, 0, -1 };

void DebugRender(const vector<vector<int>>& Board, std::pair<int, int> CurFront, std::pair<int, int> CurBack, std::pair<int, int> CheckFront, std::pair<int, int> CheckBack, int Depth)
{
    std::cout << "//////////////////////////////////" << std::endl;
    std::cout << "Depth : " << Depth << std::endl;
    for (size_t y = 0; y < Board.size(); y++)
    {
        for (size_t x = 0; x < Board[y].size(); x++)
        {
            if (std::make_pair(x, y) == CurFront || std::make_pair(x, y) == CurBack)
            {
                std::cout << 'X' << ' ';
            }
            else
            {
                std::cout << Board[y][x] << ' ';
            }
        }
        std::cout << std::endl;
    }
    std::cout << "���������������" << "Depth : " << Depth + 1 << std::endl;
    for (size_t y = 0; y < Board.size(); y++)
    {
        for (size_t x = 0; x < Board[y].size(); x++)
        {
            if (std::make_pair(x, y) == CheckFront || std::make_pair(x, y) == CheckBack)
            {
                std::cout << 'X' << ' ';
            }
            else
            {
                std::cout << Board[y][x] << ' ';
            }
        }
        std::cout << std::endl;
    }
    std::cout << "//////////////////////////////////" << std::endl;
}

int BFS(const vector<vector<int>>& Board)
{
    std::queue<std::pair<std::set<std::pair<int, int>>, int>> q;
    std::set<std::pair<int, int>> StartPos;
    StartPos.insert(std::make_pair(0, 0));
    StartPos.insert(std::make_pair(1, 0));

    IsVisit.insert(StartPos);
    q.push(std::make_pair(StartPos, 0));

    while (!q.empty())
    {
        std::pair<int, int> FrontBody = *(q.front().first.begin());
        std::pair<int, int> BackBody = *(std::prev(q.front().first.end()));
        int CurDepth = q.front().second;
        q.pop();

        if (FrontBody == Dest || BackBody == Dest)
        {
            return CurDepth;
        }

        for (int i = 0; i < 3; i++)
        {
            if (i == 0)
            {
                //�̵�üũ
                for (int i = 0; i < 4; i++)
                {
                    int CheckFrontBodyX = FrontBody.first + dx[i];
                    int CheckFrontBodyY = FrontBody.second + dy[i];
                    int CheckBackBodyX = BackBody.first + dx[i];
                    int CheckBackBodyY = BackBody.second + dy[i];

                    if (CheckFrontBodyX < 0 || CheckFrontBodyY < 0 || CheckFrontBodyX >= xMax || CheckFrontBodyY >= yMax)
                    {
                        continue;
                    }

                    if (CheckBackBodyX < 0 || CheckBackBodyY < 0 || CheckBackBodyX >= xMax || CheckBackBodyY >= yMax)
                    {
                        continue;
                    }

                    if (Board[CheckFrontBodyY][CheckFrontBodyX] == 1 || Board[CheckBackBodyY][CheckBackBodyX] == 1)
                    {
                        continue;
                    }

                    std::set<std::pair<int, int>> CheckRobot;
                    CheckRobot.insert(std::make_pair(CheckFrontBodyX, CheckFrontBodyY));
                    CheckRobot.insert(std::make_pair(CheckBackBodyX, CheckBackBodyY));
                    auto FindIter = IsVisit.find(CheckRobot);

                    if (FindIter != IsVisit.end())
                    {
                        continue;
                    }

                    IsVisit.insert(CheckRobot);
                    q.push(std::make_pair(CheckRobot, CurDepth + 1));
                    DebugRender(Board, FrontBody, BackBody, std::make_pair(CheckFrontBodyX, CheckFrontBodyY), std::make_pair(CheckBackBodyX, CheckBackBodyY), CurDepth);
                }
            }
            else if(i != 0) 
            {
                //���� ���Ѵ�
                for (int j = 0; j < 2; j++)
                {
                    //����
                    int ZeroX = FrontBody.first;
                    int ZeroY = FrontBody.second;

                    int StartRotX = BackBody.first;
                    int StartRotY = BackBody.second;

                    if (i == 2)
                    {
                        //����
                        std::swap(ZeroX, StartRotX);
                        std::swap(ZeroY, StartRotY);
                    }

                    int DestRotX = StartRotX - ZeroX;
                    int DestRotY = StartRotY - ZeroY;

                    std::swap(DestRotX, DestRotY);
                    
                    if (j == 0)
                    {
                        //�ð� ����
                        DestRotX = -DestRotX;
                    }
                    else if (j == 1)
                    {
                        //�ݽð����
                        DestRotY = -DestRotY;
                    }

                    DestRotX += ZeroX;
                    DestRotY += ZeroY;

                    //�ٱ��ΰ�
                    if (DestRotX < 0 || DestRotY < 0 || DestRotX >= xMax || DestRotY >= yMax)
                    {
                        continue;
                    }

                    //���� �κ��� ���ΰ�
                    if (Board[DestRotY][DestRotX] == 1)
                    {
                        continue;
                    }

                    //���̿� ���� �ִ°�
                    int CheckInteruptX = StartRotX == ZeroX ? DestRotX : StartRotX;
                    int CheckInteruptY = StartRotY == ZeroY ? DestRotY : StartRotY;
                    if (Board[CheckInteruptY][CheckInteruptX] == 1)
                    {
                        continue;
                    }

                    std::set<std::pair<int, int>> CheckRobot;
                    CheckRobot.insert(std::make_pair(ZeroX, ZeroY));
                    CheckRobot.insert(std::make_pair(DestRotX, DestRotY));
                    auto FindIter = IsVisit.find(CheckRobot);

                    //�湮üũ�� �ߴ°�
                    if (FindIter != IsVisit.end())
                    {
                        continue;
                    }

                    IsVisit.insert(CheckRobot);
                    q.push(std::make_pair(CheckRobot, CurDepth + 1));
                    DebugRender(Board, FrontBody, BackBody, std::make_pair(ZeroX, ZeroY), std::make_pair(DestRotX, DestRotY), CurDepth);
                }
            }
        }
    }

    return -1;
}

int solution(vector<vector<int>> board)
{
    xMax = board.size();
    yMax = board.size();

    Dest = std::make_pair(xMax - 1, yMax - 1);
    
    int answer = BFS(board);
    return answer;
}

int main()
{
    solution({ { 0, 0, 0, 1, 1 }, { 0, 0, 0, 1, 0 }, { 0, 1, 0, 1, 1 }, { 1, 1, 0, 0, 1 }, { 0, 0, 0, 0, 0 } });
    return 0;
}