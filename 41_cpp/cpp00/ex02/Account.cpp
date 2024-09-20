#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

//awk '{print $2}' test.log > test_column.log

int Account::_nbAccounts;
int Account::_totalAmount;
int Account::_totalNbDeposits;
int Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
{
	//init
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	//print 
	_displayTimestamp();
	std::cout \
			<< " "
			<< "index:" << this->_accountIndex << ";" \
			<< "amount:" <<  this->_amount << ";" \
			<< "created" << std::endl;
}

Account::Account()
{

}
Account::~Account()
{
	_displayTimestamp();
	std::cout \
			<< " "
			<< "index:" << this->_accountIndex << ";" \
			<< "amount:" <<  this->_amount << ";" \
			<< "closed" << std::endl;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (_totalAmount);
}
int	Account::getNbDeposits(void)
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals(void)
{
	return (_totalNbWithdrawals);
}
void	Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout \
		<< " "
		<< "accounts:" << _nbAccounts << ";" \
		<< "total:" << _totalAmount << ";" \
		<< "deposits:" << _totalNbDeposits << ";" \
		<< "withdrawals:" << _totalNbWithdrawals \
		<< std::endl;
}
void	Account::makeDeposit(int deposit)
{
	int p_amount;

	p_amount =this->_amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;

	_displayTimestamp();
	std::cout \
		<< " "
		<< "index:" << this->_accountIndex << ";" \
		<< "p_amount:" << p_amount << ";" \
		<< "deposit:" << deposit << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "nb_deposits:" << this->_nbDeposits \
		<< std::endl;

}
bool	Account::makeWithdrawal(int withdrawal)
{
	int p_amount;

	//handle
	if (withdrawal > checkAmount())
	{
		_displayTimestamp();
		std::cout \
			<< " "
			<< "index:" << this->_accountIndex << ";" \
			<< "p_amount:" << _amount << ";" \
			<< "withdrawal:" << "refused" \
			<< std::endl;
		return (1);
	}
	//set
	p_amount = this->_amount;
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++;
	_totalNbWithdrawals++;
	//print
	_displayTimestamp();
	std::cout \
		<< " "
		<< "index:" << this->_accountIndex << ";" \
		<< "p_amount:" << p_amount << ";" \
		<< "withdrawal:" << withdrawal << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "nb_withdrawals:" << this->_nbWithdrawals \
		<< std::endl;
	return (0);
}
int	Account::checkAmount(void) const
{
	return (_amount);
}

void	Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout \
		<< " "
		<< "index:" << this->_accountIndex << ";" \
		<< "amount:" << this->_amount << ";" \
		<< "deposits:" << this->_nbDeposits << ";" \
		<< "withdrawals:" << this->_nbWithdrawals \
		<< std::endl;
}

void	Account::_displayTimestamp(void)
{
	time_t	now;
	std::tm	*time_struct;

	now = std::time(NULL);
	time_struct = std::localtime(&now);
	std::cout << std::put_time(time_struct, "[%Y%m%d_%H%M%S]");
}
