/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 00:40:08 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 15:52:33 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <iostream>
# include "AMateria.hpp"
# include "ICharacter.hpp"

class Character : public ICharacter {

	private:

		std::string		_name;
		AMateria*		_inventory[4];
		bool			_trash[4];

		bool	isValidIndex( int idx ) const;
		void	clearTrash( void );
		void	clearInventory( void );

	public:

		Character( void );
		Character( const std::string& name );
		Character( const Character& other );
		~Character( void );

		void	setName( const std::string& name );
		const std::string&	getName( void ) const;

		Character&	operator=( const Character& other );
		void		equip( AMateria* m );
		void		unequip( int idx );
		void		use( int idx, ICharacter& target );

};

#endif
