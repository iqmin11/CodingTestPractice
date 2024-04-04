//https://school.programmers.co.kr/learn/courses/30/lessons/172927

#include <string>
#include <vector>
#include <stack>
#include <list>
#include <numeric>
#include <map>

using namespace std;

std::deque<int> RecordStack;
std::list<std::deque<int>> AllCases;
int N; //사용할 Pick의 개수

void DFS(int CurPick, vector<int>& IsVisit)
{
    IsVisit[CurPick] -= 1;
    RecordStack.push_back(CurPick);

    if (RecordStack.size() == N)
    {
        AllCases.push_back(RecordStack);
        IsVisit[CurPick] += 1;
        RecordStack.pop_back();
        return;
    }

    for (size_t i = 0; i < 3; i++)
    {
        if (IsVisit[i] == 0)
        {
            continue;
        }
        
        DFS(i, IsVisit);
    }

    IsVisit[CurPick] += 1;
    RecordStack.pop_back();
}

std::vector<std::map<char, int>> ScoreTable;

int solution(vector<int> picks, vector<string> minerals) 
{
    N = std::min(((static_cast<int>(minerals.size()) - 1) / 5) + 1, std::accumulate(picks.begin(), picks.end(), 0));

    ScoreTable.resize(3);
    ScoreTable[0]['d'] = 1;
    ScoreTable[0]['i'] = 1;
    ScoreTable[0]['s'] = 1;
    ScoreTable[1]['d'] = 5;
    ScoreTable[1]['i'] = 1;
    ScoreTable[1]['s'] = 1;
    ScoreTable[2]['d'] = 25;
    ScoreTable[2]['i'] = 5;
    ScoreTable[2]['s'] = 1;

    for (size_t i = 0; i < 3; i++)
    {
        if (picks[i] == 0)
        {
            continue;
        }

        DFS(i, picks);
    }

    int MinScore = INT32_MAX;
    for (auto i : AllCases)
    {
        int CurIndex = 0;
        int Score = 0;
        while (!i.empty())
        {
            int CurPick = i.front();
            i.pop_front();

            for (size_t j = 0; j < 5 && CurIndex < minerals.size(); j++)
            {
                Score += ScoreTable[CurPick][minerals[CurIndex++].front()];
            }
        }
        MinScore = std::min(MinScore, Score);
    }

    return MinScore;
}

int main()
{
    solution({ 0, 1, 1 }, { "diamond", "diamond", "diamond", "diamond", "diamond", "iron", "iron", "iron", "iron", "iron", "diamond" });
}
