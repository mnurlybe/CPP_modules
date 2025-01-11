#include "RPN.hpp"

int main(int argc, char **argv) 
{
    if (argc != 2) 
    {
        std::cerr << "Usage: ./rpn \"expression\"" << std::endl;
        return 1;
    }

    RPN rpn;
    rpn.calculate(argv[1]);

    return 0;
}

/* $> ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$> ./RPN "7 7 * 7 -"
42
$> ./RPN "1 2 * 2 / 2 * 2 4 - +"
0
$> ./RPN "(1 + 1)"
Error */