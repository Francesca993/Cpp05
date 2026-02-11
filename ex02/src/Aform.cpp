/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 13:17:27 by francesca         #+#    #+#             */
/*   Updated: 2026/02/11 16:29:46 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): _name("DefaultAForm"), _isSigned(false), _requiredSignGrade(150), _requiredExecuteGrade(150) {
}

AForm::AForm(std::string name, bool isSigned, int requiredSignGrade, int requiredExecuteGrade) : _name(name), _isSigned(isSigned), _requiredSignGrade(requiredSignGrade), _requiredExecuteGrade(requiredExecuteGrade) {
    
    //Check Execute grade
    if (_requiredExecuteGrade < 1)
        throw execGradeTooHighException();
    if (_requiredExecuteGrade > 150)
        throw execGradeTooLowException();
    //Check Sign Grade
    if (_requiredSignGrade < 1)
        throw signGradeTooHighException();
    if (_requiredSignGrade >150)
        throw signGradeTooLowException();
}

AForm::AForm(const AForm &other) : _name(other._name), _isSigned(other._isSigned), _requiredSignGrade(other._requiredSignGrade), _requiredExecuteGrade(other._requiredExecuteGrade){
}

AForm& AForm::operator=(const AForm& other){
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return(*this);
}

AForm::~AForm(){
    
}

const std::string AForm::getName() const {
    return(this->_name);
}

int AForm::get_rSignGrade() const{
    return(this->_requiredSignGrade);
}

int AForm::get_rExecuteGrade() const {
    return(this->_requiredExecuteGrade);
}

bool AForm::get_isSigned() const{
    return(this->_isSigned);
}

const char* AForm::signGradeTooHighException::what() const throw() {
    return "AForm Sign Grade too high";
}

const char* AForm::signGradeTooLowException::what() const throw() {
    return("AForm Sign Grade too low");
}

const char* AForm::execGradeTooHighException::what() const throw() {
    return "AForm Execution Grade too high";
}

const char* AForm::execGradeTooLowException::what() const throw() {
    return("AForm Execution Grade too low");
}

const char* AForm::FormNotSignedException::what() const throw() {
    return("AForm isn't signed.");
}

void AForm::beSigned(const Bureaucrat& _bur){
    if (_bur.getGrade() > this->_requiredSignGrade)
        throw signGradeTooLowException();
    else
        this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, AForm const& Aform){
    
    std::string str;
    if (Aform.get_isSigned() == true)
    {
        str = "AForm is signed.";
    }
    else
        str = "AForm isn't signed.";
    
    os << "AForm Name: " << Aform.getName() << "\n" << str << "\nGrade need to sign: " << Aform.get_rSignGrade() << "\nGrade need to execute: " << Aform.get_rExecuteGrade();
    return os;
}

