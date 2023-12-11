//
// Created by allej on 12/10/2023.
//

#ifndef __INTERN_H
#define __INTERN_H

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

private:

public:

    Intern();
    Intern(const Intern &obj);
    ~Intern();

    Intern &operator=(const Intern &obj);

    AForm* makePresidential(const std::string &target);
    AForm* makeShrubbery(const std::string &target);
    AForm* makeRobotomy(const std::string &target);

    AForm* makeForm(const std::string &name, const std::string &target);

    class WrongNameException: public std::exception{
        virtual const char* what() const throw() {
            return( "No form with that name");
        }

    };
};


#endif //__INTERN_H
