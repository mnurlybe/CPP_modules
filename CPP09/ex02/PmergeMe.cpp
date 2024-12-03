#include "PmergeMe.hpp"

PmergeMe::PmergeMe(int ac, char *av[]) {
    
    for (int i = 0; i < ac; ++i) {
        _vector.push_back(atoi(av[i]));
    } 
    // [ACTION] : add error management
}

PmergeMe::PmergeMe(const PmergeMe &source) {
    _vector = source._vector;
}

PmergeMe::~PmergeMe() {
    _vector.clear();
}

PmergeMe &PmergeMe::operator=(const PmergeMe &source) {
    if (this == &source) return *this;

    _vector = source._vector;
    return *this;
}

std::vector<int> PmergeMe::getVector() const {
    return _vector;
}

// Merge-Insert Sort implemented in one function
void PmergeMe::mergeInsertSort(int left, int right) {
    if (left >= right) return;  // Base case: single element or empty range

    // If the size of the segment is small enough, use insertion sort
    if (right - left + 1 <= THRESHOLD) {
        for (int i = left + 1; i <= right; ++i) {
            int key = _vector[i];
            int j = i - 1;

            // Shift elements of the sorted segment to make space for the key
            while (j >= left && _vector[j] > key) {
                _vector[j + 1] = _vector[j];
                --j;
            }
            _vector[j + 1] = key;  // Insert key in its correct position
        }
        return;
    }

    // Recursive case: divide the array
    int mid = left + (right - left) / 2;

    // Recursively sort both halves
    this->mergeInsertSort(left, mid);
    this->mergeInsertSort(mid + 1, right);

    // Merge the two sorted halves
    std::vector<int> temp;
    int i = left, j = mid + 1;

    // Merge logic
    while (i <= mid && j <= right) {
        if (_vector[i] <= _vector[j]) {
            temp.push_back(_vector[i++]);
        } else {
            temp.push_back(_vector[j++]);
        }
    }

    // Copy remaining elements from the left half
    while (i <= mid) temp.push_back(_vector[i++]);

    // Copy remaining elements from the right half
    while (j <= right) temp.push_back(_vector[j++]);

    // Copy the sorted elements back to the original array
    for (int k = left; k <= right; ++k) {
        _vector[k] = temp[k - left];
    }
}

// Utility function to print the array
void PmergeMe::printArray(const std::vector<int>& arr) {
    std::vector<int>::const_iterator it;
    for (it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}