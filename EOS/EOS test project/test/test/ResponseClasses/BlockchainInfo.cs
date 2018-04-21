using System;
namespace test.ResponseClasses
{
    public class BlockchainInfo
    {
		public string server_version { get; set; }
		public int head_block_num { get; set; }
		public int last_irreversible_block_num { get; set; }
		public string head_block_id { get; set; }
		public string head_block_time { get; set; }
		public string head_block_producer { get; set; }
		public string recent_slots { get; set; }
		public string participation_rate { get; set; }
    }
}
