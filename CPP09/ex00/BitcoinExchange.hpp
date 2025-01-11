#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>
# include <cstdlib>
# include <exception>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _exchange;
        std::string _filename;
        mutable std::string _error;
        void processCSV(void);
        void printContainer();
        bool validateDate(std::string date, bool isArgvFile);
        bool validateValue(std::string value, bool isArgvFile);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &source);
        BitcoinExchange &operator=(const BitcoinExchange &source);
        ~BitcoinExchange();

        void loadFile(std::string filename);

    class DataBaseException : public std::exception {
        public:
            const char *what() const throw();
    };

    class DataBaseFormatException : public std::exception {
        public:
            const char *what() const throw();
    };

    class FileErrorException : public std::exception {
        public:
            const char *what() const throw();
    };

    class FileFormatException : public std::exception {
        public:
            const char *what() const throw();
    };
};

#endif