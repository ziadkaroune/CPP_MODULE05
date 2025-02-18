#include "ShrubberyCreationForm.hpp"

    ShrubberyCreationForm::ShrubberyCreationForm() : AForm::AForm("ShrubberyCreationForm", 145, 137), _target("null"){}
    ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :AForm::AForm("ShrubberyCreationForm", 145, 137), _target(target){}
    ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy)
    {
        *this = copy;
    }
    ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy)
    {
        return *this;
    }
    ShrubberyCreationForm::~ShrubberyCreationForm()
    {

    }
 void  ShrubberyCreationForm::execute(Bureaucrat const &executor)const
 {
     if(executor.getGrade() > this->getGradeExec()) 
            throw Bureaucrat::GradeTooHighException();
        else if(this->is_bsigned())
            throw AForm::GradeTooLowException();
        else{
            std::ofstream outFile(this->_target + "_shrubbery");
            outFile << "       ^\n"
                    << "      ^^^\n"
                    << "     ^^^^^\n"
                    << "    ^^^^^^^\n"
                    << "   ^^^^^^^^^\n"
                    << "      |||\n";

            outFile.close();
        }
 }