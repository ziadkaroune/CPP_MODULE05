#ifndef FORM_HPP    
#   define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;
class Form 
{
private:
    const std::string _name;
    bool _is_signed;
    int  _grade_req;
    int  _grade_exec ;


public:
    Form();
    Form( std::string name , int grade_req , int grade_exec);
    Form(const Form &copy);
    Form& operator=(const Form &copy);
    ~Form();
     class GradeTooHighException : public std::exception
     {
        public:
		virtual const char *what() const throw();
     };
     class GradeTooLowException : public std::exception{
        public:
		    virtual const char *what() const throw();
     };
    void  check_grade_range(int grade_req , int grade_exec ,  std::string name);
    std::string getName()const;
    int getGradeReq()const;
    int getGradeExec()const;
    void beSigned(Bureaucrat *ap);
    std::string is_signed(void);
};
std::ostream &operator<<(std::ostream &o, const Form &a);
#endif
