using System;
using System.Collections.Generic;

namespace test.ResponseClasses
{
	public class Key
	{
		public string key { get; set; }
        public int weight { get; set; }
	}

	public class RequiredAuth
	{
        public int threshold { get; set; }
		public IList<Key> keys { get; set; }
		public IList<AccountInfo> accounts { get; set; }
	}

	public class Permission
	{
		public string perm_name { get; set; }
		public string parent { get; set; }
		public RequiredAuth required_auth { get; set; }
	}

    public class AccountInfo
	{
		public string account_name { get; set; }
        public IList<Permission> permissions { get; set; }
    }
}
