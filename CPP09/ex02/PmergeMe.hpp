#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

# define THRESHOLD 3
# define INT_MAX 2147483647

class PmergeMe {
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        void mergeInsertSortVector(int left, int right);
        void mergeInsertSortDeque(int left, int right);
        void printVector(std::vector<int> arr);
        void printDeque(std::deque<int> arr);

    public:
        PmergeMe(int ac, char *av[]);
        PmergeMe(const PmergeMe &source);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &source);

        void Sort();

        std::vector<int> getVector() const;
        std::deque<int> getDeque() const;
        
};

#endif