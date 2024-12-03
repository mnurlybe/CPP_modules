#include "RPN.hpp"

RPN::RPN() {}
RPN::RPN(const RPN &source) { *this = source; }
RPN &RPN::operator=(const RPN &source) { 
    if (this == &source) 
        return *this;
    return *this;
}
RPN::~RPN() {}

void RPN::calculate(char *str)
{
    std::istringstream iss(str);
    std::string token;
    std::string operators = "+-*/";

    while (iss >> token){
        // std::cout << "{" << token << "} ";

        if (token.size() == 1 && std::isdigit(token[0])) {
            _stack.push(std::atoi(token.c_str()));
        } else if (token.size() == 1 && operators.find(token[0]) != std::string::npos) {
            if (_stack.size() < 2) {
                std::cerr << "Error: not enough operands." << std::endl;
                return;
            }

            int a = _stack.top();
            _stack.pop();
            int b = _stack.top();
            _stack.pop();

            if (token[0] == '+') _stack.push(b + a);
            else if (token[0] == '-') _stack.push(b - a);
            else if (token[0] == '*') _stack.push(b * a);
            else if (token[0] == '/') {
                if (a == 0) {
                    std::cerr << "Error: division by zero." << std::endl;
                    return;
                }
                _stack.push(b / a);
            }
        } else {
            std::cerr << "Error: invalid input." << std::endl;
            return;
        }
    }

    if (_stack.size() != 1) {
        std::cerr << "Error: too many operands." << std::endl;
        return;
    }

    std::cout << _stack.top() << std::endl;
}