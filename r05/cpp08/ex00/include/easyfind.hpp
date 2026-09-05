/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 14:08:37 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/27 21:56:16 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>

class NotFoundException : public std::exception {
public:
	virtual const char* what() const throw() {
		return "Element not found in container";
	}
};

template <typename T>
typename T::const_iterator easyfind(const T& container, int n) {
	typename T::const_iterator it =
	    std::find(container.begin(), container.end(), n);
	if (it == container.end()) throw NotFoundException();
	return it;
}

template <typename T>
void printContainer(const std::string& name, const T& container) {
	std::cout << name << ": [ ";
	for (typename T::const_iterator it = container.begin();
	     it != container.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "]" << std::endl;
}

#endif
