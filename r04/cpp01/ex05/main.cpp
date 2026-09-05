/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 01:47:47 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 02:23:55 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

int	main( void )
{
	Harl	H;

	H.complain("DEBUG");
	H.complain("INFO");
	H.complain("WARNING");
	H.complain("ERROR");
}
