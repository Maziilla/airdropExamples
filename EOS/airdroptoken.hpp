#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>
using namespace ::eosio;

namespace airdrop {
    class airdroptoken : public eosio::contract {
        public:
            using contract::contract;

            airdroptoken(account_name self): contract(self) {
                total_supply = 1000000;
            }

            void supply(account_name user);

            void a();

        private:
            struct account {
                account_name owner;
                uint64_t     balance;

                uint64_t primary_key()const { return owner; }
            };

            uint64_t total_supply;
    };
}