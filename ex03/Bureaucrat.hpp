#ifndef BUREAUCRAT_HPP
#   define BUREAUCRAT_HPP

#include "AForm.hpp"
#include <iostream>
#include <fstream> 
#include <string>
class   AForm;
class Bureaucrat
{
private:
    const std::string _name;
    int _grade;
    
public:
     Bureaucrat();
     Bureaucrat(std::string name , int grade);
     Bureaucrat( const  Bureaucrat &copy);
     Bureaucrat& operator=( const  Bureaucrat &copy);
     class GradeTooHighException : public std::exception
     {
        public:
		virtual const char *what() const throw();
     };
     class GradeTooLowException : public std::exception{
        public:
		    virtual const char *what() const throw();
     };
     void  check_grade_range(int grade ,  std::string name);
     void   signForm(AForm &form);
     void increment(void);
     void decrement(void);
    std::string getName(void)const;
     int getGrade(void)const;
     void executeForm(AForm &Aform)const;
 
    ~Bureaucrat();
};
std::ostream &operator<<(std::ostream &o, const Bureaucrat &a);



#endif