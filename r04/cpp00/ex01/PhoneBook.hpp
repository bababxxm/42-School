/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 01:07:44 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/16 17:49:17 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <cstddef>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <sstream>

# include "Contact.hpp"

# define MaxContacts 3

class PhoneBook
{
	private:
		std::string		Input;
		
		size_t			ToSearch;
		size_t			TextLength;
		size_t			SpaceLength;
		
		size_t			Index;
		size_t			TotalContacts;
		Contact			Contact[MaxContacts];

	public:
		PhoneBook(void);

		bool	Add(void);
		bool	Search(void);
		void	Exit(void);

		bool	PromptInfo(std::string Info);
		void	PreviewTable(void);
};

#endif
