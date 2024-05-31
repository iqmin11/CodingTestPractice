//문제 주소 : https://www.biko.kr/problem/1704

#include <iostream>
#include <vector>
#include <list>
#include <queue>

int N, K;
std::list<int> ColorOrder;
std::vector<std::vector<int>> Grid;
std::vector<std::vector<bool>> IsVisit;
std::vector<std::vector<int>> RederBuffer;

void DebugRender()
{
    std::cout << "///////////////////////////" << std::endl;

    for (int y = 0; y < N; y++)
    {
        for (int x = 0; x < N; x++)
        {
            std::cout << RederBuffer[y][x] << " ";
        }
        std::cout << std::endl;
    }
 
    std::cout << "///////////////////////////" << std::endl;
}

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

int Count = 0;

void BFS(std::pair<int, int> CurPos, std::list<int>::iterator ColorIter)
{
    std::queue<std::pair<std::pair<int, int>, std::list<int>::iterator>> q;
    IsVisit[CurPos.second][CurPos.first] = true;
    Count++;
    q.push(std::make_pair(CurPos, ColorIter));
    RederBuffer[CurPos.second][CurPos.first] = 0;
    DebugRender();

    while (!q.empty())
    {
        int CurX = q.front().first.first;
        int CurY = q.front().first.second;
        std::list<int>::iterator CurColorIter = q.front().second;

        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int CheckX = CurX + dx[i];
            int CheckY = CurY + dy[i];
            std::list<int>::iterator CheckColorIter = CurColorIter;

            if (CheckX < 0 || CheckY < 0 || CheckX >= N || CheckY >= N)
            {
                continue;
            }

            if (IsVisit[CheckY][CheckX])
            {
                continue;
            }

            if (*CheckColorIter != Grid[CheckY][CheckX])
            {
                auto NextColorIter = std::next(CheckColorIter);

                while (NextColorIter != ColorOrder.end())
                {
                    if (*NextColorIter == Grid[CheckY][CheckX])
                    {
                        break;
                    }

                    ++NextColorIter;
                }

                if (NextColorIter == ColorOrder.end())
                {
                    continue;
                }

                if (*NextColorIter != Grid[CheckY][CheckX])
                {
                    continue;
                }

                CheckColorIter = NextColorIter;
            }

            q.push(std::make_pair(std::make_pair(CheckX, CheckY), CheckColorIter));
            RederBuffer[CheckY][CheckX] = 0;
            DebugRender();
            IsVisit[CheckY][CheckX] = true;
            Count++;
        }
    }

    return;
}

int main()
{
    std::cin >> N >> K;
    for (int i = 0; i < K; i++)
    {
        int temp;
        std::cin >> temp;
        ColorOrder.push_back(temp);
    }

    Grid.resize(N);
    IsVisit.resize(N);
    for (int y = 0; y < N; y++)
    {
        Grid[y].resize(N);
        IsVisit[y].resize(N, false);
        for (int x = 0; x < N; x++)
        {
            std::cin >> Grid[y][x];
        }
    }
    
    RederBuffer = Grid;

    //가장 먼저 체크해야할 색은 00에 있는 색임
    ColorOrder.push_front(Grid[0][0]);

    BFS(std::make_pair(0, 0), ColorOrder.begin());

    std::cout << Count;

    return 0;
}