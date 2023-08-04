#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

// sstream을 대략적으로 사용해본것에 의의가 있음. sstream의 사용 또는 자료 관리 방법에 대해서도 알아야 하지만
// cout등에 쓰이는 << >> 연산자에 대해서 (stl안에서는 c스타일의 비트연산자랑은 좀 다른 의미를 가진것같음)도 공부를 해야함
// 객체지향을 좀 남용한것같기도하고.. 생각은 편했는데 오래걸린것같기도 함.
// 안에서 오류를 잡을때 항상 내가 정리한 자료구조를 체크할 수 있는 cout debuging 기능을 만드는게 좋은것같아. 코테 안에서는 저것만한게 없긴 한 것 같음
// 왠만한 자료구조들을 모두 순회하면서 할 수 있지 않을까?
// 코드를 너무 많이 치면서 오류를 잡지 말고 코드 실행은 자주 눌러 오류 체크를 할 수 있도록 하자

class Date
{
public:
    Date() {}
    Date(const std::string& _Date)
    {
        std::string Temp = _Date;
        for (auto& i : Temp)
        {
            if (i == '.')
            {
                i = ' ';
            }
        }
        std::stringstream DateData(Temp);
        DateData >> YYYY;
        DateData >> MM;
        DateData >> DD;
    }

    int DateToInt() const
    {
        return YYYY * 12 * 28 + (MM - 1) * 28 + DD;
    }

    int YYYY = 0;
    int MM = 0;
    int DD = 0;
};

class terms_obj
{
public:
    static std::map<string, int> terms_Datamap;
    terms_obj() {}
    terms_obj(const std::string& _terms)
    {
        std::stringstream termData(_terms);

        std::string Name;
        int period;

        termData >> Name;
        termData >> period;

        terms_Datamap.insert(std::make_pair(Name, period));
    }

    static int PeriodToInt(const std::string& _TermsName)
    {
        return terms_Datamap.find(_TermsName)->second * 28;
    }
};

std::map<string, int> terms_obj::terms_Datamap;


class priveacies_obj
{
public:
    static int Index;
    static std::vector<int> result;
    priveacies_obj() {}
    priveacies_obj(const std::string& _Data, const Date& _Today)
    {
        Index++;
        std::string Temp = _Data;
        for (auto& i : Temp)
        {
            if (i == '.')
            {
                i = ' ';
            }
        }
        std::stringstream priveaciesData(Temp);
        priveaciesData >> CollectingDate.YYYY;
        priveaciesData >> CollectingDate.MM;
        priveaciesData >> CollectingDate.DD;
        priveaciesData >> termsName;

        if (!IsValid(_Today))
        {
            result.emplace_back(Index);
        }
    }

    bool IsValid(const Date& _Today)
    {
        return CollectingDate.DateToInt() + terms_obj::PeriodToInt(termsName) - 1 >= _Today.DateToInt();
    }

    Date CollectingDate = Date();
    std::string termsName;
};

int priveacies_obj::Index = 0;;
std::vector<int> priveacies_obj::result;

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    Date Date_Today(today);
    for (auto& i : terms)
    {
        terms_obj Temp(i);
    }

    std::vector<priveacies_obj> privaciesData;
    privaciesData.reserve(privacies.size());

    for (auto& i : privacies)
    {
        privaciesData.emplace_back(i, Date_Today);
    }

    return priveacies_obj::result;
}

int main()
{
    string today = "2022.05.19";
    vector<string> terms = { "A 6", "B 12", "C 3" };
    vector<string> privacies = { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" };

    solution(today,terms,privacies);
}

