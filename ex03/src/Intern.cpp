/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 17:27:28 by francesca         #+#    #+#             */
/*   Updated: 2026/02/11 18:22:56 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
}

Intern::Intern(const Intern &other) {
    (void)other;
}

Intern& Intern::operator=(const Intern &other) {
    (void)other;
    return(*this);
}

Intern::~Intern(){
}

const char* Intern::UnknownFormException::what() const throw() {
    return("The provided form name does not exist. Creation Failed.");
}

std::string Intern::toLower(std::string str) {
    for (std::string::size_type i = 0; i < str.size(); ++i)
    {
        str[i] = static_cast<char>(std::tolower(static_cast<unsigned char>(str[i])));
    }
    return (str);
}

AForm* Intern::PresidentialPardon(const std::string& target) const {
    return(new PresidentialPardonForm(target));
}

AForm* Intern::RobotomyRequest(const std::string& target) const {
    return(new RobotomyRequestForm(target));
}

AForm* Intern::ShrubberyCreation(const std::string& target) const {
    return(new ShrubberyCreationForm(target));
}

AForm* Intern::makeForm(std::string nameForm, std::string targetForm) 
{
    typedef AForm* (Intern::*CreateMemFn)(const std::string&) const;

    const std::string key = toLower(nameForm);

    const std::string names[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
        };

    CreateMemFn fns[3] = {
        &Intern::ShrubberyCreation,
        &Intern::RobotomyRequest,
        &Intern::PresidentialPardon
    };
    
    for (int i = 0; i < 3; ++i) 
    {
        if (key == names[i]) {
            std::cout << "Intern creates " << names[i] << std::endl;
            return (this->*fns[i])(targetForm);
        }   
    }
    throw UnknownFormException();
}