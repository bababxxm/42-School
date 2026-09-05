/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 22:35:16 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 15:52:00 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"

class Cure : public AMateria {
	
	public:

		Cure( void );
		Cure( const Cure& other );
		~Cure( void );

		Cure&		operator=( const Cure& other );
		AMateria*	clone( void ) const;
		void		use( ICharacter& target );

};

#endif
