/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:55:14 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/10 17:51:13 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog( void ) : Animal() {
	std::cout << "Dog default constructor called" << std::endl;
	_type = "Dog";
	_brain = new Brain();
}

Dog::Dog( const Dog& other ) : Animal( other ) {
	std::cout << "Dog copy constructor called" << std::endl;
	_brain = new Brain( *( other._brain ) );
}

Dog::~Dog( void ) {
	std::cout << "Dog destructor called" << std::endl;
	delete _brain;
}

Dog&	Dog::operator=( const Dog& other ) {
	std::cout << "Dog assignment operator called" << std::endl;
	if ( this != &other ) {
		Animal::operator=( other );
		if ( _brain ) {
			delete _brain;
		}
		_brain = new Brain( *( other._brain ) );
	}
	return ( *this );
}

Brain*	Dog::getBrain( void ) const {
	return ( _brain );
}

void	Dog::makeSound( void ) const {
	std::cout << "Meow Meow!" << std::endl;
}
