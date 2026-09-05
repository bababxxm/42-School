/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:29:28 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 18:33:03 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include "Weapon.hpp"

class HumanA
{

	private:
		
		std::string		_name;
		Weapon&			_weapon;

	public:

		HumanA( const std::string& name, Weapon& weapon );
		~HumanA( void );

		void	setName( const std::string& name );
		void	setWeapon( const Weapon& weapon );

		const std::string&	getName( void ) const;
		const Weapon&		getWeapon( void ) const;

		void	attack( void );

};

#endif
