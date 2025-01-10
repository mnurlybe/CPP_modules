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
        typename std::vector<container_iterator>::iterator pend_it = my_next(pend.begin(), num_of_insertions - 1);
        typename std::vector<container_iterator>::iterator bound_it =
            my_next(main.begin(), jacobsthal + total_insertions);  
        while (num_of_insertions-- > 0 && !pend.empty()) {
            InsertionV2(container, main, main_copy, pend, pend_copy, num_of_insertions, recursion_level, bound_it, pend_it);
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


// template <typename T>
// bool PmergeMe::_comp(T lv, T rv) { return *lv < *rv; };

template <typename T>
void PmergeMe::InsertionV2(T &container, 
                            std::vector<typename T::iterator>& main,
                            std::vector<typename T::iterator>& main_copy,  
                            std::vector<typename T::iterator>& pend,
                            std::vector<typename T::iterator>& pend_copy,
                            size_t b_index,
                            int recursion_level,
                            typename std::vector<typename T::iterator>::iterator bound_it,
                            typename std::vector<typename T::iterator>::iterator pend_it) {

    typedef typename T::iterator it;
    typedef typename T::value_type Value;
    it group_last = pend[b_index];
    it group_first = my_next(group_last, -(recursion_level-1));

    std::cout << "Group first: " << *group_first << ", Group last: " << *group_last << std::endl;
    Value compare_value = *group_last;
    std::cout << "Compare value: " << compare_value << std::endl;

    (void)pend_copy;
    (void)main_copy;

    // size_t a_pos = b_index + 2 + total_insertions;
    size_t a_pos = b_index + 2;
    typename std::vector<it>::iterator search_end = main.begin();
    for (size_t i = 0; i < a_pos && search_end != main.end(); ++i) {
        ++search_end;
    }
    (void)pend_it;
    // typename std::vector<it>::iterator idx =
    //             std::upper_bound(main.begin(), bound_it, *pend_it, _comp<it>);
    std::cout << "Search end: " << **bound_it << std::endl;
    // std::cout << "Index: " << **idx << std::endl;

    

    // Binary search implementation
    typename std::vector<it>::iterator left_bound = main.begin();
    typename std::vector<it>::iterator right_bound = search_end;
    while (left_bound != right_bound) {
        typename std::vector<it>::iterator mid = left_bound + std::distance(left_bound, right_bound) / 2;
        if (**mid < compare_value) {
            left_bound = mid + 1;
        } else {
            right_bound = mid;
        }
    }

    typename std::vector<it>::iterator insert_pos = left_bound;
    std::cout << "Insert pos: " << **insert_pos << std::endl;

    // here we start working with the original container

    // Calculate the target position in the container
    size_t target_pos = 0;
    for (it it = container.begin(); it != *insert_pos; ++it) {
        ++target_pos;
    }
    target_pos = (target_pos / recursion_level) * recursion_level;
    std::cout << "Container target pos: " << target_pos << std::endl;

    // Move the group to the target position
    // moveGroup(container, std::distance(container.begin(), group_first), recursion_level, target_pos);
    // std::cout << "\033[1;33m";
    // printFullContainer(container);
    // std::cout << "\033[0m";

    std::cout << "-----------------------" << std::endl;

    pend.erase(pend.begin() + b_index);

}

// int CalculateInsertPos(int main_index, int recursion_level) {
//     if (main_index == 0) return 0;
//     else if (main_index == 1) return recursion_level;
//     else return recursion_level + 2 * (main_index - 1) * recursion_level;
// }


// Insertion using Jacobsthal sequence and Binary search
// template <typename T>
// void PmergeMe::Insertion(T &container, int recursion_level) {

//     if (pend.empty()) {
//         std::cerr << "Pend is empty." << std::endl;
//         return; 
//     }

//     typedef typename std::vector<int>::iterator it;

//     if (pend.size() == 1) {
//         it pend_elem = pend.begin();
//         std::cout << "Pend element: " << *pend_elem << std::endl;
//         size_t pend_index = std::distance(pend.begin(), pend_elem);
//         // compare pend with main, pend element index is always compared against the main element index + 2, pend[0] is compared against main[2]
//         it main_search_area_end = my_next(main.begin(), pend_index + 2 + 1);
//         std::cout << "Main search area end: " << *main_search_area_end << std::endl;
//         int main_index = 0;
//         for (it main_elem = main.begin(); main_elem != main_search_area_end; ++main_elem) {
//             std::cout << "Main element: " << *main_elem << std::endl;
//             if (*pend_elem < *main_elem) 
//             {   
//                 main.insert(main_elem, *pend_elem);
//                 pend.erase(pend_elem);
//                 int group_start = (2 - 1) * recursion_level * 2;
//                 std::cout << "Group start: " << group_start << std::endl;
//                 int insert_pos = CalculateInsertPos(main_index, recursion_level);
//                 std::cout << "Insert pos: " << insert_pos << std::endl;
//                 moveGroup(container, group_start, recursion_level, insert_pos);
//                 break;
//             }
//             main_index++;
//         }
//     } 
//     else if (pend.size() > 1) {
//         // Compute Jacobsthal numbers up to the size of the container
//         std::vector<int> jacobsthal = computeJacobsthalNumbers(pend.size() + 1);
//         std::cout << "Jacobsthal sequence: ";
//         printFullContainer(jacobsthal);



//         // compare and insert pend with Jacobsthal sequence
//         // jacobsthal_i = 1;
//         // while (jacobsthal.size != 1){
//         //     int num_of_insertions = jacobsthal[jacobsthal_i] - jacobsthal[jacobsthal_i - 1];
//         //     std::cout << "Number of insertions: " << num_of_insertions << std::endl;
//         //     while (num_of_insertions-- > 0 && !pend.empty()) {
//         //         it pend_elem = my_next(pend.begin(), num_of_insertions - 1);
//         //         std::cout << "Pend element: " << *pend_elem << std::endl;
//         //     }
//         // }

//         for (size_t j = 1; j < jacobsthal.size() && !pend.empty(); ++j) {
//             int count = jacobsthal[j] - jacobsthal[j - 1];
//             while (count-- > 0 && !pend.empty()) {
//                 it pend_elem = my_next(pend.begin(), count);
//                 std::cout << "Pend element: " << *pend_elem << std::endl;
//                 size_t pend_index = std::distance(pend.begin(), pend_elem);
//                 it main_bound = my_next(main.begin(), getMainPairindex(pend_index) + 1);
//                 int main_index = 0;
//                 for (it main_elem = main.begin(); main_elem != main_bound; ++main_elem) {
//                     std::cout << "Main element: " << *main_elem << std::endl;
//                     if (*pend_elem < *main_elem) 
//                     {
//                         std::cout << "Inserting pend element: " << *pend_elem << std::endl;
//                         main.insert(main_elem, *pend_elem);
//                         // adjust main_pair_num to match the new main
//                         main_pair_num.insert(main_pair_num.begin() + main_index, pend_pair_num[pend_index]);
//                         std::cout << "Main pair num: ";
//                         printContainer(main_pair_num);
//                         std::cout << "Pend pair num: ";
//                         printContainer(pend_pair_num);
//                         int pend_pair_index = std::distance(pend_pair_num.begin(), pend_elem);
//                         int group_start = *pend_pair_index * recursion_level;
                        

//                         pend.erase(pend_elem);
//                         pend_pair_num.erase(pend_pair_num.begin() + pend_index);
//                         break;
//                     }
//                     main_index++;
//                 }
//             }
//         }

//     }

//     // compare odd against main, the search area will always be whole main, and handle it in the original container
//     int num_of_comparison_units = container.size() / recursion_level;
//     if (!odd.empty()) {
//         it odd_elem = odd.begin();
//         std::cout << "Odd element: " << *odd_elem << std::endl;
//         it main_search_area_end = my_next(main.begin(), main.size());
//         std::cout << "Main search area end: " << *main_search_area_end << std::endl;
//         int main_index = 0;
//         for (it main_elem = main.begin(); main_elem != main_search_area_end; ++main_elem) {
//             std::cout << "Main element: " << *main_elem << std::endl;
//             if (*odd_elem < *main_elem) 
//             {
//                 main.insert(main_elem, *odd_elem);
//                 odd.erase(odd_elem);
//                 int group_start = (num_of_comparison_units - 1) * recursion_level;
//                 std::cout << "Group start: " << group_start << std::endl;
//                 std::cout << "Main index: " << main_index << std::endl;
//                 int insert_pos = recursion_level * main_index;
//                 std::cout << "Insert pos: " << insert_pos << std::endl;
//                 moveGroup(container, group_start, recursion_level, insert_pos);
//                 break;
//             }
//             main_index++;
//         }
//     }

// //    write in red
//     std::cout << "\033[1;31m" << "Main (" << main.size() << ") :";
//     printFullContainer(main);
//     std::cout << "Pend (" << pend.size() << ") :";
//     printFullContainer(pend);
//     std::cout << "Odd (" << odd.size() << ") :";
//     printFullContainer(odd);
//     std::cout << "Leftovers (" << leftovers.size() << ") :";
//     printFullContainer(leftovers);
//     std::cout << "\033[0m";
//     std::cout << std::endl;       

//     std::cout << "\033[1;32m" << "====== END OF RECURSION LEVEL " << recursion_level << "============" << "\033[0m" << std::endl;

// }

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


// {{6, 15}, {8, 16}, {2, 11}, {0, 17}, {9, 18}, {14, 19}, {5, 12}, {4, 20}, {3, 10}, {1, 21}, {7, 13}};
// {b1, a1, b2, a2, b3, a3, b4, a4, b5, a5, b6};