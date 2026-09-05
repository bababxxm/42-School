/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:54:56 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/04 13:26:16 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat : public Animal {

	public:

		Cat( void );
		Cat( const Cat& other );
		~Cat( void );

		Cat&			operator=( const Cat& other );
		virtual void	makeSound( void ) const;

};

#endif
