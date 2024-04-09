#include "Zombie.hpp"

int main()
{   
    std::string stack_name;
    std::string heap_name;

    std::cout << "Enter a name for a zombie on a stack: ";
    std::cin >> stack_name;
    std::cout << "Enter a name for a zombie on a heap: ";
    std::cin >> heap_name;

    //alocate on the stack - no need to delete - RANDOMCHUMP
    // std::cout << "Zombie on a stack." << std::endl;
    randomChump(stack_name);

    // allocate on the heap - need to delete - NEWZOMBIE
    // std::cout << "Zombie on a heap." << std::endl;
    Zombie* z1 = newZombie(heap_name);
    z1->announce();
    delete z1;

    // Zombie New;
    // New.announce();

    return 0;
}