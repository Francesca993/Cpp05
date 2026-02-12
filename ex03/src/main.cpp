/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:54:36 by francesca         #+#    #+#             */
/*   Updated: 2026/02/12 10:41:37 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "Intern.hpp"


int main()
{
    // Seed per Robotomy (se usi rand() dentro execute)
    std::srand(std::time(NULL));

    try {
        Intern  someRandomIntern;

        Bureaucrat boss("Alice", 1);      // può firmare/eseguire tutto
        Bureaucrat mid("Bob", 70);        // utile per far fallire qualcosa
        Bureaucrat low("Charlie", 150);   // fallisce spesso

        // 1) Creazione corretta
        AForm* shrub = someRandomIntern.makeForm("shrubbery creation", "garden");
        AForm* robo  = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm* pardon= someRandomIntern.makeForm("presidential pardon", "Ford Prefect");

        std::cout << "\n--- SIGN + EXECUTE (con boss) ---\n";
        boss.signAForm(*shrub);
        boss.executeAForm(*shrub);

        boss.signAForm(*robo);
        boss.executeAForm(*robo);

        boss.signAForm(*pardon);
        boss.executeAForm(*pardon);

        std::cout << "\n--- TEST errori grade (con low) ---\n";
        try {
            low.signAForm(*robo);          // dovrebbe fallire
        } catch (const std::exception& e) {
            std::cout << "Expected error (low sign): " << e.what() << "\n";
        }

        try {
            mid.executeAForm(*pardon);     // dovrebbe fallire se pardon richiede grade alta
        } catch (const std::exception& e) {
            std::cout << "Expected error (mid exec): " << e.what() << "\n";
        }

        // 2) Nome form sconosciuto
        std::cout << "\n--- TEST form sconosciuto ---\n";
        try {
            AForm* unknown = someRandomIntern.makeForm("tax evasion", "someone");
            delete unknown; // se la tua makeForm ritorna NULL, delete NULL è ok
        } catch (const std::exception& e) {
            std::cout << "Expected error (unknown form): " << e.what() << "\n";
        }

        delete shrub;
        delete robo;
        delete pardon;
    }
    catch (const std::exception& e) {
        std::cout << "Fatal error: " << e.what() << "\n";
    }

    return 0;
}



/*
int main()
{
    std::cout << "--- Bureaucrats ---" << std::endl;
    Bureaucrat alfa("Alice", 1);       // top
    Bureaucrat beta("Bob", 150);       // worst
    Bureaucrat delta("Charlie", 50);   // mid

    std::cout << alfa << std::endl;
    std::cout << beta << std::endl;
    std::cout << delta << std::endl;

    std::cout << "\n--- Intern creates forms ---" << std::endl;
    Intern someRandomIntern;

    AForm* shrub  = NULL;
    AForm* pardon = NULL;
    AForm* robo   = NULL;
    AForm* wrong  = NULL;

    // Creazione corretta
    try {
        shrub  = someRandomIntern.makeForm("shrubbery creation", "Home");
        pardon = someRandomIntern.makeForm("presidential pardon", "Ford Prefect");
        robo   = someRandomIntern.makeForm("robotomy request", "Bender");
    } catch (const std::exception& e) {
        std::cerr << "Create error: " << e.what() << std::endl;
    }

    // Nome sbagliato (deve fallire)
    try {
        wrong = someRandomIntern.makeForm("Impossible request", "Bender Wrong");
        // se la tua makeForm invece di throw ritorna NULL, non dereferenziare
        if (wrong)
            std::cout << *wrong << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Expected (unknown form): " << e.what() << std::endl;
    }

    std::cout << "\n--- Forms created ---" << std::endl;
    if (shrub)  std::cout << *shrub << std::endl;
    if (pardon) std::cout << *pardon << std::endl;
    if (robo)   std::cout << *robo << std::endl;

    std::cout << "\n--- Signing (Alice) ---" << std::endl;
    try {
        if (shrub)  alfa.signAForm(*shrub);
        if (robo)   alfa.signAForm(*robo);
        if (pardon) alfa.signAForm(*pardon);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Signing (Bob should fail) ---" << std::endl;
    try {
        if (shrub)  beta.signAForm(*shrub);
        if (robo)   beta.signAForm(*robo);
        if (pardon) beta.signAForm(*pardon);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Executing (Alice) ---" << std::endl;
    try {
        if (shrub)  alfa.executeAForm(*shrub);
        if (robo)   alfa.executeAForm(*robo);
        if (pardon) alfa.executeAForm(*pardon);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Executing (Charlie mid: some may fail) ---" << std::endl;
    try {
        if (shrub)  delta.executeAForm(*shrub);
        if (robo)   delta.executeAForm(*robo);
        if (pardon) delta.executeAForm(*pardon);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    std::cout << "\n--- Finish ---" << std::endl;

    delete shrub;
    delete pardon;
    delete robo;
    delete wrong; // ok anche se NULL

    return 0;
}
*/
