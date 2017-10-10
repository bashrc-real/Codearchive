using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication2
{
    public static class FileReader
    {
        internal class Data
        {
            public string Operation;
            public int Latency;
        }

        static IEnumerable<Data> GetData(StreamReader file)
        {
            string line;
            while ((line = file.ReadLine()) != null)
            {
                var data = line.Split(',');
                yield return new Data { Operation = data[0], Latency = int.Parse(data[1]) };
            }
        }
    }
}
