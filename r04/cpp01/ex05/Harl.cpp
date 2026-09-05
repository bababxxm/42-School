/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 01:47:44 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 02:39:17 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "I love having extra bacon on my burger. Seriously, I need it!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "I cannot believe adding extra bacon costs extra money!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "I think I deserve some extra bacon for free." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "My burger is ruined, and I am extremely upset!" << std::endl;
}

void	Harl::complain( std::string level )
{
	void (Harl::*ft[4])(void) = {
		&Harl::debug, &Harl::info, &Harl::warning, &Harl::error
	};

	std::string	levels[4] = {
		"DEBUG", "INFO", "WARNING", "ERROR"
	};

	for (size_t i = 0; i < 4; i++) {
		if (levels[i] == level) {
			(this->*ft[i])();
		}
	}
}
