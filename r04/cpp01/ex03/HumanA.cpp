/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:29:14 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 18:41:01 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( const std::string& name, Weapon& weapon ) :
	_name(name), _weapon(weapon) {}

HumanA::~HumanA( void ) {}

void	HumanA::setName( const std::string& name ) { _name = name; }
void	HumanA::setWeapon( const Weapon& weapon ) { _weapon = weapon; }

const Weapon&		HumanA::getWeapon( void ) const { return (_weapon); }
const std::string&	HumanA::getName( void ) const { return (_name); }

void	HumanA::attack( void )
{
	std::cout << getName() << " attacks with their "
		<< getWeapon().getType() << "." << std::endl;
}
