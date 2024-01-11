#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <queue>

using namespace std;
int N, T, M;
std::vector<int> TimeToIntTable;
int FirstBusTime;
int LastBusTime;

size_t TimeToInt(std::string _Time)
{
    _Time[2] = ' ';
    std::stringstream Time(_Time);
    int HH, MM;
    Time >> HH;
    Time >> MM;
    return HH * 60 + MM;
}

std::string IntToTime(int _Time)
{
    size_t HH, MM;

    HH = _Time / 60;
    MM = _Time % 60;

    std::string HHStr = std::string();
    std::string MMStr = std::string();

    if (HH < 10)
    {
        HHStr = to_string(0) + to_string(HH);
    }
    else
    {
        HHStr = to_string(HH);
    }

    if (MM < 10)
    {
        MMStr = to_string(0) + to_string(MM);
    }
    else
    {
        MMStr = to_string(MM);
    }
    
    std::string result = HHStr + ":" + MMStr;
    return result;
}

bool IsBus(int _Time) //이 시간에 버스타는거 성공했어?
{
    std::priority_queue<std::pair<int, int>> pq;

    for (size_t i = 0; i < TimeToIntTable.size(); i++)
    {
        pq.push(std::make_pair(-TimeToIntTable[i], 1)); //나말구 다른애들
    }
    pq.push(std::make_pair(-_Time, 0)); //나

    int Index = 0;
    int CurBusTime = FirstBusTime;
    int Vacancy = 0;
    for (size_t i = 0; i < N; ++i)
    {
        Vacancy = M; //버스가 옴
        for (size_t j = 0; j < TimeToIntTable.size() + 1; ++j)
        {
            int CurPersonTime = -pq.top().first; //지금 탈놈의 시간
            int CurID = pq.top().second; //지금 탈놈

            if (CurID == 1) //내가 탈 차례가 아니야
            {
                if (CurPersonTime <= CurBusTime && Vacancy > 0) //탔어
                {
                    pq.pop();
                    --Vacancy;
                }
                continue;
            }

            if (Vacancy > 0) //내가 탈차례야, 자리 있어?
            {
                return true;
            }

        }
        CurBusTime += T;
    }

    return false; //이럼 못타
}

string solution(int n, int t, int m, vector<string> timetable) 
{
    N = n;
    T = t;
    M = m;
    TimeToIntTable.resize(timetable.size());
    for (size_t i = 0; i < TimeToIntTable.size(); i++)
    {
        TimeToIntTable[i] = TimeToInt(timetable[i]);
    }

    std::sort(TimeToIntTable.begin(), TimeToIntTable.end());

    FirstBusTime = TimeToInt("09:00");
    LastBusTime = FirstBusTime + ((n - 1) * t);

    int Left = 0;
    int Right = LastBusTime; // 시간 기준으로 해야겠네요 Right는 마지막 버스 시간
    int Mid = 0;
    int MaxTime = INT32_MIN;

    //버스를 타도록 노력
    while (Left <= Right) //조건을 만족하는 Mid의 최대값을 찾는게 목적
    {
        //조건은 버스를 탄다임
        Mid = (Right + Left) / 2;

        if (IsBus(Mid)) //버스 탔어?
        {
            Left = Mid + 1;
            MaxTime = std::max(MaxTime, Mid);
        }
        else //못탔어?
        {
            Right = Mid - 1;
        }
    }

    return IntToTime(MaxTime);
}

int main()
{
    string a = solution(2, 10, 2, { "09:10", "09:09", "08:00" });

	return 0;
}