/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:35:02 by francesca         #+#    #+#             */
/*   Updated: 2026/02/11 15:44:32 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", false, 145, 137), _target("DefaultTarget"){
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", false, 145, 137), _target(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), _target(other._target) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    if (this != &other)
    {
        AForm::operator=(other);
        this->_target = other._target;
    }
    return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

std::string ShrubberyCreationForm::getTarget() const {
    return(this->_target);
}

void ShrubberyCreationForm::execThrees() const {
    
    std::string filename = this->getTarget() + "_shrubbery";
    std::ofstream out(filename.c_str());   // crea/apre e sovrascrive

    if (!out)  // se apertura fallisce
        throw std::runtime_error("could not open file"); // oppure tua eccezione

    out <<
"\n"
"              ccee88oo\n"
"        C8O8O8Q8PoOb o8oo\n"
"      dOB69QO8PdUOpugoO9bD\n"
"     CgggbU8OU qOp qOdoUOdcb\n"
"         6OuU  /p u gcoUodpP\n"
"           \\\\\\//  /douUP\n"
"             \\\\\\////\n"
"              |||/\\\n"
"              |||\\/\n"
"              |||||\n"
"        .....//||||\\....\n"
"\n";
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!this->get_isSigned())
        throw FormNotSignedException();
    if (executor.getGrade() > this->get_rExecuteGrade())
        throw execGradeTooLowException();
    else
        this->execThrees();
}