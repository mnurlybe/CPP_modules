#include "Bureaucrat.hpp"

// Default constructor
Bureaucrat::Bureaucrat() : name("default"), grade(150) {}

// Parametric constructor
Bureaucrat::Bureaucrat(std::string const &name, int grade) : name(name), grade(grade)
{
    if (this->grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (this->grade > 150)
        throw Bureaucrat::GradeTooHighException();        
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &source) : name(source.name), grade(source.grade) {}

// Assignation operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &source)
{
    if (this != &source) {
        name = source.name;
        grade = source.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << this->getName() << " destroyed..." << std::endl;
}
/* Getters */
std::string Bureaucrat::getName() const 
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

/* Overload of insertion operator*/

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}


