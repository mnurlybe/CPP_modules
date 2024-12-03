#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <vector>
#include <algorithm>

class NotFoundException : public std::exception {
    const char* what() const throw() {
        return "Element not found\n";
    }
};

template <typename T>
void easyfind(T  &containter, int num) {
    // typename T::iterator it = std::find(containter.begin(), containter.end(), num);
    if (std::find(containter.begin(), containter.end(), num) == containter.end())
        throw NotFoundException();
    int pos = std::distance(containter.begin(), std::find(containter.begin(), containter.end(), num));
    std::cout << "Element " << num << " was found at position " << pos << std::endl;
}

#endif