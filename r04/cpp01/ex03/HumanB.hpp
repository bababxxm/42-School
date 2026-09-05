/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:29:30 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 18:33:05 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanB 
{
	
	private:
		
		std::string		_name;
		Weapon*			_weapon;

	public:

		HumanB( const std::string& name );
		~HumanB( void );

		void	setName( const std::string& name );
		void	setWeapon( Weapon& weapon );

		const std::string&	getName( void ) const;
		const Weapon*	getWeapon( void ) const;

		void	attack( void );

};

#endif
