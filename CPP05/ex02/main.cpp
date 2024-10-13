#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main(void)
{
    Bureaucrat Alan("Alan", 50);
    std::cout << Alan << std::endl;
    ShrubberyCreationForm form("home");
    std::cout << form << std::endl;

    Alan.signForm(form);
    std::cout << form << std::endl;
    try {
        form.execute(Alan);
    } catch (std::exception &e){
        std::cout << e.what() << std::endl;
    }

    // Alan.executeForm(form);
    // try{
    //     form.execute(Alan);
    // } catch (std::exception &e) {
    //     std::cout << e.what() << std::endl;
    // }
    // Alan.signForm(form);
    // Alan.executeForm(form);

    // std::cout << "======================" << std::endl << std::endl;
    // Bureaucrat Bob("Bob", 1);
    // PresidentialPardonForm form2("pardon");

    // Bob.executeForm(form2);
    // Bob.signForm(form2);
    // std::cout << form2 << std::endl;
    // Bob.executeForm(form2);

    return 0;
}
