#include "Bureaucrat.hpp"

// Parametric constructor
Bureaucrat::Bureaucrat(std::string name, int grade) : name(name), grade(grade)
{
    std::cout << "Object created with name: " << name << " and grade: " << grade << std::endl;
    // check the grade, if wrong throw an exception
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat &bureaucrat) : name(bureaucrat.name), grade(bureaucrat.grade)
{
    // check the grade, if wrong throw an exception
}

// Assignation operator
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &bureaucrat)
{
    if (this != &bureaucrat) {
        name = bureaucrat.name; // GETNAME
        grade = bureaucrat.grade; // GETGRADE
        // check the grade, if wrong throw an exception
    }
    return *this;
}

// Destructor
Bureaucrat::~Bureaucrat()
{
    std::cout << "Destruction..." << std::endl;
}

std::string Bureaucrat::getName() const 
{
    return name;
}

int Bureaucrat::getGrade() const
{
    return grade;
}

