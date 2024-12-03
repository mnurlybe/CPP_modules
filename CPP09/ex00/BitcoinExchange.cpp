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

    std::string line;
    std::getline(file, line);
    if (line != "date | value") {
        throw FileFormatException();
    }

    while (std::getline(file, line)) {
        std::string date = line.substr(0, line.find(' '));
        std::string value = line.substr(line.find('|') + 2);

        int DateIsWrong = validateDate(date, true);
        if (DateIsWrong) 
            continue;
        int ValueIsWrong = validateValue(value, true);
        if (ValueIsWrong) 
            continue;
        
        std::map<std::string, double>::iterator it;
        it = _exchange.lower_bound(date);
        double rate = it->second;
        if (it != _exchange.begin()) {
				if (it->first != date)
					--it;
				rate = it->second;
			}
		std::cout << date << " => " << value << " = " << rate * std::strtod(value.c_str(), NULL) << std::endl;
    }
}

void BitcoinExchange::processCSV(void) {
    std::ifstream database("data.csv");
    if (!database.is_open()) {
        throw DataBaseException();
    }

    std::string line;
    std::getline(database, line);

    if (line != "date,exchange_rate") {
        throw DataBaseFormatException();
    }

    while (std::getline(database, line)) {
        std::string date = line.substr(0, line.find(','));
        std::string value = line.substr(line.find(',') + 1);
        try {
            validateDate(date, false);
            validateValue(value, false);
        } catch(std::exception &e) {
            std::cerr << "Database: " << e.what() << std::endl;
            exit(1);
        }
        double ex_rate = strtod(value.c_str(), NULL);
        _exchange.insert(std::pair<std::string, double>(date, ex_rate));
    }
    database.close();
    // printContainer();
}

