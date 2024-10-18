//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/60061

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

std::set<std::pair<int, int>> PillarInfo; 
std::set<std::pair<int, int>> PanelInfo; 
bool CanBuild(int xPos, int yPos, int BuildCase)
{
    if (BuildCase == 0)
    {
        if (yPos == 0)
        {
            return true;
        }

        auto FindPillarIter = PillarInfo.find(std::make_pair(xPos, yPos - 1));
        if (FindPillarIter != PillarInfo.end())
        {
            return true;
        }

        auto FindPanelIter = PanelInfo.find(std::make_pair(xPos - 1, yPos));
        if (FindPanelIter != PanelInfo.end())
        {
            return true;
        }

        FindPanelIter = PanelInfo.find(std::make_pair(xPos, yPos));
        if (FindPanelIter != PanelInfo.end())
        {
            return true;
        }

        return false;
    }
    else
    {
        auto FindPillarIter0 = PillarInfo.find(std::make_pair(xPos, yPos - 1));
        auto FindPillarIter1 = PillarInfo.find(std::make_pair(xPos + 1, yPos - 1));
        if (FindPillarIter0 != PillarInfo.end() || FindPillarIter1 != PillarInfo.end())
        {
            return true;
        }

        auto FindPanelIter0 = PanelInfo.find(std::make_pair(xPos - 1, yPos));
        auto FindPanelIter1 = PanelInfo.find(std::make_pair(xPos + 1, yPos));

        if (FindPanelIter0 != PanelInfo.end() && FindPanelIter1 != PanelInfo.end())
        {
            return true;
        }

        return false;
    }
}

vector<vector<int>> solution(int n, vector<vector<int>> build_frame)
{
    for (int i = 0; i < build_frame.size(); i++)
    {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int BuildCase = build_frame[i][2];
        int Do = build_frame[i][3];

        if (Do == 1)
        {
            if (CanBuild(x, y, BuildCase))
            {
                if (BuildCase == 0)
                {
                    PillarInfo.insert(std::make_pair(x,y));
                }
                else
                {
                    PanelInfo.insert(std::make_pair(x, y));
                }
            }
        }
        else
        {
            if (BuildCase == 0)
            {
                PillarInfo.erase(std::make_pair(x, y));
            }
            else
            {
                PanelInfo.erase(std::make_pair(x, y));
            }

            for (auto i : PillarInfo)
            {
                if (!CanBuild(i.first, i.second, 0))
                {
                    if (BuildCase == 0)
                    {
                        PillarInfo.insert(std::make_pair(x, y));
                    }
                    else
                    {
                        PanelInfo.insert(std::make_pair(x, y));
                    }
                }
            }

            for (auto i : PanelInfo)
            {
                if (!CanBuild(i.first, i.second, 1))
                {
                    if (BuildCase == 0)
                    {
                        PillarInfo.insert(std::make_pair(x, y));
                    }
                    else
                    {
                        PanelInfo.insert(std::make_pair(x, y));
                    }
                }
            }
        }
    }

    vector<vector<int>> answer;
    answer.reserve(PanelInfo.size() + PillarInfo.size());
    for (auto i : PillarInfo)
    {
        std::vector<int> temp(3);
        temp[0] = i.first;
        temp[1] = i.second;
        temp[2] = 0;

        answer.push_back(std::move(temp));
    }

    for (auto i : PanelInfo)
    {
        std::vector<int> temp(3);
        temp[0] = i.first;
        temp[1] = i.second;
        temp[2] = 1;

        answer.push_back(std::move(temp));
    }

    std::sort(answer.begin(), answer.end(), [](const std::vector<int>& Left, const std::vector<int>& Right)
        {
            if (Left[0] == Right[0])
            {
                if (Left[1] == Right[1])
                {
                    return Left[2] < Right[2];
                }
                return Left[1] < Right[1];
            }
            return Left[0] < Right[0];
        });

    return answer;
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);

    solution(5, { {0, 0, 0, 1}, {1, 0, 0, 1}, {2, 0, 0, 1}, {3, 0, 0, 1}, 
        {4, 0, 0, 1}, {4, 1, 1, 1}, {3, 1, 1, 1}, {2, 1, 1, 1}, {1, 1, 1, 1}, 
        {0, 1, 1, 1}, {0, 0, 0, 0}, {1, 0, 0, 0}, {2, 0, 0, 0}, {3, 0, 0, 0}, {4, 0, 0, 0} });

	return 0;
}