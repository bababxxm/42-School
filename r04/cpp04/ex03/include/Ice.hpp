/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:30:15 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 01:21:11 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"

class Ice : public AMateria {

	public:

		Ice( void );
		Ice( const Ice& other );
		~Ice( void );
		
		Ice&		operator=( const Ice& other );
		AMateria*	clone( void ) const;
		void		use( ICharacter& target );

};

#endif
