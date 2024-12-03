#include "BitcoinExchange.hpp"

/* Orthodox Canonical Form */
BitcoinExchange::BitcoinExchange() {
    try {
        processCSV();
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}
BitcoinExchange::BitcoinExchange(const BitcoinExchange &source) {
    *this = source;
}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &source) {
    if (this == &source)
        return *this;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

/* Member Functions */
void BitcoinExchange::loadFile(std::string filename)
{
    _filename = filename;
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw FileErrorException();
    }
}

void BitcoinExchange::processCSV(void) {
    std::ifstream database("data.csv");
    if (!database.is_open()) {
        throw DataBaseException();
    }

    std::string line;
    while (std::getline(database, line)) {
        std::string key = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);
        _exchange[key] = value;
    }
    printContainer();
}

/* Exceptions */
const char *BitcoinExchange::DataBaseException::what() const throw() {
    return "Error: could not open DataBase file.";
}

const char *BitcoinExchange::FileErrorException::what() const throw() {
    return "Error: could not open file.";
}

/* Helper Functions */
void BitcoinExchange::printContainer() {
    
    // print only the first 10 elements
    std::map<std::string, std::string>::iterator it = _exchange.begin();
    for (int i = 0; i < 10; i++) {
        std::cout << it->first << " : " << it->second << std::endl;
        it++;
    }

    // print all elements
    /* for (std::map<std::string, std::string>::iterator it = _exchange.begin(); it != _exchange.end(); it++) {
        std::cout << it->first << " : " << it->second << std::endl;
    } */
}