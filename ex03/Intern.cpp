/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zkaroune <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 22:26:58 by zkaroune          #+#    #+#             */
/*   Updated: 2025/02/18 22:27:01 by zkaroune         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
Intern::Intern(){
    std::cout  << "Intern is ready for the unpaid internship" << std::endl;
}
Intern::Intern(const Intern &copy){
    *this =  copy;
}
Intern &Intern::operator=(const Intern &copy)
{
    return(*this);
}
Intern::~Intern(){}


AForm *Intern::makeForm(const std::string form_name , const std::string form_target)
{

   const  std::string type_form[3] = {"PresidentialPardonForm", "RobotomyRequestForm", "ShrubberyCreationForm"};
      AForm* forms[3] = {
            new ShrubberyCreationForm(form_target),
            new RobotomyRequestForm(form_target),
            new PresidentialPardonForm(form_target)
        };

        for(int i = 0; i < 3 ; i++)
        {
            if(type_form[i] == form_name)
            {
                std::cout << "Intern creates " << form_name <<std::endl;
                
            	 delete forms[i] ;
                 return(forms[i]);
            }
                delete forms[i] ;
            
        }
        std::cout << "form name :" << form_name << "doesn't exist" <<std::endl;
        
       
       return(NULL);
}
