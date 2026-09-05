/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:52:06 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 15:49:20 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) : ICharacter() {
	_name = "Default";
	for ( int i = 0; i < 4; i++ ) {
		_inventory[i] = NULL;
		_trash[i] = false;
	}
}

Character::Character( const std::string& name ) : ICharacter() {
	_name = name;
	for ( int i = 0; i < 4; i++ ) {
		_inventory[i] = NULL;
		_trash[i] = false;
	}
}

Character::Character( const Character& other ) {
	_name = other._name;
	for ( int i = 0; i < 4; i++ ) {
		if ( other._inventory[i] != NULL ) {
			_inventory[i] = other._inventory[i]->clone();
		} else {
			_inventory[i] = NULL;
		}
		_trash[i] = other._trash[i];
	}
}

Character&	Character::operator=( const Character& other ) {
	if ( this != &other ) {
		_name = other.getName();
		clearInventory();
		for ( int i = 0; i < 4; i++ ) {
			if ( other._inventory[i] != NULL ) {
				_inventory[i] = other._inventory[i]->clone();
			} else {
				_inventory[i] = NULL;
			}
			_trash[i] = other._trash[i];
		}
	}
	return ( *this );
}

Character::~Character( void ) {
	clearTrash();
	clearInventory();
}

void	Character::setName( const std::string& name ) {
	_name = name;
}

const std::string&	Character::getName( void ) const {
	return ( _name );
}

void	Character::equip( AMateria* m ) {
	if ( m == NULL ) {
		return ;
	}
	clearTrash();
	for ( int i = 0; i < 4; i++ ) {
		if ( _inventory[i] == NULL ) {
			_inventory[i] = m;
			return ;
		}
	}
	delete m;
	std::cout << "Inventory full. Cannot equip another materia." << std::endl;
}

void	Character::unequip( int idx ) {
	if ( !isValidIndex( idx ) || _inventory[idx] == NULL ) {
		std::cout << "Invalid index " << idx << " for unequip operation." << std::endl;
	} else if ( _trash[idx] == true ) {
		std::cout << "Materia at index " << idx << " already marked for deletion." << std::endl;
	} else {
		_trash[idx] = true; 
		std::cout << "Materia at index " << idx << " marked for deletion." << std::endl;
	}
}

void	Character::use( int idx, ICharacter& target ) {
	if ( _inventory[idx] != NULL && _trash[idx] == false ) {
		_inventory[idx]->use( target );
	} else {
		std::cout << "No materia equipped at index " << idx << " to use." << std::endl;
	}
}

bool	Character::isValidIndex( int idx ) const {
	return ( idx >= 0 && idx <= 3 );
}

void	Character::clearTrash( void ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( _trash[i] == true ) {
			delete _inventory[i];
			_inventory[i] = NULL;
			_trash[i] = false;
		}
	}
}

void	Character::clearInventory( void ) {
	for ( int i = 0; i < 4; i++ ) {
		if ( _inventory[i] != NULL ) {
			delete _inventory[i];
			_inventory[i] = NULL;
		}
	}
}
