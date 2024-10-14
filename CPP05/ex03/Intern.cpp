#include "Intern.hpp"

/* ============= CONSTRUCTORS AND DESTRUCTOR ============= */
Intern::Intern() {
    std::cout << "Intern has been created." << std::endl;
}

Intern::Intern(Intern const &source) { 
    (void)source;
    std::cout << "Intern has been cpoied." << std::endl;
}

Intern const &Intern::operator=(Intern const &source) { 
    if (this != &source) {
        std::cout << "Intern has been assigned." << std::endl;
    }
    return *this;
}

Intern::~Intern() {
    std::cout << "Intern has been destroyed." << std::endl;
}

/* ============= EXCEPTIONS ============= */
const char *Intern::FormNotFoundException::what() const throw() {
    return ("Form not found.");
}

/* ============= FUNCTIONS ============= */
// use switch case to create the form
AForm *Intern::makeForm(std::string form, std::string target)
{
    AForm *forms[3] = {new PresidentialPardonForm(target), new RobotomyRequestForm(target), new ShrubberyCreationForm(target)};
    std::string form_names[3] = {"PresidentialPardon", "RobotomyRequest", "ShrubberyCreation"};
    AForm *form_ptr = NULL;
    bool form_found = false;
    for (int i = 0; i < 3; i++)
    {
        if (form == form_names[i])
        {
            form_ptr = forms[i];
            form_found = true;
            break;
        }
    }
    // check if the form has been found
    if (!form_found) {
        for (int i = 0; i < 3; i++)
            delete forms[i];
        throw Intern::FormNotFoundException();
    }
    // return the form pointer
    std::cout << "Intern creates " << form_ptr->getName() << std::endl;
    // delete the other forms
    for (int i = 0; i < 3; i++)
    {
        if (form_ptr != forms[i])
            delete forms[i];
    }
    return form_ptr;
}