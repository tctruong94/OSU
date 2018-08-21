/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 8th, 2017
** Description: .cpp file for BankAccount
*********************************************************************/

#include <iostream>
#include <string>
#include "BankAccount.hpp"

using namespace std;

BankAccount::BankAccount()
{
    Name = "Randy Johnson";
    ID = "TEST";
    Balance = 500.00;
}

/***********************************************
** Name: BankAccount::BankAccount()
** Description: 3 parameter constructor
************************************************/

BankAccount::BankAccount (string nam, string ident, double bal)
{
    Name = nam;
    ID = ident;
    Balance = bal;
}


/***********************************************
** Name: BankAccount::getCustomerName()
** Description: returns object name variable
************************************************/

string BankAccount::getCustomerName()
{
    return Name;
}


/***********************************************
** Name: BankAccount::getCustomerID()
** Description: returns object ID variable
************************************************/
string BankAccount::getCustomerID()
{
	return ID;
}


/***********************************************
** Name: BankAccount::getCustomerBalance()
** Description: returns object balance variable
************************************************/

double BankAccount::getCustomerBalance()
{
	return Balance;
}


/***********************************************
** Name: BankAccount::setCustomarName()
** Description: sets object name variable
************************************************/

void BankAccount::setCustomerName(double nam)
{
	Name = nam;
}

/***********************************************
** Name: BankAccount::setCustomarID()
** Description: sets object ID variable
************************************************/

void BankAccount::setCustomerID(double ident)
{
	ID = ident;
}

/***********************************************
** Name: BankAccount::setCustomerBalance()
** Description: sets object Balance variable
************************************************/

void BankAccount::setCustomerBalance(double bal)
{
	Balance = bal;
}

/***********************************************
** Name: BankAccount::withdraw()
** Description: decreases balance by an amount
************************************************/
double BankAccount::withdraw(double withd)
{
	double newBalance = Balance -= withd;
	return newBalance;
}

/***********************************************
** Name: BankAccount::deposit()
** Description: increases balance by an amount
************************************************/

double BankAccount::deposit(double depo)
{
	double newBalance = Balance += depo;
	return newBalance;
}

/*

int main()
{
	
	BankAccount account1("Harry Potter", "K4637", 8032.78);
	cout << account1.getCustomerName() << endl;
	cout << account1.getCustomerID() << endl;
	cout << account1.getCustomerBalance() << endl;
	account1.withdraw(32.78);
	cout << account1.getCustomerBalance() << endl;
	account1.withdraw(1000.00);
	cout << account1.getCustomerBalance() << endl;
	account1.deposit(2000.00);
	cout << account1.getCustomerBalance() << endl;
	account1.withdraw(500.00);
	cout << account1.getCustomerBalance() << endl;
	account1.deposit(500.00);
	cout << account1.getCustomerBalance() << endl;
	double finalBalance = account1.getCustomerBalance();
	cout << "Final Balance: " << finalBalance << endl;
	return 0;
}

*/

