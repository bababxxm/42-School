/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 16:56:29 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/24 10:09:07 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {

	public:

		WrongCat( void );
		WrongCat( const WrongCat& other );
		~WrongCat( void );

		WrongCat&	operator=( const WrongCat& other );
		void		makeSound( void ) const;

};

#endif
