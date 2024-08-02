#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <iostream>
# include <string>
# include <cctype>
# include <limits> // For std::numeric_limits
# include <cstdlib>  // For std::atol - conversion from string to long

# define ERROR 0
# define CHAR 1
# define INT 2
# define FLOAT 3
# define DOUBLE 4
# define PSEUDO 5

class ScalarConverter
{
  private:
	ScalarConverter();
	ScalarConverter(const ScalarConverter &source);
	ScalarConverter &operator=(const ScalarConverter &source);
	~ScalarConverter();

  public:
	static void convert(std::string &literal);
};

int		IdentifyType(std::string const &literal);
bool	IsChar(std::string const &str);
bool    IsInt(std::string const &str);
bool    IsDouble(std::string const &str);
bool    IsFloat(std::string const &str);

#endif


// Conversion from string to long:
    //     long test = std::atol(str.c_str());
    //     std::cout << "Number: " << test << std::endl;


// std::cout << "int:\n";
// std::cout << "  Max: " << std::numeric_limits<int>::max() << "\n";
// std::cout << "  Min: " << std::numeric_limits<int>::min() << "\n";
// std::cout << "  Is signed: " << std::numeric_limits<int>::is_signed << "\n";

// should it be handled?????
    // if (literal.empty())
    //     return ERROR;