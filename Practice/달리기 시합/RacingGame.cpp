#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <iostream>

using namespace std;

//1. ���Ϳ� �ִ� players �����͸� �ؽ� ���̺� ����
//2. Calling���� �Ҹ� player�� �ؽ����� �˻��ϰ� �ε����� ��������� ����
//3. �ε��� ������ ���ؼ� �ٷ� �����ϰ� �ռ������� �÷��̾ �ٽ� �ؽ��ʿ��� �˻�
//4. �ٲ�����ϱ� �ȿ� ����Ǿ��ִ� �ε����� ���������� �ݺ�

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
//        if (FindData != SaveData.end()) //�Ʒ��� Ž������� �����ϱ� ���� �̹� ã�� �����͸� �ε����� ���� �����ϰ� �ʿ��� �˻��ϴ� ����� �õ������� ����
//        {
//            int FindIndex = FindData->second;
//            std::string Temp = std::move(answer[FindIndex]);
//            answer[FindIndex] = std::move(answer[FindIndex - 1]);
//            answer[FindIndex - 1] = std::move(Temp);
//            SaveData[answer[FindIndex - 1]] = FindIndex - 1;
//            continue;
//        }
//
//        for (int j = 0; j < answer.size(); j++) //���� Ž���˰����̶�� �̸�, �� Ž�� ����� �ش����� ��Ȳ���� �ſ� ��ȿ������
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


//swap�Լ��� ���鶧 std::move�� �̿��ϸ� ����.
//A = std::move(B) B�� ����Ű���ִ� �޸��� ���ʽ��� B���� A�� �ٲ���

//Ž����Ŀ����� ��ȿ���� �����ϱ����� Ž���˰����� ����
//Hash Ž���� ������, stl�� �ִ� Hash �ڷᱸ���� unordered_map�� ����

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

//map�� �̿��������
//�׽�Ʈ 1 ��	���(0.01ms, 4.21MB)
//�׽�Ʈ 2 ��	���(0.02ms, 4.02MB)
//�׽�Ʈ 3 ��	���(0.06ms, 4.14MB)
//�׽�Ʈ 4 ��	���(0.27ms, 4.21MB)
//�׽�Ʈ 5 ��	���(1.92ms, 4.15MB)
//�׽�Ʈ 6 ��	���(4.28ms, 4.61MB)
//�׽�Ʈ 7 ��	���(28.66ms, 8.9MB)
//�׽�Ʈ 8 ��	���(65.17ms, 14.6MB)
//�׽�Ʈ 9 ��	���(157.08ms, 25.8MB)
//�׽�Ʈ 10 ��	���(575.80ms, 59.8MB)
//�׽�Ʈ 11 ��	���(902.78ms, 103MB)
//�׽�Ʈ 12 ��	���(805.20ms, 103MB)
//�׽�Ʈ 13 ��	���(785.06ms, 103MB)
//�׽�Ʈ 14 ��	���(0.01ms, 4.15MB)
//�׽�Ʈ 15 ��	���(0.02ms, 4.12MB)
//�׽�Ʈ 16 ��	���(0.02ms, 4.15MB)

//unordered_map�� �̿����� ���
//�׽�Ʈ 1 ��	���(0.02ms, 4.21MB)
//�׽�Ʈ 2 ��	���(0.02ms, 4.15MB)
//�׽�Ʈ 3 ��	���(0.05ms, 4.18MB)
//�׽�Ʈ 4 ��	���(0.16ms, 4.17MB)
//�׽�Ʈ 5 ��	���(0.87ms, 4.23MB)
//�׽�Ʈ 6 ��	���(2.00ms, 4.45MB)
//�׽�Ʈ 7 ��	���(8.99ms, 8.88MB)
//�׽�Ʈ 8 ��	���(22.11ms, 14.4MB)
//�׽�Ʈ 9 ��	���(56.30ms, 25.9MB)
//�׽�Ʈ 10 ��	���(170.02ms, 59.6MB)
//�׽�Ʈ 11 ��	���(264.04ms, 103MB)
//�׽�Ʈ 12 ��	���(309.64ms, 103MB)
//�׽�Ʈ 13 ��	���(259.62ms, 103MB)
//�׽�Ʈ 14 ��	���(0.02ms, 3.64MB)
//�׽�Ʈ 15 ��	���(0.02ms, 4.22MB)
//�׽�Ʈ 16 ��	���(0.02ms, 4.27MB)