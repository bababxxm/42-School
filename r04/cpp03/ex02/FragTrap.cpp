/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:03:08 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 23:23:09 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap( void ) : ClapTrap( "Default" ) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created." << std::endl;
}

FragTrap::FragTrap( const std::string& name ) : ClapTrap( name ) {
	_hitPoints = 100;
	_energyPoints = 100;
	_attackDamage = 30;
	std::cout << "FragTrap " << _name << " has been created." << std::endl;
}

FragTrap::FragTrap( const FragTrap& other ) : ClapTrap( other ) {
	std::cout << "FragTrap " << _name << " has been copied." << std::endl;
}

FragTrap::~FragTrap( void ) {
	std::cout << "FragTrap " << _name << " has been destroyed." << std::endl;
}

FragTrap&	FragTrap::operator=( const FragTrap& other ) {
	if ( this != &other ) {
		ClapTrap::operator=( other );
	}
	std::cout << "FragTrap " << _name << " has been assigned." << std::endl;
	return ( *this );
}

void	FragTrap::highFivesGuys( void ) {
	std::cout << "FragTrap " << _name << " is requesting a high five! ✋" << std::endl;
}
