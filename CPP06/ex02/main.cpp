#include "Base.hpp"

int	main(void)
{
	Base *obj = generate();
    identify(obj); // void identify(Base* p);
    identify(*obj); // void identify(Base& p);
    delete obj;

    /* test exception */
    // Base *test_exception = new D;
    // identify(test_exception);
    // identify(*test_exception);
    // delete test_exception;

	return (0);
}