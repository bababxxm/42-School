/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:55:00 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 13:26:25 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal {

	public:

		Dog( void );
		Dog( const Dog& other );
		~Dog( void );

		Dog&			operator=( const Dog& other );
		virtual void	makeSound( void ) const;

};

#endif
