#include "conversion.hpp"

void ScalarConverter::convert(std::string &literal)
{
	int	literal_type = IdentifyType(literal);

    switch (literal_type)
    {
        case CHAR:
            CharConv(literal);
            break;
        case INT:
            IntConv(literal);
            break;
        case FLOAT:
            FloatConv(literal);
            break;  
        case DOUBLE:
            DoubleConv(literal);
            break;                          
        default:
            throw ScalarConverter::DataTypeNotIdentified();
            break;
    }
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
void CharConv(std::string &str)
{
    char c = static_cast<unsigned char>(str[0]);
    PrintChar(str, c, static_cast<int>(str[0]));
    PrintInt(str, static_cast<long>(str[0]));
    PrintFloat(str, static_cast<float>(c));
    PrintDouble(str, static_cast<double>(c));
}

void IntConv(std::string &str)
{
    long n = std::atol(str.c_str());
    PrintChar(str, static_cast<unsigned char>(n), static_cast<int>(n));
    PrintInt(str, n);
    PrintFloat(str, static_cast<float>(n));
    PrintDouble(str, static_cast<double>(n));
}

void FloatConv(std::string &str)
{
    float f = std::atof(str.c_str());
    PrintChar(str, static_cast<unsigned char>(f), static_cast<int>(f));
    PrintInt(str, static_cast<int>(f));
    PrintFloat(str, f);
    PrintDouble(str, static_cast<double>(f));
}

void DoubleConv(std::string &str)
{
    double d = std::atof(str.c_str());
    PrintChar(str, static_cast<unsigned char>(d), static_cast<int>(d));
    PrintInt(str, static_cast<int>(d));
    PrintFloat(str, d);
    PrintDouble(str, d);
}

