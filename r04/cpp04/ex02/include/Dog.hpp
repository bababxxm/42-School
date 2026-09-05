/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:55:00 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/24 22:57:11 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog : public AAnimal {

	private:

		Brain*	_brain;

	public:

		Dog( void );
		Dog( const Dog& other );
		~Dog( void );

		Dog&	operator=( const Dog& other );
		Brain*	getBrain( void ) const;
		void	makeSound( void ) const;

};

#endif
