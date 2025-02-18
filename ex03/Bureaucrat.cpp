/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkaroune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:27:36 by zkaroune          #+#    #+#             */
/*   Updated: 2025/02/18 22:27:47 by zkaroune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("default") , _grade(150)
{
        check_grade_range(this->_grade , this->_name); 
}
Bureaucrat::Bureaucrat(std::string name , int grade) :  _name(name) , _grade(grade)
{
        check_grade_range(grade , name);
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};
 void Bureaucrat::check_grade_range(int grade ,  std::string name)
 {
        if(grade < 1) 
            throw Bureaucrat::GradeTooHighException();
        else if(grade > 150)
            throw Bureaucrat::GradeTooLowException();
        else
            std::cout << name << " Bureaucrat " << grade << std::endl;

 }
Bureaucrat::Bureaucrat( const  Bureaucrat &copy)
{
        *this = copy ;
}

Bureaucrat &Bureaucrat::operator=( const  Bureaucrat &copy)
{
        return *this;
}

Bureaucrat::~Bureaucrat()
{

}

    void Bureaucrat::increment(void)
    {
        this->_grade++ ;
        check_grade_range(this->_grade, this->_name);
        
    }
     void Bureaucrat::decrement(void)
     {
        this->_grade--;
        check_grade_range(this->_grade, this->_name);

     }
     void Bureaucrat::signForm(AForm &form)
     {
        form.beSigned(this);
     }
     std::string Bureaucrat::getName(void)const
     {
        return this->_name ;
     }
     int Bureaucrat::getGrade(void)const
     {
            return  this->_grade ;
     }
     void	Bureaucrat::executeForm(AForm &Aform)const
     {
        try
        {
            Aform.execute(*this);
        }
        catch (std::exception &e)
        {
            std::cout << this->_name << " cannot execute " << Aform.getName() << " because: " << e.what() << std::endl;
        }
     }

        std::ostream &operator<<(std::ostream &o, const Bureaucrat &a)
        {
            o << "Bureaucrat " << a.getName() << ": grade: " << a.getGrade() << std::endl;
            return (o);
        }
