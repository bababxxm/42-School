/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:41:29 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/22 21:03:35 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

void    test_header(std::string title) {
    std::cout << "\033[1;36m[ " << title << " ]\033[0m" << std::endl;
}

int main()
{
    test_header("TEST 1: Standard Form Construction");
    try {
        Form tax("TaxForm", 50, 100);
        std::cout << tax << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    test_header("TEST 2: Form Grade Too High Construction (0)");
    try {
        Form impossible("Impossible", 0, 50);
        std::cout << impossible << std::endl;
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 3: Form Grade Too Low Construction (151)");
    try {
        Form lazy("LazyForm", 151, 50);
        std::cout << lazy << std::endl;
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 4: Signing - Grade Too Low");
    try {
        Bureaucrat  newbie("Newbie", 150);
        Form        contract("Contract", 100, 100);

        std::cout << newbie << std::endl;
        std::cout << contract << std::endl;
        
        newbie.signForm(contract);
        std::cout << contract << std::endl;
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 5: Signing - Success");
    try {
        Bureaucrat  boss("Boss", 1);
        Form        decree("Royal Decree", 10, 10);

        std::cout << boss << std::endl;
        std::cout << decree << std::endl;

        boss.signForm(decree);
        std::cout << decree << std::endl;
        
        std::cout << "Attempting to sign again..." << std::endl;
        boss.signForm(decree); 
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}
