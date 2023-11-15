#include <string>
#include <vector>
#include <set>
#include <queue>

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

std::vector<std::string> GridInfo;
std::pair<int, int> BoardSize;
std::pair<int, int> StartPos;
std::pair<int, int> Goal;

struct Node
{
    Node(std::pair<int, int> _Pos)
        : Pos(_Pos)
    {
        SetLinkNode();
    }

    void SetLinkNode()
    {
        for (int i = 0; i < 4; i++)
        {
            int CheckX = Pos.first + dx[i];
            int CheckY = Pos.second + dy[i];
            if (CheckX < 0 || CheckY < 0 || CheckX >= BoardSize.first || CheckY >= BoardSize.second)
            {
                continue;
            }

            if (GridInfo[CheckY][CheckX] == 'D')
            {
                continue;
            }

            while (GridInfo[CheckY][CheckX] != 'D' 
                && CheckX >= 0 
                && CheckY >= 0 
                && CheckX < BoardSize.first 
                && CheckY < BoardSize.second)
            {
                CheckX += dx[i];
                CheckY += dy[i];
            }

            CheckX -= dx[i];
            CheckY -= dy[i];

            LinkNodes.insert(std::make_pair(CheckX, CheckY));
        }
    }

    std::pair<int, int> Pos = { -1, -1 };
    std::set<std::pair<int, int>> LinkNodes;
    bool IsVisit = false;
    int NodeType = -1;
    int Depth = 0;
};

std::vector<std::vector<Node>> Grid;

int BFS()
{
    std::queue<std::pair<int, int>> Q;
    Grid[StartPos.second][StartPos.first].IsVisit = true;
    Grid[StartPos.second][StartPos.first].Depth = 0;
    Q.push(StartPos);

    while (!Q.empty())
    {
        std::pair<int, int> CurCheckPos = Q.front();
        Q.pop();
        for (auto& LinkNode : Grid[CurCheckPos.second][CurCheckPos.first].LinkNodes)
        {
            if (!Grid[LinkNode.second][LinkNode.first].IsVisit)
            {
                Grid[LinkNode.second][LinkNode.first].IsVisit = true;
                Grid[LinkNode.second][LinkNode.first].Depth = Grid[CurCheckPos.second][CurCheckPos.first].Depth + 1;
                Q.push(LinkNode);

                if (LinkNode == Goal)
                {
                    return Grid[LinkNode.second][LinkNode.first].Depth;
                }
            }
        }
    }
    return -1; // 목적지에 다다르지 못했다는 뜻
}

int solution(std::vector<std::string> board)
{
    GridInfo = board;
    BoardSize = { board[0].length(), board.size() };

    Grid.resize(BoardSize.second);
    for (size_t i = 0; i < BoardSize.second; i++)
    {
        Grid.reserve(BoardSize.first);
    }

    for (size_t y = 0; y < BoardSize.second; y++)
    {
        for (size_t x = 0; x < BoardSize.first; x++)
        {
            Grid[y].emplace_back(std::make_pair(x,y));
            if (board[y][x] == 'R')
            {
                StartPos = { x,y };
            }
            else if (board[y][x] == 'G')
            {
                Goal = { x,y };
            }
        }
    }

    return BFS();
}

int main()
{
    
    return 0;
}