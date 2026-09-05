/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:20:40 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 23:53:10 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	ft0;
	FragTrap	ft1( "FR4G-TP" );
	FragTrap	ft2( ft1 );

	ft0.displayStatus();
	ft1.displayStatus();
	ft2.displayStatus();
	ft1.attack( ft2.getName() );
	ft1.takeDamage( 20 );
	ft1.beRepaired( 10 );
	ft1.displayStatus();
	ft2.highFivesGuys();
	return ( 0 );
}
