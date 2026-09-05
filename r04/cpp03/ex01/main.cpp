/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:20:40 by sklaokli          #+#    #+#             */
/*   Updated: 2025/11/12 15:00:07 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int	main(void)
{
	ScavTrap	scav0;
	ScavTrap	scav1( "SC4V-TP" );
	ScavTrap	scav2( scav1 );

	scav0.attack( scav1.getName() );
	scav1.displayStatus();
	scav1.takeDamage( 5 );
	scav1.displayStatus();
	scav1.beRepaired( 3 );
	scav1.displayStatus();
	scav1.guardGate();
	scav1.attack( scav2.getName() );
	scav1.displayStatus();
	scav2.displayStatus();
	scav2.attack( scav0.getName() );
	scav2.displayStatus();
	return ( 0 );
}
