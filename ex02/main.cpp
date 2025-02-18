#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
int main()
{
 
  
    Bureaucrat ap("ceo", 10);  
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    AForm *l = new AForm("insurance", 100, 10);    

    std::cout << "-------------------------------------" << std::endl;   
    try {
        l->beSigned(&ap);
        std::cout << l->is_signed() << std::endl ;
    }       
    catch( Bureaucrat::GradeTooLowException &e) {
        std::cerr << ap.getName() << "  couldn’t sign the Form " << l->getName() << ": " << e.what()  << std::endl;
    }
     ShrubberyCreationForm *a = new ShrubberyCreationForm("homew");
     a->execute(ap);
     delete a;
    std::cout << "-------------------------------------" << std::endl;   
    RobotomyRequestForm *b = new RobotomyRequestForm("studio");
    b->execute(ap);
    delete b;
    std::cout << "-------------------------------------" << std::endl;  
    PresidentialPardonForm *c  = new PresidentialPardonForm("mall");
    c->execute(ap);

    std::cout << "-------------------------------------" << std::endl;  
    std::cout << l->execute(ap) << std::endl;
    delete c;
    delete l;
    return 0;
}
