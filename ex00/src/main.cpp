/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:54:36 by francesca         #+#    #+#             */
/*   Updated: 2026/02/09 18:26:31 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include <string>
#include <exception>

int main(){
    
    try {
        Bureaucrat a("Anna", 1);
        std::cout << MAGENTA << a << std::endl;
        std::cout << "Eseguo a.incrementGrade()" << std::endl;
        a.incrementGrade(); // qui lancerà GradeTooHighException
        std::cout << "Non arrivo qui" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Eccezione catturata: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "Programma continua qui." << std::endl;

    try {
        Bureaucrat a("Anna2", 1);
        std::cout << a << std::endl;
        std::cout << GREEN << "Ora eseguo decremento:" << std::endl;
        a.decrementGrade();
        std::cout << a << RESET << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Eccezione catturata: " << e.what() << std::endl;
    }

    std::cout << BLUE << "Programma continua qui..." << std::endl;
    try {
        std::cout << BLUE << "Creazione di Alfa:" << std::endl;
        Bureaucrat alfa("Alfa", 150);
        std::cout << alfa << std::endl;
        std::cout << "Decremento ancora il grade:" << std::endl;
        alfa.decrementGrade(); // qui lancerà GradeTooHighException
        std::cout << "Non arrivo qui" << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Eccezione catturata: " << e.what() << RESET << std::endl;
    }

    std::cout << RED << "------ NUOVO OGGETTO DELTA:" << RESET << std::endl;
    
    Bureaucrat *d = new Bureaucrat("Delta", 1);
    std::cout << RED << *d << std::endl;
    try {
        d->incrementGrade();
    }
    catch (std::exception &e) {
        std::cout << "Eccezione catturata: " << e.what() << RESET << std::endl;
    }
    std::cout << ORANGE << *d << std::endl;
    try {
        d->decrementGrade();
    }
    catch (std::exception &e) {
        std::cout << "Eccezione catturata: " << e.what() << RESET << std::endl;
    }
    std::cout << ORANGE << *d << RESET << std::endl;
    
    d->decrementGrade();
    std::cout << ORANGE << *d << RESET << std::endl;
    delete d;

    
}
