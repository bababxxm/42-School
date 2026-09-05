/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:00:50 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 18:26:57 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie( void ) : _name("Foo") {}

Zombie::Zombie( std::string &name ) : _name(name) {}

Zombie::~Zombie( void )
{
	std::cout << getName() << ": Starved to death..." << std::endl;
}

void	Zombie::setName( const std::string& name )
{
	_name = name;
}

const std::string&	Zombie::getName(void) const
{
	return (_name);
}

void	Zombie::announce( void )
{
	std::cout << getName() << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
