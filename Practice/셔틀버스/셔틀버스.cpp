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

bool IsBus(int _Time) //�� �ð��� ����Ÿ�°� �����߾�?
{
    std::priority_queue<std::pair<int, int>> pq;

    for (size_t i = 0; i < TimeToIntTable.size(); i++)
    {
        pq.push(std::make_pair(-TimeToIntTable[i], 1)); //������ �ٸ��ֵ�
    }
    pq.push(std::make_pair(-_Time, 0)); //��

    int Index = 0;
    int CurBusTime = FirstBusTime;
    int Vacancy = 0;
    for (size_t i = 0; i < N; ++i)
    {
        Vacancy = M; //������ ��
        for (size_t j = 0; j < TimeToIntTable.size() + 1; ++j)
        {
            int CurPersonTime = -pq.top().first; //���� Ż���� �ð�
            int CurID = pq.top().second; //���� Ż��

            if (CurID == 1) //���� Ż ���ʰ� �ƴϾ�
            {
                if (CurPersonTime <= CurBusTime && Vacancy > 0) //����
                {
                    pq.pop();
                    --Vacancy;
                }
                continue;
            }

            if (Vacancy > 0) //���� Ż���ʾ�, �ڸ� �־�?
            {
                return true;
            }

        }
        CurBusTime += T;
    }

    return false; //�̷� ��Ÿ
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
    int Right = LastBusTime; // �ð� �������� �ؾ߰ڳ׿� Right�� ������ ���� �ð�
    int Mid = 0;
    int MaxTime = INT32_MIN;

    //������ Ÿ���� ���
    while (Left <= Right) //������ �����ϴ� Mid�� �ִ밪�� ã�°� ����
    {
        //������ ������ ź����
        Mid = (Right + Left) / 2;

        if (IsBus(Mid)) //���� ����?
        {
            Left = Mid + 1;
            MaxTime = std::max(MaxTime, Mid);
        }
        else //������?
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