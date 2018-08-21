/*********************************************************************
** Author: Thanhbinh(Michael) Truong
** Date: February 8th, 2017
** Description: Header file for BankAccount
*********************************************************************/

#ifndef BANKACCOUNT_HPP
#define BANKACCOUNT_HPP

#include <string>
using namespace std;

class BankAccount 
{
    private:
        string Name;
        string ID;
        double Balance;
    
    public:
        BankAccount();                      //constructors
        BankAccount(string, string, double);

        string getCustomerName();           //setter
        string getCustomerID();
        double getCustomerBalance();

        void setCustomerName(double);       //setter
        void setCustomerID(double);
        void setCustomerBalance(double);

        double withdraw (double);            //functions
        double deposit (double);

};

#endif