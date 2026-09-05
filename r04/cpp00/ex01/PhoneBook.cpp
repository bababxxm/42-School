/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 01:07:42 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/17 01:05:17 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	Index = 0;
	TotalContacts = 0;
	Input = "";
	ToSearch = -1;
	TextLength = 10;
	SpaceLength = 1;
}

bool	IsDigitsOnly(const std::string &Str)
{
	if (Str.empty()) return (false);

	for (size_t i = 0; i < Str.size(); i++) {
		if (!std::isdigit(Str[i])) return (false);
	}
	return (true);
}

bool	PhoneBook::PromptInfo(std::string Info)
{
	do {

		std::cout << Info;
		if (!std::getline(std::cin, Input)) {
			std::cout << std::endl;
			return (false);
		}
		if (Input.empty()) {
			std::cout << "Information cannot be blank." << std::endl;
		}
		if (Info == "Phone Number: " && !Input.empty()) {
			if (!IsDigitsOnly(Input)) {
				std::cout << "Phone number must contain digits only." << std::endl;
				Input.clear();
				continue ;
			}
		}

	} while (Input.empty());

	return (true);
}

bool	PhoneBook::Add(void)
{
	system("clear");
    std::cout << "Complete new contact information.\n" << std::endl;

	if (!PromptInfo("Phone Number: ")) return (false);
	Contact[Index].SetPhoneNumber(Input);

	if (!PromptInfo("First Name: ")) return (false);
	Contact[Index].SetFirstName(Input);

	if (!PromptInfo("Last Name: ")) return (false);
	Contact[Index].SetLastName(Input);

	if (!PromptInfo("Nickname: ")) return (false);
	Contact[Index].SetNickname(Input);

	if (!PromptInfo("Darkest Secret: ")) return (false);
	Contact[Index].SetDarkestSecret(Input);

	system("clear");

	std::cout << "Phone Number: " << Contact[Index].GetPhoneNumber() << std::endl;
	std::cout << "First Name: " << Contact[Index].GetFirstName() << std::endl;
	std::cout << "Last Name: " << Contact[Index].GetLastName() << std::endl;
	std::cout << "Nickname: " << Contact[Index].GetNickname() << std::endl;
	std::cout << "Darkest Secret: " << Contact[Index].GetDarkestSecret() << std::endl;
    std::cout << std::endl;

	std::cout << "Success! New contact has been added.\n" << std::endl;

	Index = (Index + 1) % MaxContacts;
	if (TotalContacts < MaxContacts) TotalContacts++;

	return (true);
}

int	ToInt(const std::string Str)
{
	int					Value;
	char				Leftover;
	std::istringstream	Iss(Str);

	if (!(Iss >> Value)) return (-1);
	if (Iss >> Leftover) return (-1);

	return (Value);
}

std::string	ToString(int Value)
{
	std::ostringstream	Oss;

	Oss << Value;
	return (Oss.str());
}

void	SetCell(std::string Text, size_t TextLength, size_t SpaceLength)
{
	std::cout << "|" << std::string(SpaceLength, ' ');

	if (Text.length() <= TextLength) {
		std::cout << std::setw(TextLength)
			<< std::right << Text;
	}
	else {
		std::cout << std::setw(TextLength)
			<< std::right << Text.substr(0, TextLength - 1) + ".";
	}

	std::cout << std::string(SpaceLength, ' ');
}

void	SetRow(const std::string Columns[], size_t Count,
			size_t TextLength, size_t SpaceLength)
{
	for (size_t i = 0; i < Count; i++) {
		SetCell(Columns[i], TextLength, SpaceLength);
	}
	std::cout << "|" << std::endl;
}

void	PhoneBook::PreviewTable(void)
{
	std::string	Rows[5];

	Rows[0] = "Index";
	Rows[1] = "Phone No.";
	Rows[2] = "First Name";
	Rows[3] = "Last Name";
	Rows[4] = "Nickname";

	SetRow(Rows, 5, TextLength, SpaceLength);
	for (size_t i = 0; i < TotalContacts; i++) {
		Rows[0] = ToString(i);
		Rows[1] = Contact[i].GetFirstName();
		Rows[2] = Contact[i].GetLastName();
		Rows[3] = Contact[i].GetNickname();
		Rows[4] = Contact[i].GetDarkestSecret();

		SetRow(Rows, 5, TextLength, SpaceLength);
	}
	std::cout << std::endl;
}

bool	PhoneBook::Search(void)
{
	system("clear");

	if (TotalContacts == 0) {
		std::cout << "Currently, there are no contacts in PhoneBook.\n" << std::endl;
		return (false);
	}

	do {

		system("clear");
		std::cout << "Here's all the contacts you currently have.\n" << std::endl;
		PreviewTable();

		if (!PromptInfo("Please insert a valid index to search: ")) return (false);
		ToSearch = ToInt(Input);
		std::cout << std::endl;

	} while (ToSearch < 0 || ToSearch >= TotalContacts);

	system("clear");
	std::cout << "Here's the contact information.\n" << std::endl;

	std::cout << "Phone Number: " << Contact[ToSearch].GetPhoneNumber() << std::endl;
	std::cout << "First Name: " << Contact[ToSearch].GetFirstName() << std::endl;
	std::cout << "Last Name: " << Contact[ToSearch].GetLastName() << std::endl;
	std::cout << "Nickname: " << Contact[ToSearch].GetNickname() << std::endl;
	std::cout << "Darkest Secret: " << Contact[ToSearch].GetDarkestSecret() << std::endl;
    std::cout << std::endl;

	return (true);
}

void	PhoneBook::Exit(void)
{
	std::cout << "See ya later!" << std::endl;
	exit(EXIT_SUCCESS);
}
