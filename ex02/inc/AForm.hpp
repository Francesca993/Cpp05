/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 18:34:01 by francesca         #+#    #+#             */
/*   Updated: 2026/02/10 13:41:44 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

class Bureaucrat;

class AForm {
    private:
    const std::string _name;
    bool _isSigned;
    const int _requiredSignGrade;
    const int _requiredExecuteGrade;

    public:
    AForm();
    AForm(std::string name, bool isSigned, int requiredSignGrade, int requiredExecuteGrade);
    AForm(const AForm &other);
    AForm&operator=(const AForm &other);
    virtual ~AForm();

    //Getters
    const std::string getName() const;
    int get_rSignGrade() const;
    int get_rExecuteGrade() const;
    bool get_isSigned() const;

    virtual void beSigned(const Bureaucrat& _bur);
    virtual void execute(Bureaucrat const & executor) const = 0;
    
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

    class FormNotSignedException : public std::exception {
    public:
        const char* what() const throw();
    };
    
};

std::ostream& operator<<(std::ostream& os, AForm const& Aform);

#endif