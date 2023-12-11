#ifndef __PRESIDENTIALPARDONFORM_H__
# define __PRESIDENTIALPARDONFORM_H__

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class PresidentialPardonForm : public AForm 
{
public:

    PresidentialPardonForm(void);
    PresidentialPardonForm(const std::string& target);
    ~PresidentialPardonForm(void);
    PresidentialPardonForm(const PresidentialPardonForm& other);
    PresidentialPardonForm& operator=(const PresidentialPardonForm& other);

    void        execute(const Bureaucrat& executor) const;
    std::string getTarget(void) const { return _target; };

private:

    std::string _target;


};

#endif