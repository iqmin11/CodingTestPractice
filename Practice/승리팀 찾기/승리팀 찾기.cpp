//문제 주소 : https://www.biko.kr/problem/1693

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>

int main()
{
    int T;
    std::cin >> T;
    std::vector<std::string> Answer;
    std::vector<int> RankScore = { 0,10,8,6,5,4,3,2,1 };

    while (T-- != 0)
    {
        std::string RaceType;
        std::cin >> RaceType;
        std::priority_queue<std::pair<int, std::string>, std::vector<std::pair<int, std::string>>, std::greater<std::pair<int, std::string>>> Rank;

        for (int i = 0; i < 8; i++)
        {
            std::string Team, Time;
            std::cin >> Team >> Time;

            std::string MM_Str, SS_Str, MS_Str;
            MM_Str.push_back(Time[0]);
            SS_Str.push_back(Time[2]);
            SS_Str.push_back(Time[3]);
            MS_Str.push_back(Time[5]);
            MS_Str.push_back(Time[6]);

            int MM, SS, MS;
            MM = std::stoi(MM_Str);
            SS = std::stoi(SS_Str);
            MS = std::stoi(MS_Str);
            int RecordTime = MM * 6000 + SS * 100 + MS;

            Rank.push(std::make_pair(RecordTime, Team));
        }

        if (RaceType[0] == 'i')
        {
            Answer.push_back(Rank.top().second);
        }
        else if (RaceType[0] == 's')
        {
            int TopRecord = Rank.top().first;
            std::string TopTeam = Rank.top().second;
            int RedScore = 0;
            int BlueScore = 0;
            int CurRank = 0;
            while (!Rank.empty())
            {
                CurRank++;
                int CurTime = Rank.top().first;
                std::string CurTeam = Rank.top().second;
                Rank.pop();

                if (std::abs(CurTime - TopRecord) > 1000)
                {
                    break;
                }

                if (CurTeam[0] == 'r')
                {
                    RedScore += RankScore[CurRank];
                }
                else
                {
                    BlueScore += RankScore[CurRank];
                }
            }

            if (RedScore == BlueScore)
            {
                Answer.push_back(TopTeam);
            }
            else if (RedScore > BlueScore)
            {
                Answer.push_back("red");
            }
            else if (RedScore < BlueScore)
            {
                Answer.push_back("blue");
            }
        }
    }

    for (auto& i : Answer)
    {
        std::cout << i << std::endl;
    }

    return 0;
}