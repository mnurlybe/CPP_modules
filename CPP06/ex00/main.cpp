#include "conversion.hpp"

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        std::string literal = argv[1];
        try {
            ScalarConverter::convert(literal);
        } catch (ScalarConverter::DataTypeNotIdentified &e){
            std::cout << e.what() << std::endl;
        }
    }
    else
        std::cout << "Wrong arguments!" << std::endl;
    return 0;
}

// ScalarConverter::convert("42");
// ScalarConverter::convert("42.0f");
// ScalarConverter::convert("42.0");
// ScalarConverter::convert("+inf");
// ScalarConverter::convert("-inff");
// ScalarConverter::convert("nan");
// ScalarConverter::convert("invalid");