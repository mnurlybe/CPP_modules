
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"

int main()
{

    std::cout << "-------------------" << std::endl;
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound(); //will output the cat sound!
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;
    // std::cout << std::endl;
    // std::cout << "---------WRONG ANIMAL test----------" << std::endl;
    // std::cout << std::endl;
    // const WrongAnimal* wanimal = new WrongAnimal();
    // const WrongAnimal* wcat = new WrongCat();

    // std::cout << wcat->getType() << " " << std::endl;
    // wcat->makeSound();

    // delete wanimal;
    // delete wcat;
    // std::cout << std::endl;
    // std::cout << "---------Test Copy constructor, and Assignment operator----------" << std::endl;
    // std::cout << std::endl;
    // Dog doggy;
    // Dog Kira(doggy);
    // std::cout << doggy.getType() << " " << std::endl;
    // doggy.makeSound();
    // std::cout << Kira.getType() << " " << std::endl;

    return 0;

}