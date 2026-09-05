/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 01:56:45 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/28 20:04:36 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <vector>
#include "MutantStack.hpp"

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

void test_subject_basic() {
	test_header("TEST 1: Subject Main Requirements");
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Top element: " << B_YELLOW << mstack.top() << RESET
	          << " (Expected: 17)" << std::endl;

	mstack.pop();
	std::cout << "Size after pop: " << B_YELLOW << mstack.size() << RESET
	          << " (Expected: 1)" << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	std::cout << "Stack contents (Iterator): ";
	while (it != ite) {
		std::cout << *it << " ";
		++it;
	}
	std::cout << std::endl;

	// Test conversion/copy to base class
	std::stack<int> s(mstack);
	std::cout << B_GREEN << "SUCCESS: Assigned MutantStack to std::stack"
	          << RESET << std::endl;
}

void test_complex_types() {
	test_header("TEST 2: String Stack & Const Iterators");
	MutantStack<std::string> sstack;

	sstack.push("World");
	sstack.push("Hello");
	sstack.push("Mutant");

	const MutantStack<std::string> const_stack(sstack);

	std::cout << "Const iteration: ";
	for (MutantStack<std::string>::const_iterator cit = const_stack.begin();
	     cit != const_stack.end(); ++cit) {
		std::cout << B_YELLOW << *cit << RESET << " ";
	}
	std::cout << std::endl;
}

void test_comparison_list() {
	test_header("TEST 3: Comparison with std::list");

	MutantStack<int> mstack;
	std::list<int> mlist;

	// Push same data to both
	int values[] = {42, 100, -5, 2024};
	for (int i = 0; i < 4; ++i) {
		mstack.push(values[i]);
		mlist.push_back(values[i]);
	}

	MutantStack<int>::iterator sit = mstack.begin();
	std::list<int>::iterator lit = mlist.begin();

	bool integrity = true;
	while (sit != mstack.end() && lit != mlist.end()) {
		if (*sit != *lit) {
			integrity = false;
			break;
		}
		++sit;
		++lit;
	}

	if (integrity && mstack.size() == mlist.size()) {
		std::cout << B_GREEN << "SUCCESS: MutantStack matches std::list output!"
		          << RESET << std::endl;
	} else {
		std::cout << B_RED << "FAILURE: Data mismatch between containers."
		          << RESET << std::endl;
	}
}

int main() {
	test_subject_basic();
	test_complex_types();
	test_comparison_list();

	std::cout << std::endl
	          << B_GREEN << "--- All tests completed ---\n"
	          << RESET << std::endl;
	return 0;
}
