#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("default") {
    std::cout << "RobotomyRequestForm default constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const std::string& target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
    std::cout << "RobotomyRequestForm constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) : AForm(other), _target(other._target) {
    std::cout << "RobotomyRequestForm copy constructor called" << std::endl;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    std::cout << "RobotomyRequestForm assignment operator called" << std::endl;
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
    std::cout << "RobotomyRequestForm destructor called" << std::endl;
}

#include <fstream>

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    std::cout << "RobotomyRequestForm execute function called" << std::endl;
    AForm::execute(executor);
    std::string filename = _target + "_shrubbery";
    std::ofstream ofs(filename);
    if (ofs.is_open()) {
        ofs << "      /\\\n"
               "     /\\*\\\n"
               "    /\\O\\*\\\n"
               "   /*/\\/\\/\\\n"
               "  /\\O\\/\\*\\/\\\n"
               " /\\*\\/\\*\\/\\/\\\n"
               "/\\O\\/\\/*/\\/O/\\\n"
               "      ||\n"
               "      ||\n"
               "      ||" << std::endl;
        ofs.close();
        std::cout << "File " << filename << " has been created." << std::endl;
    } else {
        std::cerr << "Error: could not create file " << filename << std::endl;
    }
}