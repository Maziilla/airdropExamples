using System;
using System.Collections.Specialized;
using System.IO;
using System.Net;
using System.Text;

namespace test
{
	public static class Blockchain
	{
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
            using (var dataStream = response.GetResponseStream())
            using (var reader = new StreamReader(dataStream))
                responseData = reader.ReadToEnd();
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
            using (var dataStream = response.GetResponseStream())
            using (var reader = new StreamReader(dataStream))
                responseData = reader.ReadToEnd();
            return responseData;
		}

		public static string GetInfo()
		{
			return GetRequest("get_info");
		}

		public static string GetAccount(string accountName)
		{
			var postData = $"{{\"account_name\":\"{accountName}\"}}";

			return PostRequest("get_account", postData);
		}
	}
}
