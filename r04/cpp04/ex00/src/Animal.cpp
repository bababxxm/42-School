/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:55:21 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 14:57:35 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal( void ) : _type( "Animal" ) {
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal( const std::string& type ) : _type( type ) {
	std::cout << "Animal parametized constructor called" << std::endl;
}

Animal::Animal( const Animal& other ) : _type( other._type ) {
	std::cout << "Animal copy constructor called" << std::endl;
}

Animal::~Animal( void ) {
	std::cout << "Animal destructor called" << std::endl;
}

Animal&	Animal::operator=( const Animal& other ) {
	std::cout << "Animal assignment operator called" << std::endl;
	if ( this != &other ) {
		_type = other._type;
	}
	return ( *this );
}

void	Animal::makeSound( void ) const {
	std::cout << "* Generic Animal Sound *" << std::endl;
}

std::string	Animal::getType( void ) const {
	return ( _type );
}
