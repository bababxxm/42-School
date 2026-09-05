/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:31:33 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/24 22:32:17 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain( const Brain& other ) {
	std::cout << "Brain copy constructor called" << std::endl;
	for ( int i = 0; i < 100; i++ ) {
		_ideas[i] = other._ideas[i];
	}
}

Brain::~Brain( void ) {
	std::cout << "Brain destructor called" << std::endl;
}

Brain& Brain::operator=( const Brain& other ) {
	std::cout << "Brain copy assignment operator called" << std::endl;
	if ( this != &other ) {
		for ( int i = 0; i < 100; i++ ) {
			_ideas[i] = other._ideas[i];
		}
	}
	return ( *this );
}

bool	Brain::isValidIndex( int index ) const {
	return ( index >= 0 && index <= 99 );
}

void	Brain::setIdea( int index, const std::string& idea ) {
	if ( !isValidIndex( index ) ) {
		std::cerr << "Invalid index" << std::endl;
		return ;
	}
	_ideas[index] = idea;
}

std::string	Brain::getIdea( int index ) const {
	if ( !isValidIndex( index ) ) {
		return ( "" );
	}
	return ( _ideas[index] );
}
