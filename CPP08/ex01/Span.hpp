#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <exception>
#include <algorithm>
#include <cmath>
#include <ctime>


class Span {
    private: 
        unsigned int N;
        std::vector<int> numbers;
    
    public:
        Span(unsigned int N);
        Span(const Span &source);
        Span &operator=(const Span &source);
        ~Span();

        void addNumber(int number);
        int shortestSpan();
        int longestSpan();
        void addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end);
        void printNumbers();

    class FullException : public std::exception {
            const char *what() const throw();
    };

    class NoNumbersStoredException : public std::exception {
            const char *what() const throw();
    };

    class NotEnoughElementsException : public std::exception {
            const char *what() const throw();
    };  

    class NotEnoughSpaceException : public std::exception {
            const char *what() const throw();
    };        

};



#endif