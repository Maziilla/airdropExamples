#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
using namespace ::eosio;

namespace eosairdrop {
    class airdrop : public eosio::contract {
        public:
            using contract::contract;
            
            airdrop(account_name self):
                contract(self) {}

            void testcall(account_name name);
            void test(account_name name);
    };
}