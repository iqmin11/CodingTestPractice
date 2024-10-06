namespace CustomAttribute
{
    [AttributeUsage(AttributeTargets.Class | AttributeTargets.Method)]
    public class MyAttribute : Attribute
    {
        public MyAttribute(string name, int version)
        {
            Name = name;
            Version = version;
        }

        public string Name
        {
            get;
        }

        public int Version
        {
            get;
        }
    }

    [My("Hwang Seung Min", 3)]
    public class MyClass
    {
        [My("Hwang Soo Min", 1)]
        public void TestMessage()
        {
            Console.WriteLine("MyClass : Test Message");
        }
    }   

    internal class Program
    {
        static void Main(string[] args)
        {
            Type ClassType = typeof(MyClass);
            object[] Attributes = ClassType.GetCustomAttributes(false);


            foreach (var Attribute in Attributes)
            {
                if (Attribute is MyAttribute developerAttr)
                {
                    Console.WriteLine($"Class developed by {developerAttr.Name}, version {developerAttr.Version}");
                }
            }
        }
    }
}
