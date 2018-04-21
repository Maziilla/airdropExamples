using System;
using System.Collections.Specialized;
using System.IO;
using System.Net;
using System.Text;
using Newtonsoft.Json;
using test.ResponseClasses;

namespace test
{
	public static class Blockchain
	{
		private static readonly string getInfoMethod = "get_info";
        private static readonly string getAccountMethod = "get_account";
		public static readonly string serverAddress;

		static Blockchain()
		{
			serverAddress = "127.0.0.1:8888";
		}

		public static string GetRequest(string methodName)
		{
			var request = (HttpWebRequest)HttpWebRequest.Create($"http://{serverAddress}/v1/chain/{methodName}");
            request.Method = "GET";
            string responseData;
			using (var response = (HttpWebResponse)request.GetResponse())
			{
				using (var dataStream = response.GetResponseStream())
				{
					using (var reader = new StreamReader(dataStream))
					{
						responseData = reader.ReadToEnd();
					}
				}
			}         

			return responseData;
		}

		public static string PostRequest(string methodName, string postData)
		{
			var request = (HttpWebRequest)HttpWebRequest.Create($"http://{serverAddress}/v1/chain/{methodName}");
            var data = Encoding.ASCII.GetBytes(postData);
            request.Method = "POST";
            request.ContentType = "application/x-www-form-urlencoded";
            request.ContentLength = data.Length;
            using (var stream = request.GetRequestStream())
            {
                stream.Write(data, 0, data.Length);
            }

            string responseData;
			using (var response = (HttpWebResponse)request.GetResponse())
            {
                using (var dataStream = response.GetResponseStream())
                {
                    using (var reader = new StreamReader(dataStream))
                    {
                        responseData = reader.ReadToEnd();
                    }
                }
            }
            return responseData;
		}

		public static BlockchainInfo GetInfo()
		{
			var jsonString = GetRequest(getInfoMethod);

			var blockchainInfo = JsonConvert.DeserializeObject<BlockchainInfo>(jsonString);

			return blockchainInfo;
		}

		public static AccountInfo GetAccount(string accountName)
		{
			var postData = JsonConvert.SerializeObject(new { account_name = accountName });

			var resultJson = PostRequest(getAccountMethod, postData);

			var accountInfo = JsonConvert.DeserializeObject<AccountInfo>(resultJson);

			return accountInfo;
		}
	}
}
