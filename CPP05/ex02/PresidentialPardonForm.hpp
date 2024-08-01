#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string   target;

    public:
        PresidentialPardonForm();
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(PresidentialPardonForm const &source);
        PresidentialPardonForm const &operator=(PresidentialPardonForm const &source);
        ~PresidentialPardonForm();

        void    execute(Bureaucrat const &executor) const;
};

std::ostream    &operator<<(std::ostream &str, PresidentialPardonForm const &form);

#endif