/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:20:33 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 23:19:55 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap( void ):
	_name( "Default" ),
	_hitPoints( 10 ),
	_energyPoints( 10 ),
	_attackDamage( 0 ) {
	std::cout << "ClapTrap " << _name << " has been created." << std::endl;
}

ClapTrap::ClapTrap( const std::string& name ) :
	_name( name ),
	_hitPoints( 10 ),
	_energyPoints( 10 ),
	_attackDamage( 0 ) {
	std::cout << "ClapTrap " << _name << " has been created." << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap& other ) :
	_name( other._name ),
	_hitPoints( other._hitPoints ),
	_energyPoints( other._energyPoints ),
	_attackDamage( other._attackDamage ) {
	std::cout << "ClapTrap " << _name << " has been copied." << std::endl;
}

ClapTrap::~ClapTrap( void ) {
	std::cout << "ClapTrap " << _name << " has been destroyed." << std::endl;
}

ClapTrap&	ClapTrap::operator=( const ClapTrap& other ) {
	if ( this != &other ) {
		_name = other._name;
		_hitPoints = other._hitPoints;
		_energyPoints = other._energyPoints;
		_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap " << _name << " has been assigned." << std::endl;
	return ( *this );
}

std::string	ClapTrap::getName( void ) const {
	return ( _name );
}

void	ClapTrap::attack( const std::string& target ) {
	if ( _energyPoints == 0 || _hitPoints == 0 ) {
		std::cout << "ClapTrap " << _name << " cannot attack." << std::endl;
		return ;
	}
	_energyPoints--;
	std::cout << "ClapTrap " << _name << " attacks " << target
		<< ", causing " << _attackDamage << " points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ) {
	if ( _hitPoints <= amount ) {
		_hitPoints = 0;
		std::cout << "ClapTrap " << _name << " takes " << amount
			<< " points of damage and is now destroyed!" << std::endl;
		return ;
	}
	_hitPoints -= amount;
	std::cout << "ClapTrap " << _name << " takes " << amount
		<< " points of damage! Remaining hit points: " << _hitPoints << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ) {
	if ( _energyPoints == 0 || _hitPoints == 0 ) {
		std::cout << "ClapTrap " << _name
			<< " has no energy points or hit points left to repair." << std::endl;
		return ;
	}
	_energyPoints--;
	_hitPoints += amount;
	std::cout << "ClapTrap " << _name << " is repaired by " << amount
		<< " points! Current hit points: " << _hitPoints << std::endl;
}

void	ClapTrap::displayStatus( void ) const {
	std::cout << "=== ClapTrap Status ===" << std::endl;
	std::cout << "Name: " << _name << std::endl;
	std::cout << "Hit Points: " << _hitPoints << std::endl;
	std::cout << "Energy Points: " << _energyPoints << std::endl;
	std::cout << "Attack Damage: " << _attackDamage << std::endl;
	std::cout << "=======================" << std::endl;
}
