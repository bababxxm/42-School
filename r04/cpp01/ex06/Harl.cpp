/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 01:47:44 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 04:18:26 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void	Harl::debug( void )
{
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love having extra bacon on my burger. Seriously, I need it!" << std::endl;
}

void	Harl::info( void )
{
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs extra money!" << std::endl;
}

void	Harl::warning( void )
{
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve some extra bacon for free." << std::endl;
}

void	Harl::error( void )
{
	std::cout << "[ ERROR ]" << std::endl;
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

	int	i = -1;
	for (; i < 4; i++) {
		if (levels[i] == level) {
			break ;
		}
	}

	switch (i) {
		case 0:
			(this->*ft[0])();
		case 1:
			(this->*ft[1])();
		case 2:
			(this->*ft[2])();
		case 3:
			(this->*ft[3])();
			break ;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	}

}
