#ifndef __SHRUBBERYCREATIONFORM_H__
# define __SHRUBBERYCREATIONFORM_H__

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class ShrubberyCreationForm : public AForm 
{
public:

    ShrubberyCreationForm(void);
    ShrubberyCreationForm(const std::string& target);
    ~ShrubberyCreationForm(void);
    ShrubberyCreationForm(const ShrubberyCreationForm& other);
    ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);

    void        execute(const Bureaucrat& executor) const;
    std::string getTarget(void) const { return _target; };

private:

    std::string _target;

};

#endif