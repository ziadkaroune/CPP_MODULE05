#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
class  ShrubberyCreationForm : public AForm
{
private:
        std::string _target ;
public:
      ShrubberyCreationForm();
     ShrubberyCreationForm(std::string target);
     ShrubberyCreationForm(const  ShrubberyCreationForm &copy);
     ShrubberyCreationForm& operator=(const  ShrubberyCreationForm &copy);
     void execute(Bureaucrat const &executor)const;
    ~ ShrubberyCreationForm();
};


#endif