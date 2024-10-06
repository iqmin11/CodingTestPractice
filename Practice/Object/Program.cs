
using System.Numerics;


public interface IMyInterface
{
    public void Test();
}

class MyClass : IMyInterface
{
    public void Test()
    {
        Console.WriteLine("Test");
    }
    public MyClass(int Value)
    {
        a = Value;
    }

    int a = 0;
}

struct MyStruct : IMyInterface
{
    public void Test()
    {
        Console.WriteLine("Test");
    }
    int a;
}

enum MyEnum
{
    a = 0,
    b,
    c
}



namespace Object
{
    internal class Program
    {
        static void Main(string[] args)
        {
            IMyInterface TestInt = new MyClass(1);

            object Boxing = TestInt; //힙에 해당 TestInt가 새로 생성되고, object 타입으로 저장됨
            //박싱은 명시적이어도, 암시적이어도 가능함.
            //explicit Method
            //object Boxing = (object)TestInt

            IMyInterface UnBoxing = (IMyInterface)Boxing; //명시적으로 캐스팅하여 사용해야함

            bool ResultBool = Boxing.Equals(TestInt);
            Type TypeInfo = Boxing.GetType();
            int Hash = Boxing.GetHashCode(); 
            string? Str = Boxing.ToString();

            int a = 0;
        }
    }
}
