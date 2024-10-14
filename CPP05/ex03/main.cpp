#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"

// std::string form_names[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};

int main(void)
{
	Intern noob;
	AForm* test;
    Bureaucrat b1("Bureaucrat 1", 1);

	try
	{
		test = noob.makeForm("RobotomyRequest", "Bender");
		std::cout << *test << std::endl;
		delete test;
		test = noob.makeForm("PresidentialPardon", "Arthur Dent");
        b1.signForm(*test);
        std::cout << *test << std::endl;
		delete test;
		test = noob.makeForm("ShrubberyCreation", "garden");
		delete test;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	// Test for exception
	try
	{
		test = noob.makeForm("resignation letter", "employee");
		std::cout << *test << std::endl;
		delete test;
	}
	catch (std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}
