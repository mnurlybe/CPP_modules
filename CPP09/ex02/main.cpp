#include "PmergeMe.hpp"
#include <iostream>
#include <vector>



// Main function
int main(int argc, char *argv[]) {

    PmergeMe vec1(argc - 1, argv + 1);
    std::cout << "Original array: ";
    vec1.printArray(vec1.getVector());

    // Perform merge-insert sort
    vec1.mergeInsertSort(0, vec1.getVector().size() - 1);

    std::cout << "Sorted array: ";
    vec1.printArray(vec1.getVector());

    return 0;
}
