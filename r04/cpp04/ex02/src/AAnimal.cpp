/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:55:21 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/24 22:54:21 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal( void ) : _type( "AAnimal" ) {
	std::cout << "AAnimal default constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal& other ) : _type( other._type ) {
	std::cout << "AAnimal copy constructor called" << std::endl;
}

AAnimal::~AAnimal( void ) {
	std::cout << "AAnimal destructor called" << std::endl;
}

AAnimal&	AAnimal::operator=( const AAnimal& other ) {
	std::cout << "AAnimal assignment operator called" << std::endl;
	if ( this != &other ) {
		_type = other._type;
	}
	return ( *this );
}

std::string	AAnimal::getType( void ) const {
	return ( _type );
}
