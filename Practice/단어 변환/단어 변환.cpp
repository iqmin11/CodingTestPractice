//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/43163

#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

std::map<std::string, bool> IsVisit;

int BFS(const std::string& StartIndex, const std::string& DestIndex)
{
    std::queue<std::string> q;
    IsVisit[StartIndex] = true;
    q.push(StartIndex);
    std::map<std::string, int> Depth;
    Depth[StartIndex] = 0;

    while (!q.empty())
    {
        std::string CurNode = q.front();
        q.pop();

        if (CurNode == DestIndex)
        {
            return Depth[CurNode];
        }

        for (auto i : IsVisit)
        {
            std::string CheckIndex = i.first;
            int DifferCount = 0;
            for (int j = 0; j < CheckIndex.size(); j++)
            {
                if (CheckIndex[j] != CurNode[j])
                {
                    DifferCount++;
                }
            }

            if (DifferCount != 1)
            {
                continue;
            }

            if (IsVisit[CheckIndex])
            {
                continue;
            }

            IsVisit[CheckIndex] = true;
            Depth[CheckIndex] = Depth[CurNode] + 1;
            q.push(CheckIndex);
        }
    }

    return 0;
}

int solution(string begin, string target, vector<string> words)
{
    for (auto i : words)
    {
        IsVisit[i] = false;
    }
    int answer = BFS(begin, target);
    return answer;
}