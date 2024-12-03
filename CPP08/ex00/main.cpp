#include "easyfind.hpp"

int main() {

    std::vector<int> vec;

    for (int i = 0; i < 10; i++)
        vec.push_back(i);

    try {
        easyfind(vec, 5);
    } catch (std::exception &e) {
        std::cerr << e.what();
    }

    // test with the same element
    vec.push_back(5);
    try {
        easyfind(vec, 5);
    } catch (std::exception &e) {
        std::cerr << e.what();
    }    


    try {
        easyfind(vec, 10);
    } catch (std::exception &e) {
        std::cerr << e.what();
    }
    
    for (int i = 10; i < 100; i++)
        vec.push_back(i);

    try {
        easyfind(vec, 27);
    } catch (std::exception &e) {
        std::cerr << e.what();
    }

    std::vector<char> vec2;
    for (int i = 0; i < 10; i++)
        vec2.push_back(i + 65);

    try {
        easyfind(vec2, 'A');
    } catch (std::exception &e) {
        std::cerr << e.what();
    }

    return 0;
}