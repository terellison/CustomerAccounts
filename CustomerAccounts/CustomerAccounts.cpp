/* Terry Ellison 
	October 26, 2017 ©
	Chapter 11 Programming Challenge: Customer Accounts */

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

struct Account {
	string name;
	string address;
	string city;
	string state;
	int ZIP;
	string telephoneNumber;
	double accountBalance;
	string lastPayment;
};

int main()
{
	Account accountArr[10];

	for (int i = 0; i < 10; i++) {
		cout << "Enter the name of the account holder: ";
		getline(cin, accountArr[i].name);
		while (accountArr[i].name == "") {
			cout << "\nPlease re-enter the account holder's name: ";
			getline(cin, accountArr[i].name);
		}
		cout << "\nEnter the street address of the account holder: ";
		getline(cin, accountArr[i].address);
		while (accountArr[i].address == "") {
			cout << "Please re-enter the account holder's address: ";
			getline(cin, accountArr[i].address);
		}
		cout << "\nEnter the city in which the account holder lives: ";
		getline(cin, accountArr[i].city);
		while (accountArr[i].city == "") {
			cout << "\nPlease re-enter the city in which the account holder lives: ";
			getline(cin, accountArr[i].city);
		}
		cout << "\nEnter the state in which the account holder lives: ";
		getline(cin, accountArr[i].state);
		while (accountArr[i].state == "") {
			cout << "\nPlease re-enter the state in which the account holder lives: ";
			getline(cin, accountArr[i].state);
		}
		cout << "\nEnter the account holder's ZIP code: ";
		cin >> accountArr[i].ZIP;
		while (accountArr[i].ZIP == NULL) {
			cout << "\nPlease re-enter the account holder's ZIP code: ";
			cin >> accountArr[i].ZIP;
		}
		cout << "\nEnter the telephone number of the account holder: ";
		cin.ignore();
		getline(cin, accountArr[i].telephoneNumber);
		cout << "\nEnter the account balance: ";
		cin >> accountArr[i].accountBalance;
		while (accountArr[i].accountBalance < 0) {
			cout << "The balance you entered was negative, please try again: ";
			cin >> accountArr[i].accountBalance;
		}
		cout << "\nEnter the date of the last payment the account holder made: ";
		getline(cin, accountArr[i].lastPayment);
	}

	system("Pause");


    return 0;
}

