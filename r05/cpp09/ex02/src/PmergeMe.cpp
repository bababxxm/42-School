/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:53:46 by sklaokli          #+#    #+#             */
/*   Updated: 2026/06/12 15:17:51 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe& other)
    : _vector(other._vector), _deque(other._deque) {}

PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

PmergeMe::~PmergeMe() {}

const char* PmergeMe::InvalidInputException::what() const throw() {
	return "Error";
}

void PmergeMe::parseArguments(int argc, char** argv) {
	for (int i = 1; i < argc; ++i) {
		std::string token(argv[i]);

		if (!isPositiveInteger(token)) {
			throw PmergeMe::InvalidInputException();
		}

		char* endPtr;
		long val = std::strtol(token.c_str(), &endPtr, 10);

		if (*endPtr != '\0' || val > 2147483647 || val < 0) {
			throw PmergeMe::InvalidInputException();
		}

		_vector.push_back(static_cast<int>(val));
		_deque.push_back(static_cast<int>(val));
	}
}

void PmergeMe::execute() {
	if (_vector.size() < 2) {
		std::cout << "Before: ";
		print();
		std::cout << "After:  ";
		print();
		std::cout << "Time to process a range of " << _vector.size()
		          << " elements with std::vector : 0 us" << std::endl;
		std::cout << "Time to process a range of " << _deque.size()
		          << " elements with std::deque  : 0 us" << std::endl;
		return;
	}

	std::cout << "Before: ";
	print();

	std::clock_t startVec = std::clock();
	fordJohnsonSort(_vector.begin(), _vector.end());
	std::clock_t endVec = std::clock();

	std::clock_t startDeq = std::clock();
	fordJohnsonSort(_deque.begin(), _deque.end());
	std::clock_t endDeq = std::clock();

	std::cout << "After:  ";
	std::vector<int>::const_iterator v_it;
	for (v_it = _vector.begin(); v_it != _vector.end(); ++v_it) {
		std::cout << *v_it << " ";
	}
	std::cout << std::endl;

	double timeVec =
	    static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
	double timeDeq =
	    static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process a range of " << _vector.size()
	          << " elements with std::vector : " << timeVec << " us"
	          << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
	          << " elements with std::deque  : " << timeDeq << " us"
	          << std::endl;
}

void PmergeMe::print() {
	std::vector<int>::const_iterator v_it;
	for (v_it = _vector.begin(); v_it != _vector.end(); ++v_it) {
		std::cout << *v_it << " ";
	}
	std::cout << std::endl;
}

bool PmergeMe::isPositiveInteger(const std::string& str) {
	if (str.empty()) return false;
	std::string::size_type i = 0;
	if (str[0] == '+') i++;
	if (i == str.size()) return false;
	for (; i < str.size(); ++i) {
		if (!std::isdigit(str[i])) return false;
	}
	return true;
}
