#include <string>
#include <vector>
#include <list>

using namespace std;

int solution0(string name)
{
    int answer = 0;
    int TotalCount = 'Z' - 'A' + 1;
    int HalfCount = TotalCount / 2;

    //위 아래 조작에 대한 것
    for (size_t i = 0; i < name.length(); i++)
    {
        int CharToInt = name[i] - 'A';
        if (CharToInt >= HalfCount)
        {
            CharToInt = TotalCount - CharToInt;
        }
        answer += CharToInt;
    }

    //좌우 조작에 대한 것
    
    //아이디어
    //1. Name을 쭉 돌면서 가장 긴 연속된 A의 처음과 끝을 찾음
    //2. 연속된 A의 마지막 인덱스 다음 글자부터 Name의 마지막 글자까지를 Name[0] 왼쪽에 둔다고 생각
    //3. Name[0]을 기준으로 왼쪽 글자 개수와 오른쪽 글자 개수를 비교 짧은쪽을 먼저 갔다가 긴쪽으로 향하는 루트로 MoveCount 세기
    //4. 정직하게 오른쪽으로 갔을 때를 가정한 NonExeptionMoveCount 와 MoveCount를 비교, 더 작은쪽을 answer에 더함
   
    int MoveCount = 0;
    int First_A_Index = -1;
    int Last_A_Index = -1;
    int Longest_A_Count = 0;
    int NameLength = static_cast<int>(name.length());
    int NonExeptionMoveCount = NameLength - 1;
    
    int Cur_First_A_Index = -1;
    int Cur_Last_A_Index = -1;
    int Cur_A_Count = 0;

    //시작 지점인 0번 인덱스의 A여부는 관계가 없음. 때문에 결과에 영향을 주지 않도록 1부터 검사해야함. 
    for (int i = 1; i < NameLength; i++)
    {
        //연속 A검사 시작
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

                if (Cur_A_Count > Longest_A_Count) //현재 체크하고있는 연속 A의 길이가 기존의 연속 A의 길이보다 더 길경우
                {
                    //기록 갱신
                    Longest_A_Count = Cur_A_Count; 
                    First_A_Index = Cur_First_A_Index;
                    Last_A_Index = Cur_Last_A_Index;

                    //초기화
                    Cur_A_Count = 0;
                    Cur_First_A_Index = -1;
                    Cur_Last_A_Index = -1;
                }
            }
        }
    }

    //예외처리 1. 현재 진행하고있는 연속 A가 Name의 마지막까지 지속되었을 경우
    if (Cur_First_A_Index != -1 && Cur_Last_A_Index == -1)
    {
        NonExeptionMoveCount = Cur_First_A_Index - 1; // 오른쪽으로 정직하게 움직이는 마지막 인덱스가 A의 시작인덱스 -1로 바뀜 ex) 000AAA

        Cur_Last_A_Index = NameLength - 1; // 마지막 인덱스를 NameLength - 1로
        Cur_A_Count = Cur_Last_A_Index - Cur_First_A_Index + 1;
        if (Cur_A_Count > Longest_A_Count) //현재 체크하고있는 연속 A의 길이가 기존의 연속 A의 길이보다 더 길경우
        {
            //기록 갱신
            Longest_A_Count = Cur_A_Count;
            First_A_Index = Cur_First_A_Index;
            Last_A_Index = Cur_Last_A_Index;

            //초기화
            Cur_A_Count = 0;
            Cur_First_A_Index = -1;
            Cur_Last_A_Index = -1;
        }
    }

    //예외처리 2. Name 전체가 A인 경우
    if (Longest_A_Count == NameLength) 
    {
        return answer;
    }
    
    //예외처리 3. Name 에 A가 없는 경우
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
        //모든 경우의 수를 뚫고 계산했지만 정직하게 오른쪽으로 가는게 빠른 경우
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
//    //위 아래 조작에 대한 것
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
//    //처음과 끝이 연결되어있는 구조
//    //좌우로 움직여 A가 아닌 곳을 모두 A로 만드는 최소한의 움직임
//    //앞 뒤 노드와 불값을 가지고있는 방식으로 만들자
//    //list로 만들까?
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

//오래걸렸고 억지로 푼 감이 있음.
//그리디 문제라고 하기에는 최적의 해를 구하기 위한 예외처리가 존나존나많아서 비효율적이었음
