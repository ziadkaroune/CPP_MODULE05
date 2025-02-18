/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkaroune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:27:56 by zkaroune          #+#    #+#             */
/*   Updated: 2025/02/18 22:28:17 by zkaroune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

    AForm::AForm()  : _name("default name") , _grade_req(150)  , _grade_exec(150)  , _is_signed(false) 
    {
            
    }
    AForm::AForm( std::string name , int grade_req , int grade_exec) : _name(name) , _grade_req(grade_req)  , _grade_exec(grade_exec)  , _is_signed(false) 
    {
              check_grade_range(this->_grade_req , this->_grade_exec , this->_name); 
    }
    AForm::AForm(const AForm &copy)
    {
        *this = copy;
    }
    AForm &AForm::operator=(const AForm &copy)
{
    if (this != &copy) {
        this->_is_signed = copy._is_signed;
    }
    return *this;
}
    AForm::~AForm(){

    }
const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};
 void AForm::check_grade_range(int grade_req , int grade_exec ,  std::string name)
 {
        if(grade_req < 1 || grade_exec < 1 ) 
            throw AForm::GradeTooHighException();
        else if(grade_req > 150 || grade_req > 150)
            throw AForm::GradeTooLowException();

 }

void AForm::beSigned(Bureaucrat *ap) {
    if (ap->getGrade() <= this->_grade_req)
        this->_is_signed = true;
    else
        throw Bureaucrat::GradeTooLowException();
}
    std::string AForm::getName() const
    {
          return (this->_name );
    }
    int AForm::getGradeReq() const
    {
          return (this->_grade_req );
    }
      int AForm::getGradeExec() const
    {
          return (this->_grade_exec );
    }
   std::string AForm::is_signed(void)const
    {
        if(this->_is_signed == true)
            return ("is signed seccesfully");
        else 
         return ("need to be signed");
    }
       bool AForm::is_bsigned()const
       {
            if(this->_is_signed == true)
                return true;
            return false;
       }
        std::string   AForm::execute(Bureaucrat const &executor) const 
        {
               return (executor.getName() + " executed " + this->_name) ;
        }

std::ostream &operator<<(std::ostream &o, const AForm &a)  // Note: Added const
{
    o << "AForm " << a.getName() << ": grade required: " << a.getGradeReq() 
      << " || grade execute: " << a.getGradeExec() << std::endl;
    return o;
}
