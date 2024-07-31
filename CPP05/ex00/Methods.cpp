#include "Bureaucrat.hpp"

/* Exceptions */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Grade is too high.");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Grade is too low.");
}

/* Member Functions */
void Bureaucrat::GradeUp(void)
{
    this->grade--;
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
}
void Bureaucrat::GradeDown(void)
{
    this->grade++;
    if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();
}
