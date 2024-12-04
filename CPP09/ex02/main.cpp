#include "PmergeMe.hpp"

int main(int argc, char *argv[]) {

    if (argc == 1) {
        std::cerr << "Error: No input provided." << std::endl;
        return 1;
    }

    try {
        PmergeMe pm1(argc - 1, argv + 1);
        pm1.Sort();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}

// shuf -i 1-100000 -n 3000 | tr "\n" " "