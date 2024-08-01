#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include <fstream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
    private:
        std::string const   name;
        bool                is_signed;
        int const           SignGrade;
        int const           ExecGrade;
    public:
        AForm(); // Default constructor
        AForm(std::string const &name, int const &SignGrade, int const &ExecGrade); // Parametric constructor
        AForm(const AForm &source); // Copy constructor
        AForm &operator=(const AForm &source); // Assignation operator
        ~AForm(); // Destructor

    // Getters
    std::string const &getName() const;
    bool const  &getSignStatus() const;
    int const   &getSignGrade() const;
    int const   &getExecGrade() const;

    // Member Functions
    void    beSigned(Bureaucrat &b);
    virtual void    execute(Bureaucrat const &executor) const = 0;

    // Nested Exception Classes
    class GradeTooHighException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class GradeTooLowException : public std::exception
    {
        public:
            const char *what() const throw();
    };
    class FormNotSigned : public std::exception
    {
        public:
            const char *what() const throw();
    };
};

std::ostream	&operator<<(std::ostream &str, AForm const &form);

#endif