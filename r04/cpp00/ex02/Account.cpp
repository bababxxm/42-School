/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sklaokli <sklaokli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/17 01:08:58 by sklaokli          #+#    #+#             */
/*   Updated: 2025/09/17 04:14:32 by sklaokli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( void ) :
	_accountIndex(_nbAccounts), _amount(0), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();

	_nbAccounts++;
	std::cout << "index:" << _accountIndex  << ";"
		<< "amount:" << _amount << ";" << "created" << std::endl;
}

Account::Account( int initial_deposit ) :
	_accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0)
{
	_displayTimestamp();

	_nbAccounts++;
	_totalAmount += initial_deposit;
	std::cout << "index:" << _accountIndex  << ";"
		<< "amount:" << _amount << ";" << "created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex  << ";"
		<< "amount:" << _amount << ";" << "closed" << std::endl;
}

int	Account::getNbAccounts( void )
{
	return (_nbAccounts);
}

int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}

int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}

int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();

	std::cout << "accounts:" << getNbAccounts() << ";"
		<< "total:" << getTotalAmount() << ";"
		<< "deposits:" << getNbDeposits() << ";"
		<< "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";";

	_amount += deposit;
	_totalAmount += deposit;

	_nbDeposits++;
	_totalNbDeposits++;

	std::cout << "deposit:" << deposit << ";"
		<< "amount:" << _amount << ";"
		<< "nb_deposits:" << _nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";"
		<< "p_amount:" << _amount << ";"
		<< "withdrawal:";

	if (_amount < withdrawal) {
		std::cout << "refused" << std::endl;
		return (false);
	}

	_amount -= withdrawal;
	_totalAmount -= withdrawal;

	_nbWithdrawals++;
	_totalNbWithdrawals++;

	std::cout << withdrawal << ";" << "amount:" << _amount << ";"
		<< "nb_withdrawals:" << _nbWithdrawals << std::endl;

	return (true);
}

int	Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();

	std::cout << "index:" << _accountIndex << ";"
		<< "amount:" << _amount << ";"
		<< "deposits:" << _nbDeposits << ";"
		<< "withdrawals:" << _nbWithdrawals << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t	now = std::time(NULL);
	std::tm*	ltm = std::localtime(&now);

	char buffer[20];
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", ltm);

	std::cout << buffer << " ";
}
