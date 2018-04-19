#include <airdroptoken.hpp>
using namespace airdrop;

void airdroptoken::supply(account_name user) {
    print("Total supply: ", total_supply);
}
void airdroptoken::a() {
}

EOSIO_ABI(airdroptoken, (supply)(a))