/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:29:18 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 18:38:26 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( const std::string& name ) :
	_name(name), _weapon(NULL) {}

HumanB::~HumanB( void ) {}

void	HumanB::setName( const std::string& name ) { _name = name; }
void	HumanB::setWeapon( Weapon& weapon ){ _weapon = &weapon; }

const Weapon*		HumanB::getWeapon( void ) const { return (_weapon); }
const std::string&	HumanB::getName( void ) const { return (_name); }

void	HumanB::attack( void )
{
	if (_weapon) {
		std::cout << getName() << " attacks with their "
			<< getWeapon()->getType() << "." << std::endl;
	}
	else {
		std::cout << getName()
			<< " attacks with their punches." << std::endl;
	}
}
