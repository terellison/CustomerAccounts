/* Terry Ellison 
	October 26, 2017 ©
	Chapter 11 Programming Challenge: Customer Accounts */

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

// Account struct
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

// Function prototypes
Account inputAccountInfo(Account accountArr[], const int SIZE);
void searchCustomerData(Account accountArr[], const int SIZE, string searchKey);

int main()
{

	// Variable definitions
	const int SIZE = 1;
	Account accountArr[SIZE];
	bool terminate = false;
	string searchKey;
	char choice;

	// Menu loop
	while (!terminate) {
		cout << "Please select an option form the list below\n";
		cout << "A) Enter customer information\n";
		cout << "B) Search for an account holder's information\n";
		cout << "C) Exit the program\n";
		cout << "Please enter the letter of your desired option: ";
		
		cin >> choice;

		switch (choice) {
		case 'a':
		case 'A':
			inputAccountInfo(accountArr, SIZE);
			continue;
		case 'b':
		case 'B':
			cout << "Enter the name of the customer you are searching for: ";
			cin.ignore();
			getline(cin, searchKey);
			searchCustomerData(accountArr, SIZE, searchKey);
			continue;
		case 'c':
		case 'C':
			terminate = true;
			break;
		default:
			cout << "Invalid input. Please enter the letter of an option from the list.";
		}
	}

	cout << "\nGoodbye..\n";
	system("Pause");


    return 0;
}

Account inputAccountInfo(Account accountArr[], const int SIZE) {
	cout << "You will enter information for " << SIZE << " customer accounts.\n";
	cin.ignore();
	for (int i = 0; i < SIZE; i++) {
		cout << "Enter the name account holder number " << (i + 1) << ": ";
		getline(cin, accountArr[i].name);
		while (accountArr[i].name == "" || !cin) {
			cin.clear();
			cout << "\nPlease re-enter the account holder's name: ";
			getline(cin, accountArr[i].name);
		}
		cout << "\nEnter the street address of the account holder: ";
		getline(cin, accountArr[i].address);
		while (accountArr[i].address == "" || !cin) {
			cout << "Please re-enter the account holder's address: ";
			getline(cin, accountArr[i].address);
		}
		cout << "\nEnter the city in which the account holder lives: ";
		getline(cin, accountArr[i].city);
		while (accountArr[i].city == "" || !cin) {
			cin.clear();
			cout << "\nPlease re-enter the city in which the account holder lives: ";
			getline(cin, accountArr[i].city);
		}
		cout << "\nEnter the state in which the account holder lives: ";
		getline(cin, accountArr[i].state);
		while (accountArr[i].state == "" || !cin) {
			cin.clear();
			cout << "\nPlease re-enter the state in which the account holder lives: ";
			getline(cin, accountArr[i].state);
		}
		cout << "\nEnter the account holder's ZIP code: ";
		cin >> accountArr[i].ZIP;
		while (accountArr[i].ZIP == NULL || !cin) {
			cin.clear();
			cin.ignore();
			cout << "\nPlease re-enter the account holder's ZIP code: ";
			cin >> accountArr[i].ZIP;
		}
		cout << "\nEnter the telephone number of the account holder: ";
		cin.ignore();
		getline(cin, accountArr[i].telephoneNumber);
		cout << "\nEnter the account balance: ";
		cin >> accountArr[i].accountBalance;
		while (accountArr[i].accountBalance < 0 || !cin) {
			cin.clear();
			cin.ignore();
			cout << "The balance you entered was invalid, please try again: ";
			cin >> accountArr[i].accountBalance;
		}
		cout << "\nEnter the date of the last payment the account holder made: ";
		cin.ignore();
		getline(cin, accountArr[i].lastPayment);
		while (accountArr[i].lastPayment == "" || !cin) {
			cin.clear();
			cin.ignore();
			getline(cin, accountArr[i].lastPayment);
		}
	}

	return *accountArr;
}

void searchCustomerData(Account accountArr[], const int SIZE, string searchKey) {

	for (int i = 0; i < SIZE; i++) {
		if (searchKey == accountArr[i].name) {

			cout << "A match was found! Here's the matching customer's data:\n\n";
			cout << "Customer name: " << accountArr[i].name << "\n";
			cout << "Customer address: " << accountArr[i].address << ", ";
			cout << accountArr[i].city << ", ";
			cout << accountArr[i].state << ", ";
			cout << accountArr[i].ZIP << "\n";
			cout << "Customer telephone number: " << accountArr[i].telephoneNumber << "\n";
			cout << "Account balance: " << accountArr[i].accountBalance << "\n";
			cout << "Date of last payment: " << accountArr[i].lastPayment << "\n";
		}
	}

	cout << "\n\n";
}