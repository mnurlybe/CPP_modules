#include "PresidentialPardonForm.hpp"

/* ============= CONSTRUCTORS AND DESTRUCTOR ============= */

// Default constructor
PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), target("default_target") {}

// Parametric constructor
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), target(target) {}

// Copy constructor
PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &source) : AForm(source), target(source.target) {}

// Assignation operator
PresidentialPardonForm const &PresidentialPardonForm::operator=(PresidentialPardonForm const &source)
{
    if (this != &source)
    {
        AForm::operator=(source);
        target = source.target;
    }
    return (*this);
}

// Destructor
PresidentialPardonForm::~PresidentialPardonForm() {}

/* ============= FUNCTIONS ============= */
void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
    
    try {
        AForm::execute(executor);
    } catch (AForm::GradeTooLowException &e) {
        throw AForm::GradeTooLowException();
    }
    catch (AForm::FormNotSigned &e) {
        throw AForm::FormNotSigned();
    }
    std::cout << "REPLACE WITH ACTION: PresidentialPardonForm is being executed by " << executor.getName() << std::endl; //Overwrite according to the subject
}

/* Overload of insertion operator */
std::ostream	&operator<<(std::ostream &str, PresidentialPardonForm const &form)
{
    return (str << form.getName() << " form, signed: " << form.getSignStatus() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}