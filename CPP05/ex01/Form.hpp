#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class Form
{
    private:
        std::string const   name;
        bool                is_signed;
        int const           SignGrade;
        int const           ExecGrade;
    public:
        Form(); // Default constructor
        Form(std::string const &name, int const &SignGrade, int const &ExecGrade); // Parametric constructor
        Form(const Form &source); // Copy constructor
        Form &operator=(const Form &source); // Assignation operator
        ~Form(); // Destructor

    // Getters
    std::string  getName() const;
    bool   getSignStatus() const;
    int    getSignGrade() const;
    int    getExecGrade() const;

    // Member Functions
    void    beSigned(Bureaucrat &b);

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
};

std::ostream	&operator<<(std::ostream &str, Form const &form);

#endif