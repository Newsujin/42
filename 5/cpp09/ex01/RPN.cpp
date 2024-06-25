#include "RPN.hpp"

RPN::RPN() : _result(0) {}

RPN::RPN(const RPN& rhs) { *this = rhs; }

RPN& RPN::operator=(const RPN& rhs) {
	if (this != &rhs) {
		_result = rhs._result;
		_stack = rhs._stack;
	}
	return (*this);
}

RPN::~RPN() {}

void RPN::execute(const std::string& str) {
    for (size_t i = 0; i < str.size(); i++) {
		if (str[i] == ' ') continue;

		if ((str[i] == '+' || str[i] == '-') && isdigit(str[i + 1]))
			throw std::logic_error("wrong number!");
			
		if (isdigit(str[i]))
			_stack.push(str[i] - '0');
		else if (isOperator(str[i])) {
			if (_stack.size() < 2)
				throw std::logic_error("insufficient values to operate!");

			int n2 = _stack.top(); _stack.pop();
			int n1 = _stack.top(); _stack.pop();
			_stack.push(performOperator(str[i], n1, n2));
		}
		else
			throw std::logic_error("invalid argument!");
	}

	if (_stack.size() != 1)
		throw std::logic_error("fail to calculate!");

	_result = _stack.top();
	_stack.pop();
}

bool RPN::isOperator(char token) const {
    return (token == '+' || token == '-' || token == '*' || token == '/');
}

int RPN::performOperator(char op, int n1, int n2) const {
    switch (op) {
        case '+': return n1 + n2;
        case '-': return n1 - n2;
        case '*': return n1 * n2;
        case '/':
            if (n2 == 0)
                throw std::logic_error("division by zero!");
            return (n1 / n2);
        default:
            throw std::logic_error("wrong operator!");
    }
}

int RPN::getResult() const {
    return (_result);
}
