#include "RobotomyRequestForm.hpp"

    RobotomyRequestForm::RobotomyRequestForm() : AForm::AForm("RobotomyRequestForm", 72, 45), _target("null"){}
    RobotomyRequestForm::RobotomyRequestForm(std::string target) :AForm::AForm("RobotomyRequestForm", 72, 45), _target(target){}
    RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy)
    {
        *this = copy;
    }
    RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &copy)
    {
        return *this;
    }
    RobotomyRequestForm::~RobotomyRequestForm()
    {

    }
 void  RobotomyRequestForm::execute(Bureaucrat const &executor)const
 {
        std::cout << "* Drilling noises *" << std::endl;
        srand(time(NULL)); 
        if (rand() % 2 == 0) {  
            std::cout << this->_target << " has been robotomized successfully!" << std::endl;
        } else {
            std::cout << "The robotomy failed for " << this->_target << "." << std::endl;
        }
 }