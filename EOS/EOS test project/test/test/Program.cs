using System;
using System.Diagnostics;
using System.IO;
using System.Net;

namespace test
{
    class MainClass
    {
        public static void Main()
        {
			Console.WriteLine(Blockchain.GetAccount("eosio").account_name);//Blockchain.GetInfo().last_irreversible_block_num);
        }
    }
}
