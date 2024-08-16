using System.Runtime.CompilerServices;

delegate void TestDelegate();

namespace Delegate
{
    internal class Program
    {
        static void Main(string[] args)
        {
            TestDelegate MuliCast = new TestDelegate(() =>
            {
                Console.WriteLine("Test0");
            });
            
            MuliCast += () =>
            {
                Console.WriteLine("Test1");
            };

            MuliCast += () =>
            {
                Console.WriteLine("Test2");
            };

            MuliCast += () =>
            {
                Console.WriteLine("Test3");
            };

            MuliCast();
        }
    }
}
