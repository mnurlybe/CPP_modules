#include "Bureaucrat.hpp"

int main(void)
{
    // //test parametric constructor
    // Bureaucrat A("Anthony", 1);
    // std::cout << A << std::endl;

    // //test constructor
    // Bureaucrat B;
    // std::cout << B << std::endl;

    // //test copy constructor
    // Bureaucrat C(A);
    // std::cout << C << std::endl;

    // // test assignation operator
    // B = A;
    // std::cout << B << std::endl;
    
    try {
        Bureaucrat C("Calvin", 0);
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    Bureaucrat D("David", 2);
    std::cout << D << std::endl;
    try {
        D.GradeUp();
        std::cout << D << std::endl;
        D.GradeUp();
        std::cout << D << std::endl;
    } catch (Bureaucrat::GradeTooHighException &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    Bureaucrat E("Elvis", 75);
    std::cout << E << std::endl;
    try {
        E.GradeDown();
        std::cout << E << std::endl;
    } catch (Bureaucrat::GradeTooLowException &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}
