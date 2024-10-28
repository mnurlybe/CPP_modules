#include "Array.hpp"

// Default constructor
template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

// Parametric constructor
template <typename T>
Array<T>::Array(unsigned int n) {
    _array = new T[n];
    _size = n;
}

// Copy constructor
template <typename T>
Array<T>::Array(Array const &src) {
    _size = src.size();
    _array = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
        _array[i] = src[i];
    }
}

// Assignment operator
template <typename T>
Array<T> &Array<T>::operator=(Array const &src) {
    if (this != &src) {
        _size = src.size();
        _array = new T[_size];
        for (unsigned int i = 0; i < _size; i++) {
            _array[i] = src[i];
        }
    }
    return *this;
}

// Destructor
template <typename T>
Array<T>::~Array() {
    delete[] _array;
    _array = NULL;
}

// Subscript operator []
template <typename T>
T &Array<T>::operator[](unsigned int index) {
    if (index < 0 || index >= _size) {
        throw IndexOutOfBounds();
    } else {
        return _array[index];
    }
}

// Const Subscript operator []
template <typename T>
const T &Array<T>::operator[](unsigned int index) const {
    if (index < 0 || index >= _size) {
        throw IndexOutOfBounds();
    } else {
        return _array[index];
    }
}

// Exception class
template <typename T>
const char *Array<T>::IndexOutOfBounds::what() const throw() {
    return "Index out of bounds";
}

// Size method
template <typename T>
unsigned int Array<T>::size(void) const {
    return _size;
}