#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

template <typename T>
void swap( T &param1, T &param2 ) {
    T temp = param1;
    param1 = param2;
    param2 = temp;
}

template <typename T>
T min(const T param1, const T param2) {
    if (param1 < param2)
        return param1;
    return param2;
}

template <typename T>
T max(const T param1, const T param2) {
    if (param1 > param2)
        return param1;
    return param2;
}

#endif