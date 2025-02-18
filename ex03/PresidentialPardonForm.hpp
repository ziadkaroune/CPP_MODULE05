#ifndef PRESIDENTIALPARDONFORM_HPP
#   define PRESIDENTIALPARDONFORM_HPP
#include  "Bureaucrat.hpp"
#include "AForm.hpp"
class PresidentialPardonForm : public AForm
{
private:
    std::string _target;
public:
    PresidentialPardonForm();
    PresidentialPardonForm(std::string  target);
     PresidentialPardonForm(const  PresidentialPardonForm  &copy);
    void execute(Bureaucrat const &executor)const;
    ~PresidentialPardonForm();
};

#endif