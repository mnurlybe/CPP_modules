#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
    /* Test 1 */
    Bureaucrat Alan("Alan", 50);
    std::cout << Alan << std::endl;

    Form F1("Form1", 50, 70);
    std::cout << F1 << std::endl;

    Alan.signForm(F1);
    std::cout << F1 << std::endl;

    /* Test 2 */
    // try {
    //     Form F2("Form2", 150, 5);
    //     std::cout << F2 << std::endl;
    // } catch (Form::GradeTooHighException &e) {
    //     std::cout << "Exception: " << e.what() << std::endl;
    // } catch (Form::GradeTooLowException &e) {
    //     std::cout << "Exception: " << e.what() << std::endl;
    // }

    /* Test 3 */
    // Bureaucrat Bob("Bob", 51);
    // std::cout << Bob << std::endl;

    // Form F3("Form3", 50, 70);
    // std::cout << F3 << std::endl;

    // Bob.signForm(F3);

    return 0;
}
