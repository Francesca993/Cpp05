/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:54:36 by francesca         #+#    #+#             */
/*   Updated: 2026/02/11 16:34:43 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    ShrubberyCreationForm shrub("Home");
    PresidentialPardonForm  pardon("Ford Prefect");
    RobotomyRequestForm robo("Bender");
    
    Bureaucrat alfa("Alice", 1);
    Bureaucrat beta("Bob", 150);
    Bureaucrat delta("Charlie", 50);

    std::cout << MAGENTA << "--- Bureaucrat ---" << std::endl;
    std::cout << alfa << std::endl;
    std::cout << beta << std::endl;
    std::cout << delta << RESET << std::endl;
    
    std::cout << ORANGE << "--- Form: ---" << std::endl;
    std::cout << shrub << std::endl;
    std::cout << pardon << std::endl;
    std::cout << robo << RESET << std::endl;

    std::cout << BLUE << "---Starting sign Form---" << RESET << std::endl;
    try
    {
        beta.signAForm(shrub);
        beta.signAForm(robo);
        beta.signAForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        alfa.signAForm(shrub);
        alfa.signAForm(robo);
        alfa.signAForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    try
    {
        delta.signAForm(shrub);
        delta.signAForm(robo);
        delta.signAForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << BLUE << "---Starting execute Form Shrubbery ----" << RESET << std::endl;
    
    try
    {
        alfa.executeAForm(shrub);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        beta.executeAForm(shrub);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        delta.executeAForm(shrub);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << BLUE << "---Starting execute Form Robotomy ----" << RESET << std::endl;


    try
    {
        alfa.executeAForm(robo);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        beta.executeAForm(robo);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        delta.executeAForm(robo);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << BLUE << "---Starting execute Form Pardon ----" << RESET << std::endl;
    
    try
    {
        alfa.executeAForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        beta.executeAForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        delta.executeAForm(pardon);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    std::cout << BLUE << "--- Finish Tests----" << RESET << std::endl;
    std::cout << ORANGE << "--- Form: ---" << std::endl;
    std::cout << shrub << std::endl;
    std::cout << pardon << std::endl;
    std::cout << robo << RESET << std::endl;

    return (0);
    
}
