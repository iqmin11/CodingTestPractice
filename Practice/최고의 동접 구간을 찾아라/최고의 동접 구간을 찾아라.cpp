//巩力 林家 : https://www.biko.kr/problem/1696

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

std::vector<std::pair<int, bool>> AccessInfo; //<矫埃, (true 立加, false 辆丰)>

int main()
{
    int N;
    std::cin >> N;

    AccessInfo.reserve(2 * N);

    for (int i = 0; i < N; ++i)
    {
        std::string Start;
        std::string End;
        std::cin >> Start;
        std::cin >> End;

        std::string Start_HH_Str;
        Start_HH_Str.push_back(Start[0]);
        Start_HH_Str.push_back(Start[1]);

        std::string Start_MM_Str;
        Start_MM_Str.push_back(Start[3]);
        Start_MM_Str.push_back(Start[4]);

        int StartTime = 60 * std::stoi(Start_HH_Str) + std::stoi(Start_MM_Str);

        std::string End_HH_Str;
        End_HH_Str.push_back(End[0]);
        End_HH_Str.push_back(End[1]);

        std::string End_MM_Str;
        End_MM_Str.push_back(End[3]);
        End_MM_Str.push_back(End[4]);

        int EndTime = 60 * std::stoi(End_HH_Str) + std::stoi(End_MM_Str);

        AccessInfo.push_back(std::make_pair(StartTime, true));
        AccessInfo.push_back(std::make_pair(EndTime, false));
    }

    std::sort(AccessInfo.begin(), AccessInfo.end());
    int MaxAccessCount = INT32_MIN;
    int MaxTimeStart = 0;
    int MaxTimeEnd = 0;
    int CurCount = 0;
    bool Check = false;

    for (int i = 0; i < AccessInfo.size(); i++)
    {
        if (AccessInfo[i].second == false)
        {
            --CurCount;
        }
        else
        {
            ++CurCount;
        }

        if (CurCount > MaxAccessCount)
        {
            MaxAccessCount = CurCount;
            MaxTimeStart = AccessInfo[i].first;
            Check = true;
        }

        if (Check == true && CurCount < MaxAccessCount)
        {
            MaxTimeEnd = AccessInfo[i].first;
            Check = false;
        }

    }

    std::cout << MaxAccessCount << std::endl;

    std::string AnswerStart;
    std::string AnswerEnd;

    {
        int HH = MaxTimeStart / 60;
        int MM = MaxTimeStart % 60;
        std::string HHStr;
        if (HH >= 10)
        {
            HHStr = std::to_string(HH);
        }
        else
        {
            HHStr.resize(2, '0');
            HHStr[1] = '0' + HH;
        }

        std::string MMStr;
        if (MM >= 10)
        {
            MMStr = std::to_string(MM);
        }
        else
        {
            MMStr.resize(2, '0');
            MMStr[1] = '0' + MM;
        }

        AnswerStart = HHStr + ":" + MMStr;
    }

    {
        int HH = MaxTimeEnd / 60;
        int MM = MaxTimeEnd % 60;

        std::string HHStr;
        if (HH >= 10)
        {
            HHStr = std::to_string(HH);
        }
        else
        {
            HHStr.resize(2, '0');
            HHStr[1] = '0' + HH;
        }

        std::string MMStr;
        if (MM >= 10)
        {
            MMStr = std::to_string(MM);
        }
        else
        {
            MMStr.resize(2, '0');
            MMStr[1] = '0' + MM;
        }

        AnswerEnd = HHStr + ":" + MMStr;
    }

    std::cout << AnswerStart << " " << AnswerEnd;
    return 0;
}