#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Form;

class Bureaucrat
{
    private:
        std::string name;
        int grade;
    public:
        Bureaucrat(); // Default constructor
        Bureaucrat(std::string const &name, int grade); // Parametric constructor
        Bureaucrat(const Bureaucrat &source); // Copy constructor
        Bureaucrat &operator=(const Bureaucrat &source); // Assignation operator
        ~Bureaucrat(); // Destructor

        // Getters
        std::string getName() const;
        int getGrade() const;

        //Member Functions
        void GradeUp(void);
        void GradeDown(void);
        void signForm(Form &form);

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

std::ostream	&operator<<(std::ostream &str, Bureaucrat const &bureaucrat);

#endif