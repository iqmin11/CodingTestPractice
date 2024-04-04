//https://school.programmers.co.kr/learn/courses/30/lessons/77885

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    std::vector<long long> answer;
    answer.resize(numbers.size());

    //���� ��ü�� ������. ���� �ڸ��� ��Ʈ���� üũ�ϸ鼭 0�� ������ �ش� ��Ʈ�� �ϳ� �� ��Ʈ�� 10���� �ٲٴ°�
    //������ �� ������ �� �׷��ԵǴ°��� �����ϴ°�

    for (size_t i = 0; i < numbers.size(); i++)
    {
        long long Num = numbers[i];
        long long Index = 0;
        while (true)
        {
            if ((Num >> Index) & 1) // �ش��ڸ��� ��Ʈ�� 1�̸� 1, 0�̸� 0�� �������ִ� ����
            {
                ++Index;
                continue;
            }

            //long long���� 64bit������ �ϱ� ������ 1LL�� ����� �ڷ����� ������� �ʿ䰡 �־���. �ȱ׷��� �ǵ�ġ ���� ������ �Ͼ
            Num |= (1LL << Index); //�ش� �ڸ��� ��Ʈ�� 1�� �ٲ��ִ� ����
            Num &= ~(1LL << (Index - 1)); //�ش� �ڸ��� ��Ʈ�� 0���� �ٲ��ִ� ���� (�����÷ο찡 ���� �� ��� ���°ǰ�??? ����ó���� �ؾߵ� �� ���⵵ ��)
            break;
        }

        answer[i] = Num;
    }
    
    return answer;
}

int main()
{
    solution({ 1000000000000000 });

    return 0;
}