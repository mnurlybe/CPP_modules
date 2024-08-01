#include "Bureaucrat.hpp"
#include "Form.hpp"

/* Getters */
std::string Bureaucrat::getName() const 
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

/* Exceptions */
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return("Bureaucrat: Grade is too high.");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return("Bureaucrat: Grade is too low.");
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

void Bureaucrat::signForm(Form &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

/* Overload of insertion operator */

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}

