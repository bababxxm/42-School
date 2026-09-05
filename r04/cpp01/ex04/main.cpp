/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:19:06 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 04:07:42 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "File.hpp"

static bool	SearchAndReplace( char **argv  )
{
	const std::string&	name(argv[1]);
	const std::string&	search(argv[2]);
	const std::string&	replace(argv[3]);

	File inFile(name, std::ios::in);
	if (!inFile.getStream().is_open()) return (false);

	File outFile(name + ".replace", std::ios::out);
	if (!outFile.getStream().is_open()) return (false);

	std::string line;

	for (;std::getline(inFile.getStream(), line);) {
		size_t pos = 0;
		for (;(pos = line.find(search, pos)) != std::string::npos;) {
			line.erase(pos, search.length());
			line.insert(pos, replace);
			pos += replace.length();
		}
		outFile.getStream() << line << std::endl;
	}

	std::cout << "Replaced content of " << inFile.getName()
		<< " with " << outFile.getName() << std::endl;

	return (true);
}

int	main( int argc, char **argv )
{
	if (argc != 4) {
		std::cerr << "Usage: <fileName> <search> <replace>" << std::endl;
		return (1);
	}
	else {
		if (!SearchAndReplace(argv)) {
			return (1);
		}
		return (0);
	}
}
