#include <airdroptoken.hpp>
using namespace ::airdrop;

void airdroptoken::totalsupply(account_name user) {
    account_name account = current_sender();
    require_recipient(user);
    print("Total supply: ", publication_time());
}

void airdroptoken::balanceof(account_name user) {
    auto user_iterator = _accounts.find(user);
    eosio_assert(user_iterator != _accounts.end(), "that user doesn't exist");
    print("User ", name{(*user_iterator).owner}, " have ", (*user_iterator).balance);
}

void airdroptoken::issue(uint64_t tokens) {
    require_auth(_self);
    auto owner_iterator = _accounts.find(_self);
    if (owner_iterator == _accounts.end()) {
        _accounts.emplace(_self, [&](auto& a) {
            a.owner = _self;
            a.balance = tokens;
        });
    } else {
        _accounts.modify(owner_iterator, 0, [&](auto& a) {
            a.balance += tokens;
            eosio_assert(a.balance >= tokens, "overflow detected");
        });
    }
}

void airdroptoken::transfer(account_name from, account_name to, uint64_t tokens) {
    require_auth(from);

    auto from_iterator = _accounts.find(from);
    account account = *from_iterator;

    eosio_assert(!(from_iterator == _accounts.end()), "you doesn't have account");
    eosio_assert(account.balance >= tokens, "overdrawn balance");

    auto to_iterator = _accounts.find(to);
    if(to_iterator == _accounts.end()) {
        _accounts.modify(from_iterator, 0, [&](auto& a) {
            a.balance -= tokens;
        });
        _accounts.emplace(_self, [&](auto& a) {
            a.owner = to;
            a.balance = tokens;
        });
    } else {
        _accounts.modify(from_iterator, 0, [&](auto& a) {
            a.balance -= tokens;
        });
        _accounts.modify(to_iterator, 0, [&](auto& a) {
            a.balance += tokens;
            eosio_assert(a.balance >= tokens, "overflow detected");
        });
    }

}


EOSIO_ABI(airdroptoken, (totalsupply)(balanceof)(transfer)(issue))