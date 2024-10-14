#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <iostream>

class ShrubberyCreationForm : public AForm
{
    private:
        std::string   target;

    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(ShrubberyCreationForm const &source);
        ShrubberyCreationForm const &operator=(ShrubberyCreationForm const &source);
        ~ShrubberyCreationForm();

        void    execute(Bureaucrat const &executor) const;

        class FileNotOpened : public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream    &operator<<(std::ostream &str, ShrubberyCreationForm const &form);

#endif