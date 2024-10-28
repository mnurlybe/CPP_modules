#include "iter.hpp"

template <typename T>
void printArray(T const &element) {
    std::cout << element << " ";
}

template <typename T>
void IncrementArray(T &element) {
    element++;
}

int main(void)
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    size_t length = sizeof(arr) / sizeof(arr[0]);

    iter(arr, length, printArray);
    std::cout << std::endl;
    iter(arr, length, IncrementArray);
    std::cout << "Incremented int Array:" << std::endl;
    iter(arr, length, printArray);
    std::cout << std::endl;

    std::string str_arr[3] = {"Hello", "Function", "Templates"};
    iter(str_arr, 3, printArray);

    return 0;
}