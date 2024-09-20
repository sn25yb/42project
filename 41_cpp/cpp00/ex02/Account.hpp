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

class Account {


public:

	typedef Account		t;

	static int	getNbAccounts( void ); //계좌
	static int	getTotalAmount( void ); //총액
	static int	getNbDeposits( void ); //예금
	static int	getNbWithdrawals( void ); // 출금
	static void	displayAccountsInfos( void ); //계좌정보

	Account( int initial_deposit );
	~Account( void );

	void	makeDeposit( int deposit ); //예금 
	bool	makeWithdrawal( int withdrawal ); //출금
	int		checkAmount( void ) const; //총액
	void	displayStatus( void ) const; //상태? 


private:

	static int	_nbAccounts; //계좌
	static int	_totalAmount; //총액
	static int	_totalNbDeposits; //총 예금액?
	static int	_totalNbWithdrawals; //총 출금액?

	static void	_displayTimestamp( void ); //timestamp 찍는 함수 

	int				_accountIndex; //계좌 인덱스
	int				_amount; //총액
	int				_nbDeposits; //예금
	int				_nbWithdrawals; //출금

	Account( void );

};



// ************************************************************************** //
// vim: set ts=4 sw=4 tw=80 noexpandtab:                                      //
// -*- indent-tabs-mode:t;                                                   -*-
// -*- mode: c++-mode;                                                       -*-
// -*- fill-column: 75; comment-column: 75;                                  -*-
// ************************************************************************** //


#endif /* __ACCOUNT_H__ */
