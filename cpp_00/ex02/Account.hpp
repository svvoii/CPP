// ************************************************************************** //
//                                                                            //
//                Account.hpp for GlobalBanksters United                //
//                Created on  : Thu Nov 20 19:43:15 1989                      //
//                Last update : Wed Jan 04 14:54:06 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //


#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

// ************************************************************************** //
//                               Account Class                                //
// ************************************************************************** //

/*
** This Account class definition provides a basic
** scaffolding to model bank accounts in an 
** object-oriented manner for C++ program.
**
** It focuses on declaring the class members
** and methods that represent the key attributes
** and behaviors of real-world bank accounts.
*/

class Account {


public:

	typedef Account		t;

	/* 
	** These are static methods of the Account class.
	** Each of them returns information about the accounts.
	*/
	static int	getNbAccounts( void );
	static int	getTotalAmount( void );
	static int	getNbDeposits( void );
	static int	getNbWithdrawals( void );
	static void	displayAccountsInfos( void );

	/*
	** These are the constructor and destructor
	** of the Account class, respectively.
	*/
	Account( int initial_deposit );
	~Account( void );

	/* 
	** These are public methods of the Account class
	** Each of them performs an action on the account.
	*/
	void	makeDeposit( int deposit );
	bool	makeWithdrawal( int withdrawal );
	int		checkAmount( void ) const;
	void	displayStatus( void ) const;


private:

	/*
	** These are private static attributes,
	** which are used to keep track of the 
	** collective information for all accounts.
	*/
	static int	_nbAccounts;
	static int	_totalAmount;
	static int	_totalNbDeposits;
	static int	_totalNbWithdrawals;

	static void	_displayTimestamp( void );

	/*
	** These are private attributes,
	** which are used to keep track of
	** each account's information.
	*/
	int				_accountIndex;
	int				_amount;
	int				_nbDeposits;
	int				_nbWithdrawals;

	Account( void );

};

/*
** The static members allow collecting data across 
** all instances of the Account class.
** 
** The key logic flows are the deposit and withdrawal
** methods, which safely update the account's balance.
*/



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
