/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:41:30 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/10 17:44:22 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) : AMateria( "ice" ) {}

Ice::Ice( const Ice& other ) : AMateria( other._type ) {}

Ice&	Ice::operator=( const Ice& other ) {
	if ( this != &other ) {
		AMateria::operator=( other );
	}
	return ( *this );
}

Ice::~Ice( void ) {}

AMateria*	Ice::clone( void ) const {
	return ( new Ice( *this ) );
}

void	Ice::use( ICharacter& target ) {
	std::cout <<  "* heals" << target.getName() << "'s wounds *" << std::endl;
}
