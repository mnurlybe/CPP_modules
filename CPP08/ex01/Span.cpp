#include "Span.hpp"

Span::Span(unsigned int max_num) : N(max_num) {}

// Copy constructor
Span::Span(const Span &source) {
    this->N = source.N;
}

// Assignation operator
Span &Span::operator=(const Span &source) {
    if (this != &source) {
        this->N = source.N;
    }
    return *this;
}

Span::~Span() {}

const char *Span::FullException::what() const throw() {
    return "Container is full";
}

const char *Span::NoNumbersStoredException::what() const throw() {
    return "Container is empty";
}

const char *Span::NotEnoughElementsException::what() const throw() {
    return "Container has only one element";
}

const char *Span::NotEnoughSpaceException::what() const throw() {
    return "Container does not have enough space";
}

void Span::addNumber(int number) {
    if (numbers.size() >= N) {
        throw FullException();
    } else {
        numbers.push_back(number);
    }
}

int Span::shortestSpan() {
    
    if (numbers.size() == 0) {
        throw NoNumbersStoredException();
    } else if (numbers.size() == 1) {
        throw NotEnoughElementsException();
    }
    
    std::vector<int> sorted = numbers;
    std::sort(sorted.begin(), sorted.end());

    std::vector<int>::iterator it = sorted.begin();
    int shortest_span = std::abs(*(it + 1) - *it);

    if (sorted.size() == 2) {
        return shortest_span;
    }

    for (it = sorted.begin(); it != sorted.end() - 1; it++) {
        int span = std::abs(*(it + 1) - *it);
        if (span < shortest_span) {
            shortest_span = span;
        }
    }
    return shortest_span;
}

int Span::longestSpan() {

    if (numbers.size() == 0) {
        throw NoNumbersStoredException();
    } else if (numbers.size() == 1) {
        throw NotEnoughElementsException();
    }

    int max = *std::max_element(numbers.begin(), numbers.end());
    int min = *std::min_element(numbers.begin(), numbers.end());
    return max - min;
}

void Span::addRange(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    if (numbers.size() + std::distance(begin, end) > N) {
        throw FullException();
    } else {
        numbers.insert(numbers.end(), begin, end);
    }
}

void Span::printNumbers() {
    std::cout << "Numbers: ";
    for (std::vector<int>::iterator it = numbers.begin(); it != numbers.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}