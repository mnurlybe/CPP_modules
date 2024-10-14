#include "ShrubberyCreationForm.hpp"

/* ============= CONSTRUCTORS AND DESTRUCTOR ============= */

// Default constructor
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default_target") {}

// Parametric constructor
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {}

// Copy constructor
ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &source) : AForm(source), target(source.target) {}

// Assignation operator
ShrubberyCreationForm const &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &source)
{
    if (this != &source)
    {
        AForm::operator=(source);
        target = source.target;
    }
    return (*this);
}

// Destructor
ShrubberyCreationForm::~ShrubberyCreationForm() {}

/* Exceptions */
const char *ShrubberyCreationForm::FileNotOpened::what() const throw()
{
    return ("ShrubberyCreationForm: File could not be opened.");
}

/* ============= FUNCTIONS ============= */
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    
    try {
        AForm::execute(executor);
    } catch (AForm::GradeTooLowException &e) {
        throw AForm::GradeTooLowException();
    }
    catch (AForm::FormNotSigned &e) {
        throw AForm::FormNotSigned();
    }
    std::cout << "ShrubberyCreationForm is being executed by " << executor.getName() << std::endl; //Overwrite according to the subject
    std::ofstream outfile;
    outfile.open((target + "_shrubbery").c_str(), std::ios::out | std::ios::trunc);
    if (!outfile.is_open())
        throw ShrubberyCreationForm::FileNotOpened();

    outfile << "      /\\      " << std::endl;
    outfile << "     /\\*\\     " << std::endl;
    outfile << "    /\\O\\*\\    " << std::endl;
    outfile << "   /*/\\/\\/\\   " << std::endl;
    outfile << "  /\\O\\/\\*\\/\\  " << std::endl;
    outfile << " /\\*\\/\\*\\/\\/\\ " << std::endl;
    outfile << "/\\O\\/\\/*/\\/O/\\" << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile << "      ||      " << std::endl;
    outfile.close();
}

/* Overload of insertion operator */
std::ostream	&operator<<(std::ostream &str, ShrubberyCreationForm const &form)
{
    return (str << form.getName() << " form, signed: " << form.getSignStatus() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}