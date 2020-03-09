/*Adedayo Adebanjo
COSC 1336 001
10/29/2019
Purpose:Fraction Calculator (Lab06a)*/

#include <stdio.h>

// Function Prototypes
int getNumerator();
int getDenominator();
void calculateProduct(int n1, int d1, int n2, int d2);
void calculateQuotient(int n1, int d1, int n2, int d2);
int multiply(int number1, int number2);
void exitMessage();
void printDecimal(int n, int d);


int main() {
	int response;
	printf("Please enter 1 for mutiply, 2 for divide, or 5 for exit: ");
	scanf("%d", &response);
	while (response != 5) {
		int num1 = getNumerator();
		int den1 = getDenominator();
		int num2 = getNumerator();
		int den2 = getDenominator();
		switch (response) {
		case 1:
			calculateProduct(num1, den1, num2, den2);
			break;
		case 2:
			calculateQuotient(num1, den1, num2, den2);
			break;
		default:
			printf("\nUnsupported Operation\n");
			break;
		} //end switch
		exitMessage();
		return 0;
	} // end while
}//end main

int getNumerator() {
	int numerator;
	printf("Please enter the numerator (any interger): ");
	scanf("%d", &numerator);
	return numerator;
}
int getDenominator() {
	int denominator;
	printf("Please enter the denominator (positive integers only): ");
	scanf("%d", &denominator);
	return denominator;
}
void calculateProduct(int n1, int d1, int n2, int d2) {
	int numProduct = multiply(n1, n2);
	int denProduct = multiply(d1, d2);

	printf("%d/%d * %d/%d. The resulting fraction is %d/%d.\n", n1, d1, n2, d2, numProduct, denProduct);
	printDecimal(numProduct, denProduct);
}
void calculateQuotient(int n1, int d1, int n2, int d2) {
	int numQuotient = multiply(n1, d2);
	int denQuotient = multiply(d1, n2);

	printf("%d/%d / %d/%d. The resulting fraction is %d/%d.\n", n1, d1, n2, d2, numQuotient, denQuotient);
	printDecimal(numQuotient, denQuotient);
}

void exitMessage() {
	printf("\nGoodbye\n");
}

int multiply(int number1, int number2) {
	return number1 * number2;
}
void printDecimal(int n, int d) {
	double decimalValue = (double)n / d;
	printf("The decimal representation of (n)/(d) is %.2f.\n", decimalValue);
}
