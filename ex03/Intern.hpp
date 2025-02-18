#ifndef INTERN_HPP
#   define INTERN_HPP

#include  "Bureaucrat.hpp"
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern
{
private:
public:
    Intern();
    Intern(const Intern  &copy);
    Intern& operator=(const Intern  &copy);
    AForm *makeForm(const std::string form_name , const std::string form_target);
    ~Intern();
};


#endif