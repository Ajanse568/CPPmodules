#ifndef __ROBOTOMYREQUESTFORM_H__
# define __ROBOTOMYREQUESTFORM_H__

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class RobotomyRequestForm : public AForm 
{
public:

    RobotomyRequestForm(void);
    RobotomyRequestForm(const std::string& target);
    ~RobotomyRequestForm(void);
    RobotomyRequestForm(const RobotomyRequestForm& other);
    RobotomyRequestForm& operator=(const RobotomyRequestForm& other);

    void        execute(const Bureaucrat& executor) const;
    std::string getTarget(void) const { return _target; };

private:

    std::string _target;

};

#endif