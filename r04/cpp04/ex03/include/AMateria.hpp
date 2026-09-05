/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/18 21:57:36 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 15:51:55 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>
# include "ICharacter.hpp"

class ICharacter;

class AMateria {

	protected:

		std::string	_type;

	public:

		AMateria( void );
		AMateria( const std::string& type );
		AMateria( const AMateria& other );
		virtual ~AMateria( void ) {};

		void	setType( const std::string& type );
		const std::string&	getType( void ) const;

		AMateria&			operator=( const AMateria& other );
		virtual	AMateria*	clone( void ) const = 0;
		virtual	void		use( ICharacter& target ) = 0;

};

#endif
