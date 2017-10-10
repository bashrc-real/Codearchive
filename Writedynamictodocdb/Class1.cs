using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using Microsoft.Azure.Documents.Client;
using System.Dynamic;

namespace Writedynamictodocdb
{
    public class Class1
    {

        private DocumentClient client = new DocumentClient(new Uri(""), "");
        private string collectionLink;
        public Class1()
        {
            var db = client.CreateDatabaseIfNotExistsAsync(new Microsoft.Azure.Documents.Database { Id = "Foobar" }).Result;
            var res = client.CreateDocumentCollectionIfNotExistsAsync(db.Resource.SelfLink, new Microsoft.Azure.Documents.DocumentCollection { Id = "Pikachu" }).Result;
            collectionLink  = res.Resource.SelfLink;
        }

        public void WriteArbitraryDictionary(Dictionary<string, object> keyValuePairs)
        {
            var expandedObject = new ExpandoObject();
            var collection = expandedObject as ICollection<KeyValuePair<string, object>>;

            if (collection == null)
            {
                throw new NotSupportedException("NO!!!!!!!!!");
            }

            foreach (var kvp in keyValuePairs) collection.Add(kvp);

            var result = this.client.CreateDocumentAsync(this.collectionLink, expandedObject).Result;
        }

        public List<dynamic> GetArbitraryData(List<KeyValuePair<string, string>> dimensionAndTarget)
        {
            StringBuilder sb = new StringBuilder();
            sb.Append("SELECT * FROM f WHERE ");
            int cntr = dimensionAndTarget.Count;
            foreach(var kv in dimensionAndTarget)
            {
                --cntr;
                sb.Append("f.");
                sb.Append(kv.Key + "=\'" + kv.Value + (cntr > 0 ? "\' AND " : "\'"));
            }
            var query = sb.ToString();

            var q = this.client.CreateDocumentQuery(this.collectionLink, query);
            return q.ToList();
        }
    }
}
