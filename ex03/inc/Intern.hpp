/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:07:12 by francesca         #+#    #+#             */
/*   Updated: 2026/02/11 18:09:02 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cctype>

class Intern {
    
    public:
    Intern();
    Intern(const Intern &other);
    Intern&operator=(const Intern &other);
    ~Intern();

    AForm* makeForm(std::string nameForm, std::string targetForm);

    static std::string toLower(std::string str);
    AForm* PresidentialPardon(const std::string& target) const;
    AForm* RobotomyRequest(const std::string& target) const;
    AForm* ShrubberyCreation(const std::string& target) const;
    
    class UnknownFormException : public std::exception {
    public:
        const char* what() const throw();
    };
};

#endif