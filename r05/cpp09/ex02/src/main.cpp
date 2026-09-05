/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:09:50 by sklaokli          #+#    #+#             */
/*   Updated: 2026/06/08 17:03:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <deque>
#include <iostream>
#include <vector>

int main(int argc, char** argv) {
	if (argc < 2) {
		std::cerr << "Usage: ./PmergeMe [n1] [n2] ..." << std::endl;
		std::cerr << "Usage: ./PmergeMe $(shuf -i 1-100000 -n 3000 | tr "
		             "\"\\n\" \" \")"
		          << std::endl;
		std::cerr << "Note: Only positive integers allowed" << std::endl;
		return 1;
	}

	try {
		PmergeMe PM;
		PM.parseArguments(argc, argv);
		PM.execute();
	} catch (const std::exception& e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
