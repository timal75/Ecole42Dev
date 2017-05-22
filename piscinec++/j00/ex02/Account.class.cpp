/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblancha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 22:41:45 by jblancha          #+#    #+#             */
/*   Updated: 2017/01/10 20:50:32 by jblancha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <ctime> 
#include <chrono>
#include "Account.class.hpp"

Account::Account (void)
{
	_accountIndex = this->getNbAccounts ();
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_amount = 0;
	this->_displayTimestamp ();
	std::cout << " index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout <<";created\n";
	Account::_nbAccounts++;
	Account::_totalAmount = Account::_totalAmount + _amount;

}

Account::Account (int initial_deposit) : _amount(initial_deposit)
{
	_accountIndex = this->getNbAccounts ();
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	this->_displayTimestamp ();
	std::cout << " index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout <<";created\n";
	Account::_nbAccounts++;
	Account::_totalAmount = Account::_totalAmount + _amount;

}

Account::~Account (void)
{
	this->_displayTimestamp ();
	std::cout << " index:";
	std::cout << this->_accountIndex;
	std::cout << ";amount:" << this->_amount;
	std::cout <<";closed\n";
}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp ();
	std::cout << " accounts:" << Account::getNbAccounts ();
	std::cout << ":total:" << Account::getTotalAmount ();
	std::cout << ":deposits:" << Account::getNbDeposits ();
	std::cout << ":withdrawals:" << Account::getNbWithdrawals () <<"\n";
}

void	Account::displayStatus(void) const
{
	this->_displayTimestamp ();
	std::cout << " index:";
	std::cout << this->_accountIndex;
	std::cout << ":total:" << this->_amount;
	std::cout << ":deposits:" << this->_nbDeposits;
	std::cout << ":withdrawals:" << this->_nbWithdrawals<<"\n";
}

void	Account::makeDeposit(int deposit)
{
	this->_displayTimestamp ();
	std::cout << " index:";
	std::cout << this->_accountIndex;
	std::cout << ":p_amount:" << this->_amount;
	std::cout << ":deposit:" << deposit;
	_amount = _amount + deposit;
	_nbDeposits++;
	std::cout << ":amount:" << this->_amount;
	std::cout << ":nb_deposits:" << this->_nbDeposits<<"\n";
	Account::_totalAmount = Account::_totalAmount + deposit;
	Account::_totalNbDeposits++;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	this->_displayTimestamp ();
	std::cout << " index:";
	std::cout << this->_accountIndex;
	std::cout << ":p_amount:" << this->_amount;
	if (this->checkAmount() >= withdrawal)
	{
		std::cout << ":withdrawal:" << withdrawal;
		_amount = _amount - withdrawal;
		_nbWithdrawals++;
		std::cout << ":amount:" << this->_amount;
		std::cout << ":nb_withdrawals:" << this->_nbWithdrawals<<"\n";
		Account::_totalAmount = Account::_totalAmount - withdrawal;
		Account::_totalNbWithdrawals++;
		return (true);
	}
	else
		std::cout << ":withdrawal:refused\n";
	return (false);
}

int	Account::getNbAccounts(void)
{
	return(Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return(Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return(Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals (void)
{
	return(Account::_totalNbWithdrawals);
}

int	Account::checkAmount (void) const
{
	return(this->_amount);
}

void	Account::_displayTimestamp( void )
{
	using std::chrono::system_clock;
	std::time_t tt = system_clock::to_time_t (system_clock::now());

	struct std::tm * ptm = std::localtime(&tt);
	std::cout << std::put_time(ptm,"[%Y%m%d_%H%M%S]");
}

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
