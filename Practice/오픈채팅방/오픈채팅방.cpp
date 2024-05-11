//���� �ּ� : https://school.programmers.co.kr/learn/courses/30/lessons/42888

#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <iostream>

using namespace std;

std::map<std::string, std::string> ID_Nick; // ���̵�, �г���
std::vector<std::string> Message;

vector<string> solution(vector<string> record)
{
    //���̵� �������� ������� �ۼ� ��
    //���̵� �������� �г������� ġȯ�ϸ� ��

    Message.resize(2);
    Message[0] = "���� ���Խ��ϴ�.";
    Message[1] = "���� �������ϴ�.";
    std::vector<std::string> PrintID;
    std::vector<int> PrintMessage;
    //�ϴ� ��ɾ ������

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

//�޼����� ���̺�� ����������, �ξ� �޸𸮸� ���� �� �־��ڴ�.

//�׽�Ʈ 1 ��	���(0.03ms, 4.23MB)
//�׽�Ʈ 2 ��	���(0.04ms, 4.22MB)
//�׽�Ʈ 3 ��	���(0.07ms, 4.21MB)
//�׽�Ʈ 4 ��	���(0.08ms, 4.16MB)
//�׽�Ʈ 5 ��	���(0.97ms, 4.13MB)
//�׽�Ʈ 6 ��	���(1.07ms, 4.2MB)
//�׽�Ʈ 7 ��	���(0.82ms, 3.99MB)
//�׽�Ʈ 8 ��	���(1.96ms, 4.21MB)
//�׽�Ʈ 9 ��	���(1.42ms, 4.21MB)
//�׽�Ʈ 10 ��	���(1.07ms, 4.03MB)
//�׽�Ʈ 11 ��	���(0.65ms, 4.22MB)
//�׽�Ʈ 12 ��	���(0.69ms, 4.22MB)
//�׽�Ʈ 13 ��	���(1.02ms, 3.98MB)
//�׽�Ʈ 14 ��	���(1.41ms, 4.29MB)
//�׽�Ʈ 15 ��	���(0.03ms, 4.02MB)
//�׽�Ʈ 16 ��	���(0.03ms, 4.15MB)
//�׽�Ʈ 17 ��	���(0.14ms, 4.22MB)
//�׽�Ʈ 18 ��	���(0.12ms, 4.21MB)
//�׽�Ʈ 19 ��	���(1.09ms, 4.22MB)
//�׽�Ʈ 20 ��	���(0.84ms, 4.22MB)
//�׽�Ʈ 21 ��	���(0.83ms, 4.22MB)
//�׽�Ʈ 22 ��	���(0.92ms, 4.16MB)
//�׽�Ʈ 23 ��	���(1.04ms, 4.15MB)
//�׽�Ʈ 24 ��	���(1.13ms, 4.08MB)
//�׽�Ʈ 25 ��	���(168.42ms, 40.6MB)
//�׽�Ʈ 26 ��	���(205.45ms, 45.4MB)
//�׽�Ʈ 27 ��	���(185.86ms, 48.3MB)
//�׽�Ʈ 28 ��	���(215.25ms, 51.1MB)
//�׽�Ʈ 29 ��	���(224.34ms, 51MB)
//�׽�Ʈ 30 ��	���(157.79ms, 44.1MB)
//�׽�Ʈ 31 ��	���(218.47ms, 50MB)
//�׽�Ʈ 32 ��	���(139.64ms, 43.4MB)

//�ٲ� ��
//�׽�Ʈ 1 ��	���(0.04ms, 3.68MB)
//�׽�Ʈ 2 ��	���(0.03ms, 4.21MB)
//�׽�Ʈ 3 ��	���(0.07ms, 3.69MB)
//�׽�Ʈ 4 ��	���(0.08ms, 4.21MB)
//�׽�Ʈ 5 ��	���(0.86ms, 4.21MB)
//�׽�Ʈ 6 ��	���(1.00ms, 4.15MB)
//�׽�Ʈ 7 ��	���(1.37ms, 4.21MB)
//�׽�Ʈ 8 ��	���(1.06ms, 4.16MB)
//�׽�Ʈ 9 ��	���(1.24ms, 4.2MB)
//�׽�Ʈ 10 ��	���(0.96ms, 4.18MB)
//�׽�Ʈ 11 ��	���(0.63ms, 4.18MB)
//�׽�Ʈ 12 ��	���(0.64ms, 4.21MB)
//�׽�Ʈ 13 ��	���(0.96ms, 4.22MB)
//�׽�Ʈ 14 ��	���(1.69ms, 4.15MB)
//�׽�Ʈ 15 ��	���(0.04ms, 4.16MB)
//�׽�Ʈ 16 ��	���(0.06ms, 4.22MB)
//�׽�Ʈ 17 ��	���(0.13ms, 4.17MB)
//�׽�Ʈ 18 ��	���(0.12ms, 4.21MB)
//�׽�Ʈ 19 ��	���(1.06ms, 4.21MB)
//�׽�Ʈ 20 ��	���(0.82ms, 4.21MB)
//�׽�Ʈ 21 ��	���(0.80ms, 4.14MB)
//�׽�Ʈ 22 ��	���(0.85ms, 4.22MB)
//�׽�Ʈ 23 ��	���(0.95ms, 4.2MB)
//�׽�Ʈ 24 ��	���(1.05ms, 4.23MB)
//�׽�Ʈ 25 ��	���(140.28ms, 40.4MB)
//�׽�Ʈ 26 ��	���(180.45ms, 45.1MB)
//�׽�Ʈ 27 ��	���(212.40ms, 48MB)
//�׽�Ʈ 28 ��	���(226.57ms, 50.8MB)
//�׽�Ʈ 29 ��	���(185.54ms, 50.7MB)
//�׽�Ʈ 30 ��	���(151.31ms, 40.8MB)
//�׽�Ʈ 31 ��	���(211.34ms, 50.1MB)
//�׽�Ʈ 32 ��	���(154.29ms, 43.4MB)

//�������̾ȳ��� ����