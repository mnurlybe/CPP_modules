#include "conversion.hpp"

void PrintChar(std::string str, char c, int i)
{
    if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan" || str == "-inff" || str == "+inff" || str == "inff" ||str == "nanf")
        std::cout << "char: impossible" << std::endl;
    else if (i < 0 || i > CHAR_MAX)
        std::cout << "char: impossible" << std::endl;
    else if (!std::isprint(static_cast<unsigned char>(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: \'" << c << "\'" << std::endl;
}
void PrintInt(std::string str, long i)
{
    if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan" || str == "-inff" || str == "+inff" || str == "inff" ||str == "nanf")
        std::cout << "int: impossible" << std::endl;
    else if (i < INT_MIN || i > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;
}

void PrintFloat(std::string str, float f)
{
    if (str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
        std::cout << "float: " << str << std::endl;
    else if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
        std::cout << "float: " << str << "f" << std::endl;
    else if (f < -FLT_MAX || f > FLT_MAX)
        std::cout << "float: impossible" << std::endl;
    else
        std::cout << "float: " << std::fixed << std::setprecision(1) << f << "f" << std::endl;
}

void PrintDouble(std::string str, double d)
{
    if (str == "-inf" || str == "+inf" || str == "inf" || str == "nan")
        std::cout << "double: " << str << std::endl;
    else if (str == "-inff" || str == "+inff" || str == "nanf" || str == "inff")
        std::cout << "double: " << str.substr(0, str.size() - 1) << std::endl;
    else if (d < -DBL_MAX || d > DBL_MAX)
        std::cout << "double: impossible" << std::endl;
    else
        std::cout << "double: " << std::fixed << std::setprecision(1) << d << std::endl;
}
