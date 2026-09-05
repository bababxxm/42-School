/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:00:56 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/27 22:40:37 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include "easyfind.hpp"

int main() {
	std::srand(static_cast<unsigned int>(std::time(NULL)));

	std::vector<int> v;
	std::deque<int> d;
	std::list<int> l;

	int amount = 10;

	for (unsigned int i = 0; i < 10; ++i) {
		int val = std::rand() % amount;
		v.push_back(val);
		d.push_back(val);
		l.push_back(val);
	}

	printContainer("Vector", v);
	printContainer("Deque ", d);
	printContainer("List  ", l);

	int target = std::rand() % amount;
	std::cout << "\nSearching for: " << target << std::endl;

	try {
		std::vector<int>::const_iterator it = ::easyfind(v, target);
		std::cout << "Vector: Found " << *it << "!" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Vector: " << e.what() << std::endl;
	}

	try {
		std::deque<int>::const_iterator it = ::easyfind(d, target);
		std::cout << "Deque:  Found " << *it << "!" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "Deque:  " << e.what() << std::endl;
	}

	try {
		std::list<int>::const_iterator it = ::easyfind(l, target);
		std::cout << "List:   Found " << *it << "!" << std::endl;
	} catch (const std::exception& e) {
		std::cout << "List:   " << e.what() << std::endl;
	}

	return 0;
}
