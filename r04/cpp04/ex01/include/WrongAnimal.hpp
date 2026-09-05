/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:56:17 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/24 10:09:07 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal {

	protected:

		std::string	_type;

	public:

		WrongAnimal( void );
		WrongAnimal( const WrongAnimal& other );
		~WrongAnimal( void );

		WrongAnimal&	operator=( const WrongAnimal& other );
		std::string		getType( void ) const;
		void			makeSound( void ) const;

};

#endif
