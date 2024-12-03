#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <algorithm>
#include <list>


template <typename T>
class MutantStack : public std::stack<T>
{
    public:

        MutantStack() {};
        MutantStack(const MutantStack &source) : std::stack<T>(source) {}
        MutantStack &operator=(const MutantStack &source) {
            if (this == &source)
                return *this;
            this->c = source.c;
            return *this;
        }
        ~MutantStack() {};

    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return this->c.begin();
    }

    iterator end() {
        return this->c.end();
    }
};

#endif