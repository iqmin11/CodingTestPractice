//문제 주소 : https://school.programmers.co.kr/learn/courses/30/lessons/42888

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

std::map<std::string, std::string> ID_Nick; // 아이디, 닉네임
std::vector<std::string> Message;

vector<string> solution(vector<string> record)
{
    //아이디 기준으로 결과값을 작성 후
    //아이디를 마지막에 닉네임으로 치환하면 됨

    Message.resize(2);
    Message[0] = "님이 들어왔습니다.";
    Message[1] = "님이 나갔습니다.";
    std::vector<std::string> PrintID;
    std::vector<int> PrintMessage;
    //일단 명령어를 나누기

    for (int i = 0; i < record.size(); ++i)
    {
        std::stringstream Buffer(record[i]);
        std::string Cmd;
        Buffer >> Cmd;
        std::string UserID;

        if (Cmd[0] == 'E')
        {
            //Enter
            std::string NickName;
            Buffer >> UserID;
            Buffer >> NickName;
            ID_Nick[UserID] = NickName;
            PrintID.push_back(UserID);
            PrintMessage.push_back(0);
        }
        else if (Cmd[0] == 'L')
        {
            //Leave
            Buffer >> UserID;
            PrintID.push_back(UserID);
            PrintMessage.push_back(1);
        }
        else
        {
            //Change
            std::string NickName;
            Buffer >> UserID;
            Buffer >> NickName;
            ID_Nick[UserID] = NickName;
        }
    }

    vector<string> answer;
    for (int i = 0; i < PrintID.size(); ++i)
    {
        std::string NickName = ID_Nick[PrintID[i]];
        answer.push_back(NickName + Message[PrintMessage[i]]);
    }

    return answer;
}

//메세지도 테이블로 저장했으면, 훨씬 메모리를 줄일 수 있었겠다.

//테스트 1 〉	통과(0.03ms, 4.23MB)
//테스트 2 〉	통과(0.04ms, 4.22MB)
//테스트 3 〉	통과(0.07ms, 4.21MB)
//테스트 4 〉	통과(0.08ms, 4.16MB)
//테스트 5 〉	통과(0.97ms, 4.13MB)
//테스트 6 〉	통과(1.07ms, 4.2MB)
//테스트 7 〉	통과(0.82ms, 3.99MB)
//테스트 8 〉	통과(1.96ms, 4.21MB)
//테스트 9 〉	통과(1.42ms, 4.21MB)
//테스트 10 〉	통과(1.07ms, 4.03MB)
//테스트 11 〉	통과(0.65ms, 4.22MB)
//테스트 12 〉	통과(0.69ms, 4.22MB)
//테스트 13 〉	통과(1.02ms, 3.98MB)
//테스트 14 〉	통과(1.41ms, 4.29MB)
//테스트 15 〉	통과(0.03ms, 4.02MB)
//테스트 16 〉	통과(0.03ms, 4.15MB)
//테스트 17 〉	통과(0.14ms, 4.22MB)
//테스트 18 〉	통과(0.12ms, 4.21MB)
//테스트 19 〉	통과(1.09ms, 4.22MB)
//테스트 20 〉	통과(0.84ms, 4.22MB)
//테스트 21 〉	통과(0.83ms, 4.22MB)
//테스트 22 〉	통과(0.92ms, 4.16MB)
//테스트 23 〉	통과(1.04ms, 4.15MB)
//테스트 24 〉	통과(1.13ms, 4.08MB)
//테스트 25 〉	통과(168.42ms, 40.6MB)
//테스트 26 〉	통과(205.45ms, 45.4MB)
//테스트 27 〉	통과(185.86ms, 48.3MB)
//테스트 28 〉	통과(215.25ms, 51.1MB)
//테스트 29 〉	통과(224.34ms, 51MB)
//테스트 30 〉	통과(157.79ms, 44.1MB)
//테스트 31 〉	통과(218.47ms, 50MB)
//테스트 32 〉	통과(139.64ms, 43.4MB)

//바꾼 후
//테스트 1 〉	통과(0.04ms, 3.68MB)
//테스트 2 〉	통과(0.03ms, 4.21MB)
//테스트 3 〉	통과(0.07ms, 3.69MB)
//테스트 4 〉	통과(0.08ms, 4.21MB)
//테스트 5 〉	통과(0.86ms, 4.21MB)
//테스트 6 〉	통과(1.00ms, 4.15MB)
//테스트 7 〉	통과(1.37ms, 4.21MB)
//테스트 8 〉	통과(1.06ms, 4.16MB)
//테스트 9 〉	통과(1.24ms, 4.2MB)
//테스트 10 〉	통과(0.96ms, 4.18MB)
//테스트 11 〉	통과(0.63ms, 4.18MB)
//테스트 12 〉	통과(0.64ms, 4.21MB)
//테스트 13 〉	통과(0.96ms, 4.22MB)
//테스트 14 〉	통과(1.69ms, 4.15MB)
//테스트 15 〉	통과(0.04ms, 4.16MB)
//테스트 16 〉	통과(0.06ms, 4.22MB)
//테스트 17 〉	통과(0.13ms, 4.17MB)
//테스트 18 〉	통과(0.12ms, 4.21MB)
//테스트 19 〉	통과(1.06ms, 4.21MB)
//테스트 20 〉	통과(0.82ms, 4.21MB)
//테스트 21 〉	통과(0.80ms, 4.14MB)
//테스트 22 〉	통과(0.85ms, 4.22MB)
//테스트 23 〉	통과(0.95ms, 4.2MB)
//테스트 24 〉	통과(1.05ms, 4.23MB)
//테스트 25 〉	통과(140.28ms, 40.4MB)
//테스트 26 〉	통과(180.45ms, 45.1MB)
//테스트 27 〉	통과(212.40ms, 48MB)
//테스트 28 〉	통과(226.57ms, 50.8MB)
//테스트 29 〉	통과(185.54ms, 50.7MB)
//테스트 30 〉	통과(151.31ms, 40.8MB)
//테스트 31 〉	통과(211.34ms, 50.1MB)
//테스트 32 〉	통과(154.29ms, 43.4MB)

//별로차이안나네 ㅋㅋ