/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 02:58:13 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/10 17:40:22 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {
	for ( int i = 0; i < 4; i++ ) {
		_learned[i] = NULL;
	}
}

MateriaSource::MateriaSource( const MateriaSource& other ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( other._learned[i] != NULL ) {
			_learned[i] = other._learned[i];
		} else {
			_learned[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource( void ) {
	clearMateria();
}

void	MateriaSource::clearMateria( void ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( _learned[i] != NULL ) {
			delete _learned[i];
			_learned[i] = NULL;
		}
	}
}

MateriaSource&	MateriaSource::operator=( const MateriaSource& other ) {
	if (this != &other) {
		clearMateria();
		for ( int i = 0; i < 4; i++ ) {
			if ( other._learned[i] != NULL ) {
				_learned[i] = other._learned[i];
			} else {
				_learned[i] = NULL;
			}
		}
	}
	return ( *this );
}

void	MateriaSource::learnMateria( AMateria* m ) {
	if ( m == NULL ) {
		return ;
	}
	for ( int i = 0; i < 4; i++ ) {
		if ( _learned[i] == NULL ) {
			_learned[i] = m;
			return ;
		}
	}
	delete m;
	std::cout << "MateriaSource cannot learn more materia; capacity full." << std::endl;
}

AMateria*	MateriaSource::createMateria( const std::string& type ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( _learned[i] != NULL && _learned[i]->getType() == type ) {
			return ( _learned[i]->clone() );
		}
	}
	std::cout << "MateriaSource could not find materia of type: " << type << std::endl;
	return ( NULL );
}


