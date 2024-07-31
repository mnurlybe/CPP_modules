#include "Form.hpp"
#include "Bureaucrat.hpp"

/* Getters */
std::string const &Form::getName() const 
{
    return name;
}

bool const &Form::getSignStatus() const
{
    return is_signed;
}

int const &Form::getSignGrade() const
{
    return SignGrade;
}

int const &Form::getExecGrade() const
{
    return ExecGrade;
}

/* Exceptions */
const char *Form::GradeTooHighException::what() const throw()
{
    return("Form: Grade is too high.");
}
const char *Form::GradeTooLowException::what() const throw()
{
    return("Form: Grade is too low.");
}
/* Member Functions */
void    Form::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->SignGrade)
        throw Form::GradeTooLowException();
    else
        this->is_signed = 1;
}
/* Overload of insertion operator */
std::ostream	&operator<<(std::ostream &str, Form const &form)
{
    return (str << form.getName() << " form, signed: " << form.getSignStatus() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}
