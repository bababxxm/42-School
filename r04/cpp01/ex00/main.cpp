/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 05:00:00 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 18:27:43 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main( void )
{
	Zombie	z1;
	Zombie*	z2 = NULL;
	Zombie*	z3 = NULL;
	Zombie*	z4 = NULL;

	z1.announce();

	z2 = new Zombie;
	z2->announce();
	
	z3 = z2->newZombie("John");
	z3->announce();
	
	z4->randomChump("Felix");

	delete z2;
	delete z3;
}
