//https://school.programmers.co.kr/learn/courses/30/lessons/12936

##include <string>
#include <vector>

using namespace std;

long long Factorial[21];

vector<int> solution(int n, long long k)
{

    std::vector<int> Arr;
    Arr.resize(n);
    for (int i = 0; i < n; i++)
    {
        Arr[i] = i + 1;
    }

    vector<int> answer;
    answer.reserve(n);

    Factorial[0] = 1;
    Factorial[1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        Factorial[i] = Factorial[i - 1] * i;
    }

    --k; //ù��° ���� �ε����� 0�̱� ������ �ϳ� �������
    for (int i = 0; i < n; i++)
    {
        long long Fac = Factorial[n - (i + 1)];
        long long Quo = (k / Fac); //Quo(0 ~ )��°��
        k %= Fac; //�������� k��

        answer.push_back(Arr[Quo]);
        Arr.erase(Arr.begin() + Quo);
    }

    return answer;
}

int main()
{
    solution(4, 8);
}