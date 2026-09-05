/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 01:47:47 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 04:21:42 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

static void	harlFilter( const std::string& complain )
{
	Harl	H;

	H.complain(complain);
}

int	main( int argc, char **argv )
{
	if (argc < 2) {
		std::cerr << "What?! You didn't even give me a level to complain about?!" << std::endl;
		return (1);
	}
	else if (argc > 2) {
		std::cerr << "Ugh! Too many arguments! I can only complain about ONE thing at a time!" << std::endl;
		return (2);
	}
	harlFilter(std::string(argv[1]));
	return (0);
}
