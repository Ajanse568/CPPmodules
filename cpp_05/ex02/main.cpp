#include "AForm.hpp"
#include "Bureaucrat.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
    Bureaucrat  Bert(1, "Bert");
    Bureaucrat  Ernie(150, "Ernie");
    Bureaucrat  koekie(42, "koekie");
    PresidentialPardonForm  pardon("Bert");
    RobotomyRequestForm     robot("Ernie");
    ShrubberyCreationForm   shrub("koekie");

    std::cout << pardon << std::endl;
    std::cout << robot << std::endl;
    std::cout << shrub << std::endl;

    
    Bert.executeForm(pardon);
    Bert.signForm(pardon);
    Bert.executeForm(pardon);
    Ernie.executeForm(robot);
    Ernie.signForm(robot);
    Ernie.executeForm(robot);
    koekie.executeForm(shrub);
    koekie.signForm(shrub);
    koekie.executeForm(shrub);
}