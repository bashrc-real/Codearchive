using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace YeildTry
{
    class Program
    {
        public static IEnumerable<int> primeSieve(int N)
        {
            yield return 2;
            List<bool> sieve = new List<bool>(N + 1);
            for (int i = 0; i <= N; ++i) sieve.Add(false);
            for (int i = 3; i <= N; i+=2)
            {
                if (!sieve[i])
                {
                    yield return i;
                    for (int j = 3 * i; j <= N; j += 2 * i) sieve[j] = true;
                }
            }
            yield break;
        }

        static void Main(string[] args)
        {
            foreach(var x in primeSieve(10000))
            {
                Console.WriteLine(x);
            }
        }
    }
}
