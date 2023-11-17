#include <string>
#include <vector>

using namespace std;

//����� ���� * ���� �϶�
//������ ������� ���� + 2 * ���� + 2
//������ ������ �׷��� 
vector<int> solution(int brown, int yellow)
{
    std::vector<std::pair<int, int>> MulPair;

    MulPair.reserve(yellow);

    //��*�� ���
    for (int i = 1; i <= yellow; i++)
    {
        int Quo = 0;
        if (yellow % i == 0) //�����������
        {
            Quo = yellow / i; // ����� ���̾�?
            if (i <= Quo)
            {
                MulPair.push_back(std::make_pair(Quo, i)); //i * quo�� yellow
            }
            else
            {
                break;
            }
        }
    }

    vector<int> answer;
    int lt = 0;
    int rt = MulPair.size() - 1;

    while (lt <= rt)
    {
        int mid = (lt + rt) / 2;
        int Check = 2 * (MulPair[mid].first + MulPair[mid].second + 2); //���ο�� ������ ����
        if (Check == brown)
        {
            answer.push_back(MulPair[mid].first + 2);
            answer.push_back(MulPair[mid].second + 2);
            return answer;
        }
        else if (Check > brown)
        {
            lt = mid + 1;
            //üũ�� �۾������ϴ� �̵尡 Ŀ������
        }
        else if (Check < brown)
        {
            rt = mid - 1;
            //üũ�� Ŀ���� �ϴ� �̵尡 �۾�������
        }
    }

    return answer;
}

int main()
{
    solution(24, 24);

    return 0;
}