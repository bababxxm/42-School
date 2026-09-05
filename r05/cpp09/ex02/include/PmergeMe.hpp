/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 16:52:42 by sklaokli          #+#    #+#             */
/*   Updated: 2026/06/12 15:18:08 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <deque>
#include <exception>
#include <iostream>
#include <string>
#include <vector>

class PmergeMe {
public:
	PmergeMe();
	PmergeMe(const PmergeMe&);
	PmergeMe& operator=(const PmergeMe&);
	~PmergeMe();

	class InvalidInputException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	void parseArguments(int, char**);
	void execute();
	void print();

private:
	static bool isPositiveInteger(const std::string&);

	template <typename Iterator>
	static void fordJohnsonSort(Iterator, Iterator);

	std::vector<int> _vector;
	std::deque<int> _deque;
};

#include "PmergeMe.tpp"

#endif
