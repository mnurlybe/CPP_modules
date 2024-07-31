#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>


class Bureaucrat
{
    private:
        std::string name;
        int grade;
    public:
        // Bureaucrat(); // Default constructor
        Bureaucrat(std::string name, int grade); // Parametric constructor
        Bureaucrat(const Bureaucrat &bureaucrat); // Copy constructor
        Bureaucrat &operator=(const Bureaucrat &bureaucrat); // Assignation operator
        ~Bureaucrat(); // Destructor

        // Getters
        std::string getName() const;
        int getGrade() const;

        // Nested Exception Classes
        class GradeTooHighException : public std::exception;
        class GradeTooLowException : public std::exception;

};

#endif