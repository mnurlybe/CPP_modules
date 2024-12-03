#include "BitcoinExchange.hpp"

/* Helper Functions */
void BitcoinExchange::printContainer() {
    
    // print only the first 10 elements
    std::map<std::string, double>::iterator it = _exchange.begin();
    for (int i = 0; i < 10; i++) {
        std::cout << it->first << " : " << it->second << std::endl;
        it++;
    }

    // print all elements
/*     for (std::map<std::string, double>::iterator it = _exchange.begin(); it != _exchange.end(); it++) {
        std::cout << it->first << " : " << it->second << std::endl;
    } */
}

bool BitcoinExchange::validateDate(std::string date, bool isAgrvFile) {

    if (date.empty() || date.length() != 10 || date[4] != '-' || date[7] != '-') {
        if (!isAgrvFile)
            throw std::invalid_argument("Invalid Date Format.");
        std::cerr << "Error: bad input => " << date << std::endl;
        return 1;
    }

    std::string year = date.substr(0, 4);
    std::string month = date.substr(5, 2);
    std::string day = date.substr(8, 2);
    if (year.length() != 4 || month.length() != 2 || day.length() != 2) {
        if (!isAgrvFile)
            throw std::invalid_argument("Invalid Date Format.");
        std::cerr << "Error: bad input => " << date << std::endl;
        return 1;
    }

    int monthInt = std::atoi(month.c_str());
    int dayInt = std::atoi(day.c_str());
    int yearInt = std::atoi(year.c_str());

    if ((yearInt < 2009 || yearInt > 2022) 
        || (monthInt < 1 || monthInt > 12) 
        || (dayInt < 1 || dayInt > 31)) {
        if (!isAgrvFile)
            throw std::invalid_argument("Invalid Date Format.");
        std::cerr << "Error: bad input => " << date << std::endl;
        return 1;
    }

    if ((monthInt == 4 || monthInt == 6 || monthInt == 9 || monthInt == 11) && dayInt > 30) {
        if (!isAgrvFile)
            throw std::invalid_argument("Invalid Date Format.");
        std::cerr << "Error: bad input => " << date << std::endl;
        return 1;
    }
    if ((monthInt == 2 && dayInt > 29)) {
        if (!isAgrvFile)
            throw std::invalid_argument("Invalid Date Format.");
        std::cerr << "Error: bad input => " << date << std::endl;
        return 1;
    }
    if ((monthInt == 1 || monthInt == 3 || monthInt == 5 || monthInt == 7 || monthInt == 8 || monthInt == 10 || monthInt == 12) 
        && dayInt > 31) {
        if (!isAgrvFile)
            throw std::invalid_argument("Invalid Date Format.");
        std::cerr << "Error: bad input => " << date << std::endl;
        return 1;
    }
    return 0;
}

bool BitcoinExchange::validateValue(std::string value, bool isAgrvFile) {

    char *end;
    double ex_rate = strtod(value.c_str(), &end);

    if (value.empty()) {
        if (!isAgrvFile)
            throw std::invalid_argument("Empty Exchange Rate.");
        std::cerr << "Error: Empty Value." << std::endl;
        return 1;
    }
    if (*end != '\0'){
        if (!isAgrvFile)
            throw std::invalid_argument("Invalid Exchange Rate Format.");
        std::cerr << "Error: bad input => " << value << std::endl;
        return 1;
    }
    if (ex_rate < 0) {
        if (!isAgrvFile)
            throw std::invalid_argument("Rate cannot be negative.");
        std::cerr << "Error: not a positive number." << std::endl;
        return 1;
    }

    if (ex_rate > 10000 && isAgrvFile) {
        std::cerr << "Error: too large a number (max 10000)." << std::endl;
        return 1;
    }
    return 0;
}
