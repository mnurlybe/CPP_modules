#include "conversion.hpp"

void ScalarConverter::convert(std::string &literal)
{
	int	literal_type;

	literal_type = IdentifyType(literal);
	std::cout << "literal_type = " << literal_type << std::endl;
}
int	IdentifyType(std::string const &literal)
{
    if (IsChar(literal))
        return CHAR;
    else if (IsInt(literal))
        return INT;
    else if (IsDouble(literal))
        return DOUBLE;
    else if (IsFloat(literal))
        return FLOAT;
    return ERROR;
}

bool	IsChar(std::string const &str)
{
    return (str.length() == 1 
        && !std::isdigit(static_cast<unsigned char>(str[0])) 
        && std::isprint(static_cast<unsigned char>(str[0])));
}

bool    IsInt(std::string const &str)
{
    size_t i = 0;
    std::string set = "0123456789";

    if ((str[i] == '-' || str[i] == '+') && str.length() != 1)
        i++;

    size_t pos = str.find_first_not_of(set, i);

    return (pos == std::string::npos);
}

bool    IsDouble(std::string const &str)
{   
    size_t i = 0;
    std::string set = "0123456789.";

    if (str == "-inf" || str == "+inf" || str == "nan") 
        return true;

    if ((str[i] == '-' || str[i] == '+')) {
        if (str.length() == 1) 
            return false;
        i++;
    }
    // invalid character is found
    if (str.find_first_not_of(set, i) != std::string::npos) 
        return false;
    // '.' is not found in the string, or the position of decimal point is invalid
    size_t dotPos = str.find('.');
    if (dotPos == std::string::npos || str[i] == '.' || str[str.length() - 1] == '.')
        return false;
    // more than one decimal point found
    if (str.find('.', dotPos + 1) != std::string::npos)
        return false;

    return true;
}

bool    IsFloat(std::string const &str)
{
    size_t i = 0;
    std::string set = "0123456789.f";

    if (str == "-inff" || str == "+inff" || str == "nanf") return true;

    if ((str[i] == '-' || str[i] == '+')) {
        if (str.length() == 1) return false;
        i++;
    }
    // invalid character is found
    if (str.find_first_not_of(set, i) != std::string::npos) 
        return false;
    // '.' is not found in the string, or the position of decimal point is invalid
    size_t dotPos = str.find('.');
    if (dotPos == std::string::npos || str[i] == '.' || str[str.length() - 1] == '.')
        return false;
    // more than one decimal point found
    if (str.find('.', dotPos + 1) != std::string::npos)
        return false;

    // 'f' is not found, or the position of 'f' is wrong
    size_t FPos = str.find('f');
    if (FPos == std::string::npos || FPos != str.length() - 1 || str[i] == 'f' 
        || str[str.length() - 1] != 'f' || (str[str.length() - 1] == 'f' && str[str.length() - 2] == '.'))
        return false;
    return true;
}
