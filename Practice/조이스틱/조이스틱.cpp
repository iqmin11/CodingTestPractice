#include <string>
#include <vector>
#include <list>

using namespace std;

int solution0(string name)
{
    int answer = 0;
    int TotalCount = 'Z' - 'A' + 1;
    int HalfCount = TotalCount / 2;

    //�� �Ʒ� ���ۿ� ���� ��
    for (size_t i = 0; i < name.length(); i++)
    {
        int CharToInt = name[i] - 'A';
        if (CharToInt >= HalfCount)
        {
            CharToInt = TotalCount - CharToInt;
        }
        answer += CharToInt;
    }

    //�¿� ���ۿ� ���� ��
    
    //���̵��
    //1. Name�� �� ���鼭 ���� �� ���ӵ� A�� ó���� ���� ã��
    //2. ���ӵ� A�� ������ �ε��� ���� ���ں��� Name�� ������ ���ڱ����� Name[0] ���ʿ� �дٰ� ����
    //3. Name[0]�� �������� ���� ���� ������ ������ ���� ������ �� ª������ ���� ���ٰ� �������� ���ϴ� ��Ʈ�� MoveCount ����
    //4. �����ϰ� ���������� ���� ���� ������ NonExeptionMoveCount �� MoveCount�� ��, �� �������� answer�� ����
   
    int MoveCount = 0;
    int First_A_Index = -1;
    int Last_A_Index = -1;
    int Longest_A_Count = 0;
    int NameLength = static_cast<int>(name.length());
    int NonExeptionMoveCount = NameLength - 1;
    
    int Cur_First_A_Index = -1;
    int Cur_Last_A_Index = -1;
    int Cur_A_Count = 0;

    //���� ������ 0�� �ε����� A���δ� ���谡 ����. ������ ����� ������ ���� �ʵ��� 1���� �˻��ؾ���. 
    for (int i = 1; i < NameLength; i++)
    {
        //���� A�˻� ����
        if (Cur_First_A_Index == -1)
        {
            if (name[i] == 'A')
            {
                Cur_First_A_Index = i;
            }
        }
        else if(Cur_Last_A_Index == -1)
        {
            if (name[i] != 'A')
            {
                Cur_Last_A_Index = i - 1;
                Cur_A_Count = Cur_Last_A_Index - Cur_First_A_Index + 1;

                if (Cur_A_Count > Longest_A_Count) //���� üũ�ϰ��ִ� ���� A�� ���̰� ������ ���� A�� ���̺��� �� ����
                {
                    //��� ����
                    Longest_A_Count = Cur_A_Count; 
                    First_A_Index = Cur_First_A_Index;
                    Last_A_Index = Cur_Last_A_Index;

                    //�ʱ�ȭ
                    Cur_A_Count = 0;
                    Cur_First_A_Index = -1;
                    Cur_Last_A_Index = -1;
                }
            }
        }
    }

    //����ó�� 1. ���� �����ϰ��ִ� ���� A�� Name�� ���������� ���ӵǾ��� ���
    if (Cur_First_A_Index != -1 && Cur_Last_A_Index == -1)
    {
        NonExeptionMoveCount = Cur_First_A_Index - 1; // ���������� �����ϰ� �����̴� ������ �ε����� A�� �����ε��� -1�� �ٲ� ex) 000AAA

        Cur_Last_A_Index = NameLength - 1; // ������ �ε����� NameLength - 1��
        Cur_A_Count = Cur_Last_A_Index - Cur_First_A_Index + 1;
        if (Cur_A_Count > Longest_A_Count) //���� üũ�ϰ��ִ� ���� A�� ���̰� ������ ���� A�� ���̺��� �� ����
        {
            //��� ����
            Longest_A_Count = Cur_A_Count;
            First_A_Index = Cur_First_A_Index;
            Last_A_Index = Cur_Last_A_Index;

            //�ʱ�ȭ
            Cur_A_Count = 0;
            Cur_First_A_Index = -1;
            Cur_Last_A_Index = -1;
        }
    }

    //����ó�� 2. Name ��ü�� A�� ���
    if (Longest_A_Count == NameLength) 
    {
        return answer;
    }
    
    //����ó�� 3. Name �� A�� ���� ���
    if (Longest_A_Count == 0)
    {
        answer += NonExeptionMoveCount;
        return answer;
    }

    int RightSideCount = First_A_Index - 1;
    int LeftSideCount = NameLength - (Last_A_Index + 1);

    if (RightSideCount < LeftSideCount)
    {
        MoveCount = RightSideCount * 2 + LeftSideCount;
    }
    else if (RightSideCount >= LeftSideCount)
    {
        MoveCount = LeftSideCount * 2 + RightSideCount;
    }

    if (MoveCount > NonExeptionMoveCount)
    {
        //��� ����� ���� �հ� ��������� �����ϰ� ���������� ���°� ���� ���
        answer += NonExeptionMoveCount;
    }
    else
    {
        answer += MoveCount;
    }

    return answer;
}

//int solution1(string name)
//{
//    int answer = 0;
//    int TotalCount = 'Z' - 'A' + 1;
//    int HalfCount = TotalCount / 2;
//
//    //�� �Ʒ� ���ۿ� ���� ��
//    for (size_t i = 0; i < name.length(); i++)
//    {
//        int CharToInt = name[i] - 'A';
//        if (CharToInt >= HalfCount)
//        {
//            CharToInt = TotalCount - CharToInt;
//        }
//        answer += CharToInt;
//    }
//
//    //ó���� ���� ����Ǿ��ִ� ����
//    //�¿�� ������ A�� �ƴ� ���� ��� A�� ����� �ּ����� ������
//    //�� �� ���� �Ұ��� �������ִ� ������� ������
//    //list�� �����?
//
//    std::list<char> StrToCirList = std::list<char>();
//
//    return answer;
//}

int main()
{
    int a = solution0("AAAKJABJKAAAAAHAIKLKHAILAAAAAANANKLAN");
    //int b = solution1("ASJLDKAAAAAAAAAAAAAAHVBN");

    return 0;
}

//�����ɷȰ� ������ Ǭ ���� ����.
//�׸��� ������� �ϱ⿡�� ������ �ظ� ���ϱ� ���� ����ó���� �����������Ƽ� ��ȿ�����̾���
