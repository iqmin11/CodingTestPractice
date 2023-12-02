#include <string>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int dx[] = { 1,0,-1,0 };
int dy[] = { 0,1,0,-1 };

std::vector<std::vector<bool>> IsVisit;
std::vector<std::vector<std::set<std::pair<int, int>>>> LinkNodes;

int BFS(std::pair<int, int> _Start, std::pair<int, int> _End)
{
    std::queue<std::pair<int, int>> q;
    std::vector<std::vector<int>> Depth;
    Depth.resize(IsVisit.size());
    for (int i = 0; i < Depth.size(); i++)
    {
        Depth[i].resize(IsVisit[i].size(), -1);
    }

    IsVisit[_Start.second][_Start.first] = true;
    Depth[_Start.second][_Start.first] = 0;

    q.push(_Start);

    while (!q.empty())
    {
        std::pair<int, int> CheckIndex = q.front();
        q.pop();

        for (auto& LinkNode : LinkNodes[CheckIndex.second][CheckIndex.first])
        {
            if (!IsVisit[LinkNode.second][LinkNode.first])
            {
                IsVisit[LinkNode.second][LinkNode.first] = true;
                Depth[LinkNode.second][LinkNode.first] = Depth[CheckIndex.second][CheckIndex.first] + 1;
                q.push(LinkNode);

                if (LinkNode == _End)
                {
                    return Depth[LinkNode.second][LinkNode.first];
                }
            }
        }
    }

    return -1;
}

int solution(vector<string> maps)
{
    std::pair<int, int> Start, End, Lever;
    for (int y = 0; y < maps.size(); y++)
    {
        for (int x = 0; x < maps[y].size(); x++)
        {
            char Check = maps[y][x];
            if (Check == 'S')
            {
                Start = { x,y };
            }
            else if (Check == 'L')
            {
                Lever = { x,y };
            }
            else if (Check == 'E')
            {
                End = { x,y };
            }
        }
    }

    IsVisit.resize(maps.size());
    for (int i = 0; i < maps.size(); i++)
    {
        IsVisit[i].resize(maps[i].size(), false);
    }

    LinkNodes.resize(maps.size());
    for (int i = 0; i < maps.size(); i++)
    {
        LinkNodes[i].resize(maps[i].size());
    }

    for (int y = 0; y < LinkNodes.size(); y++)
    {
        for (int x = 0; x < LinkNodes[y].size(); x++)
        {
            for (int i = 0; i < 4; i++)
            {
                int LinkX = x + dx[i];
                int LinkY = y + dy[i];
                if (LinkX < 0 || LinkY < 0 || LinkX >= LinkNodes[y].size() || LinkY >= LinkNodes.size())
                {
                    continue;
                }
                if (maps[LinkY][LinkX] == 'X')
                {
                    continue;
                }
                LinkNodes[y][x].insert(std::make_pair(LinkX, LinkY));
            }
        }
    }

    int SToL = BFS(Start, Lever);

    for (int y = 0; y < IsVisit.size(); y++)
    {
        for (int x = 0; x < IsVisit[y].size(); x++)
        {
            IsVisit[y][x] = false;
        }
    }

    int LToE = BFS(Lever, End);

    if (SToL == -1 || LToE == -1)
    {
        return -1;
    }

    return SToL + LToE;
}