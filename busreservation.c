#include <stdio.h>

void login();
void exitProgram();
void showAllBuses(int busNo[3], char from[3][20], char to[3][20], int seats[3], int booked[3], float fare[3], int n);
void findBus(int busNo[3], char from[3][20], char to[3][20], int seats[3], int booked[3], float fare[3], int n);
void bookSeat(int busNo[3], int seats[3], int booked[3], int n);
void cancelSeat(int busNo[3], int booked[3], int n);

int main() 
{
    login();

    int busNo[3] = {101, 102, 103};
    char from[3][20] = {"Delhi", "Mumbai", "Jaipur"};
    char to[3][20] = {"Bihar", "Goa", "Agra"};
    int seats[3] = {50, 40, 45};
    int booked[3] = {45, 25, 40};
    float fare[3] = {500.00, 700.00, 400.00};

    int choice;

    while (1) {
        printf("\n********************BR BUS RESERVATION MENU***********************\n");
        printf("1. Show All Buses\n");
        printf("2. Find Bus Details\n");
        printf("3. Book a Seat\n");
        printf("4. Cancel a Seat\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
            showAllBuses(busNo, from, to, seats, booked, fare, 3);
        else if (choice == 2)
            findBus(busNo, from, to, seats, booked, fare, 3);
        else if (choice == 3)
            bookSeat(busNo, seats, booked, 3);
        else if (choice == 4)
            cancelSeat(busNo, booked, 3);
        else if (choice == 5) 
        {
            exitProgram();
            break;
        } else
            printf("Invalid choice! Please try again.\n");
    }

    return 0;
}

void login()
{
    char email[50], password[20];
    char inputEmail[50], inputPass[20];
    int i, emailCorrect = 1, passCorrect = 1;

    printf("\n*************** REGISTRATION ***************\n");
    printf("Set your email ID: ");
    scanf("%s", email);
    printf("Set your password: ");
    scanf("%s", password);

    printf("\n**************** LOGIN ****************\n");
    printf("Enter email ID: ");
    scanf("%s", inputEmail);
    printf("Enter password: ");
    scanf("%s", inputPass);

    for (i = 0; email[i] != '\0' || inputEmail[i] != '\0'; i++)
     {
        if (email[i] != inputEmail[i]) 
        {
            emailCorrect = 0;
            break;
        }
    }

    for (i = 0; password[i] != '\0' || inputPass[i] != '\0'; i++) 
    {
        if (password[i] != inputPass[i])
         {
            passCorrect = 0;
            break;
        }
    }

    if (emailCorrect && passCorrect)
        printf("\nLogin Successful! Welcome to BR Bus Reservation System.\n");
    else {
        printf("\nInvalid Email or Password! Exiting program.\n");
        exit(0);
    }
}
void exitProgram()
{
    printf("\nExiting the program...\nThank you for using the BR Bus Reservation System!\n");
}

void showAllBuses(int busNo[], char from[][20], char to[][20], int seats[], int booked[], float fare[], int n)
{
    printf("\nBusNo\tFrom\tTo\tTotal\tBooked\tFare\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%s\t%s\t%d\t%d\t%.2f\n",
               busNo[i], from[i], to[i], seats[i], booked[i], fare[i]);
    }
}

void findBus(int busNo[], char from[][20], char to[][20], int seats[], int booked[], float fare[], int n)
{
    int num, found = 0;
    printf("\nEnter Bus Number to Search: ");
    scanf("%d", &num);

    for (int i = 0; i < n; i++) {
        if (busNo[i] == num) {
            printf("\nBus Found!\n");
            printf("Bus No: %d\n", busNo[i]);
            printf("From: %s\n", from[i]);
            printf("To: %s\n", to[i]);
            printf("Total Seats: %d\n", seats[i]);
            printf("Booked Seats: %d\n", booked[i]);
            printf("Available Seats: %d\n", seats[i] - booked[i]);
            printf("Fare: %.2f\n", fare[i]);
            found = 1;
            break;
        }
    }

    if (found == 0)
        printf("Bus not found!\n");
}

void bookSeat(int busNo[], int seats[], int booked[], int n)
{
    int num, found = 0;
    printf("\nEnter Bus Number to Book Seat: ");
    scanf("%d", &num);

    for (int i = 0; i < n; i++)
     {
        if (busNo[i] == num) 
        {
            found = 1;
            if (booked[i] < seats[i]) 
            {
                booked[i]++;
                printf("Seat booked successfully! Total booked seats: %d\n", booked[i]);
            } 
            else 
            {
                printf("Sorry, no seats available!\n");
            }
            break;
        }
    }

    if (found == 0)
        printf("Bus not found\n");
}
void cancelSeat(int busNo[], int booked[], int n)
{
    int num, found = 0;
    printf("\nEnter Bus Number to Cancel Seat: ");
    scanf("%d", &num);

    for (int i = 0; i < n; i++) 
    {
        if (busNo[i] == num) 
        {
            found = 1;
            if (booked[i] > 0)
             {
                booked[i]--;
                printf("Seat cancelled successfully! Remaining booked seats: %d\n", booked[i]);
            } else
             {
                printf("No seats booked yet\n");
            }
            break;
        }
    }

    if (found == 0)
        printf("Bus not found\n");
}