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
     std::string Bureaucrat::getName(void)const
     {
        return this->_name ;
     }
     int Bureaucrat::getGrade(void)const
     {
            return  this->_grade ;
     }

        std::ostream &operator<<(std::ostream &o, const Bureaucrat &a)
        {
            o << "Bureaucrat " << a.getName() << ": grade: " << a.getGrade() << std::endl;
            return (o);
        }