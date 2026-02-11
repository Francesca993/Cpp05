/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:35:27 by francesca         #+#    #+#             */
/*   Updated: 2026/02/09 20:15:19 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): _name("DefaultBureaucrat"), _grade(150){
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(std::string name, int grade): _name(name), _grade(grade){
    if (_grade < 1)
        throw GradeTooHighException();
    if (_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade){
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other){
    //Non puo ri-assegnare il nome perchè è const quindi copiera solo il grade
    this->_grade = other._grade;
    return(*this);
}

Bureaucrat::~Bureaucrat(){
    
}

const std::string Bureaucrat::getName() const{
    return(this->_name);
}

int Bureaucrat::getGrade() const{
    return(this->_grade);
}

void Bureaucrat::incrementGrade(){
    if (_grade == 1)
        throw GradeTooHighException();
    else
        this->_grade--;
    
}

void Bureaucrat::signForm(Form& form)
{
    try {
        form.beSigned(*this);
        std::cout << GREEN << this->getName() << " signed " << form.getName() << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << RED << this->getName() << " couldn’t sign " << form.getName() << " because: " << e.what() << RESET << std::endl;
    }
}

void Bureaucrat::decrementGrade(){
    if (_grade == 150)
        throw GradeTooLowException();
    else
        this->_grade++;
}

const char* Bureaucrat::GradeTooHighException::what() const throw() {
    return "Grade too high";
}

const char* Bureaucrat::GradeTooLowException::what() const throw() {
    return("Grade too low");
}

std::ostream& operator<<(std::ostream& os, Bureaucrat const& br){
    os << br.getName() << ", bureaucrat grade " << br.getGrade() << ".";
    return os;
}

/*

// serve per poter scrivere:
// Fixed a(42.42f);
// std::cout << a << std::endl;
// e far sì che a venga stampato in modo “sensato”  come float.
// Senza questo overload, il compilatore non sa cosa vuol dire << a per un oggetto di tipo Fixed.
std::ostream& operator<<(std::ostream& os, Fixed const& fx)
{
    os << fx.toFloat();
    return os;
}


class Bureaucrat {
    private:
    const   std::string _name;
    int     grade; // that ranges from 1 (highest possible grade) to 150 (lowest possible grade)

    public:
    Bureaucrat();
    Bureaucrat(std::string name, int grade);
    Bureaucrat(const Bureaucrat &other);
    Bureaucrat&operator=(const Bureaucrat &other);
    ~Bureaucrat();
    
    const std::string getName() const;
    int getGrade() const;
    void incrementGrade(); // scendere da 3 → 2
    void decrementGrade(); // decrementare significa salire di numero da 3 → 4 se esci dal range → stesse eccezioni del costruttore
    
    // Exceptions (TIPI, non funzioni)
    class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& br);
*/