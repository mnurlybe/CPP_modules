#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>
#include <exception>
#include <ctime>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(Array const &src);
        Array &operator=(Array const &src);
        ~Array();

        T &operator[](unsigned int index);
        const T &operator[](unsigned int index) const;

        class IndexOutOfBounds : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };

        unsigned int size(void) const;
};

#include "Array.tpp"

#endif