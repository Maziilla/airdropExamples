using System;
using System.Diagnostics;
using System.IO;
using System.Net;

namespace test
{
    class MainClass
    {
        public static void Main(string[] args)
        {
			Console.WriteLine(Blockchain.GetAccount("eosio"));
        }
    }
}
