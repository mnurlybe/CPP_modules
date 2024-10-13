#include "Bureaucrat.hpp"
#include "AForm.hpp"

/* ============= CONSTRUCTORS AND DESTRUCTOR ============= */

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
        name = source.name;
        grade = source.grade;
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat() {}

/* ============= FUNCTIONS ============= */

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

void Bureaucrat::signForm(AForm &form)
{
    try {
        form.beSigned(*this);
        std::cout << this->name << " signed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}

void Bureaucrat::executeForm(AForm const &form)
{
    try {
        form.execute(*this);
        std::cout << this->name << " executed " << form.getName() << std::endl;
    } catch (std::exception &e) {
        std::cout << this->name << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

/* Overload of insertion operator */

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat)
{
	return (str << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade());
}


