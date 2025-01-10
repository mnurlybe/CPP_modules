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

std::string int_to_string(int number) {
    std::ostringstream ss;
    ss << number;
    return ss.str();
}

template <typename T> void PmergeMe::FordJohnsonSort(T &container) 
{
    /*------------ SECTION 1: Recursively Sort Pairs -----------*/
    int recursion_counter;
    recursion_counter = RecursivePairSort(container, 1, 0);
    std::cout << "Recursion level: " << recursion_counter << std::endl;

    std::cout << "\033[1;33m" << "After RecursivePairSort: ";
    printFullContainer(container);
    /*---------------------SECTION 1: END---------------------*/

    /*--------SECTION 2: Initilize main, pend, odd arrays--------*/
    typedef typename T::iterator _it;
    std::vector<_it> main;
    std::vector<_it> pend;
    std::vector<_it> odd;
    int recursion_level = std::pow(2, recursion_counter);
    // recursion_level = 2; // for testing purposes to replaces by a loop
    // write in blue
    while (recursion_level >= 1)
    {
        std::cout << "\033[1;34m" << "RECURSION LEVEL: " << recursion_level << "\033[0m" << std::endl;
        InitializeArraysV2(container, main, pend, odd, recursion_level);

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
        /*---------------------SECTION 2: END---------------------*/

        /*--------SECTION 3: Store original state and labels--------*/
        std::vector<Element> original_main;
        std::vector<Element> original_pend;
        // Store main elements with labels
        for (size_t i = 0; i < main.size(); ++i) {
            Element elem;
            elem.value = *main[i];
            if (i == 0)
                elem.label = "b1";
            else
                elem.label = "a" + int_to_string(i);  // a1, a2, etc.
            original_main.push_back(elem);
        }
        // Store pend elements with labels
        for (size_t i = 0; i < pend.size(); ++i) {
            Element elem;
            elem.value = *pend[i];
            elem.label = "b" + int_to_string(i + 2);  // b2, b3, etc.
            original_pend.push_back(elem);
        }
        /*---------------------SECTION 3: END---------------------*/

        /*--------SECTION 4: Perform insertion on main, pend, odd--------*/
        int jacobstal_index = 2;
        long jacobsthal_prev = get_jacobsthal(jacobstal_index);
        jacobstal_index++;
        long jacobsthal_curr = get_jacobsthal(jacobstal_index);
        // write in green
        std::cout << "\033[1;32m" << "jacobsthal_prev: " << jacobsthal_prev << ", jacobsthal_curr: " << jacobsthal_curr << "\033[0m" << std::endl;
        
        int num_of_insertions = jacobsthal_curr - jacobsthal_prev;
        int insertion_counter = 0;
        bool is_jacobsthal = true;
        while (!pend.empty()) { 
            if (num_of_insertions > static_cast<int>(pend.size())) {
                std::cout << "Number of insertions is greater than pend size: " << pend.size() << std::endl;
                insertion_counter -= num_of_insertions;
                num_of_insertions = pend.size();
                is_jacobsthal = false;
                // break;
            }
            while (num_of_insertions-- > 0 && !pend.empty()) {
                size_t b_index = num_of_insertions;
                /*get search_end value*/
                std::string b_label = "b" + int_to_string(b_index + 2 + insertion_counter);
                std::string a_label = "a" + int_to_string(b_index + 2 + insertion_counter);
                int a_value;
                for (size_t i = 0; i < original_main.size(); i++) {
                    if (original_main[i].label == a_label) {
                        a_value = original_main[i].value;
                        break;
                    }
                }
                // write in yellow
                std::cout << "\033[1;32m";
                std::cout << "b_index: " << b_index << "insertion_counter: " << insertion_counter << std::endl;
                std::cout << "b_label: " << b_label << ", a_label: " << a_label << ", a_value: " << a_value << std::endl;
                std::cout << "\033[0m";
                InsertionV2(container, main, pend, b_index, a_value, recursion_level, is_jacobsthal);
                /*----------------- Printing Main, Pend, Odd arrays -----------------*/
                std::cout << "\033[1;31m";
                std::cout << "Main (" << main.size() << ") :";
                for (size_t i = 0; i < main.size(); i++) {
                    std::cout << *main[i] << " ";
                }
                std::cout << "; Pend (" << pend.size() << ") :";
                for (size_t i = 0; i < pend.size(); i++) {
                    std::cout << *pend[i] << " ";
                }
                std::cout << "; Odd (" << odd.size() << ") :";
                for (size_t i = 0; i < odd.size(); i++) {
                    std::cout << *odd[i] << " ";
                }
                std::cout << "\033[0m" << std::endl;
            }
            jacobsthal_prev = jacobsthal_curr;
            jacobstal_index++;
            jacobsthal_curr = get_jacobsthal(jacobstal_index);
            num_of_insertions = jacobsthal_curr - jacobsthal_prev;
            insertion_counter += num_of_insertions;
        }

        // handle odd
        if (!odd.empty()) {
            InsertOdd(container, main, odd, recursion_level);
        }

        /*---------------------SECTION 4: END---------------------*/

        /*--------SECTION 5: Update the original container with new order --------*/
        // Use copy vector to store all the numbers, in order not to overwrite the original iterators.
        std::vector<int> copy;
        copy.reserve(container.size());
        for (typename std::vector<_it>::iterator it = main.begin(); it != main.end(); it++)
        {
            for (int i = 0; i < recursion_level; i++)
            {
                _it pair_start = *it;
                std::advance(pair_start, -recursion_level + i + 1);
                copy.insert(copy.end(), *pair_start);
            }
        }

        std::cout << "Copy: ";
        printFullContainer(copy);

        // Replace values in the original container.
        _it container_it = container.begin();
        std::vector<int>::iterator copy_it = copy.begin();
        while (copy_it != copy.end())
        {
            *container_it = *copy_it;
            container_it++;
            copy_it++;
        }    
        std::cout << "\033[1;33m";
        printFullContainer(container);
        std::cout << "\033[0m";
        /*---------------------SECTION 5: END---------------------*/
        recursion_level /= 2;
    }
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
    typedef typename T::iterator _it;
    _it comparison_area_start = container.begin();
    _it end = my_next(comparison_area_start, num_of_comparison_units * recursion_level);
    // get the iterator to the element that will indicate the end of the comparison area
    _it comparison_area_end = my_next(end, -(is_odd * recursion_level));

    for (_it i = comparison_area_start; i != comparison_area_end; std::advance(i, 2 * recursion_level)) {
        // last element of the first unit
        _it first_unit_end = my_next(i, recursion_level - 1);    
        // last element of the second unit
        _it second_unit_end = my_next(my_next(i, recursion_level), recursion_level - 1);

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
    main.clear();
    pend.clear();
    odd.clear();                                    
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
                            int a_value,
                            int recursion_level,
                            bool is_jacobsthal) {
    
    (void)container;
    typedef typename T::iterator _it;
    typedef typename T::value_type Value;
    _it group_last = pend[b_index];
    _it group_first = my_next(group_last, -(recursion_level-1));

    std::cout << "Group first: " << *group_first << ", Group last: " << *group_last << std::endl;
    Value compare_value = *group_last;

    typename std::vector<_it>::iterator search_end;
    if (is_jacobsthal == false) {
        search_end = main.end() - 1;
    } else {
        for (search_end = main.begin(); search_end != main.end(); ++search_end) {
            if (**search_end == a_value) break;
        }
    }
    std::cout << "Compare value: " << compare_value << std::endl;
    std::cout << "Search end: " << **search_end << std::endl;

    /* -------------- Binary Search Implementation ---------------- */
    typename std::vector<_it>::iterator insert_pos = main.begin();
    typename std::vector<_it>::iterator left = main.begin();
    typename std::vector<_it>::iterator right = search_end;


    while (left != right) {
        typename std::vector<_it>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        
        if (**mid < compare_value) {
            left = mid;
            ++left;
        } else {
            right = mid;
        }
    }
    insert_pos = left;
    std::cout << "main_insert_pos_value: " << **insert_pos << std::endl;

    main.insert(insert_pos, group_last);
    pend.erase(pend.begin() + b_index);

}

template <typename T>
void PmergeMe::InsertOdd(T &container,
                        std::vector<typename T::iterator>& main,
                        std::vector<typename T::iterator>& odd,
                        int recursion_level) {
    
    (void)container;
    std::cout << "\nInserting odd" << std::endl;
    typedef typename T::iterator _it;
    typedef typename T::value_type Value;

    // there is only one group in odd array
    _it group_last = odd[0];
    _it group_first = my_next(group_last, -(recursion_level - 1));

    std::cout << "Group first: " << *group_first << ", Group last: " << *group_last << std::endl;
    Value compare_value = *group_last;

    typename std::vector<_it>::iterator search_end;
    search_end = main.end() - 1;

    std::cout << "Compare value: " << compare_value << std::endl;
    std::cout << "Search end: " << **search_end << std::endl;

    /* -------------- Binary Search Implementation ---------------- */
    typename std::vector<_it>::iterator insert_pos = main.begin();
    typename std::vector<_it>::iterator left = main.begin();
    typename std::vector<_it>::iterator right = search_end;

    while (left != right) {
        typename std::vector<_it>::iterator mid = left;
        std::advance(mid, std::distance(left, right) / 2);
        
        if (**mid < compare_value) {
            left = mid;
            ++left;
        } else {
            right = mid;
        }
    }
    insert_pos = left;

    // handle the case when the odd element is the largest
    if (compare_value > **search_end) {
        main.insert(main.end(), group_last);
        odd.erase(odd.begin());
        return;
    }

    std::cout << "main_insert_pos_value: " << **insert_pos << std::endl;
    main.insert(insert_pos, group_last);
    odd.erase(odd.begin());
}

/* -------------- Utils ---------------- */

// print full Container
template <typename T>
void PmergeMe::printFullContainer(T &container) {
    typename T::const_iterator _it;
    int i = 0;
    for (_it = container.begin(); _it != container.end(); ++_it) {
        std::cout << *_it << " ";
        i++;
    }
    std::cout << std::endl;
}

// print Container
template <typename T>
void PmergeMe::printContainer(T &container) {
    typename T::const_iterator _it;
    int i = 0;
    for (_it = container.begin(); _it != container.end(); ++_it) {
        std::cout << *_it << " ";
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
