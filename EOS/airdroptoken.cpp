#include <eosiolib/eosio.hpp>
#include <eosiolib/print.hpp>

namespace airdrop {
    class airdroptoken : public eosio::contract {
        public:
            airdroptoken(account_name self): 
            contract(self), _balances(self, self), _allowed(self, self) {
                total_supply = 1000000;
                _balances.emplace(0, [&]( auto& a ) {
                    a.owner = self;
                    a.balance = total_supply;
                });
            }

            void balance_of(account_name token_owner) {
                auto account = _balances.find(token_owner);
                eosio::print("Balance: ", (*account).balance);
            }

        private:
            struct account {
                account_name owner;
                uint64_t     balance;

                uint64_t primary_key()const { return owner; }
            };

            struct account_allowed {
                account_name owner;
                eosio::multi_index<N(allowed), account> _allowed;

                uint64_t primary_key()const { return owner; }
            };

            eosio::multi_index<N(accounts), account> _balances;
            eosio::multi_index<N(allowed), account_allowed> _allowed;
            long total_supply;
            account_name contract_owner;
    };
}

EOSIO_ABI(airdrop::airdroptoken, (balance_of))