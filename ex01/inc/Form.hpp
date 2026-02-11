/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:34:01 by francesca         #+#    #+#             */
/*   Updated: 2026/02/10 13:20:12 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class Form {
    private:
    const std::string _name;
    bool _isSigned;
    const int _requiredSignGrade;
    const int _requiredExecuteGrade;
    
    public:
    Form();
    Form(std::string name, const int rSignGrade, const int rExecuteGrade);
    Form(const Form &other);
    Form&operator=(const Form &other);
    ~Form();

    //Getters
    const std::string getName() const;
    int get_rSignGrade() const;
    int get_rExecuteGrade() const;
    bool get_isSigned() const;

    void beSigned(const Bureaucrat& _bur);
    
    
    // Exceptions (TIPI, non funzioni)
    class signGradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class signGradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };

        class execGradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
    };

    class execGradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
    };
    
};

std::ostream& operator<<(std::ostream& os, Form const& form);

#endif