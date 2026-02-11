/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: francesca <francesca@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 17:54:36 by francesca         #+#    #+#             */
/*   Updated: 2026/02/09 21:03:21 by francesca        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Debug.hpp"
#include "Bureaucrat.hpp"
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << "=== Costruzione Form con gradi invalidi ===\n";
    try {
        Form bad("BadForm", 0, 10); // sign grade troppo alto (0)
        std::cout << bad << "\n";
    } catch (std::exception &e) {
        std::cout << "Caught: " << e.what() << "\n";
    }

    std::cout << "\n=== Bureaucrat prova a firmare (fallisce) ===\n";
    try {
        Bureaucrat low("Low", 150);
        Form f("TaxForm", 50, 20);

        std::cout << low << "\n";
        std::cout << f << "\n";

        low.signForm(f); // dovrebbe fallire (150 > 50)
        std::cout << f << "\n";
    } catch (std::exception &e) {
        std::cout << "Unexpected catch: " << e.what() << "\n";
    }

    std::cout << "\n=== Bureaucrat prova a firmare (riesce) ===\n";
    try {
        Bureaucrat high("High", 10);
        Form f2("Permit", 50, 20);

        std::cout << high << "\n";
        std::cout << f2 << "\n";

        high.signForm(f2); // dovrebbe riuscire (10 <= 50)
        std::cout << f2 << "\n";
    } catch (std::exception &e) {
        std::cout << "Unexpected catch: " << e.what() << "\n";
    }

    std::cout << "\n=== Fine test ===\n";
    return 0;
}
