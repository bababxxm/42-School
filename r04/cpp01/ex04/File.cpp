/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:45:17 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 04:02:48 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "File.hpp"

File::File( const std::string& name, std::ios_base::openmode mode) :
	_name(name), _mode(mode)
{
	_file.open(_name.c_str(), _mode);
	if (_file.fail()) {
		std::cout << "Failed to open file: " << getName() << std::endl;
	}
	else {
		std::cout << "File opened: " << getName() << std::endl;
	}
}

File::~File( void )
{
	if (_file.is_open()) {
		_file.close();
		std::cout << "File closed: " << getName() << std::endl;
	}
}

const std::string&	File::getName( void ) const
{
	return (_name);
}

std::fstream&	File::getStream( void )
{
	return (_file);
}
