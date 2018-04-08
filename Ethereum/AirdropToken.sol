pragma solidity 0.4.21;

import "./ERC20Interface.sol";
import "./SafeMath.sol";

contract AirdropToken is ERC20Interface {
    using SafeMath for uint;

    address private owner;
    uint private _totalSupply;

    mapping (address => uint) private _balances;
    mapping (address => mapping (address => uint)) private _allowed;

    function totalSupply() public constant returns (uint) {
        return _totalSupply;
    }

    function balanceOf(address tokenOwner) public constant returns (uint balance) {
        return _balances[tokenOwner];
    }

    function allowance(address tokenOwner, address spender) public constant returns (uint remaining) {
        return _allowed[tokenOwner][spender];
    }

    function transfer(address to, uint tokens) public returns (bool success) {
        address from = msg.sender;
        require(_balances[from] >= tokens);
        _balances[from].sub(tokens);
        _balances[to].add(tokens);
        emit Transfer(from, to, tokens);
        return true;
    }

    function approve(address spender, uint tokens) public returns (bool success) {
        address tokenOwner = msg.sender;
        _allowed[tokenOwner][spender] = tokens;
        emit Approval(tokenOwner, spender, tokens);
        return true;
    }

    function transferFrom(address from, address to, uint tokens) public returns (bool success) {
        require(_allowed[from][msg.sender] >= tokens);
        require(_balances[from] >= tokens);
        _balances[from].sub(tokens);
        _balances[to].add(tokens);
        _allowed[from][msg.sender].sub(tokens);
        emit Transfer(from, to, tokens);
        return true;
    }

    function AirdropToken() public {
        owner = msg.sender;
        _totalSupply = 1000000;
        _balances[owner] = _totalSupply;
    }
}