#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
int main()
{
  ///// WRONG NAME OF FORM /////
    Intern *p =  new Intern();
    p->makeForm("ziad" , "pok");
    delete p;

  ///// CORRECT NAME OF FORM /////

    Intern *k =  new Intern();
    k->makeForm("ShrubberyCreationForm" , "home ");
    delete k;

    return 0;
}
