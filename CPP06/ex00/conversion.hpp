#ifndef CONVERSION_HPP
# define CONVERSION_HPP

# include <cctype>
# include <climits>
# include <cstdlib>
# include <iostream>
# include <limits>
# include <string>
# include <cfloat>
# include <iomanip>
# include <exception>

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

  class DataTypeNotIdentified : public std::exception
  {
    public:
      const char *what() const throw();
  };
};

// detect the type of the literal passed as parameter
int		IdentifyType(std::string const &literal);
bool	IsChar(std::string const &str);
bool	IsInt(std::string const &str);
bool	IsDouble(std::string const &str);
bool	IsFloat(std::string const &str);

// convert it from string to its actual type, then convert it explicitly to the three other data types
void	CharConv(std::string &str);
void	IntConv(std::string &str);
void	FloatConv(std::string &str);
void	DoubleConv(std::string &str);

// print
void	PrintChar(std::string str, char c, int i);
void	PrintInt(std::string str, long i);
void PrintFloat(std::string str, float f);
void PrintDouble(std::string str, double d);

#endif
