using System.Collections;
using System.Data;

namespace PracticeCsharp
{
    internal class Program
    {
        //숫자 뒤집고 더해서 팰린드롬 검사하기
        static void Solution(int Value)
        {
            string NumStr = Value.ToString();
            List<char> RevNumStr = new List<char>();

            int NumLength = NumStr.Length;
            for (int i = 0; i < NumLength; i++)
            {
                RevNumStr.Add(NumStr[NumLength - 1 - i]);
            }

            int RevNum = 0;
            int PowTen = 1;
            for (int i = 0; i < NumLength; i++)
            {
                int temp = PowTen * (RevNumStr[NumLength - 1 - i] - '0');
                PowTen *= 10;
                RevNum += temp;
            }

            int Sum = Value + RevNum;
            string SumStr = Sum.ToString();
            int HalfLength = SumStr.Length / 2;
            for (int i = 0; i < HalfLength; i++)
            {
                if(SumStr[i] != SumStr[HalfLength - 1 - i])
                {
                    Console.WriteLine("NO");
                    return;
                }
            }
            Console.WriteLine("YES");
            return;
        }

        //두번째 문제도 기억 안남. 별로 안어려웠음

        //더블 점프 구현하기
        //수도 코드로 작성하면
        //이 클래스를 더블점프 할 수 있게 바꾸기
        //public class Player
        //{
        //    bool IsGrounded = true;
        //    void Update()
        //    {
        //        if (/*스페이스 누르기*/ && IsGrounded)
        //        {
        //            //업벡터 * 임펄스 해서 뭐 플레이어 점프시키는 코드
        //            IsGrounded = false;
        //        }
        //    }
        //
        //    //void 땅이랑충돌
        //    //{
        //    //    IsGrounded = true;
        //    //}
        //}

        //public class Player
        //{
        //    bool IsGrounded = true;
        //    bool CanDoubleJump = false;
        //    void Update()
        //    {
        //        if (/*스페이스 누르기*/)
        //        {
        //            if(IsGrounded || CanDoubleJump)
        //            {
        //                //업벡터 * 임펄스 해서 뭐 플레이어 점프시키는 코드
        //                IsGrounded = false;
        //                CanDoubleJump = !CanDoubleJump;
        //            }
        //        }
        //    }

        //    //void 땅이랑충돌
        //    //{
        //    //    IsGrounded = true;
        //    //    CanDoubleJump = false;
        //    //}
        //}

        //StartOverlap StartCollision이랑 뭐랑 차이점

        //Update와 FixedUpdate의 차이점

        //오브젝트 풀링 관련 문제였는데
        //코드 인터페이스가 이해가 안가서 못풀었음
        //기억은 다남

        internal class ObjPool<T> where T : Program
        {
            List<T> AvailableObjects = new List<T>();
            List<T> UseObjects = new List<T>();

            //T GetObject()
            //{
            //}

            //void ReleaseObject(T Obj)
            //{
            //
            //}
        }

        //뭐하나 더있었는데 기억안남

        //코루틴 빈칸 채우기
        //답은 StartCoroutine, IEnumerator, yield return new WaitForSecond(1.0f);

        //틀린 코드 찾기
        //Item어쩌구 코드 아이템 이름이랑 뭐 간단한 정보 담고있는 코드
        //1. 간단한 데이터를 담고있는 클래스가 모노비헤비어를 상속받음

        //StageMap인데 구현된 코드가 좆병신이었음 틀리고 자시고 이전에
        //보스를 Stage가 받고 업데이트마다 보스가 죽었는지 체크, 보스가 죽으면 아이템을 스폰하는 코드
        //보자마자 이걸 왜 스테이지에서 하지 ㅅㅂ ㅄ인가. 아무리 문제라도

        //문제는 세개 더있었음
        //2. cs파일 제목, 그냥 문제 없었음. 문제없음이 답인것도 있음. 클래스명이랑 cs파일 제목이 달랐는데 아마 함정이었을듯
        //3. 업데이트마다 Boss의 정보를 Find하는 함수를 호출함. //Awake나 Start에서 한번만 호출하고 멤버로 담자고 함
        //4. 보스를 Find하고 그걸 boss라는 변수에 담았는데 널체크를 !boss로 함

        struct MyStruct
        {
            public int Value;

            // 읽기 전용이 아닌 메서드
            public void Increment()
            {
                Value++;
            }
        }

        static void ModifyValue(in MyStruct data)
        {
            // 읽기 전용이 아닌 메서드를 호출하면 컴파일러가 자동으로 복사본을 생성합니다.
            data.Increment();

            Console.WriteLine($"함수 내부 값: {data.Value}");
        }

        static void Main(string[] args)
        {
            MyStruct original = new MyStruct { Value = 10 };
            ModifyValue(original);

            Console.WriteLine($"원본 값: {original.Value}");
        }
    }
}
