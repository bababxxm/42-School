/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:54:48 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 14:57:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal {

	protected:

		std::string		_type;

	public:

		Animal( void );
		Animal( const std::string& type );
		Animal( const Animal& other );
		virtual ~Animal( void );

		Animal&			operator=( const Animal& other );
		std::string		getType( void ) const;
		virtual void	makeSound( void ) const;		
		
};

#endif
