/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/13 15:32:58 by sklaokli          #+#    #+#             */
/*   Updated: 2026/05/25 04:47:42 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <exception>
#include <map>
#include <string>
#include <vector>

class BitcoinExchange {
public:
	BitcoinExchange();
	BitcoinExchange(const BitcoinExchange&);
	BitcoinExchange& operator=(const BitcoinExchange&);
	~BitcoinExchange();

	class FileOpenException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class DatabaseHeaderException : public std::exception {
	public:
		virtual const char* what() const throw();
	};
	class InputHeaderException : public std::exception {
	public:
		virtual const char* what() const throw();
	};

	void loadDatabase(const std::string&);
	void processInput(const std::string&);
private:
	double getExchangeAmount(const std::string& date, double value) const;

	static bool isValidDate(const std::string&);
	static double parseValue(const std::string&, bool);
	static std::string trimWhitespace(const std::string& str);
	static std::vector<std::string> splitTokens(const std::string&, char);
	static int extractDigits(const std::string&);
	static std::string getPresentDateString();

	std::map<std::string, double> _database;
};

#endif
