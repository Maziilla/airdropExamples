#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
using namespace ::eosio;

namespace airdrop {
    class airdroptoken : public eosio::contract {
        public:
            using contract::contract;

            airdroptoken(account_name self): contract(self), _accounts(_self, _self) {
                total_supply = 1000000;
            }

            void supply(account_name user);

            void moneyof(account_name user);

        private:
            struct account {
                account_name name;
                uint64_t balance;

                uint64_t primary_key()const { return name; }
            };
            eosio::multi_index<N(accounts), account> _accounts;

            uint64_t total_supply;
    };
}