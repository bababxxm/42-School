/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:54:56 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/24 22:57:00 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Cat : public AAnimal {

	private:

		Brain*	_brain;

	public:

		Cat( void );
		Cat( const Cat& other );
		~Cat( void );

		Cat&	operator=( const Cat& other );
		Brain*	getBrain( void ) const;
		void	makeSound( void ) const;

};

#endif
