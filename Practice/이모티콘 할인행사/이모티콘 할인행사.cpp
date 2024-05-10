#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

std::vector<int> Sales;
int EmoCount;
int MaxSignIn = INT32_MIN; //���� ���� ������
int MaxSellEmo = INT32_MIN; //�����ڰ� ���� ������ ���� ���� �Ǹ� �ݾ�

void BT(const vector<vector<int>>& Users, const vector<int>& Emoticons)
{
    if (Sales.size() == EmoCount)
    {
        //���� ���� ����� ���⼭ ����
        int SignIn = 0; //���� ���������� ����� ������ �����ߴ°�
        int WholeSellEmo = 0; //������ ���ΰ�
        for (int i = 0; i < Users.size(); i++)
        {
            int WantSaleValue = Users[i][0];
            int LimitMoney = Users[i][1];

            int BuyMoney = 0;

            for (int j = 0; j < Sales.size(); j++)
            {
                if (WantSaleValue > Sales[j]) //���� �������� ������ ���ϴ� ���������� ���ٸ�
                {
                    continue;
                }

                BuyMoney += Emoticons[j] / 100 * (100 - Sales[j]);

                if (BuyMoney >= LimitMoney) //���� �Ѿ��� ���� �̻��̶��
                {
                    SignIn++; //����
                    break;
                }
            }

            if (BuyMoney < LimitMoney) //���ǿ� �´� ��� ��ǰ�� �ٻ絵 ������ �Ѿ�� �ʴ´ٸ�
            {
                WholeSellEmo += BuyMoney; //�̸�Ƽ�� ����
            }
        }

        if (MaxSignIn < SignIn)
        {
            MaxSignIn = SignIn;
            MaxSellEmo = WholeSellEmo;
        }
        else if (MaxSignIn == SignIn)
        {
            if (WholeSellEmo > MaxSellEmo)
            {
                MaxSellEmo = WholeSellEmo;
            }
        }
        return;
    }

    for (int i = 1; i <= 4; i++)
    {
        Sales.push_back(i * 10);
        BT(Users, Emoticons);
        Sales.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons)
{
    //�� ��ǰ���� ������ ���� ��Ʈ��ŷ
    EmoCount = emoticons.size();

    Sales.reserve(EmoCount);

    BT(users, emoticons);

    vector<int> answer;
    answer.push_back(MaxSignIn);
    answer.push_back(MaxSellEmo);

    return answer;
}