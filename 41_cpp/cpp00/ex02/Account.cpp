#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>

Account::Account(int initial_deposit)
{
	
}

Account::Account()
{

}
Account::~Account()
{

}

int	Account::getNbAccounts(void)
{
	return (0);
}

int	Account::getTotalAmount(void)
{
	return (0);

}
int	Account::getNbDeposits(void)
{
	return (0);

}
int	Account::getNbWithdrawals(void)
{
	return (0);

}
void	Account::displayAccountsInfos(void)
{

}
void	Account::makeDeposit(int deposit)
{

}
bool	Account::makeWithdrawal(int withdrawal)
{
	return (0);

}
int	Account::checkAmount(void) const
{

	return (0);
}

void	Account::displayStatus(void) const
{

}



void	Account::_displayTimestamp(void)
{
	time_t				now;
	std::tm				*time_struct;

	now = std::time(NULL);
	time_struct = std::localtime(&now);
	std::cout << std::put_time(time_struct, "%Y-%m-%d %H:%M:%S");
}
