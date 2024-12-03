#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>

# define THRESHOLD 3
class PmergeMe {
    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

    public:
        PmergeMe(int ac, char *av[]);
        PmergeMe(const PmergeMe &source);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &source);

        void mergeInsertSort(int left, int right);
        static void printArray(const std::vector<int>& arr);
        std::vector<int> getVector() const;
        
};

#endif