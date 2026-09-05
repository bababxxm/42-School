/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:01:03 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/17 04:49:41 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

class Zombie
{

	private:

		std::string		_name;

	public:

		Zombie( void );
		Zombie( std::string &name );

		~Zombie( void );

		void	announce( void );
		Zombie*	newZombie( std::string name );
		void	randomChump( std::string name );

		void	setName(  const std::string& name );
		const std::string&	getName(void) const;

};

#endif
