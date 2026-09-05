/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 01:07:38 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/17 01:14:03 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact::Contact(void)
{
	PhoneNumber = "";
	Nickname = "";
	FirstName = "";
	LastName = "";
	DarkestSecret = "";
}

void	Contact::SetPhoneNumber(const std::string& PhoneNumber)
{
	this->PhoneNumber = PhoneNumber;
}
void	Contact::SetNickname(const std::string& Nickname)
{
	this->Nickname = Nickname;
}
void	Contact::SetFirstName(const std::string& FirstName)
{
	this->FirstName = FirstName;
}
void	Contact::SetLastName(const std::string& LastName)
{
	this->LastName = LastName;
}
void	Contact::SetDarkestSecret(const std::string& DarkestSecret)
{
	this->DarkestSecret = DarkestSecret;
}

const std::string&	Contact::GetPhoneNumber(void) const
{
	return (this->PhoneNumber);
}

const std::string&	Contact::GetNickname(void) const
{
	return (this->Nickname);
}

const std::string&	Contact::GetFirstName(void) const
{
	return (this->FirstName);
}

const std::string&	Contact::GetLastName(void) const
{
	return (this->LastName);
}

const std::string&	Contact::GetDarkestSecret(void) const
{
	return (this->DarkestSecret);
}
