#include "RobotomyRequestForm.hpp"

/* ============= CONSTRUCTORS AND DESTRUCTOR ============= */

// Default constructor
RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default_target") {}

// Parametric constructor
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {}

// Copy constructor
RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &source) : AForm(source), target(source.target) {}

// Assignation operator
RobotomyRequestForm const &RobotomyRequestForm::operator=(RobotomyRequestForm const &source)
{
    if (this != &source)
    {
        AForm::operator=(source);
        target = source.target;
    }
    return (*this);
}

// Destructor
RobotomyRequestForm::~RobotomyRequestForm() {}

/* ============= FUNCTIONS ============= */
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
    
    try {
        AForm::execute(executor);
    } catch (AForm::GradeTooLowException &e) {
        throw AForm::GradeTooLowException();
    }
    catch (AForm::FormNotSigned &e) {
        throw AForm::FormNotSigned();
    }
    std::cout << "REPLACE WITH ACTION: RobotomyRequestForm is being executed by " << executor.getName() << std::endl; //Overwrite according to the subject
}

/* Overload of insertion operator */
std::ostream	&operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
    return (str << form.getName() << " form, signed: " << form.getSignStatus() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}