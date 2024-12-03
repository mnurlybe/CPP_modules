#include "BitcoinExchange.hpp"

/* Exceptions */
const char *BitcoinExchange::DataBaseException::what() const throw() {
    return "Error: Could not open DataBase file.";
}

const char *BitcoinExchange::DataBaseFormatException::what() const throw() {
    return "Error: DataBase file is not valid.";
}

const char *BitcoinExchange::FileErrorException::what() const throw() {
    return "Error: Could not open file.";
}

const char *BitcoinExchange::FileFormatException::what() const throw() {
    return "Error: Invalid File Format.";
}