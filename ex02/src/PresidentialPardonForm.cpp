/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:31:11 by francesca         #+#    #+#             */
/*   Updated: 2026/02/11 15:41:12 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", false, 25, 5), _target("DefaultTarget"){
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", false, 25, 5), _target(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other), _target(other._target) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

std::string PresidentialPardonForm::getTarget() const {
    return(this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
    if (!this->get_isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->get_rExecuteGrade())
        throw execGradeTooLowException();
    else
        std::cout << YELLOW << this->getTarget() << " has been pardoned by Zaphod Beeblebrox." << RESET << std::endl;
}