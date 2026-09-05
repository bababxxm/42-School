/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:44:54 by sklaokli          #+#    #+#             */
/*   Updated: 2026/04/09 20:20:59 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {}

Cure::Cure(const Cure& other) : AMateria(other._type) {}

Cure& Cure::operator=(const Cure& other) {
	if (this != &other) { AMateria::operator=(other); }
	return (*this);
}

Cure::~Cure(void) {}

AMateria* Cure::clone(void) const {
	return (new Cure(*this));
}

void Cure::use(ICharacter& target) {
	std::cout << "* heals" << target.getName() << "'s wounds *" << std::endl;
}
