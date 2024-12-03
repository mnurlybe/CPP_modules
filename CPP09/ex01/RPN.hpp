#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <stack>
#include <sstream>
#include <cstdlib>

class RPN {
    private:
        std::stack<int> _stack;
    public:
        RPN();
        RPN(const RPN &source);
        ~RPN();
        RPN &operator=(const RPN &source);
        void calculate(char *str);
};

#endif