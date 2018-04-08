pragma solidity 0.4.21;

contract AirdropInterface {
    function subscribeForAirdrop() public returns (bool success);
    function unsubscribeForAirdrop() public returns (bool success);
    function getAvailableTokens() public returns (uint tokens);
    function getTokens() public returns (bool success);
}