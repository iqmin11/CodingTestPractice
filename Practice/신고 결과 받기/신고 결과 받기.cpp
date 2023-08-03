#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <set>

using namespace std;

class UserData //클래스를 활용하면 생각하기가 수월해진다
{
public:
    UserData() {}

    std::set<UserData*> ReportPtrs = std::set<UserData*>(); // set자료구조를 활용하여 중복데이터가 들어오지 않도록 함
    std::set<UserData*> ReportedBy_Ptr = std::set<UserData*>();
    int ReportedCount = 0;
    bool IsBaned = false;
    int ReciveMailCount = 0;
};

vector<int> solution(vector<string> id_list, vector<string> report, int k)
{
    std::unordered_map<string, UserData> UserHash;
    std::map<string, UserData*> BanList;

    //std::sort와 std::unique를 이용하면 리스트 자체 중복제거가 가능하여, report를 도는 시간을 절약할 수 있다고 함
    //근데 뭐 정렬하고 지우고 하는것도 시간이 들텐데 얼마나 효율적이려나?
    //어차피 report 리스트는 한번 도는거라서 크게 효율 차이가 있을까 싶긴함.
    //내일 테스트 해보자

    for (int i = 0; i < id_list.size(); i++)
    {
        UserHash.insert(make_pair(id_list[i], UserData()));
    }

    for (auto& i : report)
    {
        //데이터를 공백문자 기준으로 나누기
        std::string ReportUserName;
        std::string ReportedUserName;
        int SpaceIndex = 0;
        for (int j = 0; j < i.length(); j++)
        {
            if (i[j] == ' ')
            {
                SpaceIndex = j;
                break;
            }
        }

        ReportUserName = i.substr(0, SpaceIndex);
        ReportedUserName = i.substr(SpaceIndex + 1, i.size() - (SpaceIndex + 1));//abc defg 
        //이과정을 머릿속으로 계산하는게 좀 힘들었는데
        //sstream 라이브러리의 stringstream를 이용하면 편하다고함.
        //좀 자고일어나서 한번 쓱 보도록하자

        UserData& ReportUser = UserHash.find(ReportUserName)->second;
        UserData& ReportedUser = UserHash.find(ReportedUserName)->second;

        size_t PrevSize = ReportUser.ReportPtrs.size();
        ReportUser.ReportPtrs.insert(&ReportedUser);
        if (PrevSize < ReportUser.ReportPtrs.size())
        {
            ReportedUser.ReportedBy_Ptr.insert(&ReportUser);
            if (++ReportedUser.ReportedCount >= k)
            {
                ReportedUser.IsBaned = true;
                BanList.insert(make_pair(ReportedUserName, &ReportedUser));
            }
        }
    }

    for (auto& i : BanList)
    {
        for (auto& j : i.second->ReportedBy_Ptr)
        {
            j->ReciveMailCount++;
        }
    }

    vector<int> answer;

    for (std::string& i : id_list)
    {
        answer.emplace_back(UserHash[i].ReciveMailCount);
    }

    return answer;
}

int main()
{
    vector<string> id_list = { "muzi", "frodo", "apeach", "neo" };
    vector<string> report = { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" };
    int k = 2;
    std::vector<int> result = solution(id_list, report, k);
}

