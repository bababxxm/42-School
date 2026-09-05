/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:43:33 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/22 21:14:46 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "AForm.hpp"
#include <iostream>

void    test_header(std::string title) {
    std::cout << "\033[1;36m[ " << title << " ]\033[0m" << std::endl;
}

int main()
{
    Intern      someRandomIntern;
    Bureaucrat  boss("Boss", 1);
    AForm* rrf;

    test_header("TEST 1: Intern makes Robotomy Request");
    try {
        rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        if (rrf) {
            std::cout << *rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 2: Intern makes Shrubbery Creation");
    try {
        rrf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        if (rrf) {
            std::cout << *rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 3: Intern makes Presidential Pardon");
    try {
        rrf = someRandomIntern.makeForm("presidential pardon", "Criminal");
        if (rrf) {
            std::cout << *rrf << std::endl;
            boss.signForm(*rrf);
            boss.executeForm(*rrf);
            delete rrf;
        }
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 4: Intern makes Unknown Form (Should Fail)");
    try {
        rrf = someRandomIntern.makeForm("coffee request", "Boss");
        if (rrf) {
            std::cout << *rrf << std::endl;
            delete rrf;
        } else {
            std::cout << "Form was not created (Pointer is NULL)" << std::endl;
        }
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}
