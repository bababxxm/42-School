/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 12:09:00 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 23:31:54 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap {

	public:
	
		ScavTrap( void );
		ScavTrap( const std::string& name );
		ScavTrap( const ScavTrap& other );
		virtual	~ScavTrap( void );

		ScavTrap&		operator=( const ScavTrap& other );
		virtual void	attack( const std::string& target );
		void			guardGate( void ) const;

};

#endif
