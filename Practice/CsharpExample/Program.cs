
abstract class MyAbstractClass
{
    public abstract void Test();
    int a = 0;
    void NotAbstractFunc()
    {
        
    }
}


class MyClass
{
    public int a = 0;
}

namespace CsharpExample
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello, World!");
            MyClass A = new MyClass();
            MyClass B = A;
            A.a = 1;

        }
    }
}
