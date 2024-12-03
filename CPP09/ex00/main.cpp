#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./bitcoin [filename]" << std::endl;
        return 1;
    }

    try {
        BitcoinExchange exchange;
        exchange.loadFile(argv[1]);
        // exchange.display();
    } catch(std::exception &e) {
        std::cerr << e.what() << std::endl; 
    }

    return 0;
}