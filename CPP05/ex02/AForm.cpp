#include "AForm.hpp"
#include "Bureaucrat.hpp"

/* ============= CONSTRUCTORS AND DESTRUCTOR ============= */

// Default constructor
AForm::AForm() : name("default form"), is_signed(0), SignGrade(10), ExecGrade(75) {}

// Parametric constructor
AForm::AForm(std::string const &name, int const &SignGrade, int const &ExecGrade) : name(name), SignGrade(SignGrade), ExecGrade(ExecGrade)
{
    this->is_signed = 0;
    if (this->SignGrade < 1 || this->ExecGrade < 1)
        throw AForm::GradeTooHighException();
    else if (this->SignGrade > 150 || this->ExecGrade > 150)
        throw AForm::GradeTooLowException();
}
// Copy constructor
AForm::AForm(const AForm &source) : name(source.name), is_signed(source.is_signed), SignGrade(source.SignGrade), ExecGrade(source.ExecGrade) {}

// Assignation operator
AForm &AForm::operator=(const AForm &source)
{
    if (this != &source) {
        is_signed = source.is_signed;
    }
    return *this;
}

//Destructor
AForm::~AForm() {}

/* ============= FUNCTIONS ============= */

/* Getters */
std::string const &AForm::getName() const 
{
    return name;
}

bool const &AForm::getSignStatus() const
{
    return is_signed;
}

int const &AForm::getSignGrade() const
{
    return SignGrade;
}

int const &AForm::getExecGrade() const
{
    return ExecGrade;
}

/* Exceptions */
const char *AForm::GradeTooHighException::what() const throw()
{
    return("Form: Grade is too high.");
}
const char *AForm::GradeTooLowException::what() const throw()
{
    return("Form: Grade is too low.");
}
const char *AForm::FormNotSigned::what() const throw()
{
    return("Form is not signed.");
}
/* Member Functions */
void    AForm::beSigned(Bureaucrat &b)
{
    if (b.getGrade() > this->SignGrade)
        throw AForm::GradeTooLowException();
    else
        this->is_signed = 1;
}
/* Overload of insertion operator */
std::ostream	&operator<<(std::ostream &str, AForm const &form)
{
    return (str << form.getName() << " form, signed: " << form.getSignStatus() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}

/* Virtual Function Implementation in the Base Class */

void    AForm::execute(Bureaucrat const &executor) const
{
    if (executor.getGrade() > this->ExecGrade)
        throw AForm::GradeTooLowException();
    else if (!this->is_signed)
        throw AForm::FormNotSigned();
}