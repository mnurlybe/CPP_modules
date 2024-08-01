#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string   target;

    public:
        RobotomyRequestForm();
        RobotomyRequestForm(std::string target);
        RobotomyRequestForm(RobotomyRequestForm const &source);
        RobotomyRequestForm const &operator=(RobotomyRequestForm const &source);
        ~RobotomyRequestForm();

        void    execute(Bureaucrat const &executor) const;
};

std::ostream    &operator<<(std::ostream &str, RobotomyRequestForm const &form);

#endif