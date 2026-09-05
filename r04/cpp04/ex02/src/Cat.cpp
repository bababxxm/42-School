/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:55:05 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/10 17:48:07 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : AAnimal() {
	std::cout << "Cat default constructor called" << std::endl;
	_type = "Cat";
	_brain = new Brain();
}

Cat::Cat( const Cat& other ) : AAnimal( other ) {
	std::cout << "Cat copy constructor called" << std::endl;
	_brain = new Brain( *( other._brain ) );
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
	delete _brain;
}

Cat&	Cat::operator=( const Cat& other ) {
	std::cout << "Cat assignment operator called" << std::endl;
	if ( this != &other ) {
		AAnimal::operator=( other );
		if ( _brain ) {
			delete _brain;
		}
		_brain = new Brain( *( other._brain ) );
	}
	return ( *this );
}

Brain*	Cat::getBrain( void ) const {
	return ( _brain );
}

void	Cat::makeSound( void ) const {
	std::cout << "Meow Meow!" << std::endl;
}
