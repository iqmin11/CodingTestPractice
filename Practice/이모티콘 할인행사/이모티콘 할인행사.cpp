#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

std::vector<int> Sales;
int EmoCount;
int MaxSignIn = INT32_MIN; //가장 많은 가입자
int MaxSellEmo = INT32_MIN; //가입자가 가장 많을때 가장 높은 판매 금액

void BT(const vector<vector<int>>& Users, const vector<int>& Emoticons)
{
    if (Sales.size() == EmoCount)
    {
        //할인 적용 결과는 여기서 도출
        int SignIn = 0; //현재 할인율에서 몇명의 유저가 가입했는가
        int WholeSellEmo = 0; //수입은 얼마인가
        for (int i = 0; i < Users.size(); i++)
        {
            int WantSaleValue = Users[i][0];
            int LimitMoney = Users[i][1];

            int BuyMoney = 0;

            for (int j = 0; j < Sales.size(); j++)
            {
                if (WantSaleValue > Sales[j]) //현재 할인율이 유저가 원하는 할인율보다 적다면
                {
                    continue;
                }

                BuyMoney += Emoticons[j] / 100 * (100 - Sales[j]);

                if (BuyMoney >= LimitMoney) //구입 총액이 예산 이상이라면
                {
                    SignIn++; //가입
                    break;
                }
            }

            if (BuyMoney < LimitMoney) //조건에 맞는 모든 제품을 다사도 예산을 넘어가지 않는다면
            {
                WholeSellEmo += BuyMoney; //이모티콘 구매
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
    //각 제품마다 할인율 적용 백트래킹
    EmoCount = emoticons.size();

    Sales.reserve(EmoCount);

    BT(users, emoticons);

    vector<int> answer;
    answer.push_back(MaxSignIn);
    answer.push_back(MaxSellEmo);

    return answer;
}