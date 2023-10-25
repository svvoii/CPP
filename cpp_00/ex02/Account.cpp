#include "Account.hpp"
#include <iostream>
#include <iomanip>

// Initialize the static variable
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Constructor
Account::Account(int initial_deposit) : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Destructor
Account::~Account() {
	_nbAccounts--;
	_totalAmount -= _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Getters
int Account::getNbAccounts() {
	return _nbAccounts;
}

int Account::getTotalAmount() {
	return _totalAmount;
}

int Account::getNbDeposits() {
	return _totalNbDeposits;
}

int Account::getNbWithdrawals() {
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos() {
	_displayTimestamp();

	std::cout << "accounts:" << _nbAccounts;
	std::cout << ";total:" << _totalAmount;
	std::cout << ";deposits:" << _totalNbDeposits;
	std::cout << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

/*
** This function updates the static variables of the class
** with the collective information of all accounts.
** It also displays this collective information.
*/
void Account::makeDeposit(int deposit) {
	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;
	_displayTimestamp();

	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount - deposit;
	std::cout << ";deposit:" << deposit;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_deposits:";
	std::cout << _nbDeposits << std::endl;
}

/* 
** This function returns false if the withdrawal is refused
** Otherwise, it returns true and performs the withdrawal
** and updates the static variables of the class.
*/
bool Account::makeWithdrawal(int withdrawal) {
	if (_amount < withdrawal) {
		_displayTimestamp();
		std::cout << "index:" << _accountIndex;
		std::cout << ";p_amount:" << _amount;
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}
	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;
	_displayTimestamp();

	std::cout << "index:" << _accountIndex;
	std::cout << ";p_amount:" << _amount + withdrawal;
	std::cout << ";withdrawal:" << withdrawal;
	std::cout << ";amount:" << _amount;
	std::cout << ";nb_withdrawals:" << _nbWithdrawals << std::endl;

	return true;
}

/*
** This simply returns the amount of the account.
*/
int Account::checkAmount() const {
	return _amount;
}

/*
** This function returns the amount of the account.
** It is a const function, so it cannot modify the account.
*/
void Account::displayStatus() const {
	_displayTimestamp();

	std::cout << "index:" << _accountIndex;
	std::cout << ";amount:" << _amount;
	std::cout << ";deposits:" << _nbDeposits;
	std::cout << ";withdrawals:" << _nbWithdrawals << std::endl;
}

/*
** This function displays the collective information of all accounts.
** `setfill` and `setw` are used to format the output.
** `setfill('0')` sets the fill character to '0'.
** `setw(2)` sets the width of the next output to 2.
*/
void Account::_displayTimestamp() {
	time_t now = time(0);
	tm *ltm = localtime(&now);

	std::cout << std::setfill('0') << "[" << 1900 + ltm->tm_year;
	std::cout << std::setw(2) << ltm->tm_mon + 1;
	std::cout << std::setw(2) << ltm->tm_mday;
	std::cout << "_" << std::setw(2) << ltm->tm_hour;
	std::cout << std::setw(2) << ltm->tm_min;
	std::cout << std::setw(2) << ltm->tm_sec << "] ";
}
