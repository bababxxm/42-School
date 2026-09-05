/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 20:36:15 by sklaokli          #+#    #+#             */
/*   Updated: 2026/01/22 20:39:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

void    test_header(std::string title) {
    std::cout << "\033[1;36m[ " << title << " ]\033[0m" << std::endl;
}

int main()
{
    test_header("TEST 1: Standard Construction");
    try {
        Bureaucrat bob("Bob", 2);
        std::cout << bob << std::endl;
    } catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    test_header("TEST 2: Grade Too High Construction (0)");
    try {
        Bureaucrat alice("Alice", 0);
        std::cout << alice << std::endl;
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 3: Grade Too Low Construction (151)");
    try {
        Bureaucrat jim("Jim", 151);
        std::cout << jim << std::endl;
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 4: Incrementing Grade 1 (Exception expected)");
    try {
        Bureaucrat boss("Boss", 1);
        std::cout << "Before: " << boss << std::endl;
        boss.incrementGrade();
        std::cout << "After: " << boss << std::endl;
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    test_header("TEST 5: Decrementing Grade 150 (Exception expected)");
    try {
        Bureaucrat intern("Intern", 150);
        std::cout << "Before: " << intern << std::endl;
        intern.decrementGrade();
        std::cout << "After: " << intern << std::endl;
    } catch (std::exception &e) {
        std::cout << "\033[1;31mException caught: " << e.what() << "\033[0m" << std::endl;
    }

    return 0;
}
