using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using System.Data.Sql;
using System.Data.SqlClient;
using System.Collections.Concurrent;
using System.Diagnostics;

namespace BenchmarkConcurrentDictionary
{
    class Program
    {
        public static volatile int cntr = 0; // to make sure compiler doesn't rolls out the loop while optimizing
        static void Main(string[] args)
        {
            var lockedDictionary = new LockDicitionary();
            var concurrentDictionary = new ImplicitLockedDictionary();
            long lockedDictionaryTime = 0;
            long concurrentDictionaryTime = 0;
            var lockedDictionaryTask = Task.Run(() => lockedDictionaryTime = Benchmark(lockedDictionary));
            var concurrentDicitionaryTask = Task.Run(() => concurrentDictionaryTime = Benchmark(concurrentDictionary));
            Task.WaitAll(new Task[] { lockedDictionaryTask, concurrentDicitionaryTask });
            
            Console.WriteLine(string.Format("time taken by explicit locked dictionary {0}", lockedDictionaryTime));
            Console.WriteLine(string.Format("time taken by concurrent dictionary {0}", concurrentDictionaryTime));
        }

        private static long Benchmark(IDictionaryWrapper target, int numberOfItems = 1000)
        {
            var list = new List<string>();
            for (int i = 0; i < numberOfItems; ++i)
            {
                list.Add(i.ToString());
            }
            target.performWrite(list);
            var watch = new Stopwatch();
            watch.Start();
            foreach(var value in target.ReadNext())
            {
                cntr += value.Length;
            }
            watch.Stop();
            return watch.Elapsed.Ticks;
        }

        interface IDictionaryWrapper
        {
            void performWrite(IList<string> sampleData);
            IEnumerable<string> ReadNext();
        }

        public class LockDicitionary : IDictionaryWrapper
        {
            private Dictionary<string, string> values = new Dictionary<string,string>();
            private object lockObject = new object();

            public void performWrite(IList<string> sampleData)
            {
                var randomizer = new Random();
                Parallel.ForEach(sampleData, (string value) =>
                    {
                        lock (lockObject)
                        {
                            values.Add(value, randomizer.Next().ToString());
                        }
                    });
            }

            public IEnumerable<string> ReadNext()
            {
                foreach(var value in values)
                {
                    yield return value.Value;
                }
            }
        }

        public class ImplicitLockedDictionary : IDictionaryWrapper
        {
            private ConcurrentDictionary<string, string> values = new ConcurrentDictionary<string, string>();
            private object lockObject = new Object();
            public IEnumerable<string> ReadNext()
            {
                foreach (var value in values)
                {
                    yield return value.Value;
                }
            }

            public void performWrite(IList<string> sampleData)
            {
                Parallel.ForEach(sampleData, (string value) =>
                {
                    var randomizer = new Random();
                    if (!values.TryAdd(value, randomizer.Next().ToString()))
                    {
                        throw new InvalidOperationException();
                    }
                });
            }
        }
    }
}
