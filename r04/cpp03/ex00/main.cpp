/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 14:20:40 by sklaokli          #+#    #+#             */
/*   Updated: 2025/12/03 23:53:16 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	ct1( "One" );
	ClapTrap	ct2( "Two" );

	ct1.attack( ct2.getName() );
	ct2.takeDamage( 5 );
	ct2.beRepaired( 3 );
	ct2.attack( ct1.getName() );
	ct1.takeDamage( 12 );
	ct1.beRepaired( 4 );
	ct1.displayStatus();
	ct2.displayStatus();
	return ( 0 );
}
