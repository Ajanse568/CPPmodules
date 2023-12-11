#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main()
{
    AForm* rrf;

    try
    {
        Bureaucrat jack(10, "Jack");
        Intern someRandomIntern;
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        jack.executeForm(*rrf);
//        delete rrf;
        jack.signForm(*rrf);
        jack.executeForm(*rrf);
        someRandomIntern.makeForm("Robomtomy Request", "Bender");
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;;
    }

}