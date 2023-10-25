// ************************************************************************** //
//                                                                            //
//                tests.cpp for GlobalBanksters United                        //
//                Created on  : Thu Nov 20 23:45:02 1989                      //
//                Last update : Wed Jan 04 09:23:52 1992                      //
//                Made by : Brad "Buddy" McLane <bm@gbu.com>                  //
//                                                                            //
// ************************************************************************** //

#include <vector>
#include <algorithm>
#include <functional>
#include "Account.hpp"


int		main( void ) {

	typedef std::vector<Account::t>							  accounts_t;
	typedef std::vector<int>								  ints_t;
	typedef std::pair<accounts_t::iterator, ints_t::iterator> acc_int_t;

	int	const				amounts[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const			amounts_size( sizeof(amounts) / sizeof(int) );
	accounts_t				accounts( amounts, amounts + amounts_size );
	accounts_t::iterator	acc_begin	= accounts.begin();
	accounts_t::iterator	acc_end		= accounts.end();

	int	const			d[]			= { 5, 765, 564, 2, 87, 23, 9, 20 };
	size_t const		d_size( sizeof(d) / sizeof(int) );
	ints_t				deposits( d, d + d_size );
	ints_t::iterator	dep_begin	= deposits.begin();
	ints_t::iterator	dep_end		= deposits.end();

	int	const			w[]			= { 321, 34, 657, 4, 76, 275, 657, 7654 };
	size_t const		w_size( sizeof(w) / sizeof(int) );
	ints_t				withdrawals( w, w + w_size );
	ints_t::iterator	wit_begin	= withdrawals.begin();
	ints_t::iterator	wit_end		= withdrawals.end();

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, dep_begin );
		  it.first != acc_end && it.second != dep_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeDeposit( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	for ( acc_int_t it( acc_begin, wit_begin );
		  it.first != acc_end && it.second != wit_end;
		  ++(it.first), ++(it.second) ) {

		(*(it.first)).makeWithdrawal( *(it.second) );
	}

	Account::displayAccountsInfos();
	std::for_each( acc_begin, acc_end, std::mem_fun_ref( &Account::displayStatus ) );

	return 0;
}

/*
** About iterators:
** http://www.cplusplus.com/reference/iterator/
**
** `iterator` is an object that points to an element inside the container
** (vector, list, map, etc.).
** It is used to iterate through the elements of the container.
**
** `begin()` returns an iterator pointing to the first element of the container.
** `end()` returns an iterator pointing to the element after the last element of it.
** `++` increments the iterator to point to the next element.
** `*` dereferences the iterator to access the element it points to.
** `!=` compares two iterators.
** `std::for_each` applies a function to each element of a container.
** `std::mem_fun_ref` returns a function object that calls a member function
** on its argument.
** `std::mem_fun_ref( &Account::displayStatus )` returns a function object that
** calls `Account::displayStatus` on its argument.
**
** In the given code excerpt, `dep_begin` and `dep_end` are iterators that point
** to the first and last elements of the `deposits` vector, respectively.
**
** Similarly, `wit_begin` and `wit_end` are iterators that point to the first
** and last elements of the `withdrawals` vector, respectively.
**
** The `acc_int_t` typedef is a pair of iterators, where the first iterator
** points to an element of the `accounts` vector, and the second iterator points
** to an element of the `deposits` or `withdrawals` vector.
**
** The `it` object is an instance of the `acc_int_t` pair, initialized with
** `acc_begin` and `dep_begin` or `wit_begin`.
**
** The `for` loop iterates through the `accounts` vector, and either `deposits`
** or `withdrawals` vector, depending on the `acc_int_t` instance.
*/


// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //
