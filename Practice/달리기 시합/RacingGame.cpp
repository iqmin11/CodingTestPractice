#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

//1. 벡터에 있는 players 데이터를 해쉬 테이블에 저장
//2. Calling에서 불린 player를 해쉬에서 검색하고 인덱스를 가지고오고 수정
//3. 인덱스 접근을 통해서 바로 스왑하고 앞순위였던 플레이어를 다시 해쉬맵에서 검색
//4. 바뀌었으니까 안에 저장되어있는 인덱스를 수정해줌을 반복

vector<string> solution(vector<string> players, vector<string> callings)
{
    vector<string> answer = players;
    map<string, int> PlayersHash;

    for (size_t i = 0; i < players.size(); i++)
    {
        PlayersHash.insert(make_pair(players[i], i));
    }

    for (int i = 0; i < callings.size(); i++)
    {
        auto FindData = PlayersHash.find(callings[i]);
        int FindIndex = -1;
        int SwapIndex = -1;
        std::string FindStr;
        std::string SwapStr;

        if (FindData != PlayersHash.end())
        {
            FindStr = FindData->first;
            FindIndex = FindData->second;
            SwapIndex = FindIndex-1;
            SwapStr = answer[SwapIndex];
            FindData->second = SwapIndex;
        }

        string Temp = std::move(answer[FindIndex]);
        answer[FindIndex] = std::move(answer[SwapIndex]);
        answer[SwapIndex] = std::move(Temp);

        FindData = PlayersHash.find(SwapStr);
        if (FindData != PlayersHash.end())
        {
            FindData->second = FindIndex;
        }
    }
    return answer;
}

//vector<string> Wrongsolution(vector<string> players, vector<string> callings)
//{
//    vector<string> answer = players;
//    unordered_map<string, int> SaveData;
//
//    for (int i = 0; i < callings.size(); i++)
//    {
//        auto FindData = SaveData.find(callings[i]);
//        if (FindData != SaveData.end()) //아래의 탐색방식을 보완하기 위해 이미 찾은 데이터를 인덱스와 같이 저장하고 맵에서 검색하는 방법을 시도했으나 오답
//        {
//            int FindIndex = FindData->second;
//            std::string Temp = std::move(answer[FindIndex]);
//            answer[FindIndex] = std::move(answer[FindIndex - 1]);
//            answer[FindIndex - 1] = std::move(Temp);
//            SaveData[answer[FindIndex - 1]] = FindIndex - 1;
//            continue;
//        }
//
//        for (int j = 0; j < answer.size(); j++) //선형 탐색알고리즘이라는 이름, 이 탐색 방식은 극단적인 상황에서 매우 비효율적임
//        {
//            if (callings[i] == answer[j])
//            {
//                std::string Temp = std::move(answer[j]);
//                answer[j] = std::move(answer[j - 1]);
//                answer[j - 1] = std::move(Temp);
//                SaveData[answer[j - 1]] = j - 1;
//                break;
//            }
//        }
//    }
//    return answer;
//}


//swap함수를 만들때 std::move를 이용하면 편함.
//A = std::move(B) B가 가리키고있는 메모리의 오너쉽을 B에서 A로 바꿔줌

//탐색방식에서의 비효율을 개선하기위해 탐색알고리즘을 공부
//Hash 탐색이 빠르고, stl에 있는 Hash 자료구조로 unordered_map이 있음

int main()
{
    vector<string> players({"mumu", "soe", "poe", "kai", "mine"});
    vector<string> Call({ "kai", "kai", "mine", "mine" });
    vector<string> result;
    
    result = solution(players, Call);

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << endl;
    }

    return 0;
}

//map을 이용했을경우
//테스트 1 〉	통과(0.01ms, 4.21MB)
//테스트 2 〉	통과(0.02ms, 4.02MB)
//테스트 3 〉	통과(0.06ms, 4.14MB)
//테스트 4 〉	통과(0.27ms, 4.21MB)
//테스트 5 〉	통과(1.92ms, 4.15MB)
//테스트 6 〉	통과(4.28ms, 4.61MB)
//테스트 7 〉	통과(28.66ms, 8.9MB)
//테스트 8 〉	통과(65.17ms, 14.6MB)
//테스트 9 〉	통과(157.08ms, 25.8MB)
//테스트 10 〉	통과(575.80ms, 59.8MB)
//테스트 11 〉	통과(902.78ms, 103MB)
//테스트 12 〉	통과(805.20ms, 103MB)
//테스트 13 〉	통과(785.06ms, 103MB)
//테스트 14 〉	통과(0.01ms, 4.15MB)
//테스트 15 〉	통과(0.02ms, 4.12MB)
//테스트 16 〉	통과(0.02ms, 4.15MB)

//unordered_map을 이용했을 경우
//테스트 1 〉	통과(0.02ms, 4.21MB)
//테스트 2 〉	통과(0.02ms, 4.15MB)
//테스트 3 〉	통과(0.05ms, 4.18MB)
//테스트 4 〉	통과(0.16ms, 4.17MB)
//테스트 5 〉	통과(0.87ms, 4.23MB)
//테스트 6 〉	통과(2.00ms, 4.45MB)
//테스트 7 〉	통과(8.99ms, 8.88MB)
//테스트 8 〉	통과(22.11ms, 14.4MB)
//테스트 9 〉	통과(56.30ms, 25.9MB)
//테스트 10 〉	통과(170.02ms, 59.6MB)
//테스트 11 〉	통과(264.04ms, 103MB)
//테스트 12 〉	통과(309.64ms, 103MB)
//테스트 13 〉	통과(259.62ms, 103MB)
//테스트 14 〉	통과(0.02ms, 3.64MB)
//테스트 15 〉	통과(0.02ms, 4.22MB)
//테스트 16 〉	통과(0.02ms, 4.27MB)