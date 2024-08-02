#include "conversion.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string literal = argv[1];
        ScalarConverter::convert(literal);
    }
    else
        std::cout << "Wrong arguments!" << std::endl;
    return 0;
}