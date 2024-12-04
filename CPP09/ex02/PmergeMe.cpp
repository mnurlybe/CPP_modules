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

    clock_t start, stop;

    // write in green
    std::cout << "\033[1;32m" << "Vector sorting" << "\033[0m" << std::endl;
    std::cout << "Before: ";
    printVector(_vector);
    start = clock();
    this->mergeInsertSortVector(0, _vector.size() - 1);
    stop = clock();
    std::cout << "After: ";
    printVector(_vector);
    std::cout << "Time to process a range of " << _vector.size() << " elements with std::vector : ";
    std::cout << "\033[1;33m" << static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << std::endl << std::endl;

    std::cout << "\033[1;32m" << "Deque sorting" << "\033[0m" << std::endl;
    std::cout << "Before: ";
    printDeque(_deque);
    start = clock();
    this->mergeInsertSortDeque(0, _deque.size() - 1);
    stop = clock();
    std::cout << "After: ";
    printDeque(_deque);
    std::cout << "Time to process a range of " << _deque.size() << " elements with std::deque : ";
    std::cout << "\033[1;33m" << static_cast<double>(stop - start) / CLOCKS_PER_SEC * 1000 << " milliseconds" << std::endl;
}

void PmergeMe::mergeInsertSortVector(int left, int right) {
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
    this->mergeInsertSortVector(left, mid);
    this->mergeInsertSortVector(mid + 1, right);

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

void PmergeMe::mergeInsertSortDeque(int left, int right) {
    if (left >= right) return;  // Base case: single element or empty range

    // If the size of the segment is small enough, use insertion sort
    if (right - left + 1 <= THRESHOLD) {
        for (int i = left + 1; i <= right; ++i) {
            int key = _deque[i];
            int j = i - 1;

            // Shift elements of the sorted segment to make space for the key
            while (j >= left && _deque[j] > key) {
                _deque[j + 1] = _deque[j];
                --j;
            }
            _deque[j + 1] = key;  // Insert key in its correct position
        }
        return;
    }

    // Recursive case: divide the array
    int mid = left + (right - left) / 2;

    // Recursively sort both halves
    this->mergeInsertSortDeque(left, mid);
    this->mergeInsertSortDeque(mid + 1, right);

    // Merge the two sorted halves
    std::vector<int> temp;
    int i = left, j = mid + 1;

    // Merge logic
    while (i <= mid && j <= right) {
        if (_deque[i] <= _deque[j]) {
            temp.push_back(_deque[i++]);
        } else {
            temp.push_back(_deque[j++]);
        }
    }

    // Copy remaining elements from the left half
    while (i <= mid) temp.push_back(_deque[i++]);

    // Copy remaining elements from the right half
    while (j <= right) temp.push_back(_deque[j++]);

    // Copy the sorted elements back to the original array
    for (int k = left; k <= right; ++k) {
        _deque[k] = temp[k - left];
    }
}

/* -------------- Utils ---------------- */

void PmergeMe::printVector(std::vector<int> arr) {
    std::vector<int>::const_iterator it;
    int i = 0;
    for (it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
        if (i == 10) {
            std::cout << "[ ... ]";
            break;
        }
        i++;
    }
    std::cout << std::endl;
}

void PmergeMe::printDeque(std::deque<int> arr) {
    std::deque<int>::const_iterator it;
    int i = 0;
    for (it = arr.begin(); it != arr.end(); ++it) {
        std::cout << *it << " ";
        if (i == 10) {
            std::cout << "[ ... ]";
            break;
        }
        i++;
    }
    std::cout << std::endl;
}

std::vector<int> PmergeMe::getVector() const {
    return _vector;
}

std::deque<int> PmergeMe::getDeque() const {
    return _deque;
}
