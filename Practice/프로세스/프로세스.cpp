//https://school.programmers.co.kr/learn/courses/30/lessons/42587

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location)
{
    std::queue<std::pair<int, int>> q;
    std::vector<int> PriorityRank;
    for (int i = 0; i < priorities.size(); i++)
    {
        PriorityRank.push_back(priorities[i]);
        q.push(std::make_pair(i, priorities[i]));
    }

    std::sort(PriorityRank.begin(), PriorityRank.end());

    int answer = 0;

    while (!q.empty())
    {
        int CurIndex = q.front().first;
        int CurPri = q.front().second;
        q.pop();

        if (CurPri == PriorityRank.back())
        {
            //½ÇÇà
            answer++;
            PriorityRank.pop_back();
            if (location == CurIndex)
            {
                return answer;
            }

            continue;
        }
        q.push(std::make_pair(CurIndex, CurPri));
    }

    return answer;
}