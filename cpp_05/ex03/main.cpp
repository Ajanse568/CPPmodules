#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    try
    {
        Intern someRandomIntern;
        AForm* formpie;
        Bureaucrat  Bert(1, "Bert");
        formpie = someRandomIntern.makeForm("robotomy request", "Bender");
        Bert.signForm(*formpie);
        Bert.executeForm(*formpie);
        someRandomIntern.makeForm("blaaa", "Bender");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;;
    }

}