#include "MutantStack.hpp"

template <typename Iter>
void printContainer(Iter start, Iter end) {
    while (start != end) {
        std::cout << *start << " ";
        start++;
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "------- subject tests -------" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);

    std::cout << "Top element: " << mstack.top() << std::endl;


    mstack.pop();
    std::cout << "Stack size: " << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();

    ++it;
    --it;
    std::cout << "Printing mstack1: ";
    while (it != ite)
    {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    std::stack<int> s(mstack);

    std::cout << "------- my tests -------" << std::endl;
    MutantStack<int> mstack2(mstack);
    std::cout << "Printing mstack2: ";
    printContainer(mstack2.begin(), mstack2.end());


    MutantStack<char> mstack3;
    mstack3.push('a');
    mstack3.push('b');
    mstack3.push('c');
    mstack3.push('d');
    mstack3.push('e');
    std::cout << "Printing mstack3: ";
    printContainer(mstack3.begin(), mstack3.end());

    // std::list
    /* std::list<int> mstack;
    mstack.push_back(5);
    mstack.push_back(17);

    std::cout << mstack.back() << std::endl;

    mstack.pop_back();
    std::cout << mstack.size() << std::endl;

    mstack.push_back(3);
    mstack.push_back(5);
    mstack.push_back(737);
    //[...]
    mstack.push_back(0);

    std::list<int>::iterator it = mstack.begin();
    std::list<int>::iterator ite = mstack.end();

    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::list<int> s(mstack); */
    
    return 0;
}