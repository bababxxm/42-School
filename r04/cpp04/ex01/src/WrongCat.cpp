/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:56:33 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/10 17:47:36 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat( void ) : WrongAnimal() {
	std::cout << "WrongCat default constructor called" << std::endl;
	_type = "WrongCat";
}

WrongCat::WrongCat( const WrongCat& other ) : WrongAnimal( other ) {
	std::cout << "WrongCat copy constructor called" << std::endl;
}

WrongCat::~WrongCat( void ) {
	std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat&	WrongCat::operator=( const WrongCat& other ) {
	std::cout << "WrongCat assignment operator called" << std::endl;
	if ( this != &other ) {
		WrongAnimal::operator=( other );
	}
	return ( *this );
}

void	WrongCat::makeSound( void ) const {
	std::cout << "Meow Meow! (WrongCat Sound)" << std::endl;
}
