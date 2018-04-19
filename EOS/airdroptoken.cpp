#include <airdroptoken.hpp>
using namespace airdrop;

void airdroptoken::supply(account_name user) {
    require_auth(user);
    
    _accounts.emplace(user, [&]( auto& a ) {
        a.name = user;
        a.balance = 100;
    });
    print("Total supply: ", total_supply);
}
void airdroptoken::moneyof(account_name user) {
    require_auth(user);
    const auto& usr = _accounts.get(user);
    print("Money: ", usr.balance);
}

EOSIO_ABI(airdroptoken, (supply)(moneyof))