#include <iostream>
#include <iomanip>

void showBalance(double balance);

void showBalance(double balance) {
	std::cout << "Your balance is: $" << std::setprecision(2) << std::fixed << balance << '\n';
}

double depositMoney(double balance);

double depositMoney(double balance) {

	double amount = 0;
	std::cout << "Enter your amount: $";
	std::cin >> amount;

	if (amount >= 0) {
		return amount;
	}
	else {
		std::cout << "Please enter a valid amount!" << '\n';
		return 0;
	}
}

double withdrawMoney(double balance);

double withdrawMoney(double balance) {

	double amount = 0;

	std::cout << "Enter your amount: $";
	std::cin >> amount;

	if (amount > balance) {
		std::cout << "Insufficient funds!" << '\n';
		return 0;
	}
	else if(amount < 0) {
		std::cout << "Please enter a valid amount!" << '\n';
		return 0;
	}
	else {
		return amount;
	}
}

int main()

{
	double balance = 0;
	int choice = 0;

	do {
		std::cout << "Enter your choice: " << '\n';
		std::cout << "1.Current Balance: " << '\n';
		std::cout << "2.Deposit Money: " << '\n';
		std::cout << "3.Withdraw Money: " << '\n';
		std::cout << "4.Exit!" << '\n';
		std::cin >> choice;

		std::cin.clear();
		fflush(stdin);

		switch (choice) {
		case 1: showBalance(balance);
			break;
		case 2: balance += depositMoney(balance);
			showBalance(balance);
			break;
		case 3: balance -= withdrawMoney(balance);
			showBalance(balance);
			break;
		case 4: std::cout << "Thanks for visiting the bank!" << '\n';
			break;
		default: std::cout << "Invalid choice!" << '\n';
		}
	} while (choice != 4);

	return 0;

}