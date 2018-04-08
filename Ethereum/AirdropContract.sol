pragma solidity 0.4.21;

contract AirdropContract {
    address public owner;
    mapping (address => bool) private guysToAirdrop;

    modifier onlyOwner {
        require(msg.sender == owner);
        _;
    }

    function airdropContract() public {
        owner = msg.sender;
    }

    function contains(address sender) private constant returns(bool) {
        return guysToAirdrop[sender];
    }

    function accessToAirdrop() public {
        require(!contains(msg.sender));
        guysToAirdrop[msg.sender] = true;
    }
}