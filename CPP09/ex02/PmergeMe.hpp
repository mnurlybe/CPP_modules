#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <cmath>
#include <cstdio>

# define THRESHOLD 3
# define INT_MAX 2147483647

class PmergeMe {

    public:
        PmergeMe(int ac, char *av[]);
        PmergeMe(const PmergeMe &source);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe &source);

        void Sort();

        /* -------------- Getters ---------------- */
        std::vector<int> getVector() const;
        std::deque<int> getDeque() const;

    private:
        std::vector<int> _vector;
        std::deque<int> _deque;

        template <typename T> 
        void FordJohnsonSort(T &container);

        template <typename T>
        int RecursivePairSort(T &container, int recursion_level, int recursion_counter);

        template <typename T>
        void InitializeArraysV2(T &container, 
                                std::vector<typename T::iterator>& main, 
                                std::vector<typename T::iterator>& pend,
                                std::vector<typename T::iterator>& odd,
                                int recursion_level);

        // template <typename T>
        // void Insertion(T &container, int recursion_level);

        template <typename T>
        void InsertionV2(T &container, 
                                    std::vector<typename T::iterator>& main,
                                    std::vector<typename T::iterator>& main_copy,
                                    std::vector<typename T::iterator>& pend,
                                    std::vector<typename T::iterator>& pend_copy,
                                    size_t b_index,
                                    int recursion_level,
                                    typename std::vector<typename T::iterator>::iterator bound_it,
                                    typename std::vector<typename T::iterator>::iterator pend_it);       

        // void mergeInsertSortDeque(int left, int right);
        // void mergeInsertSortDeque(int left, int right);

        /* -------------- Utils ---------------- */
        template <typename T> 
        void printFullContainer(T &container);
        template <typename T>
        void printContainer(T &container);

        template <typename T>
        void swapGroups(T &container, size_t start_pos, size_t group_size);

        template <typename T>
        void moveGroup(T &container, size_t group_start, size_t group_size, size_t insert_pos);

        template <typename Iterator>
        Iterator my_next(Iterator it, size_t n);

        template <typename T>
        bool _comp(T lv, T rv) { return *lv < *rv; };
};

#endif