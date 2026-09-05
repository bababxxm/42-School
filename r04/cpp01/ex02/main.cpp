/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 05:01:37 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/17 20:22:49 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main( void )
{
	std::string		string = "HI THIS IS BRAIN";
	std::string*	stringPTR = &string;
	std::string&	stringREF = string;

	std::cout << &string << '\n'
		<< &stringPTR << '\n'
		<< &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << string << '\n'
		<< *stringPTR << '\n'
		<< stringREF << std::endl;
}
