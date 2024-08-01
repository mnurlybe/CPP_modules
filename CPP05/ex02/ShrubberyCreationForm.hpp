#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"

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
};

std::ostream    &operator<<(std::ostream &str, ShrubberyCreationForm const &form);

#endif