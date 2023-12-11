//
// Created by allej on 12/10/2023.
//
// Complete this file according to Intern.hpp
#include "Intern.hpp"

Intern::Intern() {
    std::cout << "Intern default constructor called" << std::endl;
};

Intern::Intern(const Intern &obj) {
    std::cout << "Intern copy constructor called" << std::endl;
}

Intern::~Intern() {
    std::cout << "Intern destructor called" << std::endl;
}

Intern &Intern::operator=(const Intern &obj) {
    std::cout << "Intern assignment operator called" << std::endl;
    return *this;
}

AForm* Intern::makePresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}

AForm* Intern::makeRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}

AForm* Intern::makeForm(const std::string &name, const std::string &target) {
    AForm* (Intern::*form[3])(const std::string &target) = {&Intern::makePresidential, &Intern::makeShrubbery, &Intern::makeRobotomy};
    std::string formNames[3] = {"presidential pardon", "shrubbery creation", "robotomy request"};
    for (int i = 0; i < 3; i++) {
        if (name == formNames[i]) {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*form[i])(target);
        }
    }
    throw Intern::WrongNameException();
}