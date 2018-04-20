#include <airdroptoken.hpp>
#include <airdrop.hpp>
using namespace ::eosairdrop;

void airdrop::testcall(account_name name) {
    dispatch_inline(permission_level{name,N(active)}, _self, N(test), &airdrop::test, {name} );
}

void airdrop::test(account_name name) {
    require_recipient(name);
    print("Hello");
}

EOSIO_ABI(airdrop, (testcall)(test))