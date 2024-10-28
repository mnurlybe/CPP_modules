#ifndef WHATEVER_HPP
#define WHATEVER_HPP

#include <iostream>
#include <string>

/*function templates are a way to create
 a function that can work with any data type, 
 allowing you to write generic and reusable code. 
 A function template is defined with a special 
 syntax that includes the template keyword, 
 followed by a placeholder for the data type. 
 This placeholder can be used within the function 
 to represent any type that will be specified 
 later when the function is called.*/
 
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