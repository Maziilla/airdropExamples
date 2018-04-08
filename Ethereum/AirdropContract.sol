pragma solidity 0.4.21;

import "./AirdropInterface.sol";
import "./SafeMath.sol";
import "./AirdropToken.sol";

contract AirdropContract is AirdropInterface {
    using SafeMath for uint;

    address private _owner;
    uint private _dateOfDistribution;
    mapping (address => bool) private _subscribers;
    mapping (address => bool) private _alreadyAirdrop;
    uint private _totalSubscribers;

    function subscribeForAirdrop() public returns (bool success) {
        require(_subscribers[msg.sender]);
        _subscribers[msg.sender] = true;
        _totalSubscribers++;
        return true;
    }

    function unsubscribeForAirdrop() public returns (bool success) {
        _subscribers[msg.sender] = false;
        _totalSubscribers--;
        return true;
    }

    function getAvailableTokens() public returns (uint tokens) {
        AirdropToken token = AirdropToken(_owner);
        return token.totalSupply().div(_totalSubscribers);
    }

    function getTokens() public returns (bool success) {
        require(now >= _dateOfDistribution);
        require(_subscribers[msg.sender]);
        require(!_alreadyAirdrop[msg.sender]);

        AirdropToken token = AirdropToken(_owner);
        uint tokenToDistribute = token.totalSupply().div(_totalSubscribers);

        token.transfer(msg.sender, tokenToDistribute);
        _alreadyAirdrop[msg.sender] = true;
        return true;
    }

    function AirdropContract() public {
        _owner = msg.sender;
        _dateOfDistribution = now + 60 * 60 * 24 * 30;
    }
}