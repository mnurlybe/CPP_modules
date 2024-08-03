#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


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
    if (dynamic_cast<A&>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(&p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(&p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Type of the object referenced by p is not identified." << std::endl;    
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
		return (new A());
	case 1:
		return (new B());
	case 2:
		return (new C());
	default:
		return (NULL);
	}
}
int	main(void)
{
	Base *obj = generate();

    identify(obj);
    identify(*obj);

    delete obj;

	return (0);
}

/*dynamic_cast in C++ is a type of casting operator 
that is used to perform safe downcasting and 
cross-casting among polymorphic types 
(types with at least one virtual function). 
It's particularly useful in the context of polymorphism, 
where you need to determine the actual type of an object 
pointed to or referenced by a base class pointer or reference.*/