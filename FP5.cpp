/*Adedayo Adebanjo
COSC 1336 001
11/21/2019
Purpuse: To create a movie theater management system (LabFP5) */


#include <stdio.h>
#define NUM_THEATERS 10
#define NUM_ADMINS 5

//Function Prototypes
void showWelcomeScreen();
int mainExitMessage();
void mainErrorMessage();
void printSeparators();
void printMovieDetails(int theater, int movieIDS, int numSeats, int currentAttendance, double pricePerTicket, int isIMax);
void processNewMovie(int movieIDS[], int numSeats[], int currentAttendance[], double pricePerTicket[], int isIMax[]);
void listAllMovies(int movieIDS[], int numSeats[], int currentAttendance[],
	double pricePerTicket[], int isIMax[]);
int isAdminCode(int candidateCode, int codes[]);
int authenticate(int validCodes[]);
void printOutAdmins(int adminCodes[]);

int main() {
	int adminIDs[NUM_ADMINS] = { 1010 , 1111, 1212, 1313, 1414};

	//Parallel arrays to hold information for each theater
	int movieIDS[NUM_THEATERS];
	int numSeats[NUM_THEATERS];
	int currentAttendance[NUM_THEATERS];
	double pricePerTicket[NUM_THEATERS];
	int isIMax[NUM_THEATERS];

	for (int i = 0; i < NUM_THEATERS; i++) {
		movieIDS[i] = 0;
		numSeats[i] = 0;
		currentAttendance[i] = 0;
		pricePerTicket[i] = 0;
		isIMax[i] = 0;
	}

	//test a movie 
	int theater = 3;
	movieIDS[theater] = 763054;
	numSeats[theater] = 60;
	currentAttendance[theater] = 3;
	pricePerTicket[theater] = 10.5;
	isIMax[theater] = 1;
	int option = 0;

	//printMovieDetails(theater, movieIDS[theater], numSeats[theater], currentAttendance[theater], pricePerTicket[theater], isIMax[theater]);
	do {
		int movieToEdit = -1;
		char response;
		int adminNumber = 0;
		showWelcomeScreen();
		printf("Please choose one of the options above: ");
		scanf("%d", &option);
		switch (option) {
		case 0 :
			option = authenticate(adminIDs);
			if (option != 6) {
				printOutAdmins(adminIDs);
				printf("Please enter the ID you wish to change or an invalid ID to exit: ");
				scanf("%d", &adminNumber);
				if (adminNumber >= 0 && adminNumber < NUM_ADMINS) {
					printf("Please enter a new ID: ");
					scanf("%d", &adminIDs[adminNumber]);
				}
			}
			break;
		case 1:
			option = authenticate(adminIDs);
			if (option != 6)
				processNewMovie(movieIDS, numSeats, currentAttendance, pricePerTicket, isIMax);
			break;
		case 2:
			option = authenticate(adminIDs);
			if (option != 6)
			{
				listAllMovies(movieIDS, numSeats, currentAttendance,
					pricePerTicket, isIMax);

				do {
					printf("Please enter the movie you wish to edit: ");
					scanf("%d", &movieToEdit);
				} while (movieToEdit < 1 || movieToEdit > NUM_THEATERS);
				movieToEdit--;
				printf("Please enter the name of the movie (%d): ", (movieIDS[movieToEdit]));
				scanf("%d", &movieIDS[movieToEdit]);
				printf("Please enter the number of seats (%d) : ", (numSeats[movieToEdit]));
				scanf("%d", &numSeats[movieToEdit]);
				printf("Please enter the current attendance (%d) : ", (currentAttendance[movieToEdit]));
				scanf("%d", &currentAttendance[movieToEdit]);
				printf("Please enter the price per ticket ($%.2f) : ", (pricePerTicket[movieToEdit]));
				scanf("%lf", &pricePerTicket[movieToEdit]);
				printf("Please enter whether the movie is in IMax (Y/N): ");
				scanf("%c", &response);
				if (response == 'Y' || response == 'y')
					isIMax[movieToEdit] = 1;
				else
					isIMax[movieToEdit] = 0;
			}
			break;
		case 3:
			listAllMovies(movieIDS, numSeats, currentAttendance,
				pricePerTicket, isIMax);
			break;
		case 4:
			listAllMovies(movieIDS, numSeats, currentAttendance,
				pricePerTicket, isIMax);
			int movieNumber;
			printf("Please enter the number of the movie for which you wish to buy a ticket: ");
			scanf("%d", &movieNumber);
			movieNumber--;
			if (currentAttendance[movieNumber] < numSeats[movieNumber]) {
				currentAttendance[movieNumber]++;
				printf("You have successfully purchased a ticket for %d.", (movieIDS[movieNumber]));
			}
			else
			{
				printf("is already full. Ticket not purchased!", (movieIDS[movieNumber]));
			}
			break;
		case 5:
			listAllMovies(movieIDS, numSeats, currentAttendance,
				pricePerTicket, isIMax);
			printf("Please enter the number of the movie for which you wish to cancel a ticket: ");
			scanf("%d", &movieNumber);
			movieNumber--;
			if (currentAttendance[movieNumber] >= 1) {
				currentAttendance[movieNumber]--;
				printf("You have successfully cancelled a ticket for %d.", (movieIDS[movieNumber]));
			}
			else
			{
				printf("is already empty. Ticket not cancelled!", (movieIDS[movieNumber]));
			}
			break;
		case 6:
			option = mainExitMessage();
			break;
		default:
			mainErrorMessage();
			printf("\n\n");
		}
		printf("\n\n\n\n\n\n\n\n\n\n");

	} while (option != 6);
}

void showWelcomeScreen() {
	printf("         Simple Movie Ticket Booking System\n");
	printSeparators();
	printf("||     0- Change an admin      (admin only)       ||\n");
	printf("||     1- Process a New Movie  (admin only)       ||\n");
	printf("||     2- Edit a Movie         (admin only)       ||\n");
	printf("||     3- View the list of Movies(admin only)     ||\n");
	printf("||     4- Purchase Ticket                         ||\n");
	printf("||     5- Cancel Ticket                           ||\n");
	printf("||     6- Exit                                    ||\n");
	printSeparators();
}
int mainExitMessage() {
	char response;
	int option = 0;
	do {
		printf("Are you sure you want to exit (Y/N)? ");
		scanf(" %c", &response);
	} while (response != 'Y' && response != 'y' && response != 'N' && response != 'n');
	if (response == 'y' || response == 'Y')
		return 6;
	return option;
}
void mainErrorMessage() {
	printf("Invalid input. Please choose a valid option.");
}
void printSeparators() {
	for (int i = 0; i < 55; i++)
		printf("=");
	printf("\n");
}
void printMovieDetails(int theater, int movieIDS, int numSeats, int currentAttendance, double pricePerTicket, int isIMax) {
	printSeparators();
	printf("Movie ID: %d\t\t\t\t", movieIDS);
	if (isIMax == 1) {
		printf("IN IMAX");
	}
	printf("\n%d%d are currently taken \t\t\tTheater: %d", currentAttendance, numSeats, theater);
	printf("\nMovie price: $%.2f\n", pricePerTicket);
}
void processNewMovie(int movieIDS[], int numSeats[], int currentAttendance[], double pricePerTicket[], int isIMax[]) {
	int movieNumber = -1;
	char response;
	do {
		printf("Please enter the movie number to replace: ");
		scanf("%d", &movieNumber);
	} while (movieNumber < 1 || movieNumber > NUM_THEATERS);
	movieNumber--;
	printf("Enter the ID of the movie: ");
	scanf("%d", &movieIDS[movieNumber]);
	printf("Enter the number of seats for the movie: ");
	scanf("%d", &numSeats[movieNumber]);
	printf("Enter the price per ticket: ");
	scanf("%lf", &pricePerTicket[movieNumber]);
	currentAttendance[movieNumber] = 0;
	printf("Is the movie in IMax (Y for Yes): ");
	scanf(" %c", &response);
	if (response == 'Y' || response == 'y')
		isIMax[movieNumber] = 1;
	else
		isIMax[movieNumber] = 0;
}

void listAllMovies(int movieIDS[], int numSeats[], int currentAttendance[],
	double pricePerTicket[], int isIMax[]) {
	for (int theater = 0; theater < NUM_THEATERS; theater++) {
		printMovieDetails(theater + 1, movieIDS[theater], numSeats[theater],
			currentAttendance[theater], pricePerTicket[theater], isIMax[theater]);
	}
}

int isAdminCode(int candidateCode, int codes[]) {
	for (int i = 0; i < NUM_ADMINS; i++)
		if (codes[i] == candidateCode)
			return 1;
	return 0;
}

int authenticate(int validCodes[]) {
	int admincode, guesses = 1;
	do {
		guesses++;
		printf("You must be an admin to perform this action. You have 3 attempts to log on. \nPlease enter your code: ");
		scanf("%d", &admincode);
	} while (!isAdminCode(admincode, validCodes) && guesses <= 3);
	if (!isAdminCode(admincode, validCodes)) {
		printf("SECURITY VIOLATION! SYSTEM EXITING! WORLD ENDING!");
		return 6;
	}
	return 1;

}

void printOutAdmins(int adminCodes[]) {
	for (int i = 0; i < NUM_ADMINS; i++)
		printf("%d: %d\n", i, adminCodes[i]);
}