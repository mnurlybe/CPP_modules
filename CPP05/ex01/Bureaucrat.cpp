#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

// Parametric constructor
Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name), grade(grade)
{
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooLowException();        
}
// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &source) : name(source.name), grade(source.grade) {}

// Assignation operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
    if (this != &source) {
        grade = source.getGrade();
    }
    std::cout << "Assignment operator" << std::endl;
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}



