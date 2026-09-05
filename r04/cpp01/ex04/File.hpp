/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   File.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 19:45:20 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/23 00:38:30 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_HPP
# define FILE_HPP

#include <iostream>
#include <fstream>

class File
{
	
	private:

		std::string					_name;
		std::fstream				_file;
		std::ios_base::openmode		_mode;

	public:

		File( const std::string& name, std::ios_base::openmode mode );
		~File( void );

		const std::string&	getName( void ) const;
		std::fstream&		getStream( void );

};

#endif
