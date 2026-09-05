/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 01:07:40 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/16 13:27:23 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact
{
	private:
		std::string 	PhoneNumber;
		std::string 	Nickname;
		std::string 	FirstName;
		std::string 	LastName;
		std::string 	DarkestSecret;

	public:
		Contact(void);

		void	SetPhoneNumber(const std::string& PhoneNumber);
		void	SetNickname(const std::string& Nickname);
		void	SetFirstName(const std::string& FirstName);
		void	SetLastName(const std::string& LastName);
		void	SetDarkestSecret(const std::string& DarkestSecret);

		const std::string& 	GetPhoneNumber(void) const;
		const std::string& 	GetNickname(void) const;
		const std::string& 	GetFirstName(void) const;
		const std::string& 	GetLastName(void) const;
		const std::string& 	GetDarkestSecret(void) const;
};

#endif
