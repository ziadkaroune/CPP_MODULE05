#include "Bureaucrat.hpp"


int main()
{
        Bureaucrat a("ziad" , 1);                      /// grade  == 1
        std::cout << "let's decrement the grade by 1 " << std::endl ; 


        try{
            a.decrement();
        }
        catch(const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "because" << a.getName() << "'s grade is " << a.getGrade() << std::endl;

        /////////////////////////////////////////////////////////////////////

        std::cout << "-------------------------------------" <<std::endl;
           a.increment();
        try{
            a.increment();
        }
        catch(const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
        std::cout << "No Exception Errors" << std::endl; 
        std::cout << "because " << a.getName() << "'s grade is " << a.getGrade() << std::endl;

        /////////////////////////////////////////////////////////////////////
        std::cout << "-------------------------------------" <<std::endl;

        Bureaucrat b("pioli" , 150);                      /// grade  == 1
        std::cout << "let's decrement the grade by 1 " << std::endl ; 

        try{
            b.increment();
        }
        catch(const std::exception &e)
        {
            std::cerr << "Exception: " << e.what() << std::endl;
        }

        std::cout << "because " << b.getName() << "'s grade is " << b.getGrade() << std::endl;

        /////////////////////////////////////////////////////////////////////

        std::cout << "-------------------------------------" <<std::endl;


    return 0;
}