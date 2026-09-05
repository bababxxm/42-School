/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:55:05 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 13:30:35 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat( void ) : Animal( "Cat" ) {
	std::cout << "Cat default constructor called" << std::endl;
}

Cat::Cat( const Cat& other ) : Animal( other ) {
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat::~Cat( void ) {
	std::cout << "Cat destructor called" << std::endl;
}

Cat&	Cat::operator=( const Cat& other ) {
	std::cout << "Cat assignment operator called" << std::endl;
	if ( this != &other ) {
		Animal::operator=( other );
	}
	return ( *this );
}

void	Cat::makeSound( void ) const {
	std::cout << "Meow Meow!" << std::endl;
}
