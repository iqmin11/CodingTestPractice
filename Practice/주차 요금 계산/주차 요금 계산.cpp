#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <list>

using namespace std;

vector<int> solution(vector<int> fees, vector<string> records)
{
    std::map<std::string, std::list<std::pair<int, int>>> Record;
    int Last = 23 * 60 + 59;
    for (auto& i : records)
    {
        i[2] = ' ';

        std::stringstream ss(i);
        int hour, minute;
        std::string car, INOUT;

        ss >> hour;
        ss >> minute;
        ss >> car;
        ss >> INOUT;

        int TimeToInt = hour * 60 + minute;

        if (INOUT == "IN")
        {
            if (Record.find(car) == Record.end())
            {
                Record.insert(std::make_pair(car, std::list<std::pair<int, int>>()));
            }
            Record[car].push_back(std::make_pair(TimeToInt, Last));
        }
        else
        {
            Record[car].back().second = TimeToInt;
        }
    }

    std::vector<int> Time;
    Time.resize(Record.size());

    auto StartIter = Record.begin();

    for (int i = 0; i < Time.size(); i++)
    {
        int TimeAdd = 0;
        for (auto& j : StartIter->second)
        {
            TimeAdd += j.second - j.first;
        }
        Time[i] = TimeAdd;
        StartIter++;
    }

    std::vector<int> Fees;
    Fees.resize(Time.size());
    for (size_t i = 0; i < Fees.size(); i++)
    {
        float ParkTime = static_cast<float>(Time[i]);
        float BasicTime = static_cast<float>(fees[0]);
        float BasicFee = static_cast<float>(fees[1]);
        float UnitTime = static_cast<float>(fees[2]);
        float UnitFee = static_cast<float>(fees[3]);

        if (ParkTime < BasicTime)
        {
            Fees[i] = fees[1];
            continue;
        }

        Fees[i] = static_cast<int>(BasicFee + ceil(((ParkTime - BasicTime) / UnitTime)) * UnitFee);
    }

    return Fees;
}

int main()
{
    std::vector<int> fees = { 1, 461, 1, 10 };
    std::vector<std::string> records = { "00:00 1234 IN" };

    solution(fees, records);
    return 0;
}