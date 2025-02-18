#include "PresidentialPardonForm.hpp"


PresidentialPardonForm::PresidentialPardonForm() : AForm::AForm("PresidentialPardonForm", 25, 5), _target("null") 
{

}
PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm::AForm("PresidentialPardonForm", 25, 5), _target(target) 
{

}
PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &copy)
{
    *this = copy;
}

PresidentialPardonForm::~PresidentialPardonForm()
{

}
void PresidentialPardonForm::execute(Bureaucrat const &executor)const
{
    (void)executor;
	std::cout << this->_target << " has been pardoned by Zafod Beeblebrox" << std::endl;
}