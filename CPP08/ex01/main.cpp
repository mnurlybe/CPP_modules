#include "Span.hpp"

int main()
{
    std::cout << "-------------Subject tests-------------" << std::endl;
    Span sp = Span(10);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);


    std::cout << sp.shortestSpan() << std::endl;
    std::cout << sp.longestSpan() << std::endl;

    std::cout << "-------------My tests-------------" << std::endl;

    sp.printNumbers();

    std::vector<int> v;
    v.push_back(1);
    v.push_back(5);
    v.push_back(3);

    sp.addRange(v.begin(), v.end());

    sp.printNumbers();


    std::srand(static_cast<unsigned>(std::time(NULL)));

    Span sp2 = Span(10000);
    for (int i = 0; i < 10000; i++)
    {
        sp2.addNumber(std::rand() % 100);
    }
    // sp2.printNumbers();
    std::cout << "Shortest Span: " << sp2.shortestSpan() << std::endl;
    std::cout << "Longest Span: " << sp2.longestSpan() << std::endl;    
    return 0;
}

// write more tests before submission