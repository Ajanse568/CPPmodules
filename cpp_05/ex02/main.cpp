#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    Bureaucrat 				jack(6, "Jack");
    Bureaucrat 				Bob(100, "Bob");
    Bureaucrat 				Charles(149, "Charles");
    PresidentialPardonForm	president("Victor");
    RobotomyRequestForm 	robot("Beep");
    ShrubberyCreationForm 	tree1("tree_1");
    ShrubberyCreationForm 	tree2("tree_2");
    try
    {
        jack.incrementGrade();
        std::cout << jack << std::endl;
        jack.executeForm(president);
        jack.signForm(president);
        jack.executeForm(robot);
        jack.signForm(robot);
        jack.executeForm(robot);
        jack.executeForm(robot);
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }

    try
    {
        Bob.signForm(tree1);
        Bob.executeForm(tree1);
        Charles.executeForm(tree2);
        Bob.executeForm(robot);
        Bob.executeForm(president);
        std::cout << Bob << std::endl;
        std::cout << Bob.getGrade() << std::endl;
    }
    catch (std::exception & e)
    {
        std::cerr << e.what() << std::endl;
    }
}