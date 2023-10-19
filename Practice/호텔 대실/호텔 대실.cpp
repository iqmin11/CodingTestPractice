#include <string>
#include <vector>
#include <sstream>

using namespace std;

//0 ~ 60*23+59 1380 + 59 + 10
//0 ~ 1449
//vector book[1450] 

int TimeToInt(std::string _Time)
{
    int result = 0;

    std::string Temp = _Time;
    int Hour = 0;
    int Minuet = 0;

    for (auto& i : Temp)
    {
        if (i == ':')
            i = ' ';
    }
    std::stringstream TimeData(Temp);
    TimeData >> Hour;
    TimeData >> Minuet;
    result = Hour * 60 + Minuet;
    return result;
}

std::vector<std::pair<int, int>> BookTimeToInt(vector<vector<string>> book_time)
{
    std::vector<std::pair<int, int>> result = std::vector<std::pair<int, int>>();
    result.resize(book_time.size());
    for (int i = 0; i < result.size(); i++)
    {
        int TempFirst = TimeToInt(book_time[i][0]);
        int TempSecond = TimeToInt(book_time[i][1]) + 10;
        result[i] = std::make_pair(TempFirst, TempSecond);
    }
    return result;
}

int solution(vector<vector<string>> book_time)
{
    int MAX = 0;

    std::vector<int> book = std::vector<int>();
    book.reserve(1450);

    for (int i = 0; i < book.capacity(); i++)
    {
        book.emplace_back(0);
    }

    std::vector<std::pair<int, int>> TempBookList = BookTimeToInt(book_time);
    for (int i = 0; i < TempBookList.size(); i++)
    {
        for (int j = TempBookList[i].first; j < TempBookList[i].second; j++)
        {
            book[j]++;
            if (book[j] > MAX)
                MAX = book[j];
        }
    }

    int answer = MAX;
    return answer;
}

int main()
{
}