/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:56:21 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/24 10:21:40 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) : _type( "WrongAnimal" ) {
	std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal& other ) : _type( other._type ) {
	std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void ) {
	std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=( const WrongAnimal& other ) {
	std::cout << "WrongAnimal assignment operator called" << std::endl;
	if ( this != &other ) {
		_type = other._type;
	}
	return ( *this );
}

void	WrongAnimal::makeSound( void ) const {
	std::cout << "* Generic WrongAnimal Sound *" << std::endl;
}

std::string	WrongAnimal::getType( void ) const {
	return ( _type );
}
