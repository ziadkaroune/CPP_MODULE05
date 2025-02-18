#ifndef AFORM_HPP    
#   define AFORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
class Bureaucrat;
class AForm 
{
private:
    const std::string _name;
    bool _is_signed;
    int  _grade_req;
    int  _grade_exec ;


public:
    AForm();
    AForm( std::string name , int grade_req , int grade_exec);
    AForm(const AForm &copy);
    AForm& operator=(const AForm &copy);
    ~AForm();
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
    std::string is_signed(void)const;
    std::string execute(Bureaucrat const & executor) const ;
    bool is_bsigned()const;
    
};
std::ostream &operator<<(std::ostream &o, const AForm &a);
#endif
