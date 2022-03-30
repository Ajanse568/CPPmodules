/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ajanse <ajanse@student.42.fr>                +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/02/10 17:28:32 by ajanse        #+#    #+#                 */
/*   Updated: 2022/02/10 22:28:20 by ajanse        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime>
#include "Account.hpp"

int		Account::_totalNbWithdrawals = 0;
int		Account::_nbAccounts = 0;
int		Account::_totalAmount = 0;
int		Account::_totalNbDeposits = 0;


Account::Account( int initial_deposit ) {

	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = initial_deposit;
	_totalAmount += initial_deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ';'
			  << "created\n";
}

Account::Account(void) {

	this->_accountIndex = _nbAccounts;
	_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ';'
			  << "created\n";
}

Account::~Account(void) {

	_nbAccounts--;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ';'
			  << "closed\n";
}

void	Account::_displayTimestamp(void) {

	const	std::time_t time_now = std::time(NULL);
	tm	tm_strct = *std::gmtime(&time_now);
	
	std::cout << "[" << (tm_strct.tm_year + 1900);
	std::cout << std::setfill('0') << std::setw(2) << (tm_strct.tm_mon + 1);
	std::cout << std::setfill('0') << std::setw(2) << tm_strct.tm_mday << "_";
	std::cout << std::setfill('0') << std::setw(2) << tm_strct.tm_hour;
	std::cout << std::setfill('0') << std::setw(2) << tm_strct.tm_min;
	std::cout << std::setfill('0') << std::setw(2) << tm_strct.tm_sec << "] ";
}

void	Account::displayAccountsInfos(void) {

	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts() << ';'
			  << "total:" << Account::getTotalAmount() << ';'
			  << "deposits:" << Account::getNbDeposits() << ';'
			  << "withdrawals:" << Account::getNbWithdrawals() << '\n';
}

void	Account::displayStatus(void) const {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "amount:" << this->_amount << ';'
			  << "deposits:" << this->_nbDeposits << ';'
			  << "withdrawals:" << this->_nbWithdrawals << '\n';
}

void	Account::makeDeposit(int deposit) {

	_displayTimestamp();
	this->_nbDeposits++;
	_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex << ';'
			  << "p_amount:" << this->_amount << ';'
			  << "deposit:" << deposit << ';';
	this->_amount += deposit;
	_totalAmount += deposit;
	std::cout << "amount:" << this->_amount << ';'
			  << "nb_deposits:" << _nbDeposits << '\n';
}

bool	Account::makeWithdrawal(int withdrawal) {

	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ';'
			  << "p_amount:" << this->_amount << ';'
			  << "withdrawal:";
	if (this->_amount < withdrawal)
	{
		std::cout << "refused\n";
		return (false);
	}
	this->_amount -= withdrawal;
	_totalAmount -= withdrawal;
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	std::cout << withdrawal << ';'
			  << "amount:" << this->_amount << ';'
			  << "nb_withdrawals:" << this->_nbWithdrawals << '\n';
	return (true);
}

int	Account::getNbAccounts( void ) {

	return (_nbAccounts);
}
int	Account::getTotalAmount( void ) {

	return (_totalAmount);
}
int	Account::getNbDeposits( void ) {

	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void ) {

	return (_totalNbWithdrawals);
}