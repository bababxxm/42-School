/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:14:10 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/24 23:20:16 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) : _type( "Default" ) {}

AMateria::AMateria( const std::string& type ) : _type( type ) {}

AMateria::AMateria( const AMateria& other ) : _type( other._type ) {}

AMateria&	AMateria::operator=( const AMateria& other ) {
	if ( this != &other ) {
		_type = other._type;
	}
	return ( *this );
}

void	AMateria::setType( const std::string& type ) {
	_type = type;
}

const std::string&	AMateria::getType( void ) const {
	return ( _type );
}

