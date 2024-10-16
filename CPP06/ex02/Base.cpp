#include "Base.hpp"

Base::~Base() {}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Type of the object pointed by p is not identified." << std::endl;
}

void identify(Base& p)
{

    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "type A identified" << std::endl;
        (void)a;
        return;
    } catch (const std::exception &e) {}

    try {
        B& b = dynamic_cast<B&>(p);
        std::cout << "type B identified" << std::endl;
        (void)b;
        return;
    } catch (const std::exception &e) {}

    try {
        C& c = dynamic_cast<C&>(p);
        std::cout << "type C identified" << std::endl;
        (void)c;
        return;
    } catch (const std::exception &e) {
        std::cout << "Type of the object referenced by p is not identified." << std::endl;    
    }

}

Base	*generate(void)
{
	int	random;

	std::srand(std::time(0));
	random = std::rand() % 3;
	std::cout << "Random: " << random << std::endl;

	switch (random)
	{
	case 0:
        std::cout << "class A is created" << std::endl;
		return (new A);
	case 1:
        std::cout << "class B is created" << std::endl;
		return (new B);
	case 2:
        std::cout << "class C is created" << std::endl;
		return (new C);
	default:
		return (NULL);
	}
}
/*dynamic_cast in C++ is a type of casting operator 
that is used to perform safe downcasting and 
cross-casting among polymorphic types 
(types with at least one virtual function). 
It's particularly useful in the context of polymorphism, 
where you need to determine the actual type of an object 
pointed to or referenced by a base class pointer or reference.*/

/* dynamic_cast Purpose: 
Used primarily for casting within an inheritance hierarchy involving polymorphism. 
It performs runtime checks, making it useful for safe downcasting (from a base class pointer to a derived class pointer). 
Only works with polymorphic types, meaning there must be at least one virtual function in the base class. */