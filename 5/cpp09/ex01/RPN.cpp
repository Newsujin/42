#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN& rhs) {}
RPN& RPN::operator=(const RPN& rhs) {}
RPN::~RPN() {}

void RPN::execute(std::string& str) {
    for ()
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
                throw std::logic_error("Error: division by zero!");
            return n1 / n2;
        default:
            throw std::logic_error("Error: wrong operator!");
    }
}

int RPN::getResult() const {
    return (result);
}
