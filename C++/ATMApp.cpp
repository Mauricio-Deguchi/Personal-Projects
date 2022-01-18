#include <iostream>
using namespace std;
// building an ATM App
// 1) check balance
// 2) deposit money
// 3) widthdraw money
// 4) show menu

void showMenu();


int main()
{
	int option;
	double balance = 500;
	do {
		showMenu();
		cout << "Option: ";
		cin >> option;
		system("cls");
		cin.ignore(10000, '\n');
		switch (option) {
		case 1: cout << "Balance is: " << balance << " $" << endl; break;
		case 2: cout << "Deposit amount: $";
			double depositAmount;
			cin >> depositAmount;
			cin.ignore(10000, '\n');
			balance += depositAmount;
			cout << "$" << depositAmount << " was deposited, new total balance: $" << balance << endl;
			break;
		case 3: cout << "Withdraw amount: $";
			double withdrawAmount;
			cin >> withdrawAmount;
			cin.ignore(10000, '\n');
			if (withdrawAmount <= balance) {
				balance -= withdrawAmount;
				cout << "$" << withdrawAmount << " was withdrawn, new total balance: $" << balance << "." << endl;
				break;
			}
			else {
				cout << "Not enough money, total balance: $" << balance << "." << endl;
			}
		}
	} while (option != 4);
	return 0;
}

void showMenu() {
	cout << "**********Menu**********" << endl;
	cout << "1. Check Balance" << endl;
	cout << "2. Deposit" << endl;
	cout << "3. Withdarw" << endl;
	cout << "4. Exit" << endl;
	cout << "************************" << endl;
}