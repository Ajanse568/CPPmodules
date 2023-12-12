#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("default") {

}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) : AForm(other), _target(other._target) {
    std::cout << "ShrubberyCreationForm copy constructor called" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {

    if (this != &other) {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

}

std::string ShrubberyCreationForm::getTarget(void) const {
    return this->_target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    AForm::checkExec(executor.getGrade());
    std::string filename = this->_target + "_shrubbery";
    std::ofstream ofs(filename.c_str());
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