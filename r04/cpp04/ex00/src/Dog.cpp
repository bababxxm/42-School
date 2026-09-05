/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:55:14 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 13:30:33 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal( "Dog" ) {
	std::cout << "Dog default constructor called" << std::endl;
}

Dog::Dog( const Dog& other ) : Animal( other ) {
	std::cout << "Dog copy constructor called" << std::endl;
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
}

Dog&	Dog::operator=( const Dog& other ) {
	std::cout << "Dog assignment operator called" << std::endl;
	if ( this != &other ) {
		Animal::operator=( other );
	}
	return ( *this );
}

void	Dog::makeSound( void ) const {
	std::cout << "Woof Woof!" << std::endl;
}
