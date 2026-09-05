/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 01:10:18 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/16 17:53:39 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "PhoneBook.hpp"

bool	Prompt(std::string &Input)
{
	std::cout << ">>> ";
	if (!std::getline(std::cin, Input)) {
		return (false);
	}
	return (true);
}

int	main(void)
{
	std::string	Input;
	PhoneBook	PhoneBook;

	system("clear");
    std::cout << "Welcome to PhoneBook!\n" << std::endl;;
	for (;;) {

		if (!Prompt(Input)) {
			PhoneBook.Exit();
		}
		if (Input == "ADD") {
			PhoneBook.Add();
		}
		else if (Input == "SEARCH") {
			PhoneBook.Search();
		}
		else if (Input == "EXIT") {
			PhoneBook.Exit();
		}
		else {
			std::cout << "phonebook: command not found" << std::endl;
		}

	}
}
