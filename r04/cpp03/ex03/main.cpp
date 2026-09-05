/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:20:40 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 23:53:07 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int	main(void)
{
	DiamondTrap	dia1( "DiamondOne" );
	dia1.displayStatus();
	dia1.attack( "TargetA" );
	dia1.takeDamage( 30 );
	dia1.beRepaired( 20 );
	dia1.displayStatus();
	dia1.whoAmI();
	return ( 0 );
}
