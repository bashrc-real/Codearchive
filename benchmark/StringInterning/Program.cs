using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    class Program
    {
        static string GetString()
        {
            Random rnd = new Random();
            if (rnd.Next(2) == 1)
            {
                return Int64.MaxValue.ToString();
            }

            return Int32.MaxValue.ToString();
        }

        static void Main(string[] args)
        {
            var values = new List<string>();
            int cntr = 0;
            var rnd = new Random();
            for (int i = 0; i < 10000000; ++i)
            {
                var s = GetString();
                values.Add(string.Intern(s));
            }
            int len = 0;
            foreach (var val in values)
            {
                len += val.Length;
            }
            Console.WriteLine(len);
            Console.ReadKey();
        }
    }
}
