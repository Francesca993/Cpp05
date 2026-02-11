/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 20:49:09 by francesca         #+#    #+#             */
/*   Updated: 2026/02/11 13:29:47 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "Debug.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>
#include <exception>

class AForm;

class Bureaucrat {
    private:
    const   std::string _name;
    int     _grade; // that ranges from 1 (highest possible grade) to 150 (lowest possible grade)

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
    void signAForm(AForm& _Aform);
    void executeAForm(AForm const& Aform) const;
    
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

#endif