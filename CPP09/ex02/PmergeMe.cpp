#include "PmergeMe.hpp"


/* ------------------- Orthodox Canonical From ------------------- */

PmergeMe::PmergeMe(int ac, char *av[]) {
    
        if (ac == 0) throw std::runtime_error("Error: No input provided.");

        for (int i = 0; i < ac; ++i) {
            std::string str(av[i]);
            
            if (str.empty()) continue;

            for (std::string::const_iterator it = str.begin(); it != str.end(); ++it) {
                if (std::isalpha(*it)) {
                    throw std::runtime_error("Error: Input contains alphabetic characters.");
                }
            }

            long num = std::atol(av[i]);

            if (num < 0)
                throw std::runtime_error("Error: Negative number is not allowed.");
            if (num > INT_MAX)
                throw std::runtime_error("Error: Number is too large.");
            _vector.push_back(static_cast<int>(num));
            _deque.push_back(static_cast<int>(num));
        } 
}

PmergeMe::PmergeMe(const PmergeMe &source) {
    _vector = source._vector;
    _deque = source._deque;
}

PmergeMe::~PmergeMe() {
    _vector.clear();
    _deque.clear();
}

PmergeMe &PmergeMe::operator=(const PmergeMe &source) {
    if (this == &source) return *this;

    _vector = source._vector;
    _deque = source._deque;
    return *this;
}

/* ------------------- Merge-Insert Sort Implementation ------------------- */

void PmergeMe::Sort() {

    // clock_t start, stop;

    // write in green
    std::cout << "\033[1;32m" << "Vector sorting" << "\033[0m" << std::endl;
    std::cout << "Before: ";
    printFullContainer(_vector);
    // start = clock();
    FordJohnsonSort(_vector);
    // stop = clock();
    // write in yellow
    // std::cout << "\033[1;33m" << "After: ";
    // printFullContainer(_vector);
    // std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : ";
    // std::cout << "\033[1;33m" << static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << std::endl << std::endl;

    // std::cout << "\033[1;32m" << "Deque sorting" << "\033[0m" << std::endl;
    // std::cout << "Before: ";
    // printFullContainer(_deque);
    // start = clock();
    // FordJohnsonSort(_deque);
    // stop = clock();
    // std::cout << "\033[1;33m" << "After: ";
    // printFullContainer(_deque);
    // std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : ";
    // std::cout << "\033[1;33m" << static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << std::endl;
}

long get_jacobsthal(long n) {
   if (n == 0) return 0;
   if (n == 1) return 1;
   return get_jacobsthal(n - 1) + 2 * get_jacobsthal(n - 2);
}

template <typename T> void PmergeMe::FordJohnsonSort(T &container) 
{
    int recursion_counter;
    recursion_counter = RecursivePairSort(container, 1, 0);
    std::cout << "Recursion level: " << recursion_counter << std::endl;

    std::cout << "\033[1;33m" << "After RecursivePairSort: ";
    printFullContainer(container);

    typedef typename T::iterator container_iterator;
    std::vector<container_iterator> main;
    std::vector<container_iterator> pend;
    std::vector<container_iterator> odd;
    int recursion_level = std::pow(2, recursion_counter);
    recursion_level = 2; // for testing purposes

    // InitializeArrays(container, 2);
    InitializeArraysV2(container, main, pend, odd, recursion_level);
    std::vector<container_iterator> main_copy;
    std::vector<container_iterator> pend_copy;
    main_copy.insert(main_copy.begin(), main.begin(), main.end());
    pend_copy.insert(pend_copy.begin(), pend.begin(), pend.end());

    /*----------------- Printing Main, Pend, Odd arrays -----------------*/
    std::cout << "\033[1;31m";
    std::cout << "Main (" << main.size() << ") :";
    for (size_t i = 0; i < main.size(); i++) {
        std::cout << *main[i] << " ";
    }
    std::cout << "Pend (" << pend.size() << ") :";
    for (size_t i = 0; i < pend.size(); i++) {
        std::cout << *pend[i] << " ";
    }
    std::cout << "Odd (" << odd.size() << ") :";
    for (size_t i = 0; i < odd.size(); i++) {
        std::cout << *odd[i] << " ";
    }
    std::cout << "\033[0m" << std::endl;
    
    int jacobstal_index = 2;
    long jacobsthal_prev = get_jacobsthal(jacobstal_index);
    jacobstal_index++;
    long jacobsthal = get_jacobsthal(jacobstal_index);
    // write in green
    std::cout << "\033[1;32m" << "Jacobsthal Prev: " << jacobsthal_prev << ", Jacobsthal: " << jacobsthal << "\033[0m" << std::endl;
    
    int num_of_insertions = jacobsthal - jacobsthal_prev;
    int total_insertions = 0;
    while (!pend.empty()) {
        std::cout << "Number of insertions: " << num_of_insertions;
        std::cout << ", Pend size: " << pend.size() << std::endl;
        if (num_of_insertions > static_cast<int>(pend.size())) {
            std::cout << "Number of insertions is greater than pend size." << std::endl;
            break;
        }
        while (num_of_insertions-- > 0 && !pend.empty()) {
            InsertionV2(container, main, pend, num_of_insertions, recursion_level);
        }
        jacobsthal_prev = jacobsthal;
        jacobstal_index++;
        jacobsthal = get_jacobsthal(jacobstal_index);
        total_insertions += num_of_insertions;
        num_of_insertions = jacobsthal - jacobsthal_prev;
    }
    // start of the loop
    // int recursion_level = std::pow(2, recursion_counter);

    // while (recursion_level > 1) {
    //     InitializeArrays(container, recursion_level);
    //     Insertion(container, recursion_level);
    //     recursion_level--;
    // }
    // recursion_level = 2; // for testing purposes
 
    // InitializeArrays(container, 4);
    // Insertion(container, 4);
    // end of the loop

    // Insertion(container, 2);

}

/* this function will recursively create pairs and compare them against each other.
With every recursion, the elements in one unit will be doubled. */
template <typename T>
int PmergeMe::RecursivePairSort(T &container, int recursion_level, int recursion_counter)
{
    // calculate the number of units that consist of recursion_level elements
    // if recursion_level is 1, then we have 1 element in each unit
    // if recursion_level is 2, then we have 2 elements in each unit
    int num_of_comparison_units = container.size() / recursion_level;
    std::cout << "Recursion level: " << recursion_level;
    std::cout << "; Number of comparison units: " << num_of_comparison_units << std::endl;

    // if there is only one unit, then there is nothing to compare, we break from the recursion
    if (num_of_comparison_units < 2) return recursion_counter;

    bool is_odd = false;
    if (num_of_comparison_units % 2 != 0)
        is_odd = true;

    // create iterator
    typedef typename T::iterator it;
    it comparison_area_start = container.begin();
    it end = my_next(comparison_area_start, num_of_comparison_units * recursion_level);
    // get the iterator to the element that will indicate the end of the comparison area
    it comparison_area_end = my_next(end, -(is_odd * recursion_level));

    for (it i = comparison_area_start; i != comparison_area_end; std::advance(i, 2 * recursion_level)) {
        // last element of the first unit
        it first_unit_end = my_next(i, recursion_level - 1);    
        // last element of the second unit
        it second_unit_end = my_next(my_next(i, recursion_level), recursion_level - 1);

        if (*first_unit_end > *second_unit_end) {
            size_t start_pos = std::distance(comparison_area_start, i);
            swapGroups(container, start_pos, 2 * recursion_level);
        }
    }

    recursion_level *= 2;
    recursion_counter++;
    return RecursivePairSort(container, recursion_level, recursion_counter);
}


template <typename T>
void PmergeMe::InitializeArraysV2(T &container, 
                                    std::vector<typename T::iterator>& main, 
                                    std::vector<typename T::iterator>& pend,
                                    std::vector<typename T::iterator>& odd,
                                    int recursion_level) {

    typename T::iterator container_it = container.begin();                                    

    int num_of_comparison_units = container.size() / recursion_level;
    if (num_of_comparison_units < 3) return;

    bool is_odd = false;
    if (num_of_comparison_units % 2 != 0)
        is_odd = true;

    if (is_odd) {
        num_of_comparison_units--;
    }

    // add b1 to main
    main.push_back(my_next(container_it, recursion_level - 1));

    // add a1, a2, a3, a4, a5, a6, a7, a8, a9, a10... to main
    int a = recursion_level;
    for (int i = 1; i < num_of_comparison_units; i += 2) {
        main.push_back(my_next(container_it, a + recursion_level - 1));
        a += 2 * recursion_level;
    }

    // add b2, b4, b6, b8, b10... to pend
    int b = 2 * recursion_level;
    for (int i = 2; i < num_of_comparison_units; i += 2) {
        pend.push_back(my_next(container_it, b + recursion_level - 1));
        b += 2 * recursion_level;
    }

    // add odd pair to odd
    if (is_odd) {
        odd.push_back(my_next(container_it, (num_of_comparison_units + 1) * recursion_level - 1));
    }
}


template <typename T>
void PmergeMe::InsertionV2(T &container, 
                            std::vector<typename T::iterator>& main,
                            std::vector<typename T::iterator>& pend,
                            size_t b_index,
                            int recursion_level) {
    
    (void)container;
    (void)main;
    typedef typename T::iterator it;
    typedef typename T::value_type Value;
    it group_last = pend[b_index];
    it group_first = my_next(group_last, -(recursion_level-1));

    std::cout << "Group first: " << *group_first << ", Group last: " << *group_last << std::endl;
    Value compare_value = *group_last;
    std::cout << "Compare value: " << compare_value << std::endl;

    pend.erase(pend.begin() + b_index);

}

/* -------------- Utils ---------------- */

// print full Container
template <typename T>
void PmergeMe::printFullContainer(T &container) {
    typename T::const_iterator it;
    int i = 0;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
        i++;
    }
    std::cout << std::endl;
}

// print Container
template <typename T>
void PmergeMe::printContainer(T &container) {
    typename T::const_iterator it;
    int i = 0;
    for (it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
        if (i == 10) {
            std::cout << "[ ... ]";
            break;
        }
        i++;
    }
    std::cout << std::endl;
}

// std::next is not available in C++98, therefore we need to implement it
template <typename Iterator>
Iterator PmergeMe::my_next(Iterator it, size_t n) {
    std::advance(it, n);
    return it;
}

// group size -> total size of two units that will be swapped
template <typename T>
void PmergeMe::swapGroups(T &container, size_t start_pos, size_t group_size) {
    size_t half_group_size = group_size / 2;

    // Perform the group swap
    for (size_t i = 0; i < half_group_size; ++i) {
        std::swap(container[start_pos + i], container[start_pos + half_group_size + i]);
    }
}

template <typename T>
void PmergeMe::moveGroup(T &container, size_t group_start, size_t group_size, size_t insert_pos) {
    // Check bounds
    if (group_start + group_size > container.size() || insert_pos > container.size()) {
        throw std::out_of_range("Indices out of range.");
    }

    // Define iterators for group range
    typename T::iterator group_start_it = container.begin();
    std::advance(group_start_it, group_start);

    typename T::iterator group_end_it = group_start_it;
    std::advance(group_end_it, group_size);

    // Extract the group into a temporary container
    std::vector<typename T::value_type> temp_group(group_start_it, group_end_it);

    // Erase the group from the original container
    container.erase(group_start_it, group_end_it);

    // Calculate the adjusted insertion position after erase
    if (group_start < insert_pos) {
        insert_pos -= group_size;
    }

    // Insert the group into the target position
    typename T::iterator insert_it = container.begin();
    std::advance(insert_it, insert_pos);

    container.insert(insert_it, temp_group.begin(), temp_group.end());
}

/* -------------- Getters ---------------- */
std::vector<int> PmergeMe::getVector() const {
    return _vector;
}

std::deque<int> PmergeMe::getDeque() const {
    return _deque;
}
