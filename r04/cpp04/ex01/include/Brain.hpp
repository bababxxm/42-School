/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 22:31:08 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/24 22:31:25 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

class Brain {

	private:

		std::string		_ideas[100];
		bool			isValidIndex( int index ) const;

	public:

		Brain( void );
		Brain( const Brain& other );
		~Brain( void );

		Brain& 		operator=( const Brain& other );
		void		setIdea( int index, const std::string& idea );
		std::string	getIdea( int index ) const;

};

#endif
