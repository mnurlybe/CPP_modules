#include "Bureaucrat.hpp"

int main(void)
{
    Bureaucrat A("Anthony", 1);
    Bureaucrat B("Bryan", 150);

    //test copy constructor
    Bureaucrat C(A);
    std::cout << "C:" << C.getName() << " " << C.getGrade() << std::endl;

    //test assignation operator
    B = A;
    std::cout << "B:" << B.getName() << " " << B.getGrade() << std::endl;
    

    return 0;
}