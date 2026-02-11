/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 20:19:42 by francesca         #+#    #+#             */
/*   Updated: 2026/02/10 13:24:52 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): _name("DefaultForm"), _isSigned(false), _requiredSignGrade(1), _requiredExecuteGrade(1) {
}

Form::Form(std::string name, const int rSignGrade, const int rExecuteGrade) : _name(name), _isSigned(false), _requiredSignGrade(rSignGrade), _requiredExecuteGrade(rExecuteGrade){
    if (_requiredExecuteGrade < 1)
        throw execGradeTooHighException();
    if (_requiredSignGrade < 1)
        throw signGradeTooHighException();
        
    if (_requiredExecuteGrade > 150)
        throw execGradeTooLowException();
    if (_requiredSignGrade >150)
        throw signGradeTooLowException();
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _requiredSignGrade(other._requiredSignGrade), _requiredExecuteGrade(other._requiredExecuteGrade){
}

Form& Form::operator=(const Form& other){
    if (this != &other)
    {
        this->_isSigned = other._isSigned;
    }
    return(*this);
}

Form::~Form(){
    
}

const std::string Form::getName() const {
    return(this->_name);
}

int Form::get_rSignGrade() const{
    return(this->_requiredSignGrade);
}

int Form::get_rExecuteGrade() const {
    return(this->_requiredExecuteGrade);
}

bool Form::get_isSigned() const{
    return(this->_isSigned);
}

const char* Form::signGradeTooHighException::what() const throw() {
    return "Form Sign Grade too high";
}

const char* Form::signGradeTooLowException::what() const throw() {
    return("Form Sign Grade too low");
}

const char* Form::execGradeTooHighException::what() const throw() {
    return "Form Execution Grade too high";
}

const char* Form::execGradeTooLowException::what() const throw() {
    return("Form Execution Grade too low");
}

void Form::beSigned(const Bureaucrat& _bur){
    if (_bur.getGrade() > this->_requiredSignGrade)
        throw signGradeTooLowException();
    else
        this->_isSigned = true;
}

std::ostream& operator<<(std::ostream& os, Form const& form){
    
    std::string str;
    if (form.get_isSigned() == true)
    {
        str = "Form is signed.";
    }
    else
        str = "Form isn't signed.";
    
    os << "Form Name: " << form.getName() << "\n" << str << "\nGrade need to sign: " << form.get_rSignGrade() << "\nGrade need to execute: " << form.get_rExecuteGrade();
    return os;
}