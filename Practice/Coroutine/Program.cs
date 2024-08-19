using System.Collections;

namespace Coroutine
{
    
    internal class Program
    {
        public static IEnumerator MyCoroutine()
        {
            Console.WriteLine("abc");
            yield return null;
            Console.WriteLine("def");
            yield return null;
            Console.WriteLine("ghi");
        }


        static void Main(string[] args)
        {
            IEnumerator enumerator = MyCoroutine();
           
            Console.WriteLine("123");
            enumerator.MoveNext();
            Console.WriteLine("456");
            enumerator.MoveNext();
            Console.WriteLine("789");
            enumerator.MoveNext();
        }
    }
}
