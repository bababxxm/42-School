/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 20:29:26 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 18:40:08 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{

	private:
		
		std::string		_type;

	public:

		Weapon( const std::string& type );
		~Weapon( void );

		void	setType( const std::string& type );
		const std::string&	getType( void ) const;

};

#endif
