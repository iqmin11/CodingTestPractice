#include <string>
#include <vector>

using namespace std;

std::vector<int> IsVisit;

int RecordCount = 0;
int MaxCount = INT32_MIN;
void DFS(int& k, vector<vector<int>>& dungeons, int CurIndex)
{
    IsVisit[CurIndex] = true;
    k -= dungeons[CurIndex][1];
    ++RecordCount;

    MaxCount = std::max(MaxCount, RecordCount);

    for (int i = 0; i < IsVisit.size(); ++i)
    {
        if (IsVisit[i])
        {
            continue;
        }

        if (k < dungeons[i][0])
        {
            continue;
        }

        DFS(k, dungeons, i);
    }

    IsVisit[CurIndex] = false;
    k += dungeons[CurIndex][1];
    --RecordCount;
}

int solution(int k, vector<vector<int>> dungeons)
{
    for (int i = 0; i < dungeons.size(); ++i)
    {
        IsVisit.resize(dungeons.size(), false);
        DFS(k, dungeons, i);
    }
    int answer = MaxCount;
    return answer;
}