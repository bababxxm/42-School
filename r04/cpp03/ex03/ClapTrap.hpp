/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:20:37 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 23:38:27 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

# include <iostream>

class ClapTrap {

	protected:

		std::string		_name;
		unsigned int	_hitPoints;
		unsigned int	_energyPoints;
		unsigned int	_attackDamage;

	public:

		ClapTrap( void );
		ClapTrap( const std::string& name );
		ClapTrap( const ClapTrap& other );
		virtual	~ClapTrap( void );
		
		std::string		getName( void ) const;
		ClapTrap&		operator=( const ClapTrap& other );
		virtual void	attack( const std::string& target );
		void			takeDamage( unsigned int amount );
		void			beRepaired( unsigned int amount );
		void			displayStatus( void ) const;

};

#endif
