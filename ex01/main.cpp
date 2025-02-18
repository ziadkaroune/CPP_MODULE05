#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "-------------------------------------" << std::endl;   

   ////////////////////////////////////////////    try to catch the error of low grade of Form
        std::cout << "TRY WRONG GRADE FOR FROM CLASS TO CATCH THE ERROR  BY EXCEPTION"<<  std::endl;
        Form *a = NULL;
        try
        {   
         a = new Form("CDI" , -1 , 200);   //// grade to heigh  -1 < 1
         a->getName() ;
        }
        catch(Form::GradeTooHighException &e)
        {
            std::cerr << "Exception : Form " <<e.what() << '\n';
        }
        
        

        Form *b = NULL;
        try
        {   
         b = new Form("CDI" , 400 , 200);    //// grade to heigh  160 > 150
         b->getName() ;
        }
        catch(Form::GradeTooLowException &e)
        {
            std::cerr << "Exception : Form " <<e.what() << std::endl;
        }
        
        delete a ;
        delete b ;



    std::cout << "-------------------------------------" << std::endl;   
    Bureaucrat ap("ceo", 10);


 ////////////////////////////////////////////     grade_req <  grade  (print an error)

    Form *l = new Form("insurance", 1, 10);    

    try {
        l->beSigned(&ap); 
    }       
    catch( Bureaucrat::GradeTooLowException &e) {
        std::cerr << ap.getName() << "  couldn’t sign the Form " << l->getName() << ": " << e.what()  << std::endl;
    }

    delete l;

    ////////////////////////////////////////////     grade_req <  grade  (print an error)
    std::cout << "-------------------------------------" << std::endl;  
    Form *p= new Form("insurance", 103, 10);    

    try {
       ap.signForm(*p);     ///  change the message
    }       
    catch( Bureaucrat::GradeTooLowException &e) {
        std::cerr << ap.getName() << "  couldn’t sign " << p->getName() << ": " << e.what()  << std::endl;
    }

    delete p;

    std::cout << "-------------------------------------" << std::endl;      

    return 0;
}
