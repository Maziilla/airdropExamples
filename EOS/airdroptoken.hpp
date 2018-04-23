#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
using namespace ::eosio;

namespace airdrop {
    class airdroptoken : public eosio::contract {
        public:
            using contract::contract;

            airdroptoken(account_name self): 
                contract(self), _accounts(_self, _self), total_supply(1000000000) {}

            void totalsupply(account_name user);

            void balanceof(account_name user);

            void transfer(account_name from, account_name to, uint64_t tokens);

            void issue(uint64_t tokens);

        private:
            struct account {
                account_name owner;
                uint64_t balance;

                uint64_t primary_key()const { return owner; }
            };
            eosio::multi_index<N(accounts), account> _accounts;

            uint64_t total_supply;
    };
}