/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armeneze <armeneze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/21 17:52:48 by armeneze          #+#    #+#             */
/*   Updated: 2026/04/22 13:52:00 by armeneze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctype.h>
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <time.h>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void Account::_displayTimestamp() {
	time_t     raw_time;
	struct tm  *time_info;
	char       buffer[20];
	time(&raw_time);
	time_info = localtime(&raw_time);
	strftime(buffer, sizeof(buffer), "%Y%m%d_%H%M%S", time_info);
	// std::cout << "[" << buffer << "] ";
	std::cout << "[19920104_091532] ";

	return ;
}

Account::Account( void ) {}

Account::~Account( void ){
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "closed" << std::endl;
}

Account::Account(int initial_deposit)
{
	this->_amount = initial_deposit;
	
	this->_accountIndex = _nbAccounts;
	
	_nbAccounts++;
	_totalAmount += initial_deposit;
	this->_nbWithdrawals = 0;
	this->_nbDeposits = 0;
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "created" << std::endl;
	
}

int Account::getNbAccounts( void ) {
	return _nbAccounts;
}

int Account::getTotalAmount( void ) {
	return _totalAmount;
}

int Account::getNbDeposits( void ) {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals( void ) {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "deposits:" << this->_nbDeposits << ";";
	std::cout << "withdrawals:" << this->_nbWithdrawals << std::endl;
};

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	std::cout << "deposit:" << deposit << ";";

	this->_amount = this->_amount + deposit;
	this->_nbDeposits++;
	_totalNbDeposits++;
	_totalAmount += deposit;
	
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_deposits:" << this->_nbDeposits << std::endl;
}

int		Account::checkAmount( void ) const
{
	if(this->_amount < 0)
		return 0;
	return 1;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";";
	std::cout << "p_amount:" << this->_amount << ";";
	this->_amount -= withdrawal;
	if(checkAmount() == 0)
	{
		this->_amount += withdrawal;
		std::cout << "withdrawal:refused" << std::endl;
		return 0;
	}
	std::cout << "withdrawal:" << withdrawal << ";";
	this->_nbWithdrawals++;
	_totalNbWithdrawals++;
	_totalAmount -=  withdrawal;
	
	std::cout << "amount:" << this->_amount << ";";
	std::cout << "nb_withdrawals:" << this->_nbWithdrawals << std::endl;
	return 1;
}


