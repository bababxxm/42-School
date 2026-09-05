/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 15:01:29 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 23:51:52 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap : virtual public ClapTrap {

	public:

		FragTrap( void );
		FragTrap( const std::string& name );
		FragTrap( const FragTrap& other );
		virtual	~FragTrap( void );
		
		FragTrap&	operator=( const FragTrap& other );
		void		highFivesGuys( void );

};

#endif
