/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:29:12 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 18:39:51 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( const std::string& type ) :
	_type(type) {}

Weapon::~Weapon( void ) {}

void	Weapon::setType( const std::string &type ) { _type = type; }

const std::string&	Weapon::getType( void ) const { return (_type); }
