//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/152995

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// 과업의 점수가 (a,b)
// a과업 기준으로, b과업의 최대값을 보관

std::unordered_map<int, int> MaxScoreInfo1;
std::unordered_map<int, int> MaxScoreInfo2;

int solution(vector<vector<int>> scores)
{
    for (int i = 0; i < scores.size(); i++)
    {
        MaxScoreInfo1[scores[i][0]] = std::max(MaxScoreInfo1[scores[i][0]], scores[i][1]);
        MaxScoreInfo2[scores[i][1]] = std::max(MaxScoreInfo2[scores[i][1]], scores[i][0]);
    }

    std::unordered_map<int, int>* MaxScoreInfo;

    if (MaxScoreInfo1.size() > MaxScoreInfo2.size())
    {
        MaxScoreInfo = &MaxScoreInfo2;

        for (int i = 0; i < scores.size(); i++)
        {
            std::swap(scores[i][0], scores[i][1]);
        }
    }
    else
    {
        MaxScoreInfo = &MaxScoreInfo1;
    }

    std::vector<std::pair<int, int>> SortingArr; //점수, 인덱스
    SortingArr.reserve(scores.size());

    for (int i = 0; i < scores.size(); i++)
    {
        bool Check = true;

        for (auto& j : *MaxScoreInfo)
        {
            if (j.first > scores[i][0] && j.second > scores[i][1])
            {
                Check = false;

                if (i == 0)
                {
                    return -1;
                }
                break;
            }
        }

        if (Check)
        {
            SortingArr.push_back(std::make_pair(scores[i][0] + scores[i][1], i));
        }
    }

    std::sort(SortingArr.begin(), SortingArr.end(), std::greater<std::pair<int, int>>());

    int Rank = 1;
    int PrevScore = SortingArr[0].first;

    for (int i = 0; i < SortingArr.size(); i++)
    {
        if (PrevScore > SortingArr[i].first)
        {
            Rank = i + 1;
        }

        PrevScore = SortingArr[i].first;

        if (SortingArr[i].second == 0)
        {
            break;
        }
    }

    return Rank;
}

int main()
{
    std::vector<vector<int>> TimeCheck;
    TimeCheck.resize(100000, std::vector<int>(2));
    for (int i = 0; i < TimeCheck.size(); i++)
    {
        TimeCheck[i][0] = i;
        TimeCheck[i][1] = 100000 - i;
    }

    int a = solution(TimeCheck);

    return 0;
}