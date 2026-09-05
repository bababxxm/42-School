/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:12:27 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 23:51:01 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap( void ) :
	ClapTrap( "Default_clap_name" ),
	ScavTrap( "Default_clap_name" ),
	FragTrap( "Default_clap_name" ),
	name( "Default" ) {
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << name << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap( const std::string& name ) :
	ClapTrap( name + "_clap_name" ),
	ScavTrap( name + "_clap_name" ),
	FragTrap( name + "_clap_name" ),
	name( name )
	{
	_hitPoints = FragTrap::_hitPoints;
	_energyPoints = ScavTrap::_energyPoints;
	_attackDamage = FragTrap::_attackDamage;
	std::cout << "DiamondTrap " << name << " has been created." << std::endl;
}

DiamondTrap::DiamondTrap( const DiamondTrap& other ) :
	ClapTrap( other ),
	ScavTrap( other ),
	FragTrap( other ),
	name( other.name ) {
	std::cout << "DiamondTrap " << name << " has been copied." << std::endl;
}

DiamondTrap::~DiamondTrap( void ) {
	std::cout << "DiamondTrap " << name << " has been destroyed." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=( const DiamondTrap& other ) {
	if ( this != &other ) {
		ScavTrap::operator=( other );
		FragTrap::operator=( other );
		name = other.name;
	}
	return ( *this );
}

void	DiamondTrap::attack( const std::string& target ) {
	ScavTrap::attack( target );
}

void	DiamondTrap::whoAmI( void ) const {
	std::cout << "DiamondTrap name: " << name
		<< ", ClapTrap name: " << ClapTrap::_name << std::endl;
}
