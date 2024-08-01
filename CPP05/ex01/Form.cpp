#include "Form.hpp"

// Default constructor
Form::Form() : name("default form"), is_signed(0), SignGrade(10), ExecGrade(75) {}

// Parametric constructor
Form::Form(std::string const &name, int const &SignGrade, int const &ExecGrade) : name(name), SignGrade(SignGrade), ExecGrade(ExecGrade)
{
    this->is_signed = 0;
    if (this->SignGrade < 1 || this->ExecGrade < 1)
        throw Form::GradeTooHighException();
    else if (this->SignGrade > 150 || this->ExecGrade > 150)
        throw Form::GradeTooLowException();
}
// Copy constructor
Form::Form(const Form &source) : name(source.name), is_signed(source.is_signed), SignGrade(source.SignGrade), ExecGrade(source.ExecGrade) {}

// Assignation operator
Form &Form::operator=(const Form &source)
{
    if (this != &source) {
        is_signed = source.is_signed;
    }
    return *this;
}

//Destructor
Form::~Form() {}