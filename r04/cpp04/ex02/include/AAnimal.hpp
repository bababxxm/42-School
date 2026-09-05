/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:53:59 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/24 22:54:01 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal {

	protected:

		std::string	_type;

	public:

		AAnimal( void );
		AAnimal( const AAnimal& other );
		virtual ~AAnimal( void );

		AAnimal&		operator=( const AAnimal& other );
		std::string		getType( void ) const;
		virtual void	makeSound( void ) const = 0;
		
};

#endif
