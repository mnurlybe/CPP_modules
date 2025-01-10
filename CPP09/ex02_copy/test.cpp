#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <iterator>

// Generate Jacobsthal numbers
std::vector<int> generateJacobsthalSequence(int max) {
    std::vector<int> jacobsthal;
    jacobsthal.push_back(1); // Start with 1
    jacobsthal.push_back(3); // Then 3
    while (jacobsthal.back() < max) {
        int size = jacobsthal.size();
        jacobsthal.push_back(2 * jacobsthal[size - 1] + jacobsthal[size - 2]);
    }
    return jacobsthal;
}

// Perform Jacobsthal insertion and group movement
template <typename Container>
void jacobsthalInsertionSort(Container& original, int recursionLevel) {
    typedef typename Container::iterator Iterator;

    // Create groups
    int groupSize = recursionLevel;
    std::vector<std::pair<int, int> > groups;
    for (size_t i = 0; i < original.size(); i += groupSize) {
        groups.push_back(std::make_pair(i, std::min(static_cast<int>(i + groupSize), static_cast<int>(original.size()))));
    }

    // Initialize main and pend
    std::vector<int> main, pend;
    for (size_t i = 0; i < groups.size(); ++i) {
        if (i % 2 == 0) { // a group
            main.push_back(original[groups[i].second - 1]);
        } else { // b group
            pend.push_back(original[groups[i].second - 1]);
        }
    }

    // Sort main and pend using Jacobsthal sequence
    std::vector<int> jacobsthal = generateJacobsthalSequence(static_cast<int>(pend.size()));
    for (size_t j = 1; j < jacobsthal.size() && !pend.empty(); ++j) {
        int count = jacobsthal[j] - jacobsthal[j - 1];
        while (count-- > 0 && !pend.empty()) {
            int pendElem = pend.back();
            pend.pop_back();

            // Find position in main to insert
            Iterator it = std::lower_bound(main.begin(), main.end(), pendElem);
            main.insert(it, pendElem);

            // Move group in the original container
            for (size_t k = 0; k < groups.size(); ++k) {
                if (original[groups[k].second - 1] == pendElem) {
                    // Extract group to move
                    Container groupToMove(original.begin() + groups[k].first, original.begin() + groups[k].second);
                    original.erase(original.begin() + groups[k].first, original.begin() + groups[k].second);

                    // Calculate insert position in the original array
                    int insertIndex = (it - main.begin()) * groupSize;
                    original.insert(original.begin() + insertIndex, groupToMove.begin(), groupToMove.end());
                    break;
                }
            }
        }
    }

    // Print results
    std::cout << "Main: ";
    for (size_t i = 0; i < main.size(); ++i) {
        std::cout << main[i] << " ";
    }
    std::cout << "\nOriginal Array: ";
    for (Iterator it = original.begin(); it != original.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";
}

int main() {
    std::vector<int> originalVector = {6, 15, 8, 16, 2, 11, 0, 17, 9, 18, 14, 19, 5, 12, 4, 20, 3, 10, 1, 21, 7, 13};
    std::deque<int> originalDeque(originalVector.begin(), originalVector.end());
    int recursionLevel = 2;

    std::cout << "Sorting vector:\n";
    jacobsthalInsertionSort(originalVector, recursionLevel);

    std::cout << "\nSorting deque:\n";
    jacobsthalInsertionSort(originalDeque, recursionLevel);

    return 0;
}
