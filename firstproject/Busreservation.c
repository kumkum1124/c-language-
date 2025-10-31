#include <stdio.h>
#include <string.h>

void showMenu();
void login();
void exitSystem();

int main()
 {
    int choice;

    while (1) {
        showMenu();
        printf("Please enter your choice: ");
        scanf("%d", &choice); 

        switch (choice) {
            case 1:
                login();
                break;
            case 2:
                exitSystem();
                break;
            default:
                printf("\nInvalid choice! Try again.\n");
        }
    }
    return 0;
}

void showMenu()
 {  
    printf("*******************************************BUS RESERVATION SYSTEM**************************************\n");
    printf("1. Login\n");
    printf("2. Exit\n");
}

void login()
 {
    char username[20], password[20];
    char correctUser[20] = "admin";
    char correctPass[20] ="1234";

    printf("\nEnter Username: ");
    scanf("%s",username);
    printf("Enter Password: ");
    scanf("%s",&password);

    if(("%s",username, correctUser) == 0 && ("%s",password, correctPass) == 0)
        printf("\nLogin Successful! Welcome to Bus Reservation System.\n");
    else
        printf("\nInvalid Username or Password!\n");
}
void exitSystem()
 {
    printf("\nThank you for using Bus Reservation System!\n");
}