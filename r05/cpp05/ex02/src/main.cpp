/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:43:16 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/22 21:13:34 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

void    test_header(std::string title) {
    std::cout << "\033[1;36m[ " << title << " ]\033[0m" << std::endl;
}

int main()
{
    Bureaucrat boss("Boss", 1);
    Bureaucrat intern("Intern", 140);
    Bureaucrat middle("MiddleManager", 40);

    test_header("TEST 1: Shrubbery Creation (Req: Sign 145, Exec 137)");
    try {
        ShrubberyCreationForm shrub("Backyard");
        
        // Intern signs (140 > 145) -> OK
        intern.signForm(shrub);
        
        // Intern executes (140 < 137) -> FAIL
        std::cout << "Intern attempts to execute:" << std::endl;
        intern.executeForm(shrub);

        // Boss executes -> OK
        std::cout << "Boss attempts to execute:" << std::endl;
        boss.executeForm(shrub);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 2: Robotomy Request (Req: Sign 72, Exec 45)");
    try {
        RobotomyRequestForm robot("Bender");
        
        // Middle manager signs (40 > 72) -> OK
        middle.signForm(robot);
        
        std::cout << "--- Running 50% success rate test (4 attempts) ---" << std::endl;
        // Boss executes multiple times to check randomness
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
        boss.executeForm(robot);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 3: Presidential Pardon (Req: Sign 25, Exec 5)");
    try {
        PresidentialPardonForm pardon("Arthur Dent");
        
        // Middle manager signs (40 < 25) -> FAIL
        std::cout << "Middle Manager attempts to sign:" << std::endl;
        middle.signForm(pardon);

        // Boss signs -> OK
        boss.signForm(pardon);
        
        // Boss executes -> OK
        boss.executeForm(pardon);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 4: Execute Unsigned Form");
    try {
        ShrubberyCreationForm unsignedShrub("Park");
        // Try to execute without signing
        boss.executeForm(unsignedShrub);
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}
