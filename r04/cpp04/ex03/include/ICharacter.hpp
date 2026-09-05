/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:07:15 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 15:52:05 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"

class AMateria;

class ICharacter {

	public:

		virtual ~ICharacter( void ) {};

		virtual const std::string&	getName( void ) const = 0;

		virtual void	equip( AMateria* m ) = 0;
		virtual void	unequip( int idx ) = 0;
		virtual void	use( int idx, ICharacter& target ) = 0;

};

#endif
