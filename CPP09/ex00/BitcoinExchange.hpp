#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <map>
# include <string>

class BitcoinExchange
{
    private:
        // std::map<std::string, double> _exchange;
        std::map<std::string, std::string> _exchange;
        std::string _filename;
        mutable std::string _error;
        void processCSV(void);
        void printContainer();

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &source);
        BitcoinExchange &operator=(const BitcoinExchange &source);
        ~BitcoinExchange();

        void loadFile(std::string filename);
        void display();

    class DataBaseException : public std::exception {
        public:
            const char *what() const throw();
    };

    class FileErrorException : public std::exception {
        public:
            const char *what() const throw();
    };
};

#endif