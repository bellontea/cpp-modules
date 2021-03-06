#include <iostream>
#include <iomanip>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit)
{
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	Account::_totalAmount += initial_deposit;
	_nbDeposits = _nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << initial_deposit << ";";
	std::cout << "created" << std::endl;
}

Account::Account()
{
	_accountIndex = _nbAccounts++;
	_amount = _nbDeposits = _nbWithdrawals = 0;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:0;";
	std::cout << "created" << std::endl;
}

Account::~Account()
{
	Account::_displayTimestamp();
	_nbAccounts--;
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t now = time(0);
	tm *start = localtime(&now);
	std::cout << "[" << 1900 + start->tm_year;
	std::cout << std::setfill('0') << std::setw(2) << 1 + start->tm_mon;
	std::cout << std::setw(2) << start->tm_mday;
	std::cout << "_" << std::setw(2) << start->tm_hour;
	std::cout << std::setw(2) << start->tm_min;
	std::cout << std::setw(2) << start->tm_sec << "] ";
}

int Account::getNbAccounts(void)
{return (Account::_nbAccounts);}

int Account::getTotalAmount(void)
{return (Account::_totalAmount);}

int Account::getNbDeposits(void)
{return (Account::_totalNbDeposits);}

int Account::getNbWithdrawals(void)
{return (Account::_totalNbWithdrawals);}

void Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";";
	std::cout << "total:" << Account::_totalAmount << ";";
	std::cout << "deposits:" << Account::_totalNbDeposits << ";";
	std::cout << "withdrawals:" << Account::_totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_nbDeposits++;
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" <<  _amount << ";";
	std::cout << "deposit:" << deposit << ";";
	Account::_totalAmount += deposit;
	std::cout << "amount:" << (_amount += deposit) << ";";
	Account::_totalNbDeposits++;
	std::cout << "nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" <<  _amount << ";";
	if (_amount < withdrawal)
	{
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	else
	{
		std::cout << "withdrawal:" << withdrawal << ";";
		_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		std::cout << "amount:" << _amount << ";";
		_nbWithdrawals++;
		Account::_totalNbWithdrawals++;
		std::cout << "nb_withdrawals:" << _nbWithdrawals << std::endl;
	}
	return (true);
}

int Account::checkAmount(void) const
{
	return (_amount > 0);
}

void Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}