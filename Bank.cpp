/*Adedayo Adebanjo
COSC 1336 001
10/10/2019
Purpose: To check bank informations (Program 05)*/

#include <stdio.h>
//Constant
#define OVERDRAFT_FEE 25

int main() {

	//Declearing variables
	double oldBalance, transaction, newBalance, deposit, withdraw;

	// Inputs
	printf("Please enter your current balance: ");
	scanf("%lf", &oldBalance);
	printf("Please state your transaction type, - for withdrawal and + for deposit: ");
	scanf("%lf", &transaction);

	//Processing
	//Calculation
	newBalance = oldBalance + transaction;

	// Determine if they deposit or withdraw
	if (newBalance > oldBalance) {

		deposit = transaction;
		newBalance = oldBalance + deposit;
		printf("Amount deposited = $%.2f\n", deposit);
	}
	else
	{

		withdraw = transaction;
		printf("Amount withdrawn = $%.2f\n", withdraw);
		newBalance = oldBalance + withdraw;

		// Overdrawn
		if (newBalance < 0)
		{
			printf("Oops! Additional $25 for overdrawn.\n");
			newBalance = newBalance - OVERDRAFT_FEE;
		}
	}

	//Output
	printf("Your previous balance was: $%.2f.\t", oldBalance);
	printf("Your new balance is: $%.2f.\n", newBalance);
	printf("Thanks for banking with us.\n");
}
