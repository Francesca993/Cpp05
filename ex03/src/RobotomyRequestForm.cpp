/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 15:42:10 by francesca         #+#    #+#             */
/*   Updated: 2026/02/11 16:11:21 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", false, 72, 45), _target("DefaultTarget"){
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", false, 72, 45), _target(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), _target(other._target) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return(*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

std::string RobotomyRequestForm::getTarget() const {
    return(this->_target);
}

int RobotomyRequestForm::robotomyNoise() const {
    std::srand(std::time(NULL));
    int r = std::rand() % 2;
    std::cout << YELLOW << "* drilling noises *" << RESET << std::endl;
    std::cout << YELLOW << "⚙️  Clank! Clonk! *gears arguing with each other*" << RESET << std::endl;
    return(r);
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
    if (!this->get_isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->get_rExecuteGrade())
        throw execGradeTooLowException();
    else
    {
        if (this->robotomyNoise() == 0) // Success
            std::cout << GREEN << executor.getName() << " has been robotomized successfully." << RESET << std::endl;
        else
            std::cout << RED << executor.getName() << " failed robotomized." << RESET << std::endl;
        
    }
}


/*
RobotomyRequestForm: Required grades: sign 72, exec 45
Makes some drilling noises, then informs that <target> has been robotomized
successfully 50% of the time. Otherwise, it informs that the robotomy failed.
*/