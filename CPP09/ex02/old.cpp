

// void PmergeMe::mergeInsertSortVector(int left, int right) {
//     if (left >= right) return;  // Base case: single element or empty range

//     // If the size of the segment is small enough, use insertion sort
//     if (right - left + 1 <= THRESHOLD) {
//         for (int i = left + 1; i <= right; ++i) {
//             int key = _vector[i];
//             int j = i - 1;

//             // Shift elements of the sorted segment to make space for the key
//             while (j >= left && _vector[j] > key) {
//                 _vector[j + 1] = _vector[j];
//                 --j;
//             }
//             _vector[j + 1] = key;  // Insert key in its correct position
//         }
//         return;
//     }

//     // Recursive case: divide the array
//     int mid = left + (right - left) / 2;

//     // Recursively sort both halves
//     this->mergeInsertSortVector(left, mid);
//     this->mergeInsertSortVector(mid + 1, right);

//     // Merge the two sorted halves
//     std::vector<int> temp;
//     int i = left, j = mid + 1;

//     // Merge logic
//     while (i <= mid && j <= right) {
//         if (_vector[i] <= _vector[j]) {
//             temp.push_back(_vector[i++]);
//         } else {
//             temp.push_back(_vector[j++]);
//         }
//     }

//     // Copy remaining elements from the left half
//     while (i <= mid) temp.push_back(_vector[i++]);

//     // Copy remaining elements from the right half
//     while (j <= right) temp.push_back(_vector[j++]);

//     // Copy the sorted elements back to the original array
//     for (int k = left; k <= right; ++k) {
//         _vector[k] = temp[k - left];
//     }
// }

// void PmergeMe::mergeInsertSortDeque(int left, int right) {
//     if (left >= right) return;  // Base case: single element or empty range

//     // If the size of the segment is small enough, use insertion sort
//     if (right - left + 1 <= THRESHOLD) {
//         for (int i = left + 1; i <= right; ++i) {
//             int key = _deque[i];
//             int j = i - 1;

//             // Shift elements of the sorted segment to make space for the key
//             while (j >= left && _deque[j] > key) {
//                 _deque[j + 1] = _deque[j];
//                 --j;
//             }
//             _deque[j + 1] = key;  // Insert key in its correct position
//         }
//         return;
//     }

//     // Recursive case: divide the array
//     int mid = left + (right - left) / 2;

//     // Recursively sort both halves
//     this->mergeInsertSortDeque(left, mid);
//     this->mergeInsertSortDeque(mid + 1, right);

//     // Merge the two sorted halves
//     std::vector<int> temp;
//     int i = left, j = mid + 1;

//     // Merge logic
//     while (i <= mid && j <= right) {
//         if (_deque[i] <= _deque[j]) {
//             temp.push_back(_deque[i++]);
//         } else {
//             temp.push_back(_deque[j++]);
//         }
//     }

//     // Copy remaining elements from the left half
//     while (i <= mid) temp.push_back(_deque[i++]);

//     // Copy remaining elements from the right half
//     while (j <= right) temp.push_back(_deque[j++]);

//     // Copy the sorted elements back to the original array
//     for (int k = left; k <= right; ++k) {
//         _deque[k] = temp[k - left];
//     }
// }










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


