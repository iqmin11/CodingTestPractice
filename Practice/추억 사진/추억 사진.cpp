#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    //name과 year pairing
    std::unordered_map<string, int> NameScores;
    for (int i = 0; i < name.size(); i++)
    {
        NameScores.insert(std::make_pair(name[i], yearning[i]));
    }

    //사진 점수 배열 생성
    vector<int> answer;

    for (int i = 0; i < photo.size(); i++)
    {
        int SumPhotoScore = 0;
        for (int j = 0; j < photo[i].size(); j++)
        {
            auto FindData = NameScores.find(photo[i][j]);
            if (FindData != NameScores.end())
            {
                SumPhotoScore += FindData->second;
            }
        }
        answer.emplace_back(SumPhotoScore);
    }

    return answer;
}

int main()
{
    vector<string> name({ "may", "kein", "kain", "radi" });
    vector<int> yearning({ 5, 10, 1, 3 });
       vector<vector<string>> photo({ {"may", "kein", "kain", "radi"}, {"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}});
    std::vector<int> Result = solution(name, yearning, photo);
    
    for (size_t i = 0; i < Result.size(); i++)
    {
        std::cout << Result[i] << std::endl;
    }

    std::string a;
}



//map 탐색
//테스트 1 〉	통과(0.01ms, 4.14MB)
//테스트 2 〉	통과(0.02ms, 4.18MB)
//테스트 3 〉	통과(0.11ms, 4.18MB)
//테스트 4 〉	통과(0.07ms, 4.22MB)
//테스트 5 〉	통과(0.32ms, 4.13MB)
//테스트 6 〉	통과(0.57ms, 4.14MB)
//테스트 7 〉	통과(0.61ms, 4.14MB)
//테스트 8 〉	통과(0.49ms, 4.2MB)
//테스트 9 〉	통과(0.64ms, 4.15MB)
//테스트 10 〉	통과(1.33ms, 4.36MB)
//테스트 11 〉	통과(1.14ms, 4.39MB)
//테스트 12 〉	통과(0.86ms, 4.2MB)
//테스트 13 〉	통과(0.06ms, 4.16MB)
//테스트 14 〉	통과(0.01ms, 4.2MB)

//unordered_map 탐색
//테스트 1 〉	통과(0.02ms, 4.14MB)
//테스트 2 〉	통과(0.02ms, 4.13MB)
//테스트 3 〉	통과(0.10ms, 3.67MB)
//테스트 4 〉	통과(0.05ms, 4.2MB)
//테스트 5 〉	통과(0.20ms, 3.9MB)
//테스트 6 〉	통과(0.35ms, 3.98MB)
//테스트 7 〉	통과(0.34ms, 4.16MB)
//테스트 8 〉	통과(0.30ms, 3.96MB)
//테스트 9 〉	통과(0.39ms, 3.96MB)
//테스트 10 〉	통과(0.70ms, 4.33MB)
//테스트 11 〉	통과(0.69ms, 4.3MB)
//테스트 12 〉	통과(0.54ms, 4.14MB)
//테스트 13 〉	통과(0.06ms, 4.17MB)
//테스트 14 〉	통과(0.01ms, 4.16MB)


