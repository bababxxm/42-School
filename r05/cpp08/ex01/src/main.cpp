/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 16:06:59 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/28 16:59:53 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <vector>
#include "Span.hpp"

#define B_CYAN "\033[1;36m"
#define B_YELLOW "\033[1;33m"
#define B_GREEN "\033[1;32m"
#define B_RED "\033[1;31m"
#define DIM "\033[2m"
#define RESET "\033[0m"

void test_header(const std::string& title) {
	std::cout << std::endl
	          << B_CYAN << "[ " << title << " ]" << RESET << std::endl;
	std::cout << DIM << "----------------------------------------" << RESET
	          << std::endl;
}

void test_subject() {
	test_header("TEST 1: Subject Basic Requirements");
	try {
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << "Shortest Span: " << B_YELLOW << sp.shortestSpan() << RESET
		          << std::endl;
		std::cout << "Longest Span:  " << B_YELLOW << sp.longestSpan() << RESET
		          << std::endl;
	} catch (const std::exception& e) {
		std::cerr << B_RED << "Error: " << e.what() << RESET << std::endl;
	}
}

void test_exceptions() {
	test_header("TEST 2: Exception Handling (Capacity)");
	Span sp(2);
	try {
		sp.addNumber(1);
		sp.addNumber(2);
		std::cout << "Attempting to add 3rd number to Span(2)..." << std::endl;
		sp.addNumber(3);
	} catch (const std::exception& e) {
		std::cout << B_GREEN << "Caught expected error: " << RESET << e.what()
		          << std::endl;
	}

	test_header("TEST 3: Exception Handling (Small Span)");
	Span empty(10);
	try {
		empty.addNumber(42);
		std::cout << "Calculating span for only 1 number..." << std::endl;
		empty.shortestSpan();
	} catch (const std::exception& e) {
		std::cout << B_GREEN << "Caught expected error: " << RESET << e.what()
		          << std::endl;
	}
}

void test_big_range() {
	test_header("TEST 4: 10,000 Numbers (Range add)");
	try {
		Span sp(10001);
		std::vector<int> v;
		for (int i = 0; i < 10000; ++i) v.push_back(i * 3);  // 0, 3, 6, 9...

		sp.addnumber(v.begin(), v.end());
		sp.addNumber(2);  // Should make shortest span 1 (between 2 and 3)

		std::cout << "Shortest Span: " << B_YELLOW << sp.shortestSpan() << RESET
		          << " (Expected: 1)" << std::endl;
		std::cout << "Longest Span:  " << B_YELLOW << sp.longestSpan() << RESET
		          << " (Expected: 29997)" << std::endl;
	} catch (const std::exception& e) {
		std::cerr << B_RED << "Error: " << e.what() << RESET << std::endl;
	}
}

int main() {
	test_subject();
	test_exceptions();
	test_big_range();

	std::cout << std::endl
	          << B_GREEN << "--- All tests completed ---\n"
	          << RESET << std::endl;
	return 0;
}
