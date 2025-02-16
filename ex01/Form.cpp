#include "Form.hpp"

    Form::Form()  : _name("default name") , _grade_req(150)  , _grade_exec(150)  , _is_signed(false)
    {
            
    }
    Form::Form( std::string name , int grade_req , int grade_exec) : _name(name) , _grade_req(grade_req)  , _grade_exec(grade_exec)  , _is_signed(false)
    {
              check_grade_range(this->_grade_req , this->_grade_exec , this->_name); 
    }
    Form::Form(const Form &copy)
    {
        *this = copy;
    }
    Form &Form::operator=(const Form &copy)
{
    if (this != &copy) {
        this->_is_signed = copy._is_signed;
    }
    return *this;
}
    Form::~Form(){

    }
const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};
 void Form::check_grade_range(int grade_req , int grade_exec ,  std::string name)
 {
        if(grade_req < 1 || grade_exec < 1 ) 
            throw Form::GradeTooHighException();
        else if(grade_req > 150 || grade_req > 150)
            throw Form::GradeTooLowException();

 }

void Form::beSigned(Bureaucrat *ap) {
    if (ap->getGrade() <= this->_grade_req)
        this->_is_signed = true;
    else
        throw Bureaucrat::GradeTooLowException();
}
    std::string Form::getName() const
    {
          return (this->_name );
    }
    int Form::getGradeReq() const
    {
          return (this->_grade_req );
    }
      int Form::getGradeExec() const
    {
          return (this->_grade_exec );
    }
   std::string Form::is_signed(void)
    {
        if(this->_is_signed == true)
            return (" is signed seccesfully ");
        else 
         return (" need to be signed ");
    }

std::ostream &operator<<(std::ostream &o, const Form &a)  // Note: Added const
{
    o << "Form " << a.getName() << ": grade required: " << a.getGradeReq() 
      << " || grade execute: " << a.getGradeExec() << std::endl;
    return o;
}