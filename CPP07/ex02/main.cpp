#include <iostream>
#include "Array.hpp"

int main() {
    try {
        // Test default constructor
        Array<int> defaultArray;
        std::cout << "Default array size: " << defaultArray.size() << std::endl;

        // Test parametric constructor
        Array<int> intArray(5);
        std::cout << "Parametric array size: " << intArray.size() << std::endl;

        // Test element assignment and access
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }
        std::cout << "Elements in intArray: ";
        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << intArray[i] << " ";
        }
        std::cout << std::endl;

        // Test copy constructor
        Array<int> copiedArray(intArray);
        std::cout << "Copied array elements: ";
        for (unsigned int i = 0; i < copiedArray.size(); i++) {
            std::cout << copiedArray[i] << " ";
        }
        std::cout << std::endl;

        // Test assignment operator
        Array<int> assignedArray;
        assignedArray = intArray;
        std::cout << "Assigned array elements: ";
        for (unsigned int i = 0; i < assignedArray.size(); i++) {
            std::cout << assignedArray[i] << " ";
        }
        std::cout << std::endl;

        // Test out-of-bounds access
        std::cout << "Attempting out-of-bounds access: " << std::endl;
        std::cout << intArray[10] << std::endl; // This should throw an exception

    } catch (const Array<int>::IndexOutOfBounds &e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }

    return 0;
}
