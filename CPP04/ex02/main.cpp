
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"
#include "WrongAnimal.hpp"
#include "Brain.hpp"

int main()
{
    // shouldn't compile as AAnimal is an abstract class
    // AAnimal wrong = AAnimal();

    std::cout << "-------------------" << std::endl;
    std::cout << "Test 1" << std::endl;
    const AAnimal* j = new Dog();
    const AAnimal* i = new Cat();

    delete j;
    delete i;

    std::cout << "-------------------" << std::endl;
    std::cout << "Test 2: loop" << std::endl;
    const int numAnimals = 100;
    const AAnimal* animals_array[numAnimals];

    for (int i = 0; i < 50; i++)
    {
        animals_array[i] = new Dog();
    }
    for (int i = 50; i < numAnimals; i++)
    {
        animals_array[i] = new Cat();
    }
    for (int i = 0; i < 100; i++)
    {
        std::cout << animals_array[i]->getType() << std::endl;
    }

    for (int i = 0; i < numAnimals; i++)
    {
        delete animals_array[i];
    }

    std::cout << "-------------------" << std::endl;
    std::cout << "Test 3: copy constructor and copy assignment operator" << std::endl;

	Dog	dog1;
	Dog	dog2(dog1);
	Dog	dog3;
	dog3 = dog1;

    Cat cat1;
    Cat cat2(cat1);
    Cat cat3;
    cat3 = cat1;

    dog1.makeSound();
    cat1.makeSound();

    std::cout << "Test 4: print ideas addresses" << std::endl;
    dog1.print_address();
    dog2.print_address();
    dog3.print_address();
    cat1.print_address();
    cat2.print_address();
    cat3.print_address();

    return 0;

}